// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "MyAnimInstance.h"
#include "Components/WidgetComponent.h"
#include "MyUserWidget.h"
#include "MyUserWidgetName.h"
#include "MyAIController.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	Camera->SetupAttachment(SpringArm);

	// SetControlMode
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritRoll = true;
	SpringArm->bInheritYaw = true;

	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);

	PowerUpEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PowerUpEffect"));
	PowerUpEffect->SetupAttachment(RootComponent);
	PowerUpEffect->bAutoActivate = false;

	AttackEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("AttackEffect"));
	AttackEffect->SetupAttachment(RootComponent);
	AttackEffect->bAutoActivate = false;

	DamageEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("DamageEffect"));
	DamageEffect->SetupAttachment(RootComponent);
	DamageEffect->bAutoActivate = false;

	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));
	HPBarWidget->SetupAttachment(GetMesh());
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen); // Screen은 2D, World는 3D
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_BAR(TEXT("WidgetBlueprint'/Game/BluePrint/UI/BP_HPWidget.BP_HPWidget_C'")); // BP 참조할때는 _C 붙여줘야 한다.
	if (UI_BAR.Succeeded())
	{
		HPBarWidget->SetWidgetClass(UI_BAR.Class);
		HPBarWidget->SetDrawSize(FVector2D(150.0f, 30.0f));
	}

	NameWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("NameWIDGET"));
	NameWidget->SetupAttachment(GetMesh());
	NameWidget->SetWidgetSpace(EWidgetSpace::Screen); // Screen은 2D, World는 3D
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_NAME(TEXT("WidgetBlueprint'/Game/BluePrint/UI/BP_NameWidget.BP_NameWidget_C'")); // BP 참조할때는 _C 붙여줘야 한다.
	if (UI_NAME.Succeeded())
	{
		NameWidget->SetWidgetClass(UI_NAME.Class);
		NameWidget->SetDrawSize(FVector2D(150.0f, 35.0f));
	}

	MaxHP = 100.f;
	Defense = 0;
	CurrentAttackDamage = 30;
	HPHeight = 180.0f;
	NameHeight = 185.0f;

	AIControllerClass = AMyAIController::StaticClass(); // AI Controller, 따로 셋팅해주지 않으면 전부 같은 동작을 하게끔 되어 있다.
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned; // 새롭게 생성되는 MyCharacter 마다 AMyIController 액터가 생성되며, 플레이어가 조종하는 캐릭터를 제외한 모든 캐릭터는 MYAIController 의 지배
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HPBarWidget)
		HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, HPHeight));

	if (NameWidget)
	{
		NameWidget->SetRelativeLocation(FVector(0.0f, 0.0f, NameHeight));
		auto MonsterNameWidget2 = Cast<UMyUserWidgetName>(NameWidget->GetUserWidgetObject());
		if (MonsterNameWidget2)
			MonsterNameWidget2->SetMonsterName(MonsterName); // 이러면 안되는데 그 이유는 순서가 BeginPlay->NativeConstruct 순서이기 때문이다.
	}														 // 때문에 Widget 소스에서 멤버로 해당 값을 받아 저장하고 있다가 NativeConstruct에서 바꿔주는 형태로 해야한다.

	MyAnim = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	if (MyAnim)
	{
		MyAnim->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackMontageEnded);
		MyAnim->OnAttackHitNotifyL.AddUObject(this, &AMyCharacter::AttackHitNotifyL);
		MyAnim->OnAttackHitNotifyR.AddUObject(this, &AMyCharacter::AttackHitNotifyR);
	}

	CurrentHP = MaxHP;
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move Forward / Backward"), this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Right / Left"), this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Mouse"), this, &AMyCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Mouse"), this, &AMyCharacter::LookUp);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);
	PlayerInputComponent->BindAction(TEXT("AttackR"), EInputEvent::IE_Pressed, this, &AMyCharacter::AttackR);
}

void AMyCharacter::MoveForward(float NewAxisValue)
{
	//if (!IsAttacking)
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
}

void AMyCharacter::MoveRight(float NewAxisValue)
{
	//if (!IsAttacking)
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
}

void AMyCharacter::Turn(float NewAxisValue)
{
	//if (!IsAttacking)
		AddControllerYawInput(NewAxisValue);
}

void AMyCharacter::LookUp(float NewAxisValue)
{
	//if (!IsAttacking)
		AddControllerPitchInput(NewAxisValue);
}

void AMyCharacter::Attack()
{
	//if (IsAttacking) return;
	if (MyAnim)
	{
		AttackEffect->Activate();
		MyAnim->PlayAttackMontage();
		IsAttacking = true;
	}
}

void AMyCharacter::AttackR()
{
	//if (IsAttacking) return;
	if (MyAnim)
	{
		MyAnim->PlayAttackMontageR();
		IsAttacking = true;
	}
}

void AMyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	IsAttacking = false;
}

void AMyCharacter::AttackHitNotifyL()
{
	//충돌 체크 해서 상대에게 데미지를 입힌다.
	float AttackRange = 200.0f;
	float AttackRadius = 50.0f;

	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);

	FVector StartLocation, EndLocation;
	StartLocation = GetActorLocation();
	EndLocation = GetActorLocation() + GetActorForwardVector() * AttackRange;
	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(AttackRadius),
		Params);

	//UE_LOG(LogTemp, Warning, TEXT("StartLocation : %s, EndLocation : %s"), StartLocation.ToString(), EndLocation.ToString());

	FVector TraceVec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;

	//Capsule 의 Z (Up)를 TraceVec 방향으로 회전 
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;

	float DebugLifeTime = 5.0f;

	DrawDebugCapsule(GetWorld(),
		Center,
		HalfHeight,
		AttackRadius,
		CapsuleRot,
		DrawColor,
		false,
		DebugLifeTime);

	if (bResult)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("AMyCharacter::AttackHitCheck == true"));

		if (HitResult.GetActor())
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor Name : %s"), *HitResult.GetActor()->GetName());

			FDamageEvent DamageEvent;
			HitResult.GetActor()->TakeDamage(CurrentAttackDamage, DamageEvent, GetController(), this);
		}
	}
	else
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("AMyCharacter::AttackHitCheck == false"));
	}
}

void AMyCharacter::AttackHitNotifyR()
{
	if (PowerUpEffect->IsActive())
		PowerUpEffect->Deactivate();
	else
		PowerUpEffect->Activate();
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	UE_LOG(LogTemp, Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);

	// CurrentHP 깍아봐
	float fDamage = DamageAmount - Defense;
	CurrentHP -= fDamage;
	if (MaxHP > 0)
	{
		float HPRate = CurrentHP / MaxHP;
		if (HPRate < 0)
			HPRate = 0.0f;
		UE_LOG(LogTemp, Warning, TEXT("CurrentHP : %f, HP Rate : %f"), CurrentHP, HPRate);

		auto HPWidget = Cast<UMyUserWidget>(HPBarWidget->GetUserWidgetObject());
		if (HPWidget)
			HPWidget->SetHP(HPRate);

		/*auto DamageWidget2 = Cast<UMyUserWidgetDamage>(DamageWidget->GetUserWidgetObject());
		if (DamageWidget2)
			DamageWidget2->SetDamageText(fDamage);*/
	}

	if (MyAnim)
	{
		DamageEffect->Deactivate();
		DamageEffect->Activate();
		//MyAnim->SetDead();
		
		FVector Dir = DamageCauser->GetActorLocation() - GetActorLocation();
		Dir.Z = 0.0f;
		FQuat LookAtRot = FRotationMatrix::MakeFromX(Dir).ToQuat();
		SetActorRotation(LookAtRot);
		//SetActorEnableCollision(false);
	}

	if (CurrentHP <= 0.0f)
	{
		MyAnim->SetDead();
	}

	return FinalDamage;
}


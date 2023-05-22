// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

UMyAnimInstance::UMyAnimInstance()
{
	CurrentPawnSpeed = 0.0f;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGE(TEXT("AnimMontage'/Game/BluePrint/AnimationMontage/AM_ShinbiAttack.AM_ShinbiAttack'"));
	if (ATTACK_MONTAGE.Succeeded())
	{
		AttackMontage = ATTACK_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> ATTACK_MONTAGER(TEXT("AnimMontage'/Game/BluePrint/AnimationMontage/AM_ShinbiAttackR.AM_ShinbiAttackR'"));
	if (ATTACK_MONTAGER.Succeeded())
	{
		AttackMontageR = ATTACK_MONTAGER.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage> DASH_MONTAGER(TEXT("AnimMontage'/Game/BluePrint/AnimationMontage/AM_ShinbiDash.AM_ShinbiDash'"));
	if (DASH_MONTAGER.Succeeded())
	{
		DashMontage = DASH_MONTAGER.Object;
	}

	bDead = false;
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}

}

void UMyAnimInstance::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.0f);
}

void UMyAnimInstance::PlayAttackMontageR()
{
	Montage_Play(AttackMontageR, 1.0f);
}

void UMyAnimInstance::PlayDashMontage()
{
	Montage_Play(DashMontage, 1.0f);
}

void UMyAnimInstance::AnimNotify_AttackHitNotifyL()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("AttackHitNotifyL"));
	OnAttackHitNotifyL.Broadcast();
}

void UMyAnimInstance::AnimNotify_AttackHitNotifyR()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("AttackHitNotifyR"));
	OnAttackHitNotifyR.Broadcast();
}

void UMyAnimInstance::AnimNotify_DashEnd()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("DashEndNotify"));
	OnDashEndNotify.Broadcast();
}

void UMyAnimInstance::AnimNotify_EnemyAttackHit()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("EnemyAttackHit"));
	OnEnemyAttackHitNotify.Broadcast();
}

void UMyAnimInstance::SetDead()
{
	bDead = true;
}

bool UMyAnimInstance::GetDashing()
{
	return bDashing;
}

void UMyAnimInstance::SetDashing(bool bDash)
{
	if (GEngine)
	{
		if (bDash)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("SetDashing True"));
		else
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("SetDashing False"));
	}

	bDashing = bDash;
}
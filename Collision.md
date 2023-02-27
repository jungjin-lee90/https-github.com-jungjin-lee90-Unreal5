# Collision
	AMyCharacter::AMyCharacter()
	{
		NameWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("NameWIDGET"));
		NameWidget->SetupAttachment(GetMesh());
		NameWidget->SetWidgetSpace(EWidgetSpace::Screen); // Screen은 2D, World는 3D
		static ConstructorHelpers::FClassFinder<UUserWidget> UI_NAME(TEXT("WidgetBlueprint'/Game/BluePrint/UI/BP_NameWidget.BP_NameWidget'")); // BP 참조할때는 _C 붙여줘야 한다.
		if (UI_NAME.Succeeded())
		{
			NameWidget->SetWidgetClass(UI_NAME.Class);
			NameWidget->SetDrawSize(FVector2D(70.0f, 20.0f));
		}
	}
	
	void AMyCharacter::BeginPlay()
	{
		if (NameWidget)
		{
			NameWidget->SetRelativeLocation(FVector(0.0f, 0.0f, NameHeight));
			auto MonsterNameWidget2 = Cast<UMyUserWidgetName>(NameWidget->GetUserWidgetObject());
			if (MonsterNameWidget2)
				MonsterNameWidget2->SetMonsterName(MonsterName); // 이러면 안되는데 그 이유는 순서가 BeginPlay->NativeConstruct 순서이기 때문이다.
		}								 // 때문에 Widget 소스에서 멤버로 해당 값을 받아 저장하고 있다가 NativeConstruct에서 바꿔주는 형태로 해야한다.
	}

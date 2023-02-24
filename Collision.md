# Collision
	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));
	HPBarWidget->SetupAttachment(GetMesh());
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen); // Screen은 2D, World는 3D
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_BAR(TEXT("WidgetBlueprint'/Game/BluePrint/UI/BP_HPWidget.BP_HPWidget_C'")); // BP 참조할때는 _C 붙여줘야 한다.
	if (UI_BAR.Succeeded())
	{
		HPBarWidget->SetWidgetClass(UI_BAR.Class);
		HPBarWidget->SetDrawSize(FVector2D(200.0f, 18.0f));
	}

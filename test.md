# 소스정리

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
            MyAnim->OnDashEndNotify.AddUObject(this, &AMyCharacter::DashEndNotify);
            MyAnim->OnEnemyAttackHitNotify.AddUObject(this, &AMyCharacter::EnemyAttackHit);
        }

        CurrentHP = MaxHP;
    }

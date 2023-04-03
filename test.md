# 소스정리

    void AMyCharacter::BeginPlay()
    {
        ...												 // 때문에 Widget 소스에서 멤버로 해당 값을 받아 저장하고 있다가 NativeConstruct에서 바꿔주는 형태로 해야한다.

        MyAnim = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
        if (MyAnim)
        {
            ...
            MyAnim->OnEnemyAttackHitNotify.AddUObject(this, &AMyCharacter::EnemyAttackHit);
        }

        CurrentHP = MaxHP;
    }

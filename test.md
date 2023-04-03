# 소스정리

    void AMyCharacter::BeginPlay()
    {
        ...

        MyAnim = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
        if (MyAnim)
        {
            ...
            MyAnim->OnEnemyAttackHitNotify.AddUObject(this, &AMyCharacter::EnemyAttackHit);
        }

        CurrentHP = MaxHP;
    }

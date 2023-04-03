# 소스정리

    void AMyCharacter::EnemyAttackHit()
    {
        //충돌 체크 해서 상대에게 데미지를 입힌다.
        float AttackRange = 100.0f;
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
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("AMyCharacter::EnemyAttackHit == true"));

            if (HitResult.GetActor())
            {
                UE_LOG(LogTemp, Warning, TEXT("Hit Actor Name : %s"), *HitResult.GetActor()->GetName());
                if (CurrentHP < MaxHP)  
                    CurrentHP += 10; // HP 증가
                UpdateCurrentHPWidget(CurrentHP); // Update HP Widget
                FDamageEvent DamageEvent;
                HitResult.GetActor()->TakeDamage(CurrentAttackDamage, DamageEvent, GetController(), this); // 공격 대상에게 데미지
            }
        }
        else
        {
            if (GEngine)
                GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("AMyCharacter::EnemyAttackHit == false"));
        }
    }

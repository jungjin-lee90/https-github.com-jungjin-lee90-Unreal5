# Collision
	//충돌 체크 해서 상대에게 데미지를 입힌다.
	float AttackRange = 400.0f;
	float AttackRadius = 50.0f;

	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);
	bool bResult = GetWorld()->SweepSingleByChannel(
		HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(AttackRadius),
		Params);

	if (bResult)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("AMyCharacter::AttackHitCheck == true"));

		if (HitResult.GetActor())
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor Name : %s"), *HitResult.GetActor()->GetName());

			FDamageEvent DamageEvent;
			HitResult.GetActor()->TakeDamage(50.0f, DamageEvent, GetController(), this);



			/*if (BloodEffect && ParticleFX1)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleFX1, HitResult.GetActor()->GetActorLocation());
			}*/
		}
	}
	else
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("AMyCharacter::AttackHitCheck == false"));
	}

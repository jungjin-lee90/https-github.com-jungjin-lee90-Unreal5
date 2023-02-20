# Collision
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

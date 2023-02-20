# Collision
	void UMyAnimInstance::AttackHitNotifyL()
	{
		OnAttackNotifyL.Broadcast();
	}

	void UMyAnimInstance::AttackHitNotifyR()
	{
		OnAttackNotifyR.Broadcast();
	}

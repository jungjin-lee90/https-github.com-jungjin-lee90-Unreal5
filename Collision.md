# Collision
	void UMyAnimInstance::AnimNotify_EnemyAttackHit()
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("EnemyAttackHit"));
		OnEnemyAttackHitNotify.Broadcast();
	}

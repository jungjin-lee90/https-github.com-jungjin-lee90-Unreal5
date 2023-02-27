# Collision
	void AMyCharacter::AttackHitNotifyL()
	{
		...
		HitResult.GetActor()->TakeDamage(CurrentAttackDamage, DamageEvent, GetController(), this);
	}
	

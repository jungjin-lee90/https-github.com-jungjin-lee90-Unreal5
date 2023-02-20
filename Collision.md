# Collision
	void AMyCharacter::Attack()
	{
		//if (IsAttacking) return;
		if (MyAnim)
		{
			AttackEffect->Activate();
			MyAnim->PlayAttackMontage();
			IsAttacking = true;
		}
	}
	
	void AMyCharacter::AttackHitNotifyR()
	{
		if (PowerUpEffect->IsActive())
			PowerUpEffect->Deactivate();
		else
			PowerUpEffect->Activate();
	}
	
	float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
	{
	...
		DamageEffect->Activate();
		MyAnim->SetDead();
	}

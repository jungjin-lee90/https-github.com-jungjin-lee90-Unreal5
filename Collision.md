# Collision
	void AMyCharacter::BeginPlay()
	{
	...
		MyAnim->OnAttackNotifyL.AddUObject(this, &AMyCharacter::AttackHitL);
		MyAnim->OnAttackNotifyR.AddUObject(this, &AMyCharacter::AttackHitR);	
	}
	
	void AMyCharacter::AttackHitL()
	{

	}

	void AMyCharacter::AttackHitR()
	{

	}

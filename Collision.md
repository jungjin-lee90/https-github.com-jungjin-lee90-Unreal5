# Collision
	void AMyCharacter::DoOnce()
	{
		FVector Location;
		LaunchCharacter(/*GetActorRotation() + */GetActorForwardVector() * 1400, false, false);
	}

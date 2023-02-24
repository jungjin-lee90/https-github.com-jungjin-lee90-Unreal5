# Collision
	void AMyCharacter::BeginPlay()
	{...
		if (HPBarWidget)
			HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, HPHeight));
	}

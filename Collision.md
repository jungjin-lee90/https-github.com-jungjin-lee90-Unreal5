# Collision
	UMyAnimInstance::UMyAnimInstance()
	{
		...
		static ConstructorHelpers::FObjectFinder<UAnimMontage> DASH_MONTAGER(TEXT("AnimMontage'/Game/BluePrint/AnimationMontage/AM_ShinbiDash.AM_ShinbiDash'"));
		if (DASH_MONTAGER.Succeeded())
		{
			DashMontage = DASH_MONTAGER.Object;
		}
	}	
	
	bool UMyAnimInstance::GetDashing()
	{
		return bDashing;
	}

	void UMyAnimInstance::SetDashing(bool bDash)
	{
		if (GEngine)
		{
			if (bDash)
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("SetDashing True"));
			else
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("SetDashing False"));
		}

		bDashing = bDash;
	}

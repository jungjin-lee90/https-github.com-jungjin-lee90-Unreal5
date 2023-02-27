# Collision
	float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
	{
		float fDamage = DamageAmount - Defense;
		CurrentHP -= fDamage;
		if (MaxHP > 0)
		{
			float HPRate = CurrentHP / MaxHP;
			if (HPRate < 0)
				HPRate = 0.0f;
			UE_LOG(LogTemp, Warning, TEXT("CurrentHP : %f, HP Rate : %f"), CurrentHP, HPRate);

			auto HPWidget = Cast<UMyUserWidget>(HPBarWidget->GetUserWidgetObject());
			if (HPWidget)
				HPWidget->SetHP(HPRate);

			/*auto DamageWidget2 = Cast<UMyUserWidgetDamage>(DamageWidget->GetUserWidgetObject());
			if (DamageWidget2)
				DamageWidget2->SetDamageText(fDamage);*/
		}
	}

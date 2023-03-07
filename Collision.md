# Collision
	void AMyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
	{ // 여긴 몽타주 끝나면 타는 곳이라 이름으로 일단 구분해줬다. 더 좋은 방법이 있긴 할것 같다.
		if (Montage->GetName() != "AM_ShinbiDash")
		{
			IsAttacking = false;
		}
		else if (Montage->GetName() == "AM_ShinbiDash")
		{
			if (MyAnim)
				MyAnim->SetDashing(false);
		}
	}
	
	void AMyCharacter::DoOnce()
	{
		if (MyAnim)
		{
			if (MyAnim->GetDashing()) return;
			MyAnim->PlayDashMontage(); // Dash몽타주 플레이
			MyAnim->SetDashing(true); // 대쉬중 체크.
		}
		FVector Location;
		LaunchCharacter(/*GetActorRotation() + */GetActorForwardVector() * 1900, false, false); // 캐릭터 전진
	}

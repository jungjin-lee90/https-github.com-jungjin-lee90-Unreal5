// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackHitNotifyLDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitNotifyRDelegate);
DECLARE_MULTICAST_DELEGATE(FOnDashEndNotifyDelegate);
DECLARE_MULTICAST_DELEGATE(FOnEnemyAttackHitNotifyRDelegate);

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UMyAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	void PlayAttackMontage();
	void PlayAttackMontageR();
	void PlayDashMontage();

	UFUNCTION()
	void AnimNotify_AttackHitNotifyL();
	UFUNCTION()
	void AnimNotify_AttackHitNotifyR();
	UFUNCTION()
	void AnimNotify_DashEnd();
	UFUNCTION()
	void AnimNotify_EnemyAttackHit();

	FOnAttackHitNotifyLDelegate OnAttackHitNotifyL;
	FOnAttackHitNotifyRDelegate OnAttackHitNotifyR;
	FOnDashEndNotifyDelegate OnDashEndNotify;
	FOnEnemyAttackHitNotifyRDelegate OnEnemyAttackHitNotify;

	void SetDead();

	bool GetDashing();
	void SetDashing(bool bDash);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontageR;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Dash, Meta = (AllowPrivateAccess = true))
	UAnimMontage* DashMontage;

	UPROPERTY(BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool bDead;

	bool bDashing = false;
};

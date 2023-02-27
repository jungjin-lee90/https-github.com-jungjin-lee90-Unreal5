// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackHitNotifyLDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitNotifyRDelegate);
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

	UFUNCTION()
	void AnimNotify_AttackHitNotifyL();
	UFUNCTION()
	void AnimNotify_AttackHitNotifyR();

	FOnAttackHitNotifyLDelegate OnAttackHitNotifyL;
	FOnAttackHitNotifyRDelegate OnAttackHitNotifyR;

	void SetDead();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontageR;

	UPROPERTY(BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool bDead;
};

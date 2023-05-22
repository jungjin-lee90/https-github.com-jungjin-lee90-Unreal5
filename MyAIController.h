// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AMyAIController();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;

	static const FName EnemyHomePosKey;
	static const FName EnemyPatrolPosKey;
	static const FName EnemyTargetKey;

	static const FName EnemyHomePosArcherKey;
	static const FName EnemyPatrolPosArcherKey;
	static const FName EnemyTargetArcherKey;

private:
	void OnTimer();

	FTimerHandle AITimerHandle;
	float TimerInterval;
};

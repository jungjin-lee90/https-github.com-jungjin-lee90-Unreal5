// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "MyBTService_EnemyDetect.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBTService_EnemyDetect : public UBTService
{
	GENERATED_BODY()
public:
	UMyBTService_EnemyDetect();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DetalSeconds) override;
};

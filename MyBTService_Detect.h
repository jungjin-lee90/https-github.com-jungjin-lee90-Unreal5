// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTService.h"
#include "MyBTService_Detect.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBTService_Detect : public UBTService
{
	GENERATED_BODY()
public:
	UMyBTService_Detect();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DetalSeconds) override;
};

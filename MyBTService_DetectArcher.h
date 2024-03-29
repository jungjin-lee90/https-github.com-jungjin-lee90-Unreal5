// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTService.h"
#include "MyBTService_DetectArcher.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBTService_DetectArcher : public UBTService
{
	GENERATED_BODY()

public:
	UMyBTService_DetectArcher();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DetalSeconds) override;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "MyBTDecorator_CheckHP.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBTDecorator_CheckHP : public UBTDecorator
{
	GENERATED_BODY()

public:
	UMyBTDecorator_CheckHP();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
};

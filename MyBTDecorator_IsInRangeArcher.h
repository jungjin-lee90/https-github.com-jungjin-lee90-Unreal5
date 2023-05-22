// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "MyBTDecorator_IsInRangeArcher.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBTDecorator_IsInRangeArcher : public UBTDecorator
{
	GENERATED_BODY()

public:
	UMyBTDecorator_IsInRangeArcher();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
};

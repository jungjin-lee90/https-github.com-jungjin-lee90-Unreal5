// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTaskNode_Attack.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBTTaskNode_Attack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UMyBTTaskNode_Attack();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

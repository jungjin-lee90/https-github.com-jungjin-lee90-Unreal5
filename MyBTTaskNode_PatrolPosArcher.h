// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTaskNode_PatrolPosArcher.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBTTaskNode_PatrolPosArcher : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UMyBTTaskNode_PatrolPosArcher();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

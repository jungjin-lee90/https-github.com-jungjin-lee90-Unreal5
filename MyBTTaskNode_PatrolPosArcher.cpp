// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTaskNode_PatrolPosArcher.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "MyCharacter.h"

UMyBTTaskNode_PatrolPosArcher::UMyBTTaskNode_PatrolPosArcher()
{
	NodeName = TEXT("FindPatrolPosArcher");
}

EBTNodeResult::Type UMyBTTaskNode_PatrolPosArcher::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return EBTNodeResult::Failed;


	auto NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem)
		return EBTNodeResult::Failed;

	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AMyAIController::EnemyHomePosArcherKey);
	FNavLocation NextPatrol;

	if (NavSystem->GetRandomPointInNavigableRadius(Origin, 500.0f, NextPatrol)) // 500.f 반경에 아무 값이나 리턴해줌, 다만 네비 메쉬가 있어야함.
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(AMyAIController::EnemyPatrolPosArcherKey, NextPatrol.Location); // vertor 값 셋팅
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

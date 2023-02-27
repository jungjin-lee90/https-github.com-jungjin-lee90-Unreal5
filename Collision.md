# Collision
	#include "MyAIController.h"
	#include "BehaviorTree/BlackboardComponent.h"
	#include "NavigationSystem.h"

	UMyBTTaskNode_FindPatrolPos::UMyBTTaskNode_FindPatrolPos()
	{
		NodeName = TEXT("FindPatrolPos");
	}

	EBTNodeResult::Type UMyBTTaskNode_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
	{
		EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

		auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
		if (nullptr == ControllingPawn)
			return EBTNodeResult::Failed;

		auto NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
		if (nullptr == NavSystem)
			return EBTNodeResult::Failed;

		FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AMyAIController::HomePosKey);
		FNavLocation NextPatrol;

		if (NavSystem->GetRandomPointInNavigableRadius(Origin, 500.0f, NextPatrol)) // 500.f 반경에 아무 값이나 리턴해줌, 다만 네비 메쉬가 있어야함.
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(AMyAIController::PatrolPosKey, NextPatrol.Location); // vertor 값 셋팅
			return EBTNodeResult::Succeeded;
		}


		return EBTNodeResult::Failed;
	}

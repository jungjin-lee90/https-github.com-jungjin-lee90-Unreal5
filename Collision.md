# Collision
	#include "MyAIController.h"
	#include "MyCharacter.h"
	#include "BehaviorTree/BlackboardComponent.h"

	UMyBTDecorator_IsInAttackRange::UMyBTDecorator_isInAttackRange()
	{
		NodeName = TEXT("CanAttack");
	}

	bool UMyBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
	{
		bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

		auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
		if (nullptr == ControllingPawn)
			return false;

		//FName TargetKey = TEXT("PlayerTarget");
		auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AMyAIController::TargetKey));

		if (nullptr == Target)
			return false;

		float Distance = Target->GetDistanceTo(ControllingPawn);
		return Distance <= 200.0f;
	}

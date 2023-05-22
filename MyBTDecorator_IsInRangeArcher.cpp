// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTDecorator_IsInRangeArcher.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTDecorator_IsInRangeArcher::UMyBTDecorator_IsInRangeArcher()
{
	NodeName = TEXT("CanAttackArcher");
}

bool UMyBTDecorator_IsInRangeArcher::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return false;

	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AMyAIController::EnemyTargetArcherKey));

	if (nullptr == Target)
		return false;

	float Distance = Target->GetDistanceTo(ControllingPawn);
	return Distance <= 400.0f;
}

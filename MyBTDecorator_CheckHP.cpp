// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTDecorator_CheckHP.h"
#include "MyCharacter.h"
#include "MyAIController.h"

UMyBTDecorator_CheckHP::UMyBTDecorator_CheckHP()
{
	NodeName = TEXT("CheckHP");
}

bool UMyBTDecorator_CheckHP::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto MyC = Cast<AMyCharacter>(OwnerComp.GetAIOwner()->GetCharacter());

	if (nullptr == MyC)
		return false;

	if (MyC->CurrentHP > 0)
		return true;
	else
		return false;
}


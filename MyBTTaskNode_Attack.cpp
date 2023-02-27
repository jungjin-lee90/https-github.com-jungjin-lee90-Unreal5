// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTaskNode_Attack.h"
#include "MyAIController.h"
#include "MyCharacter.h"

UMyBTTaskNode_Attack::UMyBTTaskNode_Attack()
{

	bNotifyTick = true; // 틱 함수 호출
}

EBTNodeResult::Type UMyBTTaskNode_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("UMyBTTaskNode_Attack::ExecuteTask"));

	auto MyC = Cast<AMyCharacter>(OwnerComp.GetAIOwner()->GetCharacter());
	if (nullptr == MyC)
		return EBTNodeResult::Failed;

	if (MyC->CurrentHP > 0)
		MyC->Attack();

	return EBTNodeResult::InProgress; // 대기
}

void UMyBTTaskNode_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("UMyBTTaskNode_Attack::TickTask"));

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}


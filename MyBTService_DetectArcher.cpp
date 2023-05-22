// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_DetectArcher.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UMyBTService_DetectArcher::UMyBTService_DetectArcher()
{
	NodeName = TEXT("Detect_EnemyArcher");
	Interval = 1.0f;
}

void UMyBTService_DetectArcher::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DetalSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DetalSeconds);

	UE_LOG(LogTemp, Warning, TEXT("UMyBTService_DetectArcher::TickNode %s"), *NodeName);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn(); // Pawn ��������
	if (nullptr == ControllingPawn)
		return;

	UWorld* World = ControllingPawn->GetWorld(); // World ��������
	FVector Center = ControllingPawn->GetActorLocation(); // Centor �� ��������
	float DetectRadius = 600.0f; // ��Ī�� ����

	if (nullptr == World)
		return;

	TArray<FOverlapResult> OverlapResults;						// �ڱ� �ڽ��� ����.
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity, // ȸ������ �ʴ� ��
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(DetectRadius), // ���� ���� ��Ī ���� ����
		CollisionQueryParam
	);

	if (bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor()); // �ٿ�ĳ����
			if (MyCharacter && MyCharacter->GetController()->IsPlayerController()) // �÷��̾ ��Ʈ�� �ϴ� MyCharacter�� ó��
			{
				if (MyCharacter->CurrentHP > 0)
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMyAIController::EnemyTargetArcherKey, MyCharacter); // ������ TargetKey�� �� ����
					DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);

					DrawDebugPoint(World, MyCharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
					DrawDebugLine(World, ControllingPawn->GetActorLocation(), MyCharacter->GetActorLocation(), FColor::Blue, false, 0.27f);
					return;
				}
			}
		}
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMyAIController::EnemyTargetArcherKey, nullptr);
	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
}


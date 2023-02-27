# Collision
	#include "MyAIController.h"
	#include "MyCharacter.h"
	#include "BehaviorTree/BlackboardComponent.h"
	#include "DrawDebugHelpers.h"

	UMyBTService_Detect::UMyBTService_Detect()
	{
		NodeName = TEXT("Detect");
		Interval = 1.0f;
	}

	void UMyBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DetalSeconds)
	{
		Super::TickNode(OwnerComp, NodeMemory, DetalSeconds);

		UE_LOG(LogTemp, Warning, TEXT("UMyBTService_Detect::TickNode %s"), *NodeName);

		APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn(); // Pawn 가져오기
		if (nullptr == ControllingPawn)
			return;

		UWorld* World = ControllingPawn->GetWorld(); // World 가져오기
		FVector Center = ControllingPawn->GetActorLocation(); // Centor 값 가져오기
		float DetectRadius = 600.0f; // 서칭할 범위

		if (nullptr == World)
			return;

		TArray<FOverlapResult> OverlapResults;						// 자기 자신은 제외.
		FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
		bool bResult = World->OverlapMultiByChannel(
			OverlapResults,
			Center,
			FQuat::Identity, // 회전하지 않는 값
			ECollisionChannel::ECC_GameTraceChannel1,
			FCollisionShape::MakeSphere(DetectRadius), // 몬스터 주위 서칭 범위 설정
			CollisionQueryParam
		);

		if (bResult)
		{
			for (auto const& OverlapResult : OverlapResults)
			{
				AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor()); // 다운캐스팅
				if (MyCharacter && MyCharacter->GetController()->IsPlayerController()) // 플레이어가 컨트롤 하는 MyCharacter만 처리
				{
					if (MyCharacter->CurrentHP > 0)
					{
						OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMyAIController::TargetKey, MyCharacter); // 블랙보드 TargetKey에 값 셋팅
						DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);

						DrawDebugPoint(World, MyCharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
						DrawDebugLine(World, ControllingPawn->GetActorLocation(), MyCharacter->GetActorLocation(), FColor::Blue, false, 0.27f);
						return;
					}
				}
			}
		}

		OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMyAIController::TargetKey, nullptr);
		DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
	}

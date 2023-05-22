// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

const FName AMyAIController::HomePosKey(TEXT("HomePos"));
const FName AMyAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AMyAIController::TargetKey(TEXT("Target"));

const FName AMyAIController::EnemyHomePosKey(TEXT("EnemyHomePos"));
const FName AMyAIController::EnemyPatrolPosKey(TEXT("EnemyPatrolPos"));
const FName AMyAIController::EnemyTargetKey(TEXT("EnemyTarget"));

const FName AMyAIController::EnemyHomePosArcherKey(TEXT("EnemyHomePosArcher"));
const FName AMyAIController::EnemyPatrolPosArcherKey(TEXT("EnemyPatrolPosArcher"));
const FName AMyAIController::EnemyTargetArcherKey(TEXT("EnemyTargetArcher"));



AMyAIController::AMyAIController()
{
	//TimerInterval = 3.0f;
}

void AMyAIController::OnTimer()
{
	UE_LOG(LogTemp, Warning, TEXT("AMyAIController::OnTimer"));
	//APawn* CurrentPawn = GetPawn();
	//if (CurrentPawn)
	//{
	//	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	//	if (nullptr == NavSystem)
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("NavSystem is nullptr!"));
	//		return;
	//	}

	//	FNavLocation NextLocation;
	//	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation)) // 500.f 반경에 아무 값이나 리턴해줌, 다만 네비 메쉬가 있어야함.
	//	{
	//		//UNavigationSystemV1::SimpleMoveToLocation(this, NextLocation.Location); // 이건 안되네,..?
	//		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation.Location); // 리턴해준 값으로 이동.
	//		UE_LOG(LogTemp, Warning, TEXT("Next Location : %s"), *NextLocation.Location.ToString());
	//	}
	//}
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	//GetWorld()->GetTimerManager().SetTimer(AITimerHandle, this, &AMyAIController::OnTimer, TimerInterval, true); // Timer
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();
	//GetWorld()->GetTimerManager().ClearTimer(AITimerHandle);
}
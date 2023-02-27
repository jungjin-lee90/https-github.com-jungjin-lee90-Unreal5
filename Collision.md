# Collision
	#include "MyAIController.h"

	// Sets default values
	AMyCharacter::AMyCharacter()
	{
	...
		AIControllerClass = AMyAIController::StaticClass(); // AI Controller, 따로 셋팅해주지 않으면 전부 같은 동작을 하게끔 되어 있다.
		AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned; // 새롭게 생성되는 MyCharacter 마다 AMyIController 액터가 생성되며, 플레이어가 조종하는 캐릭터를 제외한 모든 캐릭터는 MYAIController 의 지배
	}

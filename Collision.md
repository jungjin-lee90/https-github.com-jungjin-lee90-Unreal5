# Collision
	#include "MyAnimInstance.generated.h"
	
	DECLARE_MULTICAST_DELEGATE(FOnAttackHitNotifyLDelegate);
	DECLARE_MULTICAST_DELEGATE(FOnAttackHitNotifyRDelegate);
	...
	public:
	...
		FOnAttackHitNotifyLDelegate OnAttackNotifyL;
		FOnAttackHitNotifyRDelegate OnAttackNotifyR;

# Collision
	DECLARE_MULTICAST_DELEGATE(FOnDashEndNotifyDelegate);
	DECLARE_MULTICAST_DELEGATE(FOnEnemyAttackHitNotifyRDelegate);
	...
	public:
		UFUNCTION()
		void AnimNotify_EnemyAttackHit();
		...
		FOnEnemyAttackHitNotifyRDelegate OnEnemyAttackHitNotify;

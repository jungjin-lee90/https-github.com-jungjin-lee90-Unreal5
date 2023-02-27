# Collision
	public:
		UMyBTDecorator_IsInAttackRange();

	protected:
		virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

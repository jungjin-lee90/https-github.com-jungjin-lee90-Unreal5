# Collision
	public:
	...
		float CurrentHP;
		
	private:
	...
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		float Defense;
		
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		float MaxHP;
		
		float DefaultDamage = 50;

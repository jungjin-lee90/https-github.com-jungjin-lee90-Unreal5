# Collision
	public:
	...
		UPROPERTY(VisibleAnywhere, Category = UI)
		class UWidgetComponent* NameWidget;
		
	private:
	...
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI, Meta = (AllowPrivateAccess = true))
		float NameHeight;
		
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI, Meta = (AllowPrivateAccess = true))
		FText MonsterName;

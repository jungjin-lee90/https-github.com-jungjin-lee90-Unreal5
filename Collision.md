# Collision
	protected:
		virtual void NativeConstruct() override;

	private:
		UPROPERTY()
		class UTextBlock* NameTextBox;

		FText NameText;

	public:
		void SetMonsterName(FText str);

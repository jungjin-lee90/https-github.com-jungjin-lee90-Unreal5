# Collision
	protected:
		virtual void NativeConstruct() override;

	private:
		UPROPERTY()
		class UProgressBar* HPProgressBar;

		float fCurrentHP;
	public:
		void SetHP(float HP);

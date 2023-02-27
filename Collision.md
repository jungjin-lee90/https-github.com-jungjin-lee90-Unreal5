# Collision
	public:
		AMyAIController();
		virtual void OnPossess(APawn* InPawn) override;
		virtual void OnUnPossess() override;

		static const FName HomePosKey;  // 이건 나중에 쓸건데 일단 미리 만들어 둔다.
		static const FName PatrolPosKey; // 이건 나중에 쓸건데 일단 미리 만들어 둔다.
		static const FName TargetKey; // 이건 나중에 쓸건데 일단 미리 만들어 둔다.

	private:
		void OnTimer();

		FTimerHandle AITimerHandle;
		float TimerInterval;

# Collision
	PowerUpEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PowerUpEffect"));
	PowerUpEffect->SetupAttachment(RootComponent);
	PowerUpEffect->bAutoActivate = false;

	AttackEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("AttackEffect"));
	AttackEffect->SetupAttachment(RootComponent);
	AttackEffect->bAutoActivate = false;

	DamageEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("DamageEffect"));
	DamageEffect->SetupAttachment(RootComponent);
	DamageEffect->bAutoActivate = false;

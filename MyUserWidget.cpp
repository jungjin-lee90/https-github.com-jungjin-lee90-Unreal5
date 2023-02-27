// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/ProgressBar.h"

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	HPProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("HPBar")));
	if (HPProgressBar)
	{
		fCurrentHP = 100.0f;
		HPProgressBar->SetPercent(fCurrentHP);
	}
}

void UMyUserWidget::SetHP(float HP)
{
	fCurrentHP = HP;
	HPProgressBar->SetPercent(HP);
}
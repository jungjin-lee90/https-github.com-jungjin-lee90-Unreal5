// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidgetName.h"
#include "Components/TextBlock.h"

void UMyUserWidgetName::NativeConstruct()
{
	Super::NativeConstruct();

	NameTextBox = Cast<UTextBlock>(GetWidgetFromName(TEXT("TB_Name")));
	if (NameTextBox)
	{
		NameTextBox->SetText(NameText);
	}
}


void UMyUserWidgetName::SetMonsterName(FText str)
{
	NameText = str;
}

# Collision
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

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidgetName.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyUserWidgetName : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY()
	class UTextBlock* NameTextBox;

	FText NameText;

public:
	void SetMonsterName(FText str);
};

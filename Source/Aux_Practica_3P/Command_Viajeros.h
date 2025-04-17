// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"

#include "Command_Viajeros.generated.h"

UCLASS()
class AUX_PRACTICA_3P_API UCommand_Viajeros : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* Button1;

	UPROPERTY(meta = (BindWidget))
	UButton* Button2;

	UFUNCTION()
	void OnViajeroErranteClicked();

	UFUNCTION()
	void OnViajeroCuadranteClicked();
};

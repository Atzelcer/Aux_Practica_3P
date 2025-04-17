// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Command_Viajeros.h"
#include "HUD_viajero.generated.h"



UCLASS()
class AUX_PRACTICA_3P_API AHUD_viajero : public AHUD
{
	GENERATED_BODY()

private: 
	AHUD_viajero();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	UUserWidget* WidgetInstancia;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> WidgetClass;
};
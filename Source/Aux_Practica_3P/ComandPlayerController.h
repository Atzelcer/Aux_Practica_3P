// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ComandPlayerController.generated.h"


UCLASS()
class AUX_PRACTICA_3P_API AComandPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Estos métodos los llamará el HUD
	UFUNCTION(BlueprintCallable)
	void EjecutarComandoErrante();

	UFUNCTION(BlueprintCallable)
	void EjecutarComandoCuadrante();
	
};

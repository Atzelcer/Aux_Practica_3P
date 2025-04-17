// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Aux_Practica_3PGameMode.generated.h"

UCLASS(minimalapi)
class AAux_Practica_3PGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAux_Practica_3PGameMode();


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	class AViajeroErrante* ViajeroErrantePtr;
	class AViajeroCuadrante* ViajeroCuadrantePtr;

	UWorld* Mundo;

	FVector PosMaximaErrante;
	FVector PosMaximaCuadrante;

	FTimerHandle TimerActualizar;
	FTimerHandle TimerFinal;

	void ActualizarPosiciones();

};




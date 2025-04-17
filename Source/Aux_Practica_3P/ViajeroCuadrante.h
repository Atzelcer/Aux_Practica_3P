// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ViajeroSuperior.h"
#include "Command.h"
#include "ViajeroCuadrante.generated.h"


UCLASS()
class AUX_PRACTICA_3P_API AViajeroCuadrante : public AViajeroSuperior, public ICommand
{
	GENERATED_BODY()

private:
	AViajeroCuadrante();


protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void MoverActor(float DeltaTime) override;

private:
	float Angulo;
	float Radio;
	FVector Centro;

	virtual void Ejecutar() override;

	
};

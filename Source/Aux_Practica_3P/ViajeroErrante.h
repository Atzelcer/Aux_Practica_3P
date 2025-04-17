// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ViajeroSuperior.h"
#include "Command.h"
#include "ViajeroErrante.generated.h"


UCLASS()
class AUX_PRACTICA_3P_API AViajeroErrante : public AViajeroSuperior, public ICommand
{
	GENERATED_BODY()

private:

	AViajeroErrante();

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void MoverActor(float DeltaTime) override;

private:

	FVector DireccionActual;

	virtual void Ejecutar() override;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Command.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCommand : public UInterface
{
	GENERATED_BODY()
};


class AUX_PRACTICA_3P_API ICommand
{
	GENERATED_BODY()

public:

	virtual void Ejecutar() = 0;
};

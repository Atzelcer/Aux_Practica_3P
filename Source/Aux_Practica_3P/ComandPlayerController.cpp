// Fill out your copyright notice in the Description page of Project Settings.


#include "ComandPlayerController.h"
#include "Engine/Engine.h"

void AComandPlayerController::EjecutarComandoErrante()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("Comando: Instanciar Viajero Errante"));
	// Aquí puedes instanciar un viajero, o ejecutar un comando real
}

void AComandPlayerController::EjecutarComandoCuadrante()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, TEXT("Comando: Instanciar Viajero Cuadrante"));
}
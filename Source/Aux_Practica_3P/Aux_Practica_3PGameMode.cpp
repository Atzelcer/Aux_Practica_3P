// Copyright Epic Games, Inc. All Rights Reserved.

#include "Aux_Practica_3PGameMode.h"
#include "Aux_Practica_3PCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "ViajeroErrante.h"
#include "ViajeroCuadrante.h"
#include "HUD_viajero.h"

AAux_Practica_3PGameMode::AAux_Practica_3PGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// Asignar HUD personalizado
	HUDClass = AHUD_viajero::StaticClass();

	ViajeroErrantePtr = nullptr;
	ViajeroCuadrantePtr = nullptr;
}

void AAux_Practica_3PGameMode::BeginPlay()
{
	Super::BeginPlay();

	Mundo = GetWorld();

	if (!Mundo) return;

	FRotator Rot = FRotator::ZeroRotator;

	ViajeroErrantePtr = Mundo->SpawnActor<AViajeroErrante>(AViajeroErrante::StaticClass(), FVector(0.f, -300.f, 100.f), Rot);
	ViajeroCuadrantePtr = Mundo->SpawnActor<AViajeroCuadrante>(AViajeroCuadrante::StaticClass(), FVector(0.f, 300.f, 100.f), Rot);

	PosMaximaErrante = ViajeroErrantePtr ? ViajeroErrantePtr->GetActorLocation() : FVector::ZeroVector;
	PosMaximaCuadrante = ViajeroCuadrantePtr ? ViajeroCuadrantePtr->GetActorLocation() : FVector::ZeroVector;

	Mundo->GetTimerManager().SetTimer(TimerActualizar, this, &AAux_Practica_3PGameMode::ActualizarPosiciones, 10.0f, true);
}

void AAux_Practica_3PGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Mundo->GetTimerManager().SetTimer(TimerActualizar, this, &AAux_Practica_3PGameMode::ActualizarPosiciones, 10.0f, true);


}

void AAux_Practica_3PGameMode::ActualizarPosiciones()
{
	if (ViajeroErrantePtr)
	{
		FVector Actual = ViajeroErrantePtr->GetActorLocation();
		if (Actual.Size() > PosMaximaErrante.Size())
			PosMaximaErrante = Actual;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan,
			FString::Printf(TEXT("Errante más alejado: %s"), *PosMaximaErrante.ToString()));
	}

	if (ViajeroCuadrantePtr)
	{
		FVector Actual = ViajeroCuadrantePtr->GetActorLocation();
		if (Actual.Size() > PosMaximaCuadrante.Size())
			PosMaximaCuadrante = Actual;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange,
			FString::Printf(TEXT("Cuadrante más alejado: %s"), *PosMaximaCuadrante.ToString()));
	}
}

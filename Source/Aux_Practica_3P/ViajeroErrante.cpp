// Fill out your copyright notice in the Description page of Project Settings.


#include "ViajeroErrante.h"
#include "UObject/ConstructorHelpers.h"


AViajeroErrante::AViajeroErrante()
{
	PrimaryActorTick.bCanEverTick = true;
	// Asignar el StaticMesh de la cápsula ancha
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule"));
	if (MeshAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(MeshAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f)); // Ajustar si es necesario
	}
}

void AViajeroErrante::BeginPlay()
{
	Super::BeginPlay();
}

void AViajeroErrante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverActor(DeltaTime);
}

void AViajeroErrante::MoverActor(float DeltaTime)
{
	float Magnitud = FMath::FRandRange(400.f, 700.f);
	DireccionActual = FVector(
		FMath::FRandRange(-7.0f, 5.0f),
		FMath::FRandRange(5.0f, -9.0f),
		0.0f
	).GetSafeNormal();

	// Escala con velocidad variable
	float Velocidad = FMath::FRandRange(300.f, 600.f);

	FVector Desplazamiento = DireccionActual * Velocidad * DeltaTime;
	FVector NuevaPos = GetActorLocation() + Desplazamiento;

	SetActorLocation(NuevaPos);
}

void AViajeroErrante::Ejecutar()
{
}

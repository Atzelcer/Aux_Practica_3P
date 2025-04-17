// Fill out your copyright notice in the Description page of Project Settings.


#include "ViajeroCuadrante.h"
#include "UObject/ConstructorHelpers.h"

AViajeroCuadrante::AViajeroCuadrante()
{
	PrimaryActorTick.bCanEverTick = true;

	// Asignar el StaticMesh del cilindro
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (MeshAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(MeshAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
	}

	Angulo = 0.0f;
	Radio = 400.0f;
}

void AViajeroCuadrante::BeginPlay()
{
	Super::BeginPlay();
}

void AViajeroCuadrante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverActor(DeltaTime);
}

void AViajeroCuadrante::MoverActor(float DeltaTime)
{
	// Mantiene su centro original
	if (Centro.IsNearlyZero())
	{
		Centro = GetActorLocation();
	}

	Angulo += FMath::FRandRange(0.5f, 1.5f) * DeltaTime * 2.0f;

	FVector NuevaPos = Centro + FVector(
		FMath::Cos(Angulo) * Radio,
		FMath::Sin(Angulo) * Radio,
		0.0f
	);
	SetActorLocation(NuevaPos);
}

void AViajeroCuadrante::Ejecutar()
{
}

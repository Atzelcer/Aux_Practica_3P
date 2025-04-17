// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/AudioComponent.h"
#include "ViajeroSuperior.generated.h"

UCLASS()
class AUX_PRACTICA_3P_API AViajeroSuperior : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AViajeroSuperior();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:

	// COMPONENTES COMUNES
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	USphereComponent* ColisionEsfera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UAudioComponent* SonidoMovimiento;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UParticleSystemComponent* ParticulasFinal;

protected:
	// Método virtual puro que será implementado por cada hija
	virtual void MoverActor(float DeltaTime) PURE_VIRTUAL(AViajeroSuperior::MoverActor, );

	virtual void Destruction_Actor();

	float Life;

	virtual void InfluirDanio(float Danio);

};

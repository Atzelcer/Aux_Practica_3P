// Fill out your copyright notice in the Description page of Project Settings.


#include "ViajeroSuperior.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AViajeroSuperior::AViajeroSuperior()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ColisionEsfera = CreateDefaultSubobject<USphereComponent>(TEXT("ColisionEsfera"));
	RootComponent = ColisionEsfera;
	ColisionEsfera->InitSphereRadius(40.0f);
	ColisionEsfera->SetCollisionProfileName(TEXT("Pawn"));

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(RootComponent);

	SonidoMovimiento = CreateDefaultSubobject<UAudioComponent>(TEXT("SonidoMovimiento"));
	SonidoMovimiento->SetupAttachment(RootComponent);
	SonidoMovimiento->bAutoActivate = false;

	ParticulasFinal = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticulasFinal"));
	ParticulasFinal->SetupAttachment(RootComponent);
	ParticulasFinal->bAutoActivate = false;

	// Asignar el sonido desde contenido
	static ConstructorHelpers::FObjectFinder<USoundWave> Sonido(TEXT("/Game/StarterContent/Audio/Explosion02.Explosion02"));
	if (Sonido.Succeeded())
	{
		SonidoMovimiento->SetSound(Sonido.Object);
	}

	// Asignar el sistema de partículas desde contenido
	static ConstructorHelpers::FObjectFinder<UParticleSystem> Particula(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
	if (Particula.Succeeded())
	{
		ParticulasFinal->SetTemplate(Particula.Object);
	}

	Life = 400.0f;

}

// Called when the game starts or when spawned
void AViajeroSuperior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AViajeroSuperior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AViajeroSuperior::Destruction_Actor()
{
	if (SonidoMovimiento && !SonidoMovimiento->IsPlaying())
	{
		SonidoMovimiento->Play();
	}

	if (ParticulasFinal && !ParticulasFinal->IsActive())
	{
		ParticulasFinal->ActivateSystem();
	}

	Destroy();
}

void AViajeroSuperior::InfluirDanio(float Danio)
{
	Life -= Danio;
}


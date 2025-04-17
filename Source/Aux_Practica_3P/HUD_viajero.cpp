// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_viajero.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

AHUD_viajero::AHUD_viajero()
{
	// Cargar el Blueprint del Widget
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetBPClass(TEXT("/Game/HUD/ComandMovi"));
	if (WidgetBPClass.Succeeded())
	{
		WidgetClass = WidgetBPClass.Class;
	}
}

void AHUD_viajero::BeginPlay()
{
	Super::BeginPlay();

	if (WidgetClass)
	{
		WidgetInstancia = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
		if (WidgetInstancia)
		{
			WidgetInstancia->AddToViewport();
		}
	}
}
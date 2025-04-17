// Fill out your copyright notice in the Description page of Project Settings.


#include "Command_Viajeros.h"
#include "Components/Button.h"
#include "ComandPlayerController.h"
#include "Kismet/GameplayStatics.h"

void UCommand_Viajeros::NativeConstruct()
{
	Super::NativeConstruct();

	if (Button1)
		Button1->OnClicked.AddDynamic(this, &UCommand_Viajeros::OnViajeroErranteClicked);

	if (Button2)
		Button2->OnClicked.AddDynamic(this, &UCommand_Viajeros::OnViajeroCuadranteClicked);
}

void UCommand_Viajeros::OnViajeroErranteClicked()
{
	if (AComandPlayerController* PC = Cast<AComandPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		PC->EjecutarComandoErrante();
	}
}

void UCommand_Viajeros::OnViajeroCuadranteClicked()
{
	if (AComandPlayerController* PC = Cast<AComandPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		PC->EjecutarComandoCuadrante();
	}
}
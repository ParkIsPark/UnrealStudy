// Fill out your copyright notice in the Description page of Project Settings.

#include "Week3PlayerController.h"
#include "EngineUtils.h"
#include "Week3PossessSelector.h"
#include "Week3PlayerState.h"

void AWeek3PlayerController::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AWeek3PossessSelector> It(GetWorld()); It; ++It)
	{
		AWeek3PossessSelector* Selector = *It;
		if (IsValid(Selector) && IsValid(Selector->CharacterToControl))
		{
			Possess(Selector->CharacterToControl);
			break;
		}
	}
}

void AWeek3PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (InPawn)
	{
		LastPawnClass = InPawn->GetClass();
	}
}

void AWeek3PlayerController::ScheduleRespawn()
{
	if (APawn* P = GetPawn())
	{
		LastPawnLocation = P->GetActorLocation();
	}

	FTimerHandle RespawnHandle;
	GetWorldTimerManager().SetTimer(RespawnHandle, this, &AWeek3PlayerController::RespawnCharacter, 0.5f, false);
}

void AWeek3PlayerController::RespawnCharacter()
{
	if (!LastPawnClass) return;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	APawn* NewPawn = GetWorld()->SpawnActor<APawn>(LastPawnClass, LastPawnLocation, FRotator::ZeroRotator, Params);
	if (NewPawn)
	{
		Possess(NewPawn);
		if (AWeek3PlayerState* PS = GetPlayerState<AWeek3PlayerState>())
		{
			PS->ResetHP();
		}
	}
}

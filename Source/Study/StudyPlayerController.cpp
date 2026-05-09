// Fill out your copyright notice in the Description page of Project Settings.

#include "StudyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "EngineUtils.h"
#include "StudyPossessSelector.h"
#include "StudyPlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogStudyPC, Log, All);

void AStudyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AStudyPossessSelector> It(GetWorld()); It; ++It)
	{
		AStudyPossessSelector* Selector = *It;
		if (IsValid(Selector) && IsValid(Selector->CharacterToControl))
		{
			Possess(Selector->CharacterToControl);
			break;
		}
	}

	if (IsLocalController() && DefaultHUDWidgetClass)
	{
		UUserWidget* Widget = CreateWidget<UUserWidget>(this, DefaultHUDWidgetClass);
		if (Widget)
		{
			Widget->AddToViewport();
		}
	}
}

void AStudyPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (InPawn)
	{
		LastPawnClass = InPawn->GetClass();
	}
}

void AStudyPlayerController::HandlePlayerDeath()
{
	AStudyPlayerState* PS = GetPlayerState<AStudyPlayerState>();

	if (PS)
	{
		PS->DecrementRespawn();
	}

	// 폰 파괴는 PC의 책임.
	if (APawn* P = GetPawn())
	{
		LastPawnLocation = P->GetActorLocation();
		UnPossess();
		P->Destroy();
	}

	if (PS && PS->HasRespawnLeft())
	{
		ScheduleRespawn();
	}
	else
	{
		// 게임 오버 — 정식 UI는 9주차 범위. 5주차에서는 로그 + 입력 차단으로 마무리.
		UE_LOG(LogStudyPC, Warning, TEXT("Game Over — no respawns left."));
		DisableInput(this);
	}
}

void AStudyPlayerController::ScheduleRespawn()
{
	FTimerHandle RespawnHandle;
	GetWorldTimerManager().SetTimer(RespawnHandle, this, &AStudyPlayerController::RespawnCharacter, 0.5f, false);
}

void AStudyPlayerController::RespawnCharacter()
{
	if (!LastPawnClass) return;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	APawn* NewPawn = GetWorld()->SpawnActor<APawn>(LastPawnClass, LastPawnLocation, FRotator::ZeroRotator, Params);
	if (NewPawn)
	{
		Possess(NewPawn);
		if (AStudyPlayerState* PS = GetPlayerState<AStudyPlayerState>())
		{
			PS->ResetHP();
		}
	}
}

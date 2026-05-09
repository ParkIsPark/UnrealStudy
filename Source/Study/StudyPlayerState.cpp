// Fill out your copyright notice in the Description page of Project Settings.

#include "StudyPlayerState.h"
#include "StudyGameMode.h"
#include "Engine/World.h"
#include "GameFramework/GameModeBase.h"

AStudyPlayerState::AStudyPlayerState()
{
	MaxHP = 100.f;
	CurrentHP = 100.f;
}

void AStudyPlayerState::BeginPlay()
{
	Super::BeginPlay();
	CurrentHP = MaxHP;

	// 룰(GameMode) → 상태(PlayerState)로 복사. 노션 §"룰 vs 상태"의 핵심 흐름.
	if (UWorld* World = GetWorld())
	{
		if (AStudyGameMode* GM = World->GetAuthGameMode<AStudyGameMode>())
		{
			RemainingRespawns = GM->MaxRespawnCount;
		}
	}
}

void AStudyPlayerState::ApplyDamage(float DamageAmount)
{
	CurrentHP = FMath::Clamp(CurrentHP - DamageAmount, 0.f, MaxHP);
}

bool AStudyPlayerState::IsAlive() const
{
	return CurrentHP > 0.f;
}

void AStudyPlayerState::ResetHP()
{
	CurrentHP = MaxHP;
}

void AStudyPlayerState::DecrementRespawn()
{
	RemainingRespawns = FMath::Max(0, RemainingRespawns - 1);
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "StudyPlayerState.h"
#include "HealthComponent.h"
#include "StudyGameMode.h"
#include "Engine/World.h"
#include "GameFramework/GameModeBase.h"

AStudyPlayerState::AStudyPlayerState()
{
	// 7주차 — HP 컴포넌트를 부착. 생성자에서만 가능.
	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
}

void AStudyPlayerState::BeginPlay()
{
	Super::BeginPlay();

	// 룰(GameMode) → 상태(PlayerState)로 복사. 노션 §"룰 vs 상태"의 핵심 흐름.
	if (UWorld* World = GetWorld())
	{
		if (AStudyGameMode* GM = World->GetAuthGameMode<AStudyGameMode>())
		{
			RemainingRespawns = GM->MaxRespawnCount;
		}
	}
}

// ---- HP 래퍼 — 컴포넌트로 위임. 호출자(Character::OnTickDamage 등)는 한 줄도 안 바꾼다. ----

void AStudyPlayerState::ApplyDamage(float DamageAmount)
{
	if (Health) Health->ApplyDamage(DamageAmount);
}

void AStudyPlayerState::Heal(float HealAmount)
{
	if (Health) Health->Heal(HealAmount);
}

bool AStudyPlayerState::IsAlive() const
{
	return Health && Health->IsAlive();
}

void AStudyPlayerState::ResetHP()
{
	if (Health) Health->ResetHP();
}

void AStudyPlayerState::DecrementRespawn()
{
	RemainingRespawns = FMath::Max(0, RemainingRespawns - 1);
}

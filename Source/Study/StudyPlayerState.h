// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "StudyPlayerState.generated.h"

UCLASS()
class AStudyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AStudyPlayerState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHP = 100.f;

	UPROPERTY(BlueprintReadOnly, Category = "Stats")
	float CurrentHP = 100.f;

	/** 상태 — 이 플레이어에게 남은 부활 횟수. 룰(GameMode::MaxRespawnCount)에서 BeginPlay에 복사된다. */
	UPROPERTY(BlueprintReadOnly, Category = "Stats")
	int32 RemainingRespawns = 0;

	/** 데미지 배율 — 6주차 BP_DamageBoost가 set, 7주차 이후 공격 시스템이 read 예정. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float DamageMultiplier = 1.f;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ApplyDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void Heal(float HealAmount);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Stats")
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ResetHP();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void DecrementRespawn();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Stats")
	bool HasRespawnLeft() const { return RemainingRespawns > 0; }

protected:
	virtual void BeginPlay() override;
};

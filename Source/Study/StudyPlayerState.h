// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "StudyPlayerState.generated.h"

class UHealthComponent;

UCLASS()
class AStudyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AStudyPlayerState();

	/**
	 * 7주차 — HP 로직을 컴포넌트로 추출. PS는 더 이상 HP를 \"가지지\" 않고, Health에 위임한다.
	 * 다음 주 적도 같은 컴포넌트를 부착해서 같은 데미지 시스템을 쓴다.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
	UHealthComponent* Health;

	/** 상태 — 이 플레이어에게 남은 부활 횟수. 룰(GameMode::MaxRespawnCount)에서 BeginPlay에 복사된다. */
	UPROPERTY(BlueprintReadOnly, Category = "Stats")
	int32 RemainingRespawns = 0;

	/** 데미지 배율 — 6주차 BP_DamageBoost가 set, 7주차 이후 공격 시스템이 read 예정. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float DamageMultiplier = 1.f;

	// ---- HP 래퍼 — 4주차 호출자(Character::OnTickDamage 등)가 한 줄도 안 바뀌도록 시그니처 유지 ----

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ApplyDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void Heal(float HealAmount);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Stats")
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ResetHP();

	// ---- 부활 처리는 PS의 본질적 책임이라 그대로 둔다 ----

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void DecrementRespawn();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Stats")
	bool HasRespawnLeft() const { return RemainingRespawns > 0; }

protected:
	virtual void BeginPlay() override;
};

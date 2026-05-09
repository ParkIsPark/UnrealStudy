// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

/**
 * 7주차 — HP 시스템을 컴포넌트로 추출.
 *
 * 어떤 AActor에든 부착해서 \"체력 있는 액터\"로 만든다.
 * Player(=PlayerState)도, 8주차의 적도, 파괴 가능한 상자도 같은 컴포넌트를 쓴다.
 *
 * 이벤트는 Dynamic Multi-cast 델리게이트로 노출 — BP가 들을 수 있어야 하니까.
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, NewHP, float, MaxHPParam);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STUDY_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHP = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHP = 100.f;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void ApplyDamage(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(float Amount);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health")
	bool IsAlive() const { return CurrentHP > 0.f; }

	UFUNCTION(BlueprintCallable, Category = "Health")
	void ResetHP();

	/** HP가 변할 때마다 호출됨. HUD/사운드/포스트프로세스가 구독하는 메인 이벤트. */
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChanged OnHealthChanged;

	/** HP가 0에 도달한 \"바로 그 순간\" 한 번 호출. PlayerController의 사망 처리 / GameState의 EnemiesRemaining-- 등. */
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDeath OnDeath;

protected:
	virtual void BeginPlay() override;
};

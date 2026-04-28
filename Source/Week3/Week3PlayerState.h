// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Week3PlayerState.generated.h"

UCLASS()
class AWeek3PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AWeek3PlayerState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHP = 100.f;

	UPROPERTY(BlueprintReadOnly, Category = "Stats")
	float CurrentHP = 100.f;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ApplyDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Stats")
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ResetHP();

protected:
	virtual void BeginPlay() override;
};

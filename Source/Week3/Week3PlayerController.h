// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Week3PlayerController.generated.h"

UCLASS()
class AWeek3PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void ScheduleRespawn();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	void RespawnCharacter();

	TSubclassOf<APawn> LastPawnClass;
	FVector LastPawnLocation = FVector::ZeroVector;
};

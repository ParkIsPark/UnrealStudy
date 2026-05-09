// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StudyGameMode.generated.h"

UCLASS(minimalapi)
class AStudyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AStudyGameMode();

	/** 룰 — 한 판당 허용되는 최대 부활 횟수. 디자이너가 디테일 패널에서 0/3/999로 튜닝. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rules")
	int32 MaxRespawnCount = 3;
};

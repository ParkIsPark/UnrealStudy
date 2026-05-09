// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "StudyGameInstance.generated.h"

UCLASS()
class UStudyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/** 앱이 켜진 뒤 PIE/레벨 전환을 거치며 누적된 플레이 횟수. GameInstance는 앱 평생 살아있으므로 여기에 둔다. */
	UPROPERTY(BlueprintReadOnly, Category = "Persistent")
	int32 TotalPlayCount = 0;

	/** 이번 세션에서 도달한 최고 단계. 디스크 저장은 9주차 이후 범위. */
	UPROPERTY(BlueprintReadOnly, Category = "Persistent")
	int32 BestStageReached = 0;

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category = "Persistent")
	void ReportStageReached(int32 Stage);
};

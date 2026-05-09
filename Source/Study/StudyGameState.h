// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "StudyGameState.generated.h"

UCLASS()
class AStudyGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AStudyGameState();

	/** 진행 중인 단계 번호. 모든 클라이언트가 봐야 하므로 GameState. */
	UPROPERTY(BlueprintReadOnly, Category = "Stage")
	int32 CurrentStage = 1;

	/** 현재 웨이브 번호. */
	UPROPERTY(BlueprintReadOnly, Category = "Stage")
	int32 CurrentWave = 1;

	/** 다음 웨이브까지 남은 시간(초). HUD 좌상단에 표시. */
	UPROPERTY(BlueprintReadOnly, Category = "Stage")
	float TimeUntilNextWave = 30.f;

	/** 한 웨이브의 길이(초). 카운트다운이 0에 닿으면 이 값으로 리셋된다. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stage")
	float WaveDurationSeconds = 30.f;

	// single-player 기준이라 Tick에서 그대로 카운트다운한다. 멀티플레이로 확장되면
	// HasAuthority() 체크로 서버에서만 돌려야 한다 — 노션 §"핵심 질문" 참조.
	virtual void Tick(float DeltaSeconds) override;
};

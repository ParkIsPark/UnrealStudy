// Fill out your copyright notice in the Description page of Project Settings.

#include "StudyGameState.h"

AStudyGameState::AStudyGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStudyGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TimeUntilNextWave -= DeltaSeconds;
	if (TimeUntilNextWave <= 0.f)
	{
		++CurrentWave;
		TimeUntilNextWave = WaveDurationSeconds;
	}
}

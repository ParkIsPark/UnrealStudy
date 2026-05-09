// Fill out your copyright notice in the Description page of Project Settings.

#include "StudyGameInstance.h"

void UStudyGameInstance::Init()
{
	Super::Init();

	++TotalPlayCount;
}

void UStudyGameInstance::ReportStageReached(int32 Stage)
{
	BestStageReached = FMath::Max(BestStageReached, Stage);
}

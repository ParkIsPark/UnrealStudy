// Copyright Epic Games, Inc. All Rights Reserved.

#include "StudyGameMode.h"
#include "StudyCharacter.h"
#include "StudyGameState.h"
#include "StudyPlayerController.h"
#include "StudyPlayerState.h"
#include "UObject/ConstructorHelpers.h"

AStudyGameMode::AStudyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// 6개 매니저 매핑 — 학생이 GameMode 한 곳에서 모든 연결을 본다.
	GameStateClass        = AStudyGameState::StaticClass();
	PlayerControllerClass = AStudyPlayerController::StaticClass();
	PlayerStateClass      = AStudyPlayerState::StaticClass();
}

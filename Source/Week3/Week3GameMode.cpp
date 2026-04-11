// Copyright Epic Games, Inc. All Rights Reserved.

#include "Week3GameMode.h"
#include "Week3Character.h"
#include "UObject/ConstructorHelpers.h"

AWeek3GameMode::AWeek3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

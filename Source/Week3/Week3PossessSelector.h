// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Week3PossessSelector.generated.h"

UCLASS()
class AWeek3PossessSelector : public AActor
{
	GENERATED_BODY()

public:
	AWeek3PossessSelector();

	/** PlayerController가 BeginPlay에서 이 폰을 Possess 대상으로 사용한다 */
	UPROPERTY(EditAnywhere, Category = "Possess")
	APawn* CharacterToControl;
};

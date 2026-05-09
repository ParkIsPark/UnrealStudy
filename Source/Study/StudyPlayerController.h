// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StudyPlayerController.generated.h"

UCLASS()
class AStudyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/**
	 * Pawn(Character)이 자기 HP가 0이 되었음을 알릴 때 호출하는 단일 진입점.
	 * 죽음 결정과 Pawn 파괴 책임은 PC가 갖는다 (노션 Q6).
	 */
	UFUNCTION(BlueprintCallable, Category = "Lifecycle")
	void HandlePlayerDeath();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> DefaultHUDWidgetClass;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	void ScheduleRespawn();
	void RespawnCharacter();

	TSubclassOf<APawn> LastPawnClass;
	FVector LastPawnLocation = FVector::ZeroVector;
};

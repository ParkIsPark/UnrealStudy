// Fill out your copyright notice in the Description page of Project Settings.

#include "StudyJustPawn.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

AStudyJustPawn::AStudyJustPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStudyJustPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AStudyJustPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStudyJustPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AStudyJustPawn::Move);
	}
}

void AStudyJustPawn::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddActorWorldOffset(FVector(Input.Y, Input.X, 0.f) * MoveSpeed * GetWorld()->GetDeltaSeconds());
}

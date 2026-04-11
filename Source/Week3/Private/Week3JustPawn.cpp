// Fill out your copyright notice in the Description page of Project Settings.

#include "Week3JustPawn.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

AWeek3JustPawn::AWeek3JustPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWeek3JustPawn::BeginPlay()
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

void AWeek3JustPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeek3JustPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AWeek3JustPawn::Move);
	}
}

void AWeek3JustPawn::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddActorWorldOffset(FVector(Input.Y, Input.X, 0.f) * MoveSpeed * GetWorld()->GetDeltaSeconds());
}

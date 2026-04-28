// Fill out your copyright notice in the Description page of Project Settings.

#include "Week3PlayerState.h"

AWeek3PlayerState::AWeek3PlayerState()
{
	MaxHP = 100.f;
	CurrentHP = 100.f;
}

void AWeek3PlayerState::BeginPlay()
{
	Super::BeginPlay();
	CurrentHP = MaxHP;
}

void AWeek3PlayerState::ApplyDamage(float DamageAmount)
{
	CurrentHP = FMath::Clamp(CurrentHP - DamageAmount, 0.f, MaxHP);
}

bool AWeek3PlayerState::IsAlive() const
{
	return CurrentHP > 0.f;
}

void AWeek3PlayerState::ResetHP()
{
	CurrentHP = MaxHP;
}

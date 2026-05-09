// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	// 이벤트-주도. 매 프레임 할 일이 없다.
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// 디테일 패널에서 MaxHP를 바꿀 수 있으므로 시작 시점에 동기화.
	CurrentHP = MaxHP;
}

void UHealthComponent::ApplyDamage(float Amount)
{
	if (!IsAlive()) return; // 이미 죽었으면 무시 — 중복 OnDeath 방지

	CurrentHP = FMath::Clamp(CurrentHP - Amount, 0.f, MaxHP);

	// 값을 바꾼 \"직후\"에 알린다 — \"이 시점부터 새 값\"이라는 약속.
	OnHealthChanged.Broadcast(CurrentHP, MaxHP);

	if (CurrentHP <= 0.f)
	{
		OnDeath.Broadcast();
	}
}

void UHealthComponent::Heal(float Amount)
{
	if (!IsAlive()) return; // 죽은 후 회복 못함 (디자인 결정)

	CurrentHP = FMath::Clamp(CurrentHP + Amount, 0.f, MaxHP);
	OnHealthChanged.Broadcast(CurrentHP, MaxHP);
}

void UHealthComponent::ResetHP()
{
	CurrentHP = MaxHP;
	OnHealthChanged.Broadcast(CurrentHP, MaxHP);
}

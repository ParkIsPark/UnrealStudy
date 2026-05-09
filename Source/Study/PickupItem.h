// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupItem.generated.h"

class USphereComponent;
class UStaticMeshComponent;

/**
 * 모든 픽업 아이템의 베이스 — 6주차 실습의 메인 산출물.
 *
 * 의도적으로 Abstract: 베이스로 레벨에 못 놓고, BP 자식만 배치 가능.
 * BP 자식은 OnPickedUp을 오버라이드해 효과를 정의하고,
 * OnPlayPickupEffect는 디자이너가 시각/사운드 효과로 채운다.
 */
UCLASS(Abstract, Blueprintable)
class APickupItem : public AActor
{
	GENERATED_BODY()

public:
	APickupItem();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	USphereComponent* CollisionSphere;

	UPROPERTY(VisibleAnywhere, Category = "Pickup")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
	FText DisplayName;

	/** Native: C++ 기본 동작(효과 재생 + 자기파괴). BP 자식이 오버라이드해 효과 정의. */
	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
	void OnPickedUp(AActor* Picker);

	/** Implementable: C++엔 구현 없음. BP가 시각/사운드 효과를 채운다. */
	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
	void OnPlayPickupEffect();

	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleSphereOverlap(UPrimitiveComponent* OverlappedComponent,
	                         AActor* OtherActor,
	                         UPrimitiveComponent* OtherComp,
	                         int32 OtherBodyIndex,
	                         bool bFromSweep,
	                         const FHitResult& SweepResult);
};

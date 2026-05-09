// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupItem.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Pawn.h"

APickupItem::APickupItem()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->InitSphereRadius(64.f);
	CollisionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = CollisionSphere;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APickupItem::BeginPlay()
{
	Super::BeginPlay();

	if (CollisionSphere)
	{
		CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::HandleSphereOverlap);
	}
}

void APickupItem::HandleSphereOverlap(UPrimitiveComponent* OverlappedComponent,
                                      AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp,
                                      int32 OtherBodyIndex,
                                      bool bFromSweep,
                                      const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this)
	{
		return;
	}

	// Pawn(플레이어/AI 캐릭터)이 닿았을 때만 픽업 트리거.
	if (OtherActor->IsA<APawn>())
	{
		OnPickedUp(OtherActor);
	}
}

// BlueprintNativeEvent의 C++ 기본 구현. BP 자식이 오버라이드해도, Parent 노드를 호출하면 이 동작이 실행된다.
void APickupItem::OnPickedUp_Implementation(AActor* Picker)
{
	OnPlayPickupEffect();
	Destroy();
}

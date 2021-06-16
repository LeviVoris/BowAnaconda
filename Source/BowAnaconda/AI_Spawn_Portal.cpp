// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Spawn_Portal.h"

// Sets default values
AAI_Spawn_Portal::AAI_Spawn_Portal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_Spawn_Portal::BeginPlay()
{
	Super::BeginPlay();
	
}

/** Spawns and returns class T, forcibly sets world position. Example */
template< class T >
T* SpawnActor
(
	FVector const& Location,
	FRotator const& Rotation,
	AActor* Owner = NULL,
	APawn* Instigator = NULL,
	bool bNoCollisionFail = false
)
{
	return (T*)(GetWorld()->SpawnActor(T::StaticClass(), NAME_None, &Location, &Rotation, NULL, bNoCollisionFail, false, Owner, Instigator));
}

// Called every frame
void AAI_Spawn_Portal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


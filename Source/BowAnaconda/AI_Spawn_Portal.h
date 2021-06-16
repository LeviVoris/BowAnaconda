// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Simple_AICharacter.h"
#include "AI_Spawn_Portal.generated.h"

UCLASS()
class BOWANACONDA_API AAI_Spawn_Portal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAI_Spawn_Portal();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* SimpleAi;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

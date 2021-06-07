// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Simple_AICharacter.generated.h"

UCLASS()
class BOWANACONDA_API ASimple_AICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASimple_AICharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AWaypoint* NextWaypoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* Player;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

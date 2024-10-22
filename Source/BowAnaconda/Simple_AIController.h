// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Simple_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BOWANACONDA_API ASimple_AIController : public AAIController
{
	GENERATED_BODY()

public:
		ASimple_AIController();

		virtual void BeginPlay() override;
		virtual void OnPossess(APawn*) override;
		virtual void Tick(float DeltaSeconds) override;
		virtual FRotator GetControlRotation() const override;

		UFUNCTION()
			void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
			float AISightRadus = 1500.0f;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
			float AISightAge = 5.0f;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
			float AILoseSightRadus = AILoseSightRadus + 150.0f;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
			float AIFieldofView = 360.0f;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
			class UAISenseConfig_Sight* SightConfig;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
			bool bIsPlayerDetected = false;

		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
			float DistanceToPlayer = 0.0f;
};

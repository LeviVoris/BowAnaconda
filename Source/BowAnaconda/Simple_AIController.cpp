// Fill out your copyright notice in the Description page of Project Settings.


#include "Simple_AIController.h"
#include "Simple_AICharacter.h"
#include "Waypoint.h"
#include "Runtime\Engine\Classes\Kismet\GameplayStatics.h"
//#include "F:/Unreal/BowAnaconda/Content/FirstPersonBP/Blueprints/FirstPersonCharacter.uasset"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ASimple_AIController::ASimple_AIController()
{
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->SightRadius = AISightRadus;
	SightConfig->LoseSightRadius = AILoseSightRadus;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldofView;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ASimple_AIController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

}

void ASimple_AIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetPerceptionComponent() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("All Systems Set"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Problem in BeginPlay"));
	}
}

void ASimple_AIController::OnPossess(APawn* MyPawn)
{
	Super::OnPossess(MyPawn);
}

void ASimple_AIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//MoveToActor				Use this to have chase Player once all is done

	ASimple_AICharacter* Target = Cast<ASimple_AICharacter>(GetPawn());

	if (DistanceToPlayer > AISightRadus)
	{
		bIsPlayerDetected = false;
	}

	if (Target->NextWaypoint != nullptr && bIsPlayerDetected == false)
	{
		MoveToActor(Target->NextWaypoint, 5.0f);

	}
	else if (bIsPlayerDetected == true)
	{
		MoveToActor(Target->Player, 10.0f);
	}
}

FRotator ASimple_AIController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void ASimple_AIController::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
	for (size_t i = 0; i < DetectedPawns.Num(); i++)
	{
		DistanceToPlayer = GetPawn()->GetDistanceTo(DetectedPawns[i]);

		UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), DistanceToPlayer);
	}

	bIsPlayerDetected = true;
}
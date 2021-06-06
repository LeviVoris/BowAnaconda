// Fill out your copyright notice in the Description page of Project Settings.


#include "Simple_AICharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ASimple_AICharacter::ASimple_AICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);

}

// Called when the game starts or when spawned
void ASimple_AICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimple_AICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASimple_AICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


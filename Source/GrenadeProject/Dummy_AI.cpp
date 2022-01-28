// Fill out your copyright notice in the Description page of Project Settings.


#include "Dummy_AI.h"

// Sets default values
ADummy_AI::ADummy_AI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADummy_AI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADummy_AI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADummy_AI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


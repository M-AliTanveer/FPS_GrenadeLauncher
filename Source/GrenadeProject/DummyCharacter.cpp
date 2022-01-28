// Fill out your copyright notice in the Description page of Project Settings.

#include "DummyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimSequence.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"


// Sets default values
ADummyCharacter::ADummyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADummyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADummyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADummyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ADummyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float caused = (health - DamageAmount) > 0 ? (DamageAmount) : (health);
	health = health - DamageAmount;
	if (health <= 0)
	{
		GetMesh()->PlayAnimation(DeathAnimation, false);
		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, [&]() {}, 3, false);//@MAT this is incomplete i supose(timer)
		Destroy();
	}
	UE_LOG(LogTemp, Warning, TEXT("Damage taken %f"), DamageAmount);
	return caused;
}


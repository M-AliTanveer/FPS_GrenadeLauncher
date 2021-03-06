// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MaulProtoPrecompiled.h"
#include "GameFramework/Character.h"
#include "DummyCharacter.generated.h"


//@MAT as an oop approach,  this could have been parented to the grenade character// this can help prevent casting individually// and also will enable  to use the same Health UMG widget for both character and AI
class UAnimSequence;
UCLASS()
class GRENADEPROJECT_API ADummyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADummyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Dummy Info")//@MAT good on assigning categories here, same can be done in BPs too
		float health;
	UPROPERTY(EditAnywhere, Category = "Dummy Info")
		UAnimSequence* DeathAnimation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MaulProtoPrecompiled.h"
#include "GameFramework/Actor.h"
#include "GrenadeProjectile.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;
class URadialForceComponent;
class UParticleSystem;
class USoundBase;
class UCurveFloat;
UCLASS()
class GRENADEPROJECT_API AGrenadeProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrenadeProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Components)
		UStaticMeshComponent* GrenadeMesh;
	UPROPERTY(EditAnywhere, Category = Components)
		UProjectileMovementComponent* GR_projectile;
	/*UPROPERTY(EditAnywhere, Category = Components)
		URadialForceComponent* explosionradius;
	UPROPERTY(EditAnywhere, Category = Components)
		UParticleSystemComponent* explosinparticles;*/
	UPROPERTY(EditAnywhere, Category = GrenadeInfo)
		float timer;
	UPROPERTY(EditAnywhere, Category = GrenadeInfo)
		float explosionradius;
	UPROPERTY(EditAnywhere, Category = GrenadeInfo)
		float impulseforce;
	UPROPERTY(EditAnywhere, Category = GrenadeInfo)
		USoundBase* explosionaudio;
	UPROPERTY(EditAnywhere, Category = GrenadeInfo)
		UParticleSystem* explosion;
	UPROPERTY(EditAnywhere, Category = GrenadeInfo)
		UCurveFloat* RangedDamage;
	void explode();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

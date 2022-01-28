// Fill out your copyright notice in the Description page of Project Settings.


#include "GrenadeProjectile.h"
#include "GrenadeProjectCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/RadialForceComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Curves/CurveFloat.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGrenadeProjectile::AGrenadeProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	GrenadeMesh = CreateDefaultSubobject<UStaticMeshComponent>("GrenadeMesh");
	GR_projectile = CreateDefaultSubobject<UProjectileMovementComponent>("GrenadeProjectile");
	/*explosionradius = CreateDefaultSubobject<URadialForceComponent>("radialforce");
	explosinparticles = CreateDefaultSubobject<UParticleSystemComponent>("explosionparticles");*/

	SetRootComponent(GrenadeMesh);
	GR_projectile->InitialSpeed = 3000;
	GR_projectile->bShouldBounce = true;
	/*explosionradius->Radius = 100;
	explosionradius->ImpulseStrength = 200000;*/

	timer = 5;
	explosionradius = 1000.0f;
	impulseforce = 500000;


}

// Called when the game starts or when spawned
void AGrenadeProjectile::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle Time;
	GetWorldTimerManager().SetTimer(Time, this, &AGrenadeProjectile::explode, timer, false);
}

void AGrenadeProjectile::explode()
{
	TArray<FHitResult> ObjectsHit;
	FVector ExplosionLocation = GetActorLocation();
	FCollisionShape DamageArea = FCollisionShape::MakeSphere(explosionradius);
	bool damaged = GetWorld()->SweepMultiByChannel(ObjectsHit, GetActorLocation(), GetActorLocation(), FQuat::Identity, ECollisionChannel::ECC_Pawn, DamageArea);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosion, GetActorLocation());
	if (explosionaudio != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, explosionaudio, GetActorLocation());
	}
	if (damaged)
	{
		for (auto& DamagedObject : ObjectsHit)
		{
			UStaticMeshComponent* DamageMesh = Cast<UStaticMeshComponent>((DamagedObject.GetActor())->GetRootComponent());
			if (DamageMesh)
			{
				DamageMesh->AddRadialImpulse(GetActorLocation(), explosionradius, impulseforce, ERadialImpulseFalloff::RIF_Constant, true);
				UE_LOG(LogTemp, Warning, TEXT("Exploded character"));
			}
			if (RangedDamage )
			{
				FVector CharacterLocation = DamagedObject.GetActor()->GetActorLocation();
				float distance = FVector::Dist(CharacterLocation, ExplosionLocation);
				UGameplayStatics::ApplyDamage(DamagedObject.GetActor(), RangedDamage->GetFloatValue(distance), NULL, this, NULL);
				UE_LOG(LogTemp, Warning, TEXT("Damage sent %f"), 20.0f);
			}
			/*if (AGrenadeProjectCharacter* Character = Cast<AGrenadeProjectCharacter>(DamagedObject.GetActor()))
			{
				FVector CharacterLocation = Character->GetActorLocation();
				float distance = FVector::Dist(CharacterLocation, ExplosionLocation);
				UE_LOG(LogTemp, Warning, TEXT("Disatnce %f"),distance);
				float damage;
				if (distance <= .3*explosionradius)
				{
					damage = 1;
				}
				else if (distance > .3 * explosionradius && distance<=explosionradius)
				{
					damage = 1 - (distance / explosionradius);
				}
				else
				{
					damage = 0;
				}
				Character->UpdateHealth(damage);
			}*/
		}
	}
	
	Destroy();
}

// Called every frame
void AGrenadeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



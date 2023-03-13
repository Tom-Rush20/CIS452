// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DodgeballProjectile.generated.h"

UCLASS()
class ESCAPE_ROOM_API ADodgeballProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADodgeballProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* BounceSound;

	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundAttenuation* BounceSoundAttenuation;

	UPROPERTY(EditAnywhere, Category = Particles)
		class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* DamageSound;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dodgeball, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* SphereComponent;

public:
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor*
			OtherActor,
			UPrimitiveComponent* OtherComp, FVector
			NormalImpulse, const
			FHitResult& Hit);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dodgeball, meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* ProjectileMovement;

};

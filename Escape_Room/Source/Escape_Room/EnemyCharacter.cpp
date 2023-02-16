// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//get the player character
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	//look at the player every frame
	LookAtActor(PlayerCharacter);

}

void AEnemyCharacter::LookAtActor(AActor* TargetActor)
{
	if (TargetActor == nullptr) return;

	if (CanSeeActor(TargetActor)) 
	{
		//setting the location of the enemy and the target
		FVector Start = GetActorLocation();
		FVector End = TargetActor->GetActorLocation();

		//calculate rotation for start point to face end point
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

		//Set enemy rotation to that location
		SetActorRotation(LookAtRotation);
	}
}

bool AEnemyCharacter::CanSeeActor(const AActor* const TargetActor) const
{
	if (TargetActor == nullptr) return false;

	//Store the results of the Line Trace
	FHitResult Hit;

	//Where the line trace starts and ends
	FVector Start = GetActorLocation();
	FVector End = TargetActor->GetActorLocation();

	//The trace channel we want to compare against
	ECollisionChannel Channel = ECollisionChannel::ECC_Visibility;

	FCollisionQueryParams QueryParams;
	//Ignore the actor executing this Line Trace
	QueryParams.AddIgnoredActor(this);
	//and the target we are checking for 
	QueryParams.AddIgnoredActor(TargetActor);

	//Execute the Line Trace
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	//set color Green if blocked or Red if not blocked
	FColor LineColor = (Hit.bBlockingHit) ? FColor::Green : FColor::Red;

	//draw the line trace in the world
	DrawDebugLine(GetWorld(), Start, End, LineColor);

	return !Hit.bBlockingHit;

}



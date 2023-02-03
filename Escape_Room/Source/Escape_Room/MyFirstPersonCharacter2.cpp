// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstPersonCharacter2.h"

// Sets default values
AMyFirstPersonCharacter2::AMyFirstPersonCharacter2()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyFirstPersonCharacter2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstPersonCharacter2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyFirstPersonCharacter2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Setup input bindings
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyFirstPersonCharacter2::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyFirstPersonCharacter2::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyFirstPersonCharacter2::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyFirstPersonCharacter2::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMyFirstPersonCharacter2::Jump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AMyFirstPersonCharacter2::StopJumping);
}

void AMyFirstPersonCharacter2::MoveForward(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void AMyFirstPersonCharacter2::MoveRight(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}


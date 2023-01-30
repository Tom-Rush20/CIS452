// Copyright Epic Games, Inc. All Rights Reserved.

#include "Escape_RoomGameMode.h"
#include "Escape_RoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEscape_RoomGameMode::AEscape_RoomGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

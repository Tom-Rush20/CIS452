// Copyright Epic Games, Inc. All Rights Reserved.

#include "Dungeon_CrawlGameMode.h"
#include "Dungeon_CrawlCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADungeon_CrawlGameMode::ADungeon_CrawlGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

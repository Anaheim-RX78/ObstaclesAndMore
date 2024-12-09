// Copyright Epic Games, Inc. All Rights Reserved.

#include "ObstaclesAndMoreGameMode.h"
#include "ObstaclesAndMoreCharacter.h"
#include "UObject/ConstructorHelpers.h"

AObstaclesAndMoreGameMode::AObstaclesAndMoreGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "Week1GameMode.h"
#include "Week1Character.h"
#include "UObject/ConstructorHelpers.h"

AWeek1GameMode::AWeek1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "GrenadeProjectGameMode.h"
#include "GrenadeProjectHUD.h"
#include "GrenadeProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGrenadeProjectGameMode::AGrenadeProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGrenadeProjectHUD::StaticClass();
}

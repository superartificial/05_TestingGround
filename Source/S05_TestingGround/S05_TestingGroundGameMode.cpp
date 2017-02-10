// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "S05_TestingGround.h"
#include "S05_TestingGroundGameMode.h"
#include "S05_TestingGroundHUD.h"
#include "Player/FirstPersonCharacter.h"

AS05_TestingGroundGameMode::AS05_TestingGroundGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Static/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_TestingGroundHUD::StaticClass();
}

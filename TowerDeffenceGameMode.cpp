// Copyright Epic Games, Inc. All Rights Reserved.

#include "TowerDeffenceGameMode.h"
#include "Characters/PlayerCharacter_CPP.h"
#include "Controllers/MainPlayerController_CPP.h"
#include "UI/MainMenuHUD.h"

ATowerDeffenceGameMode::ATowerDeffenceGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMainPlayerController_CPP::StaticClass();

	DefaultPawnClass = APlayerCharacter_CPP::StaticClass();

	HUDClass = AMainMenuHUD::StaticClass();
}
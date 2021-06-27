// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGraphActionMenu.h"
#include "GameFramework/PlayerController.h"
#include "Instances/TD_GameState_CPP.h"
#include "UI/MainMenuHUD.h"
#include "MainPlayerController_CPP.generated.h"

/**
 * 
 */
class ATDPreviewBuilding_CPP;
UCLASS()
class TOWERDEFFENCE_API AMainPlayerController_CPP : public APlayerController
{
	GENERATED_BODY()

public:

	AMainPlayerController_CPP();
	
	virtual void BeginPlay() override;

	//TSharedRef<ATD_GameState_CPP> GameState;
	//TSharedPtr<ATDPreviewBuilding_CPP> ConstructionPreviewRef;
	AMainMenuHUD* WidgetRef;
	//TSubclassOf<UUserWidget> MainMenuRef;
	AMainMenuHUD* HUD_ShopMenu;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	void SpawnWidgets();
	

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;

	void OpenMenu();
	void OpenShop();
	
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	//Navigate player to the current mouse cursor location.
	void MoveToMouseCursor();

	//Navigate player to the current touch location. 
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	//Navigate player to the given world location. 
	void SetNewMoveDestination(const FVector DestLocation);
	
	//Input handlers for SetDestination action. 
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	void OnResetVR();

};

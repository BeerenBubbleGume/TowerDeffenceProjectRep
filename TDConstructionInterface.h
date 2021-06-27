// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TDConstructionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTDConstructionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TOWERDEFFENCE_API ITDConstructionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual  void ConstructBuilding(TSubclassOf<class ATDBuildingMaster_CPP> BuildingMasterClass);
	
};

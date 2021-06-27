// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainPlayerController_CPP.h"
#include "GameFramework/Actor.h"
#include "TDBuildingMaster_CPP.generated.h"

UCLASS()
class TOWERDEFFENCE_API ATDBuildingMaster_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATDBuildingMaster_CPP();

	void ConstructionScript(UStaticMesh* DisplayMesh) const;
	
	UBillboardComponent* Buildboard;

	UStaticMeshComponent* BuildingMesh;
	

	UPROPERTY(BlueprintReadWrite, meta = (InstanceEditable = "true"), meta = (ExposeOnSpawn = "true"), Category = "Components")
	UStaticMesh* DisplayMesh;

};

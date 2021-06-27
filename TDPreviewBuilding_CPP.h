// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TDBuildingMaster_CPP.h"
#include "GameFramework/Actor.h"
#include "Controllers/TDConstructionInterface.h"
#include "TDPreviewBuilding_CPP.generated.h"


UCLASS()
class TOWERDEFFENCE_API ATDPreviewBuilding_CPP : public AActor, public ITDConstructionInterface
{
	GENERATED_BODY()
	
public:	
	
	ATDPreviewBuilding_CPP();

	virtual void ConstructBuilding(TSubclassOf<class ATDBuildingMaster_CPP> BuildingMasterClass) override;

protected:

	UStaticMeshComponent* BuildingPreviewMesh;

	bool bIsPreviewing;

	void SpawnPreview(TSubclassOf<class ATDBuildingMaster_CPP> _BuildClass, UStaticMesh* DisplayMesh_);

	UStaticMesh* _DisplayMesh;

public:	

	void GetCursorPosition();

	TSubclassOf<class ATDBuildingMaster_CPP> _BuildingClass;
	
	void DestroyPreview();
};

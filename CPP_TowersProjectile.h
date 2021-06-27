// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "CPP_TowersProjectile.generated.h"

UCLASS()
class TOWERDEFFENCE_API ACPP_TowersProjectile : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACPP_TowersProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimerHandle DestroyDelayLoop;
	void DestroyTimer();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HitDestoy(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(BlueprintReadWrite, Category = Component)
		USphereComponent* CollisionSphere;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Mesh)
		UStaticMeshComponent* Mesh;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Projectile)
		UProjectileMovementComponent* ProjectileMovementComponent;
};

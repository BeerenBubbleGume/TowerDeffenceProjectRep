// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_TowersProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPP_TowersProjectile::ACPP_TowersProjectile()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	CollisionSphere = CreateDefaultSubobject<USphereComponent>("CollisionSphere");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	CollisionSphere->SetupAttachment(RootComponent);
	Mesh->SetupAttachment(CollisionSphere);

	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->InitialSpeed = 1500.f;
	ProjectileMovementComponent->MaxSpeed = 5000.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;
	ProjectileMovementComponent->bSweepCollision = false;
	ProjectileMovementComponent->bForceSubStepping = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (SphereAsset.Succeeded())
	{
		Mesh->SetStaticMesh(SphereAsset.Object);
		Mesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		Mesh->SetWorldScale3D(FVector(0.2, 0.2f, 0.2f));
	}
	//CollisionSphere->BodyInstance.SetCollisionProfileName("BlockAll");
	//CollisionSphere->OnComponentHit.AddDynamic(this, &ACPP_TowersProjectile::HitDestoy);
}

// Called when the game starts or when spawned
void ACPP_TowersProjectile::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(DestroyDelayLoop, this, &ACPP_TowersProjectile::DestroyTimer, 10.f, true, 10.f);
}

void ACPP_TowersProjectile::HitDestoy(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComponent != NULL) && OtherComponent->IsSimulatingPhysics())
	{
		if (GEngine)
		{
			OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity, Hit.ImpactPoint);
			this->Destroy();
		}
	}
}

// Called every frame
void ACPP_TowersProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void ACPP_TowersProjectile::DestroyTimer()
{
	this->Destroy();
}
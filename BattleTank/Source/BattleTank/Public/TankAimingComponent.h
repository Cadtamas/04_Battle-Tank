// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStaticsTypes.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state
UENUM()
enum class EFiringState:uint8
{
	Reloading,
	Aiming,
	Locked
};

//Forward declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

//Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise( UTankBarrel*BarrelToSet, UTankTurret* TurretToSet ); //Public, because we need it in the blueprint

	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category="State")
	EFiringState FiringState = EFiringState::Reloading;

private:

	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool IsBarrelMoving();

	//Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	//TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint; //Projectile reference											 

	double LastFireTime = 0;
	
	FVector AimDirection;
};

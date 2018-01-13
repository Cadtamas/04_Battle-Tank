// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "TankAimingComponent.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

//Called every frame
void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank= GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	else

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);//TODO check radius is in cm

	//Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
	//If aim or locked
	if (AimingComponent->GetFiringState() == EFiringState::Locked) 
	{
		AimingComponent->Fire();
	}

	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}


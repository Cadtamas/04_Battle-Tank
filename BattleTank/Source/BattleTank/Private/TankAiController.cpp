// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}


ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

//Called every frame
void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO Move towards the player
		//Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//Fire if ready
	}
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}


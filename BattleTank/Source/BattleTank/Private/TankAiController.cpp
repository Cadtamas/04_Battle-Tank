// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Tank.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

//Called every frame
void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank= Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//TODO Move towards the player
		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		//Fire if ready
		ControlledTank->Fire(); //TODO limit firing rate
	}
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}


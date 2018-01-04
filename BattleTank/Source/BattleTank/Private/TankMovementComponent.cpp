// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call Super as we're replacing the functionality
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *MoveVelocityString)
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; } //Protect the pointer
	LeftTrack->SetThrottle(Throw); //TankTrack method
	RightTrack->SetThrottle(Throw);
	//TODO prevent double speed due to dual control
}


void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; } //Protect the pointer
	LeftTrack->SetThrottle(-Throw); //TankTrack method
	RightTrack->SetThrottle(Throw);
	//TODO prevent double speed due to dual control
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; } //Protect the pointer
	LeftTrack->SetThrottle(Throw); //TankTrack method
	RightTrack->SetThrottle(-Throw);
	//TODO prevent double speed due to dual control
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; } //Protect the pointer
	LeftTrack->SetThrottle(-Throw); //TankTrack method
	RightTrack->SetThrottle(-Throw);
	//TODO prevent double speed due to dual control
}
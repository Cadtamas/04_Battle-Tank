// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
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
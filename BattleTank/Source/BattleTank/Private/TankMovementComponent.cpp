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
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal(); //The  Tank's direction
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention); //Forward multiplier between -1 and 1 
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;//.Z turns the FVector to a float 
	IntendTurnRight(RightThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw) //Throw between -1 (backward) and 1 (forward)
{
	if (!ensure(LeftTrack && RightTrack)) { return; } //Protect the pointer
	LeftTrack->SetThrottle(Throw); //TankTrack method
	RightTrack->SetThrottle(Throw);
}


void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; } //Protect the pointer
	LeftTrack->SetThrottle(-Throw); //TankTrack method
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; } //Protect the pointer
	LeftTrack->SetThrottle(Throw); //TankTrack method
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; } //Protect the pointer
	LeftTrack->SetThrottle(-Throw); //TankTrack method
	RightTrack->SetThrottle(-Throw);
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"



void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//Move the barrel the right aount frame

	//Given a max elevetion speed, and the frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate() called at speed %f"), DegreesPerSecond);
}

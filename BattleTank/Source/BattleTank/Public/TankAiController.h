// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
protected:

	//How close the AI Tank get
	UPROPERTY(EditDefaultsOnly, Category="Setup") 
	float AcceptanceRadius = 8000;

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController2.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController2 : public AAIController
{
	GENERATED_BODY()
private:
	virtual void Tick(float DeltaTime) override;
	
};

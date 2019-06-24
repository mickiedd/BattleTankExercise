// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

#define  out
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	void Tick(float DeltaTime) override;
protected:
	ATank* GetControlledTank() const;
	void BeginPlay() override;
	ATank* GetPlayerTankController() const;
};

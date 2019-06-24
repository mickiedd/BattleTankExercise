// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.h"



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto tank = GetControlledTank();
	if (tank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("This AI do not own a Tank."));
	}
	else {
		if (this->IsActorTickEnabled())
		{
			UE_LOG(LogTemp, Warning, TEXT("This is a tank AI Controller.And the tank is: %s"), *tank->GetName());
		}
	}
	auto playerController = GetPlayerTankController();
	if (playerController == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("This AI do not own a Tank."));
	} 
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("This AI found the player controller: %s"), *playerController->GetName());
	}
}

ATank* ATankAIController::GetPlayerTankController() const
{
	auto controller = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
	return controller->GetControlledTank();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetPlayerTankController();
	if (PlayerTank != nullptr)
	{
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nothing happened."));
	}
}

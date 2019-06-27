// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;
	// Called every frame
	void Tick(float DeltaTime) override;
protected:
	void BeginPlay() override;
private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = .5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = .3333f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;
};

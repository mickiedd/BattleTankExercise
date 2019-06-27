// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrel(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector Location, float LaunchSpeed)
{
	if (Barrel == nullptr)
	{
		return;
	}
	FVector OutLaunchVelocity = FVector(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("BattleStartLocation"));

	// Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, Location, LaunchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		FVector BarrelLocation = Barrel->GetComponentLocation();
		//UE_LOG(LogTemp, Warning, TEXT("Tank:%s aiming at the location: %s, and the Target's barrel location is: %s"), *GetOwner()->GetName(), *Location.ToString(), *BarrelLocation.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("LaunchSpeed is: %f, AimDirection is: %s"), LaunchSpeed, *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution Found."), GetWorld()->GetTimeSeconds());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%f: No Aim Solution Found."), GetWorld()->GetTimeSeconds());
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("DeltaRotator is: %s"), *DeltaRotator.ToString());
	Barrel->Elevate(5.0f);
}


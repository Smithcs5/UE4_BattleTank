// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	auto FoundPlayer = GetPlayerTank();
	if (!FoundPlayer) {
		UE_LOG(LogTemp, Warning, TEXT("TankAI can't find player"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("TankAI found: %s"), *(FoundPlayer->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	FVector HitLocation;
	if (GetPlayerTank()) {
		
		//TODO Move towards the player
		
		//Aim towards the player
		GetTankAIController()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire it ready
	}
}

ATank* ATankAIController::GetTankAIController() const {

	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}


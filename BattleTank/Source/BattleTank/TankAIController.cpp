// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
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

ATank* ATankAIController::GetTankAIController() const {

	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}


// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShootingRangeGameMode.h"
#include "ShootingRangeHUD.h"
#include "ShootingRangeCharacter.h"
#include "ShootingRangeGameState.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerState.h"

AShootingRangeGameMode::AShootingRangeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(
		TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AShootingRangeHUD::StaticClass();
}

void AShootingRangeGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	APlayerController* PController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PController != nullptr)
	{
		UINT Score = PController->PlayerState->GetScore();
		if (Score >= 5)
		{
			GetWorldTimerManager().SetTimer(TimerHandle_TimerCount, this,&AShootingRangeGameMode::OnVictory,1.0f, true, 1.0f);
		}
	}
}

void AShootingRangeGameMode::OnVictory()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("QUIT");
}

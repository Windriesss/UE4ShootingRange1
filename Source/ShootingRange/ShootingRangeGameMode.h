// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingRangeGameMode.generated.h"

UCLASS(minimalapi)
class AShootingRangeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AShootingRangeGameMode();

	virtual void Tick(float DeltaSeconds) override;

	void OnVictory();

	FTimerHandle TimerHandle_TimerCount;
};




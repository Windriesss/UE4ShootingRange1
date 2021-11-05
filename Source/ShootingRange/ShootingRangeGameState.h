// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ShootingRangeGameState.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGRANGE_API AShootingRangeGameState : public AGameState
{
public:
	AShootingRangeGameState();
	
	GENERATED_BODY()

	UINT8 Score;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ShootingRangePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGRANGE_API AShootingRangePlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	AShootingRangePlayerState();
	UINT8 Score;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/StaticBitArray.h"
#include "GameFramework/GameModeBase.h"
#include "MobaGameModeBase.generated.h"

#define GRID_RESOLUTION 128

/**
 * 
 */
UCLASS()
class MOBA_API AMobaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:

	UFUNCTION(BlueprintPure)
	FVector2D WorldLocationToGridLocation(const FVector WorldLocation) const;
	
protected:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FVector2D MapSize = { 3000, 3990 };

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int32 GridResolution = GRID_RESOLUTION;
	
	UPROPERTY(BlueprintReadOnly)
	TArray<AActor*> Units;

	UPROPERTY(BlueprintReadOnly)
	TStaticBitArray<GRID_RESOLUTION * GRID_RESOLUTION> VisibilityMap;
};

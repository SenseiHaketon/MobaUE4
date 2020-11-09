// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MobaFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MOBA_API UMobaFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintPure)
    static FVector2D WorldLocationToGridLocation(FVector WorldLocation, FVector2D MapSize, int32 GridResolution = 128);
};

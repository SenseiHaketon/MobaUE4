// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibraries/MobaFunctionLibrary.h"

FVector2D UMobaFunctionLibrary::WorldLocationToGridLocation(const FVector WorldLocation, const FVector2D MapSize,
                                                            const int32 GridResolution)
{
    return FVector2D(FMath::FloorToInt((WorldLocation.X / MapSize.X) * GridResolution), FMath::FloorToInt((WorldLocation.Y / MapSize.Y) * GridResolution));
}

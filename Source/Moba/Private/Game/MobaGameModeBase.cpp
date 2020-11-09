// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/MobaGameModeBase.h"



#include "Engine/TextureRenderTarget2D.h"
#include "FunctionLibraries/MobaFunctionLibrary.h"
#include "Interfaces/UnitInterface.h"
#include "Kismet/GameplayStatics.h"

void AMobaGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    UGameplayStatics::GetAllActorsWithInterface(this, UUnitInterface::StaticClass(), Units);
}

void AMobaGameModeBase::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    for(auto Unit : Units)
    {
        const FVector2D GridLocation = WorldLocationToGridLocation(Unit->GetActorLocation());
        VisibilityMap[GridLocation.X * GridResolution + GridLocation.Y] = true;
    }
}

FVector2D AMobaGameModeBase::WorldLocationToGridLocation(const FVector WorldLocation) const
{
    return UMobaFunctionLibrary::WorldLocationToGridLocation(WorldLocation, MapSize, GridResolution);
}
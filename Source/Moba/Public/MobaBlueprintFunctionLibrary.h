// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayEffectTypes.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "MobaBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MOBA_API UMobaBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = Ability)
	static void ApplyExternalEffectContainerSpecToActors(const FGameplayEffectSpecHandle& EffectSpec, const TArray<AActor*>& TargetActors);
};

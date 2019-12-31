// Fill out your copyright notice in the Description page of Project Settings.


#include "MobaBlueprintFunctionLibrary.h"
#include "GameplayEffect.h"

void UMobaBlueprintFunctionLibrary::ApplyExternalEffectContainerSpecToActors(const FGameplayEffectSpecHandle& EffectSpec, const TArray<AActor*>& TargetActors)
{
	if (EffectSpec.IsValid())
	{
		FGameplayAbilityTargetData_ActorArray* NewTargetData = new FGameplayAbilityTargetData_ActorArray();
		NewTargetData->TargetActorArray.Append(TargetActors);

		NewTargetData->ApplyGameplayEffectSpec(*EffectSpec.Data.Get());
	}
}
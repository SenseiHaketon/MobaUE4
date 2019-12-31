// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "MyAbilityTask.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMyDelegate, float, FirstParamName, int32, SecondParamName);

/**
 * 
 */
UCLASS()
class MOBA_API UMyAbilityTask : public UAbilityTask
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FMyDelegate OnCalled;

	UPROPERTY(BlueprintReadWrite)
	float OptionalValue;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (DisplayName = "ExecuteMyTask", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UMyAbilityTask* CreateMyTask(UGameplayAbility* OwningAbility, FName TaskInstanceName, float examplevariable);

	virtual void Activate() override;
};

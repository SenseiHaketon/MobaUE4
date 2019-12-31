// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilityTask.h"

UMyAbilityTask* UMyAbilityTask::CreateMyTask(UGameplayAbility* OwningAbility, FName TaskInstanceName, float examplevariable)
{
	UMyAbilityTask* MyObj = NewAbilityTask<UMyAbilityTask>(OwningAbility, TaskInstanceName);
	MyObj->OptionalValue = examplevariable;

	return MyObj;
}

void UMyAbilityTask::Activate()
{
	Super::Activate();

	// Just an example
	OnCalled.Broadcast(500.0f, 42);
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_MontageWaitForEvent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMobaMontageWaitForEventDelegate, FGameplayTag, EventTag, FGameplayEventData, EventData);

/**
 * 
 */
UCLASS()
class MOBA_API UAbilityTask_MontageWaitForEvent : public UAbilityTask
{
	GENERATED_BODY()
	
public:

	// Constructor and overrides
	UAbilityTask_MontageWaitForEvent(const FObjectInitializer& ObjectInitializer);
	virtual void Activate() override;
	virtual void ExternalCancel() override;
	virtual FString GetDebugString() const override;
	virtual void OnDestroy(bool AbilityEnded) override;

	/* The montage completely finished playing */
	UPROPERTY(BlueprintAssignable)
	FMobaMontageWaitForEventDelegate Completed;

	/* The montage started blending out */
	UPROPERTY(BlueprintAssignable)
	FMobaMontageWaitForEventDelegate BlendOut;

	/* The montage was interrupted */
	UPROPERTY(BlueprintAssignable)
	FMobaMontageWaitForEventDelegate Interrupted;

	/* The ability task was explicitly cancelled by another ability */
	UPROPERTY(BlueprintAssignable)
	FMobaMontageWaitForEventDelegate Cancelled;

	/* On of the triggering gameplay events happened */
	UPROPERTY(BlueprintAssignable)
	FMobaMontageWaitForEventDelegate EventReceived;

	/**
	 * Play a montage and wait for it to end. If a gameplay event happens that matches EventTags (or EventTags is empty), the EventReceived delegate will fire with a tag and event data.
	 * If StopWhenAbilityEnds is true, this montage will be aborted if the ability ends noramlly. It is always stopped when the ability is explicitly cancelled.
	 * On normal execution, BlendOut is called when the montage is blending out, and Completed when it is completely done playing.
	 * Interrupted is called if another montage overwrites this, and Cancelled is called if the ability or task is cancelled.
	 *
	 * @param TaskInstanceName Set to override the name of this task, for later querying
	 * @param MontageToPlay The montage to play on the character
	 * @param EventTags Any gameplay events matching this tag will activate the EventReceived callback. If empty, all events will trigger callback
	 * @param Rate Change to play the montage faster or slower
	 * @param bStopWhenAbilityEnds If true, this montage will be aborted if the ability ends normally. It is always stopped when the ability is explicitly cancelled
	 * @param AnimRootMotionTranslationScale Change to modify size of root motion or set to 0 to block it entirely
	 */
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAbilityTask_MontageWaitForEvent* PlayMontageAndWaitForEvent(
		UGameplayAbility* OwningAbility,
		FName TaskInstanceName,
		UAnimMontage* MontageToPlay,
		FGameplayTagContainer EventTags,
		float Rate = 1.0f,
		FName StartSection = NAME_None,
		bool bStopWhenAbilityEnds = true,
		float AnimRootMotionTranslationScale = 1.0f
	);

private:

	/** Montage that is playing */
	UPROPERTY()
	UAnimMontage* MontageToPlay;

	/** List of tags to match against gameplay events */
	UPROPERTY()
	FGameplayTagContainer EventTags;

	/** Playback rate */
	UPROPERTY()
	float Rate;

	/** Section to start the montage from */
	UPROPERTY()
	FName StartSection;

	/** Modifies how root motion movement is applied */
	UPROPERTY()
	float AnimRootMotionTranslationScale;

	/** Should the montage be stopped when ability ends? */
	UPROPERTY()
	bool bStopWhenAbilityEnds;

	/** Checks if the ability is playing a montage and stops it, returns true if montage was stopped */
	bool StopPlayingMontage();

	void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);
	void OnAbilityCancelled();
	void OnMontageEnded(UAnimMontage* Montage, bool bInteruppted);
	void OnGameplayEvent(FGameplayTag EventTag, const FGameplayEventData* Payload);

	FOnMontageBlendingOutStarted BlendingOutDelegate;
	FOnMontageEnded MontageEndedDelegate;
	FDelegateHandle CancelledHandle;
	FDelegateHandle EventHandle;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/UnitInterface.h"

#include "PlayerCharacter.generated.h"

//UENUM(BlueprintType)
//enum class AbilityInput : uint8
//{
//	Ability1 UMETA(DisplayName = "Use Ability 1"),
//	Ability2 UMETA(DisplayName = "Use Ability 2"),
//	Ability3 UMETA(DisplayName = "Use Ability 3"),
//	UltimateAbility UMETA(DisplayName = "Use Ultimate Ability"),
//	PassiveAbility UMETA(DisplayName = "Passive Ability")
//};

UCLASS()
class MOBA_API APlayerCharacter : public ACharacterBase, public IUnitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	///** Our ability system */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	//class UAbilitySystemComponent* AbilitySystem;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities)
	//UBaseAttributeSet* AttributeSet;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TSubclassOf<class UGameplayAbility> Ability1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TSubclassOf<class UGameplayAbility> Ability2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TSubclassOf<class UGameplayAbility> Ability3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TSubclassOf<class UGameplayAbility> UltimateAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TSubclassOf<class UGameplayAbility> PassiveAbility;*/

protected:
	void PossessedBy(AController* NewController) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called from RPGAttributeSet, these call BP events above
	virtual void HandleDamage(float DamageAmount, const FHitResult& HitInfo, const struct FGameplayTagContainer& DamageTags, ACharacterBase* InstigatorCharacter, AActor* DamageCauser) override;
	virtual void HandleHealthChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags) override;
	virtual void HandleManaChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UAbilitySystemComponent* GetAbilitySystemComponent() const override; //We add this function, overriding it from IAbilitySystemInterface.

};

// Copyright 2022, Malachias Harris, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "FESystemBoxes.generated.h"

UENUM(BlueprintType, Category = "Triggers")
enum class ETriggerTypes : uint8 {
	VFX			UMETA(DisplayName = "VFX"),
	SFX			UMETA(DisplayName = "SFX"),
	Functional	UMETA(DisplayName = "Functional")
};


/**
 * 
 */
UCLASS()
class FEVENTTRIGGERSYSTEM_API AFESystemBoxes : public ATriggerBox
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

public:

	AFESystemBoxes();

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	// Getters
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const FString GetSFXDisplayName() { return SFXfuncName; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const FString GetVFXDisplayName() { return VFXfuncName; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const FString GetFUNDisplayName() { return FUNfuncName; }

	// Setter for SFX, VFX, Functional ufunction names.
	UFUNCTION(BlueprintCallable, Category = "Triggers")
	void SetSFXDisplayName(const FString SFXDisplayName);

	UFUNCTION(BlueprintCallable, Category = "Triggers")
	void SetVFXDisplayName(const FString VFXDisplayName);

	UFUNCTION(BlueprintCallable, Category = "Triggers")
	void SetFUNDisplayName(const FString FUNDisplayName);

public:
	/*Store a reference to a UFUNCTION */
	UPROPERTY(BlueprintReadWrite, Category = Triggers)
		UFunction* SFXfunc;
	/*Store a reference to a UFUNCTION */
	UPROPERTY(BlueprintReadWrite, Category = Triggers)
		UFunction* VFXfunc;
	/*Store a reference to a UFUNCTION */
	UPROPERTY(BlueprintReadWrite, Category = Triggers)
		UFunction* FUNfunc;
private:

	UFUNCTION(BlueprintCallable, Category = Triggers)
	void LoadingFunctions();

private:
	/* Enum that store the type of the trigger box. SFX, VFX, FUNCTIONAL*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	ETriggerTypes EventTypes;

	/* Stores display name of the SFX function*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,NoClear, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	FString SFXfuncName;	

	/* Stores display name of the VFX function*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, NoClear, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	FString VFXfuncName;

	/* Stores display name of the FUN function*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, NoClear, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	FString FUNfuncName;

};

// Copyright 2022, Malachias Harris, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FESystemMethods.generated.h"

class AFESystemBoxes;

/**
 * 
 */
UCLASS()
class FEVENTTRIGGERSYSTEM_API UFESystemMethods : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
		/* Get all UFUNCTION in UObject. */
		UFUNCTION(BlueprintCallable)
		static void GetAllOjectUFunction(const UObject* Object, TArray<UFunction*>& arr);

		/*Get all UFunction mark with the prefix SFX_ in the FESystemBox class*/
		UFUNCTION(BlueprintCallable)
		static void GetAllSFXUFunction(const AFESystemBoxes* FESystemBox, TArray<UFunction*>& arr);

		/*Get all UFunction mark with the prefix VFX_ in the FESystemBox class*/
		UFUNCTION(BlueprintCallable)
		static void GetAllVFXUFunction(const AFESystemBoxes* FESystemBox, TArray<UFunction*>& arr);

		/*Get all UFunction mark with the prefix FUN_ in the FESystemBox class*/
		UFUNCTION(BlueprintCallable)
		static void GetAllFunctionalUFunction(const AFESystemBoxes* FESystemBox, TArray<UFunction*>& arr);

};

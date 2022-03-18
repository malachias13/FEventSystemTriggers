// Copyright 2022, Malachias Harris, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "FEventEditorSystemUI.generated.h"

/**
 * 
 */
UCLASS()
class FEVENTSYSTEMEDITOR_API UFEventEditorSystemUI : public UEditorUtilityWidget
{
	GENERATED_BODY()
	
private:
	/* A UFuntion pointer that stores the SFX function.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	UFunction* SFXfunc;

	/* A UFuntion pointer that stores the VFX function.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	UFunction* VFXfunc;

	/* A UFuntion pointer that stores the Functional function.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	UFunction* FUNfunc;

};

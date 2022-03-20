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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	FString SFXName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	FString VFXName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Triggers, meta = (AllowPrivateAccess = "true"))
	FString FUNName;



};

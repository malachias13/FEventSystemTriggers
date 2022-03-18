// Copyright 2022, Malachias Harris, All rights reserved

#include "FESystemMethods.h"
#include "FEventTriggerSystem.h"
#include <Objects/FESystemBoxes.h>
#include <Misc/FileHelper.h>
#include <HAL/PlatformFilemanager.h>

void UFESystemMethods::GetAllOjectUFunction(const UObject* Object, TArray<UFunction*>& arr)
{
	if (!Object) { return; }
	for (TFieldIterator<UFunction> FunctionIT(Object->GetClass(), EFieldIteratorFlags::IncludeSuper); FunctionIT; ++FunctionIT) 
	{
		arr.Add(*FunctionIT);
	}
}

void UFESystemMethods::GetAllSFXUFunction(const AFESystemBoxes* FESystemBox, TArray<UFunction*>& arr)
{
	if (!FESystemBox) { return; }
	for (TFieldIterator<UFunction> SFX_IT(FESystemBox->GetClass()); SFX_IT; ++SFX_IT)
	{
		if (SFX_IT->GetName().Contains("SFX_"))
		{
			arr.Add(*SFX_IT);
		}
	}
}

void UFESystemMethods::GetAllVFXUFunction(const AFESystemBoxes* FESystemBox, TArray<UFunction*>& arr)
{
	if (!FESystemBox) { return; }
	for (TFieldIterator<UFunction>VFX_IT(FESystemBox->GetClass()); VFX_IT; ++VFX_IT)
	{
		if (VFX_IT->GetName().Contains("VFX_"))
		{
			arr.Add(*VFX_IT);
		}
	}
}

void UFESystemMethods::GetAllFunctionalUFunction(const AFESystemBoxes* FESystemBox, TArray<UFunction*>& arr)
{
	if (!FESystemBox) { return; }
	for (TFieldIterator<UFunction> F_IT(FESystemBox->GetClass()); F_IT; ++F_IT)
	{
		if (F_IT->GetName().Contains("FUN_"))
		{
			arr.Add(*F_IT);
		}
	}
}


// Copyright 2022, Malachias Harris, All rights reserved


#include <Objects/FESystemBoxes.h>
#include <Kismet/GameplayStatics.h>
#include <FEventTriggerSystem/Public/FESystemMethods.h>

AFESystemBoxes::AFESystemBoxes()
{
}

void AFESystemBoxes::BeginPlay()
{
	Super::BeginPlay();
	
	/* Binding the OnOverlapBegin functions to the OnActorBeginOverlap delegate */
	OnActorBeginOverlap.AddDynamic(this, &AFESystemBoxes::OnOverlapBegin);

	/* Binding the OnOverlapEnd functions to the OnActorEndOverlap delegate */
	OnActorEndOverlap.AddDynamic(this, &AFESystemBoxes::OnOverlapEnd);

	/* Loading and setting the UFUnction functions*/
	LoadingFunctions();
}

void AFESystemBoxes::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	switch (EventTypes)
	{
	case ETriggerTypes::VFX:
		/* Calls the VFX UFunction variable*/
		if (VFXfunc)
		{
			this->ProcessEvent(VFXfunc, nullptr);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("VFX UFunction is null."));
		}
		break;
	case ETriggerTypes::SFX:
		/* Calls the SFX UFunction variable*/
		if (SFXfunc)
		{
			this->ProcessEvent(SFXfunc, nullptr);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("SFX UFunction is null."));
		}
		break;
	case ETriggerTypes::Functional:
		/* Calls the Functional UFunction variable*/
		if (FUNfunc)
		{
			this->ProcessEvent(FUNfunc, nullptr);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Functional UFunction is null."));
		}
		break;
	default:
		break;
	}
}

void AFESystemBoxes::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{

}

void AFESystemBoxes::SetSFXDisplayName(const FString SFXDisplayName)
{
	SFXfuncName = SFXDisplayName;
}

void AFESystemBoxes::SetVFXDisplayName(const FString VFXDisplayName)
{
	VFXfuncName = VFXDisplayName;
}

void AFESystemBoxes::SetFUNDisplayName(const FString FUNDisplayName)
{
	FUNfuncName = FUNDisplayName;
}

void AFESystemBoxes::LoadingFunctions()
{
	switch (EventTypes)
	{
	case ETriggerTypes::VFX:
	{
		TArray<UFunction*> functions;
		UFESystemMethods::GetAllVFXUFunction(this, functions);
		
		for (int i = 0; i < functions.Num(); i++) 
		{
			if (functions[i]->GetFName().ToString() == VFXfuncName)
			{
				VFXfunc = functions[i];
				return;
			}
		}
		VFXfunc = nullptr;
	}
	break;
	case ETriggerTypes::SFX:
	{
		TArray<UFunction*> functions;
		UFESystemMethods::GetAllSFXUFunction(this, functions);

		for (int i = 0; i < functions.Num(); i++)
		{
			if (functions[i]->GetFName().ToString() == SFXfuncName)
			{
				SFXfunc = functions[i];
				return;
			}
		}
		SFXfunc = nullptr;
	}
		break;
	case ETriggerTypes::Functional:
	{
		TArray<UFunction*> functions;
		UFESystemMethods::GetAllFunctionalUFunction(this, functions);
		
		for (int i = 0; i < functions.Num(); i++)
		{
			if (functions[i]->GetFName().ToString() == FUNfuncName)
			{
				FUNfunc = functions[i];
				return;
			}
		}
		FUNfunc = nullptr;
	}
		break;
	default:
		break;
	}
}

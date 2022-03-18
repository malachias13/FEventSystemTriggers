// YourModuleName.Build.cs
using UnrealBuildTool;

public class FEventSystemEditor : ModuleRules
{
    public FEventSystemEditor(ReadOnlyTargetRules Target) : base(Target)
    {
		PublicIncludePaths.AddRange(
			   new string[] {
				   "FEventTriggerSystem/Public"
				   // ... add public include paths required here ...
			   }
			   );


		PrivateIncludePaths.AddRange(
			new string[] {
				"FEventTriggerSystem/Private"
				// ... add other private include paths required here ...
			}
			);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"UnrealEd",
				"Blutility",
				"UMG",
				"FEventTriggerSystem"
				// ... add other public dependencies that you statically link with here ...
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore"
				// ... add private dependencies that you statically link with here ...	
			}
			);
	}
}
// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Aux_Practica_3P : ModuleRules
{
	public Aux_Practica_3P(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "Slate", "SlateCore" });
    }
}

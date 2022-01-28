// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GrenadeProject : ModuleRules
{
	public GrenadeProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivatePCHHeaderFile = "MaulProtoPrecompiled.h";
		MinFilesUsingPrecompiledHeaderOverride = 1;
		bUseUnity = false;
	}
}


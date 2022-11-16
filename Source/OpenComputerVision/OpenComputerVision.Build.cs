// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OpenComputerVision : ModuleRules
{
	public OpenComputerVision(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        bUseRTTI = true;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
                "$(PluginDir)/Source/ThirdParty/OpenCVLibrary",
				"$(PluginDir)/Source/ThirdParty/OpenCVLibrary/Win64/include"
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"OpenCVLibrary",
				"Projects"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class OpenComputerVisionLibrary : ModuleRules
{
	public OpenComputerVisionLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "opencv.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "opencv_world460.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "opencv_world460d.lib"));

			// Delay-load the DLL, so we can load it from the right place first
            PublicDelayLoadDLLs.Add("opencv.dll");
            PublicDelayLoadDLLs.Add("opencv_world460.dll");
            PublicDelayLoadDLLs.Add("opencv_world460d.dll");
            PublicDelayLoadDLLs.Add("opencv_videoio_msmf460_64.dll");
            PublicDelayLoadDLLs.Add("opencv_videoio_msmf460_64d.dll");
            PublicDelayLoadDLLs.Add("opencv_videoio_ffmpeg460_64.dll");

			// Ensure that the DLL is staged along with the executable
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_world460.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_world460d.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_videoio_msmf460_64.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_videoio_msmf460_64d.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_videoio_ffmpeg460_64.dll");

        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            PublicDelayLoadDLLs.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libExampleLibrary.dylib"));
            RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/OpenComputerVisionLibrary/Mac/Release/libExampleLibrary.dylib");
        }
	}
}

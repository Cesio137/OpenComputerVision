using System.IO;
using UnrealBuildTool;

public class OpenCV : ModuleRules
{
	public OpenCV(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		bUseRTTI = true;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			if (Target.Configuration == UnrealTargetConfiguration.Debug || Target.Configuration == UnrealTargetConfiguration.DebugGame)
			{
				// Add the import library
				PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "opencv_world460d.lib"));
				
				// Delay-load the DLL, so we can load it from the right place first
				PublicDelayLoadDLLs.Add("opencv_world460d.dll");
				PublicDelayLoadDLLs.Add("opencv_videoio_msmf460_64d.dll");
				PublicDelayLoadDLLs.Add("opencv_videoio_ffmpeg460_64.dll");
				
				// Ensure that the DLL is staged along with the executable
				RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_world460d.dll");
				RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_videoio_msmf460_64d.dll");
				RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_videoio_ffmpeg460_64.dll");
			}
			else
			{
				// Add the import library
				PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "opencv_world460.lib"));

				// Delay-load the DLL, so we can load it from the right place first
				PublicDelayLoadDLLs.Add("opencv_world460.dll");
				PublicDelayLoadDLLs.Add("opencv_videoio_msmf460_64.dll");
				PublicDelayLoadDLLs.Add("opencv_videoio_ffmpeg460_64.dll");


				// Ensure that the DLL is staged along with the executable
				RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_world460.dll");
				RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_videoio_msmf460_64.dll");
				RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_videoio_ffmpeg460_64.dll");
			}
		}
	}
}
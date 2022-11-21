#if defined _WIN32 || defined _WIN64
    #include "OpenCVLibrary.h"

    
#else // defined __linux__
    #include <stdio.h>
#endif

void OpenCVLibraryFunction()
{
#if defined _WIN32 || defined _WIN64
	MessageBox(NULL, TEXT("Loaded OpenCV 4.6.0 Plugin."), TEXT("OpenCV 4.6.0 Plugin"), MB_OK);
#else
    printf("Loaded OpenCV 4.6.0 Plugin");
#endif
}

#include "library.h"



void UOpenCVLibrary()
{
#if defined _WIN32 || defined _WIN64
    MessageBox(NULL, TEXT("Loaded OpenCV 4.6.0 Library"), TEXT("OpenCV 4.6.0 Plugin"), MB_OK);
#else
    printf("Loaded OPENCVLIBRARY from Third Party Plugin sample");
#endif
}


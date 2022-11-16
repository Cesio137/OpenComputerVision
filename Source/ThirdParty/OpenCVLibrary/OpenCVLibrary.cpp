#if defined _WIN32 || defined _WIN64
#include "OpenCVLibrary.h"

#define OPENCVLIBRARY_EXPORT __declspec(dllexport)
#else
#include <stdio.h>
#endif

#ifndef OPENCVLIBRARY_EXPORT
#define OPENCVLIBRARY_EXPORT
#endif


OPENCVLIBRARY_EXPORT ocl::Context context;
OPENCVLIBRARY_EXPORT ocl::Device device;

OPENCVLIBRARY_EXPORT void OpenCVLibraryFunction()
{
#if defined _WIN32 || defined _WIN64
    MessageBox(NULL, TEXT("Loaded OpenCV 4.6.0 Library"), TEXT("OpenCV 4.6.0 Plugin"), MB_OK);
#else
    printf("Loaded OPENCVLIBRARY from Third Party Plugin sample");
#endif
}

OPENCVLIBRARY_EXPORT bool CreateContext(int dtype)
{
    return context.create(dtype);
}




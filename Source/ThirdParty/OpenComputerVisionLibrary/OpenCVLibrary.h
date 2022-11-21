#define OPENCVLIBRARY_EXPORT

#if defined _WIN32 || defined _WIN64
#include <Windows.h>
#include <array>

#pragma push_macro("check")
#undef check
#include "opencv2/opencv.hpp"
#include "opencv2/core/ocl.hpp"
#pragma pop_macro("check")

#ifndef OPENCVLIBRARY_EXPORT
#define OPENCVLIBRARY __declspec(dllexport)
#else
#define OPENCVLIBRARY __declspec(dllimport)
#endif
#endif

#if defined __linux__

#ifndef OPENCVLIBRARY_EXPORT
#define OPENCVLIBRARY 
#else
#define OPENCVLIBRARY_IMPORT __attribute__((visibility("default")))
#endif
#endif

using namespace cv;
using namespace std;

OPENCVLIBRARY void OpenCVLibraryFunction();

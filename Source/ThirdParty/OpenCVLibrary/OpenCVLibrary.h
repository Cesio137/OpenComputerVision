#if defined _WIN32 || defined _WIN64
#include <Windows.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core/ocl.hpp"

#define OPENCVLIBRARY_IMPORT __declspec(dllimport)
#elif defined __linux__
#define OPENCVLIBRARY_IMPORT __attribute__((visibility("default")))
#else
#define OPENCVLIBRARY_IMPORT
#endif

/* Global Includes */

using namespace cv;

OPENCVLIBRARY_IMPORT ocl::Context context;
OPENCVLIBRARY_IMPORT ocl::Device device;

OPENCVLIBRARY_IMPORT void OpenCVLibraryFunction();
OPENCVLIBRARY_IMPORT bool CreateContext(int dtype);


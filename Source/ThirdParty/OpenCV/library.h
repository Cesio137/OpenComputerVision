#ifndef OPENCV_LIBRARY_H
#if defined _WIN32 || defined _WIN64
    /* Windows Includes */
    #include <Windows.h>
    #include "opencv2/opencv.hpp"
    #include "opencv2/core/ocl.hpp"

    #define OPENCV_LIBRARY_H __declspec(dllexport)
    #elif defined __linux__
    /* Linux Includes */

    #define OPENCV_LIBRARY_H __attribute__((visibility("default")))
    #else
    /* Mac Includes */

    #define OPENCV_LIBRARY_H
#endif //Win32 || Win64 || Linux || Mac

/* Global Includes */

using namespace cv;

OPENCV_LIBRARY_H void UOpenCVLibrary();

#endif //OPENCV_LIBRARY_H

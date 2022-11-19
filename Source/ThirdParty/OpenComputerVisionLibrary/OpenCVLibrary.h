#define OPENCVLIBRARY_EXPORT

#if defined _WIN32 || defined _WIN64
#include <Windows.h>
#include <array>

#pragma push_macro("CONSTEXPR")
#undef CONSTEXPR
#pragma push_macro("dynamic_cast")
#undef dynamic_cast
#pragma push_macro("check")
#undef check
#pragma push_macro("PI")
#undef PI
#include "opencv2/opencv.hpp"
#include "opencv2/core/ocl.hpp"
#pragma pop_macro("PI")
#pragma pop_macro("check")
#pragma pop_macro("dynamic_cast")
#pragma pop_macro("CONSTEXPR")

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

enum DeviceVendor
{
    Unknow,
    Intel,
    AMD,
    NVidia
};

struct DeviceInfo
{
    const char* DeviceName;
    const char* VendorName;
    int VendorID;
    bool bIsAvaliable;
    bool bHasImageSuport;
    const char* OpenCLVersion;
    const char* DriverVersion;
    DeviceVendor Vendor;
    int Index;
};

namespace OpenCV
{
    OPENCVLIBRARY void OpenCVLibraryFunction();

    class OPENCVLIBRARY OpenCL
    {
    public:
        ocl::Context context;
        ocl::Device device;

        bool bhaveOpenCL();
        bool CreateContext(int dtype);
        bool IsInitialized();
        void SetUseOpenCL(bool opencl);
        int nDevices();
        array<DeviceInfo, 8> GetAllDeviceInfo();
        DeviceInfo GetDeviceInfo(int index);

    private:
        bool bIsInitialized = false;
    };
}

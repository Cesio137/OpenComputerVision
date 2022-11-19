#if defined _WIN32 || defined _WIN64
    #include "OpenCVLibrary.h"

    
#else // defined __linux__
    #include <stdio.h>
#endif

void OpenCV::OpenCVLibraryFunction()
{
#if defined _WIN32 || defined _WIN64
	MessageBox(NULL, TEXT("Loaded OpenCV 4.6.0 Plugin."), TEXT("OpenCV 4.6.0 Plugin"), MB_OK);
#else
    printf("Loaded OpenCV 4.6.0 Plugin");
#endif
}

bool OpenCV::OpenCL::bhaveOpenCL()
{
    return ocl::haveOpenCL();
}

bool OpenCV::OpenCL::CreateContext(int dtype)
{
    bIsInitialized = context.create(dtype);
    return bIsInitialized;
}

bool OpenCV::OpenCL::IsInitialized()
{
    return bIsInitialized;
}

void OpenCV::OpenCL::SetUseOpenCL(bool opencl)
{
    ocl::setUseOpenCL(opencl);
}

int OpenCV::OpenCL::nDevices()
{
    return context.ndevices();
}

array<DeviceInfo, 8> OpenCV::OpenCL::GetAllDeviceInfo()
{
    array<DeviceInfo, 8> info;
    DeviceInfo currentinfo;
    
    for (int i = 0; i < context.ndevices(); i++)
    {
        currentinfo.DeviceName = context.device(i).name().c_str();
        currentinfo.VendorName = context.device(i).vendorName().c_str();
        currentinfo.VendorID = context.device(i).vendorID();
        currentinfo.bIsAvaliable = context.device(i).available();
        currentinfo.bHasImageSuport = context.device(i).imageSupport();
        currentinfo.OpenCLVersion = context.device(i).OpenCLVersion().c_str();
        currentinfo.DriverVersion = context.device(i).driverVersion().c_str();
        currentinfo.Index = i;

        if (context.device(i).isIntel())
        {
            currentinfo.Vendor = DeviceVendor::Intel;
        }
        else if(context.device(i).isAMD())
        {
            currentinfo.Vendor = DeviceVendor::AMD;
        }
        else if(context.device(i).isNVidia())
        {
            currentinfo.Vendor = DeviceVendor::NVidia;
        }
        else
        {
            currentinfo.Vendor = DeviceVendor::Unknow;
        }

        info[i] = currentinfo;
    }

    return info;
}

DeviceInfo OpenCV::OpenCL::GetDeviceInfo(int index)
{
    DeviceInfo currentinfo;

    currentinfo.DeviceName = context.device(index).name().c_str();
    currentinfo.VendorName = context.device(index).vendorName().c_str();
    currentinfo.VendorID = context.device(index).vendorID();
    currentinfo.bIsAvaliable = context.device(index).available();
    currentinfo.bHasImageSuport = context.device(index).imageSupport();
    currentinfo.OpenCLVersion = context.device(index).OpenCLVersion().c_str();
    currentinfo.DriverVersion = context.device(index).driverVersion().c_str();
    currentinfo.Index = index;

    if (context.device(index).isIntel())
    {
        currentinfo.Vendor = DeviceVendor::Intel;
    }
    else if(context.device(index).isAMD())
    {
        currentinfo.Vendor = DeviceVendor::AMD;
    }
    else if(context.device(index).isNVidia())
    {
        currentinfo.Vendor = DeviceVendor::NVidia;
    }
    else
    {
        currentinfo.Vendor = DeviceVendor::Unknow;
    }
    
    return currentinfo;
}

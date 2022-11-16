# OpenComputerVision UE 4.26/4.27/5

---



This is a integration of [OpenCV](https://opencv.org) as a thirdparty plugin for Unreal Engine



---



- [x] Windows

- [ ] Linux(Help Wanted)

- [ ] Mac(Help Wanted)

# Setting Up Your Project



- Install VS 2019/2022 and Engine sources.
- Install CMake 3.20 or above.
- Clone the repository or download the latest release.
- Move `OpenComputerVision` folder into your project's `Plugins` folder.
- Download [OpenComputerVision Binaries](https://github.com/Cesio137/OpenComputerVision/releases/tag/Libraries) and open the `.zip` file and extract  `folders` inside `OpenComputerVision` folder. It's contain the .dll and .lib files to make project work.
- Create `build` folder inside `Source/ThirdParty/OpenCVLibrary`.
- Open a terminal then type `cmake .. -G "Visual Studio 16 2019"` or `cmake .. -G "Visual Studio 17 2022"`.
- Build VS soluction in `Release` mode.

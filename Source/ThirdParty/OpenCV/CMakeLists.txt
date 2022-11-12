cmake_minimum_required(VERSION 3.20)
project(OpenCV)

set(CMAKE_CXX_STANDARD 14)

add_library(OpenCV_lib STATIC library.h library.cpp)
add_library(OpenCV_dll SHARED library.h library.cpp)
target_include_directories(OpenCV_lib PUBLIC ${CMAKE_SOURCE_DIR}/Win64/include)
target_link_libraries(OpenCV_lib ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460.lib ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460d.lib)
target_include_directories(OpenCV_dll PUBLIC ${CMAKE_SOURCE_DIR}/Win64/include)
target_link_libraries(OpenCV_dll ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460.lib ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460d.lib)

add_custom_command(TARGET OpenCV_lib POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:OpenCV_lib> ${CMAKE_SOURCE_DIR}/Win64/lib/OpenCV.lib
        )

add_custom_command(TARGET OpenCV_dll POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:OpenCV_dll> ${CMAKE_SOURCE_DIR}/../../../Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/OpenCV.dll
        )

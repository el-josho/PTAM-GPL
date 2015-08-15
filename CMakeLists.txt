cmake_minimum_required(VERSION 2.8)

project(PTAM-SLAM)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

find_package(GVars3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(CVD REQUIRED)
find_package(TooN REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(
    include/
    ${GVARS3_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${CVD_INCLUDE_DIRS}
    ${TOON_INCLUDE_DIRS}
    )

set(PTAM_SOURCES
    src/ARDriver.cpp
    src/ATANCamera.cpp
    src/Bundle.cpp
    src/EyeGame.cpp
    src/GLWindow2.cpp
    src/GLWindowMenu.cpp
    src/HomographyInit.cpp
    src/KeyFrame.cpp
    src/Map.cpp
    src/MapMaker.cpp
    src/MapPoint.cpp
    src/MapViewer.cpp
    src/MiniPatch.cpp
    src/PatchFinder.cpp
    src/Relocaliser.cpp
    src/ShiTomasi.cpp
    src/SmallBlurryImage.cpp
    src/System.cpp
    src/Tracker.cpp
    src/VideoOpenCVSource.cpp
    )

set(CALIB_SOURCES
    src/ATANCamera.cpp
    src/CalibCornerPatch.cpp
    src/CalibImage.cpp
    src/GLWindow2.cpp
    src/GLWindowMenu.cpp
    src/VideoOpenCVSource.cpp
    )

set(LIBS
    ${GVARS3_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${CVD_LIBRARIES}
    ${TOON_LIBRARIES}
    ${OpenCV_LIBS}
    )

add_executable(CameraCalibrator
    src/CameraCalibrator.cpp
    ${CALIB_SOURCES}
    )

target_link_libraries(CameraCalibrator ${LIBS})

add_executable(PTAM
    src/main.cpp
    ${PTAM_SOURCES}
    )

target_link_libraries(PTAM ${LIBS})

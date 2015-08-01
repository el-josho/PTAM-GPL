cmake_minimum_required(VERSION 2.8)

project(PTAM-SLAM)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenGL REQUIRED)

find_library(CVD_LIBRARY
    NAMES libcvd.so
    )

find_library(GVARS3_LIBRARY
    NAMES libGVars3.so
    )

find_package(LAPACK)

# TODO automatically locate include directories
set(TOON_INCLUDE_DIR /usr/include/TooN/)
set(CVD_INCLUDE_DIR /usr/include/cvd/)

include_directories(
    Src/
    ${OPENGL_INCLUDE_DIRS}
    ${TOON_INCLUDE_DIR}
    ${CVD_INCLUDE_DIR}
)

add_executable(ptam
    Src/ARDriver.cc
    Src/ATANCamera.cc
    Src/Bundle.cc
    Src/CalibCornerPatch.cc
    #Src/CalibImage.cc
    #Src/CameraCalibrator.cc
    Src/EyeGame.cc
    Src/GLWindow2.cc
    Src/GLWindowMenu.cc
    Src/HomographyInit.cc
    Src/KeyFrame.cc
    Src/main.cc
    Src/Map.cc
    Src/MapMaker.cc
    Src/MapPoint.cc
    Src/MapViewer.cc
    Src/MiniPatch.cc
    Src/PatchFinder.cc
    Src/Relocaliser.cc
    Src/ShiTomasi.cc
    Src/SmallBlurryImage.cc
    Src/System.cc
    Src/Tracker.cc
    Src/VideoSource.cc
    )

set(LIBS
    ${OPENGL_LIBRARIES}
    ${CVD_LIBRARY}
    ${GVARS3_LIBRARY}
    ${LAPACK_LIBRARIES}
    )

target_link_libraries(ptam ${LIBS})

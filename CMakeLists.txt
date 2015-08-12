cmake_minimum_required(VERSION 2.8)

project(PTAM-SLAM)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(GVars3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(CVD REQUIRED)
find_package(TooN REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(
    src/
    ${GVARS3_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${CVD_INCLUDE_DIRS}
    ${TOON_INCLUDE_DIRS}
    )

set(PTAM_SOURCES
    src/ARDriver.cc
    src/ATANCamera.cc
    src/Bundle.cc
    src/EyeGame.cc
    src/GLWindow2.cc
    src/GLWindowMenu.cc
    src/HomographyInit.cc
    src/KeyFrame.cc
    src/Map.cc
    src/MapMaker.cc
    src/MapPoint.cc
    src/MapViewer.cc
    src/MiniPatch.cc
    src/PatchFinder.cc
    src/Relocaliser.cc
    src/ShiTomasi.cc
    src/SmallBlurryImage.cc
    src/System.cc
    src/Tracker.cc
    src/VideoSource.cc
    )

set(CALIB_SOURCES
    src/ATANCamera.cc
    src/CalibCornerPatch.cc
    src/CalibImage.cc
    src/GLWindow2.cc
    src/GLWindowMenu.cc
    src/VideoSource.cc
    )

set(LIBS
    ${GVARS3_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${CVD_LIBRARIES}
    ${TOON_LIBRARIES}
    ${OpenCV_LIBS}
    )

add_executable(CameraCalibrator
    src/CameraCalibrator.cc
    ${CALIB_SOURCES}
    )

target_link_libraries(CameraCalibrator ${LIBS})

add_executable(PTAM
    src/main.cc
    ${PTAM_SOURCES}
    )

target_link_libraries(PTAM ${LIBS})

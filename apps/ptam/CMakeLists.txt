file(GLOB_RECURSE PTAM_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/ARDriver.cpp"
    "${CMAKE_SOURCE_DIR}/src/ATANCamera.cpp"
    "${CMAKE_SOURCE_DIR}/src/Bundle.cpp"
    "${CMAKE_SOURCE_DIR}/src/EyeGame.cpp"
    "${CMAKE_SOURCE_DIR}/src/GLWindow2.cpp"
    "${CMAKE_SOURCE_DIR}/src/GLWindowMenu.cpp"
    "${CMAKE_SOURCE_DIR}/src/HomographyInit.cpp"
    "${CMAKE_SOURCE_DIR}/src/KeyFrame.cpp"
    "${CMAKE_SOURCE_DIR}/src/Map.cpp"
    "${CMAKE_SOURCE_DIR}/src/MapMaker.cpp"
    "${CMAKE_SOURCE_DIR}/src/MapPoint.cpp"
    "${CMAKE_SOURCE_DIR}/src/MapViewer.cpp"
    "${CMAKE_SOURCE_DIR}/src/MiniPatch.cpp"
    "${CMAKE_SOURCE_DIR}/src/PatchFinder.cpp"
    "${CMAKE_SOURCE_DIR}/src/Relocaliser.cpp"
    "${CMAKE_SOURCE_DIR}/src/ShiTomasi.cpp"
    "${CMAKE_SOURCE_DIR}/src/SmallBlurryImage.cpp"
    "${CMAKE_SOURCE_DIR}/src/System.cpp"
    "${CMAKE_SOURCE_DIR}/src/Tracker.cpp"
    "${CMAKE_SOURCE_DIR}/src/VideoOpenCVSource.cpp"
	)

add_executable(PTAM
    ${PTAM_SOURCES}
    )

target_include_directories(PTAM PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include")

set(PTAM_LIBS
    ${GVARS3_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${CVD_LIBRARIES}
    ${TOON_LIBRARIES}
    ${OpenCV_LIBS}
    )

target_link_libraries(PTAM ${PTAM_LIBS})

install(
    TARGETS PTAM
    DESTINATION "${CMAKE_SOURCE_DIR}/bin"
    )

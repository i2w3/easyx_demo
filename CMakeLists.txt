cmake_minimum_required(VERSION 3.27)

project(MyDino LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

# vcpkg install package
find_package(fmt CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)

# use external package
message("Looking for Qt...")
set(Qt6_DIR "C:/BoostProgram/Qt/6.6.1/mingw_64/lib/cmake/Qt6")
find_package(Qt6 COMPONENTS Core Gui Quick REQUIRED)
if (${Qt6_FOUND})
    message("Found Qt " ${Qt6_VERSION})
else()
    message("Couldn't find Qt")
endif()

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
target_link_libraries(${PROJECT_NAME} PRIVATE glog::glog)
target_link_libraries(${PROJECT_NAME} PRIVATE opencv_ml opencv_dnn opencv_core opencv_flann)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Quick)

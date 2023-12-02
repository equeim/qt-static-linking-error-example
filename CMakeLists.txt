cmake_minimum_required(VERSION 3.27)

if (NOT DEFINED ENV{VCPKG_ROOT})
    message(FATAL_ERROR "VCPKG_ROOT environment variable must be set to the path of vcpkg installation")
endif ()
cmake_path(CONVERT "$ENV{VCPKG_ROOT}" TO_CMAKE_PATH_LIST vcpkg_root NORMALIZE)
set(CMAKE_TOOLCHAIN_FILE "${vcpkg_root}/scripts/buildsystems/vcpkg.cmake")

set(VCPKG_TARGET_TRIPLET "x64-windows-static")
set(VCPKG_HOST_TRIPLET "x64-windows-static")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(qt_static_linking_example)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(qt_static_linking_error_example main.cpp
        without_disable_deprecated.cpp
        with_disable_deprecated.cpp)

set_source_files_properties(with_disable_deprecated.cpp PROPERTIES COMPILE_DEFINITIONS QT_DISABLE_DEPRECATED_BEFORE=0x060600)

target_link_libraries(qt_static_linking_error_example PRIVATE Qt6::Core)

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(tn_base)

if (VCPKG_TARGET_TRIPLET MATCHES "-static$")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/output")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/output")

if (WIN32)
    add_compile_options("/FC")
endif ()

find_package(Boost COMPONENTS "filesystem" REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_subdirectory(src)

if (WITH_tn_base_EXAMPLE)
    add_subdirectory(example)
endif ()

install(EXPORT "tn-base-config" NAMESPACE tn:: DESTINATION "share/tn-base")

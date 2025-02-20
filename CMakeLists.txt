cmake_minimum_required(VERSION 3.10)

# Set the project name
project(lwm2m_client_zynq)

# Set output paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../out/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../out/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../out/lib)

# Fetch Wakaama
include(FetchContent)
FetchContent_Declare(
    wakaama
    GIT_REPOSITORY https://github.com/eclipse/wakaama.git
    GIT_TAG        master # You might want to specify a specific version/tag
)
FetchContent_MakeAvailable(wakaama)

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${wakaama_SOURCE_DIR}/core
    ${wakaama_SOURCE_DIR}/coap
)

# Add subdirectories
add_subdirectory(src)

# Enable testing
enable_testing()

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler warnings
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

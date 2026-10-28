# CMake version.
cmake_minimum_required(VERSION 3.10)
project(campaign LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Project.
project(dioramaLibrary)

add_library(diorama SHARED)


# Gather & group files.
file(GLOB_RECURSE DIORAMA_SOURCE "./src/*.cpp")
file(GLOB_RECURSE DIORAMA_HEADERS "./include/*.h")

target_sources(diorama
    PRIVATE
        ${DIORAMA_SOURCE}
        
    PUBLIC
        FILE_SET dioramaHeaders
        TYPE HEADERS
        BASE_DIRS
            include
        FILES
            ${DIORAMA_HEADERS}
)


# Set output.

set_target_properties(diorama PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


# Build tests.

if(BUILD_TESTING)
    enable_testing()

    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
cmake_minimum_required(VERSION 3.28)

# The version lives in include/NVTools/Version.hpp only: read it from there.
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/include/NVTools/Version.hpp" nvtools_version_lines
    REGEX "^#define NVTOOLS_VERSION_(MAJOR|MINOR|PATCH) [0-9]+")
foreach(line IN LISTS nvtools_version_lines)
    string(REGEX MATCH "NVTOOLS_VERSION_(MAJOR|MINOR|PATCH) ([0-9]+)" _ "${line}")
    set(nvtools_version_${CMAKE_MATCH_1} ${CMAKE_MATCH_2})
endforeach()

project(NVTools
    VERSION ${nvtools_version_MAJOR}.${nvtools_version_MINOR}.${nvtools_version_PATCH}
    DESCRIPTION "Versatile C++23 utility library"
    HOMEPAGE_URL "https://github.com/NetcatRunner/NVTools"
    LANGUAGES CXX
)

include(GNUInstallDirs)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(NVToolsOptions)
include(NVToolsFlags)

add_subdirectory(src)

if(NVTOOLS_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(NVTOOLS_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(NVTOOLS_INSTALL)
    include(NVToolsInstall)
endif()

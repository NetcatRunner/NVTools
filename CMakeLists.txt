cmake_minimum_required(VERSION 3.28)

project(NVTools
    VERSION 0.0.0
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

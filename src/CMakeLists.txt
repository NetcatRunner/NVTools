add_library(NVTools)   # STATIC or SHARED from BUILD_SHARED_LIBS
add_library(NVTools::NVTools ALIAS NVTools)

set_target_properties(NVTools PROPERTIES
    EXPORT_NAME               NVTools
    VERSION                   ${PROJECT_VERSION}
    SOVERSION                 ${PROJECT_VERSION_MAJOR}
    CXX_VISIBILITY_PRESET     hidden
    VISIBILITY_INLINES_HIDDEN ON
    DEFINE_SYMBOL             NVTOOLS_EXPORTS
)

# ── NVTOOLS_API (include/NVTools/Export.hpp): a static library exports nothing ──
get_target_property(nvtools_type NVTools TYPE)
if(nvtools_type STREQUAL "STATIC_LIBRARY")
    target_compile_definitions(NVTools PUBLIC NVTOOLS_STATIC)
endif()

# The build type, for NVTools::buildDescription().
target_compile_definitions(NVTools PRIVATE NVTOOLS_CONFIG_NAME="$<CONFIG>")

target_include_directories(NVTools
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        "${PROJECT_SOURCE_DIR}/src"
)

target_compile_features(NVTools PUBLIC cxx_std_23)

target_link_libraries(NVTools PRIVATE $<BUILD_INTERFACE:NVTools::Flags>)

target_sources(NVTools PRIVATE
    Version.cpp
)

add_subdirectory(String)

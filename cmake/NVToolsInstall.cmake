include_guard(GLOBAL)

include(CMakePackageConfigHelpers)

set(NVTOOLS_CMAKE_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/NVTools")

install(TARGETS NVTools
    EXPORT NVToolsTargets
)

# Public headers
install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp"
)

# Generated header
install(FILES "${PROJECT_BINARY_DIR}/generated/NVTools/VersionConfig.hpp"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/NVTools
)

install(EXPORT NVToolsTargets
    NAMESPACE   NVTools::
    DESTINATION ${NVTOOLS_CMAKE_DIR}
)

configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/NVToolsConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/NVToolsConfig.cmake"
    INSTALL_DESTINATION ${NVTOOLS_CMAKE_DIR}
)

write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/NVToolsConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${PROJECT_BINARY_DIR}/NVToolsConfig.cmake"
    "${PROJECT_BINARY_DIR}/NVToolsConfigVersion.cmake"
    DESTINATION ${NVTOOLS_CMAKE_DIR}
)

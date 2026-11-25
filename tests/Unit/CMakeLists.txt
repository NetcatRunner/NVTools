find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(NVToolsTests)

target_sources(NVToolsTests PRIVATE
    VersionTests.cpp
)

add_subdirectory(String)

target_link_libraries(NVToolsTests PRIVATE NVTools::NVTools NVTools::Flags GTest::gtest_main)

gtest_discover_tests(NVToolsTests DISCOVERY_MODE PRE_TEST PROPERTIES LABELS unit)

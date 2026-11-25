include_guard(GLOBAL)

# ── Options ──────────────────────────────────────────────────────────────────────────────────────
option(NVTOOLS_BUILD_TESTS        "Build the unit tests"                                                  ${PROJECT_IS_TOP_LEVEL})
option(NVTOOLS_BUILD_EXAMPLES     "Build the examples"                                                    ${PROJECT_IS_TOP_LEVEL})
option(NVTOOLS_INSTALL            "Generate the install rules and the CMake package"                      ${PROJECT_IS_TOP_LEVEL})
option(NVTOOLS_WERROR             "Treat warnings as errors (ON in the presets, OFF for packagers)"       OFF)
option(NVTOOLS_SANITIZE_ADDRESS   "AddressSanitizer and LeakSanitizer"                                    OFF)
option(NVTOOLS_SANITIZE_UNDEFINED "UndefinedBehaviorSanitizer"                                            OFF)
option(NVTOOLS_SANITIZE_THREAD    "ThreadSanitizer (exclusive with AddressSanitizer)"                     OFF)
option(NVTOOLS_HARDENING          "Hardened binaries: fortified libc, stack protection, RELRO (OpenSSF)"  OFF)
option(NVTOOLS_FRAME_POINTERS     "Keep the frame pointers: whole call stacks for perf and crash reports" OFF)

if(NVTOOLS_SANITIZE_THREAD AND NVTOOLS_SANITIZE_ADDRESS)
    message(FATAL_ERROR "NVTools: ThreadSanitizer and AddressSanitizer cannot be enabled together")
endif()

if(PROJECT_IS_TOP_LEVEL)
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
endif()

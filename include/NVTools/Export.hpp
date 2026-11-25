/// @file
/// @brief NVTOOLS_API: marks what the library exports from a shared build.
///
/// - Static build: NVTOOLS_STATIC is defined (by CMake, for the library and its clients): nothing to export.
/// - Shared build: NVTOOLS_EXPORTS is defined while building the library only: export, else import.
#pragma once

#if defined(NVTOOLS_STATIC)
#  define NVTOOLS_API
#elif defined(_WIN32)
#  if defined(NVTOOLS_EXPORTS)
#    define NVTOOLS_API __declspec(dllexport)
#  else
#    define NVTOOLS_API __declspec(dllimport)
#  endif
#else
#  define NVTOOLS_API __attribute__((visibility("default")))
#endif

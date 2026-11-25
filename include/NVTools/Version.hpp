/// @file
/// @brief The version of NVTools: the one of the headers, and the one the binary was built with.
#pragma once

#include <NVTools/Export.hpp>

#include <cstdint>
#include <string_view>

// The single source of truth of the version: the root CMakeLists.txt reads these three lines.
// Macros, not an enum: usable in #if and readable by CMake.
// NOLINTBEGIN(*-macro-to-enum)
#define NVTOOLS_VERSION_MAJOR 0
#define NVTOOLS_VERSION_MINOR 0
#define NVTOOLS_VERSION_PATCH 0
// NOLINTEND(*-macro-to-enum)

namespace NVTools {

    // ── The version of the headers, known at compile time ──────────────────────────────────────
    [[nodiscard]] constexpr std::uint32_t versionMajor() noexcept { return NVTOOLS_VERSION_MAJOR; }   ///< Major, from the headers.
    [[nodiscard]] constexpr std::uint32_t versionMinor() noexcept { return NVTOOLS_VERSION_MINOR; }   ///< Minor, from the headers.
    [[nodiscard]] constexpr std::uint32_t versionPatch() noexcept { return NVTOOLS_VERSION_PATCH; }   ///< Patch, from the headers.

    // ── The version the library was built with (a shared build may differ from the headers) ───
    [[nodiscard]] NVTOOLS_API std::string_view versionString() noexcept;   ///< "1.4.2", from the binary.
    /// "NVTools 1.4.2 (GCC, Release)", from the binary: for logs, --version and bug reports.
    [[nodiscard]] NVTOOLS_API std::string_view buildDescription() noexcept;
}

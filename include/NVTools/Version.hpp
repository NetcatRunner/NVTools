#pragma once

#include <NVTools/Export.hpp>
#include <NVTools/VersionConfig.hpp>

#include <cstdint>
#include <string_view>

namespace NVTools {

    // ── The version a client was compiled against (headers) ──────────────────────────────────
    [[nodiscard]] constexpr std::uint32_t versionMajor() noexcept { return NVTOOLS_VERSION_MAJOR; }   ///< Major, from the headers.
    [[nodiscard]] constexpr std::uint32_t versionMinor() noexcept { return NVTOOLS_VERSION_MINOR; }   ///< Minor, from the headers.
    [[nodiscard]] constexpr std::uint32_t versionPatch() noexcept { return NVTOOLS_VERSION_PATCH; }   ///< Patch, from the headers.

    // ── The version the library was built with (a shared build or a plugin may differ) ───────
    [[nodiscard]] NVTOOLS_API std::string_view versionString() noexcept;   ///< "1.4.2", from the binary.
    /// "NVTools 1.4.2 (GCC, RelWithDebInfo)", from the binary: the first line of the log, --version, crash reports.
    [[nodiscard]] NVTOOLS_API std::string_view buildDescription() noexcept;

}

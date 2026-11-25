#include <NVTools/Version.hpp>
#include <NVTools/VersionConfig.hpp>

#include <string_view>

#if defined(__clang__)
#  define NVTOOLS_COMPILER_NAME "Clang"
#elif defined(__GNUC__)
#  define NVTOOLS_COMPILER_NAME "GCC"
#elif defined(_MSC_VER)
#  define NVTOOLS_COMPILER_NAME "MSVC"
#else
#  define NVTOOLS_COMPILER_NAME "unknown compiler"
#endif

namespace NVTools {

    std::string_view versionString() noexcept
    {
        return NVTOOLS_VERSION_STRING;
    }

    std::string_view buildDescription() noexcept
    {
        return NVTOOLS_NAME " " NVTOOLS_VERSION_STRING " (" NVTOOLS_COMPILER_NAME ", " NVTOOLS_CONFIG_NAME ")";
    }
}

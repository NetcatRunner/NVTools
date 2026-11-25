#include <NVTools/Version.hpp>

#include <string_view>

#define NVTOOLS_STRINGIFY_IMPL(x) #x
#define NVTOOLS_STRINGIFY(x)      NVTOOLS_STRINGIFY_IMPL(x)
#define NVTOOLS_VERSION_TEXT                                                                                                                                   \
    NVTOOLS_STRINGIFY(NVTOOLS_VERSION_MAJOR) "." NVTOOLS_STRINGIFY(NVTOOLS_VERSION_MINOR) "." NVTOOLS_STRINGIFY(NVTOOLS_VERSION_PATCH)

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
        return NVTOOLS_VERSION_TEXT;
    }

    std::string_view buildDescription() noexcept
    {
        return "NVTools " NVTOOLS_VERSION_TEXT " (" NVTOOLS_COMPILER_NAME ", " NVTOOLS_CONFIG_NAME ")";
    }
}

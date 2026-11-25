/// @file
/// @brief Joining strings and numbers with NVTools::String.

#include <NVTools/String/Join.hpp>
#include <NVTools/Version.hpp>

#include <cstdlib>
#include <print>
#include <string>
#include <vector>

int main()
{
    namespace Str = NVTools::String;

    std::println("{}", NVTools::buildDescription());   // NVTools 0.0.0 (GCC, Debug)

    const std::vector<std::string> words = {"alpha", "beta", "gamma"};
    std::println("{}", Str::join(words, ", "));        // alpha, beta, gamma
    std::println("{}", Str::join({1, 2, 3}, " + "));   // 1 + 2 + 3
    std::println("{}", Str::joinString(words, '/'));   // alpha/beta/gamma

    return EXIT_SUCCESS;
}

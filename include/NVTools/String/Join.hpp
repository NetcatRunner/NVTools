/// @file
/// @brief Joining strings and numbers with a separator.
#pragma once

#include <NVTools/Export.hpp>

#include <format>
#include <initializer_list>
#include <ranges>
#include <span>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

namespace NVTools::String {

    /// @name Joining
    /// Numbers are formatted with `std::format`: `join({1, 2, 3}, ", ")` gives `1, 2, 3`.
    /// @{

    /// Joins the elements of `parts`, strings or numbers, with `separator` between them.
    template <std::ranges::input_range Range>
    [[nodiscard]] std::string join(const Range& parts, std::string_view separator = {})
    {
        std::string result;
        bool first = true;
        for (const auto& part : parts) {
            if (!first)
                result += separator;
            if constexpr (std::is_arithmetic_v<std::remove_cvref_t<decltype(part)>>)
                result += std::format("{}", part);
            else
                result += part;
            first = false;
        }
        return result;
    }

    /// Joins a braced list, such as `join({4, 5, 6}, "-")`.
    template <typename T>
    [[nodiscard]] std::string join(std::initializer_list<T> parts, std::string_view separator = {})
    {
        return join(std::span<const T>(parts.begin(), parts.size()), separator);
    }

    /// Joins `parts` with no separator: `{"a", "b"}` gives `ab`.
    [[nodiscard]] NVTOOLS_API std::string joinString(const std::vector<std::string>& parts);

    /// Joins `parts` with the one-character `delimiter`: `{"a", "b"}` and `'-'` give `a-b`.
    [[nodiscard]] NVTOOLS_API std::string joinString(const std::vector<std::string>& parts, char delimiter);

    /// @}
}

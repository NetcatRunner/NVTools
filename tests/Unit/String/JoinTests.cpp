#include <NVTools/String/Join.hpp>

#include <gtest/gtest.h>

#include <array>
#include <string>
#include <string_view>
#include <vector>

namespace Str = NVTools::String;

TEST(JoinTests, JoinsStringsWithSeparator)
{
    const std::vector<std::string> parts = {"a", "b", "c"};
    EXPECT_EQ(Str::join(parts, ", "), "a, b, c");
    EXPECT_EQ(Str::join(parts), "abc");
}

TEST(JoinTests, JoinsStringViews)
{
    const std::array<std::string_view, 2> parts = {"left", "right"};
    EXPECT_EQ(Str::join(parts, "|"), "left|right");
}

TEST(JoinTests, FormatsNumbers)
{
    EXPECT_EQ(Str::join({1, 2, 3}, " + "), "1 + 2 + 3");
    EXPECT_EQ(Str::join({1.5, 2.25}, ";"), "1.5;2.25");
}

TEST(JoinTests, ReturnsEmptyForEmptyRange)
{
    EXPECT_EQ(Str::join(std::vector<std::string>{}, "-"), "");
}

TEST(JoinTests, JoinStringWithCharDelimiter)
{
    const std::vector<std::string> parts = {"a", "b", "c"};
    EXPECT_EQ(Str::joinString(parts, '-'), "a-b-c");
    EXPECT_EQ(Str::joinString(parts), "abc");
    EXPECT_EQ(Str::joinString({}), "");
}

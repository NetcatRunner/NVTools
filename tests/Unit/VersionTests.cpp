#include <NVTools/Version.hpp>

#include <gtest/gtest.h>

#include <format>
#include <string>

TEST(VersionTests, BinaryMatchesHeaders)
{
    const std::string expected = std::format("{}.{}.{}", NVTools::versionMajor(), NVTools::versionMinor(), NVTools::versionPatch());
    EXPECT_EQ(NVTools::versionString(), expected);
}

TEST(VersionTests, BuildDescriptionStartsWithNameAndVersion)
{
    const std::string expected = std::format("NVTools {} (", NVTools::versionString());
    EXPECT_TRUE(NVTools::buildDescription().starts_with(expected));
}

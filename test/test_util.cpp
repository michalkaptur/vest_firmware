#include <gtest/gtest.h>
#include "util.h"
#include <string>

TEST(util_test, calculate_checksum)
{
    std::string s("SOK");
    EXPECT_EQ(37, util::calc_checksum(s.c_str(),s.size()));
    s = "#SOK";
    EXPECT_EQ(37, util::calc_checksum(s.c_str(),s.size()));
    s = "[S#OK#]";
    EXPECT_EQ(37, util::calc_checksum(s.c_str(),s.size()));
}

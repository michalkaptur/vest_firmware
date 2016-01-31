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

TEST(util_test, digit_conversion)
{
    EXPECT_EQ(0, util::digit_to_num('0'));
    EXPECT_EQ(9, util::digit_to_num('9'));
    EXPECT_EQ(-1, util::digit_to_num('a'));
}

TEST(util_test, numbers_parser_ok)
{
    numbers_seq s;
    std::string str("");
    ASSERT_TRUE(util::parse_numbers(str.c_str(), s));
    ASSERT_EQ(0, s.size);

    str = "12.345.6";
    ASSERT_TRUE(util::parse_numbers(str.c_str(), s));
    ASSERT_EQ(3, s.size);
    ASSERT_TRUE(s.numbers);
    ASSERT_EQ(12, s.numbers[0]);
    ASSERT_EQ(345, s.numbers[1]);
    ASSERT_EQ(6, s.numbers[2]);
}

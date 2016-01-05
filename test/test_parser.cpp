#include <gtest/gtest.h>
#include "parser.h"
#include "receiver.h"

TEST(parser_test, verify_checksum)
{
    parser p;
    char * partial_str = "S#OK";
    ASSERT_TRUE(p.verify_checksum(partial_str, 4, 37));
}

TEST(parser_test, parse_checksum)
{
    parser p;
    char * str = "S#OK#37\0";
    EXPECT_EQ(RESULT_OK, p.parse(str));
    char * str2 = "D#23.12.45.1#60\0";
    EXPECT_EQ(RESULT_OK, p.parse(str2));
    char * invalid_str = "S#OK#13\0";
    EXPECT_EQ(RESULT_ERR_INVALID_CHECKSUM, p.parse(invalid_str));
}

TEST(parser_test, message_types)
{
    parser p;
    char * str = "S#OK#37\0";
    ASSERT_EQ(RESULT_OK, p.parse(str));
    EXPECT_EQ(MSG_TYPE_STATUS,p.msg.type);
    char * invalid_msg_str = "x#OK#74\0";
    ASSERT_EQ(RESULT_ERR_INVALID_MSG_TYPE, p.parse(invalid_msg_str));
}



TEST(parser_test, min_content)
{
    parser p;
    char * str = "S##83\0";
    EXPECT_EQ(RESULT_OK, p.parse(str));
    char * str2 = "D##6\0";
    EXPECT_FALSE(p.parse(str2));
}

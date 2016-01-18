#include <gtest/gtest.h>
#include "stubs/Arduino.h"
#include "respond.h"
#include "receiver.h"

TEST(test_respond, println)
{
    respond r1(RESULT_OK);
    EXPECT_STREQ("[S#OK#37]", r1.msg);
    respond r2(RESULT_ERR_MALFORMED_PACKET);
    EXPECT_STREQ("[S#ERR.1#11]", r2.msg);
    respond r3(RESULT_ERR_INVALID_MSG_TYPE);
    EXPECT_STREQ("[S#ERR.2#12]", r3.msg);
    respond r4(RESULT_ERR_INVALID_CHECKSUM);
    EXPECT_STREQ("[S#ERR.3#13]", r4.msg);
    respond r5(RESULT_ERR_MSG_TOO_SHORT);
    EXPECT_STREQ("[S#ERR.4#14]", r5.msg);
}

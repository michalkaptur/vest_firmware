#include <gtest/gtest.h>
#include "stubs/Arduino.h"
#include "respond.h"
#include "receiver.h"

TEST(test_respond, println)
{
    respond r1(RESULT_OK);
    respond r2(RESULT_ERR_MALFORMED_PACKET);
    respond r3(RESULT_ERR_INVALID_MSG_TYPE);
}

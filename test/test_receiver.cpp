#include <gtest/gtest.h>
#include "receiver.h"

TEST(receiver_test, add_byte)
{
    receiver r;
    r.put_byte('a');
    EXPECT_STREQ(r.get_buffer(), "a");
    r.put_byte('b');
    r.put_byte('c');
    r.put_byte('d');
    EXPECT_STREQ(r.get_buffer(), "abcd");
}



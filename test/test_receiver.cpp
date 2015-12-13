#include <gtest/gtest.h>
#include "receiver.h"

TEST(receiver_test, add_byte)
{
    receiver r;
    EXPECT_STREQ(NULL, r.get_buffer());
    r.put_byte('a');
    EXPECT_STREQ("a", r.get_buffer());
    r.put_byte('b');
    r.put_byte('c');
    r.put_byte('d');
    EXPECT_STREQ("abcd",r.get_buffer());
}



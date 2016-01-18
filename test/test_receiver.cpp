#include <gtest/gtest.h>
#include "receiver.h"

TEST(receiver_test, add_byte)
{
    receiver r;
    EXPECT_STREQ(NULL, r.get_buffer());
    r.put_byte(TRS_BEGIN);
    EXPECT_STREQ("[", r.get_buffer());
    r.put_byte('b');
    r.put_byte('c');
    r.put_byte('d');
    EXPECT_STREQ("[bcd",r.get_buffer());
}

TEST(receiver_test, transmission_start)
{
    receiver r;
    ASSERT_STREQ(NULL, r.get_buffer());
    ASSERT_FALSE(r.put_byte('a'));
    ASSERT_TRUE(r.put_byte(TRS_BEGIN));
    ASSERT_TRUE(r.put_byte('a'));
    ASSERT_TRUE(r.put_byte(TRS_BEGIN));
    ASSERT_TRUE(r.put_byte('b'));
    EXPECT_STREQ("[b",r.get_buffer());
}

TEST(receiver_test, transmission_end_ok)
{
    receiver r;
    ASSERT_TRUE(r.put_byte(TRS_BEGIN));
    ASSERT_TRUE(r.put_byte('C'));
    ASSERT_TRUE(r.put_byte('#'));
    ASSERT_TRUE(r.put_byte('#'));
    ASSERT_TRUE(r.put_byte('0'));
    ASSERT_TRUE(r.put_byte('0'));
    ASSERT_TRUE(r.put_byte(TRS_END));
    EXPECT_TRUE(r.was_trs_valid());
}

TEST(receiver_test, transmission_end_nok)
{
    receiver r;
    ASSERT_TRUE(r.put_byte(TRS_BEGIN));
    ASSERT_TRUE(r.put_byte('a'));
    ASSERT_TRUE(r.put_byte('b'));
    EXPECT_FALSE(r.was_trs_valid());
}

TEST(receiver_test, buffer_overflow)
{
    receiver r;
    ASSERT_TRUE(r.put_byte(TRS_BEGIN));
    for (int i=0; i<127; ++i) {
        ASSERT_TRUE(r.put_byte('a'));
    }
    ASSERT_FALSE(r.put_byte('a'));
}



#include <gtest/gtest.h>
#include "player.h"
#include "message.h"

TEST(player_test, play_ok)
{
    message msg;
    const std::string msg_data("123");
    msg.data = (char*)msg_data.c_str();
    msg.data_size = msg_data.size();
    msg.type = MSG_TYPE_DATA;
    player p(msg);
    ASSERT_TRUE(p.go());
}

TEST(player_test, nok_invalid_type)
{
    message msg;
    const std::string msg_data("123");
    msg.data = (char*)msg_data.c_str();
    msg.data_size = msg_data.size();
    msg.type = MSG_TYPE_CONFIG;
    player p(msg);
    ASSERT_FALSE(p.go());
}

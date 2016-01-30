#include <gtest/gtest.h>
#include <config.h>

TEST(test_config, init)
{
    ASSERT_GT(config::instance().duration(), 0);
    ASSERT_GT(config::instance().pause(), 0);
    ASSERT_GT(config::instance().intensity(), 0);
}

TEST(test_config, update)
{
    int duration = 1;
    int pause = 2;
    int intensity = 3;
    config::instance().update(duration, pause, intensity);
    ASSERT_EQ(duration, config::instance().duration());
    ASSERT_EQ(pause, config::instance().pause());
    ASSERT_EQ(intensity, config::instance().intensity());
}

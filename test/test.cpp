#include <gtest/gtest.h>
#include "driver.h"

TEST(test1, t1)
{
	EXPECT_TRUE(true);
}

TEST(test2, t2)
{
    driver::turn_output_on(1,50);
}

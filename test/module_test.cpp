#include <gtest/gtest.h>
#include <receiver.h>

TEST(module_test, receiver_ok)
{
    receiver r;
    std::string msg("[D#12.33.21#60]");
    for(std::string::const_iterator it = msg.begin(); it != msg.end(); ++it) {
        r.put_byte(*it);
    }
    ASSERT_TRUE(r.was_trs_valid());
    std::cout<<"order:12.33.21"<<std::endl;
}

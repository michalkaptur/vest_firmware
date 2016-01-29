#include <gtest/gtest.h>
#include <receiver.h>

TEST(module_test, receiver_ok)
{
    receiver r;
    std::string msg("[D#123321#68]");
    for(std::string::const_iterator it = msg.begin(); it != msg.end(); ++it) {
        r.put_byte(*it);
    }
    std::cout<<"order:123321"<<std::endl;
}

#include "Arduino.h"

void Serial_::println(char *str)
{
    std::cout<<"uart tx:"<<str<<std::endl;
}

void Serial_::println(bool str)
{
    std::cout<<"uart tx:"<<str<<std::endl;
}

void Serial_::println(uint8_t str, void *v)
{
    std::cout<<"uart tx:"<<str<<std::endl;
}

void Serial_::print(char *str)
{
    std::cout<<"uart tx:";
}

void Serial_::flush()
{
    std::cout<<std::flush;
}

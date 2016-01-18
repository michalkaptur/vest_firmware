#include "Arduino.h"

void Serial_::println(char *str)
{
    std::cout<<"uart tx:"<<str<<std::endl;
}

void Serial_::println(bool str)
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

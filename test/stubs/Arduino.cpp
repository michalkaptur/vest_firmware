#include "Arduino.h"

void Serial_::println(char *str)
{
    std::cout<<"uart tx:"<<str<<std::endl;
}

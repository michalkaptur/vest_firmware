#ifndef GPIO_H
#define GPIO_H

#include <iostream>
#include <stdint.h>

inline void analogWrite(int out_nr, int out_level)
{
	std::cout<<"out #"<<out_nr<<" set to "<<out_level<<std::endl;
}

inline void delay(int time)
{
	std::cout<<time<<" delay called"<<std::endl;
}
#endif //GPIO_H

#ifndef GPIO_H
#define GPIO_H

#include <iostream>
#include <stdint.h>

#define DEC NULL

inline void analogWrite(int out_nr, int out_level)
{
	std::cout<<"out #"<<out_nr<<" set to "<<out_level<<std::endl;
}

inline void delay(int time)
{
	std::cout<<time<<" delay called"<<std::endl;
}

class Serial_ {
public:
    static void println(char * str);
    static void println(bool str);
    static void println(uint8_t str, void*v);
    static void print(char * str);
    static void flush();
};

static Serial_ Serial;

#endif //GPIO_H

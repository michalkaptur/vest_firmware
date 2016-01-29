#ifndef UTIL_H
#define UTIL_H
#include <Arduino.h>

class util
{
public:
    util();
    static uint8_t calc_checksum(const char *str, unsigned int strlen);
    static uint8_t digit_to_num(char c);
};

#endif // UTIL_H

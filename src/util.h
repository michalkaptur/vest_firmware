#ifndef UTIL_H
#define UTIL_H
#include <Arduino.h>

class util
{
public:
    util();
    static uint8_t calc_checksum(const char *str, unsigned int strlen);
};

#endif // UTIL_H

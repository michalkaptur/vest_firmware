#ifndef UTIL_H
#define UTIL_H
#include <Arduino.h>

struct numbers_seq
{
    numbers_seq();
    ~numbers_seq();
    uint16_t* numbers;
    uint8_t size;
};

class util
{
public:
    util();
    static uint8_t calc_checksum(const char *str, unsigned int strlen);
    static int8_t digit_to_num(char c);
    static bool parse_numbers(const char* string, numbers_seq &seq);
};


#endif // UTIL_H

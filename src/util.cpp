#include "util.h"

util::util()
{
}

uint8_t util::calc_checksum(const char *str, unsigned int strlen)
{
    unsigned int pos(0);
    unsigned int sum(0);
    while (pos != strlen)
    {
        if (str[pos] != '#'
                and str[pos] != '['
                and str[pos] != ']') {
            sum+=str[pos];
        }
        pos++;
    }
    return sum%100;
}

uint8_t util::digit_to_num(char c)
{
    return c-'0';
}

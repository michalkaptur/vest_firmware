#include "parser.h"

parser::parser()
{
}

bool parser::parse(char *str)
{
    unsigned int len(0);
    while (str[len] != '\0')
    {
        len++;
    }
    if (len < MIN_MSG_LENGTH-1) {
        return false;
    }
    uint8_t chksum = digit_to_num(str[len-1]) + digit_to_num(str[len-2])*10;
    return verify_checksum(str, len-3, chksum);
}

bool parser::verify_checksum(char *str, unsigned int strlen, uint8_t chksum)
{
    unsigned int position(0);
    unsigned int sum(0);
    while (position != strlen)
    {
        if (str[position] != '#') {
            sum+=str[position];
        }
        position++;
    }
    return sum%100 == chksum;
}

uint8_t parser::digit_to_num(char c)
{
    return c-'0';
}

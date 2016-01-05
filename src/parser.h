#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

#define MIN_MSG_LENGTH 6 //eg. C##00\n

class parser
{
public:
    parser();
    bool parse(char* str);
    bool verify_checksum(char* str, unsigned int strlen, uint8_t chksum);
    uint8_t digit_to_num(char c);
};

#endif // PARSER_H

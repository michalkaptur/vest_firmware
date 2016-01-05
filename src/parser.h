#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

#include "message.h"

class parser
{
public:
    parser();
    uint8_t parse(char* str);
    bool verify_checksum(char* str, unsigned int strlen, uint8_t chksum);
    uint8_t digit_to_num(char c);
    bool valid_msg_type(char msg_type);
    message msg;
};

#endif // PARSER_H

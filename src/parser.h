#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

#include "message.h"

class parser
{
public:
    parser();
    uint8_t parse(char* str);
    bool valid_msg_type(char msg_type);
    message msg;
    ~parser();
};

#endif // PARSER_H

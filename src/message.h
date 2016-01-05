#ifndef MESSAGE_H
#define MESSAGE_H

#include "Arduino.h"

#include "receiver.h"

struct message
{
    char type;
    char* data;
    uint8_t checksum;
};

#endif // MESSAGE_H

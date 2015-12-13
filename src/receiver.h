#ifndef RECEIVER_H
#define RECEIVER_H

#include <Arduino.h>

class receiver
{
public:
    receiver();
    void put_byte(const char _byte);
    const char* get_buffer();
private:
    static const uint8_t max_buffer_size = 128;
    char buffer[max_buffer_size];
    uint8_t buffer_ptr;

};

#endif // RECEIVER_H

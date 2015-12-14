#ifndef RECEIVER_H
#define RECEIVER_H

#include <Arduino.h>

#define TRS_BEGIN '/'

class receiver
{
public:
    receiver();
    bool put_byte(const char _byte);
    const char* get_buffer();
    ~receiver();
private:
    void append_buffer(const char _byte);
    void start_transmission();
    static const uint8_t max_buffer_size = 128;
    char *buffer;
    uint8_t buffer_ptr;
    bool trs_ongoing;

};

#endif // RECEIVER_H

#include "receiver.h"
extern "C"
{
#include <string.h>
#include <stdlib.h>
}

receiver::receiver():buffer_ptr(0), trs_ongoing(false), trs_valid(false)
{
    buffer = (char *) malloc(sizeof(char)* max_buffer_size);
}

bool receiver::append_buffer(const char _byte)
{
    if (buffer_ptr < max_buffer_size) {
        buffer[buffer_ptr]=_byte;
        buffer_ptr++;
        buffer[buffer_ptr]='\0';
        return true;
    }
    return false;
}

void receiver::start_transmission()
{
    buffer_ptr = 0;
    append_buffer(TRS_BEGIN);
    trs_ongoing = true;
    trs_valid = false;
}

void receiver::finish_transmission()
{
    trs_valid = true;
    trs_ongoing = false;
    //process buffer
}

bool receiver::put_byte(const char _byte)
{
    if (_byte == TRS_BEGIN) {
        start_transmission();
        return true;
    }

    if (trs_ongoing) {
        if (_byte == TRS_END and buffer_ptr < max_buffer_size) {
            finish_transmission();
        }
        return append_buffer(_byte);
    }
    return false;
}

const char *receiver::get_buffer()
{
    if (buffer_ptr > 0) {
        return buffer;
    }
    return NULL;
}

bool receiver::was_trs_valid()
{
    return trs_valid;
}

receiver::~receiver()
{
    free(buffer);
}

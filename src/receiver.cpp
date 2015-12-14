#include "receiver.h"
extern "C"
{
#include <string.h>
#include <stdlib.h>
}

receiver::receiver():buffer_ptr(0), trs_ongoing(false)
{
    buffer = (char *) malloc(sizeof(char)* max_buffer_size);
}

void receiver::append_buffer(const char _byte)
{
    buffer[buffer_ptr]=_byte;
    buffer_ptr++;
    buffer[buffer_ptr]='\0';
}

void receiver::start_transmission()
{
    buffer_ptr = 0;
    append_buffer(TRS_BEGIN);
    trs_ongoing = true;
}

bool receiver::put_byte(const char _byte)
{
    if (_byte == TRS_BEGIN) {
        start_transmission();
        return true;
    }

    if (trs_ongoing) {
        append_buffer(_byte);
        return true;
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

receiver::~receiver()
{
    free(buffer);
}

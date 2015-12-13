#include "receiver.h"
extern "C"
{
#include <string.h>
}

receiver::receiver():buffer_ptr(0)
{
}

void receiver::put_byte(const char _byte)
{
    buffer[buffer_ptr]=_byte;
    buffer_ptr++;
}

const char *receiver::get_buffer()
{
    char *valid_buffer;
    strncpy(valid_buffer, buffer,buffer_ptr);
    return valid_buffer;
}

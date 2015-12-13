#include "receiver.h"
extern "C"
{
#include <string.h>
#include <stdlib.h>
}

receiver::receiver():buffer_ptr(0)
{
    buffer = (char *) malloc(sizeof(char)* max_buffer_size);
}

void receiver::put_byte(const char _byte)
{
    buffer[buffer_ptr]=_byte;
    buffer_ptr++;
    buffer[buffer_ptr]='\0';
}

const char *receiver::get_buffer()
{
    if (buffer_ptr > 0) {
        return buffer;
    }
    return NULL;
}

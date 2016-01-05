#include "parser.h"

#include <cstring>

parser::parser()
{
}

uint8_t parser::parse(char *str)
{
    unsigned int len(0);
    while (str[len] != '\0')
    {
        len++;
    }
    if (len < MIN_MSG_LENGTH-1) {
        return false;
    }
    uint8_t chksum = digit_to_num(str[len-1]) + digit_to_num(str[len-2])*10;
    if (! verify_checksum(str, len-3, chksum)) {
        return RESULT_ERR_INVALID_CHECKSUM;
    }
    if (! valid_msg_type(str[0])) {
        return RESULT_ERR_INVALID_MSG_TYPE;
    }
    msg.type = str[0];
    return RESULT_OK;
}

bool parser::verify_checksum(char *str, unsigned int strlen, uint8_t chksum)
{
    unsigned int position(0);
    unsigned int sum(0);
    while (position != strlen)
    {
        if (str[position] != '#') {
            sum+=str[position];
        }
        position++;
    }
    return sum%100 == chksum;
}

uint8_t parser::digit_to_num(char c)
{
    return c-'0';
}

bool parser::valid_msg_type(char msg_type)
{
    char valid_msg_types[] = {MSG_TYPE_DATA,
                              MSG_TYPE_CONFIG,
                              MSG_TYPE_STATUS};
    char * found_ptr = strchr(valid_msg_types, msg_type);
    return found_ptr != NULL;
}

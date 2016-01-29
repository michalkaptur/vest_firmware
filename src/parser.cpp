#include "parser.h"
#include "util.h"

extern "C"
{

#include <string.h>
#include <stdlib.h>
}

parser::parser()
{
    msg.data = NULL;
}

uint8_t parser::parse(char *str)
{
    unsigned int len(0);
    do {
        len++;
    }
    while (str[len] != TRS_END);
    len++;
    if (len < MIN_MSG_LENGTH) {
        return RESULT_ERR_MALFORMED_PACKET;
    }
    uint8_t chksum = util::digit_to_num(str[len-2])
            + util::digit_to_num(str[len-3])*10;
    if (util::calc_checksum(str, len-3) != chksum) {
        return RESULT_ERR_INVALID_CHECKSUM;
    }
    if (! valid_msg_type(str[1])) {
        return RESULT_ERR_INVALID_MSG_TYPE;
    }
    msg.type = str[1];
    msg.checksum = chksum;
    if (msg.data != NULL) {
        free(msg.data);
    }
    msg.data_size = len-7;
    msg.data = (char *) calloc(msg.data_size, sizeof(char));
    strncpy(msg.data, str+3, msg.data_size);
    return RESULT_OK;
}

bool parser::valid_msg_type(char msg_type)
{
    char valid_msg_types[] = {MSG_TYPE_DATA,
                              MSG_TYPE_CONFIG,
                              MSG_TYPE_STATUS,
                             '\0'};
    char * found_ptr = strchr(valid_msg_types, msg_type);
    return found_ptr != NULL;
}

parser::~parser()
{
    if (msg.data != NULL) {
        free(msg.data);
    }
}

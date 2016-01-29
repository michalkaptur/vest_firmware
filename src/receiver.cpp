#include "receiver.h"
#include "parser.h"
#include "respond.h"
#include "player.h"

extern "C"
{
#include <string.h>
#include <stdlib.h>
}

receiver::receiver():buffer_ptr(0), trs_ongoing(false), trs_valid(false)
{
    buffer = (char *) calloc(max_buffer_size, sizeof(char));
}

bool receiver::append_buffer(const char _byte)
{
    if (buffer_ptr < max_buffer_size) {
        buffer[buffer_ptr]=_byte;
        buffer_ptr++;
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
    parser _parser;
    uint8_t result(_parser.parse(buffer));
//    respond r(result);
//    r.send();
    Serial.println(result);
    Serial.flush();
    switch(_parser.msg.type) {
        case MSG_TYPE_DATA: {
            player _player(_parser.msg);
            _player.go();
            break;
        }
        default:
            break;
    }
}

void receiver::invalidate_transmission()
{
    trs_valid = false;
    trs_ongoing = false;
    Serial.println(RESULT_ERR_MSG_TOO_SHORT);
    Serial.flush();
//    respond r(RESULT_ERR_MSG_TOO_SHORT);
//    r.send();
}

bool receiver::put_byte(const char _byte)
{
    if (_byte == TRS_BEGIN) {
        start_transmission();
        return true;
    }

    if (trs_ongoing) {
        bool result = append_buffer(_byte);
        if (_byte == TRS_END and buffer_ptr < max_buffer_size) {
            if (buffer_ptr < MIN_MSG_LENGTH) {
                invalidate_transmission();
            } else {
                finish_transmission();
            }
        }
        return result;
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

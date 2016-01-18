#ifndef RECEIVER_H
#define RECEIVER_H

#include <Arduino.h>

\
//TODO: extract it to interface

/*  Packet structure
 *  [type#data#checksum]
 *  types:
 *      D - data
 *      C - config
 *      S - status
 *  eg.:
 *  [D#23.12.45.34.2.0.0.0.2#23] (output sequence)
 *  [C#90.30.10#92] (intensity.on_time.pause_time)
 *  [S#OK#12]
 *  [S#ERR.8#37]    (error code)
 *
 *
 * Error codes:
 * 1 - malformed packet
 * 2 - invalid msg type (D/S/C)
 * 3 - invalid checksum
 * 4 - too short message
 *
 * */

#define TRS_BEGIN '['
#define TRS_END   ']'
#define MSG_TYPE_DATA 'D'
#define MSG_TYPE_CONFIG 'C'
#define MSG_TYPE_STATUS 'S'
#define MIN_MSG_LENGTH 7 //eg. [C##00]
#define RESULT_OK 0
#define RESULT_ERR_MALFORMED_PACKET 1
#define RESULT_ERR_INVALID_MSG_TYPE 2
#define RESULT_ERR_INVALID_CHECKSUM 3
#define RESULT_ERR_MSG_TOO_SHORT    4

class receiver
{
public:
    receiver();
    bool put_byte(const char _byte);
    const char* get_buffer();
    bool was_trs_valid();
    ~receiver();

private:
    bool append_buffer(const char _byte);
    void start_transmission();
    void finish_transmission();
    void invalidate_transmission();
    static const uint8_t max_buffer_size = 128;
    char *buffer;
    uint8_t buffer_ptr;
    bool trs_ongoing;
    bool trs_valid;
};

#endif // RECEIVER_H

#ifndef RECEIVER_H
#define RECEIVER_H

#include <Arduino.h>

/*  Packet structure
 *  /type#data#checksum\
 *  types:
 *      D - data
 *      C - config
 *      S - status
 *  eg.:
 *  /D#23.12.45.34.2.0.0.0.2#23\ (output sequence)
 *  /C#90.30.10#92\ (intensity.on_time.pause_time)
 *  /S#OK#12\
 *  /S#ERR.8#37\    (error code)
 * */

#define TRS_BEGIN '/'
#define TRS_END   '\\'

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
    static const uint8_t max_buffer_size = 128;
    char *buffer;
    uint8_t buffer_ptr;
    bool trs_ongoing;
    bool trs_valid;
};

#endif // RECEIVER_H

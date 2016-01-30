#include "config.h"

config &config::instance()
{
    static config c;
    return c;
}

const uint32_t config::duration() {return _duration;}

const uint32_t config::pause() {return _pause;}

const uint32_t config::intensity() {return _intensity;}

void config::update(uint32_t duration, uint32_t pause, uint32_t intensity)
{
    _duration=duration;
    _pause=pause;
    _intensity=intensity;
}

config::config():_duration(200),_pause(5),_intensity(2000){}


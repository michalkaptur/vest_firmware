#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

class config
{
public:
    static config& instance();
    const uint32_t duration();
    const uint32_t pause();
    const uint32_t intensity();
    void update(uint32_t duration, uint32_t pause, uint32_t intensity);
private:
    config();

    uint32_t _duration;
    uint32_t _pause;
    uint32_t _intensity;
};

#endif // CONFIG_H

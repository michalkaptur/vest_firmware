#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

class config
{
public:
    static config& instance();
    const uint32_t intensity();
    const uint32_t duration();
    const uint32_t pause();
    void update(uint32_t intensity, uint32_t duration, uint32_t pause);
private:
    config();

    uint32_t _intensity;
    uint32_t _duration;
    uint32_t _pause;
};

#endif // CONFIG_H

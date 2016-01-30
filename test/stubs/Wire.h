#ifndef WIRE_H
#define WIRE_H

#include <Arduino.h>

class wire {
public:
    void begin();
    void write(uint16_t);
    void beginTransmission(uint8_t);
    void endTransmission();
    void requestFrom(uint8_t, uint8_t);
    uint16_t read();
};

uint8_t floor(float);
uint16_t min(uint16_t, uint16_t);

static wire Wire;

#endif // WIRE_H


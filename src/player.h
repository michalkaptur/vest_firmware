#ifndef PLAYER_H
#define PLAYER_H
#include <message.h>

class player
{
public:
    player(message msg);
    bool go();

private:
    message _msg;
    player();
    void blink(uint16_t out_nr);
};

#endif // PLAYER_H

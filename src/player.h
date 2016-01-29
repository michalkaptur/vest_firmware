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
    void turn_on(uint8_t out_nr);
};

#endif // PLAYER_H

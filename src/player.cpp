#include "player.h"
#include "Arduino.h"
#include "util.h"

player::player(message msg):_msg(msg){}

void player::turn_on(uint8_t out_nr)
{
    //TODO: use some global config values here
    analogWrite(out_nr, 50);
    delay(20);
    analogWrite(out_nr, 0);
}

bool player::go()
{
   if (_msg.type == MSG_TYPE_DATA) {
       for(uint8_t i = 0; i<_msg.data_size; ++i) {
           turn_on(util::digit_to_num(_msg.data[i]));
       }
       return true;
   }
   return false;
}


player::player()
{

}


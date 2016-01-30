#include "player.h"
#include "Arduino.h"
#include "util.h"
#include "Adafruit_PWMServoDriver.h"

player::player(message msg):_msg(msg){}

void player::blink(uint8_t out_nr)
{
    //TODO: use some global config values here
    Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
    pwm1.begin();
    pwm1.setPWMFreq(1600);
    pwm1.setPWM(out_nr, 2000, 0);
    delay(200);
    pwm1.setPin(out_nr, 0); //turn off
}

bool player::go()
{
   if (_msg.type == MSG_TYPE_DATA) {
       for(uint8_t i = 0; i<_msg.data_size; ++i) {
           blink(util::digit_to_num(_msg.data[i]));
       }
       return true;
   }
   return false;
}


player::player()
{

}


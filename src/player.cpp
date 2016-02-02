#include "player.h"
#include "Arduino.h"
#include "util.h"
#include "Adafruit_PWMServoDriver.h"
#include "config.h"

player::player(message msg):_msg(msg){}

void player::blink(uint16_t out_nr)
{
    Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
    pwm1.begin();
    pwm1.setPWMFreq(1600);
    pwm1.setPWM(out_nr, config::instance().intensity(), 0);
    delay(config::instance().duration());
    pwm1.setPin(out_nr, 0); //turn off
    delay(config::instance().pause());
}

bool player::go()
{
    numbers_seq seq;
    if (_msg.type == MSG_TYPE_DATA and util::parse_numbers(_msg.data, seq)) {
       for(uint8_t i = 0; i<seq.size; ++i) {
           blink(seq.numbers[i]);
       }
       return true;
    }
    return false;
}


player::player()
{

}


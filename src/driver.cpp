#include "driver.h"
#include <Arduino.h>

namespace driver {

void print_time()
{
    Serial.print("time: ");
    Serial.print(on_time, DEC);
    Serial.println(" ms");
}

void print_intensity()
{
    Serial.print("intensity:");
    Serial.println(out_level*100/255, DEC);
}

void config(uint8_t _byte)
{
    switch (_byte) {
    case '+':
        out_level = (out_level+out_config_step <= 255) ? out_level+out_config_step : 255;
        print_intensity();
        break;
    case '-':
        out_level = (out_config_step < out_level) ? out_level-out_config_step : 0;
        print_intensity();
        break;
    case '>':
        on_time += on_time_step;
        print_time();
        break;
    case '<':
        on_time = (on_time_step < on_time) ? on_time-on_time_step : 0;
        print_time();
        break;
    default:
        break;
    }
    flash(on_time);
}

void add_to_sequence(char out_nr)
{
    buffer[buffer_counter] = out_nr-'1';
    buffer_counter++;
}

void run_sequence(){
    for (byte i = 0 ; i < buffer_counter; ++i)
    {
        turn_output_on(output_map[buffer[i]], on_time);
        delay(off_time);
    }
    buffer_counter = 0;
}

void turn_output_on(byte out_nr, int time)
{
    analogWrite(out_nr, out_level);
    delay(time);
    analogWrite(out_nr, 0);
}

void flash(int time){
    analogWrite(LED1, out_level);
    analogWrite(LED2, out_level);
    analogWrite(LED3, out_level);
    analogWrite(LED4, out_level);
    analogWrite(LED5, out_level);
    delay(time);
    analogWrite(LED1, 0);
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
    analogWrite(LED4, 0);
    analogWrite(LED5, 0);
}

} //namespace driver

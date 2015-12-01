#include <Arduino.h>

#define LED1 3
#define LED2 6
#define LED3 9

const char output_map[3] = { LED1, LED2, LED3 };

volatile static short on_time(300);
volatile static short off_time(30);
volatile static byte out_level(130);
const byte out_config_step(30);
const int on_time_step(70);

void config(byte _byte);
void add_to_sequence(char out_nr);
void run_sequence();
void turn_output_on(byte out_nr, int time);
void flash(int time);

char buffer[10];
byte buffer_counter;

void setup(){
    Serial.begin(9600);
    Serial.println("hi");
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    buffer_counter = 0;
}


void loop()
{
    for(;;){
        if (Serial.available())
        {
            byte rx = Serial.read();
            if (rx >= '0' and rx <='2')
                add_to_sequence(rx);
            else if (rx == '#')
                run_sequence();
            else
                config(rx);
        }
    }
}

void config(byte _byte)
{
    switch (_byte) {
    case '+':
        out_level = (out_level+out_config_step <= 255) ? out_level+out_config_step : 255;
        break;
    case '-':
        out_level = (out_config_step < out_level) ? out_level-out_config_step : 0;
    case '>':
        on_time += on_time_step;
        break;
    case '<':
        on_time = (on_time_step < on_time) ? on_time-on_time_step : 0;
        break;
    default:
        break;
    }
    flash(on_time);
}

void add_to_sequence(char out_nr)
{
    buffer[buffer_counter] = out_nr-'0';
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
    delay(time);
    analogWrite(LED1, 0);
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
}

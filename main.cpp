#include <Arduino.h>

#define LED1 3
#define LED2 6
#define LED3 9


#define MAX_SEQUENCE_LENGTH 3
#define NR_OF_SEQUENCES 3
const byte sequences[NR_OF_SEQUENCES][MAX_SEQUENCE_LENGTH+2] = {
    {'a',3,LED1,LED2,LED3},
    {'b',3,LED2,LED1,LED3},
    {'c',2,LED3,LED2,0}
};

volatile static byte out_level(200);
const byte out_config_step(20);

void config(byte _byte);
void run_sequence(byte _byte);
void turn_output_on(byte out_nr, int time);

void setup(){
    Serial.begin(9600);
    Serial.println("hi");
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}


void loop()
{
    for(;;){
        if (Serial.available())
        {
            byte rx = Serial.read();
            if (rx >= 'a' and rx <='c')
                run_sequence(rx);
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
    default:
        break;
    }
    analogWrite(LED1, out_level);
    analogWrite(LED2, out_level);
    analogWrite(LED3, out_level);
    delay(500);
    analogWrite(LED1, 0);
    analogWrite(LED2, 0);
    analogWrite(LED3, 0);
}

void run_sequence(byte _byte){
    byte seq_nr(_byte-'a');
    if (seq_nr < NR_OF_SEQUENCES) {
        for(byte i=0; i<sequences[seq_nr][1];++i)
        {
            Serial.println(sequences[seq_nr][i+2]);
            turn_output_on(sequences[seq_nr][i+2],200);
        }
    }
}

void turn_output_on(byte out_nr, int time)
{
    analogWrite(out_nr, out_level);
    delay(time);
    analogWrite(out_nr, 0);
}

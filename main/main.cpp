#include <Arduino.h>
#include <driver.h>

void setup(){
    Serial.begin(9600);
    Serial.println("hi");
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED5, OUTPUT);
    driver::buffer_counter = 0;
}

void loop()
{
    for(;;){
        if (Serial.available())
        {
            byte rx = Serial.read();
            if (rx >= '1' and rx <='5')
                driver::add_to_sequence(rx);
            else if (rx == '#')
                driver::run_sequence();
            else
                driver::config(rx);
        }
    }
}


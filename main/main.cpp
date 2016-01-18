#include <Arduino.h>
#include <driver.h>
#include <receiver.h>

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
    receiver r;
    for(;;){
        if (Serial.available())
        {
            r.put_byte(Serial.read());
        }
    }
}


#ifndef DRIVER_H
#define DRIVER_H

#include <stdint.h>

#define LED1 3
#define LED2 6
#define LED3 9
#define LED4 5
#define LED5 10

namespace driver {

const char output_map[5] = { LED1, LED2, LED3, LED4, LED5 };

volatile static short on_time(300);
volatile static short off_time(30);
volatile static uint8_t out_level(130);
const uint8_t out_config_step(30);
const int on_time_step(70);

void config(uint8_t _byte);
void add_to_sequence(char out_nr);
void run_sequence();
void turn_output_on(uint8_t out_nr, int time);
void flash(int time);

static char buffer[20];
static uint8_t buffer_counter;

}//namespace driver
#endif // DRIVER_H

#ifndef WS2812_H
#define WS2812_H

#include "stm32f4xx.h"
#include "gpio.h"
#include "rcc.h"

#define numLEDs 60
#define bufferSize numLEDs * 24

extern uint32_t leds[numLEDs];
extern uint16_t buffer[bufferSize];

uint32_t hsvtorgb(uint8_t h, uint8_t s, uint8_t v);
void updateBuffer(void);
void WS2812Init(void);
void sendBuffer(void);
#endif
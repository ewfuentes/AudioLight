#include "stm32f4xx.h"
#include "gpio.h"
#include "rcc.h"
#include "WS2812.h"

#define ARM_MATH_CM4
#include "arm_math.h"



int32_t count = 0;
uint32_t offset = 0;
int8_t dir = 1;
void SysTick_Handler(void){
  gpioTogglePin(GPIOD,12);
  sendBuffer();

  count += dir;
  uint32_t i = 0;
  for (i = 0; i < numLEDs; i ++){
    leds[i] = hsvtorgb((2 * i + offset + count)%255,255,25);
    // leds[i] = hsvtorgb((offset + count)%255,255,25);
  }

  updateBuffer();

}
  




int main(void) {
  WS2812Init();
  
  if (SysTick_Config(SystemCoreClock/100) != 0){
    while(1);
  }

  while(1){
    asm("nop");
  }



  return 0;
}
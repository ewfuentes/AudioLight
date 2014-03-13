#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx.h"

#define MODE_INPUT 	0
#define MODE_GPIO 	1
#define MODE_ALT	2
#define MODE_ANALOG	3

#define gpioMode(PORT,PIN,MODE) {PORT->MODER &= ~(3<<(2*PIN)); \
								PORT->MODER |= MODE<<(2*PIN);}
								
#define MODE_PP		0
#define MODE_OD		1				

#define gpioOutType(PORT,PIN,MODE) {PORT->OTYPER &= ~(1<<(PIN)); \
									PORT->OTYPER |= MODE<<PIN;}

#define gpioSetPin(PORT,PIN) (PORT->ODR |= 1<<PIN)
#define gpioClearPin(PORT,PIN) (PORT->ODR &= ~(1<<PIN))
#define gpioTogglePin(PORT,PIN) (PORT->ODR ^= 1<<PIN)

#define AF_SYS 		0
#define AF_TIM1 	1
#define AF_TIM2 	1
#define AF_TIM3 	2
#define AF_TIM4 	2
#define AF_TIM5 	2
#define AF_TIM8 	3
#define AF_TIM9 	3
#define AF_TIM10 	3
#define AF_TIM11 	3
#define AF_I2C1 	4
#define AF_I2C2 	4
#define AF_I2C3 	4
#define AF_SPI1		5
#define AF_SPI2		5
#define AF_SPI3		6
#define AF_USART1	7
#define AF_USART2	7
#define AF_USART3	7
#define AF_UART4	8
#define AF_UART5	8
#define AF_USART6	8
#define AF_CAN1		9
#define AF_CAN2		9
#define AF_TIM12 	9
#define AF_TIM13 	9
#define AF_TIM14 	9
#define AF_OTGFS	10
#define AF_OTGHS	10
#define AF_ETH		11
#define gpioAlternate(PORT,PIN,MODE) {PORT->AFR[PIN/8] &= \
										~0x0F<<(PIN*4 - 32*(PIN/8)); \
									PORT->AFR[PIN/8] |= \
										MODE<<(PIN*4 - 32*(PIN/8));}

#endif
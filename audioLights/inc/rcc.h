#ifndef RCC_H
#define RCC_H

#define rccResetAHB1(x) {RCC->AHB1RSTR |= 1<<x; \
							RCC->AHB1RSTR = 0;}

#define rccResetGPIOA() rccResetAHB1(RCC_AHB1RSTR_GPIOARST)
#define rccResetGPIOB() rccResetAHB1(RCC_AHB1RSTR_GPIOBRST)
#define rccResetGPIOC() rccResetAHB1(RCC_AHB1RSTR_GPIOCRST)
#define rccResetGPIOD() rccResetAHB1(RCC_AHB1RSTR_GPIODRST)
#define rccResetGPIOE() rccResetAHB1(RCC_AHB1RSTR_GPIOERST)
#define rccResetGPIOF() rccResetAHB1(RCC_AHB1RSTR_GPIOFRST)
#define rccResetGPIOG() rccResetAHB1(RCC_AHB1RSTR_GPIOGRST)
#define rccResetGPIOH() rccResetAHB1(RCC_AHB1RSTR_GPIOHRST)
#define rccResetGPIOI() rccResetAHB1(RCC_AHB1RSTR_GPIOIRST)
#define rccResetCRC() 	rccResetAHB1(RCC_AHB1RSTR_CRCRST)
#define rccResetDMA1() 	rccResetAHB1(RCC_AHB1RSTR_DMA1RST)
#define rccResetDMA2() 	rccResetAHB1(RCC_AHB1RSTR_DMA2RST)
#define rccResetETH() 	rccResetAHB1(RCC_AHB1RSTR_ETHRST)
#define rccResetOTGHS() rccResetAHB1(RCC_AHB1RSTR_OTGHSRST)

#define rccResetAHB2(x) {RCC->AHB2RSTR |= x; \
							RCC->AHB2RSTR = 0;}

#define rccResetOTGFS() rccResetAHB2(RCC_AHB2RSTR_OTGFSRST)
#define rccResetRNG() rccResetAHB2(RCC_AHB2RSTR_RNGRST)
#define rccResetHASH() rccResetAHB2(RCC_AHB2RSTR_HASHRST)
#define rccResetCRYP() rccResetAHB2(RCC_AHB2RSTR_CRYPRST)
#define rccResetDCMI() rccResetAHB2(RCC_AHB2RSTR_DCMIRST)

#define rccResetAHB3(x) {RCC->AHB3RSTR |= x; \
							RCC->AHB3RSTR = 0;}

#define rccResetFSMC() rccResetAHB3(RCC_AHB3RSTR_FSMCRST)

#define rccResetAPB1(x) {RCC->APB1RSTR |= x; \
							RCC->APB1RSTR = 0;}

#define rccResetDAC() rccResetAPB1(RCC_APB1RSTR_DACRST)
#define rccResetPWR() rccResetAPB1(RCC_APB1RSTR_PWRRST)
#define rccResetCAN2() rccResetAPB1(RCC_APB1RSTR_CAN2RST)
#define rccResetCAN1() rccResetAPB1(RCC_APB1RSTR_CAN1RST)
#define rccResetI2C3() rccResetAPB1(RCC_APB1RSTR_I2C3RST)
#define rccResetI2C2() rccResetAPB1(RCC_APB1RSTR_I2C2RST)
#define rccResetI2C1() rccResetAPB1(RCC_APB1RSTR_I2C1RST)
#define rccResetUART5() rccResetAPB1(RCC_APB1RSTR_UART5RST)
#define rccResetUART4() rccResetAPB1(RCC_APB1RSTR_UART4RST)
#define rccResetUART3() rccResetAPB1(RCC_APB1RSTR_UART3RST)
#define rccResetUART2() rccResetAPB1(RCC_APB1RSTR_UART2RST)
#define rccResetSPI3() rccResetAPB1(RCC_APB1RSTR_SPI3RST)
#define rccResetSPI2() rccResetAPB1(RCC_APB1RSTR_SPI2RST)
#define rccResetWWDG() rccResetAPB1(RCC_APB1RSTR_WWDGRST)
#define rccResetTIM14() rccResetAPB1(RCC_APB1RSTR_TIM14RST)
#define rccResetTIM13() rccResetAPB1(RCC_APB1RSTR_TIM13RST)
#define rccResetTIM12() rccResetAPB1(RCC_APB1RSTR_TIM12RST)
#define rccResetTIM7() rccResetAPB1(RCC_APB1RSTR_TIM7RST)
#define rccResetTIM6() rccResetAPB1(RCC_APB1RSTR_TIM6RST)
#define rccResetTIM5() rccResetAPB1(RCC_APB1RSTR_TIM5RST)
#define rccResetTIM4() rccResetAPB1(RCC_APB1RSTR_TIM4RST)
#define rccResetTIM3() rccResetAPB1(RCC_APB1RSTR_TIM3RST)
#define rccResetTIM2() rccResetAPB1(RCC_APB1RSTR_TIM2RST)

#define rccResetAPB2(x) {RCC->APB2RSTR |= x; \
							RCC->APB2RSTR = 0;}

#define rccResetTIM11() rccResetAPB2(RCC_APB2RSTR_TIM11RST)
#define rccResetTIM10() rccResetAPB2(RCC_APB2RSTR_TIM10RST)
#define rccResetTIM9() rccResetAPB2(RCC_APB2RSTR_TIM9RST)
#define rccResetSYSCFG() rccResetAPB2(RCC_APB2RSTR_SYSCFGRST)
#define rccResetSPI1() rccResetAPB2(RCC_APB2RSTR_SPI1RST)
#define rccResetSDIO() rccResetAPB2(RCC_APB2RSTR_SDIORST)
#define rccResetADC() rccResetAPB2(RCC_APB2RSTR_ADCRST)
#define rccResetUSART6() rccResetAPB2(RCC_APB2RSTR_USART6RST)
#define rccResetUSART1() rccResetAPB2(RCC_APB2RSTR_USART1RST)
#define rccResetTIM8() rccResetAPB2(RCC_APB2RSTR_TIM8RST)
#define rccResetTIM1() rccResetAPB2(RCC_APB2RSTR_TIM1RST)

#define rccEnableAHB1(x) {RCC->AHB1ENR |= x;}
#define rccDisableAHB1(x) {RCC->AHB1ENR |= ~x;}

#define rccEnableGPIOA() rccEnableAHB1(RCC_AHB1ENR_GPIOAEN)
#define rccEnableGPIOB() rccEnableAHB1(RCC_AHB1ENR_GPIOBEN)
#define rccEnableGPIOC() rccEnableAHB1(RCC_AHB1ENR_GPIOCEN)
#define rccEnableGPIOD() rccEnableAHB1(RCC_AHB1ENR_GPIODEN)
#define rccEnableGPIOE() rccEnableAHB1(RCC_AHB1ENR_GPIOEEN)
#define rccEnableGPIOF() rccEnableAHB1(RCC_AHB1ENR_GPIOFEN)
#define rccEnableGPIOG() rccEnableAHB1(RCC_AHB1ENR_GPIOGEN)
#define rccEnableGPIOH() rccEnableAHB1(RCC_AHB1ENR_GPIOHEN)
#define rccEnableGPIOI() rccEnableAHB1(RCC_AHB1ENR_GPIOIEN)
#define rccEnableCRC() 	rccEnableAHB1(RCC_AHB1ENR_CRCEN)
#define rccEnableDMA1() rccEnableAHB1(RCC_AHB1ENR_DMA1EN)
#define rccEnableDMA2() rccEnableAHB1(RCC_AHB1ENR_DMA2EN)
#define rccEnableETH() rccEnableAHB1(RCC_AHB1ENR_ETHEN)
#define rccEnableOTGHS() rccEnableAHB1(RCC_AHB1ENR_OTGHSEN)

#define rccDisableGPIOA() rccDisableAHB1(RCC_AHB1ENR_GPIOAEN)
#define rccDisableGPIOB() rccDisableAHB1(RCC_AHB1ENR_GPIOBEN)
#define rccDisableGPIOC() rccDisableAHB1(RCC_AHB1ENR_GPIOCEN)
#define rccDisableGPIOD() rccDisableAHB1(RCC_AHB1ENR_GPIODEN)
#define rccDisableGPIOE() rccDisableAHB1(RCC_AHB1ENR_GPIOEEN)
#define rccDisableGPIOF() rccDisableAHB1(RCC_AHB1ENR_GPIOFEN)
#define rccDisableGPIOG() rccDisableAHB1(RCC_AHB1ENR_GPIOGEN)
#define rccDisableGPIOH() rccDisableAHB1(RCC_AHB1ENR_GPIOHEN)
#define rccDisableGPIOI() rccDisableAHB1(RCC_AHB1ENR_GPIOIEN)
#define rccDisableCRC() rccDisableAHB1(RCC_AHB1ENR_CRCEN)
#define rccDisableDMA1() rccDisableAHB1(RCC_AHB1ENR_DMA1EN)
#define rccDisableDMA2() rccDisableAHB1(RCC_AHB1ENR_DMA2EN)
#define rccDisableETH() rccDisableAHB1(RCC_AHB1ENR_ETHEN)
#define rccDisableOTGHS() rccDisableAHB1(RCC_AHB1ENR_OTGHSEN)							

#define rccEnableAHB2(x) {RCC->AHB2ENR |= x;}
#define rccDisableAHB2(x) {RCC->AHB2ENR &= a~x;}

#define rccEnableOTGFS() rccEnableAHB2(RCC_AHB2ENR_OTGFSEN)
#define rccEnableRNG() rccEnableAHB2(RCC_AHB2ENR_RNGEN)
#define rccEnableHASH() rccEnableAHB2(RCC_AHB2ENR_HASHEN)
#define rccEnableCRYP() rccEnableAHB2(RCC_AHB2ENR_CRYPEN)
#define rccEnableDCMI() rccEnableAHB2(RCC_AHB2ENR_DCMIEN)

#define rccDisableOTGFS() rccDisableAHB2(RCC_AHB2ENR_OTGFSEN)
#define rccDisableRNG() rccDisableAHB2(RCC_AHB2ENR_RNGEN)
#define rccDisableHASH() rccDisableAHB2(RCC_AHB2ENR_HASHEN)
#define rccDisableCRYP() rccDisableAHB2(RCC_AHB2ENR_CRYPEN)
#define rccDisableDCMI() rccDisableAHB2(RCC_AHB2ENR_DCMIEN)

#define rccEnableAHB3(x) {RCC->AHB3ENR |= x;}
#define rccDisableAHB3(x) {RCC->AHB3ENR &= ~x;}

#define rccEnableFSMC() rccEnableAHB3(RCC_AHB3ENR_FSMCEN)

#define rccDisableFSMC() rccDisableAHB3(RCC_AHB3ENR_FSMCEN)

#define rccEnableAPB1(x) {RCC->APB1ENR |= x;}
#define rccDisableAPB1(x) {RCC->APB1ENR &= ~x;}

#define rccEnableDAC() rccEnableAPB1(RCC_APB1ENR_DACEN)
#define rccEnablePWR() rccEnableAPB1(RCC_APB1ENR_PWREN)
#define rccEnableCAN2() rccEnableAPB1(RCC_APB1ENR_CAN2EN)
#define rccEnableCAN1() rccEnableAPB1(RCC_APB1ENR_CAN1EN)
#define rccEnableI2C3() rccEnableAPB1(RCC_APB1ENR_I2C3EN)
#define rccEnableI2C2() rccEnableAPB1(RCC_APB1ENR_I2C2EN)
#define rccEnableI2C1() rccEnableAPB1(RCC_APB1ENR_I2C1EN)
#define rccEnableUART5() rccEnableAPB1(RCC_APB1ENR_UART5EN)
#define rccEnableUART4() rccEnableAPB1(RCC_APB1ENR_UART4EN)
#define rccEnableUART3() rccEnableAPB1(RCC_APB1ENR_UART3EN)
#define rccEnableUART2() rccEnableAPB1(RCC_APB1ENR_UART2EN)
#define rccEnableSPI3() rccEnableAPB1(RCC_APB1ENR_SPI3EN)
#define rccEnableSPI2() rccEnableAPB1(RCC_APB1ENR_SPI2EN)
#define rccEnableWWDG() rccEnableAPB1(RCC_APB1ENR_WWDGEN)
#define rccEnableTIM14() rccEnableAPB1(RCC_APB1ENR_TIM14EN)
#define rccEnableTIM13() rccEnableAPB1(RCC_APB1ENR_TIM13EN)
#define rccEnableTIM12() rccEnableAPB1(RCC_APB1ENR_TIM12EN)
#define rccEnableTIM7() rccEnableAPB1(RCC_APB1ENR_TIM7EN)
#define rccEnableTIM6() rccEnableAPB1(RCC_APB1ENR_TIM6EN)
#define rccEnableTIM5() rccEnableAPB1(RCC_APB1ENR_TIM5EN)
#define rccEnableTIM4() rccEnableAPB1(RCC_APB1ENR_TIM4EN)
#define rccEnableTIM3() rccEnableAPB1(RCC_APB1ENR_TIM3EN)
#define rccEnableTIM2() rccEnableAPB1(RCC_APB1ENR_TIM2EN)

#define rccDisableDAC() rccDisableAPB1(RCC_APB1ENR_DACEN)
#define rccDisablePWR() rccDisableAPB1(RCC_APB1ENR_PWREN)
#define rccDisableCAN2() rccDisableAPB1(RCC_APB1ENR_CAN2EN)
#define rccDisableCAN1() rccDisableAPB1(RCC_APB1ENR_CAN1EN)
#define rccDisableI2C3() rccDisableAPB1(RCC_APB1ENR_I2C3EN)
#define rccDisableI2C2() rccDisableAPB1(RCC_APB1ENR_I2C2EN)
#define rccDisableI2C1() rccDisableAPB1(RCC_APB1ENR_I2C1EN)
#define rccDisableUART5() rccDisableAPB1(RCC_APB1ENR_UART5EN)
#define rccDisableUART4() rccDisableAPB1(RCC_APB1ENR_UART4EN)
#define rccDisableUART3() rccDisableAPB1(RCC_APB1ENR_UART3EN)
#define rccDisableUART2() rccDisableAPB1(RCC_APB1ENR_UART2EN)
#define rccDisableSPI3() rccDisableAPB1(RCC_APB1ENR_SPI3EN)
#define rccDisableSPI2() rccDisableAPB1(RCC_APB1ENR_SPI2EN)
#define rccDisableWWDG() rccDisableAPB1(RCC_APB1ENR_WWDGEN)
#define rccDisableTIM14() rccDisableAPB1(RCC_APB1ENR_TIM14EN)
#define rccDisableTIM13() rccDisableAPB1(RCC_APB1ENR_TIM13EN)
#define rccDisableTIM12() rccDisableAPB1(RCC_APB1ENR_TIM12EN)
#define rccDisableTIM7() rccDisableAPB1(RCC_APB1ENR_TIM7EN)
#define rccDisableTIM6() rccDisableAPB1(RCC_APB1ENR_TIM6EN)
#define rccDisableTIM5() rccDisableAPB1(RCC_APB1ENR_TIM5EN)
#define rccDisableTIM4() rccDisableAPB1(RCC_APB1ENR_TIM4EN)
#define rccDisableTIM3() rccDisableAPB1(RCC_APB1ENR_TIM3EN)
#define rccDisableTIM2() rccDisableAPB1(RCC_APB1ENR_TIM2EN)

#define rccEnableAPB2(x) {RCC->APB2ENR |= x;}
#define rccDisableAPB2(x) {RCC->APB2ENR &= ~x;}

#define rccEnableTIM11() rccEnableAPB2(RCC_APB2ENR_TIM11EN)
#define rccEnableTIM10() rccEnableAPB2(RCC_APB2ENR_TIM10EN)
#define rccEnableTIM9() rccEnableAPB2(RCC_APB2ENR_TIM9EN)
#define rccEnableSYSCFG() rccEnableAPB2(RCC_APB2ENR_SYSCFGEN)
#define rccEnableSPI1() rccEnableAPB2(RCC_APB2ENR_SPI1EN)
#define rccEnableSDIO() rccEnableAPB2(RCC_APB2ENR_SDIOEN)
#define rccEnableADC() rccEnableAPB2(RCC_APB2ENR_ADCEN)
#define rccEnableUSART6() rccEnableAPB2(RCC_APB2ENR_USART6EN)
#define rccEnableUSART1() rccEnableAPB2(RCC_APB2ENR_USART1EN)
#define rccEnableTIM8() rccEnableAPB2(RCC_APB2ENR_TIM8EN)
#define rccEnableTIM1() rccEnableAPB2(RCC_APB2ENR_TIM1EN)

#define rccDisableTIM11() rccDisableAPB2(RCC_APB2ENR_TIM11EN)
#define rccDisableTIM10() rccDisableAPB2(RCC_APB2ENR_TIM10EN)
#define rccDisableTIM9() rccDisableAPB2(RCC_APB2ENR_TIM9EN)
#define rccDisableSYSCFG() rccDisableAPB2(RCC_APB2ENR_SYSCFGEN)
#define rccDisableSPI1() rccDisableAPB2(RCC_APB2ENR_SPI1EN)
#define rccDisableSDIO() rccDisableAPB2(RCC_APB2ENR_SDIOEN)
#define rccDisableADC() rccDisableAPB2(RCC_APB2ENR_ADCEN)
#define rccDisableUSART6() rccDisableAPB2(RCC_APB2ENR_USART6EN)
#define rccDisableUSART1() rccDisableAPB2(RCC_APB2ENR_USART1EN)
#define rccDisableTIM8() rccDisableAPB2(RCC_APB2ENR_TIM8EN)
#define rccDisableTIM1() rccDisableAPB2(RCC_APB2ENR_TIM1EN)

#endif
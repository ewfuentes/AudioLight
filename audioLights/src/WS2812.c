#include "WS2812.h"

uint32_t leds[numLEDs];
uint16_t buffer[bufferSize];

void DMA2_Stream1_IRQHandler(void){
  gpioSetPin(GPIOC,7);
  //Clear current interrupt 
  DMA2->LIFCR |= DMA_LIFCR_CTCIF1;
  //Clear Update Flag
  while(TIM8->CNT < TIM8->CCR1);
  TIM8->CR1 &= ~(TIM_CR1_CEN);
  gpioClearPin(GPIOC,7);
}

uint32_t hsvtorgb(uint8_t h, uint8_t s, uint8_t v){
    uint8_t region, fpart, p, q, t;
    
    if(s == 0) {
        /* color is grayscale */
        return v<<16 | v<<8 | v;
    }
    
    /* make hue 0-5 */
    region = h / 43;
    /* find remainder part, make it from 0-255 */
    fpart = (h - (region * 43)) * 6;
    
    /* calculate temp vars, doing integer multiplication */
    p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * fpart) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - fpart)) >> 8))) >> 8;
        
    /* assign temp vars based on color cone region */
    switch(region) {
        case 0:
            return v<<8 | t<<16 | p;
        case 1:
            return q<<8 | v<<16 | p;
        case 2:
            return p<<8 | v<<16 | t;
        case 3:
            return p<<8 | q<<16 | v;
        case 4:
            return t<<8 | p<<16 | v;
        default:
            return v<<8 | p<<16 | q;
    }
}


void sendBuffer(void){
  gpioMode(GPIOC, 6, MODE_ALT);
  gpioAlternate(GPIOC, 6, AF_TIM8);

  rccEnableTIM8();
  TIM8->PSC = 0;
  TIM8->ARR = 209;
  TIM8->CCR1 = 0;

  // DBGMCU->APB2FZ |= DBGMCU_APB1_FZ_DBG_TIM8_STOP;

  //Enable preload register by setting OC1PE in TIM8_CCMRx
  // TIM8->CCMR1 |= TIM_CCMR1_OC1PE;
  //enable auto-reload preload by setting arpe bit
  TIM8->CR1 |= TIM_CR1_ARPE;
  
  TIM8->BDTR |= TIM_BDTR_MOE;
  
  TIM8->CCER |= TIM_CCER_CC1E;

  //Setup TIM8 interrupt in NVIC
  NVIC_SetPriority(TIM8_CC_IRQn,10);
  NVIC_EnableIRQ(TIM8_CC_IRQn);

  //Enable DMA requests on update events
  TIM8->DIER |= TIM_DIER_UDE;

  //DMA 2 has a stream that gets triggered on TIM8 update events*
  //That stream is stream 1 channel 7
  rccEnableDMA2();

  //Disable stream by clearing EN bit in DMA_SxCR
  DMA2_Stream1->CR &= ~DMA_SxCR_EN;
  //Wait until bit is cleared
  while(DMA2_Stream1->CR & DMA_SxCR_EN);
  //set peripheral port register address in DMA_SxPAR
  DMA2_Stream1->PAR = (uint32_t)(&(TIM8->CCR1));
  //set the memory adress in DMA_SxMA0R
  DMA2_Stream1->M0AR = (uint32_t)&buffer;
  //configure number of transfers in DMA_SxNDTR
  DMA2_Stream1->NDTR = bufferSize;
  //select the dma channel request ushing CHSEL[2:0] in DMA_SxCR
  DMA2_Stream1->CR = 0;
  DMA2_Stream1->CR |= 7<<25;
  //Configure FIFO usage
  DMA2_Stream1->FCR = 0;
  // DMA2_Stream1->FCR |= DMA_SxFCR_DMDIS;
  //configure data transfer direction
  //Memory to Peripheral Mode
  DMA2_Stream1->CR |= 1<<6;
  //configure peripheral/memory incremented/fixed mode
  //Increment Memory Pointer
  DMA2_Stream1->CR |= DMA_SxCR_MINC;
  //single or burst transactions 
  //Single transfers
  //peripheral and memory data widths
  //Set Memory Size to 16 bits
  DMA2_Stream1->CR |= 1<<13;
  //Set Peripheral Size to 16 Bits
  DMA2_Stream1->CR |= 1<<11;
  //circular mode double buffer mode
  //interrupts after half/full
  //Interrupt after full
  DMA2_Stream1->CR |= DMA_SxCR_TCIE;
  //Clear transfer complete flag
  DMA2->LIFCR |= DMA_LIFCR_CTCIF1;
  //and/or errors in the DMA_SxCR


  //configure interrupt in NVIC
  NVIC_SetPriority(DMA2_Stream1_IRQn,10);
  NVIC_EnableIRQ(DMA2_Stream1_IRQn);

  //set enable flag
  DMA2_Stream1->CR |= DMA_SxCR_EN;

  TIM8->DCR = 13;

  //as preload registers are transferred to the shadow registers only when
  //an update event occers, before starting the counter you have to initialize
  //all registers by setting the ug bit in TIM8_EGR register
  // TIM8->EGR |= TIM_EGR_UG;

  //Set PWM Mode
  TIM8->CCMR1 |= 0b110 << 4;

  // gpioSetPin(GPIOC,7);
  //start the timer
  TIM8->CR1 |= TIM_CR1_CEN;
  // gpioClearPin(GPIOC,7);

}

void updateBuffer(){
  uint32_t i = 0;
  int32_t j = 0;
  for (i = 0; i < numLEDs; i++){
    for (j = 23; j >= 0; j--){
      if (leds[i] & (1<<j))
        buffer[24*i + (23 - j)] = 125;
      else
        buffer[24*i + (23 - j)] = 59;
    }
  }
}

void WS2812Init(void){
  rccEnableGPIOD();
  gpioMode(GPIOD,12,MODE_GPIO);
  gpioOutType(GPIOD,12,MODE_PP);

  rccEnableGPIOC();

  gpioMode(GPIOC, 7, MODE_GPIO);
  gpioOutType(GPIOC,7,MODE_PP);
}
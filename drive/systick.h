#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "nrf51.h"

void Systick_Init(void);
void Delay_ms(__IO uint32_t nTime);
void TimingDelay_Decrement(void);

#endif /* __SYSTICK_H */

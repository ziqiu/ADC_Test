#ifndef __KEY_H
#define	__KEY_H

#include "nrf51.h"
#include "nrf_gpio.h"
#define KEY_1  16
#define KEY_2  17 
 
void KEY_Init(void);
uint8_t KEY1_Down(void);

#endif /* __KEY_H */


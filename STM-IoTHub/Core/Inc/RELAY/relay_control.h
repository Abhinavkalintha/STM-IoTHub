#ifndef __RELAY_CONTROL_H
#define __RELAY_CONTROL_H

#include "stm32f4xx_hal.h"

void Relay_Init(void);
void Relay_On(uint16_t pin);
void Relay_Off(uint16_t pin);

#endif

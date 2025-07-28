#ifndef __STATUS_LED_H
#define __STATUS_LED_H

#include "stm32f4xx_hal.h"

typedef enum {
    LED_ALIVE,
    LED_WIFI,
    LED_ERROR
} StatusLED_Type;

typedef enum {
    LED_OFF = 0,
    LED_ON = 1
} LED_State;

void StatusLED_Init(void);
void StatusLED_Set(StatusLED_Type led, LED_State state);
void StatusLED_Toggle(StatusLED_Type led);

#endif // __STATUS_LED_H

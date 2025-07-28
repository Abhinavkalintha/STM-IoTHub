#ifndef __FAN_AUTOMATION_H__
#define __FAN_AUTOMATION_H__

#include "main.h"

void FanAutomationTask(void *argument);
extern uint8_t blynkFanCommand; // from blynk task

#endif

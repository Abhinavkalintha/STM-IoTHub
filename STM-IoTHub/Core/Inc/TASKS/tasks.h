#ifndef __TASKS_H__
#define __TASKS_H__

#include "cmsis_os.h"

// Existing task prototypes
void SensorTask(void *argument);
void FanTask(void *argument);
void LightTask(void *argument);

// ✅ Add this line
void WiFiTask(void *argument);

#endif // __TASKS_H__

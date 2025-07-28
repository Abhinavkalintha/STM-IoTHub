#ifndef __SENSOR_TASK_H__
#define __SENSOR_TASK_H__

#include "cmsis_os2.h"  // For CMSIS-RTOS API
#include "main.h"       // HAL & board defs

extern float g_temperature;
extern float g_humidity;

void StartSensorTask(void *argument);  // Task function

#endif // __SENSOR_TASK_H__


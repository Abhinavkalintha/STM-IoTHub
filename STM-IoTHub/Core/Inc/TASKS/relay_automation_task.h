#ifndef INC_TASKS_RELAY_AUTOMATION_TASK_H_
#define INC_TASKS_RELAY_AUTOMATION_TASK_H_

#include "main.h"

// Relay GPIO Pins (Defined as per your setup)
#define FAN_RELAY_GPIO_Port    GPIOB
#define FAN_RELAY_Pin          GPIO_PIN_0

#define LIGHT_RELAY_GPIO_Port  GPIOB
#define LIGHT_RELAY_Pin        GPIO_PIN_1

// Automation thresholds
#define TEMP_THRESHOLD             30.0f   // °C
#define HUMIDITY_THRESHOLD         30.0f   // %
#define IAQ_THRESHOLD              100.0f  // Air quality index
#define VOLTAGE_LOW_THRESHOLD      200.0f  // V
#define POWER_MAX_THRESHOLD        500.0f  // W
#define CURRENT_THRESHOLD          0.5f    // A

// Public function to create the task
void RelayAutomationTask_Init(void);

#endif /* INC_TASKS_RELAY_AUTOMATION_TASK_H_ */

#include "main.h"
#include "cmsis_os.h"
#include "fan_task.h"
#include "bme680_app.h"
#include <stdbool.h>
#include "shared_data.h"
//#include "blynk_app.h"

// Define the fan GPIO pin
#define FAN_GPIO_Port GPIOB
#define FAN_Pin GPIO_PIN_0  // Update if your fan relay is connected to another pin

extern float temperature;
extern bool fault_current_detected;
//extern uint8_t blynkFanState;
int blynkFanState = 0;
void FanAutomationTask(void *argument)
{
  for(;;)
  {
    // Priority 1: Fault → turn OFF fan
    if (g_energyAlert)
    {
      HAL_GPIO_WritePin(FAN_GPIO_Port, FAN_Pin, GPIO_PIN_RESET); // Turn OFF fan
    }
    // Priority 2: User control via Blynk
    else if (blynkFanState == 1)
    {
      HAL_GPIO_WritePin(FAN_GPIO_Port, FAN_Pin, GPIO_PIN_SET); // Turn ON fan
    }
    else if (blynkFanState == 0)
    {
      HAL_GPIO_WritePin(FAN_GPIO_Port, FAN_Pin, GPIO_PIN_RESET); // Turn OFF fan
    }
    // Priority 3: Auto temp-based control (only if blynkFanState is AUTO)
    else
    {
     if (g_temperature > 30.0f) 
        HAL_GPIO_WritePin(FAN_GPIO_Port, FAN_Pin, GPIO_PIN_SET);  // ON
      else if (g_temperature < 28.0f)
        HAL_GPIO_WritePin(FAN_GPIO_Port, FAN_Pin, GPIO_PIN_RESET); // OFF
    }

    osDelay(1000); // Check every 1 second
  }
}
//

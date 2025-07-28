#include "relay_automation_task.h"
#include "shared_data.h"
#include "main.h"
#include "cmsis_os.h"
  // Make sure this exists
extern shared_data_t shared_data;

void RelayAutomationTask(void *argument)
{
    for (;;)
    {
        // 🌀 Automation 1: Turn ON Fan if Temp > 30°C
        if (shared_data.bme680.temperature > 30.0f)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);  // ON Fan
        }

        // 🌀 Automation 2: Turn OFF Fan if Temp < 25°C
        if (shared_data.bme680.temperature < 25.0f)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);  // OFF Fan
        }

        // 💨 Automation 3: Turn ON Fan if Humidity > 70%
        if (shared_data.bme680.humidity > 70.0f)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);  // ON Fan
        }

        // 💧 Automation 4: Turn OFF Fan if Humidity < 50%
        if (shared_data.bme680.humidity < 50.0f)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);  // OFF Fan
        }

        // ⚡ Automation 5: Turn OFF Fan if Voltage < 200V
        if (shared_data.pzem.voltage < 200.0f)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);  // OFF Fan
        }

        // 💡 Automation 6: Turn ON Light if Humidity < 30% (too dry)
        if (shared_data.bme680.humidity < 30.0f)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);  // ON Light
        }

        // 🌫️ Automation 7: Turn ON Fan if IAQ > 100 AND Temp > 30°C
        if ((shared_data.bme680.air_quality > 100.0f) && (shared_data.bme680.temperature > 30.0f))

        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);  // ON Fan
        }

        // 🔌 Automation 8: Auto shutdown all relays if Power > 500W
        if (shared_data.pzem.power > 500.0f)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);  // OFF Fan
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);  // OFF Light
        }

        // ⚙️ Automation 9: Turn ON Fan if Current > 0.5A
        if (shared_data.pzem.current > 0.5f)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);  // ON Fan
        }

        osDelay(1000);  // Run every 1 second
    }
}


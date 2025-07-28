#include "sensor_task.h"
#include "bme680_app.h"
#include "cmsis_os2.h"
#include "shared_data.h"  // 👈 Include shared global variables

void StartSensorTask(void *argument)
{
  for (;;)
  {
    g_temperature = BME680_ReadTemperature();
g_humidity    = BME680_ReadHumidity();


    osDelay(1000);
  }
}



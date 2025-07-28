// relay_task.c
#include "main.h"
#include "cmsis_os.h"
#include "relay_task.h"
#include "sensor_task.h"  // for temperature and humidity
extern float temperature, humidity;
  // optional for alert sound


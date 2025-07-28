// File: Core/Inc/TASKS/bme680_task.h
#ifndef BME680_TASK_H
#define BME680_TASK_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    float temperature;
    float humidity;
    float pressure;
    float gas_resistance;
    bool valid;
} bme680_data_t;

#endif // BME680_TASK_H

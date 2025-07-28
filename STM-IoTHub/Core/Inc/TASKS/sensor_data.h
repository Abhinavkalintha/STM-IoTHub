#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H
#include <stdint.h>
typedef struct {
    float temperature;
    float humidity;
    uint32_t air_quality;     // Assume IAQ score
    float pressure;

    float voltage;
    float current;
    float power;
    float energy;
} SensorData_t;

extern SensorData_t g_sensorData;

#endif

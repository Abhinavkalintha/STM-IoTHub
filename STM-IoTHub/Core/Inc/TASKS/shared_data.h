#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include "cmsis_os.h"
#include <stdbool.h>

// ----------------------------
// BME680 Sensor Data Structure
// ----------------------------
typedef struct {
    float temperature;
    float humidity;
    float pressure;
    float gas_resistance;
    float air_quality;  // ✅ Air Quality field for smart monitoring
} bme680_data_t;

// ----------------------------
// PZEM-004T Sensor Data Structure
// ----------------------------
typedef struct {
    float voltage;
    float current;
    float power;
    float energy;
    float frequency;
    float power_factor;
} pzem_data_t;


// ----------------------------
// Shared Data Structure
// ----------------------------
typedef struct {
    bme680_data_t bme680;   // Environmental sensor data
    pzem_data_t pzem;       // Energy meter sensor data

    uint8_t relay1_status;  // Fan
    uint8_t relay2_status;  // Light

    osMutexId_t mutex_id;   // Mutex for thread-safe access

    // ------------------------
    // Add Global Variables Here
    // ------------------------
    float g_voltage;        // Voltage value for energy monitoring
    float g_current;        // Current value for energy monitoring
    float g_power;          // Power value for energy monitoring
} shared_data_t;


// ----------------------------
// External Global Shared Struct
// ----------------------------
extern shared_data_t shared_data;

// ----------------------------
// Global Flags for Automation
// ----------------------------
extern bool g_energyAlert;  // Set to true if power > 500W or current > 1A

#endif  // SHARED_DATA_H







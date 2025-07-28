#include "bme680_app.h"
#include "bme68x.h"
#include "bme68x_defs.h"
#include "bme680_user.h"
#include "main.h"
#include "shared_data.h"


// 📍 Global sensor device structure
struct bme68x_dev gas_sensor;

// 🧠 Extern I2C handle (defined in main.c)
extern I2C_HandleTypeDef hi2c1;

/**
 * @brief Initializes the BME680 sensor with appropriate settings
 */
void BME680_Init(void)
{
    int8_t rslt;

    // 🔌 Interface setup
    gas_sensor.intf = BME68X_I2C_INTF;
    gas_sensor.read = user_i2c_read;
    gas_sensor.write = user_i2c_write;
    gas_sensor.delay_us = user_delay_us;
    gas_sensor.intf_ptr = &hi2c1;
    gas_sensor.amb_temp = 25;

    // 🚀 Initialize the BME680 sensor
    rslt = bme68x_init(&gas_sensor);
    if (rslt != BME68X_OK) return;

    // ⚙️ Sensor configuration
    struct bme68x_conf conf;
    conf.os_hum  = BME68X_OS_2X;
    conf.os_pres = BME68X_OS_4X;
    conf.os_temp = BME68X_OS_8X;
    conf.filter  = BME68X_FILTER_OFF;

    rslt = bme68x_set_conf(&conf, &gas_sensor);
    if (rslt != BME68X_OK) return;

    // 🔥 Heater configuration
    struct bme68x_heatr_conf heatr_conf;
    heatr_conf.enable     = BME68X_ENABLE;
    heatr_conf.heatr_temp = 300;      // Target heater temperature (°C)
    heatr_conf.heatr_dur  = 100;      // Heating duration in milliseconds

    rslt = bme68x_set_heatr_conf(BME68X_FORCED_MODE, &heatr_conf, &gas_sensor);
    if (rslt != BME68X_OK) return;
}

/**
 * @brief Reads data from the BME680 sensor in forced mode
 */
void BME680_ReadData(void)
{
    struct bme68x_data data;
    uint8_t n_fields;
    int8_t rslt;

    // 🕹️ Set operation mode
    rslt = bme68x_set_op_mode(BME68X_FORCED_MODE, &gas_sensor);
    if (rslt != BME68X_OK) return;

    // ⏱️ Wait for measurement duration
    gas_sensor.delay_us(100000, gas_sensor.intf_ptr); // Delay 100ms

    // 📥 Read sensor data
    rslt = bme68x_get_data(BME68X_FORCED_MODE, &data, &n_fields, &gas_sensor);
    if (rslt == BME68X_OK && n_fields > 0)
    {
        // ✅ Save data to global variables
        g_temperature = data.temperature;
        g_humidity = data.humidity;
    }
}

/**
 * @brief Returns the last read temperature
 */
float BME680_ReadTemperature(void)
{
    return g_temperature;
}

/**
 * @brief Returns the last read humidity
 */
float BME680_ReadHumidity(void)
{
    return g_humidity;
}



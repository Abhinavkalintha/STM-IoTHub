#include <stdlib.h>
#include "bme680_user.h"
#include "bme68x.h"
#include "stm32f4xx_hal.h" // Include correct HAL header for your MCU

extern I2C_HandleTypeDef hi2c1;

// === I2C READ ===
int8_t user_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, void *intf_ptr)
{
    uint8_t dev_addr = *((uint8_t *)intf_ptr);
    return (HAL_I2C_Mem_Read(&hi2c1, dev_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, reg_data, len, 100) == HAL_OK) ? 0 : -1;
}

// === I2C WRITE ===
int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len, void *intf_ptr)
{
    uint8_t dev_addr = *((uint8_t *)intf_ptr);
    return (HAL_I2C_Mem_Write(&hi2c1, dev_addr, reg_addr, I2C_MEMADD_SIZE_8BIT, (uint8_t *)reg_data, len, 100) == HAL_OK) ? 0 : -1;
}

// === DELAY ===
void user_delay_us(uint32_t period, void *intf_ptr)
{
    (void)intf_ptr;
    HAL_Delay(period / 1000); // crude conversion from us to ms
}

// === SENSOR INITIALIZATION FUNCTION ===
// You call this from main.c
int8_t init_bme680_sensor(struct bme68x_dev *dev)
{
    int8_t rslt;
    
    dev->intf = BME68X_I2C_INTF;
    dev->read = user_i2c_read;
    dev->write = user_i2c_write;
    dev->delay_us = user_delay_us;
    dev->intf_ptr = malloc(sizeof(uint8_t)); // OR use a static address
    *((uint8_t *)dev->intf_ptr) = BME68X_I2C_ADDR_LOW; // 0x76 or BME68X_I2C_ADDR_HIGH (0x77)

    rslt = bme68x_init(dev);
    if (rslt != BME68X_OK) return rslt;

    struct bme68x_conf conf;
    struct bme68x_heatr_conf heatr_conf;

    conf.os_hum  = BME68X_OS_2X;
    conf.os_pres = BME68X_OS_4X;
    conf.os_temp = BME68X_OS_8X;
    conf.filter  = BME68X_FILTER_OFF;

    rslt = bme68x_set_conf(&conf, dev);
    if (rslt != BME68X_OK) return rslt;

    heatr_conf.enable     = BME68X_ENABLE;
    heatr_conf.heatr_temp = 300;
    heatr_conf.heatr_dur  = 100;

    rslt = bme68x_set_heatr_conf(BME68X_FORCED_MODE, &heatr_conf, dev);
    return rslt;
}




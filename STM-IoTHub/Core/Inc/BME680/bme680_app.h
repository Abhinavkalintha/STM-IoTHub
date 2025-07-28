#ifndef __BME680_APP_H__
#define __BME680_APP_H__

void BME680_Init(void);
void BME680_ReadData(void);

// 🌡️ Global variables
extern float g_temperature;
extern float g_humidity;

// ✅ New function declarations
float BME680_ReadTemperature(void);
float BME680_ReadHumidity(void);

#endif /* __BME680_APP_H__ */



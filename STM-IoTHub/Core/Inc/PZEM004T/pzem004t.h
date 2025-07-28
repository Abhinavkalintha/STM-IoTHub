#ifndef __PZEM004T_H__
#define __PZEM004T_H__

#include "main.h"
#include "stm32f4xx_hal.h"

// Initialization
void PZEM_Init(UART_HandleTypeDef *huart);
float PZEM_ReadFrequency(void);
float PZEM_ReadEnergy(void);
float PZEM_ReadPowerFactor(void);
// Voltage functions
void PZEM_RequestVoltage(void);
float PZEM_ReadVoltage(void);
float PZEM_GetVoltage(void);

// Current functions
float PZEM_ReadCurrent(void);
float get_pzem_current(void);  // Optional alias or wrapper

// Power functions
float PZEM_ReadPower(void);

#endif // __PZEM004T_H__


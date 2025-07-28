#include "pzem004t.h"
#include "string.h"
#include <stdbool.h>

extern UART_HandleTypeDef huart2;

#define PZEM_RESPONSE_SIZE 7
static uint8_t rxBuffer[PZEM_RESPONSE_SIZE];

// CRC16 lookup and calculation — optional (CRC check can be added)
static uint16_t ModRTU_CRC(uint8_t *buf, int len) {
    uint16_t crc = 0xFFFF;
    for (int pos = 0; pos < len; pos++) {
        crc ^= (uint16_t)buf[pos];          
        for (int i = 8; i != 0; i--) {
            if ((crc & 0x0001) != 0) {
                crc >>= 1;
                crc ^= 0xA001;
            } else
                crc >>= 1;
        }
    }
    return crc;
}

void PZEM_Init(UART_HandleTypeDef *huart) {
    HAL_UART_Receive_IT(huart, rxBuffer, PZEM_RESPONSE_SIZE);
}

// ========== Request Commands ==========

void PZEM_RequestVoltage(void) {
    uint8_t cmd[] = {0x01, 0x04, 0x00, 0x00, 0x00, 0x02, 0x71, 0xCB};
    HAL_UART_Transmit(&huart2, cmd, sizeof(cmd), HAL_MAX_DELAY);
}

void PZEM_RequestCurrent(void) {
    uint8_t cmd[] = {0x01, 0x04, 0x00, 0x02, 0x00, 0x02, 0x90, 0x0A};
    HAL_UART_Transmit(&huart2, cmd, sizeof(cmd), HAL_MAX_DELAY);
}

void PZEM_RequestPower(void) {
    uint8_t cmd[] = {0x01, 0x04, 0x00, 0x04, 0x00, 0x02, 0x30, 0x0B};
    HAL_UART_Transmit(&huart2, cmd, sizeof(cmd), HAL_MAX_DELAY);
}

// ========== Response Parsers ==========

float PZEM_GetVoltage(void) {
    uint16_t raw = (rxBuffer[3] << 8) | rxBuffer[4];
    return raw / 10.0f;
}

float PZEM_GetCurrent(void) {
    uint16_t raw = (rxBuffer[3] << 8) | rxBuffer[4];
    return raw / 100.0f;
}

float PZEM_GetPower(void) {
    uint16_t raw = (rxBuffer[3] << 8) | rxBuffer[4];
    return raw / 10.0f;
}

// ========== High-Level APIs ==========

float PZEM_ReadVoltage(void) {
    PZEM_RequestVoltage();
    HAL_Delay(100);  // Block until data arrives (use semaphore if RTOS)
    return PZEM_GetVoltage();
}

float PZEM_ReadCurrent(void) {
    PZEM_RequestCurrent();
    HAL_Delay(100);
    return PZEM_GetCurrent();
}

float PZEM_ReadPower(void) {
    PZEM_RequestPower();
    HAL_Delay(100);
    return PZEM_GetPower();
}
float PZEM_ReadFrequency(void) {
    uint8_t cmd[] = {0x01, 0x04, 0x00, 0x46, 0x00, 0x02, 0xf1, 0x9a}; // Standard read frequency cmd
    HAL_UART_Transmit(&huart2, cmd, sizeof(cmd), HAL_MAX_DELAY);
    HAL_Delay(100);  // wait for response
    uint16_t raw = (rxBuffer[3] << 8) | rxBuffer[4];
    return raw / 10.0f;
}

float PZEM_ReadEnergy(void) {
    uint8_t cmd[] = {0x01, 0x04, 0x00, 0x08, 0x00, 0x02, 0xF1, 0x98};
    HAL_UART_Transmit(&huart2, cmd, sizeof(cmd), HAL_MAX_DELAY);
    HAL_Delay(100);
    uint16_t raw = (rxBuffer[3] << 8) | rxBuffer[4];
    return (float)raw; // Usually in Wh
}

float PZEM_ReadPowerFactor(void) {
    uint8_t cmd[] = {0x01, 0x04, 0x00, 0x0E, 0x00, 0x02, 0x31, 0x9B};
    HAL_UART_Transmit(&huart2, cmd, sizeof(cmd), HAL_MAX_DELAY);
    HAL_Delay(100);
    uint16_t raw = (rxBuffer[3] << 8) | rxBuffer[4];
    return raw / 100.0f;
}



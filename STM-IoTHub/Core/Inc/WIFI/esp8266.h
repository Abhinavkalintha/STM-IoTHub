#ifndef __ESP8266_H__
#define __ESP8266_H__

#include "main.h"  // For UART_HandleTypeDef

extern UART_HandleTypeDef *esp_uart;

void ESP_Init(UART_HandleTypeDef *huart);
void ESP_SendATCommand(const char *cmd);
void ESP_SendData(const char *data);

#endif // __ESP8266_H__



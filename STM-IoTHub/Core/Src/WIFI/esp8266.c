#include "esp8266.h"
#include <string.h>
#include <stdio.h>  // For snprintf
extern int user_light_state;
extern RTC_HandleTypeDef hrtc;
void ESP8266_ProcessCommand(char *cmd)
{
    if (strstr(cmd, "LIGHT=1"))
    {
        user_light_state = 1;
    }
    else if (strstr(cmd, "LIGHT=0"))
    {
        user_light_state = 0;
    }
}

UART_HandleTypeDef *esp_uart;

void ESP_Init(UART_HandleTypeDef *huart) {
    
    esp_uart = huart;
    HAL_UART_Transmit(esp_uart, (uint8_t *)"AT\r\n", strlen("AT\r\n"), HAL_MAX_DELAY);
    HAL_Delay(1000);
    
}

void ESP_SendATCommand(const char *cmd) {
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "%s\r\n", cmd);
    HAL_UART_Transmit(esp_uart, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
    HAL_Delay(1000);
}

void ESP_SendData(const char *data) {
    HAL_UART_Transmit(esp_uart, (uint8_t *)data, strlen(data), HAL_MAX_DELAY);
}


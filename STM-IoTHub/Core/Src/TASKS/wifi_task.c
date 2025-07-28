#include "cmsis_os.h"
#include "esp8266.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart2; // Update this to the UART connected to ESP

void WiFiTask(void *argument) {
    ESP_Init(&huart2);

    for (;;) {
        // Example AT command to keep WiFi module alive
        ESP_SendATCommand("AT");

        // Example data to send (can be changed to real sensor data)
        const char *data = "Hello from STM32!\r\n";
        ESP_SendData(data);

        osDelay(5000); // Send every 5 seconds
    }
}

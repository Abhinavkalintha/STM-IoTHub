#include "main.h"
#include "cmsis_os.h"
#include "pzem_task.h"
#include "string.h"
#include "stdio.h"
#include "ssd1306.h"
#include "uart_ring.h"

// External declarations
extern UART_HandleTypeDef huart2;              // Assuming PZEM is connected to USART2
           // Ring buffer for UART2 RX
extern UART_RingBuffer_t uart2_rx_buffer;
// Constants
#define PZEM_REQUEST_FRAME_SIZE    8
#define PZEM_RESPONSE_FRAME_SIZE   25  // Adjust according to actual response length

// PZEM frame buffer
static uint8_t pzem_request[PZEM_REQUEST_FRAME_SIZE] = {
    0xB0, 0xC0, 0xA8, 0x01, 0x01, 0x01, 0x1A, 0xC1  // Example request frame
};

static uint8_t pzem_response[PZEM_RESPONSE_FRAME_SIZE];

// Measured values
float voltage = 0, current = 0, power = 0, energy = 0;

// Function to send request to PZEM
void send_pzem_request(void) {
    HAL_UART_Transmit(&huart2, pzem_request, PZEM_REQUEST_FRAME_SIZE, HAL_MAX_DELAY);
}

// Function to receive response from PZEM using ring buffer
uint8_t receive_pzem_response(void) {
    uint32_t start = HAL_GetTick();
    uint16_t received = 0;

    while ((HAL_GetTick() - start) < 1000) {
        while (!is_ring_buffer_empty(&uart2_rx_buffer) && received < PZEM_RESPONSE_FRAME_SIZE) {
            pzem_response[received++] = read_byte_from_ring_buffer(&uart2_rx_buffer);
        }
        if (received >= PZEM_RESPONSE_FRAME_SIZE)
            break;
        osDelay(10);  // Small delay to avoid CPU hog
    }

    return (received >= PZEM_RESPONSE_FRAME_SIZE);
}

// Function to parse voltage, current, power, energy
void parse_pzem_data(void) {
    if (pzem_response[0] != 0xA0) return;

    voltage = (float)((pzem_response[1] << 8) | pzem_response[2]) / 10.0f;
    current = (float)((pzem_response[3] << 8) | pzem_response[4]) / 100.0f;
    power   = (float)((pzem_response[5] << 8) | pzem_response[6]) / 10.0f;
    energy  = (float)((pzem_response[7] << 8) | pzem_response[8]) / 1000.0f;
}

// Function to show data on OLED
void display_pzem_data(void) {
    char buffer[32];

    OLED_Clear();

    sprintf(buffer, "V:%.1fV", voltage);
    OLED_ShowString(0, 0, buffer, 1);

    sprintf(buffer, "I:%.2fA", current);
    OLED_ShowString(0, 10, buffer, 1);

    sprintf(buffer, "P:%.1fW", power);
    OLED_ShowString(0, 20, buffer, 1);

    sprintf(buffer, "E:%.3fkWh", energy);
    OLED_ShowString(0, 30, buffer, 1);
}

// FreeRTOS task for PZEM
void StartPzemTask(void *argument) {
    for (;;) {
        send_pzem_request();
        osDelay(200);  // Wait for data to be received

        if (receive_pzem_response()) {
            parse_pzem_data();
            display_pzem_data();
        }

        osDelay(1000);  // Refresh every 1 second
    }
}





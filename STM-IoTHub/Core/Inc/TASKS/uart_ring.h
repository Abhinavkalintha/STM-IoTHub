#ifndef UART_RING_H
#define UART_RING_H

#include "main.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

#define UART_RING_BUFFER_SIZE 256

typedef struct {
    uint8_t buffer[UART_RING_BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} UART_RingBuffer_t;

// Initialization
void uart_ring_init(UART_RingBuffer_t *rb);

// Check how many bytes available in buffer
uint16_t uart_ring_available(UART_RingBuffer_t *rb);

// Read 1 byte from buffer (call only if available() > 0)
uint8_t uart_ring_read(UART_RingBuffer_t *rb);

// Write 1 byte to buffer (used internally)
void uart_ring_write(UART_RingBuffer_t *rb, uint8_t data);

// RX ISR handler — to be called inside HAL_UART_RxCpltCallback
void uart_ring_rx_handler(UART_HandleTypeDef *huart, UART_RingBuffer_t *rb);

// Begin receiving 1 byte using interrupt
void uart_ring_start_rx(UART_HandleTypeDef *huart, UART_RingBuffer_t *rb);

#endif // UART_RING_H



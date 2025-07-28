#include "uart_ring.h"

static uint8_t rx_byte; // Temporary byte for interrupt reception

void uart_ring_init(UART_RingBuffer_t *rb) {
    rb->head = 0;
    rb->tail = 0;
}

uint16_t uart_ring_available(UART_RingBuffer_t *rb) {
    return (UART_RING_BUFFER_SIZE + rb->head - rb->tail) % UART_RING_BUFFER_SIZE;
}

uint8_t uart_ring_read(UART_RingBuffer_t *rb) {
    if (rb->head == rb->tail) return 0; // buffer empty
    uint8_t data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % UART_RING_BUFFER_SIZE;
    return data;
}

void uart_ring_write(UART_RingBuffer_t *rb, uint8_t data) {
    uint16_t next_head = (rb->head + 1) % UART_RING_BUFFER_SIZE;
    if (next_head != rb->tail) { // if buffer not full
        rb->buffer[rb->head] = data;
        rb->head = next_head;
    }
    // else: data is lost if buffer full
}

void uart_ring_start_rx(UART_HandleTypeDef *huart, UART_RingBuffer_t *rb) {
    HAL_UART_Receive_IT(huart, &rx_byte, 1);
}

// To be called inside HAL_UART_RxCpltCallback
void uart_ring_rx_handler(UART_HandleTypeDef *huart, UART_RingBuffer_t *rb) {
    uart_ring_write(rb, rx_byte); // store received byte in ring buffer
    HAL_UART_Receive_IT(huart, &rx_byte, 1); // re-enable interrupt
}


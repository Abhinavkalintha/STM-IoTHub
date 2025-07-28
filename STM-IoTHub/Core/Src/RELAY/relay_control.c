#include "relay_control.h"

void Relay_Init(void) {
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;  // Example pins
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_RESET); // Turn off relays
}

void Relay_On(uint16_t pin) {
    HAL_GPIO_WritePin(GPIOB, pin, GPIO_PIN_SET);
}

void Relay_Off(uint16_t pin) {
    HAL_GPIO_WritePin(GPIOB, pin, GPIO_PIN_RESET);
}

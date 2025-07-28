#include "status_led.h"

// These are the GPIO pins configured in CubeMX for the 3 LEDs
#define LED_ALIVE_GPIO_Port   GPIOA
#define LED_ALIVE_Pin         GPIO_PIN_5

#define LED_WIFI_GPIO_Port    GPIOB
#define LED_WIFI_Pin          GPIO_PIN_0

#define LED_ERROR_GPIO_Port   GPIOC
#define LED_ERROR_Pin         GPIO_PIN_13

void StatusLED_Init(void) {
    // Already initialized by CubeMX's MX_GPIO_Init()
}

void StatusLED_Set(StatusLED_Type led, LED_State state) {
    GPIO_TypeDef *port;
    uint16_t pin;

    switch (led) {
        case LED_ALIVE:
            port = LED_ALIVE_GPIO_Port;
            pin = LED_ALIVE_Pin;
            break;
        case LED_WIFI:
            port = LED_WIFI_GPIO_Port;
            pin = LED_WIFI_Pin;
            break;
        case LED_ERROR:
            port = LED_ERROR_GPIO_Port;
            pin = LED_ERROR_Pin;
            break;
        default:
            return;
    }

    HAL_GPIO_WritePin(port, pin, (GPIO_PinState)state);
}

void StatusLED_Toggle(StatusLED_Type led) {
    GPIO_TypeDef *port;
    uint16_t pin;

    switch (led) {
        case LED_ALIVE:
            port = LED_ALIVE_GPIO_Port;
            pin = LED_ALIVE_Pin;
            break;
        case LED_WIFI:
            port = LED_WIFI_GPIO_Port;
            pin = LED_WIFI_Pin;
            break;
        case LED_ERROR:
            port = LED_ERROR_GPIO_Port;
            pin = LED_ERROR_Pin;
            break;
        default:
            return;
    }

    HAL_GPIO_TogglePin(port, pin);
}

#include "main.h"
#include "stm32f4xx_hal_rtc.h" // Needed for HAL_RTC_GetTime
#include "cmsis_os.h"
#include <stdbool.h>
#include "pzem004t.h" 
volatile uint8_t user_light_state = 0;
extern RTC_HandleTypeDef hrtc;
bool is_blocked_time()
{
    RTC_TimeTypeDef sTime;
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);

    uint16_t hour = sTime.Hours;
    uint16_t minute = sTime.Minutes;

    // Block if time is between 10:30 PM (22:30) and 6:00 AM
    if ((hour == 22 && minute >= 30) || (hour >= 23) || (hour < 6))
        return true;

    return false;
}
bool check_pzem_fault()
{
    float current = get_pzem_current();  // Function must be available from your PZEM code

    if (current > 1.5f)  // Set your threshold here
        return true;

    return false;
}
void LightAutomationTask(void *argument)
{
    for (;;)
    {
        bool fault = check_pzem_fault();       // From STEP 4
        bool timeBlock = is_blocked_time();    // From STEP 3

        if (fault || timeBlock)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);  // Turn OFF
        }
        else
        {
            if (user_light_state)
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);    // ON
            else
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);  // OFF
        }

        vTaskDelay(pdMS_TO_TICKS(1000));  // 1 sec delay
    }
}

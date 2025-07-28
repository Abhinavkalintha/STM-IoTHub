/**
 * @file oled_task.c
 * @brief Task to display sensor parameters on SSD1306 OLED using STM32 HAL and FreeRTOS
 * @path  Core/Src/TASKS/oled_task.c
 */

#include "shared_data.h"
#include "cmsis_os.h"
#include "ssd1306.h"
#include "bme680_app.h"
#include "pzem004t_app.h"
#include <stdio.h>

// External sensor data variables (updated by other tasks)
extern float temperature, humidity, pressure, gas_resistance; // From BME680
extern float voltage, current, power, energy;                 // From PZEM-004T

void OledTask(void *argument)
{
    ssd1306_Init();  // Initialize the OLED display

    uint8_t screen = 0;  // Tracks which screen to display (0 = Env, 1 = Energy)
    char line[32];       // Line buffer for formatted strings

    for (;;)
    {
        ssd1306_Fill(Black);  // Clear screen buffer

        if (screen == 0)
        {
            // Environmental Parameters (BME680)
            snprintf(line, sizeof(line), "Temp: %.1f C", temperature);
            ssd1306_SetCursor(2, 0);
            ssd1306_WriteString(line, Font_6x8, White);

            snprintf(line, sizeof(line), "Hum : %.1f %%", humidity);
            ssd1306_SetCursor(2, 10);
            ssd1306_WriteString(line, Font_6x8, White);

            snprintf(line, sizeof(line), "Pres: %.0f hPa", pressure);
            ssd1306_SetCursor(2, 20);
            ssd1306_WriteString(line, Font_6x8, White);

            snprintf(line, sizeof(line), "AQI : %.0f", gas_resistance);
            ssd1306_SetCursor(2, 30);
            ssd1306_WriteString(line, Font_6x8, White);
        }
        else
        {
            // Energy Parameters (PZEM-004T)
            snprintf(line, sizeof(line), "Power: %.2f W", power);
            ssd1306_SetCursor(2, 0);
            ssd1306_WriteString(line, Font_6x8, White);

            snprintf(line, sizeof(line), "Volt : %.1f V", voltage);
            ssd1306_SetCursor(2, 10);
            ssd1306_WriteString(line, Font_6x8, White);

            snprintf(line, sizeof(line), "Curr : %.2f A", current);
            ssd1306_SetCursor(2, 20);
            ssd1306_WriteString(line, Font_6x8, White);

            snprintf(line, sizeof(line), "Ener : %.2f Wh", energy);
            ssd1306_SetCursor(2, 30);
            ssd1306_WriteString(line, Font_6x8, White);
        }

        ssd1306_UpdateScreen();  // Refresh the OLED display

        screen = (screen + 1) % 2;  // Alternate between screen 0 and 1
        osDelay(3000);  // Delay 3 seconds between screen switches
    }
}






#include "shared_data.h"
#include "cmsis_os.h"
#include <stdbool.h>
void AlertTask(void *argument) {
    for (;;) {
        if (g_energyAlert) {
            // Do alert logic
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

    


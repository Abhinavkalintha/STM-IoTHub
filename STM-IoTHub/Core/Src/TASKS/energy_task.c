#include "shared_data.h"
#include "cmsis_os.h"
#include "pzem_task.h"     // Assuming PZEM read functions are defined here
#include <stdio.h>
#include <stdbool.h>
#include "pzem004t.h"
// Threshold values (adjust as needed)
#define OVER_VOLTAGE_THRESHOLD 250.0f
#define OVER_CURRENT_THRESHOLD 5.0f
#define HIGH_POWER_THRESHOLD   1000.0f

void StartEnergyTask(void *argument)
{
    for (;;)
    {
        // Local variables to store readings
        float voltage = PZEM_ReadVoltage();
        float current = PZEM_ReadCurrent();
        float power   = PZEM_ReadPower();
        float energy  = PZEM_ReadEnergy();
        float freq    = PZEM_ReadFrequency();
        float pf      = PZEM_ReadPowerFactor();

        // Thread-safe update of shared_data
        if (osMutexAcquire(shared_data.mutex_id, osWaitForever) == osOK)
        {
            shared_data.pzem.voltage       = voltage;
            shared_data.pzem.current       = current;
            shared_data.pzem.power         = power;
            shared_data.pzem.energy        = energy;
            shared_data.pzem.frequency     = freq;
            shared_data.pzem.power_factor  = pf;
            osMutexRelease(shared_data.mutex_id);
        }

        // Debug print
        printf("⚡ Energy Readings:\r\n");
        printf("  Voltage: %.2f V\r\n", voltage);
        printf("  Current: %.2f A\r\n", current);
        printf("  Power  : %.2f W\r\n", power);
        printf("  Energy : %.2f kWh\r\n", energy);
        printf("  Freq   : %.2f Hz\r\n", freq);
        printf("  PF     : %.2f\r\n", pf);

        // Fault detection
        if (voltage > OVER_VOLTAGE_THRESHOLD || current > OVER_CURRENT_THRESHOLD || power > HIGH_POWER_THRESHOLD)
        {
            printf("⚠️ Energy Alert: Abnormal values detected!\r\n");
        }

        osDelay(2000); // Delay 2 seconds
    }
}





#include "pzem004t_app.h"

// Simulated data for now — replace with UART read logic
void PZEM004T_Init(void) {
    // UART init if needed
}

void PZEM004T_Read(PZEM004T_Data *data) {
    // Replace with real UART data fetching from PZEM-004T
    data->voltage = 230.5f;
    data->current = 1.25f;
    data->power   = 288.125f;
    data->energy  = 12.5f;
}

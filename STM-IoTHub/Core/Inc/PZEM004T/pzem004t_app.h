#ifndef __PZEM004T_APP_H__
#define __PZEM004T_APP_H__

#include <stdint.h>

typedef struct {
    float voltage;
    float current;
    float power;
    float energy;
} PZEM004T_Data;

void PZEM004T_Init(void);
void PZEM004T_Read(PZEM004T_Data *data);

#endif // __PZEM004T_APP_H__

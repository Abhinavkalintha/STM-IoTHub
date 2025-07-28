#ifndef INC_TASKS_PZEM004T_TASK_H_
#define INC_TASKS_PZEM004T_TASK_H_

#include <stdint.h>

typedef struct {
    float voltage;
    float current;
    float power;
    float energy;
    float frequency;
    float power_factor;
} pzem004t_data_t;

void pzem004t_task(void *argument);

#endif /* INC_TASKS_PZEM004T_TASK_H_ */

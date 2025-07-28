#ifndef __LIGHT_TASK_H__
#define __LIGHT_TASK_H__

#include <stdbool.h>

extern volatile uint8_t user_light_state;

void LightAutomationTask(void *argument);
bool is_blocked_time(void);
bool check_pzem_fault(void);

#endif // __LIGHT_TASK_H__

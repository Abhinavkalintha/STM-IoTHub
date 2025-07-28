#ifndef __SDCARD_H
#define __SDCARD_H

#include "main.h"
#include "fatfs.h"
#include <stdbool.h>
bool SD_Init(void);
bool SD_WriteLog(const char* filename, const char* data);

#endif

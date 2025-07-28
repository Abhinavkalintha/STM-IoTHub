#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

extern SPI_HandleTypeDef hspi1;  // Change to your SPI instance (e.g., hspi2 if needed)

void MX_SPI1_Init(void); // Change to match your actual SPI init function name

#ifdef __cplusplus
}
#endif

#endif /* __SPI_H__ */

#ifndef __FATFS_SD_H
#define __FATFS_SD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "diskio.h"
#include "stm32f4xx_hal.h"

// ==== Chip Select pin config ====
#define HSPI_SDCARD     &hspi2
#define SD_CS_PORT      GPIOB
#define SD_CS_PIN       GPIO_PIN_12
#define SPI_TIMEOUT     100

// ==== SD card command list ====
#define CMD0    (0x40+0)    // GO_IDLE_STATE
#define CMD1    (0x40+1)    // SEND_OP_COND (MMC)
#define CMD8    (0x40+8)    // SEND_IF_COND
#define CMD9    (0x40+9)    // SEND_CSD
#define CMD10   (0x40+10)   // SEND_CID
#define CMD12   (0x40+12)   // STOP_TRANSMISSION
#define CMD16   (0x40+16)   // SET_BLOCKLEN
#define CMD17   (0x40+17)   // READ_SINGLE_BLOCK
#define CMD18   (0x40+18)   // READ_MULTIPLE_BLOCK
#define CMD23   (0x40+23)   // SET_BLOCK_COUNT
#define CMD24   (0x40+24)   // WRITE_BLOCK
#define CMD25   (0x40+25)   // WRITE_MULTIPLE_BLOCK
#define CMD41   (0x40+41)   // SEND_OP_COND (ACMD)
#define CMD55   (0x40+55)   // APP_CMD
#define CMD58   (0x40+58)   // READ_OCR

// ==== Card type flags ====
#define CT_MMC     0x01     // MMC ver 3
#define CT_SD1     0x02     // SD ver 1
#define CT_SD2     0x04     // SD ver 2
#define CT_SDC     (CT_SD1|CT_SD2)
#define CT_BLOCK   0x08     // Block addressing

// ==== FatFs required function prototypes ====
DSTATUS fatfs_sd_initialize(BYTE pdrv);
DSTATUS fatfs_sd_status(BYTE pdrv);
DRESULT fatfs_sd_read(BYTE pdrv, BYTE *buff, DWORD sector, UINT count);
DRESULT fatfs_sd_write(BYTE pdrv, const BYTE *buff, DWORD sector, UINT count);
DRESULT fatfs_sd_ioctl(BYTE pdrv, BYTE cmd, void *buff);

#ifdef __cplusplus
}
#endif

#endif /* __FATFS_SD_H */






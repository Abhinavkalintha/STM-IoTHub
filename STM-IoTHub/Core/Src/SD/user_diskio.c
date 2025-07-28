#include "ff_gen_drv.h"
#include "user_diskio.h"
#include "spi.h"
#include "main.h"

#define SD_CS_GPIO_Port GPIOA
#define SD_CS_Pin GPIO_PIN_4

extern SPI_HandleTypeDef hspi1;

static DSTATUS Stat = STA_NOINIT;

DSTATUS USER_initialize(BYTE lun) {
    HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET); // Deselect SD
    Stat &= ~STA_NOINIT;
    return Stat;
}

DSTATUS USER_status(BYTE lun) {
    return Stat;
}

DRESULT USER_read(BYTE lun, BYTE *buff, DWORD sector, UINT count) {
    // You need to implement actual SPI read here if required
    return RES_OK;
}

DRESULT USER_write(BYTE lun, const BYTE *buff, DWORD sector, UINT count) {
#if _USE_WRITE == 1
    // You need to implement actual SPI write here if required
    return RES_OK;
#else
    return RES_PARERR;
#endif
}

DRESULT USER_ioctl(BYTE lun, BYTE cmd, void *buff) {
    return RES_OK;
}

// Note: do not use 'const' here if the header doesn't declare it as const
const Diskio_drvTypeDef USER_Driver = {
    USER_initialize,
    USER_status,
    USER_read,
#if _USE_WRITE == 1
    USER_write,
#endif
#if _USE_IOCTL == 1
    USER_ioctl,
#endif
};









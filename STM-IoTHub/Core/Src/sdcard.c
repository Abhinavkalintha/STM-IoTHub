#include "sdcard.h"
#include "fatfs.h"
#include <string.h>
#include <stdio.h>

// Optional: For FreeRTOS thread safety (uncomment if using FreeRTOS)
// #include "cmsis_os.h"
// osMutexId_t sd_mutex;

static FATFS fs;
static FIL file;
static DIR dir;
static FILINFO fno;
static char SDPath[4];
#define SD_CS_GPIO_Port GPIOA
#define SD_CS_Pin GPIO_PIN_5

void SD_Select(void) {
    HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_RESET);
}

void SD_Deselect(void) {
    HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET);
}

// Initialize SD Card
bool SD_Init(void) {
    // Optional: create mutex
    // sd_mutex = osMutexNew(NULL);

    if (FATFS_LinkDriver(&USER_Driver, SDPath) != 0) {
        printf("Failed to link SD driver\n");
        return false;
    }

    if (f_mount(&fs, SDPath, 1) != FR_OK) {
        printf("Failed to mount SD card\n");
        return false;
    }

    return true;
}

// Write (append) log data
bool SD_WriteLog(const char *filename, const char *data) {
    // osMutexAcquire(sd_mutex, osWaitForever);  // Optional mutex

    if (f_open(&file, filename, FA_OPEN_APPEND | FA_WRITE) != FR_OK) {
        printf("Failed to open file %s for appending\n", filename);
        // osMutexRelease(sd_mutex);
        return false;
    }

    UINT written;
    FRESULT res = f_write(&file, data, strlen(data), &written);
    f_close(&file);

    // osMutexRelease(sd_mutex);
    return (res == FR_OK && written == strlen(data));
}

// Write (overwrite) data
bool SD_WriteOverwrite(const char *filename, const char *data) {
    // osMutexAcquire(sd_mutex, osWaitForever);

    if (f_open(&file, filename, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK) {
        printf("Failed to open file %s for overwrite\n", filename);
        // osMutexRelease(sd_mutex);
        return false;
    }

    UINT written;
    FRESULT res = f_write(&file, data, strlen(data), &written);
    f_close(&file);

    // osMutexRelease(sd_mutex);
    return (res == FR_OK && written == strlen(data));
}

// Read file contents into buffer
bool SD_ReadFile(const char *filename, char *buffer, UINT bufsize) {
    // osMutexAcquire(sd_mutex, osWaitForever);

    if (f_open(&file, filename, FA_READ) != FR_OK) {
        printf("Failed to open file %s for reading\n", filename);
        // osMutexRelease(sd_mutex);
        return false;
    }

    UINT bytesRead;
    FRESULT res = f_read(&file, buffer, bufsize - 1, &bytesRead);
    buffer[bytesRead] = '\0';  // Null-terminate
    f_close(&file);

    // osMutexRelease(sd_mutex);
    return (res == FR_OK);
}

// Check if file exists
bool SD_FileExists(const char *filename) {
    return (f_stat(filename, &fno) == FR_OK);
}

// List files in a directory
void SD_ListFiles(const char *path) {
    if (f_opendir(&dir, path) != FR_OK) {
        printf("Failed to open directory %s\n", path);
        return;
    }

    while (1) {
        FRESULT res = f_readdir(&dir, &fno);
        if (res != FR_OK || fno.fname[0] == '\0') break;

        if (fno.fattrib & AM_DIR)
            printf("[DIR ] %s\n", fno.fname);
        else
            printf("[FILE] %s\n", fno.fname);
    }

    f_closedir(&dir);
}

// Optional: Unmount and unlink driver
void SD_Deinit(void) {
    f_mount(NULL, SDPath, 1);
    FATFS_UnLinkDriver(SDPath);
    // osMutexDelete(sd_mutex);
}



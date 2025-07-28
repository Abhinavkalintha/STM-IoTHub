#include "ssd1306.h"
#include "stm32f4xx_hal.h"   // For HAL functions and HAL_MAX_DELAY
#include "main.h"            // extern I2C handle (hi2c1)
#include <string.h>

extern I2C_HandleTypeDef hi2c1;

static uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];
static uint8_t SSD1306_CurrentX = 0;
static uint8_t SSD1306_CurrentY = 0;

static void SSD1306_WriteCommand(uint8_t cmd) {
    uint8_t data[2] = {0x00, cmd};
    HAL_I2C_Master_Transmit(&hi2c1, SSD1306_I2C_ADDR, data, 2, HAL_MAX_DELAY);
}

void SSD1306_Init(void) {
    HAL_Delay(100);  // Power-on delay

    SSD1306_WriteCommand(0xAE); // Display off
    SSD1306_WriteCommand(0x20); // Set memory addressing mode
    SSD1306_WriteCommand(0x00); // Horizontal addressing mode
    SSD1306_WriteCommand(0xB0); // Page Start Address
    SSD1306_WriteCommand(0xC8); // COM Output Scan Direction remapped
    SSD1306_WriteCommand(0x00); // Low column address
    SSD1306_WriteCommand(0x10); // High column address
    SSD1306_WriteCommand(0x40); // Start line address
    SSD1306_WriteCommand(0x81); // Contrast control
    SSD1306_WriteCommand(0xFF);
    SSD1306_WriteCommand(0xA1); // Segment remap
    SSD1306_WriteCommand(0xA6); // Normal display (not inverted)
    SSD1306_WriteCommand(0xA8); // Multiplex ratio
    SSD1306_WriteCommand(0x3F);
    SSD1306_WriteCommand(0xA4); // Output RAM to display
    SSD1306_WriteCommand(0xD3); // Display offset
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0xD5); // Display clock divide ratio/oscillator freq
    SSD1306_WriteCommand(0xF0);
    SSD1306_WriteCommand(0xD9); // Pre-charge period
    SSD1306_WriteCommand(0x22);
    SSD1306_WriteCommand(0xDA); // COM pins hardware config
    SSD1306_WriteCommand(0x12);
    SSD1306_WriteCommand(0xDB); // VCOMH deselect level
    SSD1306_WriteCommand(0x20);
    SSD1306_WriteCommand(0x8D); // Charge pump setting
    SSD1306_WriteCommand(0x14);
    SSD1306_WriteCommand(0xAF); // Display ON

    SSD1306_Fill(Black);
    SSD1306_UpdateScreen();
    SSD1306_SetCursor(0, 0);
}

void SSD1306_Fill(SSD1306_COLOR color) {
    memset(SSD1306_Buffer, (color == White) ? 0xFF : 0x00, sizeof(SSD1306_Buffer));
}

void SSD1306_Clear(void) {
    SSD1306_Fill(Black);
}

void SSD1306_UpdateScreen(void) {
    for (uint8_t page = 0; page < 8; page++) {
        SSD1306_WriteCommand(0xB0 + page);
        SSD1306_WriteCommand(0x00);
        SSD1306_WriteCommand(0x10);

        HAL_I2C_Mem_Write(&hi2c1, SSD1306_I2C_ADDR, 0x40, 1,
                          &SSD1306_Buffer[SSD1306_WIDTH * page],
                          SSD1306_WIDTH, HAL_MAX_DELAY);
    }
}

void SSD1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color) {
    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) return;

    if (color == White)
        SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |=  (1 << (y % 8));
    else
        SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
}

void SSD1306_SetCursor(uint8_t x, uint8_t y) {
    SSD1306_CurrentX = x;
    SSD1306_CurrentY = y;
}

// Corrected font data indexing: data is 1D array, so calculate offset
void SSD1306_WriteChar(char ch, const SSD1306_Font_t* font, SSD1306_COLOR color) {
    if (ch < 32 || ch > 126) ch = '?';

    for (uint8_t i = 0; i < font->Width; i++) {
        // Calculate correct offset in font data array
        uint8_t line = font->data[(ch - 32) * font->Width + i];
        for (uint8_t j = 0; j < font->Height; j++) {
            SSD1306_DrawPixel(SSD1306_CurrentX + i, SSD1306_CurrentY + j, ((line >> j) & 0x1) ? color : Black);
        }
    }

    SSD1306_CurrentX += font->Width;
}

void SSD1306_WriteString(const char* str, const SSD1306_Font_t* font, SSD1306_COLOR color) {
    while (*str) {
        SSD1306_WriteChar(*str++, font, color);
    }
}



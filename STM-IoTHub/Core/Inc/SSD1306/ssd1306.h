#ifndef __SSD1306_H__
#define __SSD1306_H__

#include <stdint.h>
#include "ssd1306_fonts.h"

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64
#define SSD1306_I2C_ADDR 0x78

typedef enum {
    Black = 0,
    White = 1
} SSD1306_COLOR;

// Function prototypes
void SSD1306_Init(void);
void SSD1306_Fill(SSD1306_COLOR color);
void SSD1306_UpdateScreen(void);
void SSD1306_SetCursor(uint8_t x, uint8_t y);
void SSD1306_WriteChar(char ch, const SSD1306_Font_t* font, SSD1306_COLOR color);
void SSD1306_WriteString(const char* str, const SSD1306_Font_t* font, SSD1306_COLOR color);
void SSD1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
void SSD1306_Clear(void);

#endif /* __SSD1306_H__ */


#ifndef __LCD_Z_H__
#define __LCD_Z_H__
#include "stdint.h"
#include "lm4f120h5qr.h"
void delay(unsigned int delay);
void init_lcd();
void write_cmd(uint8_t cmd);
void write_data(uint8_t data);
void latch();
void lcd_clr(void);
void write_string(char* string);
void set_cursor(int x, int y);

#endif // __LCD_Z_H__
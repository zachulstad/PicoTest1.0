/**
 * pico_lcd.h - simple LCD utility library for pico2
 * 
 * Description:
 * A simple LCD utility library for Pico 2, using the SSD1803A LCD driver and DOGS104-A LCD display.
 * 
 * Author: Zach Ulstad
 * Created: June 13th, 2025
 * Version: 1.0.0
 */

#ifndef PICO_LCD_H
#define PICO_LCD_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

void lcd_cmd(char cmd);
void lcd_clear();
void init_lcd();
void lcd_set_cursor(char x, char y);
void lcd_print_char(char character);
void lcd_print_str(const char * str);
void lcd_scroll_message(const char * str);


#endif // PICO_LCD_H
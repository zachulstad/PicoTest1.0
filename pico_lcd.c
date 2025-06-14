#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico_lcd.h"

// I2C pin definitons, user should adjust to match their pins of choice
#define I2C_PORT i2c1
#define I2C_SDA 18
#define I2C_SCL 19
#define LCD_RESET_PIN 16

#define LCDaddress 0b0111100
#define LCDwrite (LCDaddress << 1) & 0b11111110
#define LCDread (LCDaddress << 1) | 0b00000001

#define LCD_CONTRAST 0x7A

void lcd_cmd(char cmd) {
    char data[] = {0x00, cmd};
    i2c_write_blocking(I2C_PORT, LCDaddress, data, 2, false);
}

void lcd_clear() {
    lcd_cmd(0b0000000001);
}

void init_lcd() {
    // Create a mask for GPIO12 and GPIO16 (32 bit unsigned integer to cover all possible GPIO)
    uint32_t gpio_mask = (1 << LCD_RESET_PIN);

    // Initialize reset pin
    gpio_init(LCD_RESET_PIN);

    // Set reset pin as output
    gpio_set_dir(LCD_RESET_PIN, GPIO_OUT);

    // I2C Initialisation. Using it at 100Khz.
    i2c_init(I2C_PORT, 100*1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    // Reset display
    sleep_ms(5);
    gpio_put(LCD_RESET_PIN, 0);
    sleep_us(20);
    gpio_put(LCD_RESET_PIN, 1);
    sleep_ms(1);

    // initialize LCD (ensuring contrast is adjustable)
    lcd_cmd(0x3A); // function set (RE=1)
    lcd_cmd(0x09); // extended function set
    lcd_cmd(0x06); // entry mode set
    lcd_cmd(0x1E); // bias setting
    lcd_cmd(0x39); // function set (RE=0, IS=1)
    lcd_cmd(0x1B); // internal osc
    lcd_cmd(0x6E); // follower control
    lcd_cmd(0x56); // power control
    lcd_cmd(LCD_CONTRAST); // contrast set
    lcd_cmd(0x38); // function set (RE=0, IS=0)
    lcd_cmd(0x0F); // display on
    
    // display line mode (two line, double height)
    lcd_cmd(0x3A); // function set (RE=1)
    lcd_cmd(0x09); // extended function set
    lcd_cmd(0x1A); // double-height/bias/dot-shift
    lcd_cmd(0x3C); // function set (RE=0)

    lcd_clear();
}

void lcd_set_cursor(char x, char y) {
    char command = (0x20 * y + x) | 0b10000000;
    lcd_cmd(command);
}

void lcd_print_char(char character) {
    char data[] = {0x64, character};
    i2c_write_blocking(I2C_PORT, LCDaddress, data, 2, false);
}

void lcd_print_str(const char * str) {
    int num = 0;
    while(*str != '\0') {
        if (num == 10) {
            lcd_set_cursor(0,1);
        }
        lcd_print_char(*str);
        str++;
        num++;
    }
}

void lcd_scroll_message(const char * str) {
    while (*str != '\0') {
        lcd_clear();
        lcd_print_str(str);
        str++;
        sleep_ms(200);
    }
    lcd_clear();
}
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico_lcd.h"

#define I2C_PORT i2c1
#define I2C_SDA 18
#define I2C_SCL 19
#define LED_PIN 12

int main()
{
    // Initialize all of the present standard stdio types that are linked into the binary
    stdio_init_all(); 

    // setup LED GPIO as output
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    init_lcd();

    while (true) {
        gpio_put(LED_PIN, true);
        lcd_print_str("BLINK");
        sleep_ms(1000);
        gpio_put(LED_PIN, false);
        lcd_clear();
        sleep_ms(1000);
    }
}

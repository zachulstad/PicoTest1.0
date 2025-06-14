# Pico 2 Microcontroller Mini Project

This is a simple test project, testing both GPIO and I2C functionality on the Pico 2. The program flashes a red LED and prints “BLINK” on the LCD display then clears it at one second intervals. 

## Files
‘PicoTest1.0.c’ : The main code for the program
‘pico_lcd.c’, ‘pico_lcd.h’ : Custom LCD library for the SSD1803A LCD driver and the DOGS104-A LCD display

## Requirements
Pico SDK (VSCode)
CMake
ARM compiler

## Build Instructions
Power cycle the Pico 2 while holding the BOOTSEL button. It should show up as a disk device after the BOOTSEL process has completed. Then use the “run” button at the bottom of the screen in the VSCode pico sdk extension to flash the program onto the Pico 2. 
 

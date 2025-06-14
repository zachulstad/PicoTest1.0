{\rtf1\ansi\ansicpg1252\cocoartf2822
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red193\green193\blue193;}
{\*\expandedcolortbl;;\cssrgb\c80000\c80000\c80000;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 # Pico 2 Microcontroller Mini Project\
\
This is a simple test project, testing both GPIO and I2C functionality on the Pico 2. The program flashes a red LED and prints \'93BLINK\'94 on the LCD display then clears it at one second intervals. \
\
## Files\
\'91PicoTest1.0.c\'92 : The main code for the program\
\'91pico_lcd.c\'92, \'91pico_lcd.h\'92 : Custom LCD library for the SSD1803A LCD driver and the DOGS104-A LCD display\
\
## Requirements\
Pico SDK (VSCode)\
CMake\
ARM compiler\
\
## Build Instructions\
Power cycle the Pico 2 while holding the BOOTSEL button. It should show up as a disk device after the BOOTSEL process has completed. Then use the \'93run\'94 button at the bottom of the screen in the VSCode pico sdk extension to flash the program onto the Pico 2. 
\f1 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 \

\f0 \cf0 \kerning1\expnd0\expndtw0 \outl0\strokewidth0  \
}
# Door-Locker-security-system
Implementation of Door locker security system using two ATmega32 (AVR) microcontroller. This project is layered based architecture

## Overview
Implementing a door locker security system with a password involves combining electronic components and programming to create a secure and reliable access control mechanism,The project is designed and implemented based on the layered architecture. 
There is :-
1-HMI_ECU is just responsible interaction with the user just take inputs through keypad and display
messages on the LCD.
2-CONTROL_ECU is responsible for all the processing and decisions in the system like password checking, open the door and activate the system alarm.
Below is a general overview of the process:-
Microcontroller:- AVR ATmega32 with frequency 8Mhz.
Interface with :- LCD - Keypad - DC-Motor - EEPROM - I2C - UART - Timer1 - Buzzer



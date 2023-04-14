1. Function description
   This routine shows an external trigger interrupt to control the LED flashing

2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7_1-STB V1.0

3. Instructions for use

    SystemClock: 72MHz
    GPIO: PA5 is selected as external interrupt entry, PA9 controls LED(D3) to blink

    Test steps and phenomena:
    1. After compiling, download the program to reset and run;
    2. Press and release the KEY2 button, the LED flashes;


4. Matters needing attention
        By default, the PA9 and PA10 jumper caps of the development board are connected to the virtual serial port of NSLINK. If PA9 and PA10 are not used as serial ports in the project, and are used for other purposes, the serial port jumper caps must be unplugged.
        
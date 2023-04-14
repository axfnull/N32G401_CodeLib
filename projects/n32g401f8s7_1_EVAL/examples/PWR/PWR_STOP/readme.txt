1. Function description
    1. Enter and exit STOP0 mode.

2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7_1-STB V1.0

3. Instructions for use
    System configuration:
    1. Clock source: HSE+PLL
    2. Clock frequency: 72MHz
    3. Wake up source: PA0

    Usage:
    After compiling in KEIL, it was burned to the evaluation board, connected to the ammeter. After power on and running for a period of time, the serial debugging assistant prints "Enter STOP mode", and then the current is obviously observed to decrease, indicating that the system has entered STOP0 mode; by pressing the wake-up button (PA0), the system exits STOP0 mode, and the current meter current is observed to increase obviously, and the serial debugging assistant Print "Exit STOP mode".

4. Precautions
    When evaluating power consumption, take care to remove the LED, turn off printing and DBG_STOP mode to measure
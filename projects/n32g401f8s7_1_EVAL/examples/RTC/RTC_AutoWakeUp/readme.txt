1. Function description
    1. Trigger the wakeup interrupt when wake-up time arrived.
    2. Wake-up output

2. Use environment

    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0



3. Instructions for use

    System Configuration;
        1. RTC clock source: LSI
        2. Serial port configuration:
                            - Serial port is UART1 (TX: PA9)
                            - Data bits: 8
                            - Stop bit: 1
                            - Parity: none
                            - Baud rate: 115200


    Instructions:
        1. After compiling, burn it to the evaluation board. After power-on, the serial port will print I am in rtc_wkup every 5 seconds.

4. Attention
    The first wake-up time is inaccurate, and the subsequent wake-up time is normal, ignore first wake-up
1. Function description
    1. Initialization calendar

2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0​

3. Instructions for use

    System Configuration;
        1. RTC clock source: LSI 40kHz
        2. Serial port configuration:
                            - Serial port is UART1 (TX: PA9)
                            - Data bits: 8
                            - Stop bit: 1
                            - Parity: none
                            - Baud rate: 115200

    Instructions:
        After compiling and burning it to the evaluation board, enter debug mode and run, see RTC_TSH.SCU register, it changes onec per second.


4. Attention
    none
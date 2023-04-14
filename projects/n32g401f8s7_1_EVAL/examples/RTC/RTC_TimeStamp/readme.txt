1. Function description
    1. Trigger the timestamp through the EXTI line
    
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0​

3. Instructions for use

    System Configuration;
        1. RTC clock source: LSI  40kHz
        2. EXTI interrupt IO: PB8
        3. Serial port configuration:
                            - Serial port is UART1 (TX: PA9)
                            - Data bits: 8
                            - Stop bit: 1
                            - Parity: none
                            - Baud rate: 115200


    Instructions:
        After compiling, burn it to the evaluation board, after power-on, the serial port will print time stamp when PA4 receive rising edge. 


4. Attention
    none
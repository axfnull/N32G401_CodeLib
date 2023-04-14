1. Function description
    1. WWDG reset function.


2. Use environment

    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7_1-STB V1.0


3. Instructions for use
    
    System Configuration:
        1. WWDG clock source: APB1
        2. Window value: 6.6s < n < 16.7s
        3. Indicator light: PA1(LED1) PA7(LED2) 


    Instructions:
        1. After compiling under KEIL, burn it to the evaluation board. After power-on, the window continuously prints "Feed the dog", indicating that the window value is refreshed normally and the code is running normally.


4. Matters needing attention
   1: If you want to suspend WWDG during debugging, you need to turn on DBG_Peripheral_ON(DBG_WWDG_STOP)
   2: If you want APB1 to be 32MHz, the system clock must be 64MHz (Modify the SYSCLK_FREQ macro in the system_n32g401f8s7_1.c file.)


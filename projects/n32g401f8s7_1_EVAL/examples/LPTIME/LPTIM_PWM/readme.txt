1. Function description
    1. LPTIM output PWM signal
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    System Configuration;
        1. Clock source:
           HSE=8M,PLL=72M,AHB=72M,APB1=32M,APB2=64M,LPTIM CLK=LSI 40K
        2. Port configuration:
           PA4 selected as LPTIM output
        3. LPTIM:
           LPTIM 4-frequency LSI, output PWM signal
    Instructions:
        1. Open the debug mode after compiling, and you can observe the PWM signal of the PA4 pin
        2. Connect the PA4 pin to the LED so that you can see the LED blink.
        3. If test passes, LED1 blinks, and if it fails, LED2 blinks;
4. Matters needing attention
    none
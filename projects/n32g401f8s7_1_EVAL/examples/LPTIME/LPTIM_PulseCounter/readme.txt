1. Function description
    1. LPTIM counts the number of rising edges of IN1
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    System Configuration;
        1. Clock source:
           HSE=8M,PLL=72M,AHB=72M,APB1=32M,APB2=64M,LPTIM CLK=LSI 40K
        2. Port configuration:
           PA5 is selected as LPIME IN1 input
           PA1 is selected as IO output
        3. LPTIM:
           LPTIM external counting mode, use the internal LSI clock to continuously count the number of rising edges of IN1
    Instructions:
        1. Open the debug mode after compiling, connect PA5 and PA1, and add the variable tempCNT to the watch window
        2. After the program runs, PA1 outputs 10 pulse cycles, and tempCNT is equal to 10
        3. If test passes, LED1 blinks, and if it fails, LED2 blinks;
4. Matters needing attention
    none
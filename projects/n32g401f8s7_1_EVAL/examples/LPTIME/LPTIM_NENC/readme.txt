1. Function description
    1. LPTIM counts the number of falling edges of IN1 IN2 non-orthogonal coding
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    System Configuration;
        1. Clock source:
           HSE=8M,PLL=72M,AHB=72M,APB1=32M,APB2=64M,LPTIM CLK=LSI 40K
        2. Port configuration:
           PA5 is selected as LPIME IN1 input
           PA9 is selected as LPIME IN2 input
           PA1 is selected as IO output
           PA7 is selected as IO output
        3. LPTIM:
           LPTIM non-quadrature encoder mode, use the internal LSI clock to continuously count the number of falling edges of IN1 IN2
    Instructions:
        1. Open the debug mode after compiling, connect PA1 and PA5, PA7 and PA9, and add the variable encCNT to the watch window
        2. After the program runs, PA1 PA7 outputs 20 pulse cycles, and encCNT is equal to 20
        3. If test passes, LED1 blinks, and if it fails, LED2 blinks;
4. Matters needing attention
    none
1. Function description
     1. TIM3 TIM4 counts under TIM1 cycle
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware environment: Developed based on N32G401F8S7_1_STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=72M,AHB=72M,APB1=18M,APB2=36M,TIM1 CLK=36M,TIM3 CLK=36M,TIM4 CLK=36M
         2. Port configuration:
                     PA6 is selected as CH1 output of TIM3
                     PA7 is selected as CH1 output of TIM4
                     PA0 is selected as CH1 output of TIM1
         3. TIM:
                     TIM1 CH1 cycle triggers TIM3 TIM4 gate
     Instructions:
         1. Open the debug mode after compiling, and observe the waveforms of TIM1 CH1, TIM3 CH1, TIM4 CH1 with an oscilloscope or logic analyzer
         2. After the program runs, TIM3 15 times the period TIM1, TIM4 10 times the period TIM1
4. Matters needing attention
     without
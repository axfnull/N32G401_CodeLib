1. Function description
     1. TIM2 cycle gate TIM3, TIM3 cycle gate TIM4
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware environment: Developed based on N32G401F8S7_1_STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=72M,AHB=72M,APB1=18M,TIM2 CLK=36M,TIM3 CLK=36M,TIM4 CLK=36M
         2. Port configuration:
                     PA0 is selected as TIM2 CH1 output
                     PA6 is selected as TIM3 CH1 output
                     PA7 is selected as TIM4 CH1 output
         3. TIM:
                     The period gate of TIM2 is TIM3, the period gate of TIM3 is TIM4
     Instructions:
         1. Open the debug mode after compiling, and observe the TIM2 CH1, TIM3 CH1, TIM4 CH1 waveforms with an oscilloscope or logic analyzer
         2. TIM3 4 times the period TIM2, TIM4 4 times the period TIM3
4. Matters needing attention
     none
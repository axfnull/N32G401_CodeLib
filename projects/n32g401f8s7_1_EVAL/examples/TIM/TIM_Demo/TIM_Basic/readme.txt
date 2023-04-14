1. Function description
     1. TIM6 uses update interrupt to generate timing flip IO
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware Environment: Developed based on N32G401F8S7_1-STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                    HSE=8M,PLL=72M,AHB=72M,APB1=18M,TIM6 CLK=36M
         2. Port configuration:
                    PA5 is selected as IO output
         3. TIM:
                    TIM6 enables periodic interrupts
         4. Interrupt:
                    TIM6 update interrupt on, steal priority 0, sub priority 1
     Instructions:
         1. Open the debug mode after compiling, and observe the waveform of PA5 with an oscilloscope or logic analyzer
         2. After the program runs, the cycle of TIM6 is interrupted and the level of PB6 is flipped4.
Matters needing attention
     without
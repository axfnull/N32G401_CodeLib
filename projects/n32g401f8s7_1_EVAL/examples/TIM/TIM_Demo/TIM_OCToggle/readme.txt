1. Function description
    1. After TIM3 CH1 CH2 CH3 CH4 reaches the CC value, the output is flipped, and the comparison value is accumulated
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on N32G401F8S7_1_STB V1.0
3. Instructions for use
    System Configuration;
        1. Clock source:
                    HSE=8M,PLL=72M,AHB=72M,APB1=18M,TIM3 CLK=26M
        2. Interrupt:
                    TIM3 compare interrupt on, steal priority 0, sub-priority 1
        3. Port configuration:
                    PA6 is selected as CH1 output of TIM3
                    PA7 is selected as CH2 output of TIM3
                    PB1 is selected as CH4 output of TIM3
        4. TIM:
                    TIM3 configures the comparison value output of CH1 CH2 CH4 to flip, and open the comparison interrupt
    Instructions:
        1. Open the debug mode after compiling, and observe the waveforms of CH1 CH2 CH4 of TIM3 with an oscilloscope or logic analyzer
        2. Whenever the comparison value is reached, the output is flipped, and the same comparison value is added again, and the waveform duty cycle is 50%
4. Matters needing attention
    none
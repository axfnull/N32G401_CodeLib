1. Function description
     1. Change the period and duty cycle at the same time after one cycle of TIM1
2. Use environment
     Software development environment: KEIL MDK-ARM V5.34.0.0
     Hardware environment: Developed based on N32G401F8S7_1_STB V1.0
3. Instructions for use
     System Configuration;
         1. Clock source:
                     HSE=8M,PLL=72M,AHB_CLK=72M,APB2_CLK=36M,TIM1 CLK=72M,DMA CLK=72M
         2. Port configuration:
                     PA0 is selected as TIM1 CH1 output
         3. TIM:
                     TIM1 CH1 output, period trigger DMA burst transfer, load AR, REPCNT, CCDAT1 registers, change duty cycle and period and repeat counter
         4. DMA:
                     DMA1_CH5 channel normal mode transfers 3 half-word SRC_Buffer[3] variables to TIM1 DMA register
     Instructions:
         1. Open the debug mode after compiling, and observe the waveform of TIM1 CH1 with an oscilloscope or logic analyzer
         2. After the first cycle of TIM1 ends, the following waveforms are the waveforms of the change cycle and duty cycle of DMA transfer
         3. Every time you manually modify DmaAgain=1,the DMA burst transfer will be triggered.
4. Matters needing attention
     without
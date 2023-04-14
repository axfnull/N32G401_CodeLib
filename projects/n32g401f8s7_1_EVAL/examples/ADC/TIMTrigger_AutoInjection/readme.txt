1. Function description
   1. ADC samples PA0 regularly, automatically inject the analog voltage of PA1 pin to sample, and trigger sampling under TIM1 CC2 event
   2. The result of rule conversion is read into variable ADC_RegularConvertedValueTab[10] array through DMA_CH1 channel
       End into the transformation results by transforming the interrupt read into variable ADC_InjectedConvertedValueTab [10] array
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    System configuration:
       1. Clock source:
              HSE=8M,PLL=72M,AHB=72M,APB1=18M,APB2=36M,ADC CLK=72M/16,ADC 1M CLK=HSE/8,TIM1 CLK = 72M
       2. Interruption:
              ADC injection conversion results complete interrupt open, the priority group 2, preemption priority 0, sub priority 0
              Interrupt function will be injected into the result read ADC_InjectedConvertedValueTab [10] array, and flip PA6 level
       3. Port Configuration:
              PA0 is selected as the analog function ADC conversion channel
              PA1 is selected as the analog function ADC conversion channel
              PA6 is selected as general I/O output
              PA7 is selected as TIM1 CH4 PWM output
              PA9 is selected as TIM1 CH2 PWM output
       4. DMA:
              DMA_CH1 channel loopback mode carries the 10 half-word ADC1 regular channel conversion results into the ADC_RegularConvertedValueTab[10] array
       5. ADC:
              ADC TIM1 CC2 triggered, 12-bit data right aligned, regular conversion channel PA0, automatic injection of conversion channel PA1 analog voltage data
       6. TIM:
              TIM1 turns on the CH4 CH2 output, and CH2 is also used to trigger the ADC conversion
    Usage:
       1. compiled to open the debug mode, variable ADC_RegularConvertedValueTab [10], ADC_InjectedConvertedValueTab [10] added to the watch window
       2. By changing the voltage of PA0 PA1 pin, the rule and injection channel are converted once for each CC2 event, and the variables are stored in the corresponding array. 
           Meanwhile, PWM waveforms of TIM1, CH4 and CH2 can be seen in PA7, PA9.
4. Precautions
       1.When the system uses the HSE clock (HSI is also normally turned on), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, 
         RCC_ADC1MCLK_DIV8)can be configured as HSE or HSI.
       2.When the system samples the HSI clock (generally, HSE is disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, 
         RCC_ADC1MCLK_DIV8) can only be set to HSI.
       3.The HSE used on the development board is 8M. If other values are used, please make sure that the timing clock is 1M after frequency division.
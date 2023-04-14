1. Function description
    1. ADC regular channel samples the analog voltage of pins PA3 and PA4, and injection channel samples the analog voltage of pins PA0 and PA1
    2. The result of rule conversion is read into variable ADC_RegularConvertedValueTab[10] array through DMA_CH1 channel
        End into the transformation results by transforming the interrupt read into variable ADC_InjectedConvertedValueTab [10] array
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    System configuration£º
       1. Clock source:
              HSE=8M,PLL=72M,AHB=72M,APB1=18M,APB2=36M,ADC CLK=72M/16,ADC 1M CLK=HSE/8
       2. Interruption:
              ADC injection conversion results complete interrupt open, the priority group 2, preemption priority 0, sub priority 0
              Interrupt handling receiving injection conversion results to ADC_InjectedConvertedValueTab [10] array
       3. Port Configuration:
              PA3 is selected as the analog function ADC regular conversion channel
              PA4 is selected as the analog function ADC regular conversion channel
              PA0 is selected as the analog function ADC injection conversion channel
              PA1 is selected as the analog function ADC injection conversion channel
              PA5 is selected as an external EXTI event rising edge trigger
              PA6 is selected as an external EXTI event rising edge trigger
       4. DMA:
              DMA_CH1 channel loopback mode carries the 10 half-word ADC1 regular channel conversion results into the ADC_RegularConvertedValueTab[10] array
       5. ADC:
              ADC regular channel scan intermittent mode, EXTI5 trigger, 12 bit data right alignment, conversion channel PA3 and PA4 analog voltage data
              ADC injection channel scan mode, EXTI6 trigger, 12 bit data right alignment, conversion channel PA0 and PA1 analog voltage data
    Usage:
      1, compiled to open the debug mode, variable ADC_RegularConvertedValueTab [10], ADC_InjectedConvertedValueTab [10] added to the watch window
      2. Regular channel data sampling can be triggered by PA5 rising edge, and injection channel data sampling can be triggered by PA6 rising edge
4. Precautions
       1.When the system uses the HSE clock (HSI is also normally turned on), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, 
         RCC_ADC1MCLK_DIV8)can be configured as HSE or HSI.
       2.When the system samples the HSI clock (generally, HSE is disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, 
         RCC_ADC1MCLK_DIV8) can only be set to HSI.
       3.The HSE used on the development board is 8M. If other values are used, please make sure that the timing clock is 1M after frequency division.
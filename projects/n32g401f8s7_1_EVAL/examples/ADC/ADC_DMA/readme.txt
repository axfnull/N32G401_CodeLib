1. Function description
    1. ADC samples and converts the analog voltage of PA0 pin
    2. ADC conversion results are read to variable ADCConvertedValue through DMA_CH1 channel
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
System configuration:
       1. Clock source:
              HSE=8M,PLL=72M,AHB=72M,APB1=18M,APB2=36M,ADC CLK=72M/16,ADC 1M CLK=HSE/8
       2. Port Configuration:
              PA0 is selected as the analog function ADC conversion channel 1
       3. the DMA:
              DMA_CH1 channel loopback mode carries a half-word ADC conversion result to the ADCConvertedValue variable
       4. the ADC:
              ADC continuous conversion, software trigger, 12 bit data right aligned, conversion channel 1 is PA0 analog voltage data
    Usage:
       1. After compiling, open the debugging mode and add the variable ADCConvertedValue to the Watch window 
           for observation.
       2. By changing the voltage of the PA0 pin, you can see that the conversion result variable changes synchronously
4. Precautions
       1.When the system uses the HSE clock (HSI is also normally turned on), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, 
         RCC_ADC1MCLK_DIV8)can be configured as HSE or HSI.
       2.When the system samples the HSI clock (generally, HSE is disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, 
         RCC_ADC1MCLK_DIV8) can only be set to HSI.
       3.The HSE used on the development board is 8M. If other values are used, please make sure that the timing clock is 1M after frequency division.
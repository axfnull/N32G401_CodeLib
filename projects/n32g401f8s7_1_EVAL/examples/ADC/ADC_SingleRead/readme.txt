1. Function description
    1. ADC sampling converts the analog voltage of PA0 PA1 pin
    2. Use the software to trigger once and collect once
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    System configuration:
       1. Clock source:
              HSE=8M,PLL=72M,AHB=72M,APB1=18M,APB2=36M,ADC CLK=72M/16,ADC 1M CLK=HSE/8 
       2. Port Configuration:
              PA0 is selected as the analog function ADC conversion channel 1
              PA1 is selected as the analog function ADC conversion channel 2
       3. the ADC:
             ADC software triggers conversion, right-aligned 12-bit data, and converts analog voltage data of PA0 PA1
    Usage:
       1. Open the debugging mode after compilation, and add the variable ADCConvertedValue to the Watch window for observation
       2. By changing the voltage of PA0 PA1 pin, it can be seen that the conversion result variable changes synchronously
4. Precautions
       1.When the system uses the HSE clock (HSI is also normally turned on), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, 
         RCC_ADC1MCLK_DIV8)can be configured as HSE or HSI.
       2.When the system samples the HSI clock (generally, HSE is disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, 
         RCC_ADC1MCLK_DIV8) can only be set to HSI.
       3.The HSE used on the development board is 8M. If other values are used, please make sure that the timing clock is 1M after frequency division.
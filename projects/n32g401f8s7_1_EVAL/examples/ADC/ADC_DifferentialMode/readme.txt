1. Function description
    This example describes how to configure and use the ADC to convert an external analog input in Differential Mode, 
	difference between external voltage on VinN and VinP.
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    System configuration:
       1. Clock source:
              HSE=8M,PLL=72M,AHB=72M,APB1=18M,APB2=36M,ADC CLK=72M/16,ADC 1M CLK=HSE/8
       2. Port Configuration:
              PA0 is selected as the analog function ADC VinP,PA1 is selected as the analog function ADC VinN.
       3. the ADC:
              ADC continuous conversion, different mode, software trigger, 12 bit data right aligned.
    Usage:
       1. After compiling, open the debugging mode and add the variable "VINP_VINN_Value" to the Watch window 
           for observation.
       2. User can connect ADC_CHANNEL_1 pins (PA0, PA1) to external power supply  and vary voltage
           between -3V3 to 3V3.
       3. By changing the voltage of the PA0,PA1 pin, you can see that the conversion result variable "VINP_VINN_Value" changes synchronously.
4. Precautions
       When the system uses the HSE clock (HSI is also normally turned on), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, 
       RCC_ADC1MCLK_DIV8)can be configured as HSE or HSI.
       When the system samples the HSI clock (generally, HSE is disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, 
       RCC_ADC1MCLK_DIV8) can only be set to HSI.
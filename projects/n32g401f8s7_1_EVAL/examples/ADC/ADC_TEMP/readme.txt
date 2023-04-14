1. Function description
    1. ADC samples and converts the analog voltage of the internal temperature sensor to the temperature value
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    System configuration:
        1. Clock source:
            HSE=8M,PLL=72M,AHB=72M,APB1=18M,APB2=36M,ADC CLK=72M/16,ADC 1M CLK=HSE/8
        2. DMA:
            DMA_CH1 channel loopback mode carries a half-word ADC conversion result to the ADCConvertedValue variable
        3. ADC:
            ADC continuous conversion, software triggered, 12 bit data right aligned, conversion channel 17 is the analog
            voltage data of the internal temperature sensor
        4. Port Configuration:
            PA9 selects the TX pin of UART1
            PA10 selects the RX pin for UART1
        5.USART:
           UART1 115200 Baud rate, 8 data bits, 1 Stop bit, no parity bit, no hardware flow control, send and receive enabled
        6.Functions:
            TempValue = TempCal(ADCConvertedValue):The temperature ADC function converts the raw format data into degrees
    Usage:
        1. compiled to open the debug mode, variable ADCConvertedValue, TempValue added to the watch window to observe
        2. Connect the serial port tool to the PA9 pin and open the serial port receiver tool
        3. Running at full speed, it can be seen that the value of the temperature variable is close to 25 degrees at room temperature, 
           and the serial port tool displays the real-time temperature value in the chip.
4.Precautions
       1.When the system uses the HSE clock (HSI is also normally turned on), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSE, 
         RCC_ADC1MCLK_DIV8)can be configured as HSE or HSI.
       2.When the system samples the HSI clock (generally, HSE is disabled), RCC_ConfigAdc1mClk(RCC_ADC1MCLK_SRC_HSI, 
         RCC_ADC1MCLK_DIV8) can only be set to HSI.
       3.The HSE used on the development board is 8M. If other values are used, please make sure that the timing clock is 1M after frequency division.
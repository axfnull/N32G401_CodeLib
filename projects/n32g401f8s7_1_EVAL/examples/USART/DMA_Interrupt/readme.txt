1��Function Description 

    This test example demonstrates basic communication between USARTy and USARTz via DMA. 
    USARTy and USARTz can be UART1 and USART2. 

   First, the DMA transfers the TxBuffer1 data to the USARTy transmit data register, and then the 
   data is sent to the USARTz. USARTz uses the interrupt to receive data and store it in RxBuffer2. 

   At the same time, the DMA transfers the TxBuffer2 data to the USARTz transmit data register,
   and then the data is sent to the USARTy. USARTy receives data by querying the check flag and 
   stores it in RxBuffer1. 



2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7_1-STB V1.0



3. Instructions for use
     The system clock configuration is as follows:
     - Clock Source = HSE + PLL
     - System Clock = 72MHz 
    
 USART is configured as follows:
     - Baud rate = 115200 baud
     - Word length = 8 data bits
     - 1 stop bit 
     - checksum control disabled
     - Hardware flow control disabled (RTS and CTS signals)
     - Receiver and transmitter enable
     - DMA transmit mode enabled, DMA receive mode disabled 
    
The USART pins are connected as follows:
     - UART1_Tx.PA9 <-------> USART2_Rx.PA3
     - UART1_Rx.PA10 <-------> USART2_Tx.PA2 
    
 Test steps and phenomena:
     - Demo is compiled in KEIL environment and downloaded to MCU
     - Reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, where PASSED is the test passed and FAILED is the test abnormal 


4��Attention 
    when testing with the development board,you need to unplug the MCU_TX\MCU_RX jumper cap
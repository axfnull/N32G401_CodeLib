1. Function description

    This test example demonstrates basic communication between two development boards using hardware flow control. 
    First, Master uses CTS to send TxBuffer1 data, Slave uses RTS to receive data and store in Slave RxBuffer1; 
    Then, Slave uses CTS to send TxBuffer2 data, Master use RTS to receive data and store it in Master RxBuffer1.
    Then, compare the received data with the sent data, and store the comparison results in the variable TransferStatus1.

2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7_1-STB V1.0



3. Instructions for use
    The system clock configuration is as follows:
    - Clock Source = HSE + PLL
    - System Clock = 72MHz
    
    USARTy is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 8 data bits
    - 1 stop bit
    - checksum control disabled
    - CTS hardware flow control enabled
    - Transmitter enable
    
    USARTz is configured as follows:
    - Baud rate = 115200 baud
    - Word length = 8 data bits
    - 1 stop bit
    - checksum control disabled
    - RTS hardware flow control enabled
    - Receiver enable
    
    
    The USART pins are connected as follows:
          Master                   Slave
    - USART2_Tx.PA2  <-------> USART2_Rx.PA3
    - USART2_Rx.PA3  <-------> USART2_Tx.PA2
    - USART2_CTS.PA0 <-------> USART2_RTS.PA1
    - USART2_RTS.PA1 <-------> USART2_CTS.PA0

    
    Test steps and phenomena:
    - Demo is compiled in KEIL environment and downloaded to MCU
    - Need two development boards to test, respectively burn HardwareFlowCtrl_Master and HardwareFlowCtrl_Slave project, enter debugging state,
    - Burn HardwareFlowCtrl_Slave project development board first run code. Then run the development board that burns the HardwareFlowCtrl_Mater project and check that the value of TransferStatus1 is PASSED

4. Attention
    The two development boards need to share GND
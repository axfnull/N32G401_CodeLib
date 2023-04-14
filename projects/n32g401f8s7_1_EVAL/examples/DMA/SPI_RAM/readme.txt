1. Function description
    This routine provides a DMA usage for transferring data between peripherals and RAM.
             
    Initialize CLOCK, GPIO, PERIPH, then enable DMA function of SPI, and then DMA

    First DMA_CH5 transfers data from Slave_Tx_Buffer to the TX data register of SPI2 device, and the data stream is sent from SPI2 TX
    To SPI1 RX, DMA_CH4 transfers data from the RX register of SPI1 to master_rx_buffer.

    At the same time, DMA_CH3 transfers data from Master_Tx_Buffer to the TX data register of SPI1 device,and the data stream is sent from SPI1 TX
    To SPI2 RX, DMA_CH2 transfers data from SPI2's RX register to Slave_rx_Buffer.
    Wait for the DMA transfer to complete,
    Compare data consistency between Slave_Rx_Buffer and Master_Tx_Buffer, Compare Master_Rx_Buffer and Slave_Tx_Buffer.

2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7_1-STB V1.0

3. Instructions for use
    1. Clock source: HSE+PLL
    2. Master clock: 72MHz
    3. DMA channels: DMA_CH2, DMA_CH3, DMA_CH4, DMA_CH5
    4. SPI1 configuration:
        NSS   -->  PA1           AF_PP
        SCK   -->  PA5           AF_PP
        MISO  -->  PA6           AF_PP
        MOSI  -->  PA7           AF_PP
        Full duplex
        Main mode
        8 bit transmission
        Polarity: start at low/second edge
        Piece of software to choose
        Big end in front MSB

    5. SPI2 Configuration:
        NSS   -->  PA4          AF_PP
        SCK   -->  PA10          AF_PP
        MISO  -->  PA9          AF_PP
        MOSI  -->  PB1          AF_PP
        Full duplex
        From the pattern
        8 bit transmission
        Polarity: start at low/second edge
        Piece of software to choose
        Big end in front MSB

    6. Test steps and phenomena
        A. Compile the code and run it in debug mode.
        B. Open the Watch window and check the values of TransferStatus1 and TransferStatus2. Values like PASSED (1) indicate success, and FAILED (0) indicate error.
        
4. Precautions
    None

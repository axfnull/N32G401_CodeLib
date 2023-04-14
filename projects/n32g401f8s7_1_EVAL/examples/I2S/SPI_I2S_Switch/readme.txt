1. Function description
    1. SPI sends and receives data for CRC check
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    /* Describe related module configuration methods; for example: clock, I/O, etc. */
    1、SystemClock：72MHz
    2.GPIO：I2S1: WS--PA1  <--> I2S2: WS--PA4
            I2S1: SK--PA5  <--> I2S2: SK--PA10
            I2S1: MCK--PA6 <--> I2S2: MCK--PA9
            I2S1: SD--PA7  <--> I2S2: SD--PB1
    /* Describe the test steps and phenomena of the Demo */
    1. Disconnect the MCU_RX jumper
    2. After compiling, download the program to reset and run;
    3. SPI1 and SPI2 send and receive data at the same time. After the transmission is completed, send the CRC data, 
       check the data and CRC value, check that the status of TransferStatus1 and TransferStatus2 is PASSED, and then check the CRC value;
    4.If test passes, LED1 blinks, and if it fails, LED2 blinks;
4. Matters needing attention
    none
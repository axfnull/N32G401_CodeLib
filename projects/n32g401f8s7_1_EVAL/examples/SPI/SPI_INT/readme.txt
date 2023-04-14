1. Function description
    1. SPI uses interrupt to send and receive data in single mode.
2. Use environment
    Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-STB V1.0
3. Instructions for use
    /* Describe related module configuration methods; for example: clock, I/O, etc. */
    1、SystemClock：72MHz
    2、GPIO：SPI1: NSS--PA1  <--> SPI2: NSS--PA4
             SPI1: SCK--PA5  <--> SPI2: SCK--PA10
             SPI1: MOSI--PA7 <--> SPI2: MISO--PA9
    /* Describe the test steps and phenomena of the Demo */
    1. Disconnect the MCU_RX jumper
    2. After compiling, download the program to reset and run;
    3. SPI1 uses interrupt to send data, SPI2 uses interrupt to receive data, after the transmission is completed,
       compare the sent and received data.If test passes, LED1 blinks, and if it fails, LED2 blinks;
4. Matters needing attention
     The "single wire" data lines are MOSI pins on the master side and MISO pins on the slave side
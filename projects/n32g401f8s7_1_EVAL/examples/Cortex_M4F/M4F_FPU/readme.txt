1. Function description
	/* A brief description of the engineering function */
    This routine configures and demonstrates the FPU floating point arithmetic unit

2. Use environment
	Software development environment: KEIL MDK-ARM V5.34.0.0
    Hardware environment: Developed based on the evaluation board N32G401F8S7-1-C8L7-STB V1.0

3. Instructions for use
	/* Describe the related module configuration method; For example: clock, I/O, etc. */
    SystemClock: 72 MHZ
    USART: TX-PA9, RX-PA10, baud rate 115200
	/* Describes the test steps and symptoms of Demo */
    1. Reset and run the downloaded program after compilation;
    2. Use the Julia set to test the FPU, view the printed information, and compare the calculation time of opening or closing the FPU unit.

4. Precautions
	None
1、功能说明

	/* 简单描述工程功能 */
        这个例程配置并演示开启FLASH读保护L1


2、使用环境

	/* 硬件环境：工程对应的开发硬件平台 */
        开发板：N32G401F8S7-1-C8L7-STB V1.0


3、使用说明
	
	/* 描述相关模块配置方法；例如:时钟，I/O等 */
        SystemClock：72MHz

        USART：TX - PA9，RX - PA10，波特率115200

	/* 描述Demo的测试步骤和现象 */
        1.编译后下载程序复位运行；
        2.程序执行读保护使能，程序复位，flash进入读保护L1状态，通过打印信息观察到上述现象则测试通过；


4、注意事项



1. Function description
	/* A brief description of the engineering function */
	This routine configures and demonstrates enabling FLASH read protection L1

2. Use environment
	/* Hardware environment: the corresponding development hardware platform */
	Development board: N32G401F8S7-1-C8L7-STB V1.0
        
3. Instructions for use
    
	/* Describe the related module configuration method; For example: clock, I/O, etc. */
	SystemClock: 72 MHZ
	USART: TX-PA9, RX-PA10, baud rate 115200

	/* Describes the test steps and symptoms of Demo */
	1. Reset and run the downloaded program after compilation;
	2. Program execution read protection enable, program reset, flash into the read protection L1 state, through the print information to observe the above phenomenon then the test passed.

4. Matters needing attention
1������˵��

	/* ���������̹��� */
        ����������ò���ʾ����FLASH������L1


2��ʹ�û���

	/* Ӳ�����������̶�Ӧ�Ŀ���Ӳ��ƽ̨ */
        �����壺N32G401F8S7-1-C8L7-STB V1.0


3��ʹ��˵��
	
	/* �������ģ�����÷���������:ʱ�ӣ�I/O�� */
        SystemClock��72MHz

        USART��TX - PA9��RX - PA10��������115200

	/* ����Demo�Ĳ��Բ�������� */
        1.��������س���λ���У�
        2.����ִ�ж�����ʹ�ܣ�����λ��flash���������L1״̬��ͨ����ӡ��Ϣ�۲쵽�������������ͨ����


4��ע������



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
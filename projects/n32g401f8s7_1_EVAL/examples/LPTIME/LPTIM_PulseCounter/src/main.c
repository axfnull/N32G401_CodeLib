/**
*     Copyright (c) 2022, Nations Technologies Inc.
* 
*     All rights reserved.
*
*     This software is the exclusive property of Nations Technologies Inc. (Hereinafter 
* referred to as NATIONS). This software, and the product of NATIONS described herein 
* (Hereinafter referred to as the Product) are owned by NATIONS under the laws and treaties
* of the People's Republic of China and other applicable jurisdictions worldwide.
*
*     NATIONS does not grant any license under its patents, copyrights, trademarks, or other 
* intellectual property rights. Names and brands of third party may be mentioned or referred 
* thereto (if any) for identification purposes only.
*
*     NATIONS reserves the right to make changes, corrections, enhancements, modifications, and 
* improvements to this software at any time without notice. Please contact NATIONS and obtain 
* the latest version of this software before placing orders.

*     Although NATIONS has attempted to provide accurate and reliable information, NATIONS assumes 
* no responsibility for the accuracy and reliability of this software.
* 
*     It is the responsibility of the user of this software to properly design, program, and test 
* the functionality and safety of any application made of this information and any resulting product. 
* In no event shall NATIONS be liable for any direct, indirect, incidental, special,exemplary, or 
* consequential damages arising in any way out of the use of this software or the Product.
*
*     NATIONS Products are neither intended nor warranted for usage in systems or equipment, any
* malfunction or failure of which may cause loss of human life, bodily injury or severe property 
* damage. Such applications are deemed, "Insecure Usage".
*
*     All Insecure Usage shall be made at user's risk. User shall indemnify NATIONS and hold NATIONS 
* harmless from and against all claims, costs, damages, and other liabilities, arising from or related 
* to any customer's Insecure Usage.

*     Any express or implied warranty with regard to this software or the Product, including,but not 
* limited to, the warranties of merchantability, fitness for a particular purpose and non-infringement
* are disclaimed to the fullest extent permitted by law.

*     Unless otherwise explicitly permitted by NATIONS, anyone may not duplicate, modify, transcribe
* or otherwise distribute this software for any purposes, in whole or in part.
*
*     NATIONS products and technologies shall not be used for or incorporated into any products or systems
* whose manufacture, use, or sale is prohibited under any applicable domestic or foreign laws or regulations. 
* User shall comply with any applicable export control laws and regulations promulgated and administered by 
* the governments of any countries asserting jurisdiction over the parties or transactions.
**/

/**
*\*\file      main.c
*\*\author    Nations
*\*\version   v1.0.0
*\*\copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved. 
*/
#include "main.h"

/* LPTIM_PulseCounter */

#define COUNT_NUM        10

void LEDInit(GPIO_Module* port, uint16_t Pin);
void LedOn(GPIO_Module* port, uint16_t Pin);
void LedOff(GPIO_Module* port, uint16_t Pin);
void LedBlink(GPIO_Module* port, uint16_t Pin);
void delay(vu32 nCount);


void LPTIM_InputIoInit(void);
void PWM_Out(uint16_t Pin,uint8_t cnt);
uint16_t tempCNT;
/* Main program. */
int main(void)
{
    /* At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       file (startup_n32g401f8s7_1.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_n32g401f8s7_1.c file
     */
    /* Init log */
    log_init();
    log_info("This is LPTIM pulse encoder mode demo\r\n");
    /* Init LED GPIO */
    LEDInit(LED1_GPIO, LED1);
    LEDInit(LED1_GPIO, LED2);
    /* Enable the LSI source */
    RCC_LPTIM_Enable();
    RCC_LSI_Enable();
	while(RCC_LSI_Stable_Wait() != SUCCESS);
    RCC_LPTIM_Clock_Config(RCC_LPTIMCLK_SRC_LSI);

    /* LPTIM input1 IO Init and encoder*/
    LPTIM_Prescaler_Set(LPTIM,LPTIM_PRESCALER_DIV1);
    LPTIM_InputIoInit();
  
    //PWR_EnterSTOP2Mode(PWR_STOPENTRY_WFI);
    /* config timer    CKSEL:0  COUNTMODE:1 */  
    LPTIM_Counter_Mode_Set(LPTIM,LPTIM_COUNTER_MODE_EXTERNAL);
    /* config the rising polarity */
    LPTIM_Clock_Config(LPTIM,LPTIM_CLK_FILTER_NONE,LPTIM_CLK_POLARITY_RISING);
    LPTIM_ON(LPTIM); 
    LPTIM_Auto_Reload_Set(LPTIM,60000);  
    LPTIM_Counter_Start(LPTIM,LPTIM_OPERATING_MODE_CONTINUOUS);  //start with the continue mode
    /* Great 10 square waves ,and tempCNT should be equal to 10*/
    delay(10);
    PWM_Out(LED1,COUNT_NUM);
    tempCNT = LPTIM->CNT;
    if(tempCNT == COUNT_NUM)
    {
        while(1)
        {
            LedBlink(LED1_GPIO, LED1);
            delay(20);
        }
    }
    else
    {
        while(1)
        {
            LedBlink(LED2_GPIO, LED2);
            delay(20);
        }
    }
}

/**
*\*\name    LPTIM_InputIoInit.
*\*\fun     encode input IO Initaliza.
*\*\param   none
*\*\return  none
**/
void LPTIM_InputIoInit(void)
{
    GPIO_InitType GPIO_InitStructure;
    GPIO_Structure_Initialize(&GPIO_InitStructure);
    /* Enable the GPIO Clock */
    RCC_AHB_Peripheral_Clock_Enable(RCC_AHB_PERIPH_GPIOA);

    /* Configure the GPIO pin */
    GPIO_InitStructure.Pin        = GPIO_PIN_5;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_INPUT;
    GPIO_InitStructure.GPIO_Alternate =  GPIO_AF12_LPTIM;
    GPIO_Peripheral_Initialize(GPIOA, &GPIO_InitStructure);
}

/**
*\*\name    Lptim_EncInit.
*\*\fun     encode module Initaliza.
*\*\param   none
*\*\return  none
**/
void Lptim_EncInit(void)
{
    /* config LPTIM */
    LPTIM_Clock_Source_Set(LPTIM,LPTIM_CLK_SOURCE_INTERNAL);
    LPTIM->CFG &=~(LPTIM_CFG_NENC|LPTIM_CFG_ENC);
    LPTIM_Encoder_Mode_Enable(LPTIM);
    /* ENC MODE1 */
    LPTIM_Encoder_Mode_Set(LPTIM,LPTIM_ENCODER_MODE_RISING);

    LPTIM_ON(LPTIM);
    LPTIM_Auto_Reload_Set(LPTIM,15000);
    LPTIM_Compare_Set(LPTIM,10000);    
}

/**
*\*\name    LedOn.
*\*\fun     Turns selected Led on.
*\*\return  none
**/
void LedOn(GPIO_Module* port, uint16_t Pin)
{
    port->PBC = Pin;
}
/**
*\*\name    LedOff.
*\*\fun     Turns selected Led Off.
*\*\return  none
**/
void LedOff(GPIO_Module* port, uint16_t Pin)
{
    port->PBSC = Pin;
}


/**
*\*\name    LED Init.
*\*\fun     Configures LED GPIO.
*\*\return  none
**/
void LEDInit(GPIO_Module* port, uint16_t pin)
{
    GPIO_InitType GPIO_InitStructure;
    GPIO_Structure_Initialize(&GPIO_InitStructure);
    /* Enable the GPIO_LED Clock */
    if(pin == LED3 && port == LED3_GPIO)
    {
        RCC_AHB_Peripheral_Clock_Enable(RCC_AHB_PERIPH_GPIOB);
    }
    else
    {
        RCC_AHB_Peripheral_Clock_Enable(RCC_AHB_PERIPH_GPIOA);
    }
    /* Configure the GPIO_LED pin */
    GPIO_InitStructure.Pin        = pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_OUT_PP;
    GPIO_Peripheral_Initialize(port, &GPIO_InitStructure);
}

/**
*\*\name    LedBlink.
*\*\fun     Toggles the selected Led.
*\*\return  none
**/
void LedBlink(GPIO_Module* port, uint16_t pin)
{
    port->POD ^= pin;
}

/**
*\*\name    delay.
*\*\fun     Delay by counting .
*\*\param   nCount
*\*\return  none
**/
void delay(vu32 nCount)
{
    vu32 index = 0;
    for (index = (34000 * nCount); index != 0; index--)
    {
    }
}

/**
*\*\name    PWM_Out.
*\*\fun     Great square waves.(PA1)
*\*\param   count    the number of waves.
*\*\return  none
**/
void PWM_Out(uint16_t Pin,uint8_t cnt)
{
    uint8_t i;
    for (i = 0; i< cnt;i++)
    {
        GPIO_Pins_Set(GPIOA, Pin);
        delay(10);
        GPIO_PBSC_Pins_Reset(GPIOA, Pin);
        delay(10);
    }
}


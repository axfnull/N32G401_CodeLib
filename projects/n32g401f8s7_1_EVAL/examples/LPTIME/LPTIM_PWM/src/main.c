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

/* LPTIM_PWM */

void LedBlink(GPIO_Module* port, uint16_t Pin);
void LEDInit(GPIO_Module* port,uint16_t Pin);
void LedOn(GPIO_Module* port,uint16_t Pin);
void LedOff(GPIO_Module* port,uint16_t Pin);
void delay(vu32 nCount);
void LPTIM_OutputIoInit(void);

/* Main program. */
int main(void)
{
    /* At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       file (startup_n32g401f8s7_1.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_n32g401f8s7_1.c file
     */
    /* Init LED GPIO */
    LEDInit(LED1_GPIO, LED1);
    /* Init output IO */
    LPTIM_OutputIoInit();
    /* Enable the LSI source */
    RCC_LPTIM_Enable();
	RCC_LSI_Enable();
	while(RCC_LSI_Stable_Wait() != SUCCESS);
    RCC_LPTIM_Clock_Config(RCC_LPTIMCLK_SRC_LSI);
    LPTIM_Prescaler_Set(LPTIM,LPTIM_PRESCALER_DIV4);
    /* Init lptim module */ 
    LPTIM_Waveform_Set(LPTIM,LPTIM_OUTPUT_WAVEFORM_PWM); 
    /* output wave */ 
    LPTIM_Polarity_Set(LPTIM,LPTIM_OUTPUT_POLARITY_REGULAR);  
    /* config the prescaler */          
    LPTIM_Interrupt_Enable(LPTIM, LPTIM_INT_CMPUPDIE);

    LPTIM_ON(LPTIM);
    /* config ARR ande compare register */ 
    LPTIM_Auto_Reload_Set(LPTIM,600);
    LPTIM_Compare_Set(LPTIM,300);
    //while(!(LPTIM->INTSTS & LPTIM_INTSTS_CMPUPD));
    LPTIM_Counter_Start(LPTIM,LPTIM_OPERATING_MODE_CONTINUOUS);  
    while (1)
    {
    }
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
*\*\name    LPTIM_OutputIoInit.
*\*\fun     output IO Initaliza.
*\*\param   none
*\*\return  none
**/
void LPTIM_OutputIoInit(void)
{
    GPIO_InitType GPIO_InitStructure;
    GPIO_Structure_Initialize(&GPIO_InitStructure);

    /* Enable the GPIO Clock */
    RCC_AHB_Peripheral_Clock_Enable(RCC_AHB_PERIPH_GPIOA);

    /* Configure the GPIO pin */
    GPIO_InitStructure.Pin        = GPIO_PIN_4;
    GPIO_InitStructure.GPIO_Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructure.GPIO_Alternate = GPIO_AF12_LPTIM;
    GPIO_Peripheral_Initialize(GPIOA, &GPIO_InitStructure);
}

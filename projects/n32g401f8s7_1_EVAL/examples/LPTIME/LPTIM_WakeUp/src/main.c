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

/* LPTIM_WakeUP */

void LEDInit(GPIO_Module* port, uint16_t Pin);
void LedOn(GPIO_Module* port, uint16_t Pin);
void LedOff(GPIO_Module* port, uint16_t Pin);
void LedBlink(GPIO_Module* port, uint16_t Pin);

void delay(vu32 nCount);
void LPTIMNVIC_Config(FunctionalState Cmd);
void SYSCLKConfig(uint32_t RCC_PLLMULL);
/* Main program. */
int main(void)
{
    /* At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       file (startup_n32g401f8s7_1.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_n32g401f8s7_1.c file
     */
    /* Enable PWR Clock */
    RCC_APB1_Peripheral_Clock_Enable(RCC_APB1_PERIPH_PWR);
    /* Init LED GPIO */
    LEDInit(LED1_GPIO, LED1);
    /* Enable the LSI source */
    RCC_LPTIM_Enable();
	RCC_LSI_Enable();
	while(RCC_LSI_Stable_Wait() != SUCCESS);
	RCC_LPTIM_Clock_Config(RCC_LPTIMCLK_SRC_LSI); 
    /* Enable interrupt   */
	LPTIMNVIC_Config(ENABLE);
    LPTIM_Prescaler_Set(LPTIM,LPTIM_PRESCALER_DIV1);
    LPTIM_Interrupt_Enable(LPTIM, LPTIM_INT_CMPMIE);
    /* config lptim ARR and compare register */ 
    LPTIM_ON(LPTIM);   
    LPTIM_Auto_Reload_Set(LPTIM,65000);
    LPTIM_Compare_Set(LPTIM,60000);
    LPTIM_Counter_Start(LPTIM,LPTIM_OPERATING_MODE_CONTINUOUS);
    DBG_Peripheral_ON(DBG_STOP);
    while (1)
    {
        //PWR_SLEEP_Mode_Enter(PWR_SLEEP_NOW, PWR_SLEEP_ENTRY_WFI); 
        PWR_STOP2_Mode_Enter(PWR_STOP2_ENTRY_WFI);
        /* Enable the GPIO_LED Clock */
        RCC_AHB_Peripheral_Clock_Enable(RCC_AHB_PERIPH_GPIOA);
        LedBlink(LED1_GPIO, LED1);
        delay(30);
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
*\*\name    LPTIMNVIC_Config.
*\*\fun     LPTIM Interrupt Initaliza.
*\*\param   Cmd         enable or disable
*\*\return  none
**/
void LPTIMNVIC_Config(FunctionalState Cmd)
{
    EXTI_InitType EXTI_InitStructure;
    NVIC_InitType NVIC_InitStructure;

    EXTI_Flag_Status_Clear(EXTI_LINE20);
    EXTI_InitStructure.EXTI_Line = EXTI_LINE20;
#ifdef __TEST_SEVONPEND_WFE_NVIC_DIS__
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Event;
#else
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
#endif
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Peripheral_Initializes(&EXTI_InitStructure);

    /* Enable the RTC Alarm Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel                   = LPTIM_WKUP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = NVIC_PER_PRIORITY_1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = NVIC_SUB_PRIORITY_1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = Cmd;
    NVIC_Initializes(&NVIC_InitStructure);
}

/**
*\*\name    SYSCLKConfig.
*\*\fun     Configures system clock after wake-up from low power mode:
*\*\            enable HSE, PLL and select PLL as system clock source.
*\*\param   RCC_PLLMULL         
*\*\return  none
**/
void SYSCLKConfig(uint32_t RCC_PLLMULL)
{
    __IO uint32_t StartUpCounter = 0, HSEStartUpStatus = 0;

    /* reset RCC with the default values */
    RCC_Reset();

    RCC_HSI_Enable();
    HSEStartUpStatus = RCC_HSE_Stable_Wait();

    if (HSEStartUpStatus == SUCCESS)
    {
      /* The following two steps are required to operate flash */
      FLASH_Prefetch_Buffer_Enable();        
      FLASH_Latency_Set(FLASH_LATENCY_2);

      /* set different clock trees frequency division */
      RCC_Hclk_Config(RCC_SYSCLK_DIV1);        
      RCC_Pclk2_Config(RCC_HCLK_DIV2); 
      RCC_Pclk1_Config(RCC_HCLK_DIV4);

      /* the main frequence */
      /* set PLLclock resource from HSE and the PLL factor */
      /* PLLCLK = 8MHz * pllmul */
      RCC_PLL_Config(RCC_PLL_SRC_HSE_DIV2, RCC_PLLMULL);

      RCC_PLL_Enable();
      while (RCC_Flag_Status_Get(RCC_FLAG_PLLRD) == RESET)
      {
      }
      
      RCC_Sysclk_Config(RCC_SYSCLK_SRC_PLLCLK);
      while (RCC_Sysclk_Source_Get() != 0x0C)
      {
      }
    }
    else
    { 
        /* if HSE enable to fail ,the process will come here.Then the MCU clock resoure is HSI */
        while(1)
        {}
    }
}

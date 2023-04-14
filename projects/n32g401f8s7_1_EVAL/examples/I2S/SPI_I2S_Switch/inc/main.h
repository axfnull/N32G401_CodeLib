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
*\*\file      main.h
*\*\author    Nations
*\*\version   v1.0.0
*\*\copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved. 
*/
#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g401f8s7_1_spi.h"
#include "n32g401f8s7_1_gpio.h"
#include "n32g401f8s7_1_rcc.h"
#include "log.h"

typedef enum
{
    FAILED = 0,
    PASSED = !FAILED
} Status, TestStatus;

#define I2S_MASTER               SPI1

#define I2S_MASTER_MCK_PIN       GPIO_PIN_6
#define I2S_MASTER_MCK_GPIO      GPIOA
#define I2S_MASTER_MCK_ALTERNATE GPIO_AF1_SPI1

#define I2S_MASTER_SD_PIN        GPIO_PIN_7
#define I2S_MASTER_SD_GPIO       GPIOA
#define I2S_MASTER_SD_ALTERNATE  GPIO_AF1_SPI1
        
#define I2S_MASTER_CK_PIN        GPIO_PIN_5
#define I2S_MASTER_CK_GPIO       GPIOA
#define I2S_MASTER_CK_ALTERNATE  GPIO_AF1_SPI1
        
#define I2S_MASTER_WS_PIN        GPIO_PIN_1
#define I2S_MASTER_WS_GPIO       GPIOA
#define I2S_MASTER_WS_ALTERNATE  GPIO_AF1_SPI1

#define I2S_MASTER_DMA_TX_CH     DMA_REMAP_SPI1_TX
#define I2S_MASTER_DMA_RX_CH     DMA_REMAP_SPI1_RX

#define I2S_SLAVE                SPI2
        
#define I2S_SLAVE_MCK_PIN        GPIO_PIN_9
#define I2S_SLAVE_MCK_GPIO       GPIOA
#define I2S_SLAVE_MCK_ALTERNATE  GPIO_AF1_SPI2
        
#define I2S_SLAVE_SD_PIN         GPIO_PIN_1
#define I2S_SLAVE_SD_GPIO        GPIOB
#define I2S_SLAVE_SD_ALTERNATE   GPIO_AF2_SPI2
        
#define I2S_SLAVE_CK_PIN         GPIO_PIN_10
#define I2S_SLAVE_CK_GPIO        GPIOA
#define I2S_SLAVE_CK_ALTERNATE   GPIO_AF6_SPI2
        
#define I2S_SLAVE_WS_PIN         GPIO_PIN_4
#define I2S_SLAVE_WS_GPIO        GPIOA
#define I2S_SLAVE_WS_ALTERNATE   GPIO_AF3_SPI2


/*Led1-PA1,Led2-PA7,Led3-PB1*/

#define LED1           GPIO_PIN_1
#define LED1_GPIO      GPIOA
#define LED2           GPIO_PIN_7
#define LED2_GPIO      GPIOA
#define LED3           GPIO_PIN_1
#define LED3_GPIO      GPIOB

#define KEY1           GPIO_PIN_4 
#define KEY2           GPIO_PIN_5
#define KEY3           GPIO_PIN_6
#define KEY_INPUT_PORT GPIOA
#define KEY_INPUT_PIN  GPIO_PIN_0

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */


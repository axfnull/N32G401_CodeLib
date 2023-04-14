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
*\*\file TIM1_remap.h
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
*
*/
#ifndef _TIM1_REMAP_H_
#define _TIM1_REMAP_H_

#include "n32g401f8s7_1_gpio.h"

/** TIM1 remap **/
/* CH1 */
#define TIM1_REMAP0_CH1_PORT        GPIOA
#define TIM1_REMAP0_CH1_PIN         GPIO_PIN_0
#define TIM1_REMAP0_CH1_AF          GPIO_AF10_TIM1 
/* CH2 */
#define TIM1_REMAP0_CH2_PORT        GPIOA
#define TIM1_REMAP0_CH2_PIN         GPIO_PIN_9
#define TIM1_REMAP0_CH2_AF          GPIO_AF3_TIM1 
/* CH3 */
#define TIM1_REMAP0_CH3_PORT        GPIOA
#define TIM1_REMAP0_CH3_PIN         GPIO_PIN_10
#define TIM1_REMAP0_CH3_AF          GPIO_AF3_TIM1 
/* CH4 */
#define TIM1_REMAP0_CH4_PORT        GPIOA
#define TIM1_REMAP0_CH4_PIN         GPIO_PIN_7
#define TIM1_REMAP0_CH4_AF          GPIO_AF2_TIM1 
/* BKIN */
#define TIM1_REMAP0_BKIN_PORT       GPIOA
#define TIM1_REMAP0_BKIN_PIN        GPIO_PIN_6
#define TIM1_REMAP0_BKIN_AF         GPIO_AF6_TIM1 
/* CH1N */
#define TIM1_REMAP0_CH1N_PORT       GPIOA
#define TIM1_REMAP0_CH1N_PIN        GPIO_PIN_1
#define TIM1_REMAP0_CH1N_AF         GPIO_AF2_TIM1 
/* CH2N */
#define TIM1_REMAP0_CH2N_PORT       GPIOD
#define TIM1_REMAP0_CH2N_PIN        GPIO_PIN_15
#define TIM1_REMAP0_CH2N_AF         GPIO_AF8_TIM1 
/* CH3N */
#define TIM1_REMAP0_CH3N_PORT       GPIOD
#define TIM1_REMAP0_CH3N_PIN        GPIO_PIN_14
#define TIM1_REMAP0_CH3N_AF         GPIO_AF2_TIM1 


#endif

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
*\*\file main.c
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
**/

#include "main.h"
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE  114
#define CRC_DFE_POLY 0x8005

static const uint32_t DataBuffer[BUFFER_SIZE] = {
    0x00001021, 0x20423063, 0x408450a5, 0x60c670e7, 0x9129a14a, 0xb16bc18c, 0xd1ade1ce, 0xf1ef1231, 0x32732252,
    0x52b54294, 0x72f762d6, 0x93398318, 0xa35ad3bd, 0xc39cf3ff, 0xe3de2462, 0x34430420, 0x64e674c7, 0x44a45485,
    0xa56ab54b, 0x85289509, 0xf5cfc5ac, 0xd58d3653, 0x26721611, 0x063076d7, 0x569546b4, 0xb75ba77a, 0x97198738,
    0xf7dfe7fe, 0xc7bc48c4, 0x58e56886, 0x78a70840, 0x18612802, 0xc9ccd9ed, 0xe98ef9af, 0x89489969, 0xa90ab92b,
    0x4ad47ab7, 0x6a961a71, 0x0a503a33, 0x2a12dbfd, 0xfbbfeb9e, 0x9b798b58, 0xbb3bab1a, 0x6ca67c87, 0x5cc52c22,
    0x3c030c60, 0x1c41edae, 0xfd8fcdec, 0xad2abd0b, 0x8d689d49, 0x7e976eb6, 0x5ed54ef4, 0x2e321e51, 0x0e70ff9f,
    0xefbedfdd, 0xcffcbf1b, 0x9f598f78, 0x918881a9, 0xb1caa1eb, 0xd10cc12d, 0xe16f1080, 0x00a130c2, 0x20e35004,
    0x40257046, 0x83b99398, 0xa3fbb3da, 0xc33dd31c, 0xe37ff35e, 0x129022f3, 0x32d24235, 0x52146277, 0x7256b5ea,
    0x95a88589, 0xf56ee54f, 0xd52cc50d, 0x34e224c3, 0x04817466, 0x64475424, 0x4405a7db, 0xb7fa8799, 0xe75ff77e,
    0xc71dd73c, 0x26d336f2, 0x069116b0, 0x76764615, 0x5634d94c, 0xc96df90e, 0xe92f99c8, 0xb98aa9ab, 0x58444865,
    0x78066827, 0x18c008e1, 0x28a3cb7d, 0xdb5ceb3f, 0xfb1e8bf9, 0x9bd8abbb, 0x4a755a54, 0x6a377a16, 0x0af11ad0,
    0x2ab33a92, 0xed0fdd6c, 0xcd4dbdaa, 0xad8b9de8, 0x8dc97c26, 0x5c644c45, 0x3ca22c83, 0x1ce00cc1, 0xef1fff3e,
    0xdf7caf9b, 0xbfba8fd9, 0x9ff86e17, 0x7e364e55, 0x2e933eb2, 0x0ed11ef0};

static const uint8_t Buffer[8] = {0x7e, 0x11, 0x36, 0x4e, 0x55, 0x0a, 0xf1, 0x1a};

__IO uint32_t CRCValue   = 0;
__IO uint16_t CRC16Value = 0;

/**
*\*\name    ReverseBits.
*\*\fun     Bitwise reversal.
*\*\param   bufin
*\*\return  bufout
**/
uint8_t ReverseBits(uint8_t bufin)
{
    uint8_t bufout = 0;
    uint8_t j      = 0;
    for (j = 0; j < 4; j++)
    {
        bufout |= (bufin & (0x01 << j)) << (7 - 2 * j);   // H
        bufout |= (bufin & (0x10 << (j))) >> (2 * j + 1); // L
    }
    return bufout;
}

/**
*\*\name    GetCRC16_Software.
*\*\fun     Software calculates CRC16.
*\*\param   buf
*\*\param   len
*\*\param   initcrc
*\*\return  crc16
**/
uint16_t GetCRC16_Software(uint8_t* buf, uint32_t len, uint16_t initcrc)
{
    uint16_t crc16 = initcrc;
    uint8_t i = 0, j = 0;
    //uint8_t u=0;

    for (i = 0; i < len; i++)
    {
        //u = ReverseBits((uint8_t)buf[i]);
        crc16 ^= (uint16_t)(buf[i] << 8);
        for (j = 0; j < 8; j++)
        {
            if ((crc16 & 0x8000) > 0)
            {
                crc16 = (uint16_t)((crc16 << 1) ^ CRC_DFE_POLY);
            }
            else
            {
                crc16 <<= 1;
            }
        }
    }
    return crc16;
}

/**
*\*\name    main.
*\*\fun     Main program.
*\*\param   none
*\*\return  none
**/
int main(void)
{
    /* Enable CRC clock */
    RCC_AHB_Peripheral_Clock_Enable(RCC_AHB_PERIPH_CRC);

    /* Compute the 32bit CRC of "DataBuffer" */
    CRCValue = CRC32_Buffer_Calculate((uint32_t*)DataBuffer, BUFFER_SIZE);

    /* Compute the 16bit CRC of an array */
    CRC16Value = CRC16_Buffer_Calculate((uint8_t*)Buffer, 8);
    
    /* Compute the 16bit CRC of an array by software*/
    CRCValue   = GetCRC16_Software((uint8_t*)Buffer, 8, 0x00);

    while (1)
    {
    }
}

/**
*\*\name    Delay.
*\*\fun     Inserts a delay time.
*\*\param   nCount
*\*\return  none
**/
void Delay(__IO uint32_t nCount)
{
    for (; nCount != 0; nCount--)
        ;
}


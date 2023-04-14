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
*\*\file n32g401f8s7_1_dma.c
*\*\author Nations
*\*\version v1.0.0
*\*\copyright Copyright (c) 2022, Nations Technologies Inc. All rights reserved.
**/

#include "n32g401f8s7_1_dma.h"

/** DMA Private Defines **/

/** DMA Driving Functions Declaration **/

/**
*\*\name    DMA_Reset.
*\*\fun     Reset CHCFG, TXNUM, PADDR, MADDR, INTCLR registers of DMA Channel x
*\*\        to their default reset values.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\return  none
**/
void DMA_Reset(DMA_ChannelType* DMAChx)
{
    /* Disable the selected DMA Channelx */
    DMAChx->CHCFG &= ~DMA_CHANNEL_ENABLE;

    /* Reset DMA Channelx configuration register */
    DMAChx->CHCFG = DMA_REG_BIT_FIELD_MASK;

    /* Reset DMA Channelx remaining bytes register */
    DMAChx->TXNUM = DMA_REG_BIT_FIELD_MASK;

    /* Reset DMA Channelx peripheral address register */
    DMAChx->PADDR = DMA_REG_BIT_FIELD_MASK;

    /* Reset DMA Channelx memory address register */
    DMAChx->MADDR = DMA_REG_BIT_FIELD_MASK;
    
    if (DMAChx == DMA_CH1)
    {
        /* Clear all interrupt status bits for DMA Channel1 */
        DMA->INTCLR |= DMA_CH1_INT_MASK;
    }
    else if (DMAChx == DMA_CH2)
    {
        /* Clear all interrupt status bits for DMA Channel2 */
        DMA->INTCLR |= DMA_CH2_INT_MASK;
    }
    else if (DMAChx == DMA_CH3)
    {
        /* Clear all interrupt status bits for DMA Channel3 */
        DMA->INTCLR |= DMA_CH3_INT_MASK;
    }
    else if (DMAChx == DMA_CH4)
    {
        /* Clear all interrupt status bits for DMA Channel4 */
        DMA->INTCLR |= DMA_CH4_INT_MASK;
    }
    else if (DMAChx == DMA_CH5)
    {
        /* Clear all interrupt status bits for DMA Channel5 */
        DMA->INTCLR |= DMA_CH5_INT_MASK;
    }
    else if (DMAChx == DMA_CH6)
    {
        /* Clear all interrupt status bits for DMA Channel6 */
        DMA->INTCLR |= DMA_CH6_INT_MASK;
    }
    else if (DMAChx == DMA_CH7)
    {
        /* Clear all interrupt status bits for DMA Channel7 */
        DMA->INTCLR |= DMA_CH7_INT_MASK;
    }
    else
    {
        if(DMAChx == DMA_CH8)
        {
            /* Clear all interrupt status bits for DMA Channel8 */
            DMA->INTCLR |= DMA_CH8_INT_MASK;
        }
    }
}

/**
*\*\name    DMA_Initializes.
*\*\fun     Initializes the DMA Channel x by the structure parameter
*\*\        DMA_InitParam of type DMA_InitType. Includes configuration
*\*\        peripheral/memory address, transmission direction, address
*\*\        increment mode, data bit width, priority, etc.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   DMA_InitParam (The input parameters must be the following values):
*\*\          - PeriphAddr
*\*\          - MemAddr
*\*\          - Direction
*\*\            - DMA_DIR_PERIPH_DST
*\*\            - DMA_DIR_PERIPH_SRC
*\*\          - BufSize
*\*\          - PeriphInc
*\*\            - DMA_PERIPH_INC_MODE_ENABLE
*\*\            - DMA_PERIPH_INC_MODE_DISABLE
*\*\          - MemoryInc
*\*\            - DMA_MEM_INC_MODE_ENABLE
*\*\            - DMA_MEM_INC_MODE_DISABLE
*\*\          - PeriphDataSize
*\*\            - DMA_PERIPH_DATA_WIDTH_BYTE
*\*\            - DMA_PERIPH_DATA_WIDTH_HALFWORD
*\*\            - DMA_PERIPH_DATA_WIDTH_WORD
*\*\          - MemDataSize
*\*\            - DMA_MEM_DATA_WIDTH_BYTE
*\*\            - DMA_MEM_DATA_WIDTH_HALFWORD
*\*\            - DMA_MEM_DATA_WIDTH_WORD
*\*\          - CircularMode
*\*\            - DMA_CIRCULAR_MODE_ENABLE
*\*\            - DMA_CIRCULAR_MODE_DISABLE
*\*\          - Priority
*\*\            - DMA_CH_PRIORITY_HIGHEST
*\*\            - DMA_CH_PRIORITY_HIGH
*\*\            - DMA_CH_PRIORITY_MEDIUM
*\*\            - DMA_CH_PRIORITY_LOW
*\*\          - Mem2Mem
*\*\            - DMA_MEM2MEM_ENABLE
*\*\            - DMA_MEM2MEM_DISABLE
*\*\return  none
**/
void DMA_Initializes(DMA_ChannelType* DMAChx, DMA_InitType* DMA_InitParam)
{
    DMA_Destination_Config(DMAChx, DMA_InitParam->Direction);
    DMA_Peripheral_Address_Config(DMAChx, DMA_InitParam->PeriphAddr);
    DMA_Memory_Address_Config(DMAChx, DMA_InitParam->MemAddr);
    DMA_Priority_Config(DMAChx, DMA_InitParam->Priority);
    DMA_Peripheral_Addr_Increment_Config(DMAChx, DMA_InitParam->PeriphInc);
    DMA_Memory_Addr_Increment_Config(DMAChx, DMA_InitParam->MemoryInc);
    DMA_Buffer_Size_Config(DMAChx, DMA_InitParam->BufSize);
    DMA_Peripheral_Data_Width_Config(DMAChx, DMA_InitParam->PeriphDataSize);
    DMA_Memory_Data_Width_Config(DMAChx, DMA_InitParam->MemDataSize);
    DMA_Circular_Mode_Config(DMAChx, DMA_InitParam->CircularMode);
    DMA_Memory_2_Memory_Config(DMAChx, DMA_InitParam->Mem2Mem);
}

/**
*\*\name    DMA_Peripheral_Address_Config.
*\*\fun     Configure the peripheral address for DMA Channel x. Called in
*\*\        the function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   addr :
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
**/
void DMA_Peripheral_Address_Config(DMA_ChannelType* DMAChx, uint32_t addr)
{
    /* Write to DMA Channelx PADDR */
    DMAChx->PADDR = addr;
}

/**
*\*\name    DMA_Memory_Address_Config.
*\*\fun     Configure the memory address for DMA Channel x. Called in the
*\*\        function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   addr :
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
**/
void DMA_Memory_Address_Config(DMA_ChannelType* DMAChx, uint32_t addr)
{
    /* Write to DMA Channelx MADDR */
    DMAChx->MADDR = addr;
}

/**
*\*\name    DMA_Destination_Config.
*\*\fun     Configure the transfer direction for DMA Channel x. Called in
*\*\        the function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   direction (The input parameters must be the following values):
*\*\          - DMA_DIR_PERIPH_DST
*\*\          - DMA_DIR_PERIPH_SRC
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
*\*\        After the channel x is enabled, bits [31:1] of the CHCFG register
*\*\        cannot be modified.
**/
void DMA_Destination_Config(DMA_ChannelType* DMAChx, uint32_t direction)
{
    uint32_t temp_value = 0;
    
    /* Get DMAChx_CHCFG register value */
    temp_value = DMAChx->CHCFG;
    /* Clear DIR bit */
    temp_value &= DMA_DIR_PERIPH_MASK;
    /* Set DIR bit */
    temp_value |= direction;
    /* Update DMAChx_CHCFG register */
    DMAChx->CHCFG = temp_value;
}

/**
*\*\name    DMA_Buffer_Size_Config.
*\*\fun     Configure the data transfer size for DMA Channel x. Called in the
*\*\        function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   buf_size :
*\*\          - 1~0xFFFF
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
**/
void DMA_Buffer_Size_Config(DMA_ChannelType* DMAChx, uint32_t buf_size)
{
    /* Write to DMA Channelx TXNUM */
    DMAChx->TXNUM = buf_size;
}

/**
*\*\name    DMA_Peripheral_Addr_Increment_Config.
*\*\fun     Enable/disable peripheral address increment mode for DMA Channel x.
*\*\        Called in the function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   periph_inc (The input parameters must be the following values):
*\*\          - DMA_PERIPH_INC_MODE_ENABLE
*\*\          - DMA_PERIPH_INC_MODE_DISABLE
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
*\*\        After the channel x is enabled, bits [31:1] of the CHCFG register
*\*\        cannot be modified.
**/
void DMA_Peripheral_Addr_Increment_Config(DMA_ChannelType* DMAChx, uint32_t periph_inc)
{
    uint32_t temp_value = 0;
    
    /* Get DMAChx_CHCFG register value */
    temp_value = DMAChx->CHCFG;
    /* Clear PINC bit */
    temp_value &= DMA_PERIPH_INC_MODE_MASK;
    /* Set PINC bit */
    temp_value |= periph_inc;
    /* Update DMAChx_CHCFG register */
    DMAChx->CHCFG = temp_value;
}

/**
*\*\name    DMA_Memory_Addr_Increment_Config.
*\*\fun     Enable/disable memory address increment mode for DMA Channel x.
*\*\        Called in the function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   memory_inc (The input parameters must be the following values):
*\*\          - DMA_MEM_INC_MODE_ENABLE
*\*\          - DMA_MEM_INC_MODE_DISABLE
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
*\*\        After the channel x is enabled, bits [31:1] of the CHCFG register
*\*\        cannot be modified.
**/
void DMA_Memory_Addr_Increment_Config(DMA_ChannelType* DMAChx, uint32_t memory_inc)
{
    uint32_t temp_value = 0;
    
    /* Get DMAChx_CHCFG register value */
    temp_value = DMAChx->CHCFG;
    /* Clear MINC bit */
    temp_value &= DMA_MEM_INC_MODE_MASK;
    /* Set MINC bit */
    temp_value |= memory_inc;
    /* Update DMAChx_CHCFG register */
    DMAChx->CHCFG = temp_value;
}

/**
*\*\name    DMA_Peripheral_Data_Width_Config.
*\*\fun     Configure the bit width of the peripheral data for DMA Channel x.
*\*\        Called in the function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   width (The input parameters must be the following values):
*\*\          - DMA_PERIPH_DATA_WIDTH_BYTE
*\*\          - DMA_PERIPH_DATA_WIDTH_HALFWORD
*\*\          - DMA_PERIPH_DATA_WIDTH_WORD
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
*\*\        After the channel x is enabled, bits [31:1] of the CHCFG register
*\*\        cannot be modified.
**/
void DMA_Peripheral_Data_Width_Config(DMA_ChannelType* DMAChx, uint32_t width)
{
    uint32_t temp_value = 0;
    
    /* Get DMAChx_CHCFG register value */
    temp_value = DMAChx->CHCFG;
    /* Clear PSIZE[1:0] bits */
    temp_value &= DMA_PERIPH_DATA_WIDTH_MASK;
    /* Set PSIZE[1:0] bits */
    temp_value |= width;
    /* Update DMAChx_CHCFG register */
    DMAChx->CHCFG = temp_value;
}

/**
*\*\name    DMA_Memory_Data_Width_Config.
*\*\fun     Configure the bit width of the memory data for DMA Channel x.
*\*\        Called in the function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   width (The input parameters must be the following values):
*\*\          - DMA_MEM_DATA_WIDTH_BYTE
*\*\          - DMA_MEM_DATA_WIDTH_HALFWORD
*\*\          - DMA_MEM_DATA_WIDTH_WORD
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
*\*\        After the channel x is enabled, bits [31:1] of the CHCFG register
*\*\        cannot be modified.
**/
void DMA_Memory_Data_Width_Config(DMA_ChannelType* DMAChx, uint32_t width)
{
    uint32_t temp_value = 0;
    
    /* Get DMAChx_CHCFG register value */
    temp_value = DMAChx->CHCFG;
    /* Clear MSIZE[1:0] bits */
    temp_value &= DMA_MEM_DATA_WIDTH_MASK;
    /* Set MSIZE[1:0] bits */
    temp_value |= width;
    /* Update DMAChx_CHCFG register */
    DMAChx->CHCFG = temp_value;
}

/**
*\*\name    DMA_Circular_Mode_Config.
*\*\fun     Enable/disable circular mode for DMA channel x. Called in the
*\*\        function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   cmd (The input parameters must be the following values):
*\*\          - DMA_CIRCULAR_MODE_ENABLE
*\*\          - DMA_CIRCULAR_MODE_DISABLE
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
*\*\        After the channel x is enabled, bits [31:1] of the CHCFG register
*\*\        cannot be modified.
*\*\        Circular mode cannot be enabled at the same time as memory-to-memory
*\*\        mode.
**/
void DMA_Circular_Mode_Config(DMA_ChannelType* DMAChx, uint32_t cmd)
{
    uint32_t temp_value = 0;
    
    /* Get DMAChx_CHCFG register value */
    temp_value = DMAChx->CHCFG;
    /* Clear CIRC bit */
    temp_value &= DMA_CIRCULAR_MODE_MASK;
    /* Set CIRC bit */
    temp_value |= cmd;
    /* Update DMAChx_CHCFG register */
    DMAChx->CHCFG = temp_value;
}

/**
*\*\name    DMA_Priority_Config.
*\*\fun     Configure the priority for DMA Channel x. Called in the
*\*\        function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   priority (The input parameters must be the following values):
*\*\          - DMA_CH_PRIORITY_HIGHEST
*\*\          - DMA_CH_PRIORITY_HIGH
*\*\          - DMA_CH_PRIORITY_MEDIUM
*\*\          - DMA_CH_PRIORITY_LOW
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
*\*\        After the channel x is enabled, bits [31:1] of the CHCFG register
*\*\        cannot be modified.
**/
void DMA_Priority_Config(DMA_ChannelType* DMAChx, uint32_t priority)
{
    uint32_t temp_value = 0;
    
    /* Get DMAChx_CHCFG register value */
    temp_value = DMAChx->CHCFG;
    /* Clear PRIOLVL[1:0] bits */
    temp_value &= DMA_CH_PRIORITY_MASK;
    /* Set PRIOLVL[1:0] bits */
    temp_value |= priority;
    /* Update DMAChx_CHCFG register */
    DMAChx->CHCFG = temp_value;
}

/**
*\*\name    DMA_Memory_2_Memory_Config.
*\*\fun     Enable/disable memory-to-memory mode for DMA channel x. Called
*\*\        in the function DMA_Initializes.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   cmd (The input parameters must be the following values):
*\*\          - DMA_MEM2MEM_ENABLE
*\*\          - DMA_MEM2MEM_DISABLE
*\*\return  none
*\*\note    This function can only be called if the channel x is disabled.
*\*\        After the channel x is enabled, bits [31:1] of the CHCFG register
*\*\        cannot be modified.
*\*\        Memory-to-Memory mode cannot be enabled at the same time as circular
*\*\        mode.
**/
void DMA_Memory_2_Memory_Config(DMA_ChannelType* DMAChx, uint32_t cmd)
{
    uint32_t temp_value = 0;
    
    /* Get DMAChx_CHCFG register value */
    temp_value = DMAChx->CHCFG;
    /* Clear MEM2MEM bit */
    temp_value &= DMA_MEM2MEM_MASK;
    /* Set MEM2MEM bit */
    temp_value |= cmd;
    /* Update DMAChx_CHCFG register */
    DMAChx->CHCFG = temp_value;
}

/**
*\*\name    DMA_Structure_Initializes.
*\*\fun     Initializes the structure parameter of type DMA_InitType used to
*\*\        initialize DMA. This function is usually called before initializing
*\*\        a parameter of type DMA_InitType.
*\*\param   DMA_InitParam :
*\*\          - Pointer to the DMA_InitType structure which will be initialized.
*\*\return  none
**/
void DMA_Structure_Initializes(DMA_InitType* DMA_InitParam)
{
    /* Initializes the Direction member */
    DMA_InitParam->Direction = DMA_DIR_PERIPH_SRC;
    /* Initializes the PeriphAddr member */
    DMA_InitParam->PeriphAddr = 0;
    /* Initializes the MemAddr member */
    DMA_InitParam->MemAddr = 0;
    /* Initializes the Priority member */
    DMA_InitParam->Priority = DMA_CH_PRIORITY_LOW;
    /* Initializes the PeriphInc member */
    DMA_InitParam->PeriphInc = DMA_PERIPH_INC_MODE_DISABLE;
    /* Initializes the MemoryInc member */
    DMA_InitParam->MemoryInc = DMA_MEM_INC_MODE_DISABLE;
    /* Initializes the BufSize member */
    DMA_InitParam->BufSize = 0;
    /* Initializes the PeriphDataSize member */
    DMA_InitParam->PeriphDataSize = DMA_PERIPH_DATA_WIDTH_BYTE;
    /* Initializes the MemDataSize member */
    DMA_InitParam->MemDataSize = DMA_MEM_DATA_WIDTH_BYTE;
    /* Initializes the CircularMode member */
    DMA_InitParam->CircularMode = DMA_CIRCULAR_MODE_DISABLE;
    /* Initializes the Mem2Mem member */
    DMA_InitParam->Mem2Mem = DMA_MEM2MEM_DISABLE;
}

/**
*\*\name    DMA_Channel_Enable.
*\*\fun     DMA Channel x Channel enable. This function is called after DMA
*\*\        initialization is successful to start moving data.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\return  none
**/
void DMA_Channel_Enable(DMA_ChannelType* DMAChx)
{
    /* Enable the selected DMA Channelx */
    DMAChx->CHCFG |= DMA_CHANNEL_ENABLE;
}

/**
*\*\name    DMA_Channel_Disable.
*\*\fun     DMA Channel x Channel disable. After the data is successfully moved,
*\*\        call this function to close the corresponding DMA channel according
*\*\        to the user's needs.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\return  none
**/
void DMA_Channel_Disable(DMA_ChannelType* DMAChx)
{
    /* Disable the selected DMA Channelx */
    DMAChx->CHCFG &= DMA_CHANNEL_DISABLE;
}

/**
*\*\name    DMA_Interrupts_Enable.
*\*\fun     DMA Channel x interrupts enable. Before enabling a DMA channel,
*\*\        enabling transfer completion interrupt, half-transfer interrupt
*\*\        or transfer error interrupt will cause an interrupt when the
*\*\        corresponding event occurs.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   interrupt (The input parameters must be the following values):
*\*\          - DMA_INT_TXC
*\*\          - DMA_INT_HTX
*\*\          - DMA_INT_ERR
*\*\return  none
**/
void DMA_Interrupts_Enable(DMA_ChannelType* DMAChx, uint32_t interrupt)
{
    /* Enable the selected DMA Channelx interrupts */
    DMAChx->CHCFG |= interrupt;
}

/**
*\*\name    DMA_Interrupts_Disable.
*\*\fun     DMA Channel x interrupts disable. This function is usually called
*\*\        after the DMA transfer has completed.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   interrupt (The input parameters must be the following values):
*\*\          - DMA_INT_TXC
*\*\          - DMA_INT_HTX
*\*\          - DMA_INT_ERR
*\*\return  none
**/
void DMA_Interrupts_Disable(DMA_ChannelType* DMAChx, uint32_t interrupt)
{
    /* Disable the selected DMA Channelx interrupts */
    DMAChx->CHCFG &= (~interrupt);
}

/**
*\*\name    DMA_Current_Data_Transfer_Number_Set.
*\*\fun     Set the current number of data transfers for DMA Channel x.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   num :
*\*\          - 1~0xFFFF
*\*\return  none
*\*\note    This function can only be used when the DMAChx is disabled.
**/
void DMA_Current_Data_Transfer_Number_Set(DMA_ChannelType* DMAChx, uint16_t num)
{
    /* Write to DMA Channelx TXNUM */
    DMAChx->TXNUM = num;
}

/**
*\*\name    DMA_Current_Data_Transfer_Number_Get.
*\*\fun     Get the current number of remaining data for DMA Channel x.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\return  Returns the number of bytes remaining to be transferred.
**/
uint16_t DMA_Current_Data_Transfer_Number_Get(DMA_ChannelType* DMAChx)
{
    /* Returns the number of remaining to be transferred for DMA Channelx */
    return ((uint16_t)(DMAChx->TXNUM));
}

/**
*\*\name    DMA_Flag_Status_Get.
*\*\fun     Get DMA Channel x flag status. Contains the global flag, transfer
*\*\        completion flag, half-transfer flag, and transfer error flag for
*\*\        the corresponding channel.
*\*\param   DMAx (The input parameters must be the following values):
*\*\          - DMA
*\*\param   flag (The input parameters must be the following values):
*\*\          - DMA_CH1_GLBF
*\*\          - DMA_CH1_TXCF
*\*\          - DMA_CH1_HTXF
*\*\          - DMA_CH1_ERRF
*\*\          - DMA_CH2_GLBF
*\*\          - DMA_CH2_TXCF
*\*\          - DMA_CH2_HTXF
*\*\          - DMA_CH2_ERRF
*\*\          - DMA_CH3_GLBF
*\*\          - DMA_CH3_TXCF
*\*\          - DMA_CH3_HTXF
*\*\          - DMA_CH3_ERRF
*\*\          - DMA_CH4_GLBF
*\*\          - DMA_CH4_TXCF
*\*\          - DMA_CH4_HTXF
*\*\          - DMA_CH4_ERRF
*\*\          - DMA_CH5_GLBF
*\*\          - DMA_CH5_TXCF
*\*\          - DMA_CH5_HTXF
*\*\          - DMA_CH5_ERRF
*\*\          - DMA_CH6_GLBF
*\*\          - DMA_CH6_TXCF
*\*\          - DMA_CH6_HTXF
*\*\          - DMA_CH6_ERRF
*\*\          - DMA_CH7_GLBF
*\*\          - DMA_CH7_TXCF
*\*\          - DMA_CH7_HTXF
*\*\          - DMA_CH7_ERRF
*\*\          - DMA_CH8_GLBF
*\*\          - DMA_CH8_TXCF
*\*\          - DMA_CH8_HTXF
*\*\          - DMA_CH8_ERRF
*\*\return  SET or RESET.
**/
FlagStatus DMA_Flag_Status_Get(DMA_Module* DMAx, uint32_t flag)
{
    /* Check the status of the DMA flag */
    if ((DMAx->INTSTS & flag) == (uint32_t)RESET)
    {
        /* DMA_CHx_Flag is reset */
        return RESET;
    }
    else
    {
        /* DMA_CHx_Flag is set */
        return SET;
    }
}

/**
*\*\name    DMA_Flag_Status_Clear.
*\*\fun     Clear DMA Channel x flag status. Contains the global flag, transfer
*\*\        completion flag, half-transfer flag, and transfer error flag for the
*\*\        corresponding channel.
*\*\param   DMAx (The input parameters must be the following values):
*\*\          - DMA
*\*\param   flag (The input parameters must be the following values):
*\*\          - DMA_CH1_GLBF
*\*\          - DMA_CH1_TXCF
*\*\          - DMA_CH1_HTXF
*\*\          - DMA_CH1_ERRF
*\*\          - DMA_CH2_GLBF
*\*\          - DMA_CH2_TXCF
*\*\          - DMA_CH2_HTXF
*\*\          - DMA_CH2_ERRF
*\*\          - DMA_CH3_GLBF
*\*\          - DMA_CH3_TXCF
*\*\          - DMA_CH3_HTXF
*\*\          - DMA_CH3_ERRF
*\*\          - DMA_CH4_GLBF
*\*\          - DMA_CH4_TXCF
*\*\          - DMA_CH4_HTXF
*\*\          - DMA_CH4_ERRF
*\*\          - DMA_CH5_GLBF
*\*\          - DMA_CH5_TXCF
*\*\          - DMA_CH5_HTXF
*\*\          - DMA_CH5_ERRF
*\*\          - DMA_CH6_GLBF
*\*\          - DMA_CH6_TXCF
*\*\          - DMA_CH6_HTXF
*\*\          - DMA_CH6_ERRF
*\*\          - DMA_CH7_GLBF
*\*\          - DMA_CH7_TXCF
*\*\          - DMA_CH7_HTXF
*\*\          - DMA_CH7_ERRF
*\*\          - DMA_CH8_GLBF
*\*\          - DMA_CH8_TXCF
*\*\          - DMA_CH8_HTXF
*\*\          - DMA_CH8_ERRF
*\*\return  none.
**/
void DMA_Flag_Status_Clear(DMA_Module* DMAx, uint32_t flag)
{
    /* Clear DMA flags */
    DMAx->INTCLR = flag;
}

/**
*\*\name    DMA_Interrupt_Status_Get.
*\*\fun     Get DMA Channel x interrupt status. Contains the global interrupt,
*\*\        transfer completion interrupt, half-transfer interrupt, and transfer
*\*\        error interrupt for the corresponding channel.
*\*\param   DMA (The input parameters must be the following values):
*\*\          - DMA
*\*\param   interrupt (The input parameters must be the following values):
*\*\          - DMA_CH1_INT_GLB
*\*\          - DMA_CH1_INT_TXC
*\*\          - DMA_CH1_INT_HTX
*\*\          - DMA_CH1_INT_ERR
*\*\          - DMA_CH2_INT_GLB
*\*\          - DMA_CH2_INT_TXC
*\*\          - DMA_CH2_INT_HTX
*\*\          - DMA_CH2_INT_ERR
*\*\          - DMA_CH3_INT_GLB
*\*\          - DMA_CH3_INT_TXC
*\*\          - DMA_CH3_INT_HTX
*\*\          - DMA_CH3_INT_ERR
*\*\          - DMA_CH4_INT_GLB
*\*\          - DMA_CH4_INT_TXC
*\*\          - DMA_CH4_INT_HTX
*\*\          - DMA_CH4_INT_ERR
*\*\          - DMA_CH5_INT_GLB
*\*\          - DMA_CH5_INT_TXC
*\*\          - DMA_CH5_INT_HTX
*\*\          - DMA_CH5_INT_ERR
*\*\          - DMA_CH6_INT_GLB
*\*\          - DMA_CH6_INT_TXC
*\*\          - DMA_CH6_INT_HTX
*\*\          - DMA_CH6_INT_ERR
*\*\          - DMA_CH7_INT_GLB
*\*\          - DMA_CH7_INT_TXC
*\*\          - DMA_CH7_INT_HTX
*\*\          - DMA_CH7_INT_ERR
*\*\          - DMA_CH8_INT_GLB
*\*\          - DMA_CH8_INT_TXC
*\*\          - DMA_CH8_INT_HTX
*\*\          - DMA_CH8_INT_ERR
*\*\return  SET or RESET.
*\*\note    Global interrupt status is the logic or generation of transfer completion
*\*\        interrupt, half-transfer interrupt, transfer error interrupt.
**/
INTStatus DMA_Interrupt_Status_Get(DMA_Module* DMAx, uint32_t interrupt)
{
    /* Check the status of the specified DMA interrupt */
    if ((DMAx->INTSTS & interrupt) == (uint32_t)RESET)
    {
        /* DMA_CHx_IT is reset */
        return RESET;
    }
    else
    {
        /* DMA_CHx_IT is set */
        return SET;
    }
}

/**
*\*\name    DMA_Interrupt_Status_Clear.
*\*\fun     Clear DMA Channel x interrupt status bits. Contains the global interrupt,
*\*\        transfer completion interrupt, half-transfer interrupt, and transfer
*\*\        error interrupt for the corresponding channel.
*\*\param   DMAx (The input parameters must be the following values):
*\*\          - DMA
*\*\param   interrupt (The input parameters must be the following values):
*\*\          - DMA_CH1_INT_GLB
*\*\          - DMA_CH1_INT_TXC
*\*\          - DMA_CH1_INT_HTX
*\*\          - DMA_CH1_INT_ERR
*\*\          - DMA_CH2_INT_GLB
*\*\          - DMA_CH2_INT_TXC
*\*\          - DMA_CH2_INT_HTX
*\*\          - DMA_CH2_INT_ERR
*\*\          - DMA_CH3_INT_GLB
*\*\          - DMA_CH3_INT_TXC
*\*\          - DMA_CH3_INT_HTX
*\*\          - DMA_CH3_INT_ERR
*\*\          - DMA_CH4_INT_GLB
*\*\          - DMA_CH4_INT_TXC
*\*\          - DMA_CH4_INT_HTX
*\*\          - DMA_CH4_INT_ERR
*\*\          - DMA_CH5_INT_GLB
*\*\          - DMA_CH5_INT_TXC
*\*\          - DMA_CH5_INT_HTX
*\*\          - DMA_CH5_INT_ERR
*\*\          - DMA_CH6_INT_GLB
*\*\          - DMA_CH6_INT_TXC
*\*\          - DMA_CH6_INT_HTX
*\*\          - DMA_CH6_INT_ERR
*\*\          - DMA_CH7_INT_GLB
*\*\          - DMA_CH7_INT_TXC
*\*\          - DMA_CH7_INT_HTX
*\*\          - DMA_CH7_INT_ERR
*\*\          - DMA_CH8_INT_GLB
*\*\          - DMA_CH8_INT_TXC
*\*\          - DMA_CH8_INT_HTX
*\*\          - DMA_CH8_INT_ERR
*\*\return  none.
*\*\note    Global interrupt state is the logic or generation of transfer completion
*\*\        interrupt, half-transfer interrupt, transfer error interrupt. In fact,
*\*\        after clearing the three interrupt states, the global interrupt state
*\*\        will also be cleared.
**/
void DMA_Interrupt_Status_Clear(DMA_Module* DMAx, uint32_t interrupt)
{
    /* Clear the selected DMA interrupt status bits */
    DMAx->INTCLR = interrupt;
}

/**
*\*\name    DMA_Channel_Request_Remap.
*\*\fun     Set DMA Channel x's remap request. Channel request mapping is flexible,
*\*\        allowing users to map any DMA request to any DMA channel as needed. It
*\*\        is important to note that there can be only one DMA request per DMA
*\*\        channel at a time.
*\*\param   DMAChx (The input parameters must be the following values):
*\*\          - DMA_CH1
*\*\          - DMA_CH2
*\*\          - DMA_CH3
*\*\          - DMA_CH4
*\*\          - DMA_CH5
*\*\          - DMA_CH6
*\*\          - DMA_CH7
*\*\          - DMA_CH8
*\*\param   req_remap (The input parameters must be the following values):
*\*\          - DMA_REMAP_ADC
*\*\          - DMA_REMAP_UART1_TX
*\*\          - DMA_REMAP_UART1_RX
*\*\          - DMA_REMAP_USART2_TX
*\*\          - DMA_REMAP_USART2_RX
*\*\          - DMA_REMAP_UART4_TX
*\*\          - DMA_REMAP_UART4_RX
*\*\          - DMA_REMAP_SPI1_TX
*\*\          - DMA_REMAP_SPI1_RX
*\*\          - DMA_REMAP_SPI2_TX
*\*\          - DMA_REMAP_SPI2_RX
*\*\          - DMA_REMAP_I2C1_TX
*\*\          - DMA_REMAP_I2C1_RX
*\*\          - DMA_REMAP_I2C2_TX
*\*\          - DMA_REMAP_I2C2_RX
*\*\          - DMA_REMAP_TIM1_CH1
*\*\          - DMA_REMAP_TIM1_CH2
*\*\          - DMA_REMAP_TIM1_CH3
*\*\          - DMA_REMAP_TIM1_CH4
*\*\          - DMA_REMAP_TIM1_COM
*\*\          - DMA_REMAP_TIM1_UP
*\*\          - DMA_REMAP_TIM1_TRIG
*\*\          - DMA_REMAP_TIM2_CH1
*\*\          - DMA_REMAP_TIM2_CH2
*\*\          - DMA_REMAP_TIM2_CH3
*\*\          - DMA_REMAP_TIM2_CH4
*\*\          - DMA_REMAP_TIM2_UP
*\*\          - DMA_REMAP_TIM3_CH1
*\*\          - DMA_REMAP_TIM3_CH3
*\*\          - DMA_REMAP_TIM3_CH4
*\*\          - DMA_REMAP_TIM3_UP
*\*\          - DMA_REMAP_TIM3_TRIG
*\*\          - DMA_REMAP_TIM4_CH1
*\*\          - DMA_REMAP_TIM4_CH2
*\*\          - DMA_REMAP_TIM4_CH3
*\*\          - DMA_REMAP_TIM4_UP
*\*\          - DMA_REMAP_TIM5_CH1
*\*\          - DMA_REMAP_TIM5_CH2
*\*\          - DMA_REMAP_TIM5_CH3
*\*\          - DMA_REMAP_TIM5_CH4
*\*\          - DMA_REMAP_TIM5_UP
*\*\          - DMA_REMAP_TIM5_TRIG
*\*\          - DMA_REMAP_TIM6_UP
*\*\          - DMA_REMAP_TIM8_CH1
*\*\          - DMA_REMAP_TIM8_CH2
*\*\          - DMA_REMAP_TIM8_CH3
*\*\          - DMA_REMAP_TIM8_CH4
*\*\          - DMA_REMAP_TIM8_COM
*\*\          - DMA_REMAP_TIM8_UP
*\*\          - DMA_REMAP_TIM8_TRIG
*\*\return  none.
**/
void DMA_Channel_Request_Remap(DMA_ChannelType* DMAChx, uint32_t req_remap)
{
    /* Set the selected DMA request remap */
    DMAChx->CHSEL = req_remap;
}


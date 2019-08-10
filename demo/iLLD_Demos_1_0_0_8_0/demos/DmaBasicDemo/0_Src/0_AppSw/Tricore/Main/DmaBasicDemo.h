/**
 * \file DmaBasicDemo.h
 * \brief Dma basic Memory to memory transfer Demo
 *
 * \version iLLD_Demos_1_0_0_8_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Demo_DmaBasicDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_DmaBasicDemo_SrcDoc
 * \defgroup IfxLld_Demo_DmaBasicDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_DmaBasicDemo_SrcDoc_Main
 */

#ifndef DMABASICDEMO_H
#define DMABASICDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include <Dma/Dma/IfxDma_Dma.h>

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define NUM_CHANNELS 2   /**< \brief No of dma channels */
#define BUFFER_SIZE  16  /**< \brief Dma source & destination buffer size */

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
#if defined(__TASKING__)
#pragma align 64
    volatile uint32 source[NUM_CHANNELS][BUFFER_SIZE];                                    /**< \brief source buffer */
    volatile uint32 destination[NUM_CHANNELS][BUFFER_SIZE];                               /**< \brief destination buffer */
#pragma align restore
#elif defined(__GNUC__)
    __attribute__ ((aligned(64))) volatile uint32 source[NUM_CHANNELS][BUFFER_SIZE];      /**< \brief source buffer */
    __attribute__ ((aligned(64))) volatile uint32 destination[NUM_CHANNELS][BUFFER_SIZE]; /**< \brief destination buffer */
#else
#error "unsupported compiler"
#endif
} AppDmaBuffer;

typedef struct
{
    AppDmaBuffer dmaBuffer;                       /**< \brief Dma source and destination buffers */
    struct
    {
        IfxDma_Dma_Channel chn[NUM_CHANNELS];     /**< \brief Dma channel handles */
    }drivers;
} App_DmaBasic;
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_DmaBasic g_DmaBasic;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void IfxDmaBasicDemo_init(void);
IFX_EXTERN void IfxDmaBasicDemo_run(void);

#endif

/**
 * \file DmaLinkedListDemo.h
 * \brief Dma Linked List transfers Demo
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
 * \defgroup IfxLld_Demo_DmaLinkedListDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_DmaLinkedListDemo_SrcDoc
 * \defgroup IfxLld_Demo_DmaLinkedListDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_DmaLinkedListDemo_SrcDoc_Main
 */

#ifndef TEMPLATE_H
#define TEMPLATE_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include <Dma/Dma/IfxDma_Dma.h>

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define NUM_LINKED_LIST_ITEMS 4  /**< \brief No od Dma linked lists */
#define NUM_TRANSFERED_WORDS  16 /**< \brief No of data to be transfered */

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
    uint32          source[NUM_LINKED_LIST_ITEMS][NUM_TRANSFERED_WORDS];                                    /**< \brief source buffer */
    volatile uint32 destination[NUM_LINKED_LIST_ITEMS][NUM_TRANSFERED_WORDS];                               /**< \brief destination buffer */
#pragma align restore
#elif defined(__GNUC__)
    __attribute__ ((aligned(64))) uint32 source[NUM_LINKED_LIST_ITEMS][NUM_TRANSFERED_WORDS];               /**< \brief source buffer */
    __attribute__ ((aligned(64))) volatile uint32 destination[NUM_LINKED_LIST_ITEMS][NUM_TRANSFERED_WORDS]; /**< \brief destination buffer */
#else
#error "unsupported compiler"
#endif
} AppDmaBuffer;

typedef struct
{
    AppDmaBuffer dmaBuffer;                            /**< \brief Dma source and destination buffers */
    struct
    {
#if defined(__TASKING__)
#pragma align 64
        Ifx_DMA_CH linkedList[NUM_LINKED_LIST_ITEMS];                               /**< \brief Linked List storage. IMPORTANT: it has to be aligned to an 64bit address, otherwise DMA can't read it */
#pragma align restore
#elif defined(__GNUC__)
        __attribute__ ((aligned(64))) Ifx_DMA_CH linkedList[NUM_LINKED_LIST_ITEMS]; /**< \brief Linked List storage.IMPORTANT: it has to be aligned to an 64bit address, otherwise DMA can't read it */
#else
#error "unsupported compiler"
#endif
        IfxDma_Dma_Channel chn;     /**< \brief Dma channel handle */
    }drivers;
} App_DmaLinkedList;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_DmaLinkedList g_DmaLinkedList;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void IfxDmaLinkedListDemo_init(void);
IFX_EXTERN void IfxDmaLinkedListDemo_run(void);

#endif

/**
 * \file DmaLinkedListDemo.c
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include "Cpu0_Main.h"
#include "ConfigurationIsr.h"
#include "Ifx_Assert.h"
#include "DmaLinkedListDemo.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
App_DmaLinkedList g_DmaLinkedList; /**< \brief Dma Linkedlist Global data */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxDmaLinkedListDemo_init(void)
{
    uint32                   i;

    /* create module config*/
    IfxDma_Dma_Config        dmaConfig;
    IfxDma_Dma_initModuleConfig(&dmaConfig, &MODULE_DMA);

    /* initialize module */
    IfxDma_Dma               dma;
    IfxDma_Dma_initModule(&dma, &dmaConfig);

    /* initial channel configuration */
    IfxDma_Dma_ChannelConfig cfg;
    IfxDma_Dma_initChannelConfig(&cfg, &dma);

    /* following settings are used by all transactions */
    cfg.transferCount = NUM_TRANSFERED_WORDS;
    cfg.requestMode   = IfxDma_ChannelRequestMode_completeTransactionPerRequest;
    cfg.moveSize      = IfxDma_ChannelMoveSize_32bit;
    cfg.shadowControl = IfxDma_ChannelShadow_linkedList;

    /* generate linked list items */
    for (i = 0; i < NUM_LINKED_LIST_ITEMS; ++i)
    {
        cfg.sourceAddress      =
            IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), g_DmaLinkedList.dmaBuffer.source[i]);
        cfg.destinationAddress =
            IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), g_DmaLinkedList.dmaBuffer.destination[i]);

        /* address to next transaction set */
        cfg.shadowAddress =
            IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), (uint32)&g_DmaLinkedList.drivers.linkedList[(i + 1) % NUM_LINKED_LIST_ITEMS]);

        /* transfer first transaction set into DMA channel */
        if (i == 0)
        {
            IfxDma_Dma_initChannel(&g_DmaLinkedList.drivers.chn, &cfg);
        }

        /* transfer into linked list storage */
        IfxDma_Dma_initLinkedListEntry((void *)&g_DmaLinkedList.drivers.linkedList[i], &cfg);

        if (i == 0)
        {
            /* - trigger channel interrupt once the first transaction set has been loaded (again) into DMA channel */
            g_DmaLinkedList.drivers.linkedList[i].CHCSR.B.SIT = 1;
        }
        else
        {
            /* - activate SCH (transaction request) for each entry, expect for the first one (linked list terminated here) */
            g_DmaLinkedList.drivers.linkedList[i].CHCSR.B.SCH = 1;
        }
    }
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxDmaLinkedListDemo_run(void)
{
    uint32 errors = 0;
    uint32 i, j;

    printf("Starting linked list transfer\n");

    for (i = 0; i < NUM_LINKED_LIST_ITEMS; ++i)
    {
        uint32 *src = (uint32 *)g_DmaLinkedList.dmaBuffer.source[i];

        for (j = 0; j < NUM_TRANSFERED_WORDS; ++j)
        {
            *src++ = 0x10000000 + i * 0x00010000 + j + 1;
        }
    }

    /* clear service request flag */
    (IfxDma_Dma_getSrcPointer(&g_DmaLinkedList.drivers.chn))->B.CLRR = 1;

    /* start linked list transaction */
    IfxDma_Dma_startChannelTransaction(&g_DmaLinkedList.drivers.chn);

    /* wait for service request which is triggered at the end of linked list transfers */
    while (!(IfxDma_Dma_getSrcPointer(&g_DmaLinkedList.drivers.chn))->B.SRR)
    {}

    /* check transfered values against expected values */
    printf("Checking destinationBuffer against expected values... \n");

    for (i = 0; i < NUM_LINKED_LIST_ITEMS; ++i)
    {
        uint32 *src = (uint32 *)g_DmaLinkedList.dmaBuffer.source[i];
        uint32 *dst = (uint32 *)g_DmaLinkedList.dmaBuffer.destination[i];

        for (j = 0; j < NUM_TRANSFERED_WORDS; ++j)
        {
            if (*dst++ != *src++)
            {
                ++errors;
            }
        }
    }

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, errors == 0);

    if (errors)
    {
        printf("ERROR: Dma destination data doesn't match with expected data (%lu mismatches)\n", errors);
    }
    else
    {
        printf("OK: Dma destination data matches with expected data\n");
    }
}

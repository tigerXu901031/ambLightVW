/**
 * \file DmaBasicDemo.c
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include "Cpu0_Main.h"
#include "ConfigurationIsr.h"
#include "Ifx_Assert.h"
#include "DmaBasicDemo.h"

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
App_DmaBasic g_DmaBasic; /**< \brief Dma global data */

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
void IfxDmaBasicDemo_init(void)
{
    uint32                   i, j;

    /* create module config */
    IfxDma_Dma_Config        dmaConfig;
    IfxDma_Dma_initModuleConfig(&dmaConfig, &MODULE_DMA);

    /* initialize module */
    IfxDma_Dma               dma;
    IfxDma_Dma_initModule(&dma, &dmaConfig);

    /* initial configuration for all channels */
    IfxDma_Dma_ChannelConfig cfg;
    IfxDma_Dma_initChannelConfig(&cfg, &dma);

    /* following configuration is used by all channels */
    cfg.transferCount                    = BUFFER_SIZE;
    cfg.requestMode                      = IfxDma_ChannelRequestMode_completeTransactionPerRequest;
    cfg.moveSize                         = IfxDma_ChannelMoveSize_32bit;

    cfg.destinationAddressCircularRange  = IfxDma_ChannelIncrementCircular_64;
    cfg.sourceAddressCircularRange       = IfxDma_ChannelIncrementCircular_64;
    cfg.destinationCircularBufferEnabled = TRUE;
    cfg.sourceCircularBufferEnabled      = TRUE;

    /* channel specific configurations */
    for (i = 0; i < NUM_CHANNELS; ++i)
    {
        cfg.channelId          = (IfxDma_ChannelId)i;
        cfg.sourceAddress      = IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), &g_DmaBasic.dmaBuffer.source[i][0]);
        cfg.destinationAddress = IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), &g_DmaBasic.dmaBuffer.destination[i][0]);
        IfxDma_Dma_initChannel(&g_DmaBasic.drivers.chn[i], &cfg);
    }

    /* prepare buffers */
    for (i = 0; i < NUM_CHANNELS; ++i)
    {
        uint32 *src     = (uint32 *)g_DmaBasic.dmaBuffer.source[i];
        uint32 *dst     = (uint32 *)g_DmaBasic.dmaBuffer.destination[i];
        uint32  chnWord = i * 0x10000000;

        for (j = 0; j < BUFFER_SIZE; ++j)
        {
            *src++ = chnWord++;
            *dst++ = 0xdeadbeef;
        }
    }
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxDmaBasicDemo_run(void)
{
    uint32  errors = 0;
    uint32  i, j;
    boolean notFinished;

    printf("Starting DMA transfer on all %d channels\n", NUM_CHANNELS);

    for (i = 0; i < NUM_CHANNELS; ++i)
    {
        IfxDma_Dma_startChannelTransaction(&g_DmaBasic.drivers.chn[i]);
    }

    do
    {
        notFinished = FALSE;

        for (i = 0; i < NUM_CHANNELS; ++i)
        {
            if (IfxDma_getChannelTransferCount(g_DmaBasic.drivers.chn[i].dma, g_DmaBasic.drivers.chn[i].channelId))
            {
                notFinished = TRUE;
                break;
            }
        }
    } while (notFinished);

    printf("All transactions finished\n");

    printf("Checking destinationBuffer\n");

    for (i = 0; i < NUM_CHANNELS; ++i)
    {
        uint32 *dst     = (uint32 *)g_DmaBasic.dmaBuffer.destination[i];
        uint32  chnWord = i * 0x10000000;

        for (j = 0; j < BUFFER_SIZE; ++j)
        {
            if (*dst++ != chnWord++)
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

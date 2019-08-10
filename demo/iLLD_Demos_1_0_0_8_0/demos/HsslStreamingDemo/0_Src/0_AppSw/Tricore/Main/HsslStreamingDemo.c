/**
 * \file HsslStreamingDemo.c
 * \brief Demo HsslStreamingDemo
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
#include "HsslStreamingDemo.h"

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

App_HsslStreaming g_HsslStreaming; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

__attribute__ ((aligned(256))) uint32 txData[80];

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_HsslStreaming_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void HsslStreamingDemo_init(void)
{
    /* create Hsct module config */
    IfxHssl_Hssl_initHsctModuleConfig(&g_HsslStreaming.drivers.hsctConfig, &MODULE_HSCT);

    /* choose master or slave */
    g_HsslStreaming.drivers.hsctConfig.interfaceMode = IfxHssl_InterfaceMode_master;
    g_HsslStreaming.drivers.hsctConfig.highSpeedMode = TRUE; /* interface at high speed */

    /* create Hssl module config */
    IfxHssl_Hssl_initHsslModuleConfig(&g_HsslStreaming.drivers.hsslConfig, &MODULE_HSSL);
	
	/* initialize Hsct module */
    IfxHssl_Hssl_initHsctModule(&g_HsslStreaming.drivers.hsct, &g_HsslStreaming.drivers.hsctConfig);
	
	/* initialize Hssl module */
    IfxHssl_Hssl_initHsslModule(&g_HsslStreaming.drivers.hssl, &g_HsslStreaming.drivers.hsslConfig);

    /* create HSSL channel config */
    IfxHssl_Hssl_ChannelConfig hsslChannelConfig;
    IfxHssl_Hssl_initChannelConfig(&hsslChannelConfig, &g_HsslStreaming.drivers.hssl, &g_HsslStreaming.drivers.hsct);
	
    uint32                     i;

    for (i = 0; i < 4; ++i)
    {
        hsslChannelConfig.channelId = (IfxHssl_ChannelId)i;

        if (i == 2)
        {
            /*			hsslChannelConfig.loopBack = TRUE;	// used in prepareStream Api */
        }

        IfxHssl_Hssl_initChannel(&g_HsslStreaming.drivers.hsslChannel[i], &hsslChannelConfig);
    }

    printf("Hssl is Initialized\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void HsslStreamingDemo_run(void)
{
    if (g_HsslStreaming.drivers.hsctConfig.interfaceMode == IfxHssl_InterfaceMode_slave)
    {
        while (1)
        {}
    }
    else if (g_HsslStreaming.drivers.hsctConfig.interfaceMode == IfxHssl_InterfaceMode_master)
    {
        uint32 i    = 0;
        uint32 data = 0x12345600;

        for (i = 0; i < 80; i++)
        {
            txData[i] = data + i;
        }

        /* prepare streaming of single memory block */
        IfxHssl_Hssl_prepareStream(&g_HsslStreaming.drivers.hsslChannel[0], 0x70000000, 10);

        /* stream single memory block */
        IfxHssl_Hssl_writeStream(&g_HsslStreaming.drivers.hssl, (uint32 *)IFXCPU_GLB_ADDR_DSPR(IfxCpu_getCoreId(), (uint32)txData), 10);

        while (IfxHssl_Hssl_waitAcknowledge(&g_HsslStreaming.drivers.hsslChannel[2]) != IfxHssl_Hssl_Status_ok)
        {}
    }

    printf("Hssl data Streaming is finished\n");
}

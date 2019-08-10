/**
 * \file Psi5SDemo.c
 * \brief Psi5S Demo
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
#include "Psi5SDemo.h"
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

App_Psi5S g_Psi5S; /**< brief Psi5S global data */
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
void IfxPsi5SDemo_init(void)
{
    printf("IfxPsi5SDemo_init() called\n");

    IfxPsi5s_Psi5s_Config        psi5sModuleConfig;
    IfxPsi5s_Psi5s_initModuleConfig(&psi5sModuleConfig, &MODULE_PSI5S);
    IfxPsi5s_Psi5s_initModule(&g_Psi5S.psi5s, &psi5sModuleConfig);

    IfxPsi5s_Psi5s_ChannelConfig psi5sChannelConfig;
    IfxPsi5s_Psi5s_initChannelConfig(&psi5sChannelConfig, &g_Psi5S.psi5s);

    psi5sChannelConfig.channelId = IfxPsi5s_ChannelId_4;
    int                          slot;

    for (slot = 0; slot < 6; ++slot)
    {
        psi5sChannelConfig.receiveControl.payloadLength[slot] = 8;
    }

    psi5sChannelConfig.channelId = IfxPsi5s_ChannelId_4;

    /* initialize the channel*/
    IfxPsi5s_Psi5s_initChannel(&g_Psi5S.psi5sChannel, &psi5sChannelConfig);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxPsi5SDemo_run(void)
{
    printf("IfxPsi5SDemo_run() called\n");

    uint32 channels = (1 << IfxPsi5s_ChannelId_4);                 /* enable channel 4*/
    uint32 mask     = (1 << IfxPsi5s_ChannelId_4);                 /* modify the selection for channel 4*/

    IfxPsi5s_Psi5s_enableDisableChannelTriggerCounters(&g_Psi5S.psi5s, channels, mask);

    /* enable the channel*/
    IfxPsi5s_Psi5s_enableDisableChannels(&g_Psi5S.psi5s, channels, mask);

    /* start ASC interface*/
    IfxPsi5s_Psi5s_startAscTransactions(&g_Psi5S.psi5s);

    uint32 data = 0x5;

    /* send data*/
    if (IfxPsi5s_Psi5s_sendChannelData(&g_Psi5S.psi5sChannel, data))
    {
        /* wait till data transfer is completed*/
        while (g_Psi5S.psi5s.psi5s->INTSTAT[IfxPsi5s_ChannelId_4].B.TPI == 0)
        {}
    }

    /* enable ASC receiver*/
    IfxPsi5s_Psi5s_enableAscReceiver(&g_Psi5S.psi5s);

    /* start ASC interface*/
    IfxPsi5s_Psi5s_startAscTransactions(&g_Psi5S.psi5s);

    IfxPsi5s_Psi5s_Frame frame;

    while (!IfxPsi5s_Psi5s_getReadFrameStatus(&g_Psi5S.psi5s, IfxPsi5s_ChannelId_4))
    {}

    IfxPsi5s_Psi5s_readFrame(&g_Psi5S.psi5sChannel, &frame);

    printf("Received frame:\nData=%x\nStatus=%x\nTime stamp=%x\n", frame.data, frame.status, frame.timestamp);
}

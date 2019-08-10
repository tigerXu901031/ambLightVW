/**
 * \file Psi5Demo.c
 * \brief Psi5 Demo
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
#include "Psi5Demo.h"
#include "_Utilities/Ifx_Assert.h"

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

App_Psi5 g_Psi5; /**< \brief Psi5 global data */

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
void IfxPsi5Demo_init(void)
{
    printf("IfxPsi5Demo_init() called\n");

    /* create module config*/
    IfxPsi5_Psi5_Config psi5Config;
    IfxPsi5_Psi5_initModuleConfig(&psi5Config, &MODULE_PSI5);

    /* initialize module*/
    IfxPsi5_Psi5_initModule(&g_Psi5.psi5, &psi5Config);

    /* create channel config*/
    IfxPsi5_Psi5_ChannelConfig psi5ChannelConfig;

    IfxPsi5_Psi5_initChannelConfig(&psi5ChannelConfig, &g_Psi5.psi5);

    psi5ChannelConfig.pinsConfig            = NULL_PTR;

    psi5ChannelConfig.watchdogTimerLimit[0] = 0x32;     /* initial delay before slot 0 starts*/
    psi5ChannelConfig.watchdogTimerLimit[1] = 0x90;
    psi5ChannelConfig.watchdogTimerLimit[2] = 0x10;
    psi5ChannelConfig.watchdogTimerLimit[3] = 0x10;
    psi5ChannelConfig.watchdogTimerLimit[4] = 0x10;
    psi5ChannelConfig.watchdogTimerLimit[5] = 0x10;
    psi5ChannelConfig.watchdogTimerLimit[6] = 0x10;

    int slot;

    for (slot = 0; slot < 6; ++slot)
    {
        psi5ChannelConfig.receiveControl.payloadLength[slot] = 8;

        if (slot == 0)
        {
            psi5ChannelConfig.receiveControl.frameExpectation[slot] = IfxPsi5_FrameExpectation_expected;
        }
        else
        {
            psi5ChannelConfig.receiveControl.frameExpectation[slot] = IfxPsi5_FrameExpectation_notExpected;
        }
    }

    /* initialize channels*/
    int chn = 0;

    for (chn = 0; chn < NUM_TESTED_CHANNELS; ++chn)
    {
        psi5ChannelConfig.channelId = (IfxPsi5_ChannelId)chn;

        /* TODO: currently no IOCRx.ALTI config field*/
        /*unsigned                alti = 0;*/

        /* Configure pins*/
        IfxPsi5_Psi5_PinsConfig tempPin;

        if (chn == 0)
        {
            tempPin.out                  = &IfxPsi5_TX0_P00_2_OUT;
            tempPin.in                   = &IfxPsi5_RX0A_P00_1_IN;
            tempPin.outMode              = IfxPort_OutputMode_pushPull;
            tempPin.inMode               = IfxPort_InputMode_pullDown;
            tempPin.pinDriver            = IfxPort_PadDriver_cmosAutomotiveSpeed3; // pad driver mode
            psi5ChannelConfig.pinsConfig = &tempPin;
        }

        else
        {
            IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, 0);
        }

        IfxPsi5_Psi5_initChannel(&g_Psi5.psi5Channel[chn], &psi5ChannelConfig);
    }
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxPsi5Demo_run(void)
{
    printf("IfxPsi5Demo_run() called\n");
    int      errors      = 0;
    unsigned frameOffset = 0;

    int      i;

    for (i = 0; i < 5; ++i)
    {
        printf("Waiting for frame #%d\n", i + 1);
        int chn;

        for (chn = 0; chn < NUM_TESTED_CHANNELS; ++chn)
        {
            IfxPsi5_Psi5_Frame frame;

            while (!IfxPsi5_Psi5_readChannelFrame(&g_Psi5.psi5Channel[chn], &frame))
            {}

            printf("Chn%d: 0x%08lx 0x%08lx\n",
                (int)g_Psi5.psi5Channel[chn].channelId,
                frame.rdm.lowWord, frame.rdm.highWord);

            unsigned expected = (unsigned)g_Psi5.psi5Channel[chn].channelId * 0x40;

            if (i == 0)
            {
                frameOffset = frame.frame.readData & 0x3f; // capture first frame offset
            }
            else
            {
                ++frameOffset; // increment initial frame offset
            }

            expected += frameOffset;

            if (expected != frame.frame.readData)
            {
                ++errors;
            }
        }
    }

    if (errors)
    {
        printf("ERROR: received data doesn't match with expected data (%d mismatches)\n", errors);
    }

    else
    {
        printf("OK: received data matches with expected data\n");
    }
}

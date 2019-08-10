/**
 * \file Template.c
 * \brief Demo Template
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
#include "VadcQueueTransferDemo.h"
#include <Cpu/Std/IfxCpu.h>

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
App_VadcQueueTransfer g_VadcQueueTransfer; /**< \brief Demo information */

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
void VadcQueueTransferDemo_init(void)
{
    /* VADC Configuration */
    /* disable pull devices for analog pads of P40 (assigned to some analog pins)*/
    P40_IOCR0.U = 0x00000000;

    /* create configuration*/
    IfxVadc_Adc_Config adcConfig;
    IfxVadc_Adc_initModuleConfig(&adcConfig, &MODULE_VADC);

    /* initialize module*/
    IfxVadc_Adc_initModule(&g_VadcQueueTransfer.vadc, &adcConfig);

    /* create group config*/
    IfxVadc_Adc_GroupConfig adcGroupConfig;
    IfxVadc_Adc_initGroupConfig(&adcGroupConfig, &g_VadcQueueTransfer.vadc);

    /* with group 1 */
    adcGroupConfig.groupId = IfxVadc_GroupId_1;
    adcGroupConfig.master  = adcGroupConfig.groupId;

    /* enable queue source */
    adcGroupConfig.arbiter.requestSlotQueueEnabled = TRUE;

    /* enable all gates in "always" mode (no edge detection)*/
    adcGroupConfig.queueRequest.triggerConfig.gatingMode = IfxVadc_GatingMode_always;

    /* initialize the group*/
    IfxVadc_Adc_initGroup(&g_VadcQueueTransfer.adcGroup, &adcGroupConfig);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void VadcQueueTransferDemo_run(void)
{
    printf("VadcQueueTransferDemo_run() called\n");


    printf("Queued transfer of a single channel\n");

    {
        /* create channel config*/
        IfxVadc_Adc_ChannelConfig adcChannelConfig;
        IfxVadc_Adc_initChannelConfig(&adcChannelConfig, &g_VadcQueueTransfer.adcGroup);

        /* change channel (default is ChannelId_0, change to ChannelId_3)*/
        adcChannelConfig.channelId = IfxVadc_ChannelId_3;

        /* initialize the channel*/
        IfxVadc_Adc_Channel adcChannel;
        IfxVadc_Adc_initChannel(&adcChannel, &adcChannelConfig);

        /* Add channel to queue with refill enabled*/
        IfxVadc_Adc_addToQueue(&adcChannel, IFXVADC_QUEUE_REFILL);

        /* start the Queue*/
        IfxVadc_Adc_startQueue(&g_VadcQueueTransfer.adcGroup);

        /* get 10 results */
        uint32 i;

        for (i = 0; i < 10; ++i)
        {
            unsigned     group   = adcChannel.group->groupId;
            unsigned     channel = adcChannel.channel;

            /* wait for valid result*/
            Ifx_VADC_RES conversionResult;

            do
            {
                conversionResult = IfxVadc_Adc_getResult(&adcChannel);
            } while (!conversionResult.B.VF);

            /* print result, check with expected value*/
            {
                uint32 actual = conversionResult.B.RESULT;

                /* FIXME result verification pending ??*/
                printf("Group %d Channel %d: %u, result : %u\n", group, channel, actual);
            }
        }

        /* stop the queue */
        IfxVadc_Adc_clearQueue(&g_VadcQueueTransfer.adcGroup);
    }

    printf("Queued transfers of three channels\n");

    {
        uint32                    chnIx;
        /* IMPORTANT: for deterministic results we have to disable the queue gate
         * while filling the queue, otherwise results could be output in the wrong order */
        unsigned                  savedGate = g_VadcQueueTransfer.adcGroup.module.vadc->G[g_VadcQueueTransfer.adcGroup.groupId].QMR0.B.ENGT;
        g_VadcQueueTransfer.adcGroup.module.vadc->G[g_VadcQueueTransfer.adcGroup.groupId].QMR0.B.ENGT = 0;

        /* create channel config */
        IfxVadc_Adc_ChannelConfig adcChannelConfig[3];
        IfxVadc_Adc_Channel       adcChannel[3];

        for (chnIx = 0; chnIx < 3; ++chnIx)
        {
            IfxVadc_Adc_initChannelConfig(&adcChannelConfig[chnIx], &g_VadcQueueTransfer.adcGroup);

            adcChannelConfig[chnIx].channelId      = (IfxVadc_ChannelId)(chnIx);
            adcChannelConfig[chnIx].resultRegister = IfxVadc_ChannelResult_1; /* use result register #1 for all channels */

            /* initialize the channel */
            IfxVadc_Adc_initChannel(&adcChannel[chnIx], &adcChannelConfig[chnIx]);

            /* Add channel to queue with refill enabled */
            IfxVadc_Adc_addToQueue(&adcChannel[chnIx], IFXVADC_QUEUE_REFILL);
        }

        /* restore previous gate config */
        g_VadcQueueTransfer.adcGroup.module.vadc->G[g_VadcQueueTransfer.adcGroup.groupId].QMR0.B.ENGT = savedGate;

        /* start the Queue */
        IfxVadc_Adc_startQueue(&g_VadcQueueTransfer.adcGroup); /* the queue has already been started in previous test */

        /* get 10 results for all 3 channels and store in temporary buffer */
        Ifx_VADC_RES resultTrace[3 * 10];

        uint32       i;

        for (i = 0; i < 3 * 10; ++i)
        {
            unsigned     chnIx = i % 3;

            /* wait for valid result */
            Ifx_VADC_RES conversionResult;

            do
            {
                conversionResult = IfxVadc_Adc_getResult(&adcChannel[chnIx]);
            } while (!conversionResult.B.VF);

            /* store result */
            resultTrace[i] = conversionResult;
        }

        /* stop the queue */
        IfxVadc_Adc_clearQueue(&g_VadcQueueTransfer.adcGroup);

        /* check results in buffer */
        for (i = 0; i < 3 * 10; ++i)
        {
            unsigned chnIx   = i % 3;
            unsigned group   = adcChannel[chnIx].group->groupId;
            unsigned channel = adcChannel[chnIx].channel;
            uint32   actual  = resultTrace[i].B.RESULT;
            printf("Group %d Channel %d: %u, result : %u\n", group, channel, actual);
        }
    }
}

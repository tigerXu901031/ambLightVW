/**
 * \file Ccu6IcuDemo.c
 * \brief Demo Ccu6IcuDemo
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
#include "Ccu6IcuDemo.h"

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

App_Ccu6Icu g_Ccu6Icu; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_Ccu6Icu_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Capture
 * \{ */

IFX_INTERRUPT(ccu6_ISR_Icu, 0, ISR_PRIORITY_CCU6_ICU);

/** \} */

/** \} */

/** \brief Handle Capture interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_CCU6_ICU
 * \isrPriority \ref ISR_PRIORITY_CCU6_ICU
 *
 */
void ccu6_ISR_Icu(void)
{
    IfxCpu_enableInterrupts();

    IfxCcu6_clearInterruptStatusFlag(&MODULE_CCU60, IfxCcu6_InterruptSource_cc60RisingEdge);

    /* store the time stamp in an array */
    g_Ccu6Icu.timeStamp[g_Ccu6Icu.count] = IfxCcu6_Icu_getTimeStamp(&g_Ccu6Icu.drivers.icuChannel);
    g_Ccu6Icu.count++;
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void Ccu6IcuDemo_init(void)
{
    /* disable interrupts */
    boolean            interruptState = IfxCpu_disableInterrupts();

    /* create configuration */
    IfxCcu6_Icu_Config icuConfig;
    IfxCcu6_Icu_initModuleConfig(&icuConfig, &MODULE_CCU60);

    /* configure the frequency of the timer in case of internal start */
    icuConfig.frequency = 400000;

    /* configure the period of the timer */
    icuConfig.period = 100;

    /* configure the clock for internal mode */
    icuConfig.clock.extClockEnabled = FALSE;

    /* configure count operation */
    icuConfig.countMode    = IfxCcu6_T12CountMode_edgeAligned;
    icuConfig.counterValue = 0;

    /* initialize the module */
    IfxCcu6_Icu_initModule(&g_Ccu6Icu.drivers.icu, &icuConfig);

    /* create Icu channel config */
    IfxCcu6_Icu_ChannelConfig icuChannelConfig;
    IfxCcu6_Icu_initChannelConfig(&icuChannelConfig, &MODULE_CCU60);

    /* configure the channel */
    icuChannelConfig.channelId   = IfxCcu6_T12Channel_0;
    icuChannelConfig.channelMode = IfxCcu6_T12ChannelMode_doubleRegisterCaptureRising;

    /* configure the interrupts */
    icuChannelConfig.interrupt1.source         = IfxCcu6_InterruptSource_cc60RisingEdge;
    icuChannelConfig.interrupt1.serviceRequest = IfxCcu6_ServiceRequest_2;
    icuChannelConfig.interrupt1.priority       = ISR_PRIORITY_CCU6_ICU;
    icuChannelConfig.interrupt1.typeOfService  = IfxSrc_Tos_cpu0;

    /* configure input and output triggers */
    icuChannelConfig.trigger.extInputTrigger = NULL_PTR;

    /* pin configuration, in case of multi input capture mode select the respective CC6xIn and CCPOSxIn pins of the selected channel */
    const IfxCcu6_Icu_Pins pins = {
        &IfxCcu60_CC60INA_P02_0_IN, /* CC60In pin */
        NULL_PTR,                   /* CC61In pin not used */
        NULL_PTR,                   /* CC62In pin not used */
        NULL_PTR,                   /* CCPOS0In pin not used */
        NULL_PTR,                   /* CCPOS1In pin not used */
        NULL_PTR,                   /* CCPOS2In pin not used */
        IfxPort_InputMode_pullUp,
        IfxPort_InputMode_pullUp,
        NULL_PTR,
        NULL_PTR,
        IfxPort_InputMode_pullUp
    };
    icuChannelConfig.pins = &pins;

    /* configure multi input capture mode */
    icuChannelConfig.multiInputCaptureEnabled = FALSE;

    /* initialize the channel */
    IfxCcu6_Icu_initChannel(&g_Ccu6Icu.drivers.icuChannel, &icuChannelConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    printf("Ccu6 Icu is initialised\n");

    IfxCcu6_Icu_startCapture(&g_Ccu6Icu.drivers.icuChannel);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void Ccu6IcuDemo_run(void)
{}

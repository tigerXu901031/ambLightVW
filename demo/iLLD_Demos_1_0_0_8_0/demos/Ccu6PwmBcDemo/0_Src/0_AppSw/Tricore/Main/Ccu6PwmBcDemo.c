/**
 * \file Ccu6PwmBcDemo.c
 * \brief Demo Ccu6PwmBcDemo
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
#include "Ccu6PwmBcDemo.h"

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

App_Ccu6PwmBc g_Ccu6PwmBc; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

uint8 controlTable[6][3] = {{1, 5, 17},
                            {2, 3, 36},
                            {3, 1, 6 },
                            {4, 6, 18},
                            {5, 4, 24},
                            {6, 2, 9 }};

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_Ccu6PwmBc_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Transmit
 * \{ */

IFX_INTERRUPT(ccu6_ISR_PwmBc, 0, ISR_PRIORITY_CCU6_PWMBC);

/** \} */

/** \} */

/** \brief Handle Capture interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_CCU6_PWMBC
 * \isrPriority \ref ISR_PRIORITY_CCU6_PWMBC
 *
 */
void ccu6_ISR_PwmBc(void)
{
    IfxCpu_enableInterrupts();

    IfxCcu6_clearInterruptStatusFlag(&MODULE_CCU60, IfxCcu6_InterruptSource_cc61FallingEdge);

    IfxCcu6_PwmBc_updateHallPattern(&g_Ccu6PwmBc.drivers.pwmBc, controlTable);

    /* get the current motor speed */
    g_Ccu6PwmBc.speed = IfxCcu6_PwmBc_getMotorSpeed(&g_Ccu6PwmBc.drivers.pwmBc);
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void Ccu6PwmBcDemo_init(void)
{
    /* disable interrupts */
    boolean              interruptState = IfxCpu_disableInterrupts();

    /* create configuration */
    IfxCcu6_PwmBc_Config pwmBcConfig;
    IfxCcu6_PwmBc_initModuleConfig(&pwmBcConfig, &MODULE_CCU60);

    /* configure the frequencies of both the timers */
    pwmBcConfig.base.t12Frequency = 400000;
    pwmBcConfig.base.t13Frequency = 400000;

    /* configure the periods of both the timers */
    pwmBcConfig.base.t12Period = 100;
    pwmBcConfig.base.t13Period = 100;

    /* configure the phase delay and noise filter for hall input */
    pwmBcConfig.base.phaseDelay  = 20;
    pwmBcConfig.base.noiseFilter = 10;

    /* select the active state of the output */
    pwmBcConfig.base.activeState = Ifx_ActiveState_high;

    /* configure timer12 */
    pwmBcConfig.timer12.countMode    = IfxCcu6_T12CountMode_edgeAligned;
    pwmBcConfig.timer12.counterValue = 0;

    /* configure timer13 */
    pwmBcConfig.timer13.counterValue = 0;
    pwmBcConfig.timer13.compareValue = 100;

    /* configure hall sync event that starts the hall input pattern evaluation */
    pwmBcConfig.hallSyncEvent = IfxCcu6_HallSensorTriggerMode_t13PM;

    /* configure multi channel control */
    pwmBcConfig.multiChannelControl.switchingSelect = IfxCcu6_MultiChannelSwitchingSelect_t12Channel1CompareMatch;
    pwmBcConfig.multiChannelControl.switchingSync   = IfxCcu6_MultiChannelSwitchingSync_t13ZeroMatch;

    /* pin configuration */
    const IfxCcu6_PwmBc_Pins pins = {
        &IfxCcu60_CC60_P02_0_OUT,              /* CC60Out pin */
        &IfxCcu60_CC61_P02_2_OUT,              /* CC61Out pin */
        &IfxCcu60_CC62_P02_4_OUT,              /* CC62Out pin */
        &IfxCcu60_COUT60_P02_1_OUT,            /* COUT60 pin */
        &IfxCcu60_COUT61_P02_3_OUT,            /* COUT61 pin */
        &IfxCcu60_COUT62_P02_5_OUT,            /* COUT62 pin */
        NULL_PTR,                              /* COUT63 pin not used */

        &IfxCcu60_CCPOS0A_P02_6_IN,            /* CCPOS0In pin */
        &IfxCcu60_CCPOS1A_P02_7_IN,            /* CCPOS1In pin */
        &IfxCcu60_CCPOS2A_P02_8_IN,            /* CCPOS2In pin */

        IfxPort_OutputMode_pushPull,
        IfxPort_PadDriver_cmosAutomotiveSpeed1,
        IfxPort_InputMode_pullUp,

        NULL_PTR,
        NULL_PTR,
        IfxPort_InputMode_pullUp
    };
    pwmBcConfig.pins = &pins;

    /* configure the interrupts */
    pwmBcConfig.interrupt1.source         = IfxCcu6_InterruptSource_cc61FallingEdge;
    pwmBcConfig.interrupt1.serviceRequest = IfxCcu6_ServiceRequest_2;
    pwmBcConfig.interrupt1.priority       = ISR_PRIORITY_CCU6_PWMBC;
    pwmBcConfig.interrupt1.typeOfService  = IfxSrc_Tos_cpu0;

    /* configure input and output triggers */
    pwmBcConfig.trigger.t12ExtInputTrigger   = NULL_PTR;
    pwmBcConfig.trigger.t13ExtInputTrigger   = NULL_PTR;
    pwmBcConfig.trigger.t13InSyncWithT12     = FALSE;

    pwmBcConfig.trigger.outputTriggerEnabled = TRUE;
    pwmBcConfig.trigger.outputLine           = IfxCcu6_TrigOut_0;
    pwmBcConfig.trigger.outputTrigger        = IfxCcu6_TrigSel_cout63;

    /* initialize the module */
    IfxCcu6_PwmBc_initModule(&g_Ccu6PwmBc.drivers.pwmBc, &pwmBcConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    printf("Ccu6 PwmBc is initialised\n");

    IfxCcu6_PwmBc_start(&g_Ccu6PwmBc.drivers.pwmBc);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void Ccu6PwmBcDemo_run(void)
{}

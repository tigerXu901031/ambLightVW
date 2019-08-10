/**
 * \file Ccu6TpwmDemo.c
 * \brief Demo Ccu6TpwmDemo
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
#include "Ccu6TpwmDemo.h"

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

App_Ccu6Tpwm g_Ccu6Tpwm; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_Ccu6Tpwm_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Transmit
 * \{ */

IFX_INTERRUPT(ccu6_ISR_Tpwm, 0, ISR_PRIORITY_CCU6_TPWM);

/** \} */

/** \} */

/** \brief Handle <isrName> interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_TPWM
 * \isrPriority \ref ISR_PRIORITY_TPWM
 *
 */
void ccu6_ISR_Tpwm(void)
{
    IfxCpu_enableInterrupts();

    IfxCcu6_clearInterruptStatusFlag(&MODULE_CCU60, IfxCcu6_InterruptSource_t13CompareMatch);
    g_Ccu6Tpwm.count++;
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void Ccu6TpwmDemo_init(void)
{
    /* disable interrupts */
    boolean             interruptState = IfxCpu_disableInterrupts();

    /* create configuration */
    IfxCcu6_TPwm_Config tPwmConfig;
    IfxCcu6_TPwm_initModuleConfig(&tPwmConfig, &MODULE_CCU60);

    /* configure the frequency of the timer in case of internal start */
    /* this frequency will be set for the timer block selected later */
    tPwmConfig.base.frequency = 400000;

    /* configure the period of the timer */
    tPwmConfig.base.period = 100;

    /* configure the waiting time in case of delayed T13 start in sync with T12 */
    tPwmConfig.base.waitingTime = 20;

    /* select the active state of the output */
    tPwmConfig.base.activeState = Ifx_ActiveState_high;

    /* select the timer through which PWM is to be generated */
    tPwmConfig.timer = IfxCcu6_TimerId_t13;

    /* configure the clock for internal mode */
    tPwmConfig.clock.t13ExtClockEnabled = FALSE;

    /* configure the selcted timer block */
    tPwmConfig.timer13.counterValue = 0;
    tPwmConfig.timer13.compareValue = 100;

    /*select the channel out for modulation */
    tPwmConfig.channelOut = IfxCcu6_ChannelOut_cout3;

    /* pin configuration */
    const IfxCcu6_TPwm_Pins pins = {
        NULL_PTR,                              /* CC60Out pin not used */
        NULL_PTR,                              /* CC61Out pin not used */
        NULL_PTR,                              /* CC62Out pin not used */
        NULL_PTR,                              /* COUT60 pin not used */
        NULL_PTR,                              /* COUT61 pin not used */
        NULL_PTR,                              /* COUT62 pin not used */
        &IfxCcu60_COUT63_P00_0_OUT,            /* COUT63 pin */
        IfxPort_OutputMode_pushPull,
        IfxPort_PadDriver_cmosAutomotiveSpeed1,
        NULL_PTR,
        NULL_PTR,
        IfxPort_InputMode_pullUp
    };
    tPwmConfig.pins = &pins;

    /* configure the interrupts */
    tPwmConfig.interrupt1.source         = IfxCcu6_InterruptSource_t13CompareMatch;
    tPwmConfig.interrupt1.serviceRequest = IfxCcu6_ServiceRequest_2;
    tPwmConfig.interrupt1.priority       = ISR_PRIORITY_CCU6_TPWM;
    tPwmConfig.interrupt1.typeOfService  = IfxSrc_Tos_cpu0;

    /* configure input and output triggers */
    tPwmConfig.trigger.t12ExtInputTrigger   = NULL_PTR;
    tPwmConfig.trigger.t13ExtInputTrigger   = NULL_PTR;
    tPwmConfig.trigger.t13InSyncWithT12     = FALSE;

    tPwmConfig.trigger.outputTriggerEnabled = FALSE;

    /* initialize the module */
    IfxCcu6_TPwm_initModule(&g_Ccu6Tpwm.drivers.tPwm, &tPwmConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    printf("Ccu6 Tpwm is initialised\n");

    IfxCcu6_TPwm_start(&g_Ccu6Tpwm.drivers.tPwm);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void Ccu6TpwmDemo_run(void)
{}

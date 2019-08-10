/**
 * \file Ccu6TimerDemo.c
 * \brief Demo Ccu6TimerDemo
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
#include "Ccu6TimerDemo.h"

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

App_Ccu6Timer g_Ccu6Timer; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_Ccu6Timer_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Timer
 * \{ */

IFX_INTERRUPT(ccu6_ISR_Timer, 0, ISR_PRIORITY_CCU6_TIMER);

/** \} */

/** \} */

/** \brief Handle Timer interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_TIMER
 * \isrPriority \ref ISR_PRIORITY_TIMER
 *
 */
void ccu6_ISR_Timer(void)
{
    IfxCpu_enableInterrupts();

    IfxCcu6_clearInterruptStatusFlag(&MODULE_CCU60, IfxCcu6_InterruptSource_t13PeriodMatch);
    g_Ccu6Timer.count++;
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void Ccu6TimerDemo_init(void)
{
    /* disable interrupts */
    boolean              interruptState = IfxCpu_disableInterrupts();

    /* create configuration */
    IfxCcu6_Timer_Config timerConfig;
    IfxCcu6_Timer_initModuleConfig(&timerConfig, &MODULE_CCU60);

    /* configure the frequency of the timer in case of internal start */
    /* this frequency will be set for the timer block selected later */
    timerConfig.base.t13Frequency = 400000;

    /* configure the period of the timer */
    timerConfig.base.t13Period = 100;

    /* select the timer that needs to be started */
    timerConfig.timer = IfxCcu6_TimerId_t13;

    /* select the synchronous operation if both timers need to be start at the same time */
    /* previous selection of timer block can be ignored in this mode */
    timerConfig.synchronousOperation = FALSE;

    /* configure the clock for internal mode */
    timerConfig.clock.t13ExtClockEnabled   = FALSE;
    timerConfig.clock.t13ExtClockInput     = NULL_PTR;
    timerConfig.clock.t13countingInputMode = IfxCcu6_CountingInputMode_internal;

    /* configure the selected timer block */
    timerConfig.timer13.counterValue = 0;

    /* configure the interrupts */
    timerConfig.interrupt1.source         = IfxCcu6_InterruptSource_t13PeriodMatch;
    timerConfig.interrupt1.serviceRequest = IfxCcu6_ServiceRequest_2;
    timerConfig.interrupt1.priority       = ISR_PRIORITY_CCU6_TIMER;
    timerConfig.interrupt1.typeOfService  = IfxSrc_Tos_cpu0;

    /* configure triggers */
    timerConfig.trigger.t13InSyncWithT12 = FALSE;

    /* initialize the module */
    IfxCcu6_Timer_initModule(&g_Ccu6Timer.drivers.timer, &timerConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    printf("Ccu6 Timer is initialised\n");

    IfxCcu6_Timer_start(&g_Ccu6Timer.drivers.timer);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void Ccu6TimerDemo_run(void)
{}

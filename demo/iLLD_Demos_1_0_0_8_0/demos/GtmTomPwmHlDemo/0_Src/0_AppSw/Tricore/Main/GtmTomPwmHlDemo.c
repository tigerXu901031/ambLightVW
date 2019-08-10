/**
 * \file GtmAtomPwmHlDemo.c
 * \brief Demo GtmAtomPwmHlDemo
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
#include "GtmTomPwmHlDemo.h"

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

App_GtmTomPwmHl g_GtmTomPwmHl; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_GtmTomPwmHl_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Timer
 * \{ */

IFX_INTERRUPT(ISR_Timer, 0, ISR_PRIORITY_TIMER);

/** \} */

/** \} */

/** \brief Handle 1ms interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_TIMER
 * \isrPriority \ref ISR_PRIORITY_TIMER
 *
 */
void ISR_Timer(void)
{
    IfxCpu_enableInterrupts();

    IfxGtm_Tom_Timer_acknowledgeTimerIrq(&g_GtmTomPwmHl.drivers.timer);
    g_GtmTomPwmHl.isrCounter.slotTimer++;

    /* Set PWM duty */
    IfxGtm_Tom_PwmHl *pwmHl = &g_GtmTomPwmHl.drivers.pwm;

    IfxGtm_Tom_Timer *timer = &g_GtmTomPwmHl.drivers.timer;
    Ifx_TimerValue    tOn[1];

    if (isDeadLine(g_GtmTomPwmHl.info.stateDeadline))
    {
        g_GtmTomPwmHl.info.stateDeadline = addTTime(g_GtmTomPwmHl.info.stateDeadline, TimeConst_1s);
        g_GtmTomPwmHl.info.state++;

        if (g_GtmTomPwmHl.info.state >= GtmTomPwmHl_State_count)
        {
            g_GtmTomPwmHl.info.state = GtmTomPwmHl_State_off;
        }

        switch (g_GtmTomPwmHl.info.state)
        {
        case GtmTomPwmHl_State_off:
            /* Set PWM to off */
            IfxGtm_Tom_PwmHl_setMode(pwmHl, Ifx_Pwm_Mode_off);
            IfxGtm_Tom_Timer_disableUpdate(timer);
            IfxGtm_Tom_PwmHl_setOnTime(pwmHl, NULL_PTR);
            IfxGtm_Tom_Timer_applyUpdate(timer);
            break;
        case GtmTomPwmHl_State_duty0:
            /* Set 0% duty cycle, center aligned */
            IfxGtm_Tom_PwmHl_setMode(pwmHl, Ifx_Pwm_Mode_centerAligned);
            tOn[0] = 0;
            IfxGtm_Tom_Timer_disableUpdate(timer);
            IfxGtm_Tom_PwmHl_setOnTime(pwmHl, &tOn[0]);
            IfxGtm_Tom_Timer_applyUpdate(timer);
            break;
        case GtmTomPwmHl_State_duty50:
            /* Set 50% duty cycle, center aligned */
            tOn[0] = IfxGtm_Tom_Timer_getPeriod(timer) / 2;
            IfxGtm_Tom_Timer_disableUpdate(timer);
            IfxGtm_Tom_PwmHl_setOnTime(pwmHl, &tOn[0]);
            IfxGtm_Tom_Timer_applyUpdate(timer);
            break;
        case GtmTomPwmHl_State_duty100:
            /* Set 100% duty cycle, center aligned */
            tOn[0] = IfxGtm_Tom_Timer_getPeriod(timer);
            IfxGtm_Tom_Timer_disableUpdate(timer);
            IfxGtm_Tom_PwmHl_setOnTime(pwmHl, &tOn[0]);
            IfxGtm_Tom_Timer_applyUpdate(timer);
            break;
        default:
            /* Set PWM to off */
            IfxGtm_Tom_PwmHl_setMode(pwmHl, Ifx_Pwm_Mode_off);
            IfxGtm_Tom_Timer_disableUpdate(timer);
            IfxGtm_Tom_PwmHl_setOnTime(pwmHl, NULL_PTR);
            IfxGtm_Tom_Timer_applyUpdate(timer);
            break;
        }
    }
}


void GtmTomPwmHl_initTimer(void)
{
    {   /* GTM TOM configuration */
        IfxGtm_Tom_Timer_Config timerConfig;
        IfxGtm_Tom_PwmHl_Config pwmHlConfig;

        IfxGtm_Tom_Timer_initConfig(&timerConfig, &MODULE_GTM);
        timerConfig.base.frequency                  = 10000;
        timerConfig.base.isrPriority                = ISR_PRIORITY(INTERRUPT_TIMER);
        timerConfig.base.isrProvider                = ISR_PROVIDER(INTERRUPT_TIMER);
        timerConfig.base.minResolution              = (1.0 / timerConfig.base.frequency) / 1000;
        timerConfig.base.trigger.enabled            = FALSE;
        timerConfig.tom                             = IfxGtm_Tom_1;
        timerConfig.timerChannel                    = IfxGtm_Tom_Ch_0;
        timerConfig.clock                           = IfxGtm_Cmu_Clk_0;

        timerConfig.triggerOut                      = &IfxGtm_TOM1_0_TOUT9_P00_0_OUT;
        timerConfig.base.trigger.outputEnabled      = TRUE;
        timerConfig.base.trigger.enabled            = TRUE;
        timerConfig.base.trigger.triggerPoint       = 500;
        timerConfig.base.trigger.risingEdgeAtPeriod = TRUE;

        IfxGtm_Tom_Timer_init(&g_GtmTomPwmHl.drivers.timer, &timerConfig);

        IfxGtm_Tom_PwmHl_initConfig(&pwmHlConfig);
        IfxGtm_Tom_ToutMapP ccx[1]   = {&IfxGtm_TOM1_1_TOUT10_P00_1_OUT};
        IfxGtm_Tom_ToutMapP coutx[1] = {&IfxGtm_TOM1_2_TOUT12_P00_3_OUT};
        pwmHlConfig.timer                 = &g_GtmTomPwmHl.drivers.timer;
        pwmHlConfig.tom                   = timerConfig.tom;
        pwmHlConfig.base.deadtime         = 2e-6;
        pwmHlConfig.base.minPulse         = 1e-6;
        pwmHlConfig.base.channelCount     = 1;
        pwmHlConfig.base.emergencyEnabled = FALSE;
        pwmHlConfig.base.outputMode       = IfxPort_OutputMode_pushPull;
        pwmHlConfig.base.outputDriver     = IfxPort_PadDriver_cmosAutomotiveSpeed1;
        pwmHlConfig.base.ccxActiveState   = Ifx_ActiveState_high;
        pwmHlConfig.base.coutxActiveState = Ifx_ActiveState_high;
        pwmHlConfig.ccx                   = ccx;
        pwmHlConfig.coutx                 = coutx;

        IfxGtm_Tom_PwmHl_init(&g_GtmTomPwmHl.drivers.pwm, &pwmHlConfig);

        IfxGtm_Tom_Timer_run(&g_GtmTomPwmHl.drivers.timer);
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void GtmTomPwmHlDemo_init(void)
{
    /* disable interrupts */
    boolean  interruptState = IfxCpu_disableInterrupts();

    /** - GTM clocks */
    Ifx_GTM *gtm = &MODULE_GTM;
    g_GtmTomPwmHl.info.gtmFreq = IfxGtm_Cmu_getModuleFrequency(gtm);
    IfxGtm_enable(gtm);

    /* Set the global clock frequencies */
    IfxGtm_Cmu_setGclkFrequency(gtm, g_GtmTomPwmHl.info.gtmFreq);
    g_GtmTomPwmHl.info.gtmGclkFreq = IfxGtm_Cmu_getGclkFrequency(gtm);

    IfxGtm_Cmu_setClkFrequency(gtm, IfxGtm_Cmu_Clk_0, g_GtmTomPwmHl.info.gtmGclkFreq);
    g_GtmTomPwmHl.info.gtmCmuClk0Freq = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_0, TRUE);
    g_GtmTomPwmHl.info.state          = GtmTomPwmHl_State_init;
    g_GtmTomPwmHl.info.stateDeadline  = now();

    /** - Initialise the GTM part */
    GtmTomPwmHl_initTimer();

    printf("Gtm Tom PwmHl is initialised\n");

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    IfxGtm_Cmu_enableClocks(gtm, IFXGTM_CMU_CLKEN_FXCLK | IFXGTM_CMU_CLKEN_CLK0);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void GtmTomPwmHlDemo_run(void)
{}

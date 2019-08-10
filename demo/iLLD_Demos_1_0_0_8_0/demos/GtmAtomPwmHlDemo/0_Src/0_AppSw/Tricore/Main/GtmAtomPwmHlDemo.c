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
#include "GtmAtomPwmHlDemo.h"

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

App_GtmAtomPwmHl g_GtmAtomPwmHl; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_GtmAtomPwmHl_SrcDoc_Main_Interrupt
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

    IfxGtm_Atom_Timer_acknowledgeTimerIrq(&g_GtmAtomPwmHl.drivers.timer);
    g_GtmAtomPwmHl.isrCounter.slotTimer++;

    /* Set PWM duty */
    IfxGtm_Atom_PwmHl *pwmHl = &g_GtmAtomPwmHl.drivers.pwm;

    IfxGtm_Atom_Timer *timer = &g_GtmAtomPwmHl.drivers.timer;
    Ifx_TimerValue     tOn[1];

    if (isDeadLine(g_GtmAtomPwmHl.info.stateDeadline))
    {
        g_GtmAtomPwmHl.info.stateDeadline = addTTime(g_GtmAtomPwmHl.info.stateDeadline, TimeConst_1s);
        g_GtmAtomPwmHl.info.state++;

        if (g_GtmAtomPwmHl.info.state >= GtmAtomPwmHl_State_count)
        {
            g_GtmAtomPwmHl.info.state = GtmAtomPwmHl_State_off;
        }

        switch (g_GtmAtomPwmHl.info.state)
        {
        case GtmAtomPwmHl_State_off:
            /* Set PWM to off */
            IfxGtm_Atom_PwmHl_setMode(pwmHl, Ifx_Pwm_Mode_off);
            IfxGtm_Atom_Timer_disableUpdate(timer);
            IfxGtm_Atom_PwmHl_setOnTime(pwmHl, NULL_PTR);
            IfxGtm_Atom_Timer_applyUpdate(timer);
            break;
        case GtmAtomPwmHl_State_duty0:
            /* Set 0% duty cycle, center aligned */
            IfxGtm_Atom_PwmHl_setMode(pwmHl, Ifx_Pwm_Mode_centerAligned);
            tOn[0] = 0;
            IfxGtm_Atom_Timer_disableUpdate(timer);
            IfxGtm_Atom_PwmHl_setOnTime(pwmHl, &tOn[0]);
            IfxGtm_Atom_Timer_applyUpdate(timer);
            break;
        case GtmAtomPwmHl_State_duty50:
            /* Set 50% duty cycle, center aligned */
            tOn[0] = IfxGtm_Atom_Timer_getPeriod(timer) / 2;
            IfxGtm_Atom_Timer_disableUpdate(timer);
            IfxGtm_Atom_PwmHl_setOnTime(pwmHl, &tOn[0]);
            IfxGtm_Atom_Timer_applyUpdate(timer);
            break;
        case GtmAtomPwmHl_State_duty100:
            /* Set 100% duty cycle, center aligned */
            tOn[0] = IfxGtm_Atom_Timer_getPeriod(timer);
            IfxGtm_Atom_Timer_disableUpdate(timer);
            IfxGtm_Atom_PwmHl_setOnTime(pwmHl, &tOn[0]);
            IfxGtm_Atom_Timer_applyUpdate(timer);
            break;
        default:
            /* Set PWM to off */
            IfxGtm_Atom_PwmHl_setMode(pwmHl, Ifx_Pwm_Mode_off);
            IfxGtm_Atom_Timer_disableUpdate(timer);
            IfxGtm_Atom_PwmHl_setOnTime(pwmHl, NULL_PTR);
            IfxGtm_Atom_Timer_applyUpdate(timer);
            break;
        }
    }
}


void GtmAtomPwmHl_initTimer(void)
{
    {   /* GTM TOM configuration */
        IfxGtm_Atom_Timer_Config timerConfig;
        IfxGtm_Atom_PwmHl_Config pwmHlConfig;

        IfxGtm_Atom_Timer_initConfig(&timerConfig, &MODULE_GTM);
        timerConfig.base.frequency                  = 10000;
        timerConfig.base.isrPriority                = ISR_PRIORITY(INTERRUPT_TIMER);
        timerConfig.base.isrProvider                = ISR_PROVIDER(INTERRUPT_TIMER);
        timerConfig.base.minResolution              = (1.0 / timerConfig.base.frequency) / 1000;
        timerConfig.base.trigger.enabled            = FALSE;
        timerConfig.atom                            = IfxGtm_Atom_0;
        timerConfig.timerChannel                    = IfxGtm_Atom_Ch_0;
        timerConfig.clock                           = IfxGtm_Cmu_Clk_0;

        timerConfig.triggerOut                      = &IfxGtm_ATOM0_0_TOUT9_P00_0_OUT;
        timerConfig.base.trigger.outputEnabled      = TRUE;
        timerConfig.base.trigger.enabled            = TRUE;
        timerConfig.base.trigger.triggerPoint       = 500;
        timerConfig.base.trigger.risingEdgeAtPeriod = TRUE;

        IfxGtm_Atom_Timer_init(&g_GtmAtomPwmHl.drivers.timer, &timerConfig);

        IfxGtm_Atom_PwmHl_initConfig(&pwmHlConfig);
        IfxGtm_Atom_ToutMapP ccx[1]   = {&IfxGtm_ATOM0_1_TOUT10_P00_1_OUT};
        IfxGtm_Atom_ToutMapP coutx[1] = {&IfxGtm_ATOM0_2_TOUT12_P00_3_OUT};
        pwmHlConfig.timer                 = &g_GtmAtomPwmHl.drivers.timer;
        pwmHlConfig.atom                  = timerConfig.atom;
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

        IfxGtm_Atom_PwmHl_init(&g_GtmAtomPwmHl.drivers.pwm, &pwmHlConfig);

        IfxGtm_Atom_Timer_run(&g_GtmAtomPwmHl.drivers.timer);
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void GtmAtomPwmHlDemo_init(void)
{
    /* disable interrupts */
    boolean  interruptState = IfxCpu_disableInterrupts();

    /** - GTM clocks */
    Ifx_GTM *gtm = &MODULE_GTM;
    g_GtmAtomPwmHl.info.gtmFreq = IfxGtm_Cmu_getModuleFrequency(gtm);
    IfxGtm_enable(gtm);

    /* Set the global clock frequencies */
    IfxGtm_Cmu_setGclkFrequency(gtm, g_GtmAtomPwmHl.info.gtmFreq);
    g_GtmAtomPwmHl.info.gtmGclkFreq = IfxGtm_Cmu_getGclkFrequency(gtm);

    IfxGtm_Cmu_setClkFrequency(gtm, IfxGtm_Cmu_Clk_0, g_GtmAtomPwmHl.info.gtmGclkFreq);
    g_GtmAtomPwmHl.info.gtmCmuClk0Freq = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_0, TRUE);
    g_GtmAtomPwmHl.info.state          = GtmAtomPwmHl_State_init;
    g_GtmAtomPwmHl.info.stateDeadline  = now();

    /** - Initialise the GTM part */
    GtmAtomPwmHl_initTimer();

    printf("Gtm Atom PwmHl is initialised\n");

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    IfxGtm_Cmu_enableClocks(gtm, IFXGTM_CMU_CLKEN_FXCLK | IFXGTM_CMU_CLKEN_CLK0);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void GtmAtomPwmHlDemo_run(void)
{}

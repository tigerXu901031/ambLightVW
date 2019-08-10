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
#include "GtmAtomTimerDemo.h"

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

App_GtmAtomTimer g_GtmAtomTimer; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_GtmAtomTimer_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Timer_1ms
 * \{ */

IFX_INTERRUPT(ISR_Timer_1ms, 0, ISR_PRIORITY_TIMER_1MS);

/** \} */

/** \} */

/** \brief Handle 1ms interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_TIMER_1MS
 * \isrPriority \ref ISR_PRIORITY_TIMER_1MS
 *
 */
void ISR_Timer_1ms(void)
{
    IfxCpu_enableInterrupts();

    IfxGtm_Atom_Timer_acknowledgeTimerIrq(&g_GtmAtomTimer.drivers.timerOneMs);
    g_GtmAtomTimer.isrCounter.slotOneMs++;
}


void GtmAtomTimer_initTimer(void)
{
    {   /* GTM TOM configuration */
        IfxGtm_Atom_Timer_Config timerConfig;
        IfxGtm_Atom_Timer_initConfig(&timerConfig, &MODULE_GTM);
        timerConfig.base.frequency       = 1000;
        timerConfig.base.isrPriority     = ISR_PRIORITY(INTERRUPT_TIMER_1MS);
        timerConfig.base.isrProvider     = ISR_PROVIDER(INTERRUPT_TIMER_1MS);
        timerConfig.base.minResolution   = (1.0 / timerConfig.base.frequency) / 1000;
        timerConfig.base.trigger.enabled = FALSE;
        timerConfig.atom                 = IfxGtm_Atom_0;
        timerConfig.timerChannel         = IfxGtm_Atom_Ch_0;
        timerConfig.clock                = IfxGtm_Cmu_Clk_0;
        IfxGtm_Atom_Timer_init(&g_GtmAtomTimer.drivers.timerOneMs, &timerConfig);

        IfxGtm_Atom_Timer_run(&g_GtmAtomTimer.drivers.timerOneMs);
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void GtmAtomTimerDemo_init(void)
{
    /* disable interrupts */
    boolean  interruptState = IfxCpu_disableInterrupts();

    /** - GTM clocks */
    Ifx_GTM *gtm = &MODULE_GTM;
    g_GtmAtomTimer.info.gtmFreq = IfxGtm_Cmu_getModuleFrequency(gtm);
    IfxGtm_enable(gtm);

    /* Set the global clock frequencies */
    IfxGtm_Cmu_setGclkFrequency(gtm, g_GtmAtomTimer.info.gtmFreq);
    g_GtmAtomTimer.info.gtmGclkFreq = IfxGtm_Cmu_getGclkFrequency(gtm);

    IfxGtm_Cmu_setClkFrequency(gtm, IfxGtm_Cmu_Clk_0, g_GtmAtomTimer.info.gtmGclkFreq);
    g_GtmAtomTimer.info.gtmCmuClk0Freq = IfxGtm_Cmu_getClkFrequency(gtm, IfxGtm_Cmu_Clk_0, TRUE);

    /** - Initialise the GTM part */
    GtmAtomTimer_initTimer();

    printf("Gtm Atom Timer is initialised\n");

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    IfxGtm_Cmu_enableClocks(gtm, IFXGTM_CMU_CLKEN_FXCLK | IFXGTM_CMU_CLKEN_CLK0 | IFXGTM_CMU_CLKEN_CLK1);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void GtmAtomTimerDemo_run(void)
{}

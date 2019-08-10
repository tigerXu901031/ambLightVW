/**
 * \file IomDemo.c
 * \brief Iom Demo
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
#include "IomDemo.h"
#include "IfxIom_Iom.h"
#include "IfxGtm_Tom_PwmHl.h"
#include "IfxScuWdt.h"

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
App_Iom g_Iom; /**< \brief  Iom global data*/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

volatile uint64 pattern_ok     = 0;
volatile uint64 pattern_not_ok = 0;

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_Demo_IomDemo_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Iom TimerReference(TIMERREF) & TimerReference(TIMERMON)
 * \{ */

IFX_INTERRUPT(gtmTimerInterruptHandlerref, 0, ISR_PRIORITY_TIMERREF);
IFX_INTERRUPT(gtmTimerInterruptHandlermon, 0, ISR_PRIORITY_TIMERMON);
/** \} */
/** \} */

/** \brief Handle Iom Reference Signal interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_INTERRUPT_GTM_INT2
 * \isrPriority \ref ISR_PRIORITY_INTERRUPT_TIMERREF
 *
 */
void gtmTimerInterruptHandlerref(void)
{
    IfxGtm_Tom_Timer *timer = &g_Iom.tomTimerref;
    Ifx_TimerValue    tOn;

    if (IfxGtm_Tom_Timer_acknowledgeTimerIrq(timer))
    {
        g_Iom.counterTimer++;
        /* Set 50% duty cycle, center aligned */

        tOn = IfxGtm_Tom_Timer_getPeriod(timer) / 2;
        IfxGtm_Tom_Timer_disableUpdate(timer);
        IfxGtm_Tom_PwmHl_setOnTime(&g_Iom.tomPwmref, &tOn);
        IfxGtm_Tom_Timer_applyUpdate(timer);
    }
}


/** \brief Handle Iom Monitor Signal interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_INTERRUPT_GTM_INT4
 * \isrPriority \ref ISR_PRIORITY_INTERRUPT_TIMERMON
 *
 */
void gtmTimerInterruptHandlermon(void)
{
    IfxGtm_Tom_Timer *timer = &g_Iom.tomTimermon;
    Ifx_TimerValue    tOn;

    if (IfxGtm_Tom_Timer_acknowledgeTimerIrq(timer))
    {
        g_Iom.counterTimer++;
        /* Set 50% duty cycle, center aligned */

        tOn = IfxGtm_Tom_Timer_getPeriod(timer) / 2;
        IfxGtm_Tom_Timer_disableUpdate(timer);
        IfxGtm_Tom_PwmHl_setOnTime(&g_Iom.tomPwmmon, &tOn);
        IfxGtm_Tom_Timer_applyUpdate(timer);
    }
}


/** \brief Iom FPC supplied configuration
 *
 * This function configures FPC(Filter & Prescaler Channel) block of Iom with
 *	supplied configuration
 */
static void fpcSuppliedConfig(void)
{
    g_Iom.fpcConfig.channelId           = IfxIom_FpcChannelId_14;
    g_Iom.fpcConfig.filterMode          = IfxIom_FilterMode_delayedDebounce;
    g_Iom.fpcConfig.comparatorThreshold = 100;
    g_Iom.fpcConfig.monitorSignal       = IfxIom_MonitorSignal_0;
    g_Iom.fpcConfig.referenceSignal     = IfxIom_ReferenceSignal_0;
    g_Iom.fpcConfig.timerReset          = TRUE;
    g_Iom.fpcConfig.edgeType            = IfxIom_EdgeClearType_risingFalling;
}


/** \brief Iom LAM supplied configuration
 *
 * This function configures LAM(Logic Analayser Module) block of Iom with
 *	supplied configuration
 */
static void lamSuppliedConfig(void)
{
    g_Iom.lamConfig.monitorSignalInverted    = FALSE;
    g_Iom.lamConfig.referenceSignalInverted  = FALSE;
    g_Iom.lamConfig.lamMonitorSource         = IfxIom_LamMonitorSource_exoredFpcMonitor;
    g_Iom.lamConfig.lamMode                  = IfxIom_LamRunMode_freeRunning;
    g_Iom.lamConfig.eventSource              = IfxIom_EventSource_reference;
    g_Iom.lamConfig.eventActiveEdgeSelection = IfxIom_EventActiveEdgeSelection_negativeGateEitherClear;
    g_Iom.lamConfig.eventWindowInverted      = FALSE;
    g_Iom.lamConfig.lamMonitorInputChannel   = IfxIom_LamMonitorInputChannel_14;
    g_Iom.lamConfig.lamReferenceInputChannel = IfxIom_LamReferenceInputChannel_14;
    g_Iom.lamConfig.lamId                    = IfxIom_LamId_14;
    g_Iom.lamConfig.eventWindowThreshold     = 100;
}


/** \brief GTM Clock Enable
 *
 * This function enables the GTM clock
 */
static void gtmClockEnable(void)
{
    Ifx_GTM *gtm       = &MODULE_GTM;
    float32  frequency = IfxGtm_Cmu_getModuleFrequency(gtm);

    /* Enables the GTM */
    IfxGtm_enable(gtm);
    /* Set the global clock frequency to the max */
    IfxGtm_Cmu_setGclkFrequency(gtm, frequency);

    /* Set the CMU CLK0 */
    IfxGtm_Cmu_setClkFrequency(gtm, IfxGtm_Cmu_Clk_0, frequency);
}


/** \brief GTM Initialization
 *
 * This function initializes the GTM module for use by the IOM module
 */
static void Iom_initGtm(void)
{
    {
        /* GTM TOM configuration */
        IfxGtm_Tom_Timer_Config timerConfigref;
        IfxGtm_Tom_PwmHl_Config pwmHlConfigref;
        Ifx_TimerValue          triggerPoint = 0;

        IfxGtm_Tom_Timer_initConfig(&timerConfigref, &MODULE_GTM);

        timerConfigref.base.frequency                  = CFG_PWM_FREQUENCYREF;
        timerConfigref.base.isrPriority                = ISR_PRIORITY_TIMERREF;
        timerConfigref.base.isrProvider                = CFG_PWM_ISR_PROVIDER;
        timerConfigref.base.minResolution              = CFG_PWM_MIN_PULSE;
        timerConfigref.base.trigger.enabled            = TRUE;
        timerConfigref.tom                             = IfxGtm_Tom_1;
        timerConfigref.timerChannel                    = IfxGtm_Tom_Ch_3;
        timerConfigref.clock                           = IfxGtm_Tom_Ch_ClkSrc_cmuFxclk0;

        timerConfigref.triggerOut                      = &IfxGtm_TOM1_3_TOUT13_P00_4_OUT;
        timerConfigref.base.trigger.outputEnabled      = TRUE;
        timerConfigref.base.trigger.enabled            = TRUE;
        timerConfigref.base.trigger.triggerPoint       = 500;
        timerConfigref.base.trigger.risingEdgeAtPeriod = TRUE;
        timerConfigref.base.trigger.outputMode         = IfxPort_OutputMode_pushPull;

        IfxGtm_Tom_Timer_init(&g_Iom.tomTimerref, &timerConfigref);
        triggerPoint = (IfxGtm_Tom_Timer_getInputFrequency(&g_Iom.tomTimerref) / IfxGtm_Tom_Timer_getFrequency(&g_Iom.tomTimerref)) * (CFG_PWM_TRIGGER_DUTYCYCLE * (1.0 / (float32)CFG_PWM_FREQUENCYREF));
        IfxGtm_Tom_Timer_setTrigger(&g_Iom.tomTimerref, triggerPoint);

        IfxGtm_Tom_PwmHl_initConfig(&pwmHlConfigref);
        IfxGtm_Tom_ToutMapP ccx[1]   = {&IfxGtm_TOM1_5_TOUT15_P00_6_OUT};
        IfxGtm_Tom_ToutMapP coutx[1] = {&IfxGtm_TOM1_4_TOUT14_P00_5_OUT};
        pwmHlConfigref.timer                 = &g_Iom.tomTimerref;
        pwmHlConfigref.tom                   = IfxGtm_Tom_1;
        pwmHlConfigref.base.deadtime         = CFG_PWM_DEADTIME;
        pwmHlConfigref.base.minPulse         = CFG_PWM_MIN_PULSE;
        pwmHlConfigref.base.channelCount     = 1;
        pwmHlConfigref.base.emergencyEnabled = FALSE;
        pwmHlConfigref.base.outputMode       = IfxPort_OutputMode_pushPull;
        pwmHlConfigref.base.outputDriver     = IfxPort_PadDriver_cmosAutomotiveSpeed1;
        pwmHlConfigref.base.ccxActiveState   = Ifx_ActiveState_high;
        pwmHlConfigref.base.coutxActiveState = Ifx_ActiveState_high;
        pwmHlConfigref.ccx                   = ccx;
        pwmHlConfigref.coutx                 = coutx;

        IfxGtm_Tom_PwmHl_init(&g_Iom.tomPwmref, &pwmHlConfigref);

        IfxGtm_Tom_PwmHl_setMode(&g_Iom.tomPwmref, Ifx_Pwm_Mode_centerAligned);
    }

    /* Monitor config */
    {
        /* GTM TOM configuration */
        IfxGtm_Tom_Timer_Config timerConfigmon;
        IfxGtm_Tom_PwmHl_Config pwmHlConfigmon;
        Ifx_TimerValue          triggerPoint = 0;

        IfxGtm_Tom_Timer_initConfig(&timerConfigmon, &MODULE_GTM);
        timerConfigmon.base.frequency                  = CFG_PWM_FREQUENCYMON;
        timerConfigmon.base.isrPriority                = ISR_PRIORITY_TIMERMON;
        timerConfigmon.base.isrProvider                = CFG_PWM_ISR_PROVIDER;
        timerConfigmon.base.minResolution              = CFG_PWM_MIN_PULSE;
        timerConfigmon.base.trigger.enabled            = TRUE;
        timerConfigmon.tom                             = IfxGtm_Tom_2;
        timerConfigmon.timerChannel                    = IfxGtm_Tom_Ch_8;
        timerConfigmon.clock                           = IfxGtm_Tom_Ch_ClkSrc_cmuFxclk0;

        timerConfigmon.triggerOut                      = &IfxGtm_TOM2_8_TOUT68_P20_12_OUT;
        timerConfigmon.base.trigger.outputEnabled      = TRUE;
        timerConfigmon.base.trigger.enabled            = TRUE;
        timerConfigmon.base.trigger.triggerPoint       = 500;
        timerConfigmon.base.trigger.risingEdgeAtPeriod = TRUE;
        timerConfigmon.base.trigger.outputMode         = IfxPort_OutputMode_pushPull;

        IfxGtm_Tom_Timer_init(&g_Iom.tomTimermon, &timerConfigmon);
        triggerPoint = (IfxGtm_Tom_Timer_getInputFrequency(&g_Iom.tomTimermon) / IfxGtm_Tom_Timer_getFrequency(&g_Iom.tomTimermon)) * (CFG_PWM_TRIGGER_DUTYCYCLE * (1.0 / (float32)CFG_PWM_FREQUENCYMON));
        IfxGtm_Tom_Timer_setTrigger(&g_Iom.tomTimermon, triggerPoint);

        IfxGtm_Tom_PwmHl_initConfig(&pwmHlConfigmon);
        IfxGtm_Tom_ToutMapP ccx[1]   = {&IfxGtm_TOM2_9_TOUT69_P20_13_OUT};
        IfxGtm_Tom_ToutMapP coutx[1] = {&IfxGtm_TOM2_10_TOUT70_P20_14_OUT};
        pwmHlConfigmon.timer                 = &g_Iom.tomTimermon;
        pwmHlConfigmon.tom                   = IfxGtm_Tom_2;
        pwmHlConfigmon.base.deadtime         = CFG_PWM_DEADTIME;
        pwmHlConfigmon.base.minPulse         = CFG_PWM_MIN_PULSE;
        pwmHlConfigmon.base.channelCount     = 1;
        pwmHlConfigmon.base.emergencyEnabled = FALSE;
        pwmHlConfigmon.base.outputMode       = IfxPort_OutputMode_pushPull;
        pwmHlConfigmon.base.outputDriver     = IfxPort_PadDriver_cmosAutomotiveSpeed1;
        pwmHlConfigmon.base.ccxActiveState   = Ifx_ActiveState_high;
        pwmHlConfigmon.base.coutxActiveState = Ifx_ActiveState_high;
        pwmHlConfigmon.ccx                   = ccx;
        pwmHlConfigmon.coutx                 = coutx;

        IfxGtm_Tom_PwmHl_init(&g_Iom.tomPwmmon, &pwmHlConfigmon);

        IfxGtm_Tom_PwmHl_setMode(&g_Iom.tomPwmmon, Ifx_Pwm_Mode_centerAligned);
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxIomDemo_init(void)
{
    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    {
        /* Initialize the module handle*/
        IfxIom_Iom_initModuleConfig(&g_Iom.iom, &MODULE_IOM);

        /* Enable the module control*/
        IfxIom_Iom_initModule(&g_Iom.iom);

        /* Initialize the default Filter & Prescaler Cell channel configuration buffer*/
        IfxIom_Iom_initFpcChannelConfig(&g_Iom.fpcConfig);

        /* Filter & Prescaler Cell channel supplied configuration*/
        fpcSuppliedConfig();

        /*Initialize the Filter & Prescaler Cell channel with supplied configuration*/
        IfxIom_Iom_initFpcChannel(&g_Iom.iom, &g_Iom.fpcConfig);

        /* Initialize the default Logic Analyser Module configuration buffer*/
        IfxIom_Iom_initAnalyserConfig(&g_Iom.lamConfig);

        /* Logic Analyser Module Block supplied configuration*/
        lamSuppliedConfig();

        /* Initialize the Logic Analyser Module with supplied configuration */
        IfxIom_Iom_initAnalyser(&g_Iom.iom, &g_Iom.lamConfig);

        /* Initialize the default Event Combiner Module configuration buffer*/
        IfxIom_Iom_initCombinerConfig(&g_Iom.ecmConfig);
        g_Iom.ecmConfig.globalEventSelection.B.eventCombinerSelection14 = 1;
        g_Iom.ecmConfig.eventCounter[0].input                           = IfxIom_EventCounterChannel_0;
        g_Iom.ecmConfig.eventCounter[0].threshold                       = 50;

        /* Initialize the Logic Analyser Module with supplied configuration*/
        IfxIom_Iom_initCombiner(&g_Iom.iom, &g_Iom.ecmConfig);
    }

    /* enable GTM clock */
    gtmClockEnable();

    Iom_initGtm();

    /*
     * FXCLK: used by TOM
     * CLK0: used by ATOM
     */
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_FXCLK | IFXGTM_CMU_CLKEN_CLK0);

    /* start timer */
    IfxGtm_Tom_Timer_run(&g_Iom.tomTimerref);
    IfxGtm_Tom_Timer_run(&g_Iom.tomTimermon);

    /* Start the SMU */
    SMU_CMD.U = 0;

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxIomDemo_run(void)
{
#ifdef SIMULATION
    while (g_Iom.counterTimer < 5)
    {}
#else
    while (g_Iom.counterTimer < 50000)
    {}
#endif

    g_Iom.counterTimer = 0;

    if (SMU_AG2.U == 0U)
    {
        pattern_ok++;
    }
    else
    {
        SMU_CMD.U = 5;

        while (SMU_AG2.U != 0U)
        {
            IfxScuWdt_clearSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());
            SMU_AG2.U = 0xFFFFFFFF;
            IfxScuWdt_setSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());
        }

        SMU_CMD.U = 0;
        pattern_not_ok++;
    }

    if (pattern_not_ok)
    {
        printf("Monitor signal is incorrect\n");
    }
}

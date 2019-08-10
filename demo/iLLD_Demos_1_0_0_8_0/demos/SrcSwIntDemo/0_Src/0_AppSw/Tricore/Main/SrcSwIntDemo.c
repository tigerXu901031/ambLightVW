/**
 * \file SrcSwIntDemo.c
 * \brief Demo SrcSwIntDemo
 *
 * \version iLLD_Demos_1_0_0_8_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
#include "SrcSwIntDemo.h"

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

App_SrcSwInt g_SrcSwInt; /**< \brief SrcSwInt global data */
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
static void IfxBlinkLed_run(void);

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_SrcSwIntDemo_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for ServiceRequestControl(SRC)
 * \{ */

IFX_INTERRUPT(stm0Sr0ISR, 0, ISR_PRIORITY_STM0_SR0);
/** \} */

/** \} */

/** \brief Handle ServiceRequestControl(SRC) interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_ServiceRequestControl(SRC)
 * \isrPriority \ref ISR_PRIORITY_ServiceRequestControl(SRC)
 */
IFX_INTERRUPT(stm0Sr0ISR, 0, ISR_PRIORITY_STM0_SR0)
{
    IfxStm_clearCompareFlag(g_SrcSwInt.stmSfr, g_SrcSwInt.stmConfig.comparator);
#ifdef SIMULATION
    IfxStm_updateCompare(g_SrcSwInt.stmSfr, g_SrcSwInt.stmConfig.comparator, IfxStm_getLower(g_SrcSwInt.stmSfr) + 1000);
#else
    IfxStm_updateCompare(g_SrcSwInt.stmSfr, g_SrcSwInt.stmConfig.comparator, IfxStm_getLower(g_SrcSwInt.stmSfr) + TimeConst_1s);
#endif
    IfxCpu_enableInterrupts();
    IfxBlinkLed_run();
}

/** \brief Port Pin State
 *
 * This function changes the Port Pin state
 */
static void setOutputPin(Ifx_P *port, uint8 pin, boolean state)
{
    if (state)
    {
        IfxPort_setPinState(port, pin, IfxPort_State_high);
    }
    else
    {
        IfxPort_setPinState(port, pin, IfxPort_State_low);
    }
}


/** \brief LED Blinking
 *
 * This function blinks the LED connected to P 33.6 and counts the number
 *	of times the interrupt occurs.
 */
static void IfxBlinkLed_run(void)
{
    g_SrcSwInt.LedBlink ^= 1;

    setOutputPin(&MODULE_P33, 6, g_SrcSwInt.LedBlink);
    g_SrcSwInt.counter++;
}


/** \brief LED Initialization
 *
 * This function initializes the LED connected to P33.6
 */
static void IfxBlinkLed_Init(void)
{
    IfxPort_setPinMode(&MODULE_P33, 6, IfxPort_Mode_outputPushPullGeneral);
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxSrcSwIntDemo_init(void)
{
    printf(" IfxSrcSwIntDemo_init() called\n");

    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    g_SrcSwInt.LedBlink = 0;
    g_SrcSwInt.counter  = 0;

    initTime();

    IfxCpu_Irq_installInterruptHandler(stm0Sr0ISR, ISR_PRIORITY_STM0_SR0);

    g_SrcSwInt.stmSfr = &MODULE_STM0;
    IfxStm_initCompareConfig(&g_SrcSwInt.stmConfig);

    g_SrcSwInt.stmConfig.triggerPriority         = ISR_PRIORITY_STM0_SR0;
    g_SrcSwInt.stmConfig.typeOfService           = IfxSrc_Tos_cpu0;

#ifdef SIMULATION
    g_SrcSwInt.stmConfig.ticks = (IfxStm_getLower(g_SrcSwInt.stmSfr)) + 1000;
#else
    g_SrcSwInt.stmConfig.ticks = (IfxStm_getLower(g_SrcSwInt.stmSfr)) + TimeConst_1s;
#endif

    IfxStm_initCompare(g_SrcSwInt.stmSfr, &g_SrcSwInt.stmConfig);

    IfxBlinkLed_Init();

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxSrcSwIntDemo_run(void)
{
    printf("IfxSrcSwIntDemo_run() called\n");

    while (g_SrcSwInt.counter < 10)
    {}

    printf("OK: checks passed \n");
}

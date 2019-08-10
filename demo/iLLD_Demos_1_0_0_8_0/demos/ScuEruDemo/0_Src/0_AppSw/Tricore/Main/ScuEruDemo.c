/**
 * \file ScuEruDemo.c
 * \brief Demo ScuEruDemo
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
#include "ScuEruDemo.h"
#include "Src/Std/IfxSrc.h"

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

App_ScuEru g_ScuEru; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_ScuEru_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for input state change
 * \{ */

IFX_INTERRUPT(ISR_ScuEru, 0, ISR_PRIORITY_SCUERU_0);

/** \} */

/** \} */

/** \brief Handle Timer interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_SCUERU_0
 * \isrPriority \ref ISR_PRIORITY_SCUERU_0
 *
 */
void ISR_ScuEru(void)
{
    IfxCpu_enableInterrupts();

    printf("ISR_ScuEru invoked\n");

    g_ScuEru.count++;
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void ScuEruDemo_init(void)
{
    /* disable interrupts */
    boolean        interruptState = IfxCpu_disableInterrupts();

    /* select external request pin */
    IfxScu_Req_In *reqPin = &IfxScu_REQ9_P20_0_IN;

    /* initialize this pin with pull-up enabled */
    /* this function will also configure the input multiplexers of the ERU (EICRm.EXISx) */
    IfxScuEru_initReqPin(reqPin, IfxPort_InputMode_pullUp);

    /* determine input channel EICRm depending on input pin */
    IfxScuEru_InputChannel inputChannel = (IfxScuEru_InputChannel)reqPin->channelId;

    /* signal destination */
    IfxScuEru_InputNodePointer triggerSelect = IfxScuEru_InputNodePointer_0;                           /* TRx0 */
    IfxScuEru_OutputChannel    outputChannel = IfxScuEru_OutputChannel_0;                              /* OGU channel 0 */

    /* input channel configuration */
    IfxScuEru_disableFallingEdgeDetection(inputChannel);                                               /* EICRm.FENn */
    IfxScuEru_enableRisingEdgeDetection(inputChannel);                                                 /* EICRm.RENn */
    IfxScuEru_enableAutoClear(inputChannel);                                                           /* EICRm.LDENn */

    /* Connecting Matrix, Event Trigger Logic ETL block */
    IfxScuEru_enableTriggerPulse(inputChannel);                                                        /* EICRm.EIENn */
    IfxScuEru_connectTrigger(inputChannel, triggerSelect);                                             /* EICRm.INPn */

    /* output channels, OutputGating Unit OGU block */
    IfxScuEru_setFlagPatternDetection(outputChannel, inputChannel, TRUE);                              /* IGCRm.IPENn */
    IfxScuEru_enablePatternDetectionTrigger(outputChannel);                                            /* IGCRm.GEENn */
    IfxScuEru_setInterruptGatingPattern(outputChannel, IfxScuEru_InterruptGatingPattern_alwaysActive); /* IGCEm.IGPn */

    /* service request configuration */
    {
        volatile Ifx_SRC_SRCR *src = &MODULE_SRC.SCU.SCU.ERU[(int)outputChannel % 4];
        IfxSrc_init(src, IfxSrc_Tos_cpu0, ISR_PRIORITY_SCUERU_0);
        IfxSrc_enable(src);
    }

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    printf("Scu Eru is initialised and running\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void ScuEruDemo_run(void)
{
    /* wait for 3 events */
    g_ScuEru.count = 0;

    while (g_ScuEru.count < 3)
    {}
}

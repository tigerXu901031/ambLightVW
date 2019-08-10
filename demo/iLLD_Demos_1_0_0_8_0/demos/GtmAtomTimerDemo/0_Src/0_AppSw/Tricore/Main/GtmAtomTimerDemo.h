/**
 * \file GtmAtomTimerDemo.h
 * \brief Demo GtmAtomTimerDemo
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
 *
 * \defgroup IfxLld_Demo_GtmAtomTimer_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_GtmAtomTimer_SrcDoc
 * \defgroup IfxLld_Demo_GtmAtomTimer_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_GtmAtomTimer_SrcDoc_Main
 */

#ifndef GTMATOMTIMER_H
#define GTMATOMTIMER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <Ifx_Types.h>
#include "SysSe/Bsp/Bsp.h"
#include "Configuration.h"

#include "Gtm/Atom/Timer/IfxGtm_Atom_Timer.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Application information */
typedef struct
{
    struct
    {
        float32 gtmFreq;
        float32 gtmGclkFreq;
        float32 gtmCmuClk0Freq;         /**< \brief CMU CLK 0 frequency*/
    }info;
    struct
    {
        IfxGtm_Atom_Timer timerOneMs;        /**< \brief Timer driver */
    }drivers;
    struct
    {
        uint32 slotOneMs;
    }isrCounter;
} App_GtmAtomTimer;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

IFX_EXTERN App_GtmAtomTimer g_GtmAtomTimer;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

IFX_EXTERN void GtmAtomTimerDemo_init(void);
IFX_EXTERN void GtmAtomTimerDemo_run(void);

#endif

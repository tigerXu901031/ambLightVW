/**
 * \file ScuClockDemo.h
 * \brief Scu PLL and Clock Demo
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
 * \defgroup IfxLld_Demo_ScuClockDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_ScuClockDemo_SrcDoc
 * \defgroup IfxLld_Demo_ScuClockDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_ScuClockDemo_SrcDoc_Main
 */

#ifndef SCUCLOCKDEMO_H
#define SCUCLOCKDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include "Configuration.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct
{
    uint32 sourcefreq;   /**< \brief source frequency */
    uint32 spbfreq;      /**< \brief SPB frequency */
    uint32 gtmfreq;      /**< \brief Gtm frequency */
    uint32 pllfreq;      /**< \brief PLL frequency */
    uint32 cpufreq;      /**< \brief Cpu frequency */
    uint32 maxfreq;      /**< \brief Max frequency */
    uint32 srifreq;      /**< \brief Sri frequency */
    uint32 stmfreq;      /**< \brief Stm frequency */
} App_ScuClock;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_ScuClock g_ScuClock;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void IfxScuClockDemo_init(void);
IFX_EXTERN void IfxScuClockDemo_run(void);

#endif

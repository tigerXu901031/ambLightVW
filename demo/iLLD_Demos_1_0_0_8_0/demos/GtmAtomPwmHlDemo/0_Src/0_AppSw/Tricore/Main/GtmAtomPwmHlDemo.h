/**
 * \file AsclinAscDemo.h
 * \brief Demo AsclinAscDemo
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
 * \defgroup IfxLld_Demo_AsclinAsc_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_AsclinAsc_SrcDoc
 * \defgroup IfxLld_Demo_AsclinAsc_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_AsclinAsc_SrcDoc_Main
 */

#ifndef ASCLINASCDEMO_H
#define ASCLINASCDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Configuration.h"
#include "SysSe/Bsp/Bsp.h"

#include "Gtm/Atom/PwmHl/IfxGtm_Atom_PwmHl.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

typedef enum
{
    GtmAtomPwmHl_State_init = 0,
    GtmAtomPwmHl_State_off,
    GtmAtomPwmHl_State_duty0,
    GtmAtomPwmHl_State_duty50,
    GtmAtomPwmHl_State_duty100,
    GtmAtomPwmHl_State_count
}GtmAtomPwmHl_State;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Application information */
typedef struct
{
    struct
    {
        float32            gtmFreq;
        float32            gtmGclkFreq;
        float32            gtmCmuClk0Freq; /**< \brief CMU CLK 0 frequency*/
        GtmAtomPwmHl_State state;
        Ifx_TickTime       stateDeadline;
    }info;
    struct
    {
        IfxGtm_Atom_Timer timer;        /**< \brief Timer driver */
        IfxGtm_Atom_PwmHl pwm;
    }drivers;
    struct
    {
        uint32 slotTimer;
    }isrCounter;
} App_GtmAtomPwmHl;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

IFX_EXTERN App_GtmAtomPwmHl g_GtmAtomPwmHl;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

IFX_EXTERN void GtmAtomPwmHlDemo_init(void);
IFX_EXTERN void GtmAtomPwmHlDemo_run(void);

#endif

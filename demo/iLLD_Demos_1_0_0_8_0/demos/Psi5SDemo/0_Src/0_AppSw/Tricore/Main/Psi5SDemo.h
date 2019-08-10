/**
 * \file Psi5SDemo.h
 * \brief Psi5SDemo
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
 * \defgroup IfxLld_Demo_Psi5SDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_Psi5SDemo_SrcDoc
 * \defgroup IfxLld_Demo_Template_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_Template_SrcDoc_Main
 */

#ifndef PSI5SDEMO_H
#define PSI5SDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include <Psi5s/Psi5s/IfxPsi5s_Psi5s.h>
#include "ConfigurationIsr.h"
#include "Cpu0_Main.h"

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
    IfxPsi5s_Psi5s         psi5s;           /**< \brief Psi5S  handle */
    IfxPsi5s_Psi5s_Channel psi5sChannel;    /**< \brief Psi5S Channel handle */
} App_Psi5S;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_Psi5S g_Psi5S;
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
void IfxPsi5SDemo_init(void);
void IfxPsi5SDemo_run(void);

#endif

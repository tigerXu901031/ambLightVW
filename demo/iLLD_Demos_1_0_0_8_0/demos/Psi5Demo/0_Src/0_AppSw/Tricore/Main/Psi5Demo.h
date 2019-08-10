/**
 * \file Psi5Demo.h
 * \brief Psi5Demo
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
 * \defgroup IfxLld_Demo_Psi5Demo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_Psi5Demo_SrcDoc
 * \defgroup IfxLld_Demo_Psi5Demo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_Psi5Demo_SrcDoc_Main
 */

#ifndef PSI5DEMO_H
#define PSI5DEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include "Configuration.h"
#include <Psi5/Std/IfxPsi5.h>
#include <Psi5/Psi5/IfxPsi5_Psi5.h>
#include "Cpu0_Main.h"
#include "ConfigurationIsr.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define NUM_TESTED_CHANNELS 1  /**< \brief Number of Psi5 Channels */

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct
{
    IfxPsi5_Psi5         psi5;                             /**< \brief Psi5 Module handle */
    IfxPsi5_Psi5_Channel psi5Channel[NUM_TESTED_CHANNELS]; /**< \brief Psi5 Channel handle */
} App_Psi5;
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_Psi5 g_Psi5;
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void IfxPsi5Demo_init(void);
IFX_EXTERN void IfxPsi5Demo_run(void);

#endif

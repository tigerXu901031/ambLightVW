/**
 * \file FceBasicDemo.h
 * \brief Demo FceBasicDemo
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
 * \defgroup IfxLld_Demo_FceBasicDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_FceBasicDemo_SrcDoc
 * \defgroup IfxLld_Demo_FceBasicDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_FceBasicDemo_SrcDoc_Main
 */

#ifndef FCEBASICDEMO_H
#define FCEBASICDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include <Fce/Crc/IfxFce_Crc.h>
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
    IfxFce_Crc     fce;
    IfxFce_Crc_Crc fceCrc32_0;
    IfxFce_Crc_Crc fceCrc32_1;
    IfxFce_Crc_Crc fceCrc16;
    IfxFce_Crc_Crc fceCrc8;
    int            error;
} App_FceBasic;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_FceBasic g_FceBasic;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void FceBasicDemo_init(void);
IFX_EXTERN void FceBasicDemo_run(void);

#endif

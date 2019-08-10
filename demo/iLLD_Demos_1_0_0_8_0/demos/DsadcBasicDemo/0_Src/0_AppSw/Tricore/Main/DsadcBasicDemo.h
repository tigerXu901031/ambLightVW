/**
 * \file DsadcBasicDemo.h
 * \brief Demo DsadcBasicDemo
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
 * \defgroup IfxLld_Demo_DsadcBasicDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_DsadcBasicDemo_SrcDoc
 * \defgroup IfxLld_Demo_DsadcBasicDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_DsadcBasicDemo_SrcDoc_Main
 */

#ifndef DSADCBASICDEMO_H
#define DSADCBASICDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include <Dsadc/Dsadc/IfxDsadc_Dsadc.h>
#include "Configuration.h"
#include <Cpu/Std/IfxCpu.h>
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
    IfxDsadc_Dsadc_Channel dsadcChannel[IFXDSADC_NUM_CHANNELS];
} App_DsadcBasic;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_DsadcBasic g_DsadcBasic;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void DsadcBasicDemo_init(void);
IFX_EXTERN void DsadcBasicDemo_run(void);

#endif

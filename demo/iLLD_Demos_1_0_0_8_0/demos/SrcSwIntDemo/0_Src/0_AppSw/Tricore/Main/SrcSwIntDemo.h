/**
 * \file SrcSwIntDemo.h
 * \brief SrcSwIntDemo
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
 * \defgroup IfxLld_Demo_SrcSwIntDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_SrcSwIntDemo_SrcDoc
 * \defgroup IfxLld_Demo_SrcSwIntDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_SrcSwIntDemo_SrcDoc_Main
 */

#ifndef _IFX_SRC_H
#define _SRC_H 1
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include <Stm/Std/IfxStm.h>
#include <Src/Std/IfxSrc.h>
#include "ConfigurationIsr.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
#include <stdio.h>
#include "IfxPort.h"
#include "Cpu0_Main.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
#include "IfxPort.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/
/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief SrcSwInt global data */
typedef struct
{
    Ifx_STM             *stmSfr;       /**< \brief Pointer to Stm register base */
    IfxStm_CompareConfig stmConfig;    /**< \brief Stm Configuration structure */

    volatile uint8       LedBlink;     /**< \brief LED state variable */
    volatile uint32      counter;      /**< \brief interrupt counter */
} App_SrcSwInt;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_SrcSwInt g_SrcSwInt;
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void IfxSrcSwIntDemo_init(void);
IFX_EXTERN void IfxSrcSwIntDemo_run(void);

#endif

/**
 * \file ErayDemo.h
 * \brief Eray Demo
 * \version iLLD_Demos_1_0_0_8_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Demo_ErayDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_ErayDemo_SrcDoc
 * \defgroup IfxLld_Demo_ErayDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_ErayDemo_SrcDoc_Main
 */

#ifndef ERAYDEMO_H
#define ERAYDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include <Eray/Eray/IfxEray_Eray.h>
#include <ConfigurationIsr.h>
#include <stdio.h>
#include "Cpu0_Main.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define NUMBER_ERAY_COMM_CYCLES 8   /*Number of tested communication cycles*/

#define NO_OF_SLOTS             2   /*Number of slots configured*/
/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    IfxEray_Eray            eray;                                     /**< \brief Eray handle */
    IfxEray_Eray_Config     erayModuleConfig;                         /**< \brief Eray module Configuration structure */
    IfxEray_Eray_NodeConfig nodeConfig;                               /**< \brief Eray Node Configuration structure */
    volatile unsigned       ndatCount;                                /**< \brief received data (new data) */
    volatile unsigned       errors;                                   /**< \brief error interrupt counter */
    uint32                  receivedData[NUMBER_ERAY_COMM_CYCLES][NO_OF_SLOTS]; /**< \brief received data in slots */
} App_Eray;
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_Eray g_Eray;
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void IfxErayDemo_init(void);
IFX_EXTERN void IfxErayDemo_run(void);

#endif

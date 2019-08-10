/**
 * \file Ccu6PwmBcDemo.h
 * \brief Demo Ccu6PwmBcDemo
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
 * \defgroup IfxLld_Demo_Ccu6PwmBc_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_Ccu6PwmBc_SrcDoc
 * \defgroup IfxLld_Demo_Ccu6PwmBc_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_Ccu6PwmBc_SrcDoc_Main
 */

#ifndef CCU6PWMBCDEMO_H
#define CCU6PWMBCDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <Ifx_Types.h>
#include "Configuration.h"

#include "Ccu6/PwmBc/IfxCcu6_PwmBc.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Asc information */
typedef struct
{
    struct
    {
        IfxCcu6_PwmBc pwmBc;    /**< \brief PWMBC interface */
    }      drivers;

    uint32 speed;               /* to store value of the speed */
} App_Ccu6PwmBc;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

IFX_EXTERN App_Ccu6PwmBc g_Ccu6PwmBc;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

IFX_EXTERN void Ccu6PwmBcDemo_init(void);
IFX_EXTERN void Ccu6PwmBcDemo_run(void);

#endif

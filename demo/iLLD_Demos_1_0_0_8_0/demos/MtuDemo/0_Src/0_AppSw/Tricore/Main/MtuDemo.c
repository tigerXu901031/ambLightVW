/**
 * \file MtuDemo.c
 * \brief Mtu Demo.
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include "Cpu0_Main.h"
#include <Mtu/Std/IfxMtu.h>
#include "MtuDemo.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxMtuDemo_init(void)
{
    /* Enable MTU clock */
    {
        uint16 password = IfxScuWdt_getCpuWatchdogPassword();
        IfxScuWdt_clearCpuEndinit(password);
        IfxMtu_enableModule();
        IfxScuWdt_setCpuEndinit(password);
    }

    /* Note: clearSram functions will trap with bus error if wrong ECC is initialized */
    {
        uint16 password = IfxScuWdt_getSafetyWatchdogPassword();
        IfxScuWdt_clearSafetyEndinit(password);
        IfxMtu_clearSram(IfxMtu_MbistSel_erayObf);
        IfxMtu_clearSram(IfxMtu_MbistSel_erayIbfTbf);
        IfxMtu_clearSram(IfxMtu_MbistSel_erayMbf);
        IfxScuWdt_setSafetyEndinit(password);
    }

    printf("OK: Mtu behaviour is as expected\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxMtuDemo_run(void)
{}

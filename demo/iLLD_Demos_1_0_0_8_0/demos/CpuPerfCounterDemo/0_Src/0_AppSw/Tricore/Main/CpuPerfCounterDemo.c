/**
 * \file CpuPerfCounterDemo.c
 * \brief Cpu Performance counter Demo
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
#include <Cpu/Std/IfxCpu.h>
#include <IfxCbs_reg.h>
#include "Cpu0_Main.h"
#include "CpuPerfCounterDemo.h"

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
static void TestCodeForPerfomanceEval(void);

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \brief Sample code for performance evaluation
 *
 */
static void TestCodeForPerfomanceEval(void)
{
    volatile uint32 i;

    for (i = 0; i < 42; i++)
    {
        __nop();
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxCpuPerfCounterDemo_init(void)
{
    printf("IfxCpuPerfCounterDemo_init() called\n");

    /* Enable OCDS */
    CBS_OEC.U = 0xa1;
    CBS_OEC.U = 0x5e;
    CBS_OEC.U = 0xa1;
    CBS_OEC.U = 0x5e;
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxCpuPerfCounterDemo_run(void)
{
    /* Local variable to store the result of measurement */
    IfxCpu_Perf perfCounts;

    /* With Normal mode, the counters increment on their respective triggers */
    IfxCpu_resetAndStartCounters(IfxCpu_CounterMode_normal);

    /* Call the code for which the performance is to be measured*/
    TestCodeForPerfomanceEval();

    /* Now, perfCounts will have all the counter + stick bit status */
    perfCounts = IfxCpu_stopCounters();

    printf("Performance counters: %u, %u, %u\n", perfCounts.clock, perfCounts.instruction, perfCounts.counter1);
}

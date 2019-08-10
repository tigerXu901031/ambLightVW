/**
 * \file CpuSyncDemo.c
 * \brief Cpu Synchronization Demo. It demonstrates how to use Mutex for synchronisation.
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
#include "Cpu0_Main.h"
#include "Ifx_Assert.h"
#include "CpuSyncDemo.h"

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
App_CpuSync g_CpuSync; /**< \brief Cpu Sync global data */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \brief Sample critical Section function
 *
 * This function is called from the run API
 */
static void SampleCriticalSection(void)
{
    volatile uint32 i;

    for (i = 0; i < 2000; i++)
    {
        __nop();
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxCpuSyncDemo_init(void)
{
    printf("IfxCpuSyncDemo_init() called\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxCpuSyncDemo_run(void)
{
    uint32  errors = 0;
    boolean flag1, flag2;

    flag1 = IfxCpu_acquireMutex(&g_CpuSync.resourceLock);

    if (flag1)
    {
        /*Note: Mutex acquired successfully - I */
        /*Note: Trying to acquire the same mutex...  Now it fails as mutex is already acquired. */

        flag2 = IfxCpu_acquireMutex(&g_CpuSync.resourceLock);

        if (!flag2)
        {
            /* Mutex acquire FAILED - II. It is expected as mutex is already acquired. */
        }
        else
        {
            errors++;
        }

        /* critical section */
        SampleCriticalSection();

        /* Mutex released - I. */
        IfxCpu_releaseMutex(&g_CpuSync.resourceLock);
    }
    else
    {
        errors++;
    }

    /* Note: Trying to acquire the same mutex after release. */

    flag2 = IfxCpu_acquireMutex(&g_CpuSync.resourceLock);

    if (flag2)
    {
        /* Note: Mutex acquired successfully - II */
        /* critical section*/
        SampleCriticalSection();
        /* Mutex released - II. */
        IfxCpu_releaseMutex(&g_CpuSync.resourceLock);
    }
    else
    {
        errors++;
    }

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, errors == 0);

    if (errors)
    {
        printf("ERROR: Mutex behaviour is NOT as expected. (%ld mismatches)!\n", errors);
    }
    else
    {
        printf("OK: Mutex behaviour is as expected\n");
    }
}

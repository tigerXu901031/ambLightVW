/**
 * \file EmemBasicDemo.c
 * \brief Demo EmemBasicDemo
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
#include "EmemBasicDemo.h"
#include "_Utilities/Ifx_Assert.h"
#include <Emem/Std/IfxEmem.h>
#include <Stm/Std/IfxStm.h>
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

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
App_EmemBasic g_EmemBasic; /**< \brief Demo information */

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
void EmemBasicDemo_init(void)
{

    IfxEmem_setClockEnableState(IfxEmem_State_enabled);

    IfxStm_waitTicks(&MODULE_STM0,10);

    if (IfxEmem_LockedState_locked == IfxEmem_getLockedState())
    {
        /* apply unlock sequence */
        IfxEmem_setUnlockStandbyLockFlag(0x1);
        IfxEmem_setUnlockStandbyLockFlag(0x3);
        IfxEmem_setUnlockStandbyLockFlag(0x7);
        /* wait one cycle for unlock */

        IfxStm_waitTicks(&MODULE_STM0,10);
    }

    IfxEmem_setTileConfigMode(IfxEmem_TileConfigMode_calibMode,IfxEmem_TileNumber_0);

    {
        uint64 *pmem;
        uint32  i;

        /* initialize the whole EMEM with 0 */
        pmem = (uint64 *)IFXEMEM_START_ADDR_CPU;

        for (i = 0; (uint64)i < (IFXEMEM_SIZE / 8); i += 1)
        {
            *(pmem++) = (uint64)0xAAAAAAAA55555555;
        }
    }
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void EmemBasicDemo_run(void)
{
    volatile uint64 *Emem;
    uint32           error = 0;
    uint32           i;
    uint64           value = 0x1;
    printf("EmemBasicDemo_run() called\n");
    Emem = (uint64 *)IFXEMEM_START_ADDR_CPU;

    for (i = 0; (uint64)i < (IFXEMEM_SIZE / 8); i += 1)
    {
        *(Emem++) = (uint64)value++;
    }

    Emem  = (uint64 *)IFXEMEM_START_ADDR_CPU;
    value = 0x1;

    for (i = 0; (uint64)i < (IFXEMEM_SIZE / 8); i += 1)
    {
        if (*(Emem++) != value)
        {
            error++;
        }

        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, error == 0);

        if (error)
        {
            printf("ERROR: found %d errors\n", error);
        }
        else
        {
            printf("OK: checks passed \n");
        }

        value++;
    }
}

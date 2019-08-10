/**
 * \file FceBasicDemo.c
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include "FceBasicDemo.h"
#include "_Utilities/Ifx_Assert.h"
#include <Cpu/Std/IfxCpu.h>
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define IFX_INTPRIO_FCE 1
#define CHECK_DATA_SIZE 25
/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
App_FceBasic g_FceBasic; /**< \brief Demo information */
/* data over which CRC should be calculated
 * generated with following perl script:
 * srand(42);
 */
uint32 checkData[CHECK_DATA_SIZE] = {
    0xbe9957bb,
    0x1c706c1e,
    0x14c3db3f,
    0x7fb17a93,
    0xb0d9d5a7,
    0x768093e0,
    0x88b206a0,
    0xc51299e4,
    0xe8a97d48,
    0x89367f27,
    0x70095984,
    0xec030f75,
    0xdc22f8d4,
    0xd951407b,
    0x34ae18c6,
    0x4d47ba7d,
    0x0e2e4622,
    0x4a2e90d3,
    0xdaec3752,
    0xcd3ed11c,
    0x36b416b7,
    0x8ea28658,
    0xdd37eee3,
    0x23928b62,
    0x84eb4b22,
};
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_Demo_FceBasicDemo_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for <fceISR> check length & CRC mismatch error, Bus & Configuration Error
 * \{ */
IFX_INTERRUPT(fceISR, 0, IFX_INTPRIO_FCE)
{
    {
        Ifx_FCE_STS interruptStatus = IfxFce_Crc_getInterruptStatus(&g_FceBasic.fceCrc32_0);

        if (interruptStatus.U)
        {
            if (interruptStatus.B.CMF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.CEF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.LEF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.BEF == 1)
            {
                g_FceBasic.error++;
            }
        }

        IfxFce_Crc_clearErrorFlags(&g_FceBasic.fceCrc32_0);
    }

    {
        Ifx_FCE_STS interruptStatus = IfxFce_Crc_getInterruptStatus(&g_FceBasic.fceCrc32_1);

        if (interruptStatus.U)
        {
            if (interruptStatus.B.CMF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.CEF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.LEF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.BEF == 1)
            {
                g_FceBasic.error++;
            }
        }

        IfxFce_Crc_clearErrorFlags(&g_FceBasic.fceCrc32_1);
    }

    {
        Ifx_FCE_STS interruptStatus = IfxFce_Crc_getInterruptStatus(&g_FceBasic.fceCrc16);

        if (interruptStatus.U)
        {
            if (interruptStatus.B.CMF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.CEF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.LEF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.BEF == 1)
            {
                g_FceBasic.error++;
            }
        }

        IfxFce_Crc_clearErrorFlags(&g_FceBasic.fceCrc16);
    }

    {
        Ifx_FCE_STS interruptStatus = IfxFce_Crc_getInterruptStatus(&g_FceBasic.fceCrc8);

        if (interruptStatus.U)
        {
            if (interruptStatus.B.CMF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.CEF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.LEF == 1)
            {
                g_FceBasic.error++;
            }

            if (interruptStatus.B.BEF == 1)
            {
                g_FceBasic.error++;
            }
        }

        IfxFce_Crc_clearErrorFlags(&g_FceBasic.fceCrc8);
    }
}
/** \} */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void FceBasicDemo_init(void)
{
    /* disable interrupts */
    boolean           interruptState = IfxCpu_disableInterrupts();

    /* create module config */
    IfxFce_Crc_Config fceConfig;
    IfxFce_Crc_initModuleConfig(&fceConfig, &MODULE_FCE0);

    /* ISR priorities and interrupt target */
    fceConfig.isrPriority      = IFX_INTPRIO_FCE;
    fceConfig.isrTypeOfService = (IfxSrc_Tos)IfxCpu_getCoreIndex();

    /* initialize module */
    IfxFce_Crc_initModule(&g_FceBasic.fce, &fceConfig);

    /*initialize CRC kernels */
    IfxFce_Crc_CrcConfig crcConfig;
    IfxFce_Crc_initCrcConfig(&crcConfig, &g_FceBasic.fce);

    IfxFce_Crc_initCrc(&g_FceBasic.fceCrc32_0, &crcConfig);

    crcConfig.crc32Kernel = IfxFce_Crc32Kernel_1;
    IfxFce_Crc_initCrc(&g_FceBasic.fceCrc32_1, &crcConfig);
    crcConfig.crc32Kernel = IfxFce_Crc32Kernel_0;

    crcConfig.crcMode     = IfxFce_CrcMode_16;
    IfxFce_Crc_initCrc(&g_FceBasic.fceCrc16, &crcConfig);

    crcConfig.crcMode = IfxFce_CrcMode_8;
    IfxFce_Crc_initCrc(&g_FceBasic.fceCrc8, &crcConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void FceBasicDemo_run(void)
{
    uint32 expected;
    expected = 0xd95def75;
    printf("FceBasicDemo_run() called\n");
    printf("Start with Err0r IRQ check\n");
    {
        /* initialize CRC kernel with CRC check enabled */
        IfxFce_Crc_CrcConfig crcConfig;
        IfxFce_Crc_initCrcConfig(&crcConfig, &g_FceBasic.fce);
        crcConfig.enabledInterrupts.crcMismatch = TRUE;
        crcConfig.enabledInterrupts.configError = TRUE;
        crcConfig.enabledInterrupts.lengthError = TRUE;
        crcConfig.enabledInterrupts.busError    = TRUE;
        IfxFce_Crc_initCrc(&g_FceBasic.fceCrc32_0, &crcConfig);
    }

    {
        /* Expected CRC: */
        g_FceBasic.fceCrc32_0.expectedCrc = 0xd95def75;
        /* do calculation */
        uint32 fceCrc = IfxFce_Crc_calculateCrc32(&g_FceBasic.fceCrc32_0, checkData, CHECK_DATA_SIZE, 0x00000000);

        if (expected != fceCrc)
        {
            g_FceBasic.error++;
        }
    }
    printf(" Calculate CRC with FCE\n");
    {
        uint32 fceCrc = IfxFce_Crc_calculateCrc32(&g_FceBasic.fceCrc32_0, checkData, CHECK_DATA_SIZE, 0x00000000);

        if (expected != fceCrc)
        {
            g_FceBasic.error++;
        }
    }
    printf(" CRC16 calculation with FCE\n");
    {
        uint32 fceCrc;
        expected = 0xda6f;
        fceCrc   = IfxFce_Crc_calculateCrc16(&g_FceBasic.fceCrc16, (uint16 *)checkData, CHECK_DATA_SIZE * 2, 0x00000000);

        if (expected != fceCrc)
        {
            g_FceBasic.error++;
        }
    }
    printf("CRC8 calculation with FCE\n");
    {
        uint32 fceCrc;
        expected = 0x61;
        fceCrc   = IfxFce_Crc_calculateCrc8(&g_FceBasic.fceCrc8, (uint8 *)checkData, CHECK_DATA_SIZE * 4, 0x00000000);

        if (expected != fceCrc)
        {
            g_FceBasic.error++;
        }
    }
    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, g_FceBasic.error == 0);

    if (g_FceBasic.error)
    {
        printf("ERROR: found %d errors\n", g_FceBasic.error);
    }
    else
    {
        printf("OK: checks passed \n");
    }
}

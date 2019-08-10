/**
 * \file ScuClockDemo.c
 * \brief Scu PLL and Clock Demo
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
#include <Scu/Std/IfxScuCcu.h>
#include "ScuClockDemo.h"

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
App_ScuClock g_ScuClock; /**< \brief Scu Clock global data */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/
/** \brief Default configuration for the PLL initial steps
 */
static const IfxScuCcu_PllStepsConfig IfxScuCcu_testPllConfigSteps[] = {
    IFXSCU_CFG_PLL_STEPS
};

/** \brief Default configuration for the Clock Configuration
 */
IfxScuCcu_Config                      IfxScuCcu_testClockConfig = {
    {
        sizeof(IfxScuCcu_testPllConfigSteps) / sizeof(IfxScuCcu_PllStepsConfig),
        (IfxScuCcu_PllStepsConfig *)IfxScuCcu_testPllConfigSteps,
        IFXSCU_CFG_PLL_INITIAL_STEP,
    },
    IFXSCU_CFG_CLK_DISTRIBUTION,
    IFXSCU_CFG_FLASH_WAITSTATE
};

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxScuClockDemo_init(void)
{
    /* ensure that XTAL1 configured for X MHz */
    uint32 fosc = IFX_CFG_SCU_XTAL_FREQUENCY;
    uint32 fpll = IFX_CFG_SCU_PLL_FREQUENCY;

    /* NOTE: Don't add any printf before the clock initialization. Asc won't be initialized properly. */

    /* standard PLL initialisation */
    IfxScuCcu_init(&IfxScuCcu_testClockConfig);

    g_ScuClock.pllfreq = IfxScuCcu_getPllFrequency();
    g_ScuClock.cpufreq = IfxScuCcu_getCpuFrequency(IfxCpu_getCoreIndex());
    g_ScuClock.spbfreq = IfxScuCcu_getSpbFrequency();
    g_ScuClock.gtmfreq = IfxScuCcu_getGtmFrequency();
    g_ScuClock.srifreq = IfxScuCcu_getSriFrequency();
    g_ScuClock.stmfreq = IfxScuCcu_getStmFrequency();

    printf("PLL initialized: Normal mode, fosc: %ld MHz & fpll: %ld MHz\n", fosc / 1000000, fpll / 1000000);
    printf("PLL freq: %ld MHz\n", g_ScuClock.pllfreq / 1000000);
    printf("CPU freq: %ld MHz\n", g_ScuClock.cpufreq / 1000000);
    printf("SPB freq: %ld MHz\n", g_ScuClock.spbfreq / 1000000);
    printf("GTM freq: %ld MHz\n", g_ScuClock.gtmfreq / 1000000);
    printf("SRI freq: %ld MHz\n", g_ScuClock.srifreq / 1000000);
    printf("STM freq: %ld MHz\n", g_ScuClock.stmfreq / 1000000);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxScuClockDemo_run(void) {}

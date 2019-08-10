/**
 * \file DtsBasicDemo.c
 * \brief Demo DtsBasicDemo
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
#include <Dts/Dts/IfxDts_Dts.h>
#include "DtsBasicDemo.h"
#include "_Utilities/Ifx_Assert.h"

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
void DtsBasicDemo_init(void)
{
    /* Get the default configuration */
    IfxDts_Dts_Config dtsConfig;
    IfxDts_Dts_initModuleConfig(&dtsConfig);

    /* adapt the default configuration if required */
    dtsConfig.lowerTemperatureLimit = -35; /* SMU alarm if temperature value is below this Celsius value */
    dtsConfig.upperTemperatureLimit = 150; /* SMU alarm if temperature value is above this Celsius value */

    /* Module initialisation */
    IfxDts_Dts_initModule(&dtsConfig);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void DtsBasicDemo_run(void)
{
    float32 temperature;

    /* start Sensor */
    IfxDts_Dts_startSensor();

    /* wait until a new result is available */
    while (IfxDts_Dts_isBusy())
    {}

    /* convert result to Celsius */
    temperature = IfxDts_Dts_getTemperatureCelsius();

#ifdef SIMULATION
    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, (temperature == 16));
#endif
    printf("DTS Temperature: %3.1f°C\n", temperature);
}

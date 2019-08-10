/**
 * \file I2cBasicDemo.c
 * \brief Demo I2cBasicDemo
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
#include "I2cBasicDemo.h"
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
App_I2cBasic g_I2cBasic; /**< \brief Demo information */

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
void I2cBasicDemo_init(void)
{
    /* disable interrupts */
    boolean   interruptState = IfxCpu_disableInterrupts();

    //Ifx_SizeT size;
    g_I2cBasic.i2cAddr = 0xa0;

    {   /* init Module */
        IfxI2c_I2c_Config config;

        IfxI2c_I2c_initConfig(&config, &MODULE_I2C0);

        const IfxI2c_Pins pins = {&IfxI2c0_SCL_P15_4_INOUT, &IfxI2c0_SDA_P15_5_INOUT, IfxPort_PadDriver_ttlSpeed1};

        config.pins     = &pins;
        config.baudrate = 400000;       /* 400 kHz */

        IfxI2c_I2c_initModule(&g_I2cBasic.i2c, &config);
    }

    {                                                                   /* init slave devices */
        IfxI2c_I2c_deviceConfig i2cDeviceConfig;
        IfxI2c_I2c_initDeviceConfig(&i2cDeviceConfig, &g_I2cBasic.i2c); /* Device config for Bus of i2c handle */

        i2cDeviceConfig.deviceAddress = g_I2cBasic.i2cAddr;
        IfxI2c_I2c_initDevice(&g_I2cBasic.i2cDev, &i2cDeviceConfig);
    }

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void I2cBasicDemo_run(void)
{
    uint32    i;
    Ifx_SizeT size;
    printf("I2cBasicDemo_run() called\n");

    printf("Read\n");

    for (i = 0; i < DATA_SIZE; i++)
    {
        g_I2cBasic.data[i] = 0xee;
    }

    size = 10;      /* number of bytes to rx */

    while (IfxI2c_I2c_read(&g_I2cBasic.i2cDev, g_I2cBasic.data, size) == IfxI2c_I2c_Status_nak)
    {}

    for (i = 0; i < 10; i++)
    {
        if (g_I2cBasic.data[i] == i + 1)
        {
            printf("workingn\n");
        }
    }

    printf("Write\n");

    for (i = 0; i < 10; i++)
    {
        g_I2cBasic.data[i] = 0x10 + i;
    }

    size = 10;      /* number of bytes to tx */

    while (IfxI2c_I2c_write(&g_I2cBasic.i2cDev, g_I2cBasic.data, size) == IfxI2c_I2c_Status_nak)
    {}
}

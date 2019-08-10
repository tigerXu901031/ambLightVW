/**
 * \file I2cBasicDemo.h
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
 *
 * \defgroup IfxLld_Demo_I2cBasicDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_I2cBasicDemo_SrcDoc
 * \defgroup IfxLld_Demo_I2cBasicDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_I2cBasicDemo_SrcDoc_Main
 */

#ifndef I2CBASICDEMO_H
#define I2CBASICDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Configuration.h"
#include <I2c/I2c/IfxI2c_I2c.h>

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define DATA_SIZE 64
/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct
{
    IfxI2c_I2c             i2c;
    IfxI2c_I2c_Device      i2cDev;
    unsigned char          i2cAddr;
    volatile unsigned char data[DATA_SIZE];
    volatile unsigned char cdata[DATA_SIZE];
} App_I2cBasic;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_I2cBasic g_I2cBasic;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void I2cBasicDemo_init(void);
IFX_EXTERN void I2cBasicDemo_run(void);

#endif

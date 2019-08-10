/**
 * \file SentBasicDemo.h
 * \brief Sent Demo
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
 * \defgroup IfxLld_Demo_SentBasicDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_SentBasicDemo_SrcDoc
 * \defgroup IfxLld_Demo_SentBasicDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_SentBasicDemo_SrcDoc_Main
 */

#if !defined(SENTBASICDEMO_H)
#define SENTBASICDEMO_H 1
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include "Configuration.h"
#include "IfxSent_Sent.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct
{
    IfxSent_Sent         sent;
    IfxSent_Sent_Channel sentChannel;
    volatile uint32      interruptCounter;
    volatile uint32      sentRawData;
    volatile uint8       sentStatus;
    volatile uint32      sentMSensorData;
    volatile int         sentTempSensorData;
    volatile int         errors;
} App_Sent;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_Sent g_Sent;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void SentBasicDemo_init(void);
IFX_EXTERN void SentBasicDemo_run(void);

#endif

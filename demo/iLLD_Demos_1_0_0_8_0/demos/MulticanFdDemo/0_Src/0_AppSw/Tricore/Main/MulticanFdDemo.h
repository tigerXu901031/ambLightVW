/**
 * \file MulticanFdDemo.h
 * \brief Demo MulticanFdDemo
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
 * \defgroup IfxLld_Demo_MulticanFd_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_MulticanFd_SrcDoc
 * \defgroup IfxLld_Demo_MulticanFd_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_MulticanFd_SrcDoc_Main
 */

#ifndef MULTICANFDDEMO_H
#define MULTICANFDDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <Ifx_Types.h>
#include "Configuration.h"

#include <Multican/Can/IfxMultican_Can.h>

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Asc information */
typedef struct
{
    struct
    {
        IfxMultican_Can        can;          /**< \brief CAN driver handle */
        IfxMultican_Can_Node   canSrcNode;   /**< \brief CAN Source Node */
        IfxMultican_Can_Node   canDstNode;   /**< \brief CAN Destination Node*/
        IfxMultican_Can_MsgObj canDstMsgObj; /**< \brief CAN Destination Message object */
        IfxMultican_Can_MsgObj canSrcMsgObj; /**< \brief CAN Source Message object */
    }      drivers;

    uint32 txData[16];
    uint32 rxData[16];
} App_MulticanFd;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

IFX_EXTERN App_MulticanFd g_MulticanFd;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

IFX_EXTERN void MulticanFdDemo_init(void);
IFX_EXTERN void MulticanFdDemo_run(void);

#endif

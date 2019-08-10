/**
 * \file MulticanFdDemo.c
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include "MulticanFdDemo.h"

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

App_MulticanFd g_MulticanFd; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

const unsigned id = 0x100;             /* message identifier */

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_MulticanFd_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void MulticanFdDemo_init(void)
{
    /* create module config */
    IfxMultican_Can_Config canConfig;
    IfxMultican_Can_initModuleConfig(&canConfig, &MODULE_CAN);

    /* initialize module */
    IfxMultican_Can_initModule(&g_MulticanFd.drivers.can, &canConfig);

    printf("Prepare CAN Nodes\n");

    /* create CAN node config */
    IfxMultican_Can_NodeConfig canNodeConfig;
    IfxMultican_Can_Node_initConfig(&canNodeConfig, &g_MulticanFd.drivers.can);
    canNodeConfig.baudrate = 1000000;    /* 1 MBaud */

    /* Source Node */
    {
        canNodeConfig.nodeId                         = IfxMultican_NodeId_0;
        canNodeConfig.rxPin                          = &IfxMultican_RXD0B_P20_7_IN;
        canNodeConfig.rxPinMode                      = IfxPort_InputMode_pullUp;
        canNodeConfig.txPin                          = &IfxMultican_TXD0_P20_8_OUT;
        canNodeConfig.txPinMode                      = IfxPort_OutputMode_pushPull;

        canNodeConfig.flexibleDataRate               = TRUE;

        canNodeConfig.fdConfig.nominalBaudrate       = 500000;
        canNodeConfig.fdConfig.nominalSynchJumpWidth = 8000;
        canNodeConfig.fdConfig.nominalSamplePoint    = 2000;
        canNodeConfig.fdConfig.fastBaudrate          = 1000000;
        canNodeConfig.fdConfig.fastSynchJumpWidth    = 8000;
        canNodeConfig.fdConfig.fastSamplePoint       = 2000;
        canNodeConfig.fdConfig.loopDelayOffset       = 0;

        IfxMultican_Can_Node_init(&g_MulticanFd.drivers.canSrcNode, &canNodeConfig);
    }

    /* Destination Node */
    {
        canNodeConfig.nodeId                         = IfxMultican_NodeId_1;
        canNodeConfig.rxPin                          = &IfxMultican_RXD1B_P14_1_IN;
        canNodeConfig.rxPinMode                      = IfxPort_InputMode_pullUp;
        canNodeConfig.txPin                          = &IfxMultican_TXD1_P14_0_OUT;
        canNodeConfig.txPinMode                      = IfxPort_OutputMode_pushPull;

        canNodeConfig.flexibleDataRate               = TRUE;

        canNodeConfig.fdConfig.nominalBaudrate       = 500000;
        canNodeConfig.fdConfig.nominalSynchJumpWidth = 8000;
        canNodeConfig.fdConfig.nominalSamplePoint    = 2000;
        canNodeConfig.fdConfig.fastBaudrate          = 1000000;
        canNodeConfig.fdConfig.fastSynchJumpWidth    = 8000;
        canNodeConfig.fdConfig.fastSamplePoint       = 2000;
        canNodeConfig.fdConfig.loopDelayOffset       = 0;

        IfxMultican_Can_Node_init(&g_MulticanFd.drivers.canDstNode, &canNodeConfig);
    }

    printf("Prepare CAN Message Objects\n");

    /*destination message object */
    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanFd.drivers.canDstNode);

        canMsgObjConfig.msgObjId               = 0;
        canMsgObjConfig.msgObjCount            = 1;
        canMsgObjConfig.messageId              = id;
        canMsgObjConfig.acceptanceMask         = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                  = IfxMultican_Frame_receive;
        canMsgObjConfig.control.messageLen     = IfxMultican_DataLengthCode_64;
        canMsgObjConfig.control.extendedFrame  = FALSE;
        canMsgObjConfig.control.matchingId     = TRUE;

        canMsgObjConfig.control.topMsgObjId    = 252;
        canMsgObjConfig.control.bottomMsgObjId = 253;
        canMsgObjConfig.control.fastBitRate    = FALSE;             /* fast bit rate enable/disable */

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&g_MulticanFd.drivers.canDstMsgObj, &canMsgObjConfig);
    }

    /* source message object */
    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanFd.drivers.canSrcNode);

        canMsgObjConfig.msgObjId               = 1;    /* avoid clashing with transmit FIFO message objects */
        canMsgObjConfig.msgObjCount            = 1;
        canMsgObjConfig.messageId              = id;
        canMsgObjConfig.acceptanceMask         = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                  = IfxMultican_Frame_transmit;
        canMsgObjConfig.control.messageLen     = IfxMultican_DataLengthCode_64;
        canMsgObjConfig.control.extendedFrame  = FALSE;
        canMsgObjConfig.control.matchingId     = TRUE;

        canMsgObjConfig.control.topMsgObjId    = 250;
        canMsgObjConfig.control.bottomMsgObjId = 251;
        canMsgObjConfig.control.fastBitRate    = FALSE;             /* fast bit rate enable/disable */

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&g_MulticanFd.drivers.canSrcMsgObj, &canMsgObjConfig);
    }

    printf("Multican FD is Initialized\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void MulticanFdDemo_run(void)
{
    /* Transmit Data */
    {
        /* load txData buffer with the data that needs to be send */
        uint32 i;

        for (i = 0; i < 16; ++i)
        {
            g_MulticanFd.txData[i] = (0x11110000 + i);
        }

        IfxMultican_Message msg;

        IfxMultican_Message_longFrameInit(&msg, id, IfxMultican_DataLengthCode_64, FALSE);

        while (IfxMultican_Can_MsgObj_sendLongFrame(&g_MulticanFd.drivers.canSrcMsgObj, &msg, g_MulticanFd.txData) == IfxMultican_Status_notSentBusy)
        {}
    }

    /* Receiving Data */
    {
        IfxMultican_Message msg;
        IfxMultican_Message_longFrameInit(&msg, 0xdead, IfxMultican_DataLengthCode_64, FALSE);

        /* wait until MCAN received the frame */
        while (!IfxMultican_Can_MsgObj_isRxPending(&g_MulticanFd.drivers.canDstMsgObj))
        {}

        IfxMultican_Status readStatus = IfxMultican_Can_MsgObj_readLongFrame(&g_MulticanFd.drivers.canDstMsgObj, &msg, g_MulticanFd.rxData);

        /* if no new data is been received report an error */
        if (!(readStatus & IfxMultican_Status_newData))
        {
            printf("ERROR: IfxMultican_Can_MsgObj_readMessage returned 0x%04x\n", readStatus);
        }

        /* if a new data is been received but one lost, report the status */
        if (readStatus == IfxMultican_Status_newDataButOneLost)
        {
            printf(" IfxMultican_Can_MsgObj_readMessage returned 0x%04x\n", readStatus);
        }

        /* clear pending flag */
        IfxMultican_Can_MsgObj_clearRxPending(&g_MulticanFd.drivers.canDstMsgObj);
    }

    printf("Multican FD data transactions are finished\n");
}

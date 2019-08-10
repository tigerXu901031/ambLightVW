/**
 * \file MulticanBasicDemo.c
 * \brief Demo MulticanBasicDemo
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
#include "MulticanBasicDemo.h"

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

App_MulticanBasic g_MulticanBasic; /**< \brief Demo information */

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

/** \addtogroup IfxLld_Demo_MulticanBasic_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void MulticanBasicDemo_init(void)
{
    /* create module config */
    IfxMultican_Can_Config canConfig;
    IfxMultican_Can_initModuleConfig(&canConfig, &MODULE_CAN);

    /* initialize module */
    IfxMultican_Can_initModule(&g_MulticanBasic.drivers.can, &canConfig);

    /* create CAN node config */
    IfxMultican_Can_NodeConfig canNodeConfig;
    IfxMultican_Can_Node_initConfig(&canNodeConfig, &g_MulticanBasic.drivers.can);

    canNodeConfig.baudrate = 1000000;     /* 1 MBaud
                                           *
                                           * Source Node */
    {
        canNodeConfig.nodeId    = (IfxMultican_NodeId)((int)IfxMultican_NodeId_0);
        canNodeConfig.rxPin     = &IfxMultican_RXD0B_P20_7_IN;
        canNodeConfig.rxPinMode = IfxPort_InputMode_pullUp;
        canNodeConfig.txPin     = &IfxMultican_TXD0_P20_8_OUT;
        canNodeConfig.txPinMode = IfxPort_OutputMode_pushPull;

        IfxMultican_Can_Node_init(&g_MulticanBasic.drivers.canSrcNode, &canNodeConfig);
    }

    /* Destination Node */
    {
        canNodeConfig.nodeId    = (IfxMultican_NodeId)((int)IfxMultican_NodeId_1);
        canNodeConfig.rxPin     = &IfxMultican_RXD1B_P14_1_IN;
        canNodeConfig.rxPinMode = IfxPort_InputMode_pullUp;
        canNodeConfig.txPin     = &IfxMultican_TXD1_P14_0_OUT;
        canNodeConfig.txPinMode = IfxPort_OutputMode_pushPull;

        IfxMultican_Can_Node_init(&g_MulticanBasic.drivers.canDstNode, &canNodeConfig);
    }

    /* Destination Message object */
    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanBasic.drivers.canDstNode);

        canMsgObjConfig.msgObjId              = 0;
        canMsgObjConfig.messageId             = id;
        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                 = IfxMultican_Frame_receive;
        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
        canMsgObjConfig.control.extendedFrame = FALSE;
        canMsgObjConfig.control.matchingId    = TRUE;

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&g_MulticanBasic.drivers.canDstMsgObj, &canMsgObjConfig);
    }

    /* Source Message object  */
    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanBasic.drivers.canSrcNode);

        canMsgObjConfig.msgObjId              = 1;
        canMsgObjConfig.messageId             = id;
        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                 = IfxMultican_Frame_transmit;
        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
        canMsgObjConfig.control.extendedFrame = FALSE;
        canMsgObjConfig.control.matchingId    = TRUE;

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&g_MulticanBasic.drivers.canSrcMsgObj, &canMsgObjConfig);
    }

    printf("Multican is Initialized\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void MulticanBasicDemo_run(void)
{
    const uint32 dataLow  = 0x12340000;
    const uint32 dataHigh = 0x9abc0000;

    uint32       errors   = 0;

    /* Transmit Data */
    {
        IfxMultican_Message msg;
        IfxMultican_Message_init(&msg, id, dataLow, dataHigh, IfxMultican_DataLengthCode_8);

        while (IfxMultican_Can_MsgObj_sendMessage(&g_MulticanBasic.drivers.canSrcMsgObj, &msg) == IfxMultican_Status_notSentBusy)
        {}
    }

    /* Receiving Data */
    {
        /* wait until MCAN received the frame */
        while (!IfxMultican_Can_MsgObj_isRxPending(&g_MulticanBasic.drivers.canDstMsgObj))
        {}

        IfxMultican_Message msg1;
        IfxMultican_Message_init(&msg1, 0xdead, 0xdeadbeef, 0xdeadbeef, IfxMultican_DataLengthCode_8); /* start with invalid values */

        IfxMultican_Status  readStatus = IfxMultican_Can_MsgObj_readMessage(&g_MulticanBasic.drivers.canDstMsgObj, &msg1);

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

        /* check the received data */
        if (msg1.data[0] != dataLow)
        {
            ++errors;
        }

        if (msg1.data[1] != dataHigh)
        {
            ++errors;
        }

        if (errors)
        {
            printf("ERROR: Found (%d errors)\n", errors);
        }
        else
        {
            printf("OK: Checks passed\n");
        }
    }

    printf("Multican Basic data transactions are finished");
}

/**
 * \file MulticanGatewayFifoDemo.c
 * \brief Demo MulticanGatewayFifoDemo
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
#include "MulticanGatewayFifoDemo.h"

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

App_MulticanGatewayFifo g_MulticanGatewayFifo; /**< \brief Demo information */

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

/** \addtogroup IfxLld_Demo_MulticanGatewayFifo_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void MulticanGatewayFifoDemo_init(void)
{
    /* create module config */
    IfxMultican_Can_Config canConfig;
    IfxMultican_Can_initModuleConfig(&canConfig, &MODULE_CAN);
    /* initialize module */
    IfxMultican_Can_initModule(&g_MulticanGatewayFifo.drivers.can, &canConfig);

    printf("Prepare CAN Nodes\n");

    /* node initialisation */
    /* create CAN node config */
    IfxMultican_Can_NodeConfig canNodeConfig;
    IfxMultican_Can_Node_initConfig(&canNodeConfig, &g_MulticanGatewayFifo.drivers.can);

    canNodeConfig.baudrate = 1000000;     /* 1 MBaud */

    /* Source Node */
    {
        canNodeConfig.nodeId    = IfxMultican_NodeId_0;
        canNodeConfig.rxPin     = &IfxMultican_RXD0B_P20_7_IN;
        canNodeConfig.rxPinMode = IfxPort_InputMode_pullUp;
        canNodeConfig.txPin     = &IfxMultican_TXD0_P20_8_OUT;
        canNodeConfig.txPinMode = IfxPort_OutputMode_pushPull;

        IfxMultican_Can_Node_init(&g_MulticanGatewayFifo.drivers.canSrcNode, &canNodeConfig);
    }

    /* Destination Node */
    {
        canNodeConfig.nodeId    = IfxMultican_NodeId_1;
        canNodeConfig.rxPin     = &IfxMultican_RXD1B_P14_1_IN;
        canNodeConfig.rxPinMode = IfxPort_InputMode_pullUp;
        canNodeConfig.txPin     = &IfxMultican_TXD1_P14_0_OUT;
        canNodeConfig.txPinMode = IfxPort_OutputMode_pushPull;

        IfxMultican_Can_Node_init(&g_MulticanGatewayFifo.drivers.canDstNode, &canNodeConfig);
    }

    printf("Prepare Message Objects\n");

    /* Message objects initialisation */
    /* source message object */
    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanGatewayFifo.drivers.canSrcNode);

        canMsgObjConfig.msgObjId              = 0;
        canMsgObjConfig.messageId             = id;
        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                 = IfxMultican_Frame_transmit;
        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
        canMsgObjConfig.control.extendedFrame = FALSE;
        canMsgObjConfig.control.matchingId    = TRUE;
        canMsgObjConfig.gatewayTransfers      = FALSE;

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&g_MulticanGatewayFifo.drivers.canSrcMsgObj, &canMsgObjConfig);
    }

    /* gateway source Fifo */
    /* data will be received into this object from SrcObj, and then copied into gateway Fifo objects */
    IfxMultican_Can_MsgObj canGatewaySrcMsgObj;
    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanGatewayFifo.drivers.canDstNode);

        canMsgObjConfig.msgObjId                         = 1;
        canMsgObjConfig.messageId                        = id;
        canMsgObjConfig.msgObjCount                      = 3; /* FIFO */
        canMsgObjConfig.acceptanceMask                   = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                            = IfxMultican_Frame_receive;
        canMsgObjConfig.control.messageLen               = IfxMultican_DataLengthCode_8;
        canMsgObjConfig.control.extendedFrame            = FALSE;
        canMsgObjConfig.control.matchingId               = TRUE;
        canMsgObjConfig.gatewayTransfers                 = TRUE;      /* gateway FIFO */
        canMsgObjConfig.gatewayConfig.copyDataLengthCode = TRUE;
        canMsgObjConfig.gatewayConfig.copyData           = TRUE;
        canMsgObjConfig.gatewayConfig.copyId             = FALSE;
        canMsgObjConfig.gatewayConfig.enableTransmit     = TRUE;
        canMsgObjConfig.firstSlaveObjId                  = 2;

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&canGatewaySrcMsgObj, &canMsgObjConfig);
    }

    uint32 i = 0;

    for (i = 0; i < 3; ++i)
    {
        /* gateway destination objects */
        /* data, id , datlength code will be copied from GatewaySrcObj into this object through gateway transfers */
        /* and then sent onto the bus for sending the message to destination receive Fifo message objects */
        IfxMultican_Can_MsgObj canGatewayDstMsgObj;
        {
            /* create message object config */
            IfxMultican_Can_MsgObjConfig canMsgObjConfig;
            IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanGatewayFifo.drivers.canSrcNode);

            canMsgObjConfig.msgObjId              = 2 + i;
            canMsgObjConfig.messageId             = 0x200;
            canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
            canMsgObjConfig.frame                 = IfxMultican_Frame_transmit;
            canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
            canMsgObjConfig.control.extendedFrame = FALSE;
            canMsgObjConfig.control.matchingId    = TRUE;
            canMsgObjConfig.gatewayTransfers      = FALSE;

            /* initialize message object */
            IfxMultican_Can_MsgObj_init(&canGatewayDstMsgObj, &canMsgObjConfig);
        }
    }

    /* destination receive Fifo */
    /* data will be received from GatewayDstObj into this Fifo */
    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanGatewayFifo.drivers.canDstNode);

        canMsgObjConfig.msgObjId              = 10;
        canMsgObjConfig.messageId             = 0x200;
        canMsgObjConfig.msgObjCount           = 3; /* receive FIFO */
        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                 = IfxMultican_Frame_receive;
        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
        canMsgObjConfig.control.extendedFrame = FALSE;
        canMsgObjConfig.control.matchingId    = FALSE;
        canMsgObjConfig.gatewayTransfers      = FALSE;
        canMsgObjConfig.firstSlaveObjId       = 11;

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&g_MulticanGatewayFifo.drivers.canDstMsgObj, &canMsgObjConfig);
    }

    printf("Multican Gateway Fifo Initialized\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void MulticanGatewayFifoDemo_run(void)
{
    const uint32 dataLow  = 0xC0CAC01A;
    const uint32 dataHigh = 0xBA5EBA11;

    uint32       i, errors = 0;

    for (i = 0; i < 3; ++i)
    {
        /* Transmit Data from the source message object */
        {
            IfxMultican_Message msg;
            IfxMultican_Message_init(&msg, id, dataLow + i, dataHigh + i, IfxMultican_DataLengthCode_8);

            while (IfxMultican_Can_MsgObj_sendMessage(&g_MulticanGatewayFifo.drivers.canSrcMsgObj, &msg) == IfxMultican_Status_notSentBusy)
            {}
        }
    }

    for (i = 0; i < 3; ++i)
    {
        /* Receiving Data, read the data from the destination receive Fifo */
        {
            /* wait until MCAN received the frame */
            /* wait until Multican received a new message */
            while (!IfxMultican_Can_MsgObj_isRxPending(&g_MulticanGatewayFifo.drivers.canDstMsgObj))
            {}

            IfxMultican_Message msg1;
            IfxMultican_Message_init(&msg1, 0xdead, 0xdeadbeef, 0xdeadbeef, IfxMultican_DataLengthCode_8); /* start with invalid values */

            IfxMultican_Status  readStatus = IfxMultican_Can_MsgObj_readMessage(&g_MulticanGatewayFifo.drivers.canDstMsgObj, &msg1);

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
            if (msg1.data[0] != dataLow + i)
            {
                ++errors;
            }

            if (msg1.data[1] != dataHigh + i)
            {
                ++errors;
            }
        }
    }

    if (errors)
    {
        printf("ERROR: Found (%d errors)\n", errors);
    }
    else
    {
        printf("OK: Checks passed\n");
    }

    printf("Multican Gateway Fifo data transactions are finished\n");
}

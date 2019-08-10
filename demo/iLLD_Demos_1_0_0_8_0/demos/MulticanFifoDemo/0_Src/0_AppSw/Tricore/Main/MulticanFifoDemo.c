/**
 * \file MulticanFifoDemo.c
 * \brief Demo MulticanFifoDemo
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
#include "MulticanFifoDemo.h"

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

App_MulticanFifo g_MulticanFifo; /**< \brief Demo information */

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

/** \addtogroup IfxLld_Demo_MulticanFifo_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void MulticanFifoDemo_init(void)
{
    /* create module config */
    IfxMultican_Can_Config canConfig;
    IfxMultican_Can_initModuleConfig(&canConfig, &MODULE_CAN);

    /* initialize module */
    IfxMultican_Can_initModule(&g_MulticanFifo.drivers.can, &canConfig);

    printf("Prepare CAN Nodes\n");

    /* create CAN node config */
    IfxMultican_Can_NodeConfig canNodeConfig;
    IfxMultican_Can_Node_initConfig(&canNodeConfig, &g_MulticanFifo.drivers.can);

    canNodeConfig.baudrate = 1000000;         /* 1 MBaud */

    /* Source Node */
    {
        canNodeConfig.nodeId    = IfxMultican_NodeId_0;
        canNodeConfig.rxPin     = &IfxMultican_RXD0B_P20_7_IN;
        canNodeConfig.rxPinMode = IfxPort_InputMode_pullUp;
        canNodeConfig.txPin     = &IfxMultican_TXD0_P20_8_OUT;
        canNodeConfig.txPinMode = IfxPort_OutputMode_pushPull;

        IfxMultican_Can_Node_init(&g_MulticanFifo.drivers.canSrcNode, &canNodeConfig);
    }

    /* Destination Node */
    {
        canNodeConfig.nodeId    = IfxMultican_NodeId_1;
        canNodeConfig.rxPin     = &IfxMultican_RXD1B_P14_1_IN;
        canNodeConfig.rxPinMode = IfxPort_InputMode_pullUp;
        canNodeConfig.txPin     = &IfxMultican_TXD1_P14_0_OUT;
        canNodeConfig.txPinMode = IfxPort_OutputMode_pushPull;

        IfxMultican_Can_Node_init(&g_MulticanFifo.drivers.canDstNode, &canNodeConfig);
    }

    printf("Prepare CAN Message Objects\n");

    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanFifo.drivers.canDstNode);

        canMsgObjConfig.msgObjId              = 0;
        canMsgObjConfig.msgObjCount           = FIFO_SIZE;
        canMsgObjConfig.firstSlaveObjId       = 1;
        canMsgObjConfig.messageId             = id;
        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                 = IfxMultican_Frame_receive;
        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
        canMsgObjConfig.control.extendedFrame = FALSE;
        canMsgObjConfig.control.matchingId    = TRUE;

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&g_MulticanFifo.drivers.canDstMsgObj, &canMsgObjConfig);
    }

    {
        /* create message object config */
        IfxMultican_Can_MsgObjConfig canMsgObjConfig;
        IfxMultican_Can_MsgObj_initConfig(&canMsgObjConfig, &g_MulticanFifo.drivers.canSrcNode);

        canMsgObjConfig.msgObjId              = FIFO_SIZE + 1;     /* avoid clashing with transmit FIFO message objects */
        canMsgObjConfig.msgObjCount           = FIFO_SIZE / 2;
        canMsgObjConfig.firstSlaveObjId       = FIFO_SIZE + 2;
        canMsgObjConfig.messageId             = id;
        canMsgObjConfig.acceptanceMask        = 0x7FFFFFFFUL;
        canMsgObjConfig.frame                 = IfxMultican_Frame_transmit;
        canMsgObjConfig.control.messageLen    = IfxMultican_DataLengthCode_8;
        canMsgObjConfig.control.extendedFrame = FALSE;
        canMsgObjConfig.control.matchingId    = TRUE;

        /* initialize message object */
        IfxMultican_Can_MsgObj_init(&g_MulticanFifo.drivers.canSrcMsgObj, &canMsgObjConfig);
    }

    printf("Multican Fifo is Initialized\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void MulticanFifoDemo_run(void)
{
    /* three rounds */
    uint32 round, i, errors = 0;

    for (round = 0; round < 3; ++round)
    {
        printf("Round #%d\n", round + 1);

        /* Transmit Data */
        {
            IfxMultican_Message msg;
            IfxMultican_Message_init(&msg, id, 0, 0, IfxMultican_DataLengthCode_8);

            /* send some data */
            for (i = 0; i < FIFO_SIZE; ++i)
            {
                msg.data[0] = (0x11110000 + i + round * 0x100);
                msg.data[1] = (0x22220000 + i + round * 0x100);

                while (IfxMultican_Can_MsgObj_sendMessage(&g_MulticanFifo.drivers.canSrcMsgObj, &msg) == IfxMultican_Status_notSentBusy)
                {}
            }
        }

        /* Receiving Data */
        {
            IfxMultican_Message msg;
            IfxMultican_Message_init(&msg, id, 0xdeadbeef, 0xdeadbeef, IfxMultican_DataLengthCode_8);

            /* receive data */
            for (i = 0; i < FIFO_SIZE; ++i)
            {
                /* wait until Multican received a new message */
                while (!IfxMultican_Can_MsgObj_isRxPending(&g_MulticanFifo.drivers.canDstMsgObj))
                {}

                /* read message */
                IfxMultican_Status readStatus = IfxMultican_Can_MsgObj_readMessage(&g_MulticanFifo.drivers.canDstMsgObj, &msg);

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
                if (msg.data[0] != (0x11110000 + i + round * 0x100))
                {
                    ++errors;
                }

                if (msg.data[1] != (0x22220000 + i + round * 0x100))
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
    }

    printf("Multican Fifo Data transactions are finished\n");
}

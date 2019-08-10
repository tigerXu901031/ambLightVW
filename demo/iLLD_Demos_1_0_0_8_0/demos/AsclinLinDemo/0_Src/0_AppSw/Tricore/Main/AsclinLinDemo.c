/**
 * \file AsclinLinDemo.c
 * \brief Demo AsclinLinDemo
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
#include "AsclinLinDemo.h"

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

App_AsclinLin g_AsclinLin; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_AsclinLin_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void AsclinLinDemo_init(void)
{
    /* disable interrupts */
    boolean              interruptState = IfxCpu_disableInterrupts();

    /* create module config */
    IfxAsclin_Lin_Config linConfig;
    IfxAsclin_Lin_initModuleConfig(&linConfig, &MODULE_ASCLIN1);

    /* set the desired baudrate */
#ifdef SIMULATION
    linConfig.brg.baudrate     = 1000000;
#else
    linConfig.brg.baudrate     = 19200;      /* FDR values will be calculated in initModule */
#endif
    linConfig.btc.oversampling = IfxAsclin_OversamplingFactor_4;

    /* pin configuration */
    const IfxAsclin_Lin_Pins pins = {
        &IfxAsclin1_RXB_P15_5_IN, IfxPort_InputMode_pullUp,      /* Rx pin */
        &IfxAsclin1_TX_P15_4_OUT, IfxPort_OutputMode_pushPull,   /* Tx pin */
        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    linConfig.pins = &pins;

    /* initialize module */
    IfxAsclin_Lin_initModule(&g_AsclinLin.drivers.lin, &linConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    printf("Asclin Lin is initialised\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void AsclinLinDemo_run(void)
{
    /* set the id byte */
    uint8 txId = 0x80;      /* for sending respose after header */
    uint8 rxId = 0xC1;      /* for receiving respose after header */

    /* prepare data to transmit and receive */
    g_AsclinLin.size = 8;

    uint32 i;

    for (i = 0; i < g_AsclinLin.size; ++i)
    {
        /* prepare the data to be transfered */
        g_AsclinLin.txData[i] = i + 1;    /* {1, 2, 3 ,4 ,5, 6, 7, 8} */
        /* prepare an empty buffer for received data */
        g_AsclinLin.rxData[i] = 0;
    }

    /* master mode */

    /* sending */
    IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &txId);                                             /* send header */

    if (g_AsclinLin.drivers.lin.acknowledgmentFlags.txHeaderEnd == 1)                                      /* if the header is been transmitted succesfully */
    {
        IfxAsclin_Lin_sendResponse(&g_AsclinLin.drivers.lin, g_AsclinLin.txData, g_AsclinLin.size);        /* send response */
    }

    if (g_AsclinLin.drivers.lin.acknowledgmentFlags.txResponseEnd == 1)                                    /* if the response is been transmitted succesfully */
    {
        /* receiving */
        IfxAsclin_Lin_sendHeader(&g_AsclinLin.drivers.lin, &rxId);                                         /* send header */

        if (g_AsclinLin.drivers.lin.acknowledgmentFlags.txHeaderEnd == 1)                                  /* if the header is been transmitted succesfully */
        {
            IfxAsclin_Lin_receiveResponse(&g_AsclinLin.drivers.lin, g_AsclinLin.rxData, g_AsclinLin.size); /* receive response */
        }
    }

    printf("Asclin Lin data transactions are finished\n");
}

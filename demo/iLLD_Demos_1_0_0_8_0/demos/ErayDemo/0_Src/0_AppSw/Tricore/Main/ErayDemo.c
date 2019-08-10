/**
 * \file ErayDemo.c
 * \brief Eray Demo
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

#include "ErayDemo.h"

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
App_Eray g_Eray; /**< \brief Eray global data */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
void ERAY_irqInt0Handler(void);
void ERAY_irqInt1Handler(void);
void ERAY_irqNdat1Handler(void);
/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_Demo_Eray_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for ERAY drivers
 * \{ */
IFX_INTERRUPT(ERAY_irqInt0Handler, 0, ISR_PRIORITY_ERAY_INT0);
IFX_INTERRUPT(ERAY_irqInt1Handler, 0, ISR_PRIORITY_ERAY_INT1);
IFX_INTERRUPT(ERAY_irqNdat1Handler, 0, ISR_PRIORITY_ERAY_NDAT1);
/** \} */

/** \} */

/** \brief Handle Eray INT 0 service line interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_ERAY_INT0
 * \isrPriority \ref ISR_PRIORITY_ERAY_INT0
 *
 */
void ERAY_irqInt0Handler(void)
{
    /*Get the error interrupt flags*/
    Ifx_ERAY_EIR ErrIntStat = IfxEray_Eray_getErrorInterrupts(&g_Eray.eray);

    /* Get the status interrupt flags*/
    Ifx_ERAY_SIR StatusIntStat = IfxEray_Eray_getStatusInterrupts(&g_Eray.eray);

    if (StatusIntStat.B.SDS)
    {
        /* SDS must be cleared for getting the next interrupt   */
        IfxEray_Eray_clearStatusFlag(&g_Eray.eray, IfxEray_ClearStatusFlag_sds);
    }

    if (StatusIntStat.B.CYCS)
    {
        /* CYCS must be cleared for getting the next interrupt   */
        IfxEray_Eray_clearStatusFlag(&g_Eray.eray, IfxEray_ClearStatusFlag_cycs);
    }

    if (StatusIntStat.B.SUCS)
    {
        /* SUCS must be cleared for getting the next interrupt   */
        IfxEray_Eray_clearStatusFlag(&g_Eray.eray, IfxEray_ClearStatusFlag_sucs);
    }

    if (StatusIntStat.B.TIBC)
    {
        /* TIBC must be cleared for getting the next interrupt   */
        IfxEray_Eray_clearStatusFlag(&g_Eray.eray, IfxEray_ClearStatusFlag_tibc);
    }

    if (ErrIntStat.B.MHF)
    {
        g_Eray.errors++;
        /* clear flag MHF */
        IfxEray_Eray_clearErrorFlag(&g_Eray.eray, IfxEray_ClearErrorFlag_mhf);
    }
}


/** \brief Handle Eray INT 1 service line interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_ERAY_INT1
 * \isrPriority \ref ISR_PRIORITY_ERAY_INT1
 *
 */
void ERAY_irqInt1Handler(void)
{
    /*Get the status interrupt flags*/
    Ifx_ERAY_SIR StatusIntStat = IfxEray_Eray_getStatusInterrupts(&g_Eray.eray);

    if (StatusIntStat.B.TOBC)
    {
        /* TOBC must be cleared for getting the next interrupt */
        IfxEray_Eray_clearStatusFlag(&g_Eray.eray, IfxEray_ClearStatusFlag_tobc);
    }
}


/** \brief Handle Eray New Data 1 service line interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_ERAY_NDAT1
 * \isrPriority \ref ISR_PRIORITY_ERAY_NDAT1
 *
 */
void ERAY_irqNdat1Handler(void)
{
    if (g_Eray.ndatCount < NUMBER_ERAY_COMM_CYCLES)
    {
        /*message received in slot1 buffer*/
        if (IfxEray_Eray_getNewDataInterruptStatus(&g_Eray.eray, 1) == 1)
        {
            uint32 data[2];
            /*store received data in slot 1*/
            {
                IfxEray_Eray_ReceiveControl config;
                config.headerReceived   = FALSE;
                config.dataReceived     = TRUE;
                config.receiveRequested = TRUE;
                config.swapRequested    = TRUE;
                config.bufferIndex      = 1;
                IfxEray_Eray_receiveFrame(&g_Eray.eray, &config);
                IfxEray_Eray_readData(&g_Eray.eray, &g_Eray.receivedData[g_Eray.ndatCount++][0], 2 * 2);
            }
            /* write local buffer to send the data in other slot*/
            data[0] = g_Eray.receivedData[g_Eray.ndatCount - 1][0];
            data[1] = g_Eray.receivedData[g_Eray.ndatCount - 1][1];
            /* send "data" in slot 0*/
            {
                IfxEray_Eray_writeData(&g_Eray.eray, data, 2 * 2);
                IfxEray_Eray_TransmitControl config;
                config.headerTransfered  = FALSE;
                config.dataTransfered    = TRUE;
                config.transferRequested = TRUE;
                config.bufferIndex       = 0;
                IfxEray_Eray_transmitFrame(&g_Eray.eray, &config);
            }
        }
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
IFX_EXTERN void IfxErayDemo_init(void)
{
    printf("IfxErayDemo_init() called\n");

    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    int     result         = 0;
    int     i;

    g_Eray.ndatCount = 0;
    g_Eray.errors    = 0;

    /*initialize Eray PLL*/
    printf("Initialize ERAY PLL\n");
    {
        IfxScuCcu_ErayPllConfig ErayPllConfig;
        IfxScuCcu_initErayPllConfig(&ErayPllConfig);
        result |= IfxScuCcu_initErayPll(&ErayPllConfig);
    }

    /* create default module config*/
    printf("Initialize ERAY0\n");
    IfxEray_Eray_initModuleConfig(&g_Eray.erayModuleConfig, &MODULE_ERAY0);

    /*Supplied Module Config*/
    g_Eray.erayModuleConfig.interrupt.int0Priority  = ISR_PRIORITY_ERAY_INT0;
    g_Eray.erayModuleConfig.interrupt.int1Priority  = ISR_PRIORITY_ERAY_INT1;
    g_Eray.erayModuleConfig.interrupt.ndat1Priority = ISR_PRIORITY_ERAY_NDAT1;

    IfxEray_Eray_initModule(&g_Eray.eray, &g_Eray.erayModuleConfig);

    /*create ERAY node default configuration*/
    IfxEray_Eray_Node_initConfig(&g_Eray.nodeConfig);

    /* ERAY node suppled configurations*/
    /* Messages*/
    g_Eray.nodeConfig.messageRAMConfig.numberOfMessageBuffers = 2;
    g_Eray.nodeConfig.messageRAMConfig.firstDynamicBuffer     = 0x40;
    g_Eray.nodeConfig.messageRAMConfig.fifoBufferStartIndex   = 0x40;

    /*Frame header */
    IfxEray_Header     header[NO_OF_SLOTS] = {
        /* fid  cyc  cha    chb     buffer direction                   ppit   transmission mode          mbi    pl  dp   startup  sync*/
        {2, 1, TRUE, TRUE, IfxEray_BufferDirection_transmit, TRUE,  IfxEray_TransmissionMode_continuous, TRUE, 4, 0x30, TRUE,  TRUE },
        {1, 1, TRUE, TRUE, IfxEray_BufferDirection_receive,  FALSE, IfxEray_TransmissionMode_continuous, TRUE, 4, 0x40, FALSE, FALSE},
    };

    /* slot buffer transmit configuration */
    IfxEray_SlotConfig slot[NO_OF_SLOTS] = {
        /* header data   stxrh bufferNum */
        {TRUE, TRUE,  TRUE,  0},
        {TRUE, FALSE, FALSE, 1},
    };

    for (i = 0; i < NO_OF_SLOTS; i++)
    {
        g_Eray.nodeConfig.messageRAMConfig.header[i]      = &header[i];
        g_Eray.nodeConfig.messageRAMConfig.slotControl[i] = &slot[i];
        g_Eray.nodeConfig.messageRAMConfig.data[i]        = NULL_PTR;
    }

    /* channel A pins*/
    const IfxEray_Eray_NodeA nodeAPins = {
        IfxPort_InputMode_pullDown,             IfxPort_OutputMode_pushPull,
        IfxPort_PadDriver_cmosAutomotiveSpeed3, IfxPort_OutputMode_pushPull,
        &IfxEray0_RXDA0_P14_8_IN,               &IfxEray0_TXDA_P14_10_OUT,
        &IfxEray0_TXENA_P14_9_OUT
    };
    /* channel B pins*/
    const IfxEray_Eray_NodeB nodeBPins = {
        IfxPort_InputMode_pullDown,             IfxPort_OutputMode_pushPull,
        IfxPort_PadDriver_cmosAutomotiveSpeed3, IfxPort_OutputMode_pushPull,
        &IfxEray0_RXDB0_P14_7_IN,               &IfxEray0_TXDB_P14_5_OUT,
        &IfxEray0_TXENB_P14_6_OUT
    };

    const IfxEray_Eray_Pins  pins = {(IfxEray_Eray_NodeA *)&nodeAPins, (IfxEray_Eray_NodeB *)&nodeBPins};
    g_Eray.nodeConfig.pins = (IfxEray_Eray_Pins *)&pins;

    /*ERAY node initialisation with supplied configuration*/
    IfxEray_Eray_Node_init(&g_Eray.eray, &g_Eray.nodeConfig);

    /*ALL NDAT interrupts are routed to SRC_ERAYNDAT1 interrupt service line*/
    IfxEray_Eray_setNewDataInterruptDestination(&g_Eray.eray, 0, 1); // New Data #0 -> NDAT1
    IfxEray_Eray_setNewDataInterruptDestination(&g_Eray.eray, 1, 1); // New Data #1 -> NDAT1

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    /* wait for wakeup pattern on default configured channel ( IfxEray_Channel_a )*/
    while (IfxEray_Eray_getWakeupPatternReceivedChannel(&g_Eray.eray) != IfxEray_WakeupChannel_a)
    {}

    /* allow node to cold-start and wait until cold-start is successful*/
    while (!IfxEray_Eray_allowColdStart(&g_Eray.eray))
    {}

    /* start the communication in cluster and wait until communication is successfull*/
    while (!IfxEray_Eray_startCommunication(&g_Eray.eray))
    {}

    /* wait until communication Controller enters NORMAL_ACTIVE or NORMAL_PASSIVE state, exit if communication Controller enters HALT state.*/
    IfxEray_PocState pocState;

    do
    {
        pocState = IfxEray_Eray_getPocState(&g_Eray.eray);

        /*if communication Controller enters HALT state, break the loop.*/
        if (pocState == IfxEray_PocState_halt)
        {
            break;
        }
    } while (!((pocState == IfxEray_PocState_normalActive) || (pocState == IfxEray_PocState_normalPassive)));

    /*enter ALL_SLOTS mode when Communication Controller is in NORMAL_ACTIVE or NORMAL_PASSIVE state only.*/
    if ((pocState == IfxEray_PocState_normalActive) || (pocState == IfxEray_PocState_normalPassive))
    {
        while (!IfxEray_Eray_setPocAllSlots(&g_Eray.eray))
        {}
    }
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
IFX_EXTERN void IfxErayDemo_run(void)
{
    printf("IfxErayDemo_run() called\n");
    int      i;

    unsigned prevReceivedDataCounter = 0;

    /* wait until all data received in all cycles*/
    while (1)
    {
        if (g_Eray.ndatCount != prevReceivedDataCounter)
        {
            prevReceivedDataCounter = g_Eray.ndatCount;
            printf("Received %d packets \n", g_Eray.ndatCount);

            if (g_Eray.ndatCount >= NUMBER_ERAY_COMM_CYCLES)
            {
                g_Eray.ndatCount = 0;
                break;
            }
        }
    }

    /*print the data received in all communication cycles*/
    for (i = 0; i < NUMBER_ERAY_COMM_CYCLES; ++i)
    {
        printf("Data packet received in slot1 cycle %d is: %d %d \n", g_Eray.ndatCount, g_Eray.receivedData[i][0], g_Eray.receivedData[i][1]);
    }

    if (g_Eray.errors)
    {
        printf("ERROR: %d Errors occured during communication\n", g_Eray.errors);
    }
    else
    {
        printf("OK: No Errors during communication \n");
    }
}

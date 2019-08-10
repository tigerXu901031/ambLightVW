/**
 * \file EthDemo.c
 * \brief Demo EthDemo
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
#include "EthDemo.h"

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

App_Eth g_Eth; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

const uint8 myMacAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_Eth_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void EthDemo_init(void)
{
    /* configure Ethermac */
    {
        const IfxEth_RmiiPins pins = {
            &IfxEth_CRSDVA_P11_11_IN,
            &IfxEth_REFCLK_P11_12_IN,
            &IfxEth_RXD0_P11_10_IN,
            &IfxEth_RXD1_P11_9_IN,
            &IfxEth_MDC_P21_0_OUT,
            &IfxEth_MDIO_P21_1_INOUT,
            &IfxEth_TXD0_P11_3_OUT,
            &IfxEth_TXD1_P11_2_OUT,
            &IfxEth_TXEN_P11_6_OUT
        };

        IfxEth_Config   config;
        IfxEth_initConfig(&config, &MODULE_ETH);

		config.phyInterfaceMode = IfxEth_PhyInterfaceMode_rmii;
		config.rmiiPins = &pins;
		config.phyInit = &IfxEth_Phy_Pef7071_init;
		config.phyLink = &IfxEth_Phy_Pef7071_link;

        IfxEth_init(&g_Eth.drivers.eth, &config);

        /* activate loopback */
        IfxEth_setLoopbackMode(&g_Eth.drivers.eth, 1);

        /* and enable transmitter/receiver */
        IfxEth_startTransmitter(&g_Eth.drivers.eth);
        IfxEth_startReceiver(&g_Eth.drivers.eth);
    }

    printf("Eth is initialised\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void EthDemo_run(void)
{
    printf("Ethernet transfers in loopback mode are started\n");

    /* send 5 packets, each contains 8 bytes */
    const uint32 numPackets = 5;
    const uint32 packetSize = 8;

    uint32       packet;

    for (packet = 0; packet < numPackets; ++packet)
    {
        uint8 *pTxBuf = (uint8 *)IfxEth_waitTransmitBuffer(&g_Eth.drivers.eth);

        printf("TX #%d\n", packet + 1);

        /* DA */
        const uint8 packetId = 0x10 * packet;
        uint32      i;

        for (i = 0; i < 6; i++)
        {
            pTxBuf[i] = myMacAddress[i];
        }

        /* SA */
        for (i = 0; i < 6; i++)
        {
            pTxBuf[i + 6] = myMacAddress[i];
        }

        /* length of payload */
        pTxBuf[12] = packetSize / 256;
        pTxBuf[13] = packetSize % 256;

        for (i = HEADER_SIZE; i < (HEADER_SIZE + packetSize); i++)
        {
            pTxBuf[i] = packetId | (i % 16);
        }

        /* send packet */
        IfxEth_clearTxInterrupt(&g_Eth.drivers.eth);
        IfxEth_sendTransmitBuffer(&g_Eth.drivers.eth, HEADER_SIZE + packetSize);

        while (IfxEth_isTxInterrupt(&g_Eth.drivers.eth) == FALSE)
        {}
    }

    /* check the 5 received packets */
    uint32 errors = 0;

    for (packet = 0; packet < numPackets; ++packet)
    {
        printf("RX #%d\n", packet + 1);

#if 0

        /* only one interrupt for all the received packets so far... */
        while (IfxEth_isRxInterrupt(&g_Eth.drivers.eth) == FALSE)
        {}

        IfxEth_clearRxInterrupt(&g_Eth.drivers.eth);
#else

        if (IfxEth_isRxDataAvailable(&g_Eth.drivers.eth) != TRUE)
        {
            ++errors;
        }

#endif
        uint8      *pRxBuf = (uint8 *)IfxEth_getReceiveBuffer(&g_Eth.drivers.eth); /* we expect that a packet is available */
        IfxEth_freeReceiveBuffer(&g_Eth.drivers.eth);

        /* DA */
        const uint8 packetId = 0x10 * packet;
        uint32      i;

        for (i = 0; i < 6; i++)
        {
            if (pRxBuf[i] != myMacAddress[i])
            {
                ++errors;
            }
        }

        /* SA */
        for (i = 0; i < 6; i++)
        {
            if (pRxBuf[i + 6] != myMacAddress[i])
            {
                ++errors;
            }
        }

        /* length of payload */
        if (pRxBuf[12] != (packetSize / 256))
        {
            ++errors;
        }

        if (pRxBuf[13] != (packetSize % 256))
        {
            ++errors;
        }

        for (i = HEADER_SIZE; i < (HEADER_SIZE + packetSize); i++)
        {
            if (pRxBuf[i] != (packetId | (i % 16)))
            {
                ++errors;
            }
        }
    }

    printf("Expect that no additional receive data is available:");

    if (IfxEth_isRxDataAvailable(&g_Eth.drivers.eth) != FALSE)
    {
        ++errors;
    }

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, errors == 0);

    if (errors)
    {
        printf("ERROR: Found (%d errors)\n", errors);
    }
    else
    {
        printf("OK: Checks passed\n");
    }
}

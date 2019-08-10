/**
 * \file AsclinSpiDemo.c
 * \brief Demo AsclinSpiDemo
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
#include "AsclinSpiDemo.h"

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

App_AsclinSpi g_AsclinSpi; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_AsclinSpi_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Transmit
 * \{ */

IFX_INTERRUPT(asclin1TxISR, 0, ISR_PRIORITY_ASCLIN1_TX)
{
    IfxAsclin_Spi_isrTransmit(&g_AsclinSpi.drivers.spi);
}

/** \} */

/** \name Interrupts for Receive
 * \{ */

IFX_INTERRUPT(asclin1RxISR, 0, ISR_PRIORITY_ASCLIN1_RX)
{
    IfxAsclin_Spi_isrReceive(&g_AsclinSpi.drivers.spi);
}

/** \} */

/** \name Interrupts for Error
 * \{ */

IFX_INTERRUPT(asclin1ErISR, 0, ISR_PRIORITY_ASCLIN1_ER)
{
    IfxAsclin_Spi_isrError(&g_AsclinSpi.drivers.spi);
}

/** \} */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void AsclinSpiDemo_init(void)
{
    /* disable interrupts */
    boolean              interruptState = IfxCpu_disableInterrupts();

    /* create module config */
    IfxAsclin_Spi_Config spiConfig;
    IfxAsclin_Spi_initModuleConfig(&spiConfig, &MODULE_ASCLIN1);

    /* set the desired baudrate */
    spiConfig.baudrate.prescaler    = 1;
    spiConfig.baudrate.baudrate     = 1000000;                   /* FDR values will be calculated in initModule */
    spiConfig.baudrate.oversampling = IfxAsclin_OversamplingFactor_4;

    spiConfig.inputOutput.loopBack  = TRUE;

    /* ISR priorities and interrupt target */
    spiConfig.interrupt.txPriority    = ISR_PRIORITY_ASCLIN1_TX; /* see also \ref IfxLld_Asclin */
    spiConfig.interrupt.rxPriority    = ISR_PRIORITY_ASCLIN1_RX; /* see also \ref IfxLld_Asclin */
    spiConfig.interrupt.erPriority    = ISR_PRIORITY_ASCLIN1_ER; /* see also \ref IfxLld_Asclin */
    spiConfig.interrupt.typeOfService = (IfxSrc_Tos)IfxCpu_getCoreIndex();

    /* pin configuration */
    const IfxAsclin_Spi_Pins pins = {
        &IfxAsclin1_SCLK_P15_0_OUT, IfxPort_OutputMode_pushPull, /* Clock out pin */
        &IfxAsclin1_RXA_P15_1_IN,   IfxPort_InputMode_pullUp,    /* Rx pin */
        &IfxAsclin1_TX_P15_4_OUT,   IfxPort_OutputMode_pushPull, /* Tx pin */
        &IfxAsclin1_SLSO_P20_8_OUT, IfxPort_OutputMode_pushPull, /* Slave select pin */
        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    spiConfig.pins = &pins;

    /* initialize module */
    IfxAsclin_Spi_initModule(&g_AsclinSpi.drivers.spi, &spiConfig);

    printf(" Asclin Spi initialised\n");

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void AsclinSpiDemo_run(void)
{
    uint32 i, j, errors = 0;

    for (i = 0; i < 3; ++i)
    {
        {
            uint8 *tx = g_AsclinSpi.spiTxBuffer;
            uint8 *rx = g_AsclinSpi.spiRxBuffer;

            for (j = 0; j < SPI_BUFFER_SIZE; ++j)
            {
                *tx++ = i * 0x10 + j;
                *rx++ = 0;
            }
        }

        /* send/receive new stream */
        IfxAsclin_Spi_exchange(&g_AsclinSpi.drivers.spi, g_AsclinSpi.spiTxBuffer, g_AsclinSpi.spiRxBuffer, SPI_BUFFER_SIZE);

        /* wait until transfer of previous data stream is finished */
        while (IfxAsclin_Spi_getStatus(&g_AsclinSpi.drivers.spi) == IfxAsclin_Spi_Status_busy)
        {}

        /* check received stream */
        {
            uint8 *rx = g_AsclinSpi.spiRxBuffer;

            for (j = 0; j < SPI_BUFFER_SIZE; ++j)
            {
                if (*rx++ != i * 0x10 + j)
                {
                    ++errors;
                }
            }
        }

        if (errors)
        {
            printf("ERROR: received data doesn't match with expected data (%lu mismatches)\n", errors);
        }
        else
        {
            printf("OK: received data matches with expected data\n");
        }
    }

    printf("Asclin Spi Data transactions are finished\n");
}

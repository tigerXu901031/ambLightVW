/**
 * \file AsclinSpiDemo.h
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
 *
 * \defgroup IfxLld_Demo_AsclinSpi_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_AsclinSpi_SrcDoc
 * \defgroup IfxLld_Demo_AsclinSpi_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_AsclinSpi_SrcDoc_Main
 */

#ifndef ASCLINSPIDEMO_H
#define ASCLINSPIDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <Ifx_Types.h>
#include "Configuration.h"
#include "_Lib/DataHandling/Ifx_Fifo.h"

#include <Asclin/Spi/IfxAsclin_Spi.h>

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define ASC_TX_BUFFER_SIZE 64
#define ASC_RX_BUFFER_SIZE 64

#define SPI_BUFFER_SIZE    32

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    uint8 tx[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
    uint8 rx[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
} AppAscBuffer;

/** \brief Asc information */
typedef struct
{
    AppAscBuffer ascBuffer;                     /**< \brief ASC interface buffer */
    struct
    {
        IfxAsclin_Spi spi;                      /**< \brief ASC interface */
    }     drivers;

    uint8 spiTxBuffer[SPI_BUFFER_SIZE];
    uint8 spiRxBuffer[SPI_BUFFER_SIZE];
} App_AsclinSpi;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

IFX_EXTERN App_AsclinSpi g_AsclinSpi;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

IFX_EXTERN void AsclinSpiDemo_init(void);
IFX_EXTERN void AsclinSpiDemo_run(void);

#endif

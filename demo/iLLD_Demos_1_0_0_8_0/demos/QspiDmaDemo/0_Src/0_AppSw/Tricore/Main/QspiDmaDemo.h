/**
 * \file QspiDmaDemo.h
 * \brief Qspi Master & Slave Demo (using dma)
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
 * \defgroup IfxLld_Demo_QspiDmaDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_QspiDmaDemo_SrcDoc
 * \defgroup IfxLld_Demo_QspiDmaDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_QspiDmaDemo_SrcDoc_Main
 */

#ifndef QSPIDMADEMO_H
#define QSPIDMADEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include "Configuration.h"
#include <Qspi/SpiMaster/IfxQspi_SpiMaster.h>
#include <Qspi/SpiSlave/IfxQspi_SpiSlave.h>

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define SPI_BUFFER_SIZE 10   /**< \brief Tx/Rx Buffer size */

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct
{
#if defined(__TASKING__)
#pragma align 64
    uint8 spi0TxBuffer[SPI_BUFFER_SIZE];                               /**< \brief Qspi0 Transmit buffer */
    uint8 spi0RxBuffer[SPI_BUFFER_SIZE];                               /**< \brief Qspi0 receive buffer */
    uint8 spi2TxBuffer[SPI_BUFFER_SIZE];                               /**< \brief Qspi2 Transmit buffer */
    uint8 spi2RxBuffer[SPI_BUFFER_SIZE];                               /**< \brief Qspi2 receive buffer */
#pragma align restore
#elif defined(__GNUC__)
    __attribute__ ((aligned(64))) uint8 spi0TxBuffer[SPI_BUFFER_SIZE]; /**< \brief Qspi0 Transmit buffer */
    __attribute__ ((aligned(64))) uint8 spi0RxBuffer[SPI_BUFFER_SIZE]; /**< \brief Qspi0 receive buffer */
    __attribute__ ((aligned(64))) uint8 spi2TxBuffer[SPI_BUFFER_SIZE]; /**< \brief Qspi2 Transmit buffer */
    __attribute__ ((aligned(64))) uint8 spi2RxBuffer[SPI_BUFFER_SIZE]; /**< \brief Qspi2 receive buffer */
#else
#error "Unsupported Compiler."
#endif
} AppQspiBuffer;

/** \brief QspiCpu global data */
typedef struct
{
    AppQspiBuffer qspiBuffer;                       /**< \brief Qspi buffer */
    struct
    {
        IfxQspi_SpiMaster         spiMaster;        /**< \brief Spi Master handle */
        IfxQspi_SpiMaster_Channel spiMasterChannel; /**< \brief Spi Master Channel handle */
        IfxQspi_SpiSlave          spiSlave;         /**< \brief Spi Slave handle */
    }drivers;
} App_QspiDma;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_QspiDma g_QspiDma;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void IfxQspiDmaDemo_init(void);
IFX_EXTERN void IfxQspiDmaDemo_run(void);

#endif

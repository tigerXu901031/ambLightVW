/**
 * \file QspiDmaDemo.c
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include "Cpu0_Main.h"
#include "ConfigurationIsr.h"
#include "Ifx_Assert.h"
#include "QspiDmaDemo.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define IFX_QSPI0_TX_CHANNELID (IfxDma_ChannelId_1) /**< \brief Dma channel used for Master Qspi0 Transmit */
#define IFX_QSPI0_RX_CHANNELID (IfxDma_ChannelId_2) /**< \brief Dma channel used for Master Qspi0 receive */
#define IFX_QSPI2_TX_CHANNELID (IfxDma_ChannelId_3) /**< \brief Dma channel used for Slave Qspi2 Transmit */
#define IFX_QSPI2_RX_CHANNELID (IfxDma_ChannelId_4) /**< \brief Dma channel used for Slave Qspi2 receive */

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
App_QspiDma g_QspiDma; /**< \brief Qspi global data */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_Demo_QspiCpu_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Qspi Master (QSPI0) & Slave (QSPI2) drivers
 * \{ */
IFX_INTERRUPT(ISR_qspi0_Er, 0, ISR_PRIORITY_QSPI0_ER);
IFX_INTERRUPT(ISR_qspi2_Er, 0, ISR_PRIORITY_QSPI2_ER);
IFX_INTERRUPT(ISR_dma_ch1, 0, ISR_PRIORITY_DMA_CH1);
IFX_INTERRUPT(ISR_dma_ch2, 0, ISR_PRIORITY_DMA_CH2);
IFX_INTERRUPT(ISR_dma_ch3, 0, ISR_PRIORITY_DMA_CH3);
IFX_INTERRUPT(ISR_dma_ch4, 0, ISR_PRIORITY_DMA_CH4);

/** \} */

/** \} */

/** \brief Handle qspi0_Er interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_QSPI0_ER
 * \isrPriority \ref ISR_PRIORITY_QSPI0_ER
 *
 */
void ISR_qspi0_Er(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrError(&g_QspiDma.drivers.spiMaster);
}


/** \brief Handle qspi2_Er interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_QSPI2_ER
 * \isrPriority \ref ISR_PRIORITY_QSPI2_ER
 *
 */
void ISR_qspi2_Er(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiSlave_isrError(&g_QspiDma.drivers.spiSlave);
}


/** \brief Handle dma_ch1 interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_DMA_CH1
 * \isrPriority \ref ISR_PRIORITY_DMA_CH1
 *
 */
void ISR_dma_ch1(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrDmaTransmit(&g_QspiDma.drivers.spiMaster);
}


/** \brief Handle dma_ch2 interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_DMA_CH2
 * \isrPriority \ref ISR_PRIORITY_DMA_CH2
 *
 */
void ISR_dma_ch2(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrDmaReceive(&g_QspiDma.drivers.spiMaster);
}


/** \brief Handle dma_ch3 interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_DMA_CH3
 * \isrPriority \ref ISR_PRIORITY_DMA_CH3
 *
 */
void ISR_dma_ch3(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiSlave_isrDmaTransmit(&g_QspiDma.drivers.spiSlave);
}


/** \brief Handle dma_ch4 interrupt.
 *
 * \isrProvider \ref ISR_PROVIDER_DMA_CH4
 * \isrPriority \ref ISR_PRIORITY_DMA_CH4
 *
 */
void ISR_dma_ch4(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiSlave_isrDmaReceive(&g_QspiDma.drivers.spiSlave);
}


/** \brief Qspi Master initilisation
 *
 * This function initialises Qspi0 in master mode.
 */
static void IfxQspi_Dma_Masterinit(void)
{
    uint32                          i;
    IfxQspi_SpiMaster_Config        spiMasterConfig;
    IfxQspi_SpiMaster_ChannelConfig spiMasterChannelConfig;
    Ifx_QSPI                       *qspi0SFR;

    {
        /* create module config */
        IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, &MODULE_QSPI0);

        /* set the maximum baudrate */
        spiMasterConfig.base.maximumBaudrate = 10000000;

        /* ISR priorities and interrupt target */
        spiMasterConfig.base.txPriority    = ISR_PRIORITY_DMA_CH1;
        spiMasterConfig.base.rxPriority    = ISR_PRIORITY_DMA_CH2;
        spiMasterConfig.base.erPriority    = ISR_PRIORITY_QSPI0_ER;
        spiMasterConfig.base.isrProvider   = (IfxSrc_Tos)IfxCpu_getCoreIndex();
        spiMasterConfig.dma.txDmaChannelId = IFX_QSPI0_TX_CHANNELID;
        spiMasterConfig.dma.rxDmaChannelId = IFX_QSPI0_RX_CHANNELID;
        spiMasterConfig.dma.useDma         = 1;

        /* pin configuration */
        const IfxQspi_SpiMaster_Pins pins = {&IfxQspi0_SCLK_P20_11_OUT,                               /* SCLK */
                                             IfxPort_OutputMode_pushPull,
                                             &IfxQspi0_MTSR_P20_14_OUT,  IfxPort_OutputMode_pushPull, /* MTSR */
                                             &IfxQspi0_MRSTA_P20_12_IN,  IfxPort_InputMode_pullDown,  /* MRST */
                                             IfxPort_PadDriver_cmosAutomotiveSpeed3                   /* pad driver mode */
        };
        spiMasterConfig.pins = &pins;

        /* initialize module */
        IfxQspi_SpiMaster_initModule(&g_QspiDma.drivers.spiMaster, &spiMasterConfig);

        {
            qspi0SFR = spiMasterConfig.qspi;
            volatile Ifx_SRC_SRCR *src = IfxQspi_getErrorSrc(qspi0SFR);
            IfxSrc_init(src, (IfxSrc_Tos)IfxCpu_getCoreIndex(), ISR_PRIORITY_QSPI0_ER);
            IfxSrc_enable(src);
        }
    }

    {
        /* create channel config */
        IfxQspi_SpiMaster_initChannelConfig(&spiMasterChannelConfig,
            &g_QspiDma.drivers.spiMaster);

        /* set the baudrate for this channel */
        spiMasterChannelConfig.base.baudrate = 5000000;

        const IfxQspi_SpiMaster_Output slsOutput = {&IfxQspi0_SLSO7_P33_5_OUT,
                                                    IfxPort_OutputMode_pushPull,
                                                    IfxPort_PadDriver_cmosAutomotiveSpeed1};

        spiMasterChannelConfig.sls.output.pin    = slsOutput.pin;
        spiMasterChannelConfig.sls.output.mode   = slsOutput.mode;
        spiMasterChannelConfig.sls.output.driver = slsOutput.driver;

        /* initialize channel */
        IfxQspi_SpiMaster_initChannel(&g_QspiDma.drivers.spiMasterChannel,
            &spiMasterChannelConfig);
    }

    /* init tx buffer area */
    for (i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        g_QspiDma.qspiBuffer.spi0TxBuffer[i] = (uint8)(i + 1);
        g_QspiDma.qspiBuffer.spi2TxBuffer[i] = (uint8)(i + 100);

        g_QspiDma.qspiBuffer.spi0RxBuffer[i] = (uint8)(0);
        g_QspiDma.qspiBuffer.spi2RxBuffer[i] = (uint8)(0);
    }
}


/** \brief Qspi Slave initilisation
 *
 * This function initialises Qspi2 in Slave mode.
 */
static void IfxQspi_Dma_Slaveinit(void)
{
    IfxQspi_SpiSlave_Config spiSlaveConfig;
    Ifx_QSPI               *qspi2SFR;

    {
        /* create module config */
        IfxQspi_SpiSlave_initModuleConfig(&spiSlaveConfig, &MODULE_QSPI2);

        /* set the maximum baudrate */
        spiSlaveConfig.base.maximumBaudrate = 10000000;

        /* ISR priorities and interrupt target */
        spiSlaveConfig.base.txPriority    = ISR_PRIORITY_DMA_CH3;
        spiSlaveConfig.base.rxPriority    = ISR_PRIORITY_DMA_CH4;
        spiSlaveConfig.base.erPriority    = ISR_PRIORITY_QSPI2_ER;
        spiSlaveConfig.base.isrProvider   = (IfxSrc_Tos)IfxCpu_getCoreIndex();
        spiSlaveConfig.dma.txDmaChannelId = IFX_QSPI2_TX_CHANNELID;
        spiSlaveConfig.dma.rxDmaChannelId = IFX_QSPI2_RX_CHANNELID;
        spiSlaveConfig.dma.useDma         = 1;

        /* pin configuration */
        const IfxQspi_SpiSlave_Pins slavePins = {&IfxQspi2_SCLKB_P15_8_IN,                               /* SCLK Pin */
                                                 IfxPort_InputMode_pullDown,
                                                 &IfxQspi2_MTSRA_P15_5_IN,  IfxPort_InputMode_pullDown,  /* MTSR Pin */
                                                 &IfxQspi2_MRST_P15_7_OUT,  IfxPort_OutputMode_pushPull, /* MRST Pin */
                                                 &IfxQspi2_SLSIB_P15_1_IN,  IfxPort_InputMode_pullDown,  /* SLSI Pin */
                                                 IfxPort_PadDriver_cmosAutomotiveSpeed3                  /* pad driver mode */
        };
        spiSlaveConfig.pins = &slavePins;

        /* initialize module */
        IfxQspi_SpiSlave_initModule(&g_QspiDma.drivers.spiSlave, &spiSlaveConfig);

        {
            qspi2SFR = spiSlaveConfig.qspi;

            volatile Ifx_SRC_SRCR *src = IfxQspi_getErrorSrc(qspi2SFR);
            IfxSrc_init(src, (IfxSrc_Tos)IfxCpu_getCoreIndex(), ISR_PRIORITY_QSPI2_ER);
            IfxSrc_enable(src);
        }
    }
}


/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxQspiDmaDemo_init(void)
{
    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    IfxQspi_Dma_Slaveinit();
    IfxQspi_Dma_Masterinit();

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxQspiDmaDemo_run(void)
{
    uint32 size = SPI_BUFFER_SIZE;
    printf("Transfering %d bytes\n", size);

    {
        {
            /* Slave transfer */
            printf("wait until slave is free\n");

            while (IfxQspi_SpiSlave_getStatus(&g_QspiDma.drivers.spiSlave) == SpiIf_Status_busy)
            {}

            IfxQspi_SpiSlave_exchange(&g_QspiDma.drivers.spiSlave, &g_QspiDma.qspiBuffer.spi2TxBuffer[0],
                &g_QspiDma.qspiBuffer.spi2RxBuffer[0], SPI_BUFFER_SIZE);

            /* Master transfer */
            printf("wait until master is free\n");

            while (IfxQspi_SpiMaster_getStatus(&g_QspiDma.drivers.spiMasterChannel)
                   == SpiIf_Status_busy)
            {}

            IfxQspi_SpiMaster_exchange(&g_QspiDma.drivers.spiMasterChannel, &g_QspiDma.qspiBuffer.spi0TxBuffer[0],
                &g_QspiDma.qspiBuffer.spi0RxBuffer[0], SPI_BUFFER_SIZE);
        }
    }

    printf("wait until slave received all data\n");

    /* wait until slave received all data */
    while (IfxQspi_SpiSlave_getStatus(&g_QspiDma.drivers.spiSlave) == SpiIf_Status_busy)
    {}

    printf("Check received data\n");
    {
        uint32 errors       = 0;
        uint8 *spi0Received = (uint8 *)g_QspiDma.qspiBuffer.spi0RxBuffer;
        uint8 *spi0Expected = (uint8 *)g_QspiDma.qspiBuffer.spi2TxBuffer;
        uint8 *spi2Received = (uint8 *)g_QspiDma.qspiBuffer.spi2RxBuffer;
        uint8 *spi2Expected = (uint8 *)g_QspiDma.qspiBuffer.spi0TxBuffer;

        {
            uint32 i;

            for (i = 0; i < SPI_BUFFER_SIZE; i++)
            {
                if (*spi2Received++ != *spi2Expected++)
                {
                    ++errors;
                }

                if (*spi0Received++ != *spi0Expected++)
                {
                    ++errors;
                }
            }
        }

        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, errors == 0);

        if (errors)
        {
            printf("ERROR: received data doesn't match with expected data (%d mismatches)\n", errors);
        }
        else
        {
            printf("OK: received data matches with expected data\n");
        }
    }
}

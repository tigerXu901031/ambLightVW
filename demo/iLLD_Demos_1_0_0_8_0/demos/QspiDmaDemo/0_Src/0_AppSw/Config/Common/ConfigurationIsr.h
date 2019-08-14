/**
 * \file ConfigurationIsr.h
 * \brief Interrupts configuration.
 *
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
 * \defgroup IfxLld_Demo_QspiDmaDemo_SrcDoc_InterruptConfig Interrupt configuration
 * \ingroup IfxLld_Demo_QspiDmaDemo_SrcDoc
 */

#ifndef CONFIGURATIONISR_H
#define CONFIGURATIONISR_H
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Build the ISR configuration object
 * \param no interrupt priority
 * \param cpu assign CPU number
 */
#define ISR_ASSIGN(no, cpu)  ((no << 8) + cpu)

/** \brief extract the priority out of the ISR object */
#define ISR_PRIORITY(no_cpu) (no_cpu >> 8)

/** \brief extract the service provider  out of the ISR object */
#define ISR_PROVIDER(no_cpu) (no_cpu % 8)
/**
 * \addtogroup IfxLld_Demo_QspiDmaDemo_SrcDoc_InterruptConfig
 * \{ */

/**
 * \name Interrupt priority configuration.
 * The interrupt priority range is [1,255]
 * \{
 */
#define ISR_PRIORITY_PRINTF_ASC0_TX 5  /**< \brief Define the ASC0 transmit interrupt priority used by printf.c */
#define ISR_PRIORITY_PRINTF_ASC0_EX 6  /**< \brief Define the ASC0 error interrupt priority used by printf.c */

#define ISR_PRIORITY_QSPI0_TX       1  /**< \brief Define the Qspi0 transmit interrupt priority.  */
#define ISR_PRIORITY_QSPI0_RX       2  /**< \brief Define the Qspi0 receive interrupt priority.  */
#define ISR_PRIORITY_QSPI0_ER       10 /**< \brief Define the Qspi0 error interrupt priority.  */

#define ISR_PRIORITY_QSPI2_TX       3  /**< \brief Define the Qspi0 transmit interrupt priority.  */
#define ISR_PRIORITY_QSPI2_RX       4  /**< \brief Define the Qspi0 receive interrupt priority.  */
#define ISR_PRIORITY_QSPI2_ER       11 /**< \brief Define the Qspi0 error interrupt priority.  */

#define ISR_PRIORITY_DMA_CH1        50 /**< \brief Define the Dma channel1 interrupt priority.  */
#define ISR_PRIORITY_DMA_CH2        51 /**< \brief Define the Dma channel2 interrupt priority.  */
#define ISR_PRIORITY_DMA_CH3        52 /**< \brief Define the Dma channel3 interrupt priority.  */
#define ISR_PRIORITY_DMA_CH4        53 /**< \brief Define the Dma channel4 interrupt priority.  */

/** \} */

/**
 * \name Interrupt service provider configuration.
 * \{ */
#define ISR_PROVIDER_PRINTF_ASC0_TX IfxSrc_Tos_cpu0     /**< \brief Define the ASC0 transmit interrupt provider used by printf.c   */
#define ISR_PROVIDER_PRINTF_ASC0_EX IfxSrc_Tos_cpu0     /**< \brief Define the ASC0 error interrupt provider used by printf.c */

#define ISR_PROVIDER_QSPI0_TX       IfxSrc_Tos_dma      /**< \brief Define the Qspi0 transmit interrupt provider.  */
#define ISR_PROVIDER_QSPI0_RX       IfxSrc_Tos_dma      /**< \brief Define the Qspi0 receive interrupt provider.  */
#define ISR_PROVIDER_QSPI0_ER       IfxSrc_Tos_cpu0     /**< \brief Define the Qspi0 error interrupt provider.  */

#define ISR_PROVIDER_QSPI2_TX       IfxSrc_Tos_dma      /**< \brief Define the Qspi2 transmit interrupt provider.  */
#define ISR_PROVIDER_QSPI2_RX       IfxSrc_Tos_dma      /**< \brief Define the Qspi2 receive interrupt provider.  */
#define ISR_PROVIDER_QSPI2_ER       IfxSrc_Tos_cpu0     /**< \brief Define the Qspi2 error interrupt provider.  */

#define ISR_PROVIDER_DMA_CH1        IfxSrc_Tos_cpu0     /**< \brief Define the Dma Channel1 interrupt provider.  */
#define ISR_PROVIDER_DMA_CH2        IfxSrc_Tos_cpu0     /**< \brief Define the Dma Channel2 interrupt provider.  */
#define ISR_PROVIDER_DMA_CH3        IfxSrc_Tos_cpu0     /**< \brief Define the Dma Channel3 interrupt provider.  */
#define ISR_PROVIDER_DMA_CH4        IfxSrc_Tos_cpu0     /**< \brief Define the Dma Channel4 interrupt provider.  */
/** \} */

/**
 * \name Interrupt configuration.
 * \{ */
#define INTERRUPT_PRINTF_ASC0_TX    ISR_ASSIGN(ISR_PRIORITY_PRINTF_ASC0_TX, ISR_PROVIDER_PRINTF_ASC0_TX) /**< \brief Define the ASC0 transmit interrupt priority used by printf.c */
#define INTERRUPT_PRINTF_ASC0_EX    ISR_ASSIGN(ISR_PRIORITY_PRINTF_ASC0_EX, ISR_PROVIDER_PRINTF_ASC0_EX) /**< \brief Define the ASC0 error interrupt priority used by printf.c */

#define INTERRUPT_QSPI0_TX          ISR_ASSIGN(ISR_PRIORITY_QSPI0_TX, ISR_PROVIDER_QSPI0_TX)             /**< \brief Define the QSPI0 transmit interrupt priority.  */
#define INTERRUPT_QSPI0_RX          ISR_ASSIGN(ISR_PRIORITY_QSPI0_RX, ISR_PROVIDER_QSPI0_RX)             /**< \brief Define the QSPI0 receive interrupt priority.  */
#define INTERRUPT_QSPI0_ER          ISR_ASSIGN(ISR_PRIORITY_QSPI0_ER, ISR_PROVIDER_QSPI0_ER)             /**< \brief Define the QSPI0 error interrupt priority.  */

#define INTERRUPT_QSPI2_TX          ISR_ASSIGN(ISR_PRIORITY_QSPI2_TX, ISR_PROVIDER_QSPI2_TX)             /**< \brief Define the QSPI2 transmit interrupt priority.  */
#define INTERRUPT_QSPI2_RX          ISR_ASSIGN(ISR_PRIORITY_QSPI2_RX, ISR_PROVIDER_QSPI2_RX)             /**< \brief Define the QSPI2 receive interrupt priority.  */
#define INTERRUPT_QSPI2_ER          ISR_ASSIGN(ISR_PRIORITY_QSPI2_ER, ISR_PROVIDER_QSPI2_ER)             /**< \brief Define the QSPI2 error interrupt priority.  */

#define INTERRUPT_DMA_CH1           ISR_ASSIGN(ISR_PRIORITY_DMA_CH1, ISR_PROVIDER_DMA_CH1)               /**< \brief Define the Dma channel1 interrupt priority.  */
#define INTERRUPT_DMA_CH2           ISR_ASSIGN(ISR_PRIORITY_DMA_CH2, ISR_PROVIDER_DMA_CH2)               /**< \brief Define the Dma channel2 interrupt priority.  */
#define INTERRUPT_DMA_CH3           ISR_ASSIGN(ISR_PRIORITY_DMA_CH3, ISR_PROVIDER_DMA_CH3)               /**< \brief Define the Dma channel3 interrupt priority.  */
#define INTERRUPT_DMA_CH4           ISR_ASSIGN(ISR_PRIORITY_DMA_CH4, ISR_PROVIDER_DMA_CH4)               /**< \brief Define the Dma channel4 interrupt priority.  */
/** \} */

/** \} */
//------------------------------------------------------------------------------

#endif
/**
 * \file HsslStreamingDemo.h
 * \brief Demo HsslStreamingDemo
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
 * \defgroup IfxLld_Demo_HsslStreaming_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_HsslStreaming_SrcDoc
 * \defgroup IfxLld_Demo_HsslStreaming_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_HsslStreaming_SrcDoc_Main
 */

#ifndef HSSLSTREAMINGDEMO_H
#define HSSLSTREAMINGDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <Ifx_Types.h>
#include "Configuration.h"

#include <Hssl/Hssl/IfxHssl_Hssl.h>
#include "Cpu/Std/IfxCpu.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Asc information */
typedef struct
{
    struct
    {
        IfxHssl_Hssl         hssl;                          /**< \brief HSSL interface */
		IfxHssl_Hsct         hsct;                      /**< \brief HSCT interface */
        IfxHssl_Hssl_Config  hsslConfig;
		IfxHssl_Hsct_Config  hsctConfig;
        IfxHssl_Hssl_Channel hsslChannel[4];		
    }drivers;
} App_HsslStreaming;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

IFX_EXTERN App_HsslStreaming g_HsslStreaming;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

IFX_EXTERN void HsslStreamingDemo_init(void);
IFX_EXTERN void HsslStreamingDemo_run(void);

#endif

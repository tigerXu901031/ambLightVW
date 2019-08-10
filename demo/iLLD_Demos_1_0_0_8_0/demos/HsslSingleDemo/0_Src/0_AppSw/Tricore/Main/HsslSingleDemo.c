/**
 * \file HsslSingleDemo.c
 * \brief Demo HsslSingleDemo
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
#include "HsslSingleDemo.h"

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

App_HsslSingle g_HsslSingle; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_HsslSingle_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void HsslSingleDemo_init(void)
{
    /* create Hsct module config */
    IfxHssl_Hssl_initHsctModuleConfig(&g_HsslSingle.drivers.hsctConfig, &MODULE_HSCT);

    /* choose master or slave */
    g_HsslSingle.drivers.hsctConfig.interfaceMode = IfxHssl_InterfaceMode_master;
    g_HsslSingle.drivers.hsctConfig.highSpeedMode = TRUE; /* interface at high speed */

    /* create Hssl module config */
    IfxHssl_Hssl_initHsslModuleConfig(&g_HsslSingle.drivers.hsslConfig, &MODULE_HSSL);
	
	/* initialize Hsct module */
    IfxHssl_Hssl_initHsctModule(&g_HsslSingle.drivers.hsct, &g_HsslSingle.drivers.hsctConfig);
	
	/* initialize Hssl module */
    IfxHssl_Hssl_initHsslModule(&g_HsslSingle.drivers.hssl, &g_HsslSingle.drivers.hsslConfig);

    /* create HSSL channel config */
    IfxHssl_Hssl_ChannelConfig hsslChannelConfig;
    IfxHssl_Hssl_initChannelConfig(&hsslChannelConfig, &g_HsslSingle.drivers.hssl, &g_HsslSingle.drivers.hsct);

    uint32                     i;

    for (i = 0; i < 4; ++i)
    {
        hsslChannelConfig.channelId = (IfxHssl_ChannelId)i;
        IfxHssl_Hssl_initChannel(&g_HsslSingle.drivers.hsslChannel[i], &hsslChannelConfig);
    }

    printf("Hssl is initialised\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void HsslSingleDemo_run(void)
{
    if (g_HsslSingle.drivers.hsctConfig.interfaceMode == IfxHssl_InterfaceMode_slave)
    {
        while (1)
        {}
    }

    else if (g_HsslSingle.drivers.hsctConfig.interfaceMode == IfxHssl_InterfaceMode_master)
    {
        /* write some data to remote location: */
        IfxHssl_Hssl_write(&g_HsslSingle.drivers.hsslChannel[0], 0x70000000, 0x12345678, IfxHssl_DataLength_32bit);

        while (IfxHssl_Hssl_waitAcknowledge(&g_HsslSingle.drivers.hsslChannel[0]) != IfxHssl_Hssl_Status_ok)
        {
            if (IfxHssl_Hssl_waitAcknowledge(&g_HsslSingle.drivers.hsslChannel[0]) == IfxHssl_Hssl_Status_error)
            {
                IfxHssl_Hssl_checkErrors(&g_HsslSingle.drivers.hssl);
                break;
            }
        }

        IfxHssl_Hssl_write(&g_HsslSingle.drivers.hsslChannel[0], 0x70000004, 0xaabbccdd, IfxHssl_DataLength_32bit);

        while (IfxHssl_Hssl_waitAcknowledge(&g_HsslSingle.drivers.hsslChannel[0]) == IfxHssl_Hssl_Status_busy)
        {}

        /* read some data from remote location: */
        IfxHssl_Hssl_read(&g_HsslSingle.drivers.hsslChannel[0], 0x70000000, IfxHssl_DataLength_32bit);

        while (IfxHssl_Hssl_waitAcknowledge(&g_HsslSingle.drivers.hsslChannel[0]) != IfxHssl_Hssl_Status_ok)
        {
            if (IfxHssl_Hssl_waitAcknowledge(&g_HsslSingle.drivers.hsslChannel[0]) == IfxHssl_Hssl_Status_error)
            {
                IfxHssl_Hssl_checkErrors(&g_HsslSingle.drivers.hssl);
                break;
            }
        }

        uint32 dataL = IfxHssl_Hssl_getReadData(&g_HsslSingle.drivers.hsslChannel[0]);

        IfxHssl_Hssl_read(&g_HsslSingle.drivers.hsslChannel[0], 0x70000004, IfxHssl_DataLength_32bit);

        while (IfxHssl_Hssl_waitAcknowledge(&g_HsslSingle.drivers.hsslChannel[0]) == IfxHssl_Hssl_Status_busy)
        {}

        uint32 dataU = IfxHssl_Hssl_getReadData(&g_HsslSingle.drivers.hsslChannel[0]);

        /* Check received data */
        uint32 errors = 0;

        if (dataL != 0x12345678)
        {
            ++errors;
        }

        if (dataU != 0xaabbccdd)
        {
            ++errors;
        }

        {
            unsigned int *target = (unsigned int *)0x70000010;
            target[0] = dataL;
            target[1] = dataU;
        }

        if (errors)
        {
            printf("ERROR: Found (%lu errors)\n", errors);
        }
        else
        {
            printf("OK: Checks passed\n");
        }
    }

    printf("Hssl Single data transactions are finished\n");
}

/**
 * \file HsslMultipleDemo.c
 * \brief Demo HsslMultipleDemo
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
#include "HsslMultipleDemo.h"

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

App_HsslMultiple g_HsslMultiple; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Demo_HsslMultiple_SrcDoc_Main_Interrupt
 * \{ */

/** \} */

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void HsslMultipleDemo_init(void)
{
    /* create Hsct module config */
    IfxHssl_Hssl_initHsctModuleConfig(&g_HsslMultiple.drivers.hsctConfig, &MODULE_HSCT);

    /* choose master or slave */
    g_HsslMultiple.drivers.hsctConfig.interfaceMode = IfxHssl_InterfaceMode_master;
    g_HsslMultiple.drivers.hsctConfig.highSpeedMode = TRUE; /* interface at high speed */

    /* create Hssl module config */
    IfxHssl_Hssl_initHsslModuleConfig(&g_HsslMultiple.drivers.hsslConfig, &MODULE_HSSL);
	
	/* initialize Hsct module */
    IfxHssl_Hssl_initHsctModule(&g_HsslMultiple.drivers.hsct, &g_HsslMultiple.drivers.hsctConfig);
	
	/* initialize Hssl module */
    IfxHssl_Hssl_initHsslModule(&g_HsslMultiple.drivers.hssl, &g_HsslMultiple.drivers.hsslConfig);

    /* create HSSL channel config */
    IfxHssl_Hssl_ChannelConfig hsslChannelConfig;
    IfxHssl_Hssl_initChannelConfig(&hsslChannelConfig, &g_HsslMultiple.drivers.hssl, &g_HsslMultiple.drivers.hsct);

    uint32                     i;

    for (i = 0; i < 4; ++i)
    {
        hsslChannelConfig.channelId = (IfxHssl_ChannelId)i;
        IfxHssl_Hssl_initChannel(&g_HsslMultiple.drivers.hsslChannel[i], &hsslChannelConfig);
    }

    printf("Hssl is initialised\n");
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void HsslMultipleDemo_run(void)
{
    if (g_HsslMultiple.drivers.hsctConfig.interfaceMode == IfxHssl_InterfaceMode_slave)
    {
        while (1)
        {}
    }
    else if (g_HsslMultiple.drivers.hsctConfig.interfaceMode == IfxHssl_InterfaceMode_master)

    {
        uint32 i       = 0;
        uint32 data    = 0x12340000;
        uint32 address = 0x70000000;

        for (i = 0; i <= 499; i++)
        {
            data = ~data;
            /* write some data to remote location: */
            IfxHssl_Hssl_write(&g_HsslMultiple.drivers.hsslChannel[0], (address + 4 * i), data, IfxHssl_DataLength_32bit);

            while (IfxHssl_Hssl_waitAcknowledge(&g_HsslMultiple.drivers.hsslChannel[0]) != IfxHssl_Hssl_Status_ok)
            {
                if (IfxHssl_Hssl_waitAcknowledge(&g_HsslMultiple.drivers.hsslChannel[0]) == IfxHssl_Hssl_Status_error)
                {
                    IfxHssl_Hssl_checkErrors(&g_HsslMultiple.drivers.hssl);
                    break;
                }
            }
        }

        address = 0x70000000;

        for (i = 0; i <= 499; i++)
        {
            /* read some data from the same location: */
            IfxHssl_Hssl_read(&g_HsslMultiple.drivers.hsslChannel[0], (address + 4 * i), IfxHssl_DataLength_32bit);

            while (IfxHssl_Hssl_waitAcknowledge(&g_HsslMultiple.drivers.hsslChannel[0]) != IfxHssl_Hssl_Status_ok)
            {
                if (IfxHssl_Hssl_waitAcknowledge(&g_HsslMultiple.drivers.hsslChannel[0]) == IfxHssl_Hssl_Status_error)
                {
                    IfxHssl_Hssl_checkErrors(&g_HsslMultiple.drivers.hssl);
                    break;
                }
            }

            g_HsslMultiple.dataRead[i] = IfxHssl_Hssl_getReadData(&g_HsslMultiple.drivers.hsslChannel[0]);
        }
    }

    printf("Hssl Multiple data transactions are finished\n");
}

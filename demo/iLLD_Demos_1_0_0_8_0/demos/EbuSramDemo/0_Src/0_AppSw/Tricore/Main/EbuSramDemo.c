/**
 * \file EbuSramDemo.c
 * \brief Ebu Sram Demo.
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
#include <Ebu/Sram/IfxEbu_Sram.h>
#include "IfxPort.h"
#include "Ifx_Assert.h"
#include "EbuSramDemo.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define EBUSRAM_CS1_START_ADDRESS (0xa4000000)  /**< \brief ChipSelect 1 Start address */
#define EBUSRAM_CS0_START_ADDRESS (0xa8000000)  /**< \brief ChipSelect 0 Start address */

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void IfxEbuSramDemo_init(void)
{
    IfxEbu_Sram        sram;
    IfxEbu_Sram_Config cfg;

    /* enable byte control pins */
    IfxEbu_setByteControlEnable(&MODULE_EBU0, IfxEbu_ByteControlEnable_byteControl32Bit);

    /* get default SRAM configuration */
    IfxEbu_Sram_initMemoryConfig(&cfg, &MODULE_EBU0);

    /* Configure CS#0 */
    cfg.chipSelect                     = IfxEbu_ChipSelect_0;
    cfg.memoryRegionConfig.baseAddress = EBUSRAM_CS0_START_ADDRESS; /* specify noncached segment A, driver will also enable the cached segment 8 */
    IfxEbu_Sram_initMemory(&sram, &cfg);

    /* Configure CS#1 */
    cfg.chipSelect                     = IfxEbu_ChipSelect_1;
    cfg.memoryRegionConfig.baseAddress = EBUSRAM_CS1_START_ADDRESS; /* specify noncached segment A, driver will also enable the cached segment 8 */
    cfg.device                         = IfxEbu_Sram_Device_deMuxedAsynchronousType;
    /* configuring the device type for read */
    cfg.readConfig.deviceInterface     = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    /* configuring the device type for write */
    cfg.writeConfig.deviceInterface    = IfxEbu_ExternalDeviceInterface_32bitMultiplexed;
    /* Configure the wait states */
    cfg.writeAccessParameter.waitState = 0x12;
    IfxEbu_Sram_initMemory(&sram, &cfg);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void IfxEbuSramDemo_run(void)
{
    uint32           i;
    uint32           errors;
    volatile uint32 *sramAddress;

    sramAddress = (volatile uint32 *)(EBUSRAM_CS1_START_ADDRESS);
    errors      = 0;

    for (i = 0; i < 64; i++)
    {
        sramAddress[i] = 0xAABBCC00 + i;
    }

    for (i = 0; i < 64; i++)
    {
        uint32 sramData     = sramAddress[i];
        uint32 expectedData = 0xAABBCC00 + i;

        if (sramData != expectedData)
        {
            printf("Error @ sramAddress: 0x%08x = value: 0x%08x , Expected value: 0x%08x\n", sramAddress + i, sramData, expectedData);
            errors++;
        }
    }

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, errors == 0);

    if (errors)
    {
        printf("ERROR: Sram written data doesn't match with read data (%d mismatches)\n", errors);
    }
    else
    {
        printf("OK: Sram written data matches with read data\n");
    }
}

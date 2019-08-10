/**
 * \file MscBasicDemo.c
 * \brief Demo MscBasicDemo
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
#include "MscBasicDemo.h"
#include <Cpu/Std/IfxCpu.h>
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
App_MscBasic               g_MscBasic; /**< \brief Demo information */
/* IO Pins */
static const IfxMsc_Msc_Io IfxMsc_PinMap[IFXMSC_NUM_MODULES] = {
    {
        {&IfxMsc0_FCLP_P13_1_OUT, IfxPort_OutputMode_pushPull},
        {&IfxMsc0_FCLN_P13_0_OUT, IfxPort_OutputMode_pushPull},
        {&IfxMsc0_SOP_P13_3_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc0_SON_P13_2_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc0_EN0_P10_3_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc0_EN1_P11_2_OUT,  IfxPort_OutputMode_pushPull},
        {NULL_PTR},
	{NULL_PTR},
        {&IfxMsc0_SDI0_P11_10_IN, IfxPort_InputMode_pullUp   },
        {&IfxMsc0_INJ0_P00_0_IN,  IfxPort_InputMode_pullUp   },
        {&IfxMsc0_INJ1_P10_5_IN,  IfxPort_InputMode_pullUp   },
        IfxPort_PadDriver_cmosAutomotiveSpeed3
    },

#if IFXMSC_NUM_MODULES >= 2
    {
        {&IfxMsc1_FCLP_P22_1_OUT, IfxPort_OutputMode_pushPull},
        {&IfxMsc1_FCLN_P22_0_OUT, IfxPort_OutputMode_pushPull},
        {&IfxMsc1_SOP_P22_3_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc1_SON_P22_2_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc1_EN0_P23_4_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc1_EN1_P23_5_OUT,  IfxPort_OutputMode_pushPull},
        {NULL_PTR},
	{NULL_PTR},
        {&IfxMsc1_SDI0_P23_1_IN,  IfxPort_InputMode_pullUp   },
        {&IfxMsc1_INJ0_P23_3_IN,  IfxPort_InputMode_pullUp   },
        {&IfxMsc1_INJ1_P33_13_IN, IfxPort_InputMode_pullUp   },
        IfxPort_PadDriver_cmosAutomotiveSpeed3
    },
#endif

#if IFXMSC_NUM_MODULES >= 3
    {
        {&IfxMsc2_FCLP_P13_5_OUT, IfxPort_OutputMode_pushPull},
        {&IfxMsc2_FCLN_P13_4_OUT, IfxPort_OutputMode_pushPull},
        {&IfxMsc2_SOP_P13_7_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc2_SON_P13_6_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc2_EN0_P13_4_OUT,  IfxPort_OutputMode_pushPull},
        {&IfxMsc2_EN1_P14_13_OUT, IfxPort_OutputMode_pushPull},
        {NULL_PTR},
	{NULL_PTR},
        {&IfxMsc2_SDI0_P14_12_IN, IfxPort_InputMode_pullUp   },
        {&IfxMsc2_INJ0_P13_13_IN, IfxPort_InputMode_pullUp   },
        {&IfxMsc2_INJ1_P14_15_IN, IfxPort_InputMode_pullUp   },
        IfxPort_PadDriver_cmosAutomotiveSpeed3
    },
#endif
};
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
void MscBasicDemo_init(void)
{
    uint32            i;

    /* create configuration (same is used for all MSCs) */
    IfxMsc_Msc_Config mscConfig;
    IfxMsc_Msc_initModuleConfig(&mscConfig, &MODULE_MSC0);

    /* increase baudrate for faster simulation: */
    mscConfig.clockConfig.baudrate    = 25000000;
    mscConfig.clockConfig.dividerMode = IfxMsc_DividerMode_fractional;

    /* FCL only activated on transfers */
    mscConfig.outputControlConfig.fclClockControl = IfxMsc_FclClockControlEnabled_activePhaseOnly;

    /* in this case we also don't need a selection bit */
    mscConfig.downstreamConfig.srlActivePhaseSelection = IfxMsc_ActivePhaseSelection_none;
    mscConfig.downstreamConfig.srhActivePhaseSelection = IfxMsc_ActivePhaseSelection_none;

    /* initialize MSCs */
    for (i = 0; i < IFXMSC_NUM_MODULES; ++i)
    {
        /* init module pointer */
        mscConfig.msc = (Ifx_MSC *)IfxMsc_cfg_indexMap[i].module;

        /* IO Config */
        mscConfig.io = IfxMsc_PinMap[i];

        /* initialize module */
        IfxMsc_Msc_initModule(&g_MscBasic.msc[i], &mscConfig);
    }
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void MscBasicDemo_run(void)
{
    uint32 n, i;
    printf("Sending some values\n");

    for (n = 0; n < 10; ++n)
    {
        printf("#%lu\n", n + 1);

        /* clear IRQ flag of previous transfer */
        for (i = 0; i < IFXMSC_NUM_MODULES; ++i)
        {
            IfxMsc_Msc_clearDataFrameInterrupt(&g_MscBasic.msc[i]);
        }

        /* new transfer */
        for (i = 0; i < IFXMSC_NUM_MODULES; ++i)
        {
            const unsigned dataL = i * 0x1000 + n;
            const unsigned dataH = i * 0x1000 + 0x0100 + n;
            IfxMsc_Msc_sendData(&g_MscBasic.msc[i], dataL, dataH);
        }

        /* wait until transfers are finished */
        for (i = 0; i < IFXMSC_NUM_MODULES; ++i)
        {
            while (!IfxMsc_Msc_getDataFrameInterruptStatus(&g_MscBasic.msc[i]))
            {}

            while (IfxMsc_Msc_getActiveDataFrameStatus(&g_MscBasic.msc[i]))
            {}
        }
    }
}

/**
 * \file DsadcBasicDemo.c
 * \brief Demo DsadcBasicDemo
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
#include "DsadcBasicDemo.h"

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
App_DsadcBasic g_DsadcBasic; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/
static uint8 dsadcChannelAvailable[4] = {1, 0, 0, 1};

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void DsadcBasicDemo_init(void)
{
    uint32 chn;

    /* disable pull-up devices for analog pads of P00 (assigned to some analog pins) */
    P00_IOCR0.U  = 0x00000000;
    P00_IOCR4.U  = 0x00000000;
    P00_IOCR8.U  = 0x00000000;
    P00_IOCR12.U = 0x00000000;

    /* create module config */
    IfxDsadc_Dsadc_Config        dsadcConfig;
    IfxDsadc_Dsadc_initModuleConfig(&dsadcConfig, &MODULE_DSADC);

    /* initialize module */
    IfxDsadc_Dsadc               dsadc;
    IfxDsadc_Dsadc_initModule(&dsadc, &dsadcConfig);

    /* create channel config */
    IfxDsadc_Dsadc_ChannelConfig dsadcChannelConfig;
    IfxDsadc_Dsadc_initChannelConfig(&dsadcChannelConfig, &dsadc);

    /* modify default configuration */
    dsadcChannelConfig.modulator.positiveInput      = IfxDsadc_InputConfig_inputPin;
    dsadcChannelConfig.modulator.negativeInput      = IfxDsadc_InputConfig_inputPin;
    dsadcChannelConfig.modulator.inputGain          = IfxDsadc_InputGain_factor1;
    dsadcChannelConfig.modulator.inputPin           = IfxDsadc_InputPin_a;
    dsadcChannelConfig.modulator.modulatorClockFreq = 10.0e6;
    dsadcChannelConfig.modulator.commonModeVoltage  = IfxDsadc_CommonModeVoltage_c;

    dsadcChannelConfig.combFilter.bypassed          = FALSE;
    dsadcChannelConfig.combFilter.combFilterType    = IfxDsadc_MainCombFilterType_comb3;
    dsadcChannelConfig.combFilter.combFilterShift   = IfxDsadc_MainCombFilterShift_noShift;
    dsadcChannelConfig.combFilter.serviceRequest    = IfxDsadc_MainServiceRequest_everyNewResult;
    dsadcChannelConfig.combFilter.decimationFactor  = 32;
    dsadcChannelConfig.combFilter.startValue        = 32;

    dsadcChannelConfig.firFilter.fir0Enabled        = TRUE;
    dsadcChannelConfig.firFilter.fir1Enabled        = TRUE;
    dsadcChannelConfig.firFilter.offsetCompensation = FALSE;
    dsadcChannelConfig.firFilter.dataShift          = IfxDsadc_FirDataShift_shiftBy2;
    dsadcChannelConfig.firFilter.internalShift      = IfxDsadc_FirInternalShift_shiftBy1;

    /* initialize channels */
    for (chn = 0; chn < 1; ++chn)
    {
        if (dsadcChannelAvailable[chn])
        {
            dsadcChannelConfig.channelId = (IfxDsadc_ChannelId)chn;

            IfxDsadc_Dsadc_initChannel(&g_DsadcBasic.dsadcChannel[chn], &dsadcChannelConfig);
        }
    }

    /* start conversions */
    IfxDsadc_Dsadc_startScan(&dsadc, 0x3f, 0x3f);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void DsadcBasicDemo_run(void)
{
    uint32 i, j;
    uint32 chn;

    printf("DsadcBasicDemo_run() called\n");

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 100000; j++)
        {}

        printf("DSADC Channel Results:\n");

        for (chn = 0; chn < 1; ++chn)
        {
            if (dsadcChannelAvailable[chn])
            {
                printf("Chn#%d: %d\n", chn, IfxDsadc_Dsadc_getMainResult(&g_DsadcBasic.dsadcChannel[chn]));
            }
        }
    }
}

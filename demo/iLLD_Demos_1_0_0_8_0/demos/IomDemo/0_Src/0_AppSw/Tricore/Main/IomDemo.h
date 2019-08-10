/**
 * \file IomDemo.h
 * \brief Iom Demo
 * \version iLLD_Demos_1_0_0_8_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Demo_IomDemo_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_IomDemo_SrcDoc
 * \defgroup IfxLld_Demo_IomDemo_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_IomDemo_SrcDoc_Main
 */

#ifndef IOMDEMO_H
#define IOMDEMO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include "ConfigurationIsr.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
#include "Iom/Iom/IfxIom_Iom.h"
#include <Gtm/Tom/PwmHl/IfxGtm_Tom_PwmHl.h>
#include "_Utilities/Ifx_Assert.h"
#include "IfxGtm_regdef.h"
#include <stdio.h>
#include "Cpu0_Main.h"
#include "IfxSmu_reg.h"
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
/* PWM configuration*/
#define CFG_PWM_FREQUENCYREF                  (10001)
#define CFG_PWM_FREQUENCYMON                  (10000)
#define CFG_PWM_ISR_PROVIDER                  (IfxSrc_Tos_cpu0)
#define CFG_PWM_TRIGGER_RISING_EDGE_AT_PERIOD (TRUE)
#define CFG_PWM_TRIGGER_DUTYCYCLE             (0.5)
#define CFG_PWM_DEADTIME                      (2e-6)
#define CFG_PWM_MIN_PULSE                     (1e-6)
#define CFG_PWM_CCX_ACTIVE_STATE              (Ifx_ActiveState_high)
#define CFG_PWM_COUTX_ACTIVE_STATE            (Ifx_ActiveState_high)
/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    IfxIom_Iom_EcmConfig ecmConfig;    /**< \brief Event Combiner Module Configuration structure */
    IfxIom_Iom_FpcConfig fpcConfig;    /**< \brief Filter & Prescaler  Configuration structure */
    IfxIom_Iom_LamConfig lamConfig;    /**< \brief Logical Analayser Module Configuration structure */
    IfxIom_Iom           iom;          /**< \brief Iom handle */

    volatile unsigned    counterTimer; /**< \brief counter to track alarm signal   */

    IfxGtm_Tom_Timer     tomTimerref;  /**< \brief Iom Reference signal handle */
    IfxGtm_Tom_PwmHl     tomPwmref;    /**< \brief pwm handle */

    IfxGtm_Tom_Timer     tomTimermon;  /**< \brief Iom Monitor signal handle */
    IfxGtm_Tom_PwmHl     tomPwmmon;    /**< \brief pwm handle */
} App_Iom;
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN App_Iom g_Iom;
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
void IfxIomDemo_init(void);
void IfxIomDemo_run(void);

#endif

/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2010)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Lin_Core.h                                                   **
**                                                                           **
**  VERSION   : 1.2.1                                                        **
**                                                                           **
**  DATE      : 2011.11.01                                                   **
**                                                                           **
**  PLATFORM  : Infineon XC2000                                              **
**                                                                           **
**  COMPILER  : Tasking - Viper v2.4 r2                                      **
**                                                                           **
**  PROJECT   :  XC2000 LIN                                                  **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : This file contains functionality of Lin driver            **
******************************************************************************/
/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
** --------------------------------------------------------------------------**
** PM         Puneetha Mukherjee                                             **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/* 
 * V1.2.1: 2011.11.01, PM  : UTP ID AI00058130 is fixed.
 * V1.2.0: 2010.12.03, PM  : UTP AI00057123 is fixed. 
 * V1.1.0: 2010.05.19, PM  : UTP ID AI00056397 fixed. 
 * V1.0.0: 2010.05.19, PM  : Final Released Version
 * V0.1.0: 2010.04.16, PM  : Fixed MISRA checking. . 
 * V0.0.0: 2010.03.12, PM  : Initial version of IDL for LIN
 */

/******************************************************************************
**                      Includes                                              *
******************************************************************************/
#ifndef _LIN_CORE_H
#define _LIN_CORE_H

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
/*
   This is used to refer LLD_frm_data_updt_flg, LLD_frm_data_ovwr_flg
   and LLD_frm_data_usage_flg.
*/
#define  LIN_INIT_FRM_DATA            (0U)
#define  LIN_FRM_STATUS_RST           (0U)

#define  LIN_DUMMY_TIMEOUT            (65532U)
#define  LIN_BIT_0_EXTRACT            (1U)
#define  LIN_EXTRACT_BIT_OFFSET       (7U)
#define  LIN_EXTRACT_BYTE_OFFSET      (3U)  
         
#define  LIN_WKUP_CNT_EN_BIT0_VAL     (1U)
#define  LIN_WKUP_CNT_EN_BIT1_VAL     (2U)
#define  LIN_WKUP_CNT_EN_BIT2_VAL     (4U)
#define  LIN_WKUP_CNT_EN_BIT3_VAL     (8U) 
                                      
#define  LIN_FRM_NXT_BYTE             (1U) 
#define  LIN_FRM_BIT_BOUNDARY         (8U)
#define  LIN_FRM_HIGHER_OFFSET        (256U)
                                      
/* (( ((uint8)LIN_NUM_FRMS >> 3)) + 1)*/                                      
#define  LIN_FRM_BUFF_FLAGS           (9U)

/* status update macros and values */
#define LIN_STAT_SLP_LOC              (3U)
#define LIN_STAT_SLP_VAL              (8U)
#define LIN_STAT_ERROR_LOC            (0U)
#define LIN_STAT_ERROR_VAL            (1U)
#define LIN_STAT_SUCCESS_LOC          (1U)
#define LIN_STAT_SUCCESS_VAL          (2U)
#define LIN_STAT_OVER_RUN_LOC         (2U)
#define LIN_STAT_OVER_RUN_VAL         (4U)
#define LIN_STAT_PRTCT_ID_LOC         (8U)
#define LIN_STAT_PRTCT_ID_VAL         (65280U)
#define LIN_STAT_SAVE_CFG_LOC         (6U)
#define LIN_STAT_SAVE_CFG_VAL         (64U)
#define LIN_STAT_EVNT_COLL_LOC        (5U)
#define LIN_STAT_EVNT_COLL_VAL        (32U)
#define LIN_STAT_BUS_ACTVTY_LOC       (4U)
#define LIN_STAT_BUS_ACTVTY_VAL       (16U)

/* Wake up bit macros */                                      
#define IFC_WKUP_CNT_EN_BIT0_VAL      (1U)
#define IFC_WKUP_CNT_EN_BIT1_VAL      (2U)
#define IFC_WKUP_CNT_EN_BIT2_VAL      (4U)
#define IFC_WKUP_CNT_EN_BIT3_VAL      (8U)

/* Union for Parity calculations and wake up bit definitions */
/*lint -esym(960,18.4) */
typedef union
{
	struct
	{
  	uint16 b0: 1U;
  	uint16 b1: 1U;
  	uint16 b2: 1U;
  	uint16 b3: 1U;
  	uint16 b4: 1U;
  	uint16 b5: 1U;
  	uint16 b6: 1U;
    uint16 b7: 1U;
  }b;
  uint8 ch;
}T_SFR;
/*lint +esym(960,18.4) */
/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
#endif /*_LIN_CORE_H*/

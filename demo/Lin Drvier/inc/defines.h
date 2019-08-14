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
**  FILENAME  : defines.h                                                    **
**                                                                           **
**  VERSION   : 1.3.1                                                        **
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
**  DESCRIPTION  : This file contains common definition                      ** 
******************************************************************************/
/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
** --------------------------------------------------------------------------**
** PM         Puneetha Mukherjee                                            **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
 * V1.3.1: 2011.11.01, PM  : UTP ID AI00058130 is fixed.
 * V1.3.0: 2010.12.03, PM  : UTP AI00057123 is fixed. 
 * V1.2.0: 2010.09.08, PM  : UTP AI00056225 is fixed. 
 * V1.1.0: 2010.07.23, PM  : MISRA issues fixed.  
 * V1.0.0: 2010.05.19, PM  : Final Released Version
 * V0.1.0: 2010.04.16, PM  : Fixed MISRA checking. . 
 * V0.0.0: 2010.03.12, PM  : Initial version of IDL for LIN
 */

#ifndef _DEFINES_H
#define _DEFINES_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/

/*****************************************************************************
**                      Global Macro Definitions                            **
*****************************************************************************/
#define  E_OK                          (0U)
#define  E_NOT_OK                      (-1)

#define  LIN_1ST_BYTE                  (0U)
#define  LIN_2ND_BYTE                  (1U)  
#define  LIN_NULL_DATA                 (0U)
/* Moved the  macro from LIN_Diag.h and LIN_Protocol.h */
#define  LIN_FRM_ID_RST                (15U)
#define  LIN_TP_3RD_BYTE               (2U)
#define  LIN_TP_4TH_BYTE               (3U)
#define  LIN_NO_BYTES_TXED             (0U)
#define  LIN_BYTE_EXTRACT              (255U)
#define  LIN_GET_FRAME_ID              (63U)
#define  LIN_FRM_LEN_OFFSET            (1U)

#define  LIN_DIAG_SUPPORTED            (1U) 
#define  LIN_NO_SIGNAL_DEFINED         (0U)
#define  LIN_DIAG_TFIFO_NOT_DEF        (0U) 
#define  LIN_DIAG_RFIFO_NOT_DEF        (0U)
#define  LIN_SIGNAL_API_DYNAMIC        (1U)
#define  LIN_SLP_WKUP_SUPPORTED        (1U)
#define  LIN_RESP_ERR_SUPPORTED        (-1)
#define  LIN_NO_EVNT_FRM_DEFINED       (0U)
#define  LIN_NO_SPRDC_FRM_DEFINED      (0U)
#define  LIN_ALL_FEATURES_SUPPORTED    (1U)                                        
#define  LIN_SIGNAL_RD_WR_SUPPORTED    (1U)
#define  LIN_EVNT_SPRDC_FRM_SUPPORTED  (1U)
   
#define  LIN_NO_TIMEOUT                (0U)
#define  LIN_DIAG_EXTRACT_BYTE         (8U)

/*****************************************************************************
**                      Global Macro Definitions                            **
*****************************************************************************/

/*****************************************************************************
**                      Global Type Definitions                             **
*****************************************************************************/

/*****************************************************************************
**                      Global Constant Declarations                        **
*****************************************************************************/

/*****************************************************************************
**                      Global Variable Declarations                        **
*****************************************************************************/

/*****************************************************************************
**                      Global Function Declarations                        **
*****************************************************************************/ 
#endif /* _DEFINES_H */

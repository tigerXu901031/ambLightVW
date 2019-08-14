/******************************************************************************
**                                                                          **
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
**  FILENAME  : LIN_Protocol.h                                               **
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
**  DESCRIPTION  : This file contains functionality of Lin ISR and State     **
**  Machines for timeout and serial communications.                          ** 
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
 * V1.3.1: 2011.11.01, PM  : UTP ID AI00058130 is fixed.
 * V1.3.0: 2010.12.03, PM  : UTP AI00057123 is fixed. 
 * V1.2.0: 2010.08.19, PM  : UTP AI00056226 is fixed.
 * V1.1.0: 2010.07.23, PM  : Updated for UTP AI00055629.     
 * V1.0.0: 2010.05.19, PM  : Final Released Version
 * V0.1.0: 2010.04.16, PM  : Fixed MISRA checking. . 
 * V0.0.0: 2010.03.12, PM  : Initial version of IDL for LIN
 */

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#ifndef _LIN_PROTOCOL_H
#define _LIN_PROTOCOL_H

#include "LIN_LDF.h"
#include "LIN_Core.h"

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
#define  LIN_AUTOBAUD_HW_PAGE         (5U)

/* UTP AI00056226 is fixed */
#define LIN_RESP_ERROR_BIT_CLR        (0U)
#define LIN_RESP_ERROR_BIT_SET        (1U)
/* UTP AI00056226 is fixed */

/* If Frame buffer conatins updated data or not */
#define  LIN_UPDATED_DATA             (0U)
#define  LIN_NO_UPDATED_DATA          (1U)
                                      
/* Frame Type , Subscriber / Publisher or None */
#define  LIN_FRM_TX                   (1U)
#define  LIN_FRM_RX                   (2U)
#define  LIN_DUMMY_FRM                (0U)
                                      
/* Auto baud detection counts */
#define  LIN_BREAK_BIT                (0U)           
#define  LIN_SYNC_BYTE_2BIT           (2U)           
#define  LIN_SYNC_BYTE_4BIT           (3U)           
#define  LIN_SYNC_BYTE_6BIT           (4U)           
#define  LIN_SYNC_BYTE_8BIT           (5U)           
#define  LIN_SYNC_BYTE_STOP_BIT       (6U)
#define  LIN_SYNC_BYTE_START_BIT      (1U)           
                                      
/* Sleep / Wakeup related */                                      
#define  LIN_WKUP_CNT_1               (0U)      
#define  LIN_WKUP_CNT_2               (1U)      
#define  LIN_WKUP_CNT_3               (2U)
#define  LIN_WKUP_CNT_4               (3U)   
#define  LIN_BUS_IDLE_4S              (1U) 
#define  LIN_WAKBYTE_EXTRACT          (0x0F)
#define  LIN_8BIT_BYTE_BOUNDARY       (256U)

#define  LIN_CHKSUM_BYTE              (255U)

#define  LIN_1_BYTE_TIME              (11000U)/*(10U * 1000U * 1U)U and 10%*/
#define  LIN_2_BYTE_TIME              (22000U)/*(10U * 1000U * 2U)U */

 
/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
typedef struct
{
	 #ifdef _IFC_SLAVE
	   /* Break / SYNC State Machine */
     LIN_BRK_SYNC_STATE  Lin_BrkSyncState; 
   #endif /* #ifdef _IFC_SLAVE */
   /* Frame Processing State Machine */	
   LIN_COMM_STATE  Lin_CommState	;
}LIN_SLAVE_STATE_INFO;

/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
          
#endif /* _LIN_PROTOCOL_H */

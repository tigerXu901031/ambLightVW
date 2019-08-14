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
**  FILENAME  : Lin_Diag.h                                                   **
**                                                                           **
**  VERSION   : 1.4.1                                                        **
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
**  DESCRIPTION  : This file contains functionality of Lin Diagnostic services*
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
 * V1.4.1: 2011.11.01, PM  : UTP ID AI00058130 is fixed.
 * V1.4.0: 2010.12.03, PM  : UTP AI00057123 is fixed. 
 * V1.3.0: 2010.09.08, PM  : UTP AI00056225 fixed. 
 * V1.2.0: 2010.08.12, PM  : UTP AI00056181 (Assign Frame ID Range) fixed.
 * V1.1.0: 2010.07.23, PM  : Updated for UTP: AI00055629
 * V1.0.0: 2010.05.19, PM  : Final Released Version
 * V0.1.0: 2010.04.16, PM  : Fixed MISRA checking. . 
 * V0.0.0: 2010.03.12, PM  : Initial version of IDL for LIN
 */
#ifndef _LIN_Diag_H
#define _LIN_Diag_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/

#include "LIN_IIL.h"

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
#define  LIN_DIAG_FRM_LEN                   (8U)
#define  LIN_DIAG_RFIFO_EMPTY               (0U) 
#define  LIN_DIAG_TFIFO_EMPTY               (0U) 
#define  LIN_DIAG_FIFO_STS_RESET            (1U)
                                            
/* Diag Buffer Index values */              
#define  DIAG_TX_BUFF_INDEX_0               (0U)   
#define  DIAG_TX_BUFF_INDEX_1               (1U)
#define  DIAG_TX_BUFF_INDEX_2               (2U)
#define  DIAG_TX_BUFF_INDEX_3               (3U)
#define  DIAG_TX_BUFF_INDEX_4               (4U)   
#define  DIAG_TX_BUFF_INDEX_5               (5U)
#define  DIAG_TX_BUFF_INDEX_6               (6U)
#define  DIAG_TX_BUFF_INDEX_7               (7U)
                                            
#define  LIN_DIAG_SLP_CMD                   (0U)
#define  LIN_DIAG_UNUSED_BYTE               (255U)
#define  LIN_DIAG_CLASSIC_CHKSUM            (0U) 

/* TP related macros */
#define  LIN_TP_SF                           (0U)
#define  LIN_TP_FF                           (1U)        
#define  LIN_TP_MIN_SN                       (0U)   
#define  LIN_TP_PCI_FF                       (16U)
#define  LIN_TP_PCI_CF			                 (32U)                    
#define  LIN_TP_PCI_SF                       (0U)                
#define  LIN_TP_PCI_SN                       (15U)                
#define  LIN_TP_MAX_SN                			 (16U) 
#define  LIN_TP_SF_LEN                       (6U)                
#define  LIN_TP_RX_PNDG                      (1U)
#define  LIN_TP_TX_PNDG                      (1U)
#define  LIN_TP_MSB_BYTE                     (4U)   
#define  LIN_TP_NO_RX_MSG                    (0U)
#define  LIN_TP_NO_TX_MSG                    (0U)
#define  LIN_TP_LEN_DELIMIT                  (256U)
#define  LIN_TP_MSG_MAX_LEN                  (4096U)  
#define  LIN_TP_FRAME_LEN_MSB_EXTRACT        (15U)  
                                
                                             
#define  LIN_MAX_PID_CNT                     (4U)         
#define  LIN_DIAG_UNASSIGN                   (64U)      
#define  LIN_INVALID_FRM_ID                  (64U)
                         
#define  LIN_FRM_ID_UASSIGN                  (0U)
#define  LIN_MAX_FRM_ID_UNCD                 (59U)
#define  LIN_FRM_ID_DONT_CARE                (255U) 
#define  LIN_DGNSTC_REQ_FRM_NUM              (60U)
#define  LIN_DGNSTC_RESP_FRM_NUM             (61U)
         
/* Diags Call back related */
#define  LIN_DIAG_PCI_SF                     (6U)
#define  LIN_DIAG_PCI_1_BYTE                 (1U)
#define  LIN_DIAG_PCI_6_BYTE                 (6U)
#define  LIN_DIAG_READ_BY_ID_00              (0U)
#define  LIN_DIAG_ASSIGN_NAD_SID             (176U)/*(0xB0U)*/
#define  LIN_DIAG_READ_BY_ID_SID             (178U)/*(0xB2U)*/
#define  LIN_DIAG_ASSIGN_NAD_RSID            (240U)/*(0xF0U)*/
#define  LIN_DIAG_CONDITIONAL_NAD            (179U)/*(0xB3U)*/
#define  LIN_DIAG_READ_BY_ID_RSID            (242U)/*(0xF2U)*/
#define  LIN_DIAG_ASSIGN_FRM_ID_SID          (177U)/*(0xB1U)*/
#define  LIN_DIAG_ASSIGN_FRM_ID_RSID         (241U)/*(0xF1U)*/
#define  LIN_DIAG_CONDITIONAL_NAD_RSID       (243U)/*(0xF3U)*/
#define  LIN_DIAG_ASSIGN_FRM_ID_RANGE_SID    (183U)/*(0xB7U)*/
#define  LIN_DIAG_ASSIGN_FRM_ID_RANGE_RSID   (247U)/*(0xF7U)*/

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
typedef enum
{
  #ifdef LIN_V_2_1
    /* Transmit queue is empty. In case previous calls to ld_put_raw, all 
        frames in the queue have been transmitted.                                                         
    */                                                                         
    LD_QUEUE_EMPTY     = 0U,            
    /* The transmit queue contains entries, but is not full. */                      
    LD_QUEUE_AVAILABLE = 1U,   
    /* Transmit queue is full and can not accept further frames.*/
    LD_QUEUE_FULL      = 2U,   
    /* LIN protocol errors occurred during the 
        transfer, initialize and redo the transfer.
    */    
    LD_TRANSMIT_ERROR  = 4U,   

    /* The receive queue is empty */
    LD_NO_DATA         = 0U,  
    /* The receive queue contains data, that can be read. */
    LD_DATA_AVAILABLE  = 16U,  
    /* LIN protocol errors occurred during the transfer, initialize and 
        redo the transfer.    
    */    
    LD_RECEIVE_ERROR   = 32U   
  #else                           
    /* Tx/Rx FIFO Status */                                               
    LD_NO_VALUE        = 0U,    
    /* The transmit queue is full and can not  accept further frames. */                                             
    LD_QUEUE_FULL      = 1U,    
    /* The transmit queue is empty i.e. all frames available in the queue 
        has been transmitted. 
    */    
    LD_QUEUE_EMPTY     = 2U,    
    /* LIN protocol errors occurred during the 
        transfer, abort and redo the transfer.
    */    
    LD_TRANSFER_ERROR  = 4U,    
    /* The receive queue contains data and can be read. */
    LD_DATA_AVAILABLE  = 8U,    
    /* The last node configuration call was successfully carried out. */
    LD_SUCCESS         = 16U,   
    /* The last node configuration call failed, more information can be 
        found by parsing error_code.
    */                            
    LD_NEGATIVE        = 32U,   
    /* No response was received on the last node configuration request. */  
    LD_NO_RESPONSE     = 64U    
  #endif   /* LIN_V_2_1 */
} LIN_DIAG_FIFO_STAT;  

typedef enum
{
	/* The receiption is not yet completed. */
  LD_IN_PROGRESS = 0U,
  /* Data transmission is completed and all data available.*/
  LD_COMPLETED = 1U,

  /* The transmission ended in an error and 
     the data was only partially transmitted.
  */
  LD_FAILED = 2U,
  /* Transmission failed because of a N_As timeout.*/
  LD_N_AS_TIMEOUT = 4U,
  /* Transmission failed because of a N_CR timeout.*/
  LD_N_CR_TIMEOUT = 8U,
  /* The reception failed becoz of an unexpected SN.*/
  LD_WRONG_SN = 16U
} LD_DIAG_TP_STAT;

/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
/* The call queues the transmission of the eight bytes specified byte data.*/                                                                                  
void        ld_put_raw( l_ifc_handle iii,  const uint8 * const data1  );                                                                                
                                                                                       
/* The call copies the oldest received diagnostic frame to the memory 
   specified by data1.                                                                                                
*/                                                                                  
void        ld_get_raw( l_ifc_handle iii,  uint8 * const data1  );                                                                                
                                                                                       

/*  The call returns the status of the tx queue status */
uint8        ld_raw_tx_status( l_ifc_handle iii    );

/*The call returns the status of the tx queue status */
uint8        ld_raw_rx_status( l_ifc_handle iii  );
     
/* The call packs the information specified by data and length into one or 
   multiple diagnostic frames     .
*/   
void ld_send_message (  l_ifc_handle iii ,
                        uint16* const length,
                        uint8* const NAD,
                        uint8* const data_buff
                        );

/* The call prepares the LIN diagnostic module to receive one message and 
   store it in the buffer pointed to by data.
*/   
void ld_receive_message (
                        l_ifc_handle iii ,
                        uint16* const length,
                        uint8* const NAD,
                        uint8* const data_buff
                        ) ;
                        
/* The call returns the status of the last made call to ld_receive_message. */                                                
uint8 ld_rx_status( l_ifc_handle iii );

/* The call returns the status of the last made call to ld_send_message. */
uint8 ld_tx_status( l_ifc_handle iii );     
#endif /*_LIN_Diag_H */















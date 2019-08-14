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
**  FILENAME  : Lin_IIL.h                                                    **
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
**  DESCRIPTION  : This file contains functionality of Lin Hardware dependent**
**  layer. In abstracts the functionality of USIC ASC driver                 **
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
 * V1.2.0: 2010.09.08, PM  : updated for UTP ID AI00056265   
 * V1.1.0: 2010.07.23, PM  : updated for UTP ID AI00055632   
 * V1.0.0: 2010.05.19, PM  : Final Released Version
 * V0.1.0: 2010.04.16, PM  : Fixed MISRA checking. . 
 * V0.0.0: 2010.03.12, PM  : Initial version of IDL for LIN
 */

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#ifndef _LIN_IIL_H
#define _LIN_IIL_H
   
#include "LIN_LDF.h"   
#include "Defines.h"
#include "LIN_Core.h"

/******************************************************************************
**                      Imported Compiler Switch Check                       **
******************************************************************************/
#ifndef _IFC_SLAVE
  #error "Select interface either as slave in LIN_CFG.h file"
#endif /* #ifndef _IFC_SLAVE */

#if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 
  #if  (_TP_BUFF_MGMT  == 0U) 
    #if((_DGNSTC_TBUFF_SZ < 1U) || (_DGNSTC_RBUFF_SZ < 1U) )
      #error "Configure diagnostic TX/RX buffer sizes (>zero)in LIN_CFG.h file"
    #endif/* Diags Buffer Size */
  #endif /* #if  (_TP_BUFF_MGMT  == 0) */  
#endif /* _DGNSTC_FRM_SPRT */

#if    ((LIN_SYS_CFG_BAUD < 4800U) || (LIN_SYS_CFG_BAUD > 20000U))
  #error "The configured baudrates in LIN_LDF.h file is not supported"
#endif

#define   _LIN_FRAME_CNT                 (1U)

/******************************************************************************       
**                      Global Macro Definitions                             **       
******************************************************************************/       
#define  LIN_NUM_FRMS                    (64U)
#define  LIN_EVNT_FRM_COLLISION          (1U)
#define  LIN_EVNT_FRM_NO_COLLISION       (0U)


/* Used as time counters to measure sleep and wakeup timeouts all in ms */
#define LIN_CFG_SLEEP_TIME               (4000)
/* Updated for UTP AI00056265 */   
#define LIN_CFG_WKUP_RESP_WAIT_TIME      (200U)
#define LIN_CFG_WKUP_RESP_MAX_WAIT_TIME  (1900U)
/* Updated for UTP AI00056265 */

/*broadcast symbols used in diagnostic module */
#define LIN_BROADCAST                    (127U)
#define LIN_ANY_SUPPLIER                 (32767U)
#define LIN_ANY_FUNCTION                 (65535U)
#define LIN_ANY_MESSAGE                  (65535U)
#define LIN_FUNCTIONAL_NAD               (126U)

/*
   Timeout for each byte of respoonse field used in slave
   UART ISR-->RCV_FRM_ID branch of 'ifc_curr_slot_timeout'. Incase the 
   transmission is not complete then timer interrupt will be triggered by 
   checking with ifc_curr_time_out_cntr variable in LIN_IFX_SLP_WKUP_TMR_ISR 
   (salve) or LIN_IFX_SCHD_ISR(master).
*/
#define LIN_CFG_RESP_TIMEOUT \
             (uint8)(((14U * 1000U)/(LIN_SYS_CFG_BAUD * 1U)) + 1U)/*0.5 */

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
typedef enum
{ 
	/*Diagnostic module is busy */
  LD_SERVICE_BUSY     = 0U,       
  /* Completed master request frame */
  LD_REQUEST_FINISHED = 1U,
  /*Diagnostic module is free */  
  LD_SERVICE_IDLE     = 2U,  
  /*Transmission error while sending diagnostic frame */
  LD_SERVICE_ERROR    = 4U  
} LD_DIAG_RESP_STAT;                                                                       

/* Specifies the state of interface. */
typedef enum
{  
	/* Interface is in active state; it can either receive or publish frames. */
  LIN_ACTIVE   = 0U, 
  /* 
   Interface is in sleep pending state, i.e. a sleep command will be 
    sent in next slot
  */
  LIN_SLP_PNDG = 1U,                    
  /* Interface in sleep state, interface neither receive nor transmit frames. */                    
  LIN_SLPNG    = 2U,    
  /* Interface send a wakeup signal & waiting for breakup signal from master */
  LIN_WKUP     = 3U
} LIN_BUS_STATE;

#ifdef _IFC_SLAVE
  typedef enum
  {  
    /* Break / Sync default state , waiting for a new break */
    LIN_BRK_SYNC_IDLE = 0U,
  	/* Break / Sync state is waiting for SYNC Byte */
    LIN_DETECT_SYNC   = 1U 
  } LIN_BRK_SYNC_STATE;
#endif /* #ifdef _IFC_SLAVE */  
/*                                                                                       
   @enum:(DESIGN) LIN_IFC_CURR_STATE |                                                   
   Specify the current state of interface in specific frame transaction period.          
 */                                                                                      
typedef enum                                                                             
{                       
  /* 
  IDLE state, interface enter into this state whenever it expec
  after current frame transaction or sleep state. 
  */
  LIN_IDLE      = 0U,
  /* Interface waiting for receiving a break signal. */     
  LIN_BREAK     = 1U,   
   /* Waiting for sync signal */                
  LIN_SYNC      = 2U,  
  /* Waiting for frame ID */                                      
  LIN_PID       = 3U,         
  /* Interface is subscriber and receiving data */                            
  LIN_RX_DATA   = 4U,  
  /* Interface is publisher and transmits data */                 
  LIN_TX_DATA   = 5U,  
  /* Waiting for receiving checksum byte */                        
  LIN_RX_CHKSUM = 6U,        
   /* Sending checksum byte */                   
  LIN_TX_CHKSUM = 7U  
} LIN_COMM_STATE;                                                                            

/* 
 Indicates the interface number. l_ifc_handle is used in the API wherever
  an interface must be selected. This is required to abstract the number 
  of LIN interfaces implemented in the same system.
*/    

typedef uint8 l_ifc_handle;

/* 
 Indicates the flag handle. l_flag_handle is used in API whenever a frame 
  flag must be selected. This is required to abstract the number of frames 
  implemented in the same system.
*/
typedef uint8 l_flag_handle;

/*
 Used in API to store or restore the interrupt flags of peripherals
  (like ASC and timers).
*/
typedef uint8 l_irqmask;
/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/      

/*
  Initializes the controller specified by interface handle (l_ifc_handle)
   Initialize all the interface variables to the default values.
*/
#ifdef LIN_V_2_1
  l_bool l_ifc_init( l_ifc_handle iii );
#else
  void   l_ifc_init( l_ifc_handle iii   );
#endif /* LIN_V_2_1 */


/* LIN core initialization function */
l_bool      l_sys_init( void );

#ifndef LIN_V_2_1
  /*
   Connect the interface handle to the LIN cluster and enables the
    transmit/receive of frame header and its repsonses.
  */
  l_bool      l_ifc_connect( l_ifc_handle iii );
  
  /* Disconnects interface from the LIN cluster  */
  l_bool      l_ifc_disconnect( l_ifc_handle iii );
#endif /* #ifdef LIN_V_2_1 */

#if ((_SIG_RDWR_FUNC_SPRT == 1U) || (_FEATURES == 1U))
  #if (LIN_SYS_CFG_NUM_OF_SIGS > 0U)
    #if (_SIGNAL_PROTOTYPE == LIN_SIGNAL_API_DYNAMIC)
      
      /* The API is used to read signal of size 1 bit.  */
      l_bool      l_bool_rd( l_signal_handle sss );

      /* 
         The API returns the value of signal. Signal size is between 
         1 to 8 bits. 
      */
      l_u8        l_u8_rd( l_signal_handle sss  );

      /*
         The API returns the value of signal. Signal size is between 
         1 to 16 bits. 
      */
      l_u16       l_u16_rd( l_signal_handle sss  );
      
      /* The API updates signal of size 1 bit. */
      void        l_bool_wr( l_signal_handle sss, l_bool v  );

      /* The API updates signal of size 1 to 8 bit */
      void        l_u8_wr( l_signal_handle sss, l_u8 v  );
      /* The API updates signal of size 9 to 16 bit */         
      void        l_u16_wr( l_signal_handle sss, l_u16 v  );
      
      /*
        reads and returns the current value of the selected 
         bytes of the signal specified only incase the associated frame 
         has updated data.
      */
      void        l_bytes_rd( l_signal_handle sss, l_u8 start, l_u8 count, 
                        l_u8 * const data1  );
                        
      /* update the signal's associated frame data with the supplied data */
      void        l_bytes_wr( l_signal_handle sss, l_u8 start, 
                              l_u8 count, const l_u8 * const data1 
                             );
    #endif /* #if (_SIGNAL_PROTOTYPE == LIN_SIGNAL_API_DYNAMIC) */     
  #endif   /*LIN_SYS_CFG_NUM_OF_SIGS */
#endif   /* Signal read/write functions support */

/* returns boolean value indicating the current state of the flag specified */
l_bool      l_flg_tst( l_flag_handle fff  );

/* Reset the current value of the flag specified by the l_flag_handle */
void        l_flg_clr( l_flag_handle fff );


/* Sends a go to sleep command  */
#if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
  /* Sends a wakeup signal on the bus */
  void        l_ifc_wake_up( l_ifc_handle iii );
#endif /* */

/* Returns the status of the interface :

   bit 0 --> one of the frame transmission is incomplete
   bit 1 --> one of the frame transmission is success
   bit 2 --> bit 0/1 are overwritten
   bit 3 --> interface is/was entered into sleep state
   bit 4 --> bus active state (only in v2.1)
   0 --> bus is inactive
   1 --> bus is in active
   bit 5 --> event triggered frame collision (only in v2.1, master)
   1 --> event triggered frame schedule table is active
   bit 6 --> save configuration (only in v2.1, slave)
   1 --> received save configuration request, currently not supported
   bit 8 to 15 --> PID detected and processed on the bus very recently

*/
uint16       l_ifc_read_status( l_ifc_handle iii );
     
/* Disables all the LIN related interrupts. */
l_irqmask   l_sys_irq_disable( void );

/* Re-enables the LIN interrupts */
void        l_sys_irq_restore( l_irqmask previous   );
     
#ifdef LIN_V_2_1

  /* This routine (re) initializes diagnostic module variables  */
  void        ld_init( l_ifc_handle iii   );
#endif

#ifdef _LIN_FRAME_CNT   
  #ifdef LIN_V_2_1
    void FrmId_FrmCntIncr(uint8 FrameId);
    uint16 FrmId_FrmCntRead(uint8 FrameId);
    l_bool FrmId_FrmCntInit (uint8 u8FrameId) ;
  #endif /* LIN_V_2_1 */  
#endif /* _LIN_FRAME_CNT */

#endif /*_LIN_IIL_H*/

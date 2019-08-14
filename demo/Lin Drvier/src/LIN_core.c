/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2010)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorisation.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Lin_Core.c                                                   **
**                                                                           **
**  VERSION   : 1.6.0                                                        **
**                                                                           **
**  DATE      : 2011.12.01                                                   **
**                                                                           **
**  PLATFORM  : Infineon XC2000                                              **
**                                                                           **
**  COMPILER  : Independent                                                  **
**                                                                           **
**  AUTHOR    : Puneetha Mukherjee                                           **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**                                                                           **
**  DESCRIPTION  : This file contains functionality of Lin driver            **
**                                                                           **
**  SPECIFICATION(S) : Lin 2.1 / 2.0                                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                           **
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
 * V1.6.0: 2011.12.01, PM  : UTP ID AI00058380 is fixed. 
 * V1.5.0: 2011.11.01, PM  : UTP ID AI00058130 is fixed. 
 * V1.4.0: 2010.12.03, PM  : Removed Master Code. UTP AI00057123. 
 * V1.3.0: 2010.09.08, PM  : UTP AI00056226 is fixed.
 * V1.2.0: 2010.08.12, PM  : Status Frame ID made a variable from a macro.  
 * V1.1.0: 2010.07.23, PM  : utp AI00055631 is fixed.  
 * V1.0.0: 2010.05.19, PM  : Final Released Version
 * V0.1.0: 2010.04.16, PM  : Fixed MISRA checking. . 
 * V0.0.0: 2010.03.12, PM  : Initial version 
 */

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
/* Repeated file inclusion  */
/*lint -elib(537) */
/* Function-like macro defined in LIN_LDF.h */
/*lint -esym(961, 19.7)*/  
/* '#/##' operator used in LIN_LDF.h */
/*lint -esym(961, 19.13)*/ 
#include "LIN_IIL.h"
#include "LIN_IDL.h"                    
#include "LIN_Diag.h"          
#include "LIN_Protocol.h"               
/* lint +elib(537) */
/*lint +esym(961,19.7) */
/*lint +esym(961, 19.13)*/ 

/*lint -e10 */
/*lint -e48 */
/*lint -e63 */
/*lint -e69 */
/*lint -e151 */
/*lint -e923 */
/*lint -e529 */      /* Warning 529: Symbol 'FAR'not subsequently referenced */

/******************************************************************************
**               Private Macro Definitions                                   **
******************************************************************************/

/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/

/******************************************************************************
**                      Private Function Declarations                        **
******************************************************************************/                    
#ifdef LIN_V_2_1    
  static l_bool Lin_lConnect (l_ifc_handle iii);
#endif /* #ifdef LIN_V_2_1 */
#ifdef LIN_V_2_1
  uint8  Lin_lGetFrmIdx(uint8 u8FrmId);
#endif /* */  
#if (_SIGNAL_PROTOTYPE == LIN_SIGNAL_API_DYNAMIC)
  #if((_SIG_RDWR_FUNC_SPRT == LIN_SIGNAL_RD_WR_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
    static uint16 Lin_lSignalRd( l_signal_handle sss );
    static void   Lin_lSignalWr( l_signal_handle sss, uint16 v );
  #endif
#endif /* */
#if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED)
  void Lin_lRespFrmUpdate(uint8 u8Data);
#endif 

/******************************************************************************
**                      Global Constant Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Global Variable Definitions                          **
******************************************************************************/
/*-----------------------------------------------------------------------------
* Variable Name : Lin_BufferInUse                                             *
* Type          : unsigned char                                               *
* Description   : This flag indicates the busy/available status for the LLD   *
*                 buffer.                                                     *
-----------------------------------------------------------------------------*/
uint8  Lin_BufferInUse[ LIN_FRM_BUFF_FLAGS ];

/*-----------------------------------------------------------------------------
* Variable Name : Lin_BufferDataLost                                          *
* Type          : unsigned char                                               *
* Description   : This flag indicates a data loss in "frame data" buffer when *
*                 the buffer gets overwritten.                                *
*                                                                             *  
-----------------------------------------------------------------------------*/
uint8 Lin_BufferDataLost[ LIN_FRM_BUFF_FLAGS ];

/*-----------------------------------------------------------------------------
* Variable Name : Lin_CurrTimeOutCntr                                         *
* Type          : unsigned short                                              *
* Description   : The variable is used to measure frame timeout, sleep and    *
                 wakeup time. The variable is reset to zero, at the start of  *
                 event and gets incremented within timer ISR.                 *
-----------------------------------------------------------------------------*/
uint16       Lin_CurrTimeOutCntr;

/*-----------------------------------------------------------------------------
* Variable Name : lin_CurrSlotTimeOut                                         *
* Type          : unsigned char                                               *
* Description   : The variable contains the maximum allowed time for following*
*                - frame transmission                                         *
*                - wait for wakeup (slave) within which master should respond.*
*                - wait for wakeup (master) in order to publish a header      *
-----------------------------------------------------------------------------*/
uint8        Lin_CurrSlotTimeOut;

/*-----------------------------------------------------------------------------
* Variable Name : Lin_FrmSts                                                  *
* Type          : unsigned char                                               *
* Description   : This variable contains the following:                       *
*                - recent PID transmitted on LIN bus,                         *
*                - status of frame transmission e.g. failure/success, over run*
*                  or sleeping etc... .                                       *
*                                                                             *  
*                It is used in l_ifc_read_status API                          *
-----------------------------------------------------------------------------*/
uint16       Lin_FrmSts;
/*-----------------------------------------------------------------------------
* Variable Name : Lin_BusState                                                *
* Type          : unsigned char                                               *
* Description   : Indicates interface status e.g. ACTIVE, SLEEP ..            *
-----------------------------------------------------------------------------*/
volatile LIN_BUS_STATE Lin_BusState;

#if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED)
  /*---------------------------------------------------------------------------
  * Variable Name : Lin_Status_FrmID                                          *
  * Type          : unsigned char                                             *
  * Description   : Indicates Status Frame ID Number                          *
  ---------------------------------------------------------------------------*/
  uint8 Lin_Status_FrmID;
  
  /*---------------------------------------------------------------------------
  * Variable Name : Lin_Status_FrmID_Index                                    *
  * Type          : unsigned char                                             *
  * Description   : Indicates Status Frame ID Index Number                    *
  ---------------------------------------------------------------------------*/
  uint8 Lin_Status_FrmID_Index;
#endif   /* _IFC_RESP_ERR_FRM_NUM ... */
/*-----------------------------------------------------------------------------
* Variable Name : Lin_WkupCnt                                                 *
* Type          : union / custom                                              *
* Description   : This variable contains interface specific flags.            * 
*                 (diagnostic/sporadic frame etc..)                           *
-----------------------------------------------------------------------------*/
T_SFR t_Lin_WkupCnt;
#define Lin_WkupCnt  (t_Lin_WkupCnt.ch)
#define wkup_bit2    (t_Lin_WkupCnt.b.b2)
#define wkup_bit3    (t_Lin_WkupCnt.b.b3)
/* #define wkup_bit4    (t_Lin_WkupCnt.b.b4) */

/******************************************************************************
**                      Private  Constant Definitions                        **
******************************************************************************/

/******************************************************************************
**                     Imported  Variable Definitions                        **
******************************************************************************/
#ifdef _IFC_SLAVE 
  extern LIN_SLAVE_STATE_INFO   Lin_StateMachine;
  extern uint8                  Lin_AutoBaudBitCtr;   
  extern uint8                  Lin_WkupRetryCnt;
#endif /* Slave */

#ifdef LIN_V_2_1
  #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 
    extern uint8    Lin_LastFrmId;
  #endif /* Diags */
#endif /* #ifdef LIN_V_2_1 */

#ifndef LIN_V_2_1
  #if ((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || \
     (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
    extern uint8  Lin_NAD;
    extern uint8  Lin_OldNAD;                           
    extern uint8  Lin_InitNAD;                           
    extern uint8  Lin_TempNAD;                     
  #endif /* */ 
  extern uint8  Lin_DiagTxFifoRdIdx;
  extern uint8  Lin_DiagTxFifoWrIdx;
  extern uint8  Lin_DiagTxFifoLvl;
  extern volatile uint8  Lin_DiagRxFifoLvl;
  extern LIN_DIAG_FIFO_STAT Lin_DiagFifoSts;
  
  #ifdef LIN_V_2_0  
      #if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) )
        #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)
          extern uint16 Lin_EventCache[LIN_SYS_CFG_NUM_OF_EVNT_FRMS] ;
        #endif 
      #endif
  #endif         
#endif /* */  

/* Last value assigned to variable 'iii' not used */
/*lint -e438 */ 
/*lint -e550 */
/******************************************************************************
**                      Global Function Definitions                          **
******************************************************************************/
/******************************************************************************
** Syntax           : l_sys_init                                             **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : None                                                   **
**                                                                           **
** Parameters (out) : None                                                   **
**                                                                           **
** Return value     : Zero If the initialization succeeded.                  **
**                    Non-zero If the initialization failed.                 **
**                                                                           **
** Description      : This API called only at the time of LIN LLD .          **
**                    initialization. This performs the initialization of    ** 
**                    the LIN core. The scope of the initialization is the   ** 
**                    physical node.                                         **              
**                                                                           **
******************************************************************************/
l_bool l_sys_init( void )
{
  uint8        nloop;
    
  /* Init of all global vars to their default state, except those which need
      to be set within specific API. 
      (e.g. sch table to L_NULL_SCHEDULE in l_ifc_init)	 
  */

  /* Reset data flags. */
  for ( nloop = 0U; nloop < (uint8)( LIN_FRM_BUFF_FLAGS ); nloop++ )
  {
    Lin_BufferInUse[nloop]    = (uint8)LIN_INIT_FRM_DATA;
    Lin_BufferDataLost[nloop] = (uint8)LIN_INIT_FRM_DATA;
  }  

  /* Set the device in active state (default).*/
  Lin_BusState     = LIN_ACTIVE;  

  /* Reset status data. (used in l_ifc_read_status) */
  Lin_FrmSts       = (uint16)LIN_FRM_STATUS_RST;  
  
  /* Reset Current activity elapsed time counter.
      This counter is reset at start of any timeout activity e.g. frame  
      duration timeout, timeout while waiting after a wakeup (before sending 
      successive wakeups).   
      It is incremented in T0/T1/GPTA timer ISR.
  */
  Lin_CurrTimeOutCntr = 0U;
  
  #if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED)
    /* UTP AI00056226 is fixed */
    Lin_Status_FrmID       = (uint8)_IFC_RESP_ERR_FRM_NUM;    
    #ifdef LIN_V_2_1      
      Lin_Status_FrmID_Index = Lin_lGetFrmIdx((uint8)Lin_Status_FrmID);
    #else
      /* frame IDs are in sequence order in V2.0*/
      Lin_Status_FrmID_Index = Lin_Status_FrmID;
    #endif /* LIN_V_2_1 */
  #endif /* #if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED) */
  
  #if( ( _DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) ||( _FEATURES == LIN_ALL_FEATURES_SUPPORTED ))

    #ifndef LIN_V_2_1
      /* Prepare the Diagnostic module to accept new commands.*/
      Lin_WkupCnt = LIN_WKUP_CNT_EN_BIT0_VAL;

      /* Initialize NAD with the defined value in LIN_CFG.h file */
      Lin_NAD     = (uint8)_IFC_NAD;
      Lin_InitNAD = (uint8)_IFC_NAD;
      Lin_OldNAD  = (uint8)_IFC_NAD;  
          
      /* Initialize diagnostic FIFO status. (no transfer/transmit errors) */
      Lin_DiagFifoSts = LD_NO_VALUE; /* ( LIN_DIAG_FIFO_STAT ) LD_NO_VALUE */
  
      /* Reset TX and RX diagnostic circular queue. */
      #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF)
        Lin_DiagTxFifoRdIdx    = 0U;
        Lin_DiagTxFifoWrIdx    = 0U;
        Lin_DiagTxFifoLvl      = 0U;
      #endif /* End of #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF) */

      #if (_DGNSTC_RBUFF_SZ > LIN_DIAG_RFIFO_NOT_DEF)
        Lin_DiagTxFifoRdIdx    = 0U;
        Lin_DiagTxFifoWrIdx    = 0U;
        Lin_DiagRxFifoLvl      = 0U;
      #endif /* End of #if (_DGNSTC_RBUFF_SZ > LIN_DIAG_RFIFO_NOT_DEF) */
      
		  /* UTP AI00058380 */
      #if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) )
        #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)
          for ( nloop = 0U; nloop < (uint8)( LIN_SYS_CFG_NUM_OF_EVNT_FRMS ); nloop++ )
          {
            Lin_EventCache[nloop] = Lin_SignalMsgId [(Lin_EvntSchTbl[nloop].frm_id)];
          }
        #endif /* */
      #endif /* */
		 
      
    #endif/* LIN_V_2_1 */
  #endif/* Diagnostic support */

  #ifdef _IFC_SLAVE
    /* No frame transmission at the moment, therefore initialize the states
        and clear the bits for wake handling.
    */
    /* TBC */   
    wkup_bit3      = 0U;
    /* TBC */   
    Lin_StateMachine.Lin_CommState    = (LIN_COMM_STATE)LIN_IDLE;/*RCV_BREAK;*/
    Lin_StateMachine.Lin_BrkSyncState = LIN_BRK_SYNC_IDLE;
    
    #if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      /* Reset wakeup counter enable flag.
          This flag is used to measure the elapsed time after sending wakeup  
          frame by slave.
      */
      /* TBC */   
      wkup_bit2      = 0U;
      /* TBC */ 
    #endif /*sleep/wakeup configuration support */
    #ifdef LIN_V_2_1
      #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 
       Lin_LastFrmId = LIN_INVALID_FRM_ID;
      #endif /*_DGNSTC_FRM_SPRT */
    #endif   /* LIN_V_2_1 */  
  #endif /* _IFC_SLAVE */  
  return ((l_bool) E_OK);
}
/******************************************************************************
** Syntax           : void l_ifc_init( l_ifc_handle iii )                    **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : l_ifc_handle iii                                       **
**                                                                           **
** Parameters (out) : None                                                   **
**                                                                           **
** Return value     : NULL in V2.0 and in V2.1 zero if the initialization    **
**                    was successful and non-zero if failed.                 **
**                                                                           **
** Description      : This API is called only at the time of LIN LLD         **
**                    initialization after l_sys_init API has been called.   **
**                    The function initializes the controller specified by   **
**                    the name iii, i.e. sets up internal functions          **
**                    such as the baud rate.                                 **
**                                                                           **
******************************************************************************/
#ifdef LIN_V_2_1
  l_bool l_ifc_init( l_ifc_handle iii )
#else
  void l_ifc_init( l_ifc_handle iii )
#endif /* End of #ifdef LIN_V_2_1 */
{
  #if( ( _DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) ||( _FEATURES == LIN_ALL_FEATURES_SUPPORTED ))
    #ifdef LIN_V_2_1
      /* Initialize TX and RX diagnostic circular FIFO and 
          related data-structures.   
      */
      ld_init( iii );
	#endif /* LIN_V_2_1 */
  #endif /*   _DGNSTC_FRM_SPRT... */
  
  /* For Master - The Timer should be configured for schedule ticks
      For Slave  - The Timer should be configured for timeout/wakeup/sleep 
      timings.
  */
  idl_config_timeout_tmr();

  /* Initialize the HW communication channel and associated interrupts.  */  
  idl_channel_init();
  
  /* Configure the communication channel as required for master to function   
      - 8 bit platforms: program UART in normal divider mode and disable
      Break /Sync detection
      - 16 bit platforms: program the desired USIC channel
  */
  /* Club this API with idl_channel_init for 8 bit */
  idl_config_channel();

  /* The following API calls initialize the timers for   
      1. Detection of Autobaud
      2. Timings for the Wakeup frames / Frame Time outs.
  */
  #ifdef _IFC_SLAVE  
    /* This counter is used in Autobaud detection. and gets cleared after a
        frame is received successfully.
    */
    Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;  
    /* Slave Autobaud detection configuration.
        This code configures the underlying module's Baud rate detection 
        features. 
        Following actions are performed within the IDL Layer
        1. The underlying timer module (if required) is configured in capture 
           mode .
        2. The break / sync detection feature (if available) are enabled.
        3. Any interrupts required to be initialized towards autobaud detection 
           is initialized.
    */
    idl_init_atbd_dtct();
  #endif/*_IFC_SLAVE */

  #ifdef LIN_V_2_1
    /* Connecting the LIN node to LIN bus is done by Lin_lConnect API.*/   
    return(Lin_lConnect((l_ifc_handle)iii));
  #endif /* End of #ifdef LIN_V_2_1 */ 
}

/******************************************************************************
** Syntax           : l_bool l_ifc_connect( l_ifc_handle iii )               **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : l_ifc_handle iii                                       **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : Zero if the "connect operation" was successful and     **
**                    non-zero if the "connect operation" failed.            **
**                                                                           **
** Description      : The API is called at the time of interface             **
**                    initialization.                                        **
**                      - This API connects the interface to LIN cluster.    **
**                      - IMP: This API must be called after calling         **
**                      l_ifc_disconnect API in 2.0.                         **
**                                                                           **
**                      NOTE: In v2.1 this API is not available.             **
**                      Therefore Interrupts are enabled via a call to       **
**                      API "l_sys_irq_restore".                             **
**                                                                           **
******************************************************************************/
#ifdef LIN_V_2_1
  static l_bool Lin_lConnect (l_ifc_handle iii)
#else
  l_bool l_ifc_connect (l_ifc_handle iii)
#endif /* #ifdef LIN_V_2_1 */
{
  iii = (l_ifc_handle)E_OK;/*0;*/
  
  /* API to configure the Port Pins */  
  idl_Port_Connect( );
 
  /* Slave functionality begins here */
  #ifdef _IFC_SLAVE
    /* Configure the Autobaud detection mechanisms of the underlying peripheral
        This API call should enable the underlying device to an extent that 
        the next frame should be detected correctly.
    */
    idl_cfg_atbd_dtct();
    #ifndef LIN_V_2_1
      /* Enable autobaud detection via interrupt.
          This interrupt should be enabled to detect the break and sync symbols
          for next frame.
      */
      IDL_EN_ATBD_INT();
    #endif/* LIN_V_2_1 */  
    /* Initialize the timer so that the sleep / wakeup timeout gets activated. 
        This timer is used for:
        - sleep / wakeup functionality
        - the frame time out feature.
    */
    idl_load_new_timeout( ( uint16 ) LIN_DUMMY_TIMEOUT ); 
    #ifndef LIN_V_2_1
      /* Enable Sleep /Wakeup timeout ( timer ) interrupt */
      IDL_EN_TIMEOUT_INT();
    #endif /* #ifndef LIN_V_2_1 */  
  #endif /* _IFC_SLAVE */
   
  #ifndef LIN_V_2_1 
    /* Enable communication channel interrupt. */
    IDL_EN_CHANNEL_INT();
  #endif /* #ifndef LIN_V_2_1 */  
  /* Because of the interface type, there is no connection failure. 
      API always returns Connection success.
  */
  /*return ((l_bool)E_OK);*/
  return ((l_bool)iii);
}

/******************************************************************************
** Syntax           : l_bool l_ifc_disconnect( l_ifc_handle iii )            **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : l_ifc_handle iii                                       **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : Zero if the "disconnect operation" was successful and  **
**                    non-zero if the "disconnect operation" failed          **
**                                                                           **
** Description      : This API disconnects the interface from LIN cluster.   **
**                    NOTE: This API is not available in version 2.1,        **
**                    therefore a call to l_sys_irq_disable API should be    **
**                    disable the interrupts.                                **
**                                                                           **
******************************************************************************/
#ifdef LIN_V_2_0
l_bool l_ifc_disconnect (l_ifc_handle iii)
{   
  iii = (l_ifc_handle)0;

  /* Disconnect the Port Pins  */
  idl_Port_Disconnect( );

  /* Disable communication channel interrupt */
  IDL_DIS_CHANNEL_INT();
  
  #ifdef _IFC_SLAVE
    /* Disable Autobaud related interrupts */
    IDL_DIS_ATBD_INT();
    /* Disable Timeout interrupts. */
    IDL_STOP_TIMEOUT_INTR();
  #endif /* _IFC_SLAVE */
  return (E_OK);   
}
#endif /* LIN_V_2_0 */

/******************************************************************************
** Syntax           : Lin_lSignalRd                                          **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : handle to signal                                       **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : This API reads particular signal data, internal API.   **
**                                                                           **
******************************************************************************/
#if (_SIGNAL_PROTOTYPE == LIN_SIGNAL_API_DYNAMIC)
  #if((_SIG_RDWR_FUNC_SPRT == LIN_SIGNAL_RD_WR_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
    static uint16 Lin_lSignalRd( l_signal_handle sss )
    {
      uint8 ret_data_loc = 0U, ret_extrct_val = 0U; 
      uint8 frm_data_loc = 0U, frm_index ;
      uint8 frm_num, sig_offset, sig_size;
      
/*      #ifdef LIN_V_2_1  
        uint8 nloop; 
       #endif  #ifdef LIN_V_2_1 */
      
      uint16 ret_data = 0U, buff_indx_val;
    
      /* Retrieve the frame and signal info */    
      sig_offset = Lin_SignalDefinition[sss].offset;
      sig_size   = Lin_SignalDefinition[sss].size_bits;
      frm_num    = Lin_SignalDefinition[sss].asctd_frame_num;
    
      #ifdef LIN_V_2_1
       /* Get the index */
        frm_index = Lin_lGetFrmIdx(frm_num); 
      #else
        frm_index = frm_num;
      #endif   /* LIN_V_2_1 */
    
      /* 
         Calculate frame data offset, and data is read only if 
          updated data is available 
      */
      if ( ( Lin_FrmDataUpdtFlag[( frm_index >> 3U )] ) &
           (uint8)(( 1U << ( frm_index & 0x07U ) )) )
      {
        if ( Lin_FrmInfo[frm_index] & ((uint8)(LIN_SYS_FRM_INFO_OFFSET_MSK)) )
        {
          buff_indx_val = (uint16)( 
                                    (uint16)LIN_FRM_HIGHER_OFFSET + \
                                    (uint16)(Lin_FrmOffset[frm_index])                                  
                                  );
        }
        else
        {
          buff_indx_val = (uint16)(Lin_FrmOffset[frm_index]);
        }
        buff_indx_val += ((uint16)sig_offset >> (uint16)LIN_EXTRACT_BYTE_OFFSET) ;
    
        frm_data_loc = (uint8)( sig_offset & (uint8)LIN_EXTRACT_BIT_OFFSET );
    
        /* ret_extrct_val has the full data byte value (0xF2)     
            frm_data_loc refer to the current location of bit (e.g. 1st bit)
            ret_data contains the value of the signal, this starts with lsb 
            only.After every bit the location will be advanced by 1 bit. This 
            location will be maintained by ret_data_loc.
        */
        do
        {
          /* Read frame data byte */
          /* ret_extrct_val = 0xF2 */
          ret_extrct_val = (uint8)(Lin_FrmData[ buff_indx_val ]);
    
          /* Reset all other data bits except the current bit. */
          /* ret_extrct_val = 0x02. */
          ret_extrct_val = (( uint8 )( ( uint8 )ret_extrct_val & (( uint8 )(0x01U << frm_data_loc))));

          /*Move the bit to lsb location */
          /* ret_extrct_val = 0x01 */
          ret_extrct_val = (uint8)( (uint8)(ret_extrct_val >> (uint8)frm_data_loc));
          
          /* Place the extracted bit into app data to appropriate position */
          /* Add extracted value of ret_extrct_val to ret_data.          
              location is specified by ret_data_loc.
          */
          ret_data |= (uint16)( (uint16)ret_extrct_val << (uint16)ret_data_loc );
    
          /* The reading of data bit advances by 1 */
          frm_data_loc++;
          if ( (uint8)LIN_FRM_BIT_BOUNDARY == frm_data_loc )
          {
            buff_indx_val  += (uint16)LIN_FRM_NXT_BYTE;
            frm_data_loc   = 0U;
          }
          ret_data_loc++;
        } while ( ret_data_loc < sig_size );
      }
      return (ret_data);
    }
/******************************************************************************
** Syntax           : Lin_lSignalWr                                          **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : handle to signal                                       **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : This API writes particular signal data, internal API.  **
**                                                                           **
******************************************************************************/
    static void Lin_lSignalWr( l_signal_handle sss, uint16 v )
    {
      uint8        frm_data_loc ;
      uint8        frm_index    ;
      uint8        write_index  = 0U;
      uint8        write_mask   = 0U;
      l_bool       write_val    = (l_bool)0;
    
      uint8        frm_num      ;
      uint8        sig_offset   ;
      uint8        sig_size     ;
      uint16       buff_indx_val = 0U;
    
      /* Retrieve frame and signal info */
      frm_num    = Lin_SignalDefinition[sss].asctd_frame_num;
      sig_offset = Lin_SignalDefinition[sss].offset;
      sig_size   = Lin_SignalDefinition[sss].size_bits;
    
      #ifdef LIN_V_2_1
        frm_index = Lin_lGetFrmIdx (frm_num);
      #else
        frm_index = frm_num;
      #endif   /* LIN_V_2_1 */
    
      /* calculate frame data offset */
      if ( Lin_FrmInfo[frm_index] & (uint8)(LIN_SYS_FRM_INFO_OFFSET_MSK) )
      {
         buff_indx_val = (uint16)(                                             
                                   (uint16)LIN_FRM_HIGHER_OFFSET + \
                                   (uint16)(Lin_FrmOffset[frm_index])
                                 );                                            
        
      }
      else
      {
        buff_indx_val = (uint16)(Lin_FrmOffset[frm_index]);
      }
      buff_indx_val += ( (uint16)sig_offset >> (uint16)LIN_EXTRACT_BYTE_OFFSET );
    
      frm_data_loc = (uint8)( sig_offset & (uint8)LIN_EXTRACT_BIT_OFFSET );
    
      do
      {
        /* Crate mask to reset the current bit */
        write_mask = (uint8)( (uint16)0x01 << (uint16)frm_data_loc );
    
        /* Reset the bit in frame data */
        Lin_FrmData[buff_indx_val] &= (uint8)(( ~(uint16)( write_mask ) ));
    
        /*Extract the bit form application data */
        write_val = (l_bool)( ( v >> write_index ) & (uint16)LIN_BIT_0_EXTRACT );
    
        /*write bit to frame data */
        Lin_FrmData[buff_indx_val] |= ( uint8 )( (uint16)write_val << (uint16)frm_data_loc );
    
        frm_data_loc++;
        
        if ( frm_data_loc == (uint8)LIN_FRM_BIT_BOUNDARY )
        {
          frm_data_loc   = 0U;
          buff_indx_val += (uint16)LIN_FRM_NXT_BYTE;
        }
        write_index++;
      } while ( write_index < sig_size );
      return;
    }  
    /**************************************************************************
    ** Syntax           : l_bool_rd                                              **
    **                                                                           **
    ** Service ID       : none / NA                                              **
    **                                                                           **
    ** Sync/Async       : Synchronous                                            **
    **                                                                           **
    ** Reentrancy       : non-reentrant                                          **
    **                                                                           **
    ** Parameters(in)   : handle to signal                                       **
    **                                                                           **
    ** Parameters (out) : none                                                   **
    **                                                                           **
    ** Return value     : NA                                                     **
    **                                                                           **
    ** Description      : API Reads and returns the current value of the signal. **
    **                                                                           **
    ******************************************************************************/
    l_bool l_bool_rd( l_signal_handle sss )
    {
      l_bool      ret_data;
    
      #if (LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED)
        ret_data = ( l_bool ) Lin_lSignalRd( sss );
      #else
        sss = (l_signal_handle)0;
      #endif   /*LIN_SYS_CFG_NUM_OF_SIGS > 0 */
      return ret_data;
    }
    /******************************************************************************
    ** Syntax           : l_u8_rd                                                  **
    **                                                                           **
    ** Service ID       : none / NA                                              **
    **                                                                           **
    ** Sync/Async       : Synchronous                                            **
    **                                                                           **
    ** Reentrancy       : non-reentrant                                          **
    **                                                                           **
    ** Parameters(in)   : handle to signal                                       **
    **                                                                           **
    ** Parameters (out) : none                                                   **
    **                                                                           **
    ** Return value     : NA                                                     **
    **                                                                           **
    ** Description      : API Reads and returns the current value of the signal. **
    **                                                                           **
    ******************************************************************************/
    l_u8 l_u8_rd( l_signal_handle sss )
    {
      uint8        ret_data ;
    
      #if (LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED)
        ret_data = ( uint8 ) Lin_lSignalRd( sss );
      #else
        sss = (l_signal_handle)0;
      #endif   /*LIN_SYS_CFG_NUM_OF_SIGS > 0 */
      return ret_data;
    }    
    /******************************************************************************
    ** Syntax           : l_u16_rd                                                **
    **                                                                           **
    ** Service ID       : none / NA                                              **
    **                                                                           **
    ** Sync/Async       : Synchronous                                            **
    **                                                                           **
    ** Reentrancy       : non-reentrant                                          **
    **                                                                           **
    ** Parameters(in)   : handle to signal                                       **
    **                                                                           **
    ** Parameters (out) : none                                                   **
    **                                                                           **
    ** Return value     : NA                                                     **
    **                                                                           **
    ** Description      : API Reads and returns the current value of the signal. **
    **                                                                           **
    ******************************************************************************/
    l_u16 l_u16_rd( l_signal_handle sss )
    {
      uint16       ret_data;
    
      #if (LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED)
        ret_data = ( uint16 ) Lin_lSignalRd( sss );
      #else
        sss = (l_signal_handle)0;
      #endif   /*LIN_SYS_CFG_NUM_OF_SIGS > 0 */
      return ret_data;
    }
    /******************************************************************************
    ** Syntax           : l_bool_wr                                              **
    **                                                                           **
    ** Service ID       : none / NA                                              **
    **                                                                           **
    ** Sync/Async       : Synchronous                                            **
    **                                                                           **
    ** Reentrancy       : non-reentrant                                          **
    **                                                                           **
    ** Parameters(in)   : handle to signal                                       **
    **                                                                           **
    ** Parameters (out) : none                                                   **
    **                                                                           **
    ** Return value     : NA                                                     **
    **                                                                           **
    ** Description      : API writes value of the signal specified by 		       **
    **                  : the name sss with the value v.                         **
    **                                                                           **
    ******************************************************************************/
    void l_bool_wr( l_signal_handle sss, l_bool v )
    {
      #if (LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED)
        Lin_lSignalWr( sss, ( uint16 ) v );
      #else
        sss = (l_signal_handle)0;
        v   = (l_bool)0;
      #endif /*(LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED) */
    }             
    /******************************************************************************
    ** Syntax           : l_u8_wr                                                 **
    **                                                                           **
    ** Service ID       : none / NA                                              **
    **                                                                           **
    ** Sync/Async       : Synchronous                                            **
    **                                                                           **
    ** Reentrancy       : non-reentrant                                          **
    **                                                                           **
    ** Parameters(in)   : handle to signal                                       **
    **                                                                           **
    ** Parameters (out) : none                                                   **
    **                                                                           **
    ** Return value     : NA                                                     **
    **                                                                           **
    ** Description      : API writes value of the signal specified by 		       **
    **                  : the name sss with the value v.                         **
    **                                                                           **
    ******************************************************************************/
    void l_u8_wr( l_signal_handle sss, l_u8 v )
    {
      #if (LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED)
        Lin_lSignalWr( sss, ( uint16 ) v );
      #else
        sss = (l_signal_handle)0;
        v   = 0U;
      #endif   /*(LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED) */
    }
    /******************************************************************************
    ** Syntax           : l_u16_wr                                               **
    **                                                                           **
    ** Service ID       : none / NA                                              **
    **                                                                           **
    ** Sync/Async       : Synchronous                                            **
    **                                                                           **
    ** Reentrancy       : non-reentrant                                          **
    **                                                                           **
    ** Parameters(in)   : handle to signal                                       **
    **                                                                           **
    ** Parameters (out) : none                                                   **
    **                                                                           **
    ** Return value     : NA                                                     **
    **                                                                           **
    ** Description      : API writes value of the signal specified by 		       **
    **                  : the name sss with the value v.                         **
    **                                                                           **
    ******************************************************************************/
    void l_u16_wr( l_signal_handle sss, l_u16 v )
    {
      #if (LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED)
        Lin_lSignalWr( sss, ( uint16 ) v );
      #else
        sss = (l_signal_handle)0;
        v   = 0U;
      #endif   /*(LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED) */
    }
    /**************************************************************************
    ** Syntax           : l_bytes_rd                                         **
    **                                                                       **
    ** Service ID       : none / NA                                          **
    **                                                                       **
    ** Sync/Async       : Synchronous                                        **
    **                                                                       **
    ** Reentrancy       : non-reentrant?                                     **
    **                                                                       **
    ** Parameters(in)   : first byte to read from , number of bytes to read  **
    **                  : where data will be written                         **
    **                                                                       **
    ** Parameters (out) : none                                               **
    **                                                                       **
    ** Return value     : NA                                                 **
    **                                                                       **
    ** Description      : API Reads and returns the current value of the     **
    **                  : selected bytes in the signal specified by sss.     **
    **                                                                       **
    **************************************************************************/
    void l_bytes_rd( l_signal_handle sss, l_u8 start,
                     l_u8 count, l_u8 * const data1 )
    {
      #if (LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED)      
        uint8  frm_num   = 0U, read_data_index = 0U ; 
        uint8  frm_index = 0U /*, nloop */ ;
        uint16 buff_indx_val = 0U;
      
        /* Validate the input parameter */
        if ( data1 != ( void * )LIN_NULL_DATA )
        {
        	/* get the frame no. */
          frm_num = Lin_SignalDefinition[sss].asctd_frame_num;  
          #ifdef LIN_V_2_1
            frm_index = Lin_lGetFrmIdx (frm_num);                                    
          #else
            frm_index = frm_num;
          #endif   /* LIN_V_2_1 */
    
          if ( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_OFFSET_MSK )
          {
            buff_indx_val = (uint16)( (uint16)LIN_FRM_HIGHER_OFFSET +  \
                                      (uint16)Lin_FrmOffset[frm_index]\
                                    );
          }
          else
          {
            buff_indx_val = (uint16)Lin_FrmOffset[frm_index];
          }
          
          /* read the data from buffer from the offset requested */
          do
          {
            data1[read_data_index] = Lin_FrmData[(uint8)buff_indx_val + start];
            start++;
            read_data_index++;
          } while ( read_data_index < count );
        }
      #else
        sss   = (l_signal_handle)0;
        count = (uint8)data1[0];
        start = 0U;
      #endif   /*(LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED) */
    }
    /**************************************************************************
    ** Syntax           : l_bytes_wr                                         **
    **                                                                       **
    ** Service ID       : none / NA                                          **
    **                                                                       **
    ** Sync/Async       : Synchronous                                        **
    **                                                                       **
    ** Reentrancy       : non-reentrant                                      **
    **                                                                       **
    ** Parameters(in)   : first byte to read from , number of bytes to read  **
    **                  : where data will be written                         **
    **                                                                       **
    ** Parameters (out) : none                                               **
    **                                                                       **
    ** Return value     : NA                                                 **
    **                                                                       **
    ** Description      : API updates value of the selected bytes in the     **
    **                  : signal specified by sss                            **
    **                                                                       **
    **************************************************************************/
    void l_bytes_wr( l_signal_handle sss, l_u8 start,
                     l_u8 count, const l_u8 * const data1 )
    {
      #if (LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED)
        uint8  frm_num   = 0U, write_data_index = 0U;
        uint8  frm_index = 0U /* , nloop = (uint8)0*/;
        uint16 buff_indx_val = 0U;
        
        /* Validate the input parameter */
        if ( data1 != ( void * )LIN_NULL_DATA )
        {
          frm_num = Lin_SignalDefinition[sss].asctd_frame_num;    
          #ifdef LIN_V_2_1
            frm_index = Lin_lGetFrmIdx (frm_num);                                        
          #else
              frm_index = frm_num;
          #endif   /* LIN_V_2_1 */
    
          if ( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_OFFSET_MSK )
          {
            buff_indx_val = (uint16)( (uint16)LIN_FRM_HIGHER_OFFSET+  \
                                      (uint16)Lin_FrmOffset[frm_index] \
                                     );
          }
          else
          {
            buff_indx_val = (uint16)Lin_FrmOffset[frm_index];
          }
          
          /* Copy data to the specified locations */
          do
          {
            Lin_FrmData[(uint8)buff_indx_val + start] = data1[write_data_index];
            start++;
            write_data_index++;
          } while ( write_data_index < count );
        }
      #else
        sss   = (l_signal_handle)0;
        count = (uint8)data1[0];
        start = 0U; 
      #endif   /*(LIN_SYS_CFG_NUM_OF_SIGS > LIN_NO_SIGNAL_DEFINED) */
    }
  #endif   /*Signal support */
#endif /* _SIGNAL_PROTOTYPE */  
/******************************************************************************
** Syntax           : l_flg_tst                                              **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : handle No                                              **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : Returns a C boolean indicating the current state of    **
**                  : the flag specified by the name fff, i.e. returns zero  **
**                  : if the flag is cleared and non-zero otherwise          **
**                                                                           **
******************************************************************************/
l_bool l_flg_tst( l_flag_handle fff )
{
  uint8        ret_val /*, nloop = (uint8)0*/;

  /*
   get the offset  and return the flag value,
    can be used to check if data available in buffer.
  */
  #ifdef LIN_V_2_1
    fff = Lin_lGetFrmIdx(fff);
  #endif   /* LIN_V_2_1 */

  ret_val = Lin_FrmDataUpdtFlag[( fff >> 3U )];
  ret_val = ( ( ret_val >> ( (uint8)fff & 0x7U ) ) & 0x1U );
  return ( ( l_bool ) ret_val );
}

/******************************************************************************
** Syntax           : l_flg_clr                                              **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : handle No                                              **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : Sets the current value of the flag specified by the    **
**                  : name fff to zero                                       **
**                                                                           **
******************************************************************************/
void l_flg_clr( l_flag_handle fff )
{
	uint8 u8Data ;
	
  #ifdef LIN_V_2_1    
    fff = Lin_lGetFrmIdx(fff);                                          
  #endif   /* LIN_V_2_1 */

  /* Clear the frame information update data flag */
  u8Data = (uint8)( (uint16)0x01 << ( (uint16)fff & (uint16)0x07 ) );
  u8Data = ( uint8 ) (~(uint16)(u8Data) );
  Lin_FrmDataUpdtFlag[((uint8)fff >> 3U )] &= ( uint8 )u8Data;
}

/******************************************************************************
** Syntax           : l_ifc_wake_up                                          **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : handle no                                              **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : none                                                   **
**                                                                           **
** Description      : Sends wakeup frame in sleeping LIN cluster             **
**                                                                           **
******************************************************************************/
#if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
  void l_ifc_wake_up( l_ifc_handle iii )
  {
    iii = ( l_ifc_handle ) 0;  

  #ifdef _IFC_SLAVE
    /* Send Wake up Command only if Bus is sleeping */
    if ( (LIN_SLPNG == Lin_BusState ) )
    {	
      /* Set the state to recognize own wakeup signal 
          (in UART ISR--> IDLE branch)     
      */
      Lin_BusState                   = LIN_WKUP;      
      /* Set current state as idle */
      Lin_StateMachine.Lin_CommState = LIN_IDLE;
  
      /* Reset wakeup flag */
      wkup_bit2   = 0U;
      /* Variable indicated the wake up sequence count */
      Lin_WkupRetryCnt = (uint8)LIN_WKUP_CNT_1;
  
      /* Reset sync/break detection and enable baud rate RUN control bit
          After receiving this wakeup signal master starts to send header, so
          break/sync detection gets enabled in UART ISR after receiving the 
          wakeup signal.     
          For 8 bit platforms:
            - This wakeup signal has to be received. Hence UART RUN bit is set.
          For 16 bit platforms:
            - Send Wake signal.
      */
      idl_dis_atbd_dtct();
      
      /* Send wakeup signal from slave */
      IDL_SEND_WAKE_BYTE();
    }/*if sleeping */
  #endif/*_IFC_SLAVE */  
  }
#endif/*sleep/wake up configuration support */
/******************************************************************************
** Syntax           : l_ifc_read_status( l_ifc_handle iii )                  **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : l_ifc_handle iii                                       **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : interface status data                                  **
**                                                                           **
** Description      : Returns the status previous communication              **
**                                                                           **
******************************************************************************/
uint16 l_ifc_read_status( l_ifc_handle iii )
{
  uint16  ret_val;

  ret_val = Lin_FrmSts;
  iii     = (l_ifc_handle)0;
  
  /* Reset the flag so that it has valid information for the next frame.*/
  Lin_FrmSts = 0U;
  return (ret_val);
}

/******************************************************************************
** Syntax           : l_irqmask l_sys_irq_disable( void ) 					         **
**                                                                           **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : none                                                   **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : interrupt mask used to restore the interrupts which are**
**                    disabled from this API.                                **
**                                                                           **
**                    The return value is used in API "l_sys_irq_restore"    **
**                                                                           **
** Description      : Disables the UART /Timer interrupts.                   **
**                    This function returns the current status of interrupts **
**                    and disable all the peripheral interrupts except       **
**                    global interrupt.                                      **
**                    bit 0 --> communication channel interrupt              **
**                    bit 1 --> Primary Timer interrupt (T0/T1/T2)           **
**                    bit 2 --> Secondary Timer interrupt (T0/T1) (slave)    **
**                                                                           **
******************************************************************************/
l_irqmask l_sys_irq_disable( void )
{
  /* Store current status of global interrupt enable flag here. */
  l_irqmask lintrStat_Val = (l_irqmask) 0;
  
  /* Disables the following interrupts  
      1. channel interrupts
      2. Timer interrupts for Autobaud Timer
      3. Timeout interrupts.
  */
  lintrStat_Val = (l_irqmask)idl_dis_sys_ints();

  #ifdef LIN_V_2_1
    /* Set the bus to inactive state */
    Lin_FrmSts &= (uint16)~( (uint16)LIN_STAT_BUS_ACTVTY_VAL );
  #endif /* LIN_V_2_1 */
  
  return ((l_irqmask)lintrStat_Val);
}
/******************************************************************************
** Syntax           : void l_sys_irq_restore( l_irqmask previous )           **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : Mask to indicate the interrupts to enable              **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : None                                                   **
**                                                                           **
** Description      : re enables the interrupts.                             **
**                                                                           **
******************************************************************************/
void l_sys_irq_restore( l_irqmask previous )
{
  /* Restore the interrupts according to the mask provided. */
  idl_restore_sys_ints( previous );

  #ifdef _IFC_SLAVE
    /* Clear the counter, this is used to drive the state machine for autobaud   
        detection.
    */
    Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;
    wkup_bit2 = 0U;    
  #endif /*_IFC_SLAVE */
  
  /*Reset driver state so that next frame transmission /reception is ensured.*/   
  Lin_StateMachine.Lin_CommState = LIN_IDLE;/* RCV_BREAK; */
  /* No activity, when interrupts are enabled the scheduler starts because  
      ifc_curr_time_out_cntr > ifc_curr_slot_timeout
  */  
  Lin_CurrSlotTimeOut = 0U;
}

#ifdef LIN_V_2_1
  /****************************************************************************
  ** Syntax           : uint8 Lin_lGetFrmIdx( uint8 u8FrmId )                **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : Frame ID                                             **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : None                                                 **
  **                                                                         **
  ** Description      : Gets the index in the LIN_FrmTbl buffer              **
  **                                                                         **
  ****************************************************************************/  
  uint8  Lin_lGetFrmIdx(uint8 u8FrmId)
  { 
    uint8        frm_index ;
    uint8        nloop ;
     
    /* This code is required because frame IDs are not defined 
        sequentially.
         - The index nloop is used to access the flags related to data and  
           their offsets etc.
         - Loop Checks the position of frm_id in Lin_FrmTbl from 0 to 
           LIN_SYS_NUM_FRMS   
         - Lin_FrmTbl stores the index of the frame id and is not 
           continuous. 
    */
    frm_index = (uint8)LIN_SYS_NUM_FRMS ;
    
    for (nloop = 0U ; nloop < (uint8)LIN_SYS_NUM_FRMS; nloop++ )
    {
      if ( Lin_FrmTbl[nloop] == u8FrmId )
      {
        frm_index = nloop;
        break;
      }
    }
    return (frm_index);
  } 
#endif /* LIN_V_2_1 */

#if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED)
  /****************************************************************************
  ** Syntax           : void Lin_lRespFrmUpdate(void)                        **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : 1 - Set Data , 0 - Reset Data                        **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : None                                                 **
  **                                                                         **
  ** Description      : Updates the response error in the frame buffer       **
  **                                                                         **
  ****************************************************************************/ 
  void Lin_lRespFrmUpdate(uint8 u8Data)
  {
    uint16       buff_indx = 0U;      
    uint8        frm_index ; 
      
    #ifdef LIN_V_2_1      
      /* UTP AI00056226 is fixed */
      frm_index = Lin_lGetFrmIdx((uint8)Lin_Status_FrmID);
    #else
      /* frame IDs are in sequence order in V2.0*/
      frm_index = Lin_Status_FrmID;
    #endif /* LIN_V_2_1 */
    
    /* Response Error frame should be defined in slave */
    #ifdef LIN_V_2_1 
      if((uint8)LIN_SYS_NUM_FRMS != frm_index)
    #endif /* LIN_V_2_1 */  	
      {	
        /* Get frame data offset to LLD_sys_frm_data.       
            Offsets are maintained in LIN_sys_frm_offset in an 
            optimized manner. Check If the data is placed at an offset > 255. 
            ( the flag is set in 'LIN_sys_frm_info')
        */
        if ( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_OFFSET_MSK )
        {
          buff_indx = (uint16)((uint16)LIN_FRM_HIGHER_OFFSET + (uint16)Lin_FrmOffset[frm_index]);
        }
        else
        {
          buff_indx = Lin_FrmOffset[frm_index];
        }
        buff_indx += (uint16)(((uint16)_IFC_RESP_ERR_FRM_BIT_LOC >> 3U ));  
        
        /* UTP AI00056226 is fixed */
        if(u8Data)
        {	
          /*
           Set the bit (_IFC_RESP_ERR_FRM_BIT_LOC) of frame
           (_IFC_RESP_ERR_FRM_NUM) defined in LIN_CFG.h file
          */
          Lin_FrmData[buff_indx] |=
          (uint8)(( 1U <<  ((uint8)_IFC_RESP_ERR_FRM_BIT_LOC & 0x7U)));
             
          Lin_FrmDataUpdtFlag[( frm_index >> 3U )] |=
              (uint8)(( 1U <<  ( frm_index & 0x07U ) ));
        } 
        else
        { 
          Lin_FrmData[buff_indx] &=
          (uint8)(~(uint8)(( 1U << ((uint8)_IFC_RESP_ERR_FRM_BIT_LOC & 0x7U))));      	
        }	   
      }       
  }
#endif /*  (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED) */   
/*lint +e438 */ 
/*lint +e550 */


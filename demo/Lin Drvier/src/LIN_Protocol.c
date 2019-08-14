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
**  FILENAME  : Lin_protocol.c                                               **
**                                                                           **
**  VERSION   : 1.6.0                                                        **
**                                                                           **
**  DATE      : 2011.09.03                                                   **
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
 * V1.6.0: 2011.09.03, PM  : UTP ID AI00059574 , AI00059573, AI00059568 fixed.
 * V1.5.0: 2011.11.01, PM  : UTP ID AI00058130 and AI00058345 and 
                             AI00058346 and AI00058362 is fixed. 
 * V1.4.0: 2010.12.03, PM  : UTP AI00057719  and AI00056260 fixed  and
                             functional NAD supported
 * V1.3.1: 2010.09.09, PM  : UTP ID AI00056413 fixed.  
 * V1.3.0: 2010.09.08, PM  : UTP AI00056225 and AI00056226 is fixed.
 * V1.2.0: 2010.08.12, PM  : UTP AI00056180 (Synchronization issue) is fixed.
 * V1.1.0: 2010.07.23, PM  : Updated for UTP ID: AI00055629 and AI00055632
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
/*lint +elib(537) */
/*lint +esym(961,19.7) */
/*lint +esym(961, 19.13)*/ 
/*lint -e745 */
/*lint -e939 */
/*lint -e957 */
/*lint -e10 */
/*lint -e69 */
/*lint -e63 */
/*lint -e48 */
/*lint -e151 */
/*lint -e923 */
/*lint -e539 */      /* positivie indentation */
/*lint -e725 */      /* positivie indentation */
/*lint -e525 */      /* negative indentation */
/*lint -e529 */      /* Warning 529: Symbol 'FAR'not subsequently referenced */


/******************************************************************************
**                      Imported Compiler Switch Check                       **
******************************************************************************/

/******************************************************************************
**                      Private Macro Definitions                            **
******************************************************************************/
#define   _FIFO              (0U)
/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/

/******************************************************************************
**                      Private Function Declarations                        **
******************************************************************************/
static void  Lin_lParityCal(void);
static void  Lin_lPIDHandleTx(void);
static void  Lin_lPIDHandle(uint8 rcvd_data);
static void  Lin_lHandleIDLE(uint8 rcvd_data);

#if  (_FIFO == 1U)
  static void Lin_lChkSumCalc(uint8 *FrmData , uint8 u8FrmLen);
#else
  static void  Lin_lChkSumCalc(uint8 Data); 
#endif /* _FIFO */

#ifdef _IFC_SLAVE
  static void  Lin_lDiagErrorSts(void);
  static void  Lin_lTpTimeOutChk(void);
  static void  Lin_lSetFrameEror( void);
  #ifdef LIN_V_2_1       
    #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))      
      static void  Lin_lChkDiagResp(void);
    #endif/* _DGNSTC_FRM_SPRT */
  #endif /* LIN_V_2_1 */    
#endif /* #ifdef _IFC_SLAVE    */

static void  Lin_lHandleTxChkSum(void);
static void  Lin_lHandleRxChkSum(void);
static void  Lin_lEventFrmDataCopy(void);
static uint8 Lin_lSlaveTimeOutWakUp(void);
static void  Lin_lSlaveTimeOutActive(void);
static uint8 Lin_lPIDHandleEvntFrmProc(void);
static void  Lin_lReadTpBuffer(uint8 *u8Data);
static void  Lin_lTpRxMsgPrc(uint8 rcvd_data);  
static void  Lin_lHandleRxData(uint8 rcvd_data);
static void  Lin_lHandleTxData(uint8 rcvd_data);
static void  Lin_lHandleRxTxChkSum(uint8 rcvd_data);
static uint8 Lin_lPrepareTpBuffer( uint16 *u16Len , uint8 *u8Data);
/******************************************************************************
**                      Global Constant Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Global Variable Definitions                          **
******************************************************************************/
/*-----------------------------------------------------------------------------
*Variable Name : checksum                                                     *
*Type          : unsigned short                                               *
*Description   : This variable contains checksum for current frame            *
-----------------------------------------------------------------------------*/
uint16       Lin_ChkSum;

/*-----------------------------------------------------------------------------      
* Variable Name : Lin_FrmType                                                 *      
* Type          : unsigned char                                               *      
* Description   : This variable denotes the frame type (unconditional,        *      
*                 event triggered, sporadic) for current frame                *      
-----------------------------------------------------------------------------*/      
LIN_FRM_TYPE Lin_FrmType;                                                 

/*-----------------------------------------------------------------------------      
* Variable Name : Lin_StateMachine                                            *      
* Type          : Structure                                                   *      
* Description   : This variable indicates the LIN state machine.              *      
-----------------------------------------------------------------------------*/     
LIN_SLAVE_STATE_INFO    Lin_StateMachine ;

/*-----------------------------------------------------------------------------
*Variable Name : Lin_RcvedFrmId                                               *
*Type          : union / custom                                               *
*Description   : This bit definitions are used to calculate the parity bits   *
                 of frame ID.                                                 *
-----------------------------------------------------------------------------*/
T_SFR t_Lin_RcvedFrmId;
#define Lin_RcvedFrmId (t_Lin_RcvedFrmId.ch)

#define bit0 (t_Lin_RcvedFrmId.b.b0)
#define bit1 (t_Lin_RcvedFrmId.b.b1)
#define bit2 (t_Lin_RcvedFrmId.b.b2)
#define bit3 (t_Lin_RcvedFrmId.b.b3)
#define bit4 (t_Lin_RcvedFrmId.b.b4)
#define bit5 (t_Lin_RcvedFrmId.b.b5)
#define bit6 (t_Lin_RcvedFrmId.b.b6)
#define bit7 (t_Lin_RcvedFrmId.b.b7)

#ifdef _IFC_SLAVE  
  /*---------------------------------------------------------------------------
  * Variable Name : Lin_AutoBaudBitCtr                                        *
  * Type          : unsigned char                                             *
  * Description   : Internal variable to support break/sync sequence detection*
  *                 and autobaud programming.                                 *
  ---------------------------------------------------------------------------*/
  uint8        Lin_AutoBaudBitCtr;
  
  /*---------------------------------------------------------------------------
  * Variable Name : Lin_BitTime                                               *
  * Type          : unsigned short                                            *
  * Description   : This variable contains the value of bit time derived from *
  *                 SYNC field of current frame, and is used for autobaud     *
  *                 calculations.                                             *
  ---------------------------------------------------------------------------*/
  uint16       Lin_BitTime;
  
  #if((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
    /*-------------------------------------------------------------------------
    * Variable Name : Lin_4sIdle                                              *
    * Type          : unsigned char variable                                  *
    * Description   : The flag is used to indicate if slave is in sleep state *
    *                 as a result of bus being idle for more than 4 seconds.  *
    *                                                                         *
    -------------------------------------------------------------------------*/
    uint8     Lin_4sIdle;    
    
    /*-------------------------------------------------------------------------
    * Variable Name : Lin_WkupRetryCnt                                        *
    * Type          : unsigned char variable                                  *
    * Description   : The variable indicates the wake up re try count.        *    
    *                                                                         *
    -------------------------------------------------------------------------*/
    uint8     Lin_WkupRetryCnt;
  #endif /* Sleep/Wakeup */  
#endif /* #ifdef _IFC_SLAVE */

/*-----------------------------------------------------------------------------
* Variable Name : Lin_FrmBuffIdx                                              *
* Type          : unsigned short                                              *
* Description   : This variable contains the index of last data transmitted   * 
*                 from the frame buffer.                                      *
-----------------------------------------------------------------------------*/
uint16       Lin_FrmBuffIdx;

/*-----------------------------------------------------------------------------
*Variable Name : last_tx_data                                                 *
*Type          : unsigned char                                                *
*Description   : This variable contains last transmitted data if the interface* 
*                is publisher.                                                *
-----------------------------------------------------------------------------*/
uint8        Lin_LastTxData;
/*-----------------------------------------------------------------------------
*Variable Name : num_of_bytes                                                 *
*Type          : unsigned char                                                *
*Description   : This variable contains the number of bytes transmitted       *
*                from current frame                                           *
-----------------------------------------------------------------------------*/
uint8        Lin_NumofBytesTx;
/*-----------------------------------------------------------------------------
*Variable Name : null_tx_data                                                 *
*Type          : unsigned char                                                *
*Description   : This variable indicates if dummy data should be transmitted  *
*                instead of actual data                                       *
*                0-> data available, 1 --> no real data                       *
-----------------------------------------------------------------------------*/
uint8        Lin_FrmTxDataPtr;
/*-----------------------------------------------------------------------------
*Variable Name : Lin_FrmLen                                                   *
*Type          : unsigned char                                                *
*Description   : This variable indicates length of payload in a frame         *
-----------------------------------------------------------------------------*/
uint8        Lin_FrmLen;
/*-----------------------------------------------------------------------------
*Variable Name : Lin_FrmTxMode                                                *
*Type          : unsigned char                                                *
*Description   : This variable indicates the Frame Tx direction.              *
                 0--> IDLE, 1 -->Tx, 2 --> Rx                                 *
-----------------------------------------------------------------------------*/
uint8        Lin_FrmTxMode;
/*-----------------------------------------------------------------------------
*Variable Name : Lin_FlgIdx                                                   *
*Type          : unsigned char                                                *
*Description   : This variable contains the index to update / access the      *
*                following flags:                                             *
*                LLD_frm_tx_buff_use_flg,                                     *
*                LLD_frm_data_updt_flg, and                                   *
*                LLD_frm_data_usage_flg.                                      *
-----------------------------------------------------------------------------*/
uint8        Lin_FlgIdx;
/*-----------------------------------------------------------------------------
*Variable Name : Lin_FlagVal                                                  *
*Type          : unsigned char                                                *
*Description   : This flag contains the value to update (reset/set) the flags *
*                following flags:                                             *
*                LLD_frm_tx_buff_use_flg,                                     *
*                LLD_frm_data_updt_flg, and                                   *
*                LLD_frm_data_usage_flg.                                      *
-----------------------------------------------------------------------------*/
uint8        Lin_FlagVal;

#if  ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) || (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED))
  /*---------------------------------------------------------------------------
  * Variable Name: first_byte_val                                             *
  * Type         : unsinged char                                              * 
  * Description  : The first byte value will be saved to detect master sleep  *
  *                command                                                    *  
  ---------------------------------------------------------------------------*/
  uint8        Lin_RxFirstByte;
#endif /* _WKUP_SLP_SPRT */

#if  (_FIFO == 1U)
  /*---------------------------------------------------------------------------
  * Variable Name: Lin_TempRxData                                             *
  * Type         : unsinged char array                                        *  
  * Description  : The  variable holds the data read from LIN Master,         *
  *                when FIFO is enabled                                       *  
  ---------------------------------------------------------------------------*/
  uint8  Lin_TempRxData[8];
  /*---------------------------------------------------------------------------
  * Variable Name: Lin_TempTxData                                             *
  * Type         : unsinged char                                              * 
  * Description  : The  variable holds the data to be transmitted to LIN      *
  *                Master when FIFO is enabled                                *  
  ---------------------------------------------------------------------------*/
  uint8  Lin_TempTxData[8];
  /*---------------------------------------------------------------------------
  * Variable Name: Lin_RxDataPtr                                              *
  * Type         : unsinged char                                              * 
  * Description  : The variable holds the pointer to the receive buffer       *
  *                command                                                    *  
  ---------------------------------------------------------------------------*/
  uint8  *Lin_RxDataPtr ;
#endif /* _FIFO */

/*-----------------------------------------------------------------------------
*Variable Name : global_flag_val                                              *
*Type          : unsigned char                                                *
*Description   : This flag used in the timeout interrupt to indicate if       *
*                driver should enter a sleep mode at the end of 4 second idle.*
-----------------------------------------------------------------------------*/
uint8 global_flag_val = (uint8)0;

/*-----------------------------------------------------------------------------
*Variable Name : Lin_BaudRate                                                 *
*Type          : unsigned int                                                 *
*Description   : This variable holds the baud rate calculated by the driver   *
-----------------------------------------------------------------------------*/
uint32 Lin_BaudRate;

#ifdef _LIN_FRAME_CNT 
  #ifdef LIN_V_2_1
  /*---------------------------------------------------------------------------
  *Variable Name : Lin_FrameIDCnt                                             *
  *Type          : unsigned int                                               *
  *Description   : This holds a count, which indicates successful transmission* 
  *                for a particular ID                                        *
  ---------------------------------------------------------------------------*/
  uint16 Lin_FrameIDCnt[LIN_SYS_NUM_FRMS];
  #endif /*  LIN_V_2_1*/
#endif /* _LIN_FRAME_CNT */

/*-----------------------------------------------------------------------------
* Variable Name : Lin_FrmId                                                   *
* Type          : unsigned char                                               *
* Description   : This variable contains the current PID,(incl. parity bits.) *
-----------------------------------------------------------------------------*/
uint8        Lin_FrmId;

#ifdef LIN_V_2_1
  #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 
    /*-------------------------------------------------------------------------
    * Variable Name : Lin_LastFrmId                                           *
    * Type          : unsigned char                                           *
    * Description   : This variable contains the  PID                         *
    -------------------------------------------------------------------------*/
    uint8        Lin_LastFrmId; 
  #endif /* _DGNSTC_FRM_SPRT */
#endif /* #ifdef LIN_V_2_1 */
/*****************************************************************************/

/******************************************************************************
**                      Private Constant Definitions                         **
******************************************************************************/

/******************************************************************************
**                      Imported Variable Definitions                        **
******************************************************************************/
#if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED) 
  extern uint8  Lin_Status_FrmID;
  extern uint8  Lin_Status_FrmID_Index;
#endif   /* _IFC_RESP_ERR_FRM_NUM ... */     	                    

extern uint8    Lin_FrmId;
extern uint16   Lin_FrmSts;
extern uint8    Lin_TpRxSts;
extern uint8    Lin_TpTxSts;
#ifdef LIN_V_2_1
  #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 
    extern uint8    Lin_LastFrmId;
  #endif /* Diags */
#endif /* #ifdef LIN_V_2_1 */

extern volatile LIN_BUS_STATE   Lin_BusState;

#if ((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || \
     (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
  extern uint8  Lin_NAD;                           
  extern uint8  Lin_OldNAD;                           
  extern uint8  Lin_InitNAD;                           
  extern uint8  Lin_TempNAD;                     
  extern uint8  Lin_FuncReq;
  
  #if  (_TP_BUFF_MGMT  == 0U)       
    extern volatile uint8  Lin_DiagRxFifoLvl;
    extern uint8           Lin_DiagTxFifoLvl;
    extern uint8           Lin_DiagTxFifoRdIdx;
    extern uint8           Lin_DiagRxFifoWrIdx;
    extern uint8           Lin_DiagTxFifo[ ][LIN_DIAG_FRM_LEN];
    extern uint8           Lin_DiagRxFifo[ ][LIN_DIAG_FRM_LEN];
    extern LIN_DIAG_FIFO_STAT Lin_DiagFifoSts;
  #endif /* _TP_BUFF_MGMT  */  
  
  #ifdef LIN_V_2_1
     extern uint8        Lin_TpSendMsgPndg;
    extern uint8         Lin_TpRxMsgPndg;
    extern uint16        *Lin_TpRxLenPtr;
    extern uint16        Lin_TpNoBytesTobeRxed;
    extern uint8         Lin_TpRxFirstFrm;
    extern uint8         Lin_TpRxFrmSerialNo;
    extern uint8         *Lin_TpTxDataPtr;
    extern uint16        Lin_TpBytesTxed;
    extern uint8         Lin_TpTxFirstFrm;
    extern uint8         *Lin_TpRxDataPtr;
    extern uint16        Lin_TpBytesRxed;
        
    #if  (_TP_BUFF_MGMT  == 1U)
      extern uint16      Lin_TpTxLenPtr;      
      extern uint8       Lin_TpRxWrIndex;
      extern uint8       Lin_TpTxRdIndex;
      extern uint8       Lin_TpRxBuff[ ];
      extern uint8       Lin_TpTxBuff[ ];        
    #else
      extern uint16      *Lin_TpTxLenPtr;
    #endif /* _TP_BUFF_MGMT */    
    
    extern uint16          Lin_TpRxTimeOutCntr;
    extern uint16          Lin_TpTxTimeOutCntr;
    extern uint8           Lin_TpTxFrmSerialNo;
    extern uint8           Lin_TpRxFrm;
  #endif /* 2.1 */  
#endif /* _DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED*/

extern uint8           Lin_BufferDataLost[ ];
extern uint8           Lin_CurrSlotTimeOut;
extern uint16          Lin_CurrTimeOutCntr;
extern uint8           Lin_BufferInUse[ ];

extern T_SFR           t_Lin_WkupCnt;
#define Lin_WkupCnt    (t_Lin_WkupCnt.ch)
#define wkup_bit0      (t_Lin_WkupCnt.b.b0)
#define wkup_bit1      (t_Lin_WkupCnt.b.b1)
#define wkup_bit2      (t_Lin_WkupCnt.b.b2)
#define wkup_bit3      (t_Lin_WkupCnt.b.b3)
#define wkup_bit4      (t_Lin_WkupCnt.b.b4)

/******************************************************************************
**                      Imported function Definitions                        **
******************************************************************************/
#ifdef LIN_V_2_1
  extern uint8  Lin_lGetFrmIdx(uint8 u8FrmId);
#endif /* #ifdef LIN_V_2_1  */

extern void   Lin_lRespFrmUpdate(uint8 u8Data); 
extern uint8  Lin_TpCallBack ( uint8 *lRxBuff ,  
               	               uint16  lRxLen , 
      	                       uint8  *lTxBuff ,
      	                       uint16  *lTxLen 
      	                      );
      	                     
#if  (_TP_BUFF_MGMT  == 0U)      	                     
  extern void lUpdate_DiagTxFifo( uint8 NAD, uint8 PCI, uint8 SID, 
                                uint8 supplier_id1, uint8 supplier_id2,  
                                uint8 function_id1,uint8 function_id2, 
                                uint8 new_NAD 
                               );                     
#endif /* #if  (_TP_BUFF_MGMT  == 0U) */

#ifdef _IFC_SLAVE
  #if ((_FEATURES == LIN_ALL_FEATURES_SUPPORTED)  || \
      (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED)  || \
      (_DGNSTC_ASGN_FRM_SPRT == 1U))
    extern uint8 Lin_lHandleNodeConfig(uint8 *u8Data );
    extern uint8 Lin_lAssignID(uint8 drvd_id0 , uint8 *u8Data); 
  #endif  /*_DGNSTC_FRM_SPRT  */ 
#endif /* _IFC_SLAVE */

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/


/******************************************************************************
**                      Global Function Definitions                          **
******************************************************************************/


/******************************************************************************
** Syntax           : COMM_HANDLER                                           **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : NA                                                     **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : ISR to handle the data transfer                        **
**                                                                           **
******************************************************************************/
/* Note 960: Note 960: Violates MISRA Required Rule 18.4, unions shall not be used */
/* [MISRA 2004 Rules 18.4] */
/*lint -esym(960,18.4) */
/*lint -e(102) */
INTERRUPT (LIN_1INT) void COMM_HANDLER()
/*lint +esym(960,18.4) */
/*lint +esym( 533, INTERRUPT* )*/
{
  volatile uint8 rcvd_data = (uint8)0;
  uint8  frm_index ;   
  /*
   perform any platform specific activity
    e.g. : Save any paging or other registers req inside the ISR
   */
  IDL_ISR_PRE_HOOK();
  
  /*If Sync Break detected */
  #ifdef _IFC_SLAVE
    if(IDL_CHK_BRK_RECEPTION())    	
    {
    	/* UTP AI00059574 fixed */
      IDL_CLR_BRK_RECEPTION();
      /* Clear Format Error Interrupts */
      /*USIC_CHANNEL_PTR->PSCR.B.CST5 = 1U;*/      
      
      IDL_CLR_SYNC_ERR_INT( );
      /* Clear Format Error Interrupts */
      
      /* Break detected. Prepare for Baud rate calculation. */
      IDL_CNF_BRK_DTCT();
    
      /* UTP AI00057719 fixed Lin_AutoBaudBitCtr++; */
      Lin_AutoBaudBitCtr = 1U;
      
      Lin_StateMachine.Lin_CommState    = (LIN_COMM_STATE)LIN_IDLE;
      Lin_StateMachine.Lin_BrkSyncState = LIN_DETECT_SYNC;
      
      /* Some activity detected on bus, so reset the bus Idle flag */
      /* UTP AI00059573 fixed */
      Lin_4sIdle = 0U;  
      
      /* Bus is active as it has got Break Signal */
      Lin_BusState                      = LIN_ACTIVE;
     
    
      /*
       frame transmission is on going this is reset in RCV_CHKSUM branch,
        used to check for time out in Time out ISR.
      */
      wkup_bit3 = (uint8)1;
    	
    	/* current frame timeout, for response depending on the frame length.*/    	
    	/* UTP AI00056260 fixed */
    	/* First calculate the timing for 2 byte duration, SYNC and PID*/
    	/* UTP AI00059574 fixed */
    	Lin_CurrSlotTimeOut = (uint8)(((50000U) /Lin_BaudRate) ) + 1U;
    	/* Timer base defines the count value.*/
    	Lin_CurrSlotTimeOut = (Lin_CurrSlotTimeOut / _TMR_BASE);
                         
      /* reset current frame elapsed time */
      Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;       
      
      /* Frame transmission is active, start timer */      
      idl_load_new_timeout( (LIN_CFG_TMR_TICKS) );
            
      /* Read the byte 0x00 of Break */
      /*lint -e(102) */
      rcvd_data    = (uint8)IDL_READ_CHANNEL_BUFF();
      /*lint -e(102) */
      IDL_CLR_CHANNEL_RX_INT();      
    }  
    /*lint -esym(960,12.4) */    
    if( (  /*lint -save -e506 */ (USIC_CHANNEL_PTR->PSR.B2.FER0 != 0U) ) ||
    	   ( (USIC_CHANNEL_PTR->PSR.B2.RNS != 0U)) ||
    	   ( (USIC_CHANNEL_PTR->PSR.B2.DLIF != 0U) )  /*lint -restore */
    	)    
    {
    /*lint +esym(960,12.4) */	
      /* Clear Format Error Interrupts, UTP AI00057719 fixed  */      
      USIC_CHANNEL_PTR->PSCR.B.CST5 = 1U;
      USIC_CHANNEL_PTR->PSCR.B.CST4 = 1U ; 
      USIC_CHANNEL_PTR->PSCR.B.CDLIF = 1U ;       
      
      {
        /* Clear Time Out */
        wkup_bit3 = (uint8)0;
         
        #ifdef LIN_V_2_1
          /* Bus is in inactive state, may be set in T2 ISR falling edge */
          /* Lin_FrmSts &= ~( LIN_STAT_BUS_ACTVTY_VAL );*/
        #endif/* LIN_V_2_1 */
                  
        /* Update with flag i.e. LLD is not using the frame data buffer */
        #ifdef LIN_V_2_1
          frm_index = Lin_lGetFrmIdx(Lin_RcvedFrmId);
        #else
          frm_index = Lin_RcvedFrmId;
        #endif/* LIN_V_2_1 */
                        
        /* Update with flag i.e. LLD is not using the frame data buffer */
        Lin_BufferInUse[( frm_index >> (uint8)3 )] &= 
                         (uint8)(~((uint8)( (uint8)1 << \
                         (uint8)(( frm_index & (uint8)0x07 ))) ));       
                 
        #ifdef LIN_V_2_1
          /* bus is in inactive state */
          Lin_FrmSts &= ((~(uint16)( LIN_STAT_BUS_ACTVTY_VAL )));
        #endif   /* LIN_V_2_1 */          
        
        #ifdef _IFC_SLAVE
          if((LIN_PID != Lin_StateMachine.Lin_CommState) &&
          	 (LIN_IDLE != Lin_StateMachine.Lin_CommState)
          	)
          	{
              Lin_lSetFrameEror();
            }      
          /*
            Need to clear the timeout counter for every byte of transmission 
             to be in active state. 
             Otherwise the interface will enter sleep state after 4sec timeout 
          */
          Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
          
          /* clear the counter, this is used in Auto Baud interrupt */
          idl_Restart_AutoBaud( );      
          Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;                 
        #endif /* _IFC_SLAVE */          
        
        /* Reset The status */
        Lin_StateMachine.Lin_CommState = LIN_IDLE;        
      }	  
      /* Clear Format Error Interrupts */    	
    }/* */	
  #endif /* #ifdef _IFC_SLAVE   */
  
  if ( IDL_CHANNEL_RX_INT() )
  {
  	/* read data from UART RX register */	
  	rcvd_data    = (uint8)IDL_READ_CHANNEL_BUFF();  	
  	
  	/* clear receive interrupt status flag */
  	IDL_CLR_CHANNEL_RX_INT();
  	
    #ifdef LIN_V_2_1
      /* bus is in active state */
      Lin_FrmSts |= (uint16)LIN_STAT_BUS_ACTVTY_VAL;
    #endif/* LIN_V_2_1 */
      	
  	switch ( Lin_StateMachine.Lin_CommState )
  	{
  	  case LIN_IDLE:
  	  {
  	    Lin_lHandleIDLE(rcvd_data);		
  	  }
  	  break;
  	       
  	  case LIN_PID: 
  	  {
 	      Lin_lPIDHandle(rcvd_data);
  	  }
  	  break;
  	  
  	  case LIN_RX_DATA:
  	  {	
  	    Lin_lHandleRxData(rcvd_data);		 	  
  	  }
  	  break;
  	    	
  	  case LIN_TX_DATA:
  	  {		
  	    Lin_lHandleTxData(rcvd_data);	
  	  }
  	  break;  	  
  	  
 	    case LIN_RX_CHKSUM:
  	  {		
  	  	/* The below line should not be removed. These lines are commented
  	  	   for LIN specification confirmance.
  	  	*/
  	  	/* AI00056413 fixed */
  	  	#if  (_FIFO == 1U)
  	  	  if (rcvd_data == (uint8)Lin_ChkSum)
  	  	#endif /* #if  (_FIFO == 1U) */	
  	  	{
  	  		Lin_lHandleRxTxChkSum(rcvd_data);	
  	  	}
  	  }
  	  break; 
  	  
 	    case LIN_TX_CHKSUM:
      {		
        Lin_lHandleRxTxChkSum(rcvd_data);	
      }
  	  break;   
  	  
      default:
        break;  	  	  
  	} /* End of switch */ 
  }/*End of UART receive interrupt */	    	  	
  
  if ( IDL_CHANNEL_TX_INT() )
  {
    /* clear UART TX interrupt status flag */
    IDL_CLR_CHANNEL_TX_INT();
  }
  IDL_ISR_POST_HOOK();
}
   
/******************************************************************************
** Syntax           : AUTOBAUD_EVNT_HANDLER                                  **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : NA                                                     **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : autobaud ISR to handle the BRK/SYNC detection and baud **
**                    rate measurements.                                     **
**                                                                           **
******************************************************************************/
#ifdef _IFC_SLAVE
/*lint -e(102) */
/*lint -e31 */
INTERRUPT (LIN_0INT) void AUTOBAUD_EVNT_HANDLER(void)
{
  uint8 scu_page ;
  /*
   perform any platform specific activity
   e.g. : Save any paging or other registers req inside the ISR
  */
  IDL_ISR_PRE_HOOK();
  /*
   8/16 bit platforms: Save Context here if needed
   ideally, every context change should happen once every time an
   SFR is accessed or set, in order to ensure re-entrancy.
   */
  scu_page = idl_change_context( ); 
   
  if ( IDL_CHK_ATBD_INT() )
  {	
    #ifdef LIN_V_2_1
      /* bus is in active state */
      Lin_FrmSts |= (uint16)LIN_STAT_BUS_ACTVTY_VAL;
    #endif/* LIN_V_2_1 */
    	
    switch ( Lin_AutoBaudBitCtr )
    {
      case LIN_BREAK_BIT:
      {
        /*
         may be the first falling edge of break or the break
         detected interrupt.(Prepare Break/SYNC Detection).
        */
        IDL_CNF_BRK_DTCT();
      
        Lin_AutoBaudBitCtr++;
      }
      break;    
      /* start bit of sync byte, falling edge interrupt */
      case LIN_SYNC_BYTE_START_BIT: 
      {
        IDL_CLR_ATBD_INT();
        IDL_CNF_SYNC_DTCT();
        Lin_AutoBaudBitCtr++;
      }
      break;
      /* second bit of sync byte, falling edge interrupt */
      case LIN_SYNC_BYTE_2BIT: 
      {
        /* Clear Interrupt Flag */           
        IDL_CLR_ATBD_INT();  
        Lin_AutoBaudBitCtr++;
        Lin_BitTime = idl_calc_bittime();
      }/*case 2 */
      break;
      
      case LIN_SYNC_BYTE_4BIT: 
      case LIN_SYNC_BYTE_6BIT: 
      case LIN_SYNC_BYTE_8BIT: 
      {
        Lin_AutoBaudBitCtr++;
        if ( (uint8)LIN_SYNC_BYTE_STOP_BIT == Lin_AutoBaudBitCtr )
        {
          IDL_STOP_ATBD_DTCT();
        
          /* Program new baud rate values */
          idl_program_baud( Lin_BitTime );	
          
          /* rest the counter */
          Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;
          
          /* Break / SYNC state is idle */
          Lin_StateMachine.Lin_BrkSyncState = LIN_BRK_SYNC_IDLE;
          Lin_StateMachine.Lin_CommState    = LIN_PID;
        }
      }
      break;
      
      default:
        /* No action, (control will never come here.) */
        break;
    }/*endof switch */
  }/*end of falling edge */

  /*restore page settings */
  idl_restore_context( scu_page );   
  /*
   perform any platform specific activity
   e.g. : retrieving any paging or other registers req inside the ISR
  */
  IDL_ISR_POST_HOOK();
}
#endif   /* _IFC_SLAVE */   

#ifdef _IFC_SLAVE
/******************************************************************************
** Syntax           : TIMEOUT_EVNT_HANDLER                                   **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                         **
**                                                                           **
** Parameters(in)   : NA                                                     **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : This ISR handles timeouts for the following	 in slave  **
**                  : - Sleep / Wakeup timeout								               **
**                  : - Frame timings                                        **
**                                                                           **
******************************************************************************/
/*lint -e(102) */
/*lint -e31 */
INTERRUPT(TIM_INT)  void TIMEOUT_EVNT_HANDLER(void)
{
  uint8 flag_val = (uint8)0;  

  /*
   Perform any platform specific activity
    e.g. : Save any paging or other registers req inside the ISR
  */
  IDL_ISR_PRE_HOOK();  
  
   /* reload timer. */
  idl_load_new_timeout ( (uint16)LIN_CFG_TMR_TICKS );
  Lin_CurrTimeOutCntr += (uint16)_TMR_BASE;  

  switch ( Lin_BusState )
  {
    case LIN_ACTIVE:
    {
    	global_flag_val = (uint8)0;
      Lin_lSlaveTimeOutActive( );
      if(global_flag_val == (uint8)1) 
      {	
        flag_val = (uint8)1;	
      }  
    }/*case: active */
    break;

    #if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      case LIN_WKUP:
      {
        flag_val = Lin_lSlaveTimeOutWakUp( );
      }/*case: LIN_WKUP*/
      break;/*1st wakeup */      
    #endif/* ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) .. */

    /* no action */
    default:
      break;
  }/*end of switch */

  #if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
    if ( flag_val > (uint8)0 )
    {
      Lin_StateMachine.Lin_CommState = LIN_IDLE; 
      wkup_bit2 = (uint8)0;    
      /*
        Set UART baud rate RUN control bit and enable UART interrupt enable,
         because we may receive wakeup signal from other slave/master
      */
      idl_Restart_AutoBaud( );   
      if ((uint8)2 == flag_val )
      {
        IDL_SEND_WAKE_BYTE();        
      }
    }/* End of if ( flag_val > 0 ) */
  #endif   /* ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED)... */
  /*
   perform any platform specific activity
   e.g. : retrieving any paging or other registers req inside the ISR
   */
  IDL_ISR_POST_HOOK();
}
#endif   /*_IFC_SLAVE */

/****************************************************************************** 
** Syntax           : Lin_lParityCal                                         ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                         **  
**                                                                           ** 
** Parameters(in)   : NA                                                     ** 
**                                                                           ** 
** Parameters (out) : none                                                   ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : The API calculates the Parity from Frame ID            ** 
**                                                                           ** 
******************************************************************************/ 

#ifdef _IFC_SLAVE
  static void Lin_lParityCal(void)
  {
    /* calculate parity bits (P0 and P1) */
    bit6 = bit0 ^ bit1 ^ bit2 ^ bit4;
    bit7 =(uint8)( ~( bit1 ^ bit3 ^ bit4 ^ bit5 ));
  }/* Lin_lParityCal */
#endif /* #ifdef _IFC_SLAVE */

/****************************************************************************** 
** Syntax           : Lin_lPIDHandle                                         ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                          **  
**                                                                           ** 
** Parameters(in)   : received byte                                          ** 
**                                                                           ** 
** Parameters (out) : none                                                   ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Called from PID case from COMM_HANDLER to process      **
**                    the PID received                                       ** 
**                                                                           ** 
******************************************************************************/ 
static void Lin_lPIDHandle(uint8 rcvd_data)
{ 	

	uint8 frm_index  , index = (uint8)0 , temp_index;

	#if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))	  
	    uint8 nloop1;	  
	#endif /* _EVNT_SPRDC_FRM_SPRT   */
  /*
   Reset the flag which indicates a timeout waiting for frame header
   in autobaud ISR
  */
  wkup_bit3 = 0U;
      	
	#ifdef _IFC_SLAVE
    Lin_FrmId      = rcvd_data; 
    Lin_RcvedFrmId = rcvd_data; 	    
    /* Calculate parity bits (P0 and P1) */
    Lin_lParityCal ( );
  #endif   /*_IFC_SLAVE */      
                           
  #ifdef LIN_V_2_1
    frm_index = Lin_lGetFrmIdx((Lin_RcvedFrmId & (uint8)LIN_GET_FRAME_ID));   
  #else
    frm_index = ( Lin_RcvedFrmId & LIN_GET_FRAME_ID ); 
  #endif /* #ifdef LIN_V_2_1  */
  
  if((Lin_RcvedFrmId == rcvd_data) &&
  	  ( frm_index < (uint8)LIN_SYS_NUM_FRMS ))
  {
  	#ifdef _IFC_SLAVE
  	  /* Get Only the Frame ID */ 
      Lin_RcvedFrmId &= (uint8)LIN_GET_FRAME_ID ;
    #endif /* #ifdef _IFC_SLAVE */
    
    /* Check what check sum model to use. Enhanced / Classic  */
  	#if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) || (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) )
  	  if(Lin_RcvedFrmId >= ( uint8 )LIN_DGNSTC_REQ_FRM_NUM)
  	  {	
  	    Lin_ChkSum   = (uint16) LIN_DIAG_CLASSIC_CHKSUM;     
  	  }  
  	  else
  	  {	  
  	#endif /* _WKUP_SLP_SPRT */  	
  	    Lin_ChkSum = ( uint16 ) rcvd_data; 
  	#if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) || (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) )  
  	  }
  	#endif /* _WKUP_SLP_SPRT */  	  
  	/* 
  	  Initialize to default values, before deciding the data transfer mode.
  	   No data to transfer, Transmission direction is None , and Frame Type 
  	   Unconditional and number of bytes transmitted is 0. 
  	*/
  	Lin_FrmTxMode     = LIN_DUMMY_FRM;
  	Lin_FrmBuffIdx    = 0U;
  	Lin_NumofBytesTx  = 0U;  	 
  	Lin_FrmTxDataPtr  = LIN_NO_UPDATED_DATA;  	 
  	Lin_FrmType       = LIN_FRM_UNCD ;     
  	 
  	/* If interface is a subscriber or publisher to a frame */ 
  	if ( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_REG_ID_MSK )      
  	{
  	  /* is publisher */      
  	  if ( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_PBLSHR_MSK ) 
  	  {
  	    #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 	
  	      /* The slave is publisher for slave response frame */   
  	      if ( (uint8)LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId )
  	      {
  	      #if (_TP_BUFF_MGMT  == 1U)
  	        /* Check if buffer is pending to be trabsmitted */  
  	        if((uint8)LIN_TP_TX_PNDG == Lin_TpSendMsgPndg)
  	        {	
  	          Lin_FrmTxMode    = (uint8) LIN_FRM_TX ;	
  	          Lin_FrmTxDataPtr = (uint8) LIN_UPDATED_DATA;  	          
  	        } /* If diag data is available */
  	      #else  
  	        #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF)  	    
  	          /* 
  	            If any data is available to respond in diagnostic TX 
  	             buffer or if a buffer is pending from transport protocol 
  	             layer. 
  	          */
  	          #ifdef LIN_V_2_1 
  	            if ( ( Lin_DiagTxFifoLvl > 0U ) || 
  	            	   (1U == Lin_TpSendMsgPndg))
  	          #else
  	            if ( Lin_DiagTxFifoLvl > 0U )
  	          #endif /* #ifdef LIN_V_2_1 */
  	            {
  	              /* the slave has diagnostic response frame data */ 	 
  	              Lin_FrmTxMode    = (uint8) LIN_FRM_TX ;
  	              Lin_FrmTxDataPtr = (uint8) LIN_UPDATED_DATA; 
  	            }
  	        #endif /* _DGNSTC_TBUFF_SZ */  	        
  	      #endif  /*_TP_BUFF_MGMT */
  	      } /* if ( (uint8)LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId ) */
  	      else  
  	    #endif /* _DGNSTC_FRM_SPRT */
  	      {
  	       	/* Publisher to a frame and not a diagnostic frame. */
  	        Lin_FrmTxMode = (uint8) LIN_FRM_TX ;
  	        
  	        /* Check if application has updated data for Frame ID */
            {
              Lin_FrmTxDataPtr = (uint8) LIN_UPDATED_DATA;    	
            }  
  	      }/* If PID != LIN_DGNSTC_RESP_FRM_NUM */
  	  }/* if ( Lin_FrmInfo[frm_index] & LIN_SYS_FRM_INFO_PBLSHR_MSK ) */  	  
  	  else
  	  {
        #ifdef _IFC_SLAVE
  	  	  Lin_FrmTxMode = (uint8) LIN_FRM_RX;	
  	    #endif /* #ifdef _IFC_SLAVE */  	    
  	  }	/*subscriber */  
   	}	/* if ( Lin_FrmInfo[frm_index] & LIN_SYS_FRM_INFO_REG_ID_MSK ) */
   	   
   	/* It could be an event triggered frame, neither publisher or subscriber */   
    #if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) )
      #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)
        else
        { 
        	/* Check any Event Frame is publisher */
          index = Lin_lPIDHandleEvntFrmProc( );                  
          
          /* Does not have updated data so may be other nodes will send data */
          /* if ( Lin_FrmTxMode != (uint8)LIN_FRM_TX )*/
          {    	      
    	      #ifdef LIN_V_2_1
    	        frm_index = Lin_lGetFrmIdx(Lin_RcvedFrmId);
    	      #else
    	        frm_index = Lin_RcvedFrmId;
    	      #endif /* LIN_V_2_1 */  
          }	/* if ( Lin_FrmTxMode != (uint8)LIN_FRM_TX ) */                   
        }        	
      #endif /* LIN_SYS_CFG_NUM_OF_EVNT_FRMS */
    #endif /* _EVNT_SPRDC_FRM_SPRT */   
    
  #if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
    #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)	
      /*
         in-case of event triggered frame get the frame length from any one of 
          associated unconditional frames.
         
         (All associated unconditional frames of event triggered frames have 
           the same length.)
      */
      if ( ( (LIN_FRM_TYPE)LIN_FRM_EVNT == Lin_FrmType ) && 
      	   ( Lin_FrmTxMode > (uint8)LIN_DUMMY_FRM ) )
      {
        /*code is introduced to avoid any out of bound array acces*/
        if (index < 1U)
        {
          index = 1U;
        } 
        /*code is introduced to avoid any out of bound array acces*/      	
        index -- ;        
        #ifdef LIN_V_2_1
          for ( nloop1 = (uint8)0; nloop1 < (uint8)LIN_SYS_NUM_FRMS; nloop1++ )
          {
          	/* check for the event triggered frame ID  length */
          	for(temp_index = 0U ; 
          	    temp_index < Lin_EvntSchTbl[index].max_num_of_uncd_frms; 
          	    temp_index ++ )
          	{
          		if ( Lin_FrmTbl[nloop1] == Lin_EvntSchTbl[index].asctd_uncd_frm_ids[temp_index] )
          	  {	
                Lin_FrmLen =
                  (uint8)(( Lin_FrmInfo[nloop1] & 
                  (uint8)LIN_SYS_FRM_INFO_LEN_MASK ) + (uint8)1 );
                  
                  nloop1 = LIN_SYS_NUM_FRMS; 
                  break;          			
              }    
          	}/* inner for loop */	    
          }          
        #else
          for ( nloop1 = 0U; nloop1 <
                       Lin_EvntSchTbl[index].max_num_of_uncd_frms; 
                            nloop1++ )        
          {                  
            if ( (Lin_FrmInfo[(Lin_EvntSchTbl[index].asctd_uncd_frm_ids[nloop1])])
            	 & (uint8)LIN_SYS_FRM_INFO_REG_ID_MSK )
            {	 
             Lin_FrmLen =
              ( Lin_FrmInfo
                [ ( Lin_EvntSchTbl[index].asctd_uncd_frm_ids[nloop1]) ] &
                    LIN_SYS_FRM_INFO_LEN_MASK                      ) +
                    1U ;                    	  
             }       
          }  	
        #endif /* LIN_V_2_1 */
      }
      else
    #endif
  #endif
      {
     	  Lin_FrmLen =                                                          
     	     (uint8)( ( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_LEN_MASK ) + (uint8)1);
      }   	    
    /*
       in-case of event triggered frame and subscriber, copy receive data into
        temporary buffer because event triggered frame do not have specific
        data buffer.
    */
    #if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      if ( ( (LIN_FRM_TYPE)LIN_FRM_EVNT == Lin_FrmType ) && ( (uint8) LIN_FRM_RX == Lin_FrmTxMode) )
      {
        Lin_FrmBuffIdx = (uint16)LIN_SYS_TOTAl_FRM_BUFF_SZ;
      }
      else
    #endif
      {
        /* receive/transmit, point to buffer to get/update with data */	
        if ( Lin_FrmTxMode > (uint8)LIN_DUMMY_FRM )  	
        {
          Lin_FlgIdx = ( frm_index >> (uint8)3 );	
        	Lin_FlagVal = ((uint8)( (uint16)0x01 << ( frm_index & (uint16)0x07 ) ));
        	 
        	#if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
        	  if ( Lin_RcvedFrmId < (uint8)LIN_DGNSTC_REQ_FRM_NUM )
        	#endif /*diagnostic support */
        	  {
              if (Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_OFFSET_MSK)
                {
                  Lin_FrmBuffIdx = (uint16)(((uint16)LIN_FRM_HIGHER_OFFSET +
                                   (uint16)Lin_FrmOffset[frm_index]));
                }
                else
                {
                  Lin_FrmBuffIdx = Lin_FrmOffset[frm_index];
                }        	  	
        	  }
        }/* if ( Lin_FrmTxMode > (uint8)LIN_DUMMY_FRM ) */          	  
      }
    
    Lin_lPIDHandleTx( );          
    #ifdef _IFC_SLAVE
      if ( Lin_FrmTxMode > (uint8)LIN_DUMMY_FRM )
      {
        /* Frame transmission is active, start timer */      
        idl_load_new_timeout( (uint16)(LIN_CFG_TMR_TICKS) );
        
        /*
         frame transmission is on going this is reset in RCV_CHKSUM branch,
          used to check for time out in Time out ISR.
        */
        wkup_bit3 = (uint8)1;
      	
      	/* current frame timeout, for response depending on the frame length.*/      	
      	/* UTP AI00056260 fixed */
      	/* current frame timeout, for response depending on the frame length.*/
      	/* UTP AI00059574 fixed */
      	Lin_CurrSlotTimeOut = ((uint8)((uint16)((uint16)(14U * 1000U)) / \
      	                              ((uint16)(Lin_BaudRate )) )) + 1U;
        Lin_CurrSlotTimeOut *= (uint8)(Lin_FrmLen + (uint8)LIN_FRM_LEN_OFFSET);                         
        
      	/* Timer base defines the count value.*/
      	Lin_CurrSlotTimeOut = (Lin_CurrSlotTimeOut / _TMR_BASE);      	
     
        /* reset current frame elapsed time */
        Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
      }    
    #endif /* _IFC_SLAVE */   
  }/* if Valid PID and correct PID */	  
  else
  {     
    #ifdef LIN_V_2_1
      /*
       bus is in inactive state and this is set in UART ISR --> IDLE,
       UART ISR -->RCV_BREAK
       */
      Lin_FrmSts &= ((~(uint16)( LIN_STAT_BUS_ACTVTY_VAL )));
    #endif   /* LIN_V_2_1 */              	
    Lin_StateMachine.Lin_CommState = LIN_IDLE;/* RCV_BREAK; */
    
    #ifdef _IFC_SLAVE
      /*
        Need to clear the timeout counter for every byte of transmission 
         to be in active state. 
         Otherwise the interface will enter sleep state after 4sec timeout 
      */
      Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
      /* clear the counter, this is used in Auto Baud interrupt */
      Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;       
      idl_cfg_atbd_dtct( );
    #endif /* _IFC_SLAVE */    
  }	  
} /* Lin_lPIDHandle */

/****************************************************************************** 
** Syntax           : Lin_lPIDHandleTx                                       ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                          **  
**                                                                           ** 
** Parameters(in)   : None                                                   ** 
**                                                                           ** 
** Parameters (out) : none                                                   ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Handles the data transfer direction                    **
**                                                                           ** 
******************************************************************************/ 
static void Lin_lPIDHandleTx (void)
{  
  #if  (_FIFO == 1U)
	  uint8 u8BytesTxed; 
	#endif /* _FIFO */		
	
  switch ( Lin_FrmTxMode )
  {
    /* no transmission, need to check break/sync sequence from master */
    case LIN_DUMMY_FRM:
    {    	
      #ifdef LIN_V_2_1
          /* Bus is in inactive state  */
          Lin_FrmSts &= (~((uint16) LIN_STAT_BUS_ACTVTY_VAL ));
      #endif   /* LIN_V_2_1 */    	
      
      Lin_StateMachine.Lin_CommState = LIN_IDLE;
      #ifdef _IFC_SLAVE  
        /*
         Need to clear the timeout counter for every byte of transmission 
         to be in active state. 
         Otherwise the interface will enter sleep state after 4sec timeout 
        */
        Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
        /* clear the counter */
        Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;
          
        /* #ifdef LIN_V_2_1 
          ifc_status_data &= ~( LIN_STAT_BUS_ACTVTY_VAL );
        #endif    LIN_V_2_1 */        
        /*disable UART for 8 bit here */
        /* To make sure Autobaud feature is running,in case of dropped frames*/
        idl_cfg_atbd_dtct();
      #endif /* #ifdef _IFC_SLAVE  */
    }
    break;/* idle */
    
    /* transmits frame data */
    case LIN_FRM_TX:
    {
      #if  (_FIFO == 1U)
        #if ((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
          if ( (uint8) LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId )
          {	
            #if  (_TP_BUFF_MGMT  == 1U)	          
              /* Prepare the buffer */     
              u8BytesTxed = Lin_lPrepareTpBuffer(&Lin_TpTxLenPtr ,
                                           &(Lin_TpTxBuff[Lin_TpTxRdIndex]) );   
              /* Pointer to give to FIFO */
              Lin_RxDataPtr = Lin_TempTxData;
              
              Lin_TpBytesTxed += u8BytesTxed;     
              Lin_TpTxRdIndex += u8BytesTxed;     
              
              Lin_TpTxSts   = (uint8)LD_IN_PROGRESS;
            #else        
              #ifdef LIN_V_2_1        
                if((uint8)LIN_TP_TX_PNDG == Lin_TpSendMsgPndg)
                {
                  u8BytesTxed = Lin_lPrepareTpBuffer(Lin_TpTxLenPtr , 
                                (Lin_TpTxDataPtr+Lin_TpBytesTxed));   
                
                  Lin_RxDataPtr   = Lin_TempTxData;                                    
                  Lin_TpBytesTxed += u8BytesTxed; 
                  Lin_TpTxSts     = (uint8)LD_IN_PROGRESS;
                }	
                else
              #endif /* #ifdef LIN_V_2_1 */  	
              {		
                Lin_RxDataPtr = &(Lin_DiagTxFifo[Lin_DiagTxFifoRdIdx] \
                                   [Lin_NumofBytesTx]);
              }  
            #endif /*  _TP_BUFF_MGMT   */ 
          }  
          else
      #endif /* #if (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) */
        {
        	Lin_RxDataPtr = &(Lin_FrmData[Lin_FrmBuffIdx]);
        }		
      /* Set up _FIFO, and transmit data */
      idl_Setup_TxFIFO( (uint8)(Lin_FrmLen - 1U) , Lin_RxDataPtr ,LIN_FRM_TX);
      Lin_NumofBytesTx = Lin_FrmLen; 
    #else
      #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
        /*
          in-case of diagnostic frame read data from diagnostic TX buffer
           or TP buffers.
        */
        #ifdef _IFC_SLAVE
          if ( (uint8) LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId )
        #endif /* #ifdef _IFC_SLAVE */  	
          {            	
          #if (_TP_BUFF_MGMT  == 1U)
  	        /* If it is a Assign NAD command response, send with Init NAD */
						if(LIN_DIAG_ASSIGN_NAD_RSID == Lin_TpTxBuff[0])
						{	  	        
  	          Lin_LastTxData = (uint8)Lin_InitNAD;	  
  	        }
  	        else if (LIN_DIAG_CONDITIONAL_NAD_RSID == Lin_TpTxBuff[0])	
  	        {
  	          Lin_LastTxData = (uint8)Lin_OldNAD;	  	
  	          Lin_OldNAD     = Lin_NAD;
  	        }	
  	        else
  	        {
  	          Lin_LastTxData = (uint8)Lin_NAD;	  	
  	        }	  
  	        Lin_TpTxSts    = (uint8)LD_IN_PROGRESS;          	        
  	      #else
            #ifdef LIN_V_2_1          	
            	/*
			         If TP Message to be transmitted, first byte is always NAD,
			         Make the status as IN PROGRESS, so that no fresh send_message
			         is accepted.
			         */
              if((uint8)LIN_TP_TX_PNDG == Lin_TpSendMsgPndg)
              {
               	Lin_LastTxData = (uint8)Lin_NAD;
			          Lin_TpTxSts    = (uint8)LD_IN_PROGRESS;
              }
              else
            #endif /* #ifdef LIN_V_2_1 */    
                    	            
            #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF)
              {
                Lin_LastTxData =
                    Lin_DiagTxFifo[Lin_DiagTxFifoRdIdx][Lin_NumofBytesTx];
              }      
            #endif/*_DGNSTC_TBUFF_SZ */
          #endif   /*_TP_BUFF_MGMT */   
          }
          else
          {	
      #endif   /*diagnostic frame support */
            Lin_LastTxData = Lin_FrmData[Lin_FrmBuffIdx++];
      #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
          }
      #endif   /*diagnostic frame support */
        Lin_lChkSumCalc(Lin_LastTxData);      
        idl_channel_send(Lin_LastTxData);
        Lin_NumofBytesTx++;
	    #endif /* _FIFO */
	    
      Lin_StateMachine.Lin_CommState = LIN_TX_DATA;      
      /* update with flag i.e. LLD is using the frame data buffer */
      Lin_BufferInUse[Lin_FlgIdx] |= Lin_FlagVal;      
    }
    break;    /* case 1: Tx */
    /*  receive frame data     */
    case LIN_FRM_RX:
    {
    	/* Event Triggered frame is updated in a different location */
    	if( (LIN_FRM_TYPE)LIN_FRM_EVNT != Lin_FrmType )
    	{	
        /*
         Check if previous frame data is read by application,
         if not then set overflow flag.
         */
        if ( Lin_FrmDataUpdtFlag[Lin_FlgIdx] & Lin_FlagVal )
        {
          Lin_FrmDataUpdtFlag[Lin_FlgIdx] &= ((uint8)~( Lin_FlagVal ));
          Lin_BufferDataLost[Lin_FlgIdx]  |= Lin_FlagVal;
        }
        /* update with flag i.e. LLD is using the frame data buffer */
        Lin_BufferInUse[Lin_FlgIdx] |= Lin_FlagVal;
      }
            
      #if (_TP_BUFF_MGMT == 1U)
    	  #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))	
          /* If Rx is in progress. */
          if((uint8)LD_IN_PROGRESS != Lin_TpRxSts)     
          {	
            if ( (uint8) LIN_DGNSTC_REQ_FRM_NUM == Lin_RcvedFrmId )   
    	      {
              Lin_TpRxFrmSerialNo  = (uint8) 0;
              Lin_TpBytesRxed      = (uint8) 0;
              Lin_TpRxWrIndex      = (uint8) 0;
              Lin_TpRxMsgPndg      = (uint8)LIN_TP_RX_PNDG;         
              Lin_TpRxFrm         = 0U;    
            }
          }
        #endif /*_DGNSTC_FRM_SPRT  */ 
      #endif /*_TP_BUFF_MGMT */           
      
      #if  (_FIFO == 1U)
        /* get the right pointer to read data bytes */
        #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 	        
          if ( (uint8)LIN_DGNSTC_REQ_FRM_NUM == Lin_RcvedFrmId ) 
          {	
          	#if  (_TP_BUFF_MGMT  == 1U)
              Lin_RxDataPtr = Lin_TempRxData;
            #else      
              #ifdef LIN_V_2_1                 
                if((uint8)LIN_TP_RX_PNDG == Lin_TpRxMsgPndg)
                {	
                  Lin_RxDataPtr = Lin_TempRxData;
                }
                else
              #endif /* #ifdef LIN_V_2_1  */  	
              {
                Lin_RxDataPtr = &(Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx] \
                                   [Lin_NumofBytesTx]);
              }  
            #endif /* #if  (_TP_BUFF_MGMT  == 0U) */  
          }
          else
        #endif /* Diags Support */	
        {
        	Lin_RxDataPtr = &(Lin_FrmData[Lin_FrmBuffIdx]);
        }		
        idl_Setup_TxFIFO( (uint8)(Lin_FrmLen-1U) , LIN_NULL_DATA , LIN_FRM_RX);		
        Lin_NumofBytesTx = Lin_FrmLen;
      #endif /* _FIFO */  
      
      
      Lin_StateMachine.Lin_CommState = LIN_RX_DATA;
    }
    break; /* case 2: Rx */

    default:
      break;
  }/*switch Lin_FrmTxMode*/
}/* Lin_lPIDHandleTx */   

/****************************************************************************** 
** Syntax           : Lin_lChkSumCalc                                        ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                          **  
**                                                                           ** 
** Parameters(in)   : None                                                   ** 
**                                                                           ** 
** Parameters (out) : Buffer and the length                                  ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Calculates the checksum                                **
**                                                                           ** 
******************************************************************************/ 
/* Pointer to'u8Data' could be declared as pointing to const */
/*lint -e818 */
#if  (_FIFO == 1U)
  static void Lin_lChkSumCalc(uint8 *FrmData , uint8 u8FrmLen)    
#else
  static void Lin_lChkSumCalc(uint8 Data)     
#endif   /* #if  (_FIFO == 1U) */
{ 
	#if  (_FIFO == 1U)
	  uint8  index , Data; 
	  
	  for(index = (uint8)0; index < u8FrmLen ; index ++)
	  {
	    Data = 	*FrmData ; 
	    FrmData ++;
  #endif /* #if  (_FIFO == 1U) */    
  
      /* update checksum */       
      Lin_ChkSum += Data; 

      if ( Lin_ChkSum >= (uint16)LIN_8BIT_BYTE_BOUNDARY )    
      {       
        Lin_ChkSum -= (uint16)((LIN_CHKSUM_BYTE));       
      }
  #if  (_FIFO == 1U)
    }    /* end of for */
  #endif /* #if  (_FIFO == 1U) */   
}/*  Lin_lChkSumCalc  */       
/*lint +e818 */ 
/****************************************************************************** 
** Syntax           : Lin_lPIDHandleEvntFrmProc                              ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Event Triggered Frame Handling                         **
**                                                                           ** 
******************************************************************************/      
#if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) )
  #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)
    static uint8 Lin_lPIDHandleEvntFrmProc( void )
    {
      uint8  index = (uint8)0 , nloop = (uint8)0 , frm_index;
                      
      Lin_FrmTxMode	= (uint8) LIN_DUMMY_FRM; 
      
      do
      {      
      	/* if event triggered frame */
      	if( Lin_RcvedFrmId == Lin_EvntSchTbl[index].frm_id ) 
      	{
          /* By default receive mode, as other slave may respond with their 
              unconditional frames. 
          */
          Lin_FrmTxMode	= (uint8) LIN_FRM_RX;            
          /* 
            Set frame type as event triggered, due to the fact that there  		
             are no errors on unsuccessful frame transmission
          */   
          Lin_FrmType = (LIN_FRM_TYPE) LIN_FRM_EVNT;
          
          /* 
            Check if any of the associated unconditional frames associated
             is a publisher. 
          */   
          for (
                nloop = (uint8)0;
                nloop < Lin_EvntSchTbl[index].max_num_of_uncd_frms;
                nloop++
              )
          {
            #ifdef LIN_V_2_1 	
              frm_index = Lin_lGetFrmIdx(
                               Lin_EvntSchTbl[index].asctd_uncd_frm_ids[nloop]
                               ) ;                              
            #else
              frm_index = Lin_EvntSchTbl[index].asctd_uncd_frm_ids[nloop];
            #endif /* LIN_V_2_1 */
                      
            if ( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_PBLSHR_MSK )
            {            	
            	/* Check if updated frame data is available */
              if (( ( Lin_FrmDataUpdtFlag[( frm_index >> 3 )]) &
                    ((uint8)( (uint16)0x01 << (uint16)(( frm_index & (uint16)0x07 )) )) )
                  )
              {
                /* Update ifc_rcv_frm_id with current associated UNCND ID */
                Lin_RcvedFrmId  =  Lin_EvntSchTbl[index].\
                                   asctd_uncd_frm_ids[nloop];                  
                /* transmit the data */
                Lin_FrmTxMode    = (uint8) LIN_FRM_TX;
                Lin_FrmTxDataPtr = (uint8) LIN_UPDATED_DATA;
              }
              break;
            }
          }        
      	}/* */	
        index ++;	
      }while ((index < (uint8)LIN_SYS_CFG_NUM_OF_EVNT_FRMS ) && 
               ( (uint8)LIN_DUMMY_FRM == Lin_FrmTxMode ) );              
    
    return(index);  
    } /* Lin_lPIDHandleEvntFrmProc */              
  #endif /* LIN_SYS_CFG_NUM_OF_EVNT_FRMS */
#endif  /* _EVNT_SPRDC_FRM_SPRT */     

/****************************************************************************** 
** Syntax           : Lin_lHandleRxData                                      ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                          **  
**                                                                           ** 
** Parameters(in)   : Data received                                          ** 
**                                                                           ** 
** Parameters (out) : None                                                   ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Rx Data handling part of COMM_HANDLER.                 **
**                                                                           ** 
******************************************************************************/ 
static void Lin_lHandleRxData (uint8 rcvd_data)
{
  #if  (_FIFO == 1U)
    idl_ReadRxFiFo( Lin_FrmLen , Lin_RxDataPtr , LIN_FRM_RX);	
    #ifdef _IFC_SLAVE	
      #if((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) ) 
        Lin_RxFirstByte = *Lin_RxDataPtr; 
      #endif /* Sleep support */     
    #endif /* Slave */    
    
    #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) ||\
        (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      if ( (uint8)LIN_DGNSTC_REQ_FRM_NUM == Lin_RcvedFrmId )
      {        
        #ifdef LIN_V_2_1
          if(Lin_TpRxMsgPndg)  
          {
          	Lin_lReadTpBuffer(Lin_RxDataPtr);
          }/* Lin_TpRxMsgPndg */	
        #endif /* #ifdef LIN_V_2_1 */  
      }
    #endif /* Diags */  
  #else  	
    #ifdef _IFC_SLAVE	
      #if((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) ||(_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
        /*Save the first byte value(in order to check for goto sleep command)*/
        if ( (uint8)0 == Lin_NumofBytesTx )
        {
          Lin_RxFirstByte = rcvd_data;
        }
      #endif /* Sleep support */
    #endif /* Slave */    
    
    #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      /* Store data in diagnostic RX buffer, if it is a diagnostic frame */
      #ifdef _IFC_SLAVE	
        if ( (uint8)LIN_DGNSTC_REQ_FRM_NUM == Lin_RcvedFrmId )        
      #endif /* slave */  	
      { 
      #if (_TP_BUFF_MGMT	== 1U)
         if((Lin_TpRxMsgPndg) && (!Lin_FuncReq))
         {	
           Lin_lTpRxMsgPrc(rcvd_data); 
         }  
      #else
        /*
	  	    Check if it is a TP message; if true, store to the buffer
	  	     specified from upper layer.
	  	  */
        #ifdef LIN_V_2_1		     
          if((Lin_TpRxMsgPndg)&& (!Lin_FuncReq))
          {
            Lin_lTpRxMsgPrc(rcvd_data);
          } /* */
          else
        #endif /* #ifdef LIN_V_2_1  */
          {
            #if (((_DGNSTC_RBUFF_SZ > LIN_DIAG_RFIFO_NOT_DEF)) && ((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)))
              Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][Lin_NumofBytesTx]= rcvd_data;
              #ifdef LIN_V_2_1
                Lin_lChkDiagResp( ); 
              #endif /* #ifdef LIN_V_2_1 */  
            #endif /* _DGNSTC_RBUFF_SZ.... */
          }
      #endif /* _TP_BUFF_MGMT */          
      }/* if ( Lin_RcvedFrmId == LIN_DGNSTC_REQ_FRM_NUM )*/
      else
      	
    #endif /* diags support */
      {
        Lin_FrmData[Lin_FrmBuffIdx++] = rcvd_data;
      }
      Lin_NumofBytesTx++;
  #endif /* #if  (_FIFO == 1U) */
    
  /* Calculate Check Sum */    
  #if  (_FIFO == 1U)
    Lin_lChkSumCalc(Lin_RxDataPtr ,Lin_FrmLen ); 
  #else
    Lin_lChkSumCalc(rcvd_data);
  #endif /* #if  (_FIFO == 1U) */
  
  /* if the last data byte is received, wait for checksum */
  if ( Lin_NumofBytesTx >= Lin_FrmLen )
  {
    Lin_StateMachine.Lin_CommState = LIN_RX_CHKSUM;
    Lin_ChkSum = ( uint16 ) ( ~Lin_ChkSum );
  }
}/* Lin_lHandleRxData */                      


/****************************************************************************** 
** Syntax           : Lin_lTpRxMsgPrc                                        ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                          **  
**                                                                           ** 
** Parameters(in)   : Data received                                          ** 
**                                                                           ** 
** Parameters (out) : None                                                   ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Transport Protocol handling of data                    **
**                                                                           ** 
******************************************************************************/ 
#if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
  #ifdef LIN_V_2_1		     
    static void Lin_lTpRxMsgPrc(uint8 rcvd_data )
    {
    	/* Validate NAD, If NAD is wrong then ignore the Frame data.*/
    	if((uint8)LIN_1ST_BYTE == Lin_NumofBytesTx)
    	{
    	  if( (0U == rcvd_data) ||
    	  	  (Lin_NAD == rcvd_data)      ||
    	  	  (LIN_BROADCAST == rcvd_data) ||
    	  	  (Lin_InitNAD == rcvd_data)   
    	  	  #ifdef LIN_V_2_1
    	  	    || (LIN_FUNCTIONAL_NAD == rcvd_data)
    	  	  #endif/* LIN_V_2_1 */
    	  	 )  
    	  {
    	  	/* Check if a functional request has come in between a tx/rx */
    	  	#ifdef LIN_V_2_1
      	  	if(LIN_FUNCTIONAL_NAD == rcvd_data )    	  		
      	  	{
      	  		/* If a Transmission is on going dicard the functional request */
      	  		if( ((uint16)LD_IN_PROGRESS == (uint16)Lin_TpRxSts) ||   
      	  			  ((uint16)LD_IN_PROGRESS == (uint16)Lin_TpTxSts) ||
      	  			  /* UTP AI00059568 fixed */
      	  			  ((LIN_TP_TX_PNDG == Lin_TpSendMsgPndg))  
      	  			)
      	  		{
      	  		  Lin_FuncReq = 1U;	
      	  		}/* */	 
      	  		else
      	  		{
          	    Lin_TpRxSts  = (uint8)LD_IN_PROGRESS;
          	    /* Store the NAD to support Lin_InitNAD feature */
        	      Lin_TempNAD  = rcvd_data;     	    
      	  		}	
      	  	}	
      	  	else
    	  	#endif /* */
      	  	{		
        	    Lin_TpRxSts  = (uint8)LD_IN_PROGRESS;
        	    /* Store the NAD to support Lin_InitNAD feature */
        	    if(0U != rcvd_data)
        	    {	
        	      Lin_TempNAD  = rcvd_data;     	    
        	    }
        	    else  
        	    {
        	    	Lin_TempNAD  = Lin_NAD; 
        	    }	
          	  /* Check if any pending response should be discarded */
        	  }
    	  }    	  
    	  else
    	  {
    	    Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
    	    Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
    	    /* Update the status as failed */
    	    Lin_TpRxSts         = (uint8)LD_FAILED;  
    	    /* UTP AI00059568 fixed */
    	    Lin_TpRxFrm         = 0U;
    	  }
    	  
        if(LIN_FUNCTIONAL_NAD != rcvd_data)
     	  {
     	  	/* Check if any pending response should be discarded */
    	    Lin_lChkDiagResp();
    	  }/* */    	  
    	}/* End of if(0 == Lin_NumofBytesTx) */
      
      /* second byte is PCI, gives info about FF/SF/CF */
      else if((uint8)LIN_2ND_BYTE == Lin_NumofBytesTx)
      {
    	  /* Check if FF, calculate the MSB 4 bits of length */
    	  #if((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) ||(_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
          if(LIN_DIAG_SLP_CMD == Lin_RxFirstByte)
          {
     	      Lin_TpNoBytesTobeRxed = 6U;
     	      Lin_TpRxFirstFrm      = (uint8)0;        	
          }	
          else
        #endif /* */  	
        {		
          if( (uint8)LIN_TP_PCI_FF == (rcvd_data & (uint8)LIN_TP_PCI_FF) )
          {
      	    Lin_TpNoBytesTobeRxed   = (uint16)((uint16)rcvd_data & 
      	                    (uint16)LIN_TP_FRAME_LEN_MSB_EXTRACT);
      	    Lin_TpNoBytesTobeRxed <<= (uint8)LIN_TP_MSB_BYTE; 
            Lin_TpRxFirstFrm        = (uint8)1;
          }
      	  /* Check if its a CF, if yes validate SN */
          else if( (uint8)LIN_TP_PCI_CF == (rcvd_data & (uint8 )LIN_TP_PCI_CF) )
          {
          	/* UTP AI00059568 fixed */ 
          	if(Lin_TpRxFrm)
          	{	
        	    /* Its a CF */
           	  Lin_TpRxFirstFrm = (uint8)0;
              /* Increment the SN, FF is SN = 0 */
              Lin_TpRxFrmSerialNo ++;
        	    /* Frame Counter is from 0 - 16 */
              if((uint8)LIN_TP_MAX_SN == Lin_TpRxFrmSerialNo)
              {
                Lin_TpRxFrmSerialNo = (uint8)LIN_TP_MIN_SN;
              }
        	    /* Validate SN, if wrong update the status */
              if( Lin_TpRxFrmSerialNo != (rcvd_data & (uint8)LIN_TP_PCI_SN))
              {
                Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
                Lin_TpRxSts         = (uint8)LD_WRONG_SN;
                Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
                /* UTP AI00059568 fixed */
                Lin_TpRxFrm         = 0U;
              }
            }
            else
            {
        	    Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
        	    Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
        	    
        	    /* Update the status as failed */
        	    Lin_TpRxSts         = (uint8)LD_FAILED;        	    
        	    /* UTP AI00059568 fixed */
        	    Lin_TpRxFrm         = 0U;
            }	
          }
      	  else /* SF packet */
      	  {
      	    Lin_TpNoBytesTobeRxed = ((uint16)rcvd_data & 
      	                               (uint16)LIN_TP_FRAME_LEN_MSB_EXTRACT);
      	    Lin_TpRxFirstFrm      = (uint8)0;
      	  }
      	}/* */
      }
      /* No Need to save the NAD and PCI in the buffers */
      else 
      {
        /* if ((uint8)LD_IN_PROGRESS == Lin_TpRxSts) */
        {
          /*
            No need to save LEN byte in-case of FF,
             but store the length received in another variable, to check
             end of frame reception.
          */
          if( ((uint8)LIN_TP_3RD_BYTE == Lin_NumofBytesTx) &&
              (Lin_TpRxFirstFrm) )
          {
            Lin_TpNoBytesTobeRxed |= rcvd_data;
      	    /* Lin_TpRxFirstFrm       = (uint8)0; */
          }
          else if ( ((uint8)LIN_TP_3RD_BYTE == Lin_NumofBytesTx) &&
                 (rcvd_data == LIN_DIAG_ASSIGN_NAD_SID) )
          {
          	/* IF Assign NAD, then always it should be with Init NAD */
            if(Lin_TempNAD == Lin_InitNAD)
            {
            	#if (_TP_BUFF_MGMT  == 1U)
            	  Lin_TpRxBuff[Lin_TpRxWrIndex++] = rcvd_data;
            	#else
                /* Store data including SID. */
                *Lin_TpRxDataPtr = rcvd_data;
                Lin_TpRxDataPtr ++	;
              #endif /* _TP_BUFF_MGMT */
              /* Increment the length, used for actual length calculation. */
              Lin_TpBytesRxed ++;          	
            }	
            else
            {
        	    Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
        	    Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
        	    /* Update the status as failed */
        	    Lin_TpRxSts         = (uint8)LD_FAILED;    	              	
        	    /* UTP AI00059568 fixed */
        	    Lin_TpRxFrm         = 0U;
            }	        	
          }	  
          /* validate SID for First Frame */   
          else if ((Lin_TpRxFirstFrm)  &&
          	       ((uint8)LIN_TP_4TH_BYTE == Lin_NumofBytesTx))
          {
            Lin_TpRxFirstFrm = 0U;
            /* UTP AI00059568 fixed */
            Lin_TpRxFrm      = 1U;
            
        	  if((Lin_TempNAD == Lin_NAD ) ||
        		   (LIN_BROADCAST == Lin_TempNAD) ||
        		   (LIN_FUNCTIONAL_NAD == Lin_TempNAD)
        		   )
        	  {
            	#if (_TP_BUFF_MGMT  == 1U)
            	  Lin_TpRxBuff[Lin_TpRxWrIndex++] = rcvd_data;
            	#else
                /* Store data including SID. */
                *Lin_TpRxDataPtr = rcvd_data;
                Lin_TpRxDataPtr ++	;
              #endif /* _TP_BUFF_MGMT */
              /* Increment the length, used for actual length calculation. */
              Lin_TpBytesRxed ++;        		        		
          	}	
          	else
          	{	
        	    Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
        	    Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
        	    /* Update the status as failed */
        	    Lin_TpRxSts         = (uint8)LD_FAILED;        		
        	    /* UTP AI00059568 fixed */
        	    Lin_TpRxFrm         = 0U;
            }          	
          }	        
          else 
          {
          	if((uint8)LIN_TP_3RD_BYTE == Lin_NumofBytesTx) 
          	{	
          	  if((Lin_TempNAD == Lin_NAD ) ||
          		   (LIN_BROADCAST == Lin_TempNAD)||
          		   (LIN_FUNCTIONAL_NAD == Lin_TempNAD)
          		   )
          	  {
            	#if (_TP_BUFF_MGMT  == 1U)
            	  Lin_TpRxBuff[Lin_TpRxWrIndex++] = rcvd_data;
            	#else
                /* Store data including SID. */
                *Lin_TpRxDataPtr = rcvd_data;
                Lin_TpRxDataPtr ++	;
              #endif /* _TP_BUFF_MGMT */
                /* Increment the length, used for actual length calculation. */
                Lin_TpBytesRxed ++;        		        		
            	}	
            	else
            	{	
          	    Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
          	    Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
          	    /* Update the status as failed */
          	    Lin_TpRxSts         = (uint8)LD_FAILED;        		
          	    /* UTP AI00059568 fixed */
          	    Lin_TpRxFrm         = 0U;
              }
            }
            else
            {
            	#if (_TP_BUFF_MGMT  == 1U)
            	  Lin_TpRxBuff[Lin_TpRxWrIndex++] = rcvd_data;
            	#else
                /* Store data including SID. */
                *Lin_TpRxDataPtr = rcvd_data;
                Lin_TpRxDataPtr ++	;
              #endif /* _TP_BUFF_MGMT */
              /* Increment the length, used for actual length calculation. */
              Lin_TpBytesRxed ++;        		                 	
            }	
          }/* else of (2 == Lin_NumofBytesTx)....*/
        } /* if (0 != Lin_TpRxDataPtr) */
      }/* if ((uint8)LD_IN_PROGRESS == Lin_TpRxSts) */
    }/* Lin_lTpRxMsgPrc   */
  #endif /* #ifdef LIN_V_2_1 */
#endif /* Diag Support */

/****************************************************************************** 
** Syntax           : Lin_lHandleTxData                                      ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                          **  
**                                                                           ** 
** Parameters(in)   : Data received                                          ** 
**                                                                           ** 
** Parameters (out) : None                                                   ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Tx Data handling part of COMM_HANDLER.                 **
**                                                                           ** 
******************************************************************************/ 
static void Lin_lHandleTxData(uint8 rcvd_data)
{
	#if  (_FIFO == 1U)
	  uint8  index ; 	
	#endif /* */
	
	#if  (_FIFO == 1U)
	  idl_ReadRxFiFo( Lin_FrmLen , Lin_TempRxData , LIN_FRM_TX);
	  
	  rcvd_data = Lin_LastTxData ;
	  
	  for(index = (uint8) 0 ; index < Lin_FrmLen ; index ++)
	  {
	    if(Lin_TempRxData[index] != *(Lin_RxDataPtr + index))
	    {	
	      rcvd_data = (uint8)(Lin_LastTxData + 1U) ;  		
	      break;
	  	}
	  }
	#endif /* #if  (_FIFO == 1U) */    
	 	
  /* received correctly the last sent data */
  if ( rcvd_data == Lin_LastTxData )                 
  {     	
    /* Check if all data bytes are transmitted, if yes send check sum byte */
    if ( Lin_NumofBytesTx >= Lin_FrmLen )
    {
    	#if  (_FIFO == 1U)
    	  Lin_lChkSumCalc(Lin_TempRxData ,Lin_FrmLen );   
    	#endif /* #if  (_FIFO == 1U) */
    	
      Lin_ChkSum = ( uint8 ) ( ~Lin_ChkSum );     
      
      /* Send Lin_ChkSum calculated */
      idl_channel_send( ( uint8 ) Lin_ChkSum );
            
      /* receive same data and cross verify */
      Lin_StateMachine.Lin_CommState = LIN_TX_CHKSUM;
      
      /*
        Check if the frame transmission is over, if yes the timer should 
         be reset. In-case failure of checksum, handled in RCV_CHKSUM branch
      */
      Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;    
    }
    #if  (_FIFO == 0U)
      else
      {  
        #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
          /*
            in-case of diagnostic frame, read data from diagnostic TX buffer
             and for TP read from application buffer and transmit byte
          */
          #ifdef _IFC_SLAVE
            if ( (uint8)LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId )
          #endif /* _IFC_SLAVE */
          { 
            #ifdef LIN_V_2_1        	            
              #if  (_TP_BUFF_MGMT  == 0U)	
                if(Lin_TpSendMsgPndg)
              #endif /* _TP_BUFF_MGMT */  	
              {
                /*
                 If No of bytes is greater than 2 then its the pay load in
		  	         case of CF and Length in-case of FF. in-case of SF
		  	         its always the data. Send the data from the buffer
		  	         specified by application.
                */
                if((Lin_NumofBytesTx > (uint8)LIN_TP_3RD_BYTE ) &&
                	                           (!Lin_TpTxFirstFrm))
                {	
                	#if  (_TP_BUFF_MGMT  == 1U)
                	  if(Lin_TpBytesTxed < Lin_TpTxLenPtr )
                	  {
                	  	Lin_LastTxData = Lin_TpTxBuff[Lin_TpTxRdIndex++];
                	  }		
                	  else
                	  {
                	    Lin_LastTxData = (uint8)LIN_DIAG_UNUSED_BYTE ;	
                	  } 	
                	#else
               	    if(Lin_TpBytesTxed < *Lin_TpTxLenPtr )
                	  {
                      Lin_LastTxData = *Lin_TpTxDataPtr;
                      Lin_TpTxDataPtr ++;                	  	
                	  }		
                	  else
                	  {	                	
                      Lin_LastTxData = (uint8)LIN_DIAG_UNUSED_BYTE;
                    }  
                  #endif /* _TP_BUFF_MGMT */    
                
                  Lin_TpBytesTxed ++;                  
                }
		  	        /* Check if FF transmit length */
                else if((uint8)LIN_TP_3RD_BYTE == Lin_NumofBytesTx)
                {
		              if(Lin_TpTxFirstFrm)
		  	          {
		  	          	#if  (_TP_BUFF_MGMT  == 1U)
		  	          	  Lin_LastTxData   = (uint8)( (uint16)(Lin_TpTxLenPtr &  \
		  	          	                                      (uint16)0x00FF));
		  	          	#else
		      	          Lin_LastTxData   = (uint8)((uint16)(*Lin_TpTxLenPtr & \
		      	                                             (uint16)0x00FF));
		      	        #endif  
                    Lin_TpTxFirstFrm = (uint8)0;
		  	          }
		  	          /* Its a CF/SF, just send data from buffer. */
		  	          else
		  	          {
		  	          	#if  (_TP_BUFF_MGMT  == 1U)
                	   /* if(Lin_TpBytesTxed < Lin_TpTxLenPtr )*/
                	    {
                	    	Lin_LastTxData = Lin_TpTxBuff[Lin_TpTxRdIndex++];
                	    }		
                	    /*else
                	    {
                	      Lin_LastTxData = (uint8)LIN_DIAG_UNUSED_BYTE ;	
                	    } */			      	       
		      	          /*Lin_LastTxData = Lin_TpTxBuff[Lin_TpTxRdIndex++];*/
		      	        #else
               	      /*if(Lin_TpBytesTxed < *Lin_TpTxLenPtr )*/
                	    {
                        Lin_LastTxData = *Lin_TpTxDataPtr;
                        Lin_TpTxDataPtr ++;                	  	
                	    }		
                	  /*  else
                	    {	                	
                        Lin_LastTxData = (uint8)LIN_DIAG_UNUSED_BYTE;
                      } */  		      	        
		  	              /*Lin_LastTxData = *Lin_TpTxDataPtr;                    
                      Lin_TpTxDataPtr ++;*/
                    #endif /* */
                    Lin_TpBytesTxed ++;
		  	          }
                }
                /* Send suitable PCI */
                else
                {
		  	          /*  If length is <=6 data can be in SF. */
		  	          #if  (_TP_BUFF_MGMT  == 1U)
		  	            if (Lin_TpTxLenPtr <= (uint8)LIN_TP_SF_LEN) 
		  	          #else		  	          
            	      if (*Lin_TpTxLenPtr <= (uint8)LIN_TP_SF_LEN) 
            	    #endif	
            	    {
            	    	#if  (_TP_BUFF_MGMT  == 1U)
            	    	  Lin_LastTxData = (uint8)(((uint16)LIN_TP_PCI_SF | \
            	    	                            Lin_TpTxLenPtr)) ;
            	    	#else
            	  	    Lin_LastTxData = (uint8)(((uint16)LIN_TP_PCI_SF | \
            	  	                              *Lin_TpTxLenPtr)) ;
            	  	  #endif   
            	    }
            	    /* in-case FF set PCI suitably */
            	    else if( Lin_TpTxFirstFrm )
            	    {
            	    	#if  (_TP_BUFF_MGMT  == 1U)
            	    	  Lin_LastTxData = (uint8)(((uint16)LIN_TP_PCI_FF | \
            	    	            (Lin_TpTxLenPtr/(uint16)LIN_TP_LEN_DELIMIT))); 
            	    	#else
            	  	    Lin_LastTxData = (uint8)(((uint16)LIN_TP_PCI_FF | \
            	  	             (*Lin_TpTxLenPtr/(uint16)LIN_TP_LEN_DELIMIT))); 
            	  	  #endif   
            	    }
            	    /* Its a CF */
            	    else
            	    {
            	  	  Lin_LastTxData       = (uint8)(((uint8)LIN_TP_PCI_CF |\
            	  	                                 (Lin_TpTxFrmSerialNo)));
            	  	  Lin_TpTxFrmSerialNo ++;          		  
            	  	  
            		    /* Increment SN, to check if its exceeding limit */
            		    if(Lin_TpTxFrmSerialNo >= (uint8)LIN_TP_MAX_SN)
            		    	{
            		        Lin_TpTxFrmSerialNo = (uint8)LIN_TP_MIN_SN;
            		      }  
            	    }
                }
              }/* End of if(Lin_TpSendMsgPndg) */
              #if  (_TP_BUFF_MGMT  == 0U)	
                else
              #endif /* _TP_BUFF_MGMT */  		
            #endif /* #ifdef LIN_V_2_1 */ 
            #if  (_TP_BUFF_MGMT  == 0U)	         	
            #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF)
              {
                Lin_LastTxData = Lin_DiagTxFifo[Lin_DiagTxFifoRdIdx]\
                                                [Lin_NumofBytesTx];
              }
            #endif /* _DGNSTC_TBUFF_SZ */
            #endif 
          }
          else
          {	
        #endif /* diag support */        
        Lin_LastTxData = Lin_FrmData[Lin_FrmBuffIdx++];
        #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
        }
        #endif /* diag support */
        /* Send data */
        idl_channel_send( Lin_LastTxData );
        /* Increment bytes count */
        Lin_NumofBytesTx++;
        /* Calculate the checksum */
        Lin_lChkSumCalc(Lin_LastTxData);
      }
    #endif /*  #if  (_FIFO == 0U) */
  }
  else
  {
    /* Update with flag i.e. LLD is not using the frame data buffer */
    Lin_BufferInUse[Lin_FlgIdx] &= (uint8)(~( (uint8)Lin_FlagVal ));
     
    wkup_bit3 = (uint8)0;
      
    #ifdef LIN_V_2_1
      /* bus is in inactive state */
      Lin_FrmSts &= ((~(uint16)( LIN_STAT_BUS_ACTVTY_VAL )));
    #endif   /* LIN_V_2_1 */          
    
    Lin_StateMachine.Lin_CommState = LIN_IDLE;/* RCV_BREAK; */
    
    #ifdef _IFC_SLAVE
      Lin_lSetFrameEror( );      
      /*
        Need to clear the timeout counter for every byte of transmission 
         to be in active state. 
         Otherwise the interface will enter sleep state after 4sec timeout 
      */
      Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
      /* clear the counter, this is used in Auto Baud interrupt */
      Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;       
      idl_cfg_atbd_dtct( );      
    #endif /* _IFC_SLAVE */  
  }     
}/* Lin_lHandleTxData */

/****************************************************************************** 
** Syntax           : Lin_lSetFrameEror                                      ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Sets error in response .                               **
**                                                                           ** 
******************************************************************************/
#ifdef _IFC_SLAVE
  void Lin_lSetFrameEror( void)
  { 
    if ( ( Lin_FrmType != (LIN_FRM_TYPE)LIN_FRM_EVNT ) && \
    	   ( Lin_NumofBytesTx > (uint8)0 ) )
    {
      /* update status info */
      if ( Lin_FrmSts & (uint16)LIN_STAT_ERROR_VAL )
      {
        Lin_FrmSts |= (uint16)LIN_STAT_OVER_RUN_VAL;
      }
      else
      {
        Lin_FrmSts |= (uint16)LIN_STAT_ERROR_VAL;
      }      
    }
    
    /* Updated status flag */
    Lin_FrmSts &= (~((uint16) (LIN_STAT_PRTCT_ID_VAL) ));
    Lin_FrmSts |= (uint16)(( (uint16)Lin_FrmId << \
                           (uint16)LIN_STAT_PRTCT_ID_LOC ));    
    /* Update transmit error status */
    #if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED)
      /*
        not an event frame and some data has been transmitted on bus
         for event triggered frame there could be collisions
      */
      /* AI00056413 fixed */
      if ( ( Lin_FrmType != (LIN_FRM_TYPE)LIN_FRM_EVNT ) && \
      	   ( Lin_NumofBytesTx > (uint8)0 ) 
      	   )
      {
        Lin_lRespFrmUpdate(LIN_RESP_ERROR_BIT_SET);
      }
      /* If state is RX_DATA, first byte may be erreneous, */
      else 
      {
        if (( Lin_FrmType != (LIN_FRM_TYPE)LIN_FRM_EVNT ) && 
        	       (LIN_RX_DATA == Lin_StateMachine.Lin_CommState ))
        {
          Lin_lRespFrmUpdate(LIN_RESP_ERROR_BIT_SET);	
        }
      }		
    #endif /* _RESP_ERR_FRM_NUM */
  
    /* The error has occurred while transmitting diagnostic frame */
    #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      Lin_lDiagErrorSts( );
    #endif /* _DGNSTC_FRM_SPRT */
  } /* Lin_lSetFrameEror */
#endif /* #ifdef _IFC_SLAVE   */

/****************************************************************************** 
** Syntax           : Lin_lDiagErrorSts                                      ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Sets error in response for diag frames                 **
**                                                                           ** 
******************************************************************************/
#ifdef _IFC_SLAVE
  #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || \
      (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 
  static void Lin_lDiagErrorSts(void)
  {  
    if ( ( (uint8)LIN_DGNSTC_REQ_FRM_NUM == Lin_RcvedFrmId )||
         ((uint8)LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId ) )
    {
      #ifdef LIN_V_2_1
        if ( (uint8)LIN_FRM_TX == Lin_FrmTxMode )
        {
          /* in-case error indicate the flag */            
          if(Lin_TpSendMsgPndg)
          {
  		      Lin_TpSendMsgPndg   = (uint8)LIN_TP_NO_TX_MSG;
            Lin_TpTxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
            Lin_TpTxSts         = (uint8)LD_FAILED;
          }
          #if  (_TP_BUFF_MGMT  == 0U)	
            /* diagnostic frame transmit error */
            else     
            {         
                Lin_DiagFifoSts     = LD_TRANSMIT_ERROR;
            }
          #endif /* _TP_BUFF_MGMT */  
        }
        else 
        {
         /* if ( (uint8)LIN_FRM_RX == Lin_FrmTxMode )*/
          {
            /* in-case error indicate the flag */
            if(Lin_TpRxMsgPndg)
            {
              Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
              Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
              Lin_TpRxSts         = (uint8)LD_FAILED;
              /* UTP AI00059568 fixed */
              Lin_TpRxFrm         = 0U;
            }  
            #if  (_TP_BUFF_MGMT  == 0U)	  
              /* diagnostic frame receive error */
              else
              	{
                  Lin_DiagFifoSts     = LD_RECEIVE_ERROR;
                }
            #endif /*_TP_BUFF_MGMT */       
          }
        }
      #else
        /* Diagnostic frame transfer error */
        Lin_DiagFifoSts         |= (uint16)LD_TRANSFER_ERROR;
      #endif   /* LIN_V_2_1 */
    }  
    else
    {
      /*Nothing*/
    }
  }/* Lin_lDiagErrorSts */          
#endif /* Diags */
#endif /* #ifdef _IFC_SLAVE */
/****************************************************************************** 
** Syntax           : Lin_lHandleRxTxChkSum                                  ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                          **  
**                                                                           ** 
** Parameters(in)   : received byte                                          ** 
**                                                                           ** 
** Parameters (out) : None                                                   ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Once Checksum is sent/received, verifies the checksum  **
**                    byte and sets the status accordingly                   **
**                                                                           ** 
******************************************************************************/
static void Lin_lHandleRxTxChkSum(uint8 rcvd_data)      
{
  /* Frame transmission timeout is reached */
  #ifdef _IFC_SLAVE
    wkup_bit3 = (uint8)0;
  #endif /* _IFC_SLAVE */
  
  
  #ifdef LIN_V_2_1
    /* Bus is in inactive state */
    Lin_FrmSts &= (~( (uint16)LIN_STAT_BUS_ACTVTY_VAL ));
  #endif   /* LIN_V_2_1 */  
  
  Lin_StateMachine.Lin_CommState = LIN_IDLE;

  /*
   This is valid irrespective of successful/failure of frame transmission
   Update with flag i.e. LLD is not using the frame data buffer
  */
  Lin_BufferInUse[Lin_FlgIdx] &= (uint8)((~( (uint8)Lin_FlagVal )));

  /* Updated status flag, update the last Frame ID. */
  Lin_FrmSts &= (~((uint16) LIN_STAT_PRTCT_ID_VAL ));
  Lin_FrmSts |= (uint16)(( (uint16)Lin_FrmId <<(uint16)LIN_STAT_PRTCT_ID_LOC));
  
  /* Lin_ChkSum received correctly */
  if ( ( Lin_ChkSum & (uint8)LIN_BYTE_EXTRACT ) == rcvd_data )
  {
    /* TX mode */
    if ( (uint8)LIN_FRM_TX == Lin_FrmTxMode )
    {
      Lin_lHandleTxChkSum( );
    }
    /* RX mode */
    else
    {
      Lin_lHandleRxChkSum( );
      
      #ifdef _LIN_FRAME_CNT 
        #ifdef LIN_V_2_1
          /* If Frame ID is not diagnostic ID, increment the count */ 
          if ( ( Lin_RcvedFrmId < (uint8)LIN_DGNSTC_REQ_FRM_NUM ) &&
          	   ( (LIN_FRM_TYPE)LIN_FRM_EVNT != Lin_FrmType )
          	 )  
          {
            FrmId_FrmCntIncr(Lin_RcvedFrmId & (uint8)LIN_GET_FRAME_ID);
          }	  
        #endif    
      #endif /* #ifdef _LIN_FRAME_CNT  */
    }   
    /* update status info */
    if ( Lin_FrmSts & (uint16)LIN_STAT_SUCCESS_VAL )
    {
      Lin_FrmSts |= (uint16)LIN_STAT_OVER_RUN_VAL;
    }
    else
    {
      Lin_FrmSts |= (uint16)LIN_STAT_SUCCESS_VAL;
    }    
  }/*if(Lin_ChkSum == rcvd_data) */

  #ifdef _IFC_SLAVE
    else
    {
      Lin_lSetFrameEror( );        
      Lin_FrmDataUpdtFlag[Lin_FlgIdx] &= ((uint8)~( Lin_FlagVal ));
      /* Frame data is lost */        
    }/*end of else(Lin_ChkSum == rcvd_data) */
  #endif /* _IFC_SLAVE */
  
  #if((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
    if ((LIN_BUS_STATE)LIN_ACTIVE == Lin_BusState )
  #endif
      {
        /*
         Need to clear the timeout counter for every byte of transmission 
         to be in active state. 
         Otherwise the interface will enter sleep state after 4sec timeout 
         */
        Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
        /*
         clear the counter, this is used in LIN_IFX_T2_ISR
         */
        Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;
        /* --- Add Code to disable UART for 8 bit here */
        
        /*  --- Add Code to disable UART for 8 bit here */
        
        /* To make sure Autobaud feature is running */
        idl_cfg_atbd_dtct();        
      }  /* */
}/* Lin_lHandleRxTxChkSum */
      
/****************************************************************************** 
** Syntax           : Lin_lHandleTxChkSum                                    ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Handles the frame once checksum is received correctly  **
**                                                                           ** 
******************************************************************************/
static void Lin_lHandleTxChkSum(void)
{
	#ifdef _IFC_SLAVE 
    #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      /* Is diagnostic frame */
      if ( ( (uint8)LIN_DGNSTC_REQ_FRM_NUM == Lin_RcvedFrmId ) ||
           ((uint8)LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId ) )
      {
        #ifdef LIN_V_2_1          	
          /* Check if TP message reception is complete. */
          if(Lin_TpSendMsgPndg)
          {
            /* If all the TP packets are transmitted, update the status. */
            #if  (_TP_BUFF_MGMT  == 1U)
              if ( Lin_TpBytesTxed  >= Lin_TpTxLenPtr )
            #else
              if ( Lin_TpBytesTxed  >= *Lin_TpTxLenPtr )
            #endif  	
	            {
                Lin_TpTxSts = (uint8)LD_COMPLETED;
                /* Call the Call back here */
	            }
	            /* No time out required */
              Lin_TpTxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
          }/* End of if(Lin_TpRxMsgPndg) */
        #else /*#ifndef LIN_V_2_1*/			
          /* transmission is success */
          Lin_DiagFifoSts &= (uint16)((uint16)~ ( 4U/* LD_TRANSFER_ERROR*/ ));
        #endif   /* LIN_V_2_1 */
      }
    
      /*
        If the frame is slave response frame update diagnostic frame TX
         buffer Adjust diagnostic frame TX buffer pointers, decrease TX
         buffer level by 1
      */
      if ( (uint8)LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId )
      {
      	#if  (_TP_BUFF_MGMT  == 1U)
      	  /* if(Lin_TpSendMsgPndg) */
      	  {
      	    if(Lin_TpTxSts == (uint8)LD_COMPLETED) 
      	    {	
      	    	Lin_TpSendMsgPndg = (uint8)LIN_TP_NO_TX_MSG;
      	    }
      	  }  	
      	#else
          #ifdef LIN_V_2_1
            /* If not TP packet adjust the diag buffer levels */
            if(!Lin_TpSendMsgPndg)
          #endif /* #ifdef LIN_V_2_1 */ 
                    	
          #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF)            
            {
              Lin_DiagTxFifoLvl--;
              
              Lin_DiagTxFifoRdIdx++;
              if ( Lin_DiagTxFifoRdIdx >= (uint8)_DGNSTC_TBUFF_SZ )
              {
                Lin_DiagTxFifoRdIdx = (uint8)0;
              }
            }
            #ifdef LIN_V_2_1            
              /* Make transmission complete */
              else if(Lin_TpTxSts == (uint8)LD_COMPLETED)
              	{
                  Lin_TpSendMsgPndg = (uint8)LIN_TP_NO_TX_MSG;
                }
              else
              {
                /*Nothing*/
              }
            #endif /* #ifdef LIN_V_2_1 */			        
          #endif/* _DGNSTC_TBUFF_SZ */
        #endif   
      }
    #endif /* _DGNSTC_FRM_SPRT */
    
    #ifdef _LIN_FRAME_CNT 
      #ifdef LIN_V_2_1
        /* If Frame ID is not diagnostic ID, increment the count */ 
        if (( Lin_RcvedFrmId < (uint8)LIN_DGNSTC_REQ_FRM_NUM ) &&
        	   ( (LIN_FRM_TYPE)LIN_FRM_EVNT != Lin_FrmType )
        	 ) 
        {
          FrmId_FrmCntIncr(Lin_RcvedFrmId & (uint8)LIN_GET_FRAME_ID);	
        }	 
      #endif /* #ifdef LIN_V_2_1 */     
    #endif   /* _LIN_FRAME_CNT */
    
    {
      Lin_FrmDataUpdtFlag[Lin_FlgIdx] &= ((uint8)~( Lin_FlagVal ));
    }
    
    /* Clear Response Error Bit */
    #if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED)
      if(Lin_Status_FrmID == Lin_RcvedFrmId )
      {	
        Lin_lRespFrmUpdate(LIN_RESP_ERROR_BIT_CLR);
      }  
    #endif /* _IFC_RESP_ERR_FRM_NUM */
    /* Clear Response Error Bit */
  #endif /*_IFC_SLAVE */  
}/* Lin_lHandleTxChkSum */
    
/****************************************************************************** 
** Syntax           : Lin_lEventFrmDataCopy                                  ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Copies the data for event triggered frame to           ** 
**                    associated unconditional Frame ID location             **
**                                                                           ** 
******************************************************************************/
#if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
  #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)
    static void  Lin_lEventFrmDataCopy(void)
    {
    	uint8 nloop , frm_index;
    	/* The first byte is reserved for the protected identifier */
      #ifdef LIN_V_2_1       
       frm_index = (uint8) LIN_SYS_NUM_FRMS;  /* UTP 0 */         
       for ( nloop = (uint8)0; nloop < (uint8)LIN_SYS_NUM_FRMS; nloop++ )
       {                  
         if ( Lin_FrmTbl[nloop] ==         
          ( Lin_FrmData[LIN_SYS_TOTAl_FRM_BUFF_SZ] & (uint8)LIN_GET_FRAME_ID ))
         {                  
           frm_index = nloop;                  
           break;                  
         }                  
       }                  
      #else                  
        frm_index =                  
            (Lin_FrmData[LIN_SYS_TOTAl_FRM_BUFF_SZ] & (uint8)LIN_GET_FRAME_ID);
      #endif   /* LIN_V_2_1 */                  
      
      if (( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_REG_ID_MSK ) && 
      	  ( frm_index !=  LIN_SYS_NUM_FRMS ) 
      	  ) 
      {
        /*  calculate buffer index */                 
        if ( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_OFFSET_MSK )
        {
          Lin_FrmBuffIdx = (uint16)((uint16)LIN_FRM_HIGHER_OFFSET + 
                         (uint16)Lin_FrmOffset[frm_index]);
        }
        else
        {
          Lin_FrmBuffIdx = (uint16)Lin_FrmOffset[frm_index];
        }
        /* Frame length of the received PID */
        Lin_FrmLen =
               (( Lin_FrmInfo[frm_index] & (uint8)LIN_SYS_FRM_INFO_LEN_MASK )
                + (uint8)1);
      
        /* Index pointers*/
        Lin_FlgIdx = ( frm_index >> 3 );
        Lin_FlagVal = (uint8)(( (uint16)0x01 << ( frm_index & (uint16)0x07 ) ));
        
        /* Update the usage flag of the received frame ID */
        Lin_BufferInUse[Lin_FlgIdx] |= Lin_FlagVal;
          
        /* Copy the data to the correct location as defined by Lin_FrmInfo */
        for ( nloop = (uint8)0; nloop < Lin_FrmLen; nloop++ )
        {
          Lin_FrmData[Lin_FrmBuffIdx + nloop] =
                Lin_FrmData[(uint16)LIN_SYS_TOTAl_FRM_BUFF_SZ + nloop];
        }
          
        /*
         Update the usage and updated data flags of the received frame ID
        */
        Lin_BufferInUse[Lin_FlgIdx]       &= ((uint8)~( Lin_FlagVal ));
        Lin_FrmDataUpdtFlag[Lin_FlgIdx] |= Lin_FlagVal;
      }
    }/* Lin_lEventFrmDataCopy */ 
  #endif /* Event frame defined */
#endif /* Event support */           
/****************************************************************************** 
** Syntax           : Lin_lHandleRxChkSum                                    ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Handles the frame once checksum is received correctly  **
**                                                                           ** 
******************************************************************************/
#if  (_TP_BUFF_MGMT  == 0U) 
/*lint -e438 */	
/*lint -e550 */
#endif /* #if  (_TP_BUFF_MGMT  == 0U)  */
static void Lin_lHandleRxChkSum(void)
{
	uint8 retVal ;
		
  #ifdef _IFC_SLAVE	
    #if( (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      #ifdef LIN_V_2_1     
         	
        /* Check if TP message reception is complete. */
        if(Lin_TpRxMsgPndg)
        {
        	/*
        	  If all the TP packets are received, update the status
        	   and update the actual length received.
        	*/
          if ( Lin_TpBytesRxed  >= Lin_TpNoBytesTobeRxed )
        	{
        	  Lin_TpRxSts     = (uint8)LD_COMPLETED;
        	  
        	  /* Call back function */
        	  #if  (_TP_BUFF_MGMT  == 1U) 
              /* Check if its a Assign NAD , Assign Frame ID command, if yes
                 no call back should be called. 
              */
              if(((uint8)LIN_DIAG_ASSIGN_NAD_SID == Lin_TpRxBuff [0]) ||
              	  ( ((uint8)LIN_DIAG_READ_BY_ID_SID == Lin_TpRxBuff [0]) &&
              	    ((uint8)LIN_DIAG_READ_BY_ID_00  == Lin_TpRxBuff [1])
              	  ) ||
              	  (
              	    ((uint8)LIN_DIAG_CONDITIONAL_NAD == Lin_TpRxBuff [0])  && 
              	    ((uint8)LIN_DIAG_READ_BY_ID_00   == Lin_TpRxBuff [1])
              	  ) ||  
              	#ifdef LIN_V_2_1
              	  ((uint8)LIN_DIAG_ASSIGN_FRM_ID_RANGE_SID == Lin_TpRxBuff [0])
              	#else
                  ((uint8)LIN_DIAG_ASSIGN_FRM_ID_SID == Lin_TpRxBuff [0])
                #endif /* */                    	                 	   
                )
              {
              	retVal = Lin_lHandleNodeConfig(Lin_TpRxBuff);               		
              }
              else
              {		
                /* */        	  
          	    retVal = Lin_TpCallBack ( Lin_TpRxBuff , 
          	                              /* Lin_TpBytesRxed , */
          	                              Lin_TpNoBytesTobeRxed,
          	                              Lin_TpTxBuff ,
          	                              &Lin_TpTxLenPtr 
          	                            );
          	  }  	                          
        	    /* returns 1 if response is prepared */                        
        	    if((uint8)1 == retVal)
        	    {             
        	    	if((uint8)LD_IN_PROGRESS != Lin_TpTxSts)
        	      {
        	        if( Lin_TpTxLenPtr <= (uint8)LIN_TP_SF_LEN )
        	        {
        	          Lin_TpTxFirstFrm = (uint8)LIN_TP_SF;	
        	        }	
        	        else
        	        {
        	        	 Lin_TpTxFirstFrm = (uint8)LIN_TP_FF;
        	        }	
        	        Lin_TpTxFrmSerialNo = (uint8) 1;
        	        Lin_TpTxRdIndex     = (uint8) 0; 
        	        Lin_TpBytesTxed     = (uint16) 0;
        	        Lin_TpSendMsgPndg   = (uint8) LIN_TP_TX_PNDG;
        	      }
        	    }
        	  #else
        	    *Lin_TpRxLenPtr = Lin_TpBytesRxed;
        	            	    
              if(((uint8)LIN_DIAG_ASSIGN_NAD_SID == *((Lin_TpRxDataPtr - Lin_TpBytesRxed) + 0)) ||
              	  (((uint8)LIN_DIAG_READ_BY_ID_SID == *((Lin_TpRxDataPtr - Lin_TpBytesRxed) + 0))&&
              	    ((uint8)LIN_DIAG_READ_BY_ID_00 == *((Lin_TpRxDataPtr - Lin_TpBytesRxed) + 1))
              	  ) ||
              	  (
              	   ((uint8)LIN_DIAG_CONDITIONAL_NAD ==*((Lin_TpRxDataPtr - Lin_TpBytesRxed) + 0))&& 
              	   ((uint8)LIN_DIAG_READ_BY_ID_00 == *((Lin_TpRxDataPtr - Lin_TpBytesRxed) + 1))
              	  ) ||  
              	 #ifdef LIN_V_2_1
              	   ((uint8)LIN_DIAG_ASSIGN_FRM_ID_RANGE_SID == 
              	        *((Lin_TpRxDataPtr-Lin_TpBytesRxed) + 0))
                #endif /* */                    	                 	   
                )
              {
              	retVal = Lin_lHandleNodeConfig((Lin_TpRxDataPtr - Lin_TpBytesRxed));               		
              }
              else
              {		        	    
        	      retVal = Lin_TpCallBack ( (Lin_TpRxDataPtr - Lin_TpBytesRxed) , 
        	                               /* Lin_TpBytesRxed , */
        	                               Lin_TpNoBytesTobeRxed,
        	                                LIN_NULL_DATA,
        	                                LIN_NULL_DATA 
        	                              );
        	    }
        	  #endif /* _TP_BUFF_MGMT */  
        	}  /* End of if ( Lin_TpBytesRxed  == Lin_TpNoBytesTobeRxed ) */
	        Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
        }/* End of if(Lin_TpRxMsgPndg) */
        /* Clear the flag to ignore the funct req in between transmission */
        if(Lin_FuncReq)
        {	
          Lin_FuncReq	 = 0U;
        }/* if(Lin_FuncReq) */  
      #endif /* #ifdef LIN_V_2_1 */
    #endif /* (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) */
       
    #if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)
        /*
         By default the interface will received the data in-case the PID
         is event triggered frame and interface has not data to publish.
         The received data stored in Lin_FrmInfo at
         LIN_SYS_TOTAl_FRM_BUFF_SZ location.
        
         This is the frame ID for the rest of the data.
        
         If Lin_FrmInfo[LIN_SYS_TOTAl_FRM_BUFF_SZ] is registered PID
         then the data will be copied to the corresponding location as
         specified by Lin_FrmInfo table.
        */
        if ((LIN_FRM_TYPE)LIN_FRM_EVNT == Lin_FrmType  )
        {                  
          Lin_lEventFrmDataCopy();
        }
        else
      #endif
    #endif   /*event/sporadic frame support */
    
    #if((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) || (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED))
      /* may be sleep command from master */
      if ( (uint8)LIN_DGNSTC_REQ_FRM_NUM == Lin_RcvedFrmId )
      {
        if ( (uint8)LIN_DIAG_SLP_CMD == Lin_RxFirstByte )
        {
          /* enter into sleep state */
          Lin_BusState   = LIN_SLPNG;
          Lin_StateMachine.Lin_CommState = LIN_IDLE;
      
          /* update status flag */
          Lin_FrmSts |= (uint16)LIN_STAT_SLP_VAL;            
          /* Disable UART here for 8 bit */
          /* IDL_DIS_CHANNEL(); */
          /* Disable UART here for 8 bit */ 
          /* stop wakeup timer */
          IDL_STOP_TIMEOUT_TIMER();
                    
          idl_Restart_AutoBaud( );
                    
          #ifdef LIN_V_2_1               
           /* if( (uint8)LD_COMPLETED == Lin_TpRxSts)*/
  	        {
  	          Lin_TpRxMsgPndg = (uint8)LIN_TP_NO_RX_MSG;
  	        }
	        #endif /* #ifdef LIN_V_2_1   */ 
        }
        else
        {
          /*
           in-case of master command frame call LIN_nw_resp_mngr API
           with the received data to analyze the data and make the
           necessary changes to configurations and to send the response
           */
          #if (((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)  ) )
            /*
              Adjust diagnostic frame RX buffer write pointers
               and increase RX buffer level by 1
            */
            #if  (_TP_BUFF_MGMT  == 1U)
						  if( (uint8)LD_COMPLETED == Lin_TpRxSts)
	            {
	              Lin_TpRxMsgPndg = (uint8)LIN_TP_NO_RX_MSG;
	            }             
            #else
              #ifdef LIN_V_2_1               
                if(!Lin_TpRxMsgPndg)
                {
              #endif /* #ifdef LIN_V_2_1 */                
                  #if (_DGNSTC_RBUFF_SZ > LIN_DIAG_RFIFO_NOT_DEF) 
                    /* If NAD is correct */
                     if(((Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][0] == Lin_NAD) &&
                     	  ((uint8)LIN_DIAG_ASSIGN_NAD_SID != Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2]))||
                     	  (
                     	   (Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][0] == Lin_InitNAD) &&
                     	   ((uint8)LIN_DIAG_ASSIGN_NAD_SID == Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2])
                     	  ) ||
    	  	              (LIN_BROADCAST == Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][0])
    	  	             )  
                    {	                               
                      if(( (uint8)LIN_DIAG_ASSIGN_NAD_SID == 
                      	   Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2]) ||
                        ( 
                          ((uint8)LIN_DIAG_READ_BY_ID_SID == 
                           Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2]) &&
                          ((uint8)LIN_DIAG_READ_BY_ID_00 == 
                            Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][3])
                        ) ||
                        (
                          ((uint8)LIN_DIAG_CONDITIONAL_NAD == 
                            Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2])  && 
                          ((uint8) LIN_DIAG_READ_BY_ID_00 == 
                            Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][3])
                        ) ||  
                        #ifdef LIN_V_2_1
                          ((uint8)LIN_DIAG_ASSIGN_FRM_ID_RANGE_SID == 
                            Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2])
                        #else
                          ((uint8)LIN_DIAG_ASSIGN_FRM_ID_SID == 
                            Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2])
                        #endif /* */                    	                 	   
                        )                  
                      {
                        retVal = Lin_lHandleNodeConfig
                                    (
                                    &Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2]
                                    );
                      }
          					  else if((LIN_DIAG_READ_BY_ID_SID ==                          
                                         Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2]))
          					  {
                        retVal =   Lin_TpCallBack 
                          	          (&Lin_DiagRxFifo[Lin_DiagRxFifoWrIdx][2],
          						                 8U,
          										         LIN_NULL_DATA,
          										         LIN_NULL_DATA
          										         );          										         
          					  }
                      else
                      {	
                        Lin_DiagRxFifoWrIdx++;
                        Lin_DiagRxFifoLvl++;
                        if ( Lin_DiagRxFifoLvl >= (uint8)_DGNSTC_RBUFF_SZ )
                        {
                          Lin_DiagRxFifoLvl = (uint8)_DGNSTC_RBUFF_SZ;
                        }
                        if ( Lin_DiagRxFifoWrIdx >= (uint8)_DGNSTC_RBUFF_SZ )
                        {
                          Lin_DiagRxFifoWrIdx = (uint8)0;
                        }                     
                      }/* */  
                    }                 
                  #endif /* _TP_BUFF_MGMT */             
                  #ifdef LIN_V_2_1                
                }/* End of if(!Lin_TpRxMsgPndg) */
	              else 
	              {	
	                if( (uint8)LD_COMPLETED == Lin_TpRxSts)
	                {
	                  Lin_TpRxMsgPndg = (uint8)LIN_TP_NO_RX_MSG;
	                } 
	              }  
              #endif /*  #ifdef LIN_V_2_1 */
            #endif /* _TP_BUFF_MGMT */  
          #endif/* diag support */
        }
      }
      else
    #endif   /* sleep/wakeup support */
      {
        Lin_FrmDataUpdtFlag[Lin_FlgIdx] |= ( Lin_FlagVal );
      }
  #endif /* Slave */  
}   /* Lin_lHandleRxChkSum */
#if  (_TP_BUFF_MGMT  == 0U) 
/*lint +e438 */    
/*lint +e550 */  
#endif /* #if  (_TP_BUFF_MGMT  == 0U)  */
/****************************************************************************** 
** Syntax           : Lin_lHandleIDLE                                        ** 
**                                                                           ** 
** Service ID       : none / NA                                              ** 
**                                                                           ** 
** Sync/Async       : Synchronous                                            ** 
**                                                                           ** 
** Reentrancy       : non-reentrant                                          **  
**                                                                           ** 
** Parameters(in)   : received byte                                          ** 
**                                                                           ** 
** Parameters (out) : None                                                   ** 
**                                                                           ** 
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Handles the frame once checksum is received correctly  **
**                                                                           ** 
******************************************************************************/
static void  Lin_lHandleIDLE( uint8 rcvd_data )
{
	uint8 flag_val = (uint8) 1;	 
  
  #ifdef _IFC_SLAVE	
    #if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      switch ( Lin_BusState )
      {
        /* Received its own wakeup signal, set in l_ifc_wake_up API */
        case LIN_WKUP:
        {
          /*Increment a counter to indicate the number of wakeup signals sent*/
          Lin_WkupRetryCnt ++;
        
          if (Lin_WkupRetryCnt <= (uint8)LIN_WKUP_CNT_4 )
          {
            /* Start wakeup timer */
            wkup_bit2 = (uint8)1;         
          }
          else 
          {
            /*
             If 3 successive wakeup signals have already been sent,
             enter into active state.
            
             If there is no response from master with 4 sec, slave enters 
             in sleep state again.
            
             Therefore set the state to ACTIVE to ensure wait till 4secs.
            */
            Lin_BusState = LIN_ACTIVE;
          }
          /*
           This value is incremented in sleep/wakeup timer ISR and checked for
           maximum wait time to get response from master. in-case of no 
           response, slave continues to issue wakeup signal.
           */
          Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
          
          /*clear the counter, this is used in Autobaud ISR */
          Lin_AutoBaudBitCtr = (uint8) LIN_BREAK_BIT;
          /*
            Get ready to receive frame header from master, which is handled
             by autobaud ISR.
          */
          idl_cfg_atbd_dtct();
          /* set state to default receiving break state */
          Lin_StateMachine.Lin_CommState = LIN_IDLE;
        }
        break;
    
        /* Received wakeup signal from others */
        case LIN_SLPNG:
        {
          flag_val = (uint8)0;
          /* wakeup signal must be between 250us to 5sec */
          if( (uint8)0 == ( rcvd_data & (uint8)LIN_WAKBYTE_EXTRACT ) )
          {
            flag_val = ( uint8 ) 1;
            /* 
              Set state as active while waiting for the frame 
               header from master           
            */
            Lin_BusState = LIN_ACTIVE;
            /* UART RX interrupt will not occur in-case of invalid stop bit */
            IDL_EN_CHANNEL();
    
            /*
             This value is incremented in sleep/wakeup timer ISR and checked 
              for maximum wait time to get response from master. in-case of no 
              response, slave continues to issue wakeup signal.
             */
            Lin_CurrTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
            
            /*clear the counter, this is used in Autobaud ISR */
            Lin_AutoBaudBitCtr = (uint8) LIN_BREAK_BIT;
            /*
              Get ready to receive frame header from master, which is handled
               by autobaud ISR.
            */
            idl_cfg_atbd_dtct();
            /* set state to default receiving break state */
            Lin_StateMachine.Lin_CommState = LIN_IDLE;/* RCV_BREAK; */               
          }
        }/*case SLP_PNDG / SLPNG*/
        break;
        
        default:
        break;
      }/*end of switch(ifc_state) */
      
      if ( flag_val == (uint8)1 )
      {
        /* Load timer registers, used for sleep/wakeup and timeout */
	  	  idl_load_new_timeout((uint16)LIN_CFG_TMR_TICKS);
      }
    #endif   /*sleep and wakeup support */
    
    #ifdef LIN_V_2_1
      /* Indicate that bus is in active due to own/external wakeup signal */
      Lin_FrmSts |= (uint16)LIN_STAT_BUS_ACTVTY_VAL;
    #endif/* LIN_V_2_1 */
  #endif /* Slave */  
}/* Lin_lHandleIDLE */	

/****************************************************************************** 
** Syntax           : Lin_lTpTimeOutChk                                      ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Takes care of the timeout for TP packets               **
**                                                                           ** 
******************************************************************************/
#ifdef _IFC_SLAVE
  #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
  #ifdef LIN_V_2_1
    static void Lin_lTpTimeOutChk(void)  
    { 
      /* Check for Time Out in-case of TP message is in progress */
      if( (uint8)LIN_TP_TX_PNDG == Lin_TpSendMsgPndg )
      {
      	/* Increment TP time out variables */  
      	Lin_TpTxTimeOutCntr += (uint16)_TMR_BASE;
        if(Lin_TpTxTimeOutCntr > (uint16)LIN_TP_N_AS_TIME)
        {
          Lin_TpTxSts         = (uint8)LD_N_AS_TIMEOUT;
          Lin_TpSendMsgPndg   = (uint8)LIN_TP_NO_TX_MSG;
          Lin_TpTxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
        }
      }
      if( (uint8)LIN_TP_RX_PNDG == Lin_TpRxMsgPndg )      
      {
      	/* Increment TP time out variables */  
      	Lin_TpRxTimeOutCntr += (uint16)_TMR_BASE;
        if(Lin_TpRxTimeOutCntr > (uint16)LIN_TP_N_CR_TIME)
        {
          Lin_TpRxSts          = (uint8)LD_N_CR_TIMEOUT;
          Lin_TpRxMsgPndg      = (uint8)LIN_TP_NO_RX_MSG;
          Lin_TpRxTimeOutCntr  = (uint16)LIN_NO_TIMEOUT;
          /* UTP AI00059568 fixed */
          Lin_TpRxFrm          = 0U;
        }
      }
    }/* Lin_lTpTimeOutChk */  
  #endif /* #ifdef LIN_V_2_1 */  
#endif /* Diags */
#endif /* _IFC_SLAVE */
/****************************************************************************** 
** Syntax           : Lin_lSlaveTimeOutActive                                ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Takes care frame response timeouts and IDLE timeout    **
**                                                                           ** 
******************************************************************************/
#ifdef _IFC_SLAVE   
  static void Lin_lSlaveTimeOutActive(void)
  {
  	uint8 frm_index = (uint8)0;
  	  	  	
    /* Frame transmission is going on, but full frame is not received */
    if ( wkup_bit3 )
    {
      if ( Lin_CurrTimeOutCntr > Lin_CurrSlotTimeOut )
      {
        wkup_bit3 = (uint8)0;    
        #ifdef LIN_V_2_1
          /* Bus is in inactive state, may be set in T2 ISR falling edge */
          /* Lin_FrmSts &= ~( LIN_STAT_BUS_ACTVTY_VAL );*/
        #endif/* LIN_V_2_1 */
                  
        /* Update with flag i.e. LLD is not using the frame data buffer */
        #ifdef LIN_V_2_1
          frm_index = Lin_lGetFrmIdx(Lin_RcvedFrmId);
        #else
          frm_index = Lin_RcvedFrmId;
        #endif/* LIN_V_2_1 */
  
        Lin_BufferInUse[( frm_index >> (uint8)3 )] &= 
               (uint8)(~((uint8)( (uint16)0x01 << (uint16)(( frm_index & (uint16)0x07 ))) ));
                          
        #if (_IFC_RESP_ERR_FRM_NUM != -1)
          /* Is event triggered frame  collision occurred */
          /* AI00056413 fixed */
          if ( ( Lin_FrmType != (LIN_FRM_TYPE)LIN_FRM_EVNT ) && 
          	   ( Lin_NumofBytesTx > (uint8)0 ) &&           	   
		         (LIN_IDLE != Lin_StateMachine.Lin_CommState) &&  
		         (LIN_PID != Lin_StateMachine.Lin_CommState)		                   	   
          	 )
          {
            Lin_lRespFrmUpdate(LIN_RESP_ERROR_BIT_SET);
          }
        #endif/* _IFC_RESP_ERR_FRM_NUM */
        
        /* The error has occurred while transmitting diagnostic frame */
        #if  (_TP_BUFF_MGMT  == 0U)	
          #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
            if( ((uint8)LIN_DGNSTC_REQ_FRM_NUM == Lin_RcvedFrmId ) ||
                ((uint8)LIN_DGNSTC_RESP_FRM_NUM == Lin_RcvedFrmId )  )
            {              	
              #ifdef LIN_V_2_1
                if ( (uint8)LIN_FRM_TX == Lin_FrmTxMode )
                {
                  Lin_DiagFifoSts = LD_TRANSMIT_ERROR;
                }
                else 
                {
                  /* if ( (uint8)LIN_FRM_RX == Lin_FrmTxMode ) */
                  {          	    
                    Lin_DiagFifoSts = LD_RECEIVE_ERROR;
                  }
                }  
              #else
                Lin_DiagFifoSts |= (uint16)4U;/* LD_TRANSFER_ERROR;*/
              #endif   /* LIN_V_2_1 */                
            }
          #endif  /* Diags Support */
        #endif  /* _TP_BUFF_MGMT */  
  
        if ( Lin_FrmType != (LIN_FRM_TYPE)LIN_FRM_EVNT )
        {
          /*  Update status info */
          if ( Lin_FrmSts & (uint16)LIN_STAT_ERROR_VAL )
          {
            Lin_FrmSts |= (uint16)LIN_STAT_OVER_RUN_VAL;
          }
          else
          {
            Lin_FrmSts |= (uint16)LIN_STAT_ERROR_VAL;
          }
        }/* if ( Lin_FrmType != (uint8)LIN_FRM_EVNT ) */
        
        /* Updated status flag */
        Lin_FrmSts &= (~((uint16) (LIN_STAT_PRTCT_ID_VAL) ));
        Lin_FrmSts |= (uint16)(( (uint16)Lin_FrmId << \
                               (uint16)LIN_STAT_PRTCT_ID_LOC ));
        
        
        /*
         Restart the detection of break/sync pair, irrespective of
         ifc_curr_status, therefore stop autobaud detection.
        */
        /*IDL_STOP_ATBD_DTCT_P();*/
        idl_Restart_AutoBaud( );       
       
        /* Clear the counter, this is used in autobaud ISR */
        Lin_AutoBaudBitCtr = (uint8)LIN_BREAK_BIT;
        
        /* set state to default.(receiving break state) */
        Lin_StateMachine.Lin_CommState = LIN_IDLE;/* RCV_BREAK; */
      }/* if ( Lin_CurrTimeOutCntr > Lin_CurrSlotTimeOut ) */
    }/* if ( wkup_bit3 ) */
    
    #if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      /* Check if bus is idle for 4 seconds */
      else 
      {	
        if ( Lin_CurrTimeOutCntr > (uint16)LIN_CFG_SLEEP_TIME )
        {
          /* stop timer. */
          IDL_STOP_TIMEOUT_TIMER();
          /* set state as sleeping state */
          Lin_BusState = LIN_SLPNG;          
          global_flag_val   = (uint8)1; /*  flag_val = 1;  */
          /* set 4s_Idle flag */
          Lin_4sIdle = (uint8)LIN_BUS_IDLE_4S;  
                  
          #ifdef LIN_V_2_1
            /* Bus is in inactive state  */
            Lin_FrmSts &= (uint16)(~( (uint16)LIN_STAT_BUS_ACTVTY_VAL ));
          #endif/* LIN_V_2_1 */
        }/* else if ( Lin_CurrTimeOutCntr > LIN_CFG_SLEEP_TIME ) */
      } 
    #endif/* ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) */
      
    #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
      #ifdef LIN_V_2_1      
        Lin_lTpTimeOutChk( );
      #endif /* #ifdef LIN_V_2_1 */      
    #endif /* */     
   /* return(flag_val); */
  }/* Lin_lSlaveTimeOutActive */      
#endif /* #ifdef _IFC_SLAVE    */
/****************************************************************************** 
** Syntax           : Lin_lSlaveTimeOutWakUp                                 ** 
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
** Return value     : NA                                                     ** 
**                                                                           ** 
** Description      : Takes care of sending multiple Wake up signals         **
**                                                                           ** 
******************************************************************************/
#ifdef _IFC_SLAVE
  #if ((_WKUP_SLP_SPRT == LIN_SLP_WKUP_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))
  static uint8 Lin_lSlaveTimeOutWakUp(void)
  {
  	uint8 flag_val = (uint8)0;
  	 
    /* own wakeup signal, if received by UART */  
    /* UTP AI00059574  is fixed */
    if ( wkup_bit2 )
    {
      if (Lin_WkupRetryCnt < (uint8)LIN_WKUP_CNT_4) 
      {
        /*
         Wait for a maximum of 150ms, if frame header received from master 
          then state set it as active. Else send next wakeup signal
        */
        if ( Lin_CurrTimeOutCntr >= (uint16)LIN_CFG_WKUP_RESP_WAIT_TIME )
        {
          /* Send next wakeup signal, if counter is then wait for 1.5 */            
          flag_val = (uint8)2;
        }
      }
      else
      {  
        /* Wait for 1.5 seconds before sending 4th wakeup signal  */
        if ( Lin_CurrTimeOutCntr >= (uint16)LIN_CFG_WKUP_RESP_MAX_WAIT_TIME )
        {
          flag_val = (uint8)2;
        }
      } 
    }
    return(flag_val);
  }  /* Lin_lSlaveTimeOutWakUp */   
#endif /* _WKUP_SLP_SPRT */  
#endif /* _IFC_SLAVE */

/******************************************************************************
** Syntax           : Lin_lPrepareTpBuffer                                   **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : Length of TP frame and the buffer pointer for data     **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : Local API to prepare the buffer                        **
**                                                                           **
******************************************************************************/
#if  (_FIFO == 1U)
#ifdef LIN_V_2_1
/*lint -e818 */
static uint8 Lin_lPrepareTpBuffer( uint16 *u16Len , uint8 *u8Data)
{  
  uint8   u8BytesTxed = (uint8) 0;
  
  /* 1st byte always NAD */
  if(LIN_DIAG_ASSIGN_NAD_RSID == *u8Data)
  {
  	Lin_TempTxData[DIAG_TX_BUFF_INDEX_0] = Lin_InitNAD;
  }		
  else if (LIN_DIAG_CONDITIONAL_NAD_RSID== *u8Data)  
  {	  	
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_0] = Lin_OldNAD;
    Lin_OldNAD = Lin_NAD;
  }
  else
  {
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_0] = Lin_NAD;	
  }	
  /* 2nd Byte is PCI, if less is < 6  bytes SF */  
  /* 3rd Byte either LEN in case of FF or data */
  if (*u16Len <= (uint8)LIN_TP_SF_LEN) 
  {
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_1] = (uint8)(((uint16)LIN_TP_PCI_SF | \
                                                    *u16Len)) ;
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_2] = *u8Data;
    Lin_TpBytesTxed ++;        
  }
  /* Length is greater than 8 bytes, so can be FF or CF */
  else if( Lin_TpTxFirstFrm )
  {
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_1] = (uint8)(((uint16)LIN_TP_PCI_FF | 
                          (*u16Len/(uint16)LIN_TP_LEN_DELIMIT))); 
                          
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_2]   = (uint8)(((uint16)(*u16Len) & (uint16)(0x00FF)));                             
  }
  else
  {
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_1]  = (uint8)(((uint8)LIN_TP_PCI_CF | 
                                            (Lin_TpTxFrmSerialNo)));
    Lin_TpTxFrmSerialNo ++;          		  
    
    /* Increment SN, to check if its exceeding limit */
    if(Lin_TpTxFrmSerialNo >= (uint8)LIN_TP_MAX_SN)
    	{
        Lin_TpTxFrmSerialNo = (uint8)LIN_TP_MIN_SN;
      }  
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_2] = *u8Data;
    Lin_TpBytesTxed ++;        
  }  
  
  /* 4th , 5th , 6th 7th and 8th bytes are only data */  
  if( Lin_TpTxFirstFrm )
  {	
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_3] = *(u8Data);
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_4] = *(u8Data+1);
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_5] = *(u8Data+2);
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_6] = *(u8Data+3);
    Lin_TempTxData[DIAG_TX_BUFF_INDEX_7] = *(u8Data+4);
        
    Lin_TpTxFirstFrm = (uint8)0;
    Lin_TpBytesTxed += 5U;
  }
  else
  {	
    #if  (_TP_BUFF_MGMT  == 1U)
      if(Lin_TpBytesTxed < Lin_TpTxLenPtr )
    #else 
      if(Lin_TpBytesTxed < *Lin_TpTxLenPtr )  	
    #endif /* */  	
    {	
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_3] = *(u8Data + 1);
    }
    else
    {
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_3] = (uint8)LIN_DIAG_UNUSED_BYTE ;	
    }		  
    Lin_TpBytesTxed ++;
    
    #if  (_TP_BUFF_MGMT  == 1U)
      if(Lin_TpBytesTxed < Lin_TpTxLenPtr )
    #else 
      if(Lin_TpBytesTxed < *Lin_TpTxLenPtr )  	
    #endif /* */  	 
    { 
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_4] = *(u8Data + 2);
    }
    else  
    {
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_4] = (uint8)LIN_DIAG_UNUSED_BYTE ;	
    }		
    Lin_TpBytesTxed ++;
    
    #if  (_TP_BUFF_MGMT  == 1U)
      if(Lin_TpBytesTxed < Lin_TpTxLenPtr )
    #else 
      if(Lin_TpBytesTxed < *Lin_TpTxLenPtr )  	
    #endif /* */  	 
    { 
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_5] = *(u8Data + 3);
    }
    else  
    {
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_5] = (uint8)LIN_DIAG_UNUSED_BYTE ;	
    }		  
    Lin_TpBytesTxed ++;  
    
    #if  (_TP_BUFF_MGMT  == 1U)
      if(Lin_TpBytesTxed < Lin_TpTxLenPtr )
    #else 
      if(Lin_TpBytesTxed < *Lin_TpTxLenPtr )  	
    #endif /* */  	 
    { 
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_6] = *(u8Data + 4);
    }
    else  
    {
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_6] = (uint8)LIN_DIAG_UNUSED_BYTE ;	
    }		 
    Lin_TpBytesTxed ++;  
   
    #if  (_TP_BUFF_MGMT  == 1U)
      if(Lin_TpBytesTxed < Lin_TpTxLenPtr )
    #else 
      if(Lin_TpBytesTxed < *Lin_TpTxLenPtr )  	
    #endif /* */  	 
    { 
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_7] = *(u8Data + 5);
    }
    else  
    {
      Lin_TempTxData[DIAG_TX_BUFF_INDEX_7] = LIN_DIAG_UNUSED_BYTE ;	
    }	 
    Lin_TpBytesTxed ++;
  }/* in case if it is CF / SF */
  return(u8BytesTxed);
}/* Lin_lPrepareTpBuffer */
/******************************************************************************
** Syntax           : Lin_lReadTpBuffer                                      **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : non-reentrant                                          **
**                                                                           **
** Parameters(in)   : buffer pointer where data is available                 **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : API validates the read buffer and updates a global     ** 
**                    TP buffer.                                             **
**                                                                           **
******************************************************************************/
static void Lin_lReadTpBuffer(uint8 *u8Data)
{ 
  /* uint8 u8DataLen = (uint8) 0; */
  uint8 index     = (uint8)0 ;
  
  /* first byte should be NAD */    	 
  if((Lin_NAD      == *u8Data) ||
  	 (LIN_BROADCAST == *u8Data) ||
  	 (Lin_InitNAD  == *u8Data) 
     #ifdef LIN_V_2_1
       || (LIN_FUNCTIONAL_NAD == *u8Data)
     #endif/* LIN_V_2_1 */  	  
  	 ) 
  {
    Lin_TpRxSts  = (uint8)LD_IN_PROGRESS;
    
    /* Get the Frame type(SF/FF/CF) if FF, calculate the MSB 4 bits of length*/
    if( (uint8)LIN_TP_PCI_FF == (*(u8Data+1) & (uint8)LIN_TP_PCI_FF) )
    {
      Lin_TpNoBytesTobeRxed   = (uint16)((uint16)(*(u8Data+1)) & 
                                (uint16)LIN_TP_FRAME_LEN_MSB_EXTRACT);
      Lin_TpNoBytesTobeRxed <<= (uint8)LIN_TP_MSB_BYTE; 
      Lin_TpRxFirstFrm        = (uint8)1;  
    }    
    /* Check if its a CF, if yes validate SN */                                      
    else if( (uint8)LIN_TP_PCI_CF == (*(u8Data+1) & (uint8 )LIN_TP_PCI_CF) )  
    {
      /* Its a CF */
      Lin_TpRxFirstFrm = (uint8)0;
      /* Increment the SN, FF is SN = 0 */
      Lin_TpRxFrmSerialNo ++;
      /* Frame Counter is from 0 - 16 */
      if((uint8)LIN_TP_MAX_SN == Lin_TpRxFrmSerialNo)
      {
        Lin_TpRxFrmSerialNo = (uint8)LIN_TP_MIN_SN;
      }
      /* Validate SN, if wrong update the status */
      if( Lin_TpRxFrmSerialNo != (*(u8Data+1) & (uint8)LIN_TP_PCI_SN))
      {
        Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
        Lin_TpRxSts         = (uint8)LD_WRONG_SN;
        Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
        /* UTP AI00059568 fixed */
        Lin_TpRxFrm         = 0U;
      }  
    }
    /* SF packet */
    else 
    {
      Lin_TpNoBytesTobeRxed = ((uint16)(*(u8Data+1)) & \
                               (uint16)LIN_TP_FRAME_LEN_MSB_EXTRACT);
      Lin_TpRxFirstFrm      = (uint8)0;
    }  
    /* 3rd byte is either Length or the actual byte */
    if(Lin_TpRxFirstFrm)
    {
      Lin_TpNoBytesTobeRxed |= *(u8Data+2);    
      index     = (uint8)1;       
    }
    else
    {
      index     = (uint8)0;     
    }  
    
    /* Store data */
    for(; index < (uint8)6; index ++)
    {
      #if (_TP_BUFF_MGMT  == 1U)
        Lin_TpRxBuff[Lin_TpRxWrIndex++] = *(u8Data+2+index);
      #else      
        *Lin_TpRxDataPtr = *(u8Data+2+index);
        Lin_TpRxDataPtr ++	;
      #endif /* _TP_BUFF_MGMT */     
      
      /* Increment the length, used for actual length calculation. */
      Lin_TpBytesRxed ++;  
    }    
  }
  else
  {
    Lin_TpRxMsgPndg     = (uint8)LIN_TP_NO_RX_MSG;
    Lin_TpRxTimeOutCntr = (uint16)LIN_NO_TIMEOUT;
    /* Update the status as failed */
    Lin_TpRxSts         = (uint8)LD_FAILED;    
    /* UTP AI00059568 fixed */
    Lin_TpRxFrm         = 0U;
  }    	  	  
}/* Lin_lReadTpBuffer */
/*lint +e818 */
#endif /* #ifdef LIN_V_2_1 */
#endif /* #if  (_FIFO == 1U) */

#ifdef _LIN_FRAME_CNT 
  #ifdef LIN_V_2_1
    /**************************************************************************
    ** Syntax           : FrmId_FrmCntInit                                   **
    **                                                                       **
    ** Service ID       : none / NA                                          **
    **                                                                       **
    ** Sync/Async       : Synchronous                                        **
    **                                                                       **
    ** Reentrancy       : re-reentrant                                       **
    **                                                                       **
    ** Parameters(in)   : Frame ID                                           **
    **                                                                       **
    ** Parameters (out) : none                                               **
    **                                                                       **
    ** Return value     : NA                                                 **
    **                                                                       **
    ** Description      : API initializes the frame ID counter               ** 
    **                                                                       **
    **************************************************************************/
    l_bool FrmId_FrmCntInit ( uint8 u8FrameId ) 
    { 
    	uint8        frm_index ;
    	l_bool       ret_val ;
    	
    	#ifdef LIN_V_2_1
    	  /* Get the index, in Lin_FrmTbl[ ] */
    	  frm_index = Lin_lGetFrmIdx(u8FrameId);	
    	#endif /* LIN_V_2_1 */	
    		
    	/* If its not a valid ID */	    	
    	if( (uint8)LIN_SYS_NUM_FRMS == frm_index)      
    	{ 
    		ret_val = (l_bool)0;     		
    	}      
      else
      {
      	/* Initialize the count */  
        Lin_FrameIDCnt[frm_index]  = (uint16)0;  
        ret_val = (l_bool)1;  
      }
      return(ret_val);      
    }     
    /**************************************************************************
    ** Syntax           : FrmId_FrmCntIncr                                   **
    **                                                                       **
    ** Service ID       : none / NA                                          **
    **                                                                       **
    ** Sync/Async       : Synchronous                                        **
    **                                                                       **
    ** Reentrancy       : re-reentrant                                       **
    **                                                                       **
    ** Parameters(in)   : Frame ID                                           **
    **                                                                       **
    ** Parameters (out) : none                                               **
    **                                                                       **
    ** Return value     : NA                                                 **
    **                                                                       **
    ** Description      : API increments the frame ID counter                ** 
    **                                                                       **
    **************************************************************************/    
    void FrmId_FrmCntIncr(uint8 u8FrameId)
    {
    	uint8        frm_index ;
    	
    	#ifdef LIN_V_2_1
        /* Get the index, in Lin_FrmTbl[ ] */
    	  frm_index = Lin_lGetFrmIdx(u8FrameId);
    	#endif /* LIN_V_2_1 */  
      
      /* Increment the count */
      if( (uint8)LIN_SYS_NUM_FRMS != frm_index) 
      {	
        Lin_FrameIDCnt[frm_index] ++; 
      }  
    }    
    /**************************************************************************
    ** Syntax           : FrmId_FrmCntRead                                   **
    **                                                                       **
    ** Service ID       : none / NA                                          **
    **                                                                       **
    ** Sync/Async       : Synchronous                                        **
    **                                                                       **
    ** Reentrancy       : re-reentrant                                       **
    **                                                                       **
    ** Parameters(in)   : Frame ID                                           **
    **                                                                       **
    ** Parameters (out) : none                                               **
    **                                                                       **
    ** Return value     : NA                                                 **
    **                                                                       **
    ** Description      : API returns the frame ID counter                   ** 
    **                                                                       **
    **************************************************************************/    
    uint16 FrmId_FrmCntRead(uint8 u8FrameId)
    {
    	uint8        frm_index ;
    	uint16       ret_Val = 0U;
    	
    	#ifdef LIN_V_2_1
        /* Get the index, in Lin_FrmTbl[ ] */
    	  frm_index = Lin_lGetFrmIdx(u8FrameId);
    	#endif /* LIN_V_2_1 */  
      
      /* Return the count value */
      if( (uint8)LIN_SYS_NUM_FRMS != frm_index)
      {	       	
        ret_Val = Lin_FrameIDCnt[frm_index]; 
      }
      
      return(ret_Val);  
    }    
  #endif /* V2.1 */
#endif /* _LIN_FRAME_CNT */

/******************************************************************************
** Syntax           : Lin_lChkDiagResp                                       **
**                                                                           **
** Service ID       : none / NA                                              **
**                                                                           **
** Sync/Async       : Synchronous                                            **
**                                                                           **
** Reentrancy       : re-reentrant                                           **
**                                                                           **
** Parameters(in)   : Frame ID                                               **
**                                                                           **
** Parameters (out) : none                                                   **
**                                                                           **
** Return value     : NA                                                     **
**                                                                           **
** Description      : Validates if Diags response should be discarded        ** 
**                                                                           **
******************************************************************************/   
#ifdef _IFC_SLAVE
  #ifdef LIN_V_2_1       
    #if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))    
      void Lin_lChkDiagResp(void)
      {
        /* Check if previous ID is 0x3C and current is also 0x3C
           then discard any pending response.
        */      
        if((LIN_DGNSTC_REQ_FRM_NUM == Lin_LastFrmId) && 
        	 (LIN_DGNSTC_REQ_FRM_NUM == (Lin_FrmId & LIN_GET_FRAME_ID)))
        {
          /* If any message is pending to be transmitted, discard that */      
          if(LIN_TP_TX_PNDG == Lin_TpSendMsgPndg)
          {
            Lin_TpSendMsgPndg = LIN_TP_NO_TX_MSG;	
            Lin_TpTxSts       = (uint8)LD_FAILED;
          }        
          #if (_TP_BUFF_MGMT  == 0U)
            else 
            {
              if (Lin_DiagTxFifoLvl > 0U)
              {
                Lin_DiagTxFifoLvl--;
                
                Lin_DiagTxFifoRdIdx++;
                if ( Lin_DiagTxFifoRdIdx >= (uint8)_DGNSTC_TBUFF_SZ )
                {
                  Lin_DiagTxFifoRdIdx = (uint8)0;
                }        	
              }/* if (Lin_DiagTxFifoLvl > 0U) */
            }
          #endif /* #if  (_TP_BUFF_MGMT  == 0U) */  		
        }  	
        Lin_LastFrmId  = (uint8)(Lin_FrmId & LIN_GET_FRAME_ID); 
      }/* Lin_lChkDiagResp */  
    #endif /* _DGNSTC_FRM_SPRT */  
  #endif /* LIN_V_2_1 */   
#endif /* #ifdef _IFC_SLAVE */ 
/*lint +e539 */      /* positivie indentation */
/*lint +e525 */      /* negative indentation */

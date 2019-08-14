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
**  FILENAME  : Lin_Diag.c                                                   **
**                                                                           **
**  VERSION   : 1.7.0                                                        **
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
**  DESCRIPTION  : This file contains functionality of Lin HW independent    **
**  diagnostc layer.                                                         **
******************************************************************************/
/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
** --------------------------------------------------------------------------**
** PM         Puneetha Mukherjee                                             *
**                                                                           **
******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
 * V1.7.0: 2011.09.03, PM  : UTP ID AI00059568 fixed.
 * V1.6.0: 2011.12.01, PM  : UTP ID AI00058380 is fixed. 
 * V1.5.0: 2011.11.01, PM  : UTP ID AI00058130 and AI00058345 and 
                             AI00058346 is fixed. 
 * V1.4.0: 2010.12.03, PM  : Removed Master Code. UTP AI00057123. 
 * V1.3.0: 2010.09.08, PM  : UTP AI00056225 fixed. 
 * V1.2.0: 2010.08.12, PM  : UTP AI00056181 (Assign Frame ID Range) fixed.
 * V1.1.0: 2010.07.23, PM  : UTP AI00055629 fixed.
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
#include "LIN_IIL.H"
#include "LIN_Diag.h"
/* lint +elib(537) */
/*lint +esym(961,19.7) */
/*lint +esym(961, 19.13)*/ 
/******************************************************************************
**               Private Macro Definitions                                   **
******************************************************************************/

/******************************************************************************   
**                      Private Type Definitions                             **   
******************************************************************************/   
                                                                                  
/******************************************************************************   
**                      Private Function Declarations                        **   
******************************************************************************/   
static void lUpdate_DiagTxPtr( void );
static void lUpdate_DiagTxFifo( uint8 NAD, uint8 PCI, uint8 SID, uint8 supplier_id1,
                         uint8 supplier_id2, uint8 function_id1,
                         uint8 function_id2, uint8 new_NAD );

/******************************************************************************
**                      Global Constant Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Global Variable Definitions                          **
******************************************************************************/
#if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED))

  /*---------------------------------------------------------------------------
  * Variable Name   : Lin_InitNAD                                             *
  * Type            : unsigned char                                           *
  * Description     : This variable contains Initial NAD information          *           
  ---------------------------------------------------------------------------*/
  uint8        Lin_InitNAD;  

  /*---------------------------------------------------------------------------
  * Variable Name   : Lin_NAD                                                 *
  * Type            : unsigned char                                           *
  * Description     : This variable contains current interface NAD            *
  *                   information.                                            *           
  ---------------------------------------------------------------------------*/
  uint8        Lin_NAD;
  /*---------------------------------------------------------------------------
  * Variable Name   : Lin_OldNAD                                              *
  * Type            : unsigned char                                           *
  * Description     : This variable temporarily holds interface NAD when      * 
  *                   assign NAD command is received.                         *
  *                   information.                                            *           
  ---------------------------------------------------------------------------*/
  uint8        Lin_OldNAD;
  
  /*---------------------------------------------------------------------------
  * Variable Name   : Lin_TempNAD                                             *
  * Type            : unsigned char                                           *
  * Description     : This variable temporarily holds NAD received.           * 
  ---------------------------------------------------------------------------*/
  uint8        Lin_TempNAD;
  
  #if  (_TP_BUFF_MGMT  == 0U)
    #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF)
      /*-----------------------------------------------------------------------
      * Variable Name    : Lin_DiagTxFifo                                     *
      * Type             : unsigned char                                      *
      * Description      : The diagnostics transmit buffer.                   *
      *                    It is used as a circular FIFO.                     *
      -----------------------------------------------------------------------*/    
      uint8 Lin_DiagTxFifo[_DGNSTC_TBUFF_SZ][LIN_DIAG_FRM_LEN];
      
      /*-----------------------------------------------------------------------
      * Variable Name    : Lin_DiagTxFifoRdIdx                                *
      * Type             : unsigned char                                      *
      * Description      : This variable points to the current "read" index   * 
      *                    for The diagnostics transmit buffer.               *
      -----------------------------------------------------------------------*/
      uint8 Lin_DiagTxFifoRdIdx;  
      
      /*-----------------------------------------------------------------------
      * Variable Name    : Lin_DiagTxFifoWrIdx                                *
      * Type             : unsigned char                                      *
      * Description      : This variable points to the current "write" index  * 
      *                    for The diagnostics transmit buffer.               *
      -----------------------------------------------------------------------*/
      uint8  Lin_DiagTxFifoWrIdx;
    
      /*-----------------------------------------------------------------------
      * Variable Name    : Lin_DiagTxFifoLvl                                  *
      * Type             : unsigned char                                      *
      * Description      : This variable contains the number of diagnostic    * 
      *                    frames in the diagnostics  transmit buffer         *
      -----------------------------------------------------------------------*/
      uint8 Lin_DiagTxFifoLvl;
    #endif /* #if _DGNSTC_TBUFF_SZ > 0 */
    
    #if (_DGNSTC_RBUFF_SZ > LIN_DIAG_RFIFO_NOT_DEF)
      /*-----------------------------------------------------------------------
      * Variable Name    : Lin_DiagRxFifo                                     *                                    
      * Type             : unsigned char                                      *
      * Description      : Stores the data received as diagnostic frames.     *
      *                     Used as circular queue.                           *
      -----------------------------------------------------------------------*/
      uint8 Lin_DiagRxFifo[_DGNSTC_RBUFF_SZ][LIN_DIAG_FRM_LEN];
    
      /*-----------------------------------------------------------------------
      * Variable Name    : Lin_DiagRxFifoRdIdx                                *
      * Type             : unsigned char                                      *
      * Description      : Read index pointer to the diagnostics receive buff *
      -----------------------------------------------------------------------*/
      uint8 Lin_DiagRxFifoRdIdx;
    
      /*-----------------------------------------------------------------------
      * Variable Name   : Lin_DiagTxFifoWrIdx                                 *
      * Type            : unsigned char                                       *
      * Description     : Write index pointer to the diagnostics receive buff *
      -----------------------------------------------------------------------*/
      uint8 Lin_DiagRxFifoWrIdx;
    
      /*-----------------------------------------------------------------------
      * Variable Name   : Lin_DiagRxFifoLvl                                   *
      * Type            : unsigned char                                       *
      * Description     : This variable contains the number of diagnostic     *
      *                    frames received.                                   *
      -----------------------------------------------------------------------*/
      volatile uint8 Lin_DiagRxFifoLvl;
    #endif /*(_DGNSTC_RBUFF_SZ > LIN_DIAG_RFIFO_NOT_DEF)*/
  #endif /* _TP_BUFF_MGMT */
  

  /*---------------------------------------------------------------------------
  * Variable Name : Lin_DiagFifoSts                                           *
  * Type          : unsigned char                                             *
  * Description   : This variable contains status of RX and TX diagnostic     *
  *                  queue i.e. transmission/transfer errors.                 *
  ----------------------------------------------------------------------------*/
  LIN_DIAG_FIFO_STAT Lin_DiagFifoSts;

  #ifdef LIN_V_2_1
    /* Transport layer Variables */
    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpRxFirstFrm                                         *
    *Type          : unsigned char                                            *
    *Description   : This variable indicates First Frame in a TP message.     *
    -------------------------------------------------------------------------*/
    uint8    Lin_TpRxFirstFrm;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpTxFirstFrm                                         *
    *Type          : unsigned char                                            *
    *Description   : This variable indicates First Frame in a TP message.     *
    -------------------------------------------------------------------------*/
    uint8    Lin_TpTxFirstFrm;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpTxSts                                              *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the status of TP transmit.            *
    -------------------------------------------------------------------------*/
    uint8    Lin_TpTxSts;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpRxSts                                              *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the status of TP receive.             *
    -------------------------------------------------------------------------*/
    uint8    Lin_TpRxSts;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpRxMsgPndg                                          *
    *Type          : unsigned char                                            *
    *Description   : The variable indicates TP ld_receive_message is waiting. *
    -------------------------------------------------------------------------*/
    uint8    Lin_TpRxMsgPndg;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpSendMsgPndg                                        *
    *Type          : unsigned char                                            *
    *Description   : The variable indicates TP message is available for       *
                     transmit.                                                *
    -------------------------------------------------------------------------*/
    uint8    Lin_TpSendMsgPndg;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpNoBytesTobeRxed                                    *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the length to be read as part of TP   *
                     receive message.                                         *
    --------------------------------------------------------------------------*/
    uint16   Lin_TpNoBytesTobeRxed;
    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpRxLenPtr                                           *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the address of length variable,       *
                     received in ld_receive_message API.                      *
    -------------------------------------------------------------------------*/
    uint16     *Lin_TpRxLenPtr;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpTxLenPtr                                           *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the address of length variable,       *
                     received in ld_send_message API.                         *
    -------------------------------------------------------------------------*/
    #if  (_TP_BUFF_MGMT  == 1U)	
      uint16      Lin_TpTxLenPtr;    
    #else
      uint16     *Lin_TpTxLenPtr;
    #endif

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpRxDataPtr                                          *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the address where TP message to be    *
                     copied
    -------------------------------------------------------------------------*/
    uint8   *Lin_TpRxDataPtr;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpTxDataPtr                                          *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the address where TP message from     *
                     where data will be transmitted.                          *
    -------------------------------------------------------------------------*/
    uint8   *Lin_TpTxDataPtr;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpBytesRxed                                          *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the actual length read as part        *
                     of TP message.                                           *
    -------------------------------------------------------------------------*/
    uint16   Lin_TpBytesRxed  ;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpBytesTxed                                          *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the actual length read as part        *
                     of TP message.                                           *
    -------------------------------------------------------------------------*/
    uint16   Lin_TpBytesTxed;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpRxFrmSerialNo                                      *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the Serial Number of ongoing TP       *
                     transfer .
    -------------------------------------------------------------------------*/
    uint8    Lin_TpRxFrmSerialNo;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpTxFrmSerialNo                                      *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the Serial Number of ongoing TP       *
                      transfer                                                *
    -------------------------------------------------------------------------*/
    uint8    Lin_TpTxFrmSerialNo;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpRxTimeOutCntr                                      *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the current time out value for TP     *
                      receive.                                                *
    --------------------------------------------------------------------------*/
    uint16   Lin_TpRxTimeOutCntr;

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpTxTimeOutCntr                                      *
    *Type          : unsigned char                                            *
    *Description   : The variable holds the current time out value for TP     *
                      transmit                                                *
    -------------------------------------------------------------------------*/
    uint16   Lin_TpTxTimeOutCntr;
    /* ************** End of TP Layer Variables ******************  */

    /*-------------------------------------------------------------------------
    *Variable Name : Lin_FuncReq                                              *
    *Type          : unsigned char                                            *
    *Description   : The variable holds if a functional request is arrived    *
                      in between transmissions.                               *
    -------------------------------------------------------------------------*/    
    uint8    Lin_FuncReq ; 
    
    /*-------------------------------------------------------------------------
    *Variable Name : Lin_TpRxFrm                                              *
    *Type          : unsigned char                                            *
    *Description   : The variable holds if frame to be read or not.           *
    -------------------------------------------------------------------------*/    
    /* UTP AI00059568 fixed */
    uint8    Lin_TpRxFrm;
    
    #if  (_TP_BUFF_MGMT  == 1U)
      uint8   Lin_TpRxBuff[_TP_BUFF_SIZE] ;
      uint8   Lin_TpTxBuff[_TP_BUFF_SIZE] ;
      uint8   Lin_TpRxWrIndex ;
      uint8   Lin_TpTxRdIndex ;
    #endif
  #endif /* #ifdef LIN_V_2_1 */
  
  #ifdef LIN_V_2_0  
      #if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) )
        #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)
          uint16 Lin_EventCache[LIN_SYS_CFG_NUM_OF_EVNT_FRMS] ;
        #endif 
      #endif
  #endif       
#endif   /*Diagnostic support */

/*-----------------------------------------------------------------------------
*Variable Name : g_rid_params                                                 *
*Type          : unsigned int                                                 *
*Description   : Holds the response for ID = 0                                *
-----------------------------------------------------------------------------*/
#ifdef _IFC_SLAVE
  #if ((_FEATURES == LIN_ALL_FEATURES_SUPPORTED)  || (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED))
    /*lint -e{572} */
    /*lint -esym(960,12.7) */    
    uint8 g_rid_params [6] =
    {
    LIN_DIAG_READ_BY_ID_RSID,
    (uint8)(_SUPPLIER_ID),
    (uint8)(_SUPPLIER_ID >> 8U),
    (uint8)(_FUNCTION_ID),
    (uint8)(_FUNCTION_ID >> 8U),
    (uint8)(_VARIANT_ID)    	
    };
    /*lint +esym(960,12.7) */
  #endif
#endif

#if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED)
  extern uint8 Lin_Status_FrmID;
  extern uint8 Lin_Status_FrmID_Index;
#endif   /* _IFC_RESP_ERR_FRM_NUM ... */

/******************************************************************************
**                      Private  Constant Definitions                        **
******************************************************************************/

/******************************************************************************
**                     Private  Variable Definitions                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
#ifdef _IFC_SLAVE
  #if ((_FEATURES == LIN_ALL_FEATURES_SUPPORTED)  || \
      (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED)  || \
      (_DGNSTC_ASGN_FRM_SPRT == 1U))
    uint8 Lin_lHandleNodeConfig(uint8 *u8Data );
    uint8 Lin_lAssignID(uint8 drvd_id0 , uint8 *u8Data); 
  #endif   
#endif /* */

/* Last value assigned to variable 'iii' not used */
/*lint -e438 */ 
/*lint -e550 */
/*lint -e539 */      /* positivie indentation */
/*lint -e525 */      /* negative indentation */

/******************************************************************************
**                      Global Function Definitions                          **
******************************************************************************/
#if((_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED)) 
  #if  (_TP_BUFF_MGMT  == 0U)
  /****************************************************************************
  ** Syntax           : ld_put_raw                                           **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : handle No , buffer where to copy data                **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : The call queues the transmission of 8 bytes of data  **
  **                  : in one frame. The data area will be copied in the    **
  **                  : call the pointer will not be memorized.              **
  **                                                                         **
  ****************************************************************************/
  void ld_put_raw( l_ifc_handle iii, const uint8 * const data1 )
  {
    #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF)
      uint8        nloop;

      /* Copy data from application buffer to LLD diagnostic TX buffer */
      for ( nloop = 0U; nloop < (uint8)LIN_DIAG_FRM_LEN; nloop++ )
      {
        Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][nloop] = data1[nloop];
      }

      /* Update diagnostic frame TX buffer pointers */
      lUpdate_DiagTxPtr( );
    #endif /* _DGNSTC_TBUFF_SZ > .... */
    iii = data1[0];
  }
  /****************************************************************************
  ** Syntax           : ld_get_raw                                           **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : handle No , buffer where to copy data                **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : The call copies the oldest received diagnostic frame **
  **                  : data to the memory specified by data. If the receive **
  **                  : queue is empty no data will be copied.               **
  **                                                                         **
  ****************************************************************************/
  void ld_get_raw( l_ifc_handle iii, uint8 * const data1 )
  {
    #if (_DGNSTC_RBUFF_SZ > LIN_DIAG_RFIFO_NOT_DEF)
      uint8        nloop;

      /* check if data available */
      if ( Lin_DiagRxFifoLvl > (uint8) LIN_DIAG_RFIFO_EMPTY )
      {
      	/*copy data from LLD diagnostic RX buffer to application buffer */
        for ( nloop = 0U; nloop < (uint8)LIN_DIAG_FRM_LEN; nloop++ )
        {
          data1[nloop] = Lin_DiagRxFifo[Lin_DiagRxFifoRdIdx][nloop];
        }/* end of for */

        /* Adjust diagnostic RX buffer pointers */
        Lin_DiagRxFifoLvl--;
        Lin_DiagRxFifoRdIdx++;
        if ( Lin_DiagRxFifoRdIdx >= (uint8)_DGNSTC_RBUFF_SZ )
        {
          Lin_DiagRxFifoRdIdx = (uint8)0;
        }
      }/* end of if */
    #endif
    iii = (l_ifc_handle)data1[0];
  }

  /****************************************************************************
  ** Syntax           : ld_raw_tx_status                                     **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : handle No                                            **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : The call returns the status of the raw frame         **
  **                  : transmission function .                              **
  **                  : - LD_QUEUE_EMPTY                                     **
  **                  : - LD_QUEUE_AVAILABLE                                 **
  **                  : - LD_QUEUE_FULL                                      **
  **                  : - LD_TRANSMIT_ERROR                                  **
  **                                                                         **
  ****************************************************************************/
  uint8 ld_raw_tx_status( l_ifc_handle iii )
  {
    uint8        ret_val = 0U;
    #ifdef LIN_V_2_1  
      uint16 temp_val; 
    #endif /* #ifdef LIN_V_2_1 */  
    
    iii                 = (l_ifc_handle)0;

    #ifdef LIN_V_2_1
      /* Check if the status */
      if ( (uint8)LIN_DIAG_TFIFO_EMPTY == Lin_DiagTxFifoLvl )
      {
        ret_val = (uint8)LD_QUEUE_EMPTY;
      }
      else if ( (uint8)_DGNSTC_TBUFF_SZ == Lin_DiagTxFifoLvl )
      {
        ret_val = (uint8)LD_QUEUE_FULL;
      }
      else
      {
        ret_val = (uint8)LD_QUEUE_AVAILABLE;
      }
      ret_val  |= (uint8)((uint8) Lin_DiagFifoSts & (uint8) LD_TRANSMIT_ERROR );

      /* Clear the status, so that for a new frame fresh status can be captured. */
      temp_val         = (uint16) ((~((uint16)LD_TRANSMIT_ERROR)) & (uint16)(Lin_DiagFifoSts));
      Lin_DiagFifoSts  = (LIN_DIAG_FIFO_STAT)temp_val;
      return (ret_val);

    #else    /* LIN_V_2_1 */
      #if (_DGNSTC_TBUFF_SZ > LIN_DIAG_TFIFO_NOT_DEF)
        if ( Lin_DiagTxFifoLvl >= (uint8)_DGNSTC_TBUFF_SZ )
        {
          ret_val = (uint8)LD_QUEUE_FULL;
        }
        else 
        {
          if ( (uint8)LIN_DIAG_TFIFO_EMPTY == Lin_DiagTxFifoLvl )
          {
            ret_val = (uint8)LD_QUEUE_EMPTY;
          }
        }
        /* Clear the status, so that for a new frame status can be captured. */
        /*lint -e63 */
        ret_val         |= (uint8)Lin_DiagFifoSts;
        Lin_DiagFifoSts = ( LIN_DIAG_FIFO_STAT ) LIN_DIAG_FIFO_STS_RESET;
        return (ret_val);
      #endif /* _DGNSTC_TBUFF_SZ > */
    #endif   /* LIN_V_2_1 */
  }

  /****************************************************************************
  ** Syntax           : ld_raw_rx_status                                     **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous?                                         **
  **                                                                         **
  ** Reentrancy       : non-reentrant?                                       **
  **                                                                         **
  ** Parameters(in)   : handle No                                            **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : The call returns the status of the raw frame receive **
  **                  : function .                                           **
  **                  : -LD_NO_DATA                                          **
  **                  : -LD_DATA_AVAILABLE                                   **
  **                  : -LD_RECEIVE_ERROR                                    **
  **                                                                         **
  ****************************************************************************/
  uint8 ld_raw_rx_status( l_ifc_handle iii )
  {
    uint8        ret_val = 0U;
    
    #ifdef LIN_V_2_1  
      uint16 temp_val; 
    #endif /* #ifdef LIN_V_2_1 */    
    
    iii = (l_ifc_handle)0;

    #ifdef LIN_V_2_1
      if ( (uint8)LIN_DIAG_RFIFO_EMPTY == Lin_DiagRxFifoLvl )
      {
        ret_val = (uint8)LD_NO_DATA;
      }
      else
      {
        ret_val = (uint8)LD_DATA_AVAILABLE;
      }
      ret_val  |= (uint8)( (uint8)Lin_DiagFifoSts & (uint8)LD_RECEIVE_ERROR );

      /* Clear the status, so that for a new frame fresh status
          can be captured.
      */
      temp_val        = (uint16)((~((uint16)LD_RECEIVE_ERROR))& (uint16)(Lin_DiagFifoSts));
      Lin_DiagFifoSts = (LIN_DIAG_FIFO_STAT )temp_val;
      return (ret_val);

    #else    /* LIN_V_2_1 */
      #if (_DGNSTC_RBUFF_SZ > LIN_DIAG_RFIFO_NOT_DEF)
        if ( Lin_DiagRxFifoLvl > (uint8) LIN_DIAG_RFIFO_EMPTY )
        {
          ret_val = (uint8)LD_DATA_AVAILABLE;
        }

        /* Clear the status, so that for a new frame status can be captured. */
        ret_val         |= (uint8)Lin_DiagFifoSts;
        Lin_DiagFifoSts = ( LIN_DIAG_FIFO_STAT ) ( 0 );
        return ret_val;
      #endif
    #endif   /* LIN_V_2_1 */
  }
  #endif /* #if  (_TP_BUFF_MGMT  == 1) */

  #ifdef LIN_V_2_1
  /****************************************************************************
  ** Syntax           : ld_init                                              **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : handle No                                            **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : initializes the Diagnostics related variable.         **
  **                  : All transport layer buffers will be initialized.     **
  **                                                                         **
  ****************************************************************************/
  void ld_init( l_ifc_handle iii )
  {
    iii = (l_ifc_handle)0;

    /*Initialize NAD */
    Lin_InitNAD      = (uint8)_IFC_NAD;
    Lin_NAD          = (uint8)_IFC_NAD;
    Lin_OldNAD       = (uint8)_IFC_NAD;  
    
    Lin_FuncReq      = 0U;
  
    /*Initialize diagnostic FIFO status */
    Lin_DiagFifoSts  = ( LIN_DIAG_FIFO_STAT ) LD_QUEUE_EMPTY;

    /*Program TX and RX diagnostic buffer variables */
    #if (_TP_BUFF_MGMT == 0U)
      #if _DGNSTC_TBUFF_SZ > 0U
        Lin_DiagTxFifoRdIdx   = 0U;
        Lin_DiagTxFifoWrIdx   = 0U;
        Lin_DiagTxFifoLvl     = 0U;
      #endif /* #if _DGNSTC_TBUFF_SZ > 0 */
      
      #if _DGNSTC_RBUFF_SZ > 0U
        Lin_DiagTxFifoRdIdx   = 0U;
        Lin_DiagTxFifoWrIdx   = 0U;
        Lin_DiagRxFifoLvl     = 0U;
      #endif /* #if _DGNSTC_RBUFF_SZ > 0 */
    #endif /* #if (_TP_BUFF_MGMT == 1) */

    /* TP related variable initializations */
    /* Tx and Rx status are in default LD_COMPLETED state */
    Lin_TpTxSts         = (uint8)LD_COMPLETED;
    Lin_TpRxSts         = (uint8)LD_COMPLETED;
    Lin_TpTxFirstFrm    = 0U;    
    #if (_TP_BUFF_MGMT == 1U)
      Lin_TpRxWrIndex     = 0U;
      Lin_TpTxRdIndex     = 0U;
    #endif /* */  
    /* TP related variable initializations */ 
  }
  #endif   /* LIN_V_2_1 */

#if  (_TP_BUFF_MGMT  == 0U)
  /****************************************************************************
  ** Syntax           : lUpdate_DiagTxFifo                                   **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : 8 bytes to update the transfer diag buffer           **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : updates the diag tx buffer (internal API)            **
  **                                                                         **
  ****************************************************************************/
  static void lUpdate_DiagTxFifo( uint8 NAD, uint8 PCI, uint8 SID,
                                  uint8 supplier_id1,
                                  uint8 supplier_id2, uint8 function_id1,
                                  uint8 function_id2,uint8 new_NAD )
  {
    Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][0] = NAD;
    Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][1] = PCI;
    Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][2] = SID;
    Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][3] = ( uint8 ) supplier_id1;
    Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][4] = ( uint8 ) supplier_id2;
    Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][5] = ( uint8 ) function_id1;
    Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][6] = ( uint8 ) function_id2;
    Lin_DiagTxFifo[Lin_DiagTxFifoWrIdx][7] = new_NAD;

    /*Update diagnostic TX buffer pointers */
    lUpdate_DiagTxPtr();
  }
  /****************************************************************************
  ** Syntax           : lUpdate_DiagTxPtr                                    **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : None                                                 **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : updates the diag tx buffer ptr(internal API)         **
  **                                                                         **
  ****************************************************************************/
  static void lUpdate_DiagTxPtr( void )
  {
    Lin_DiagTxFifoLvl++;
    if ( Lin_DiagTxFifoLvl >= ( uint8 ) _DGNSTC_TBUFF_SZ )
    {
      Lin_DiagTxFifoLvl = ( uint8 ) _DGNSTC_TBUFF_SZ;
    }

    Lin_DiagTxFifoWrIdx++;
    if ( Lin_DiagTxFifoWrIdx >= ( uint8 ) _DGNSTC_TBUFF_SZ )
    {
      Lin_DiagTxFifoWrIdx = 0U;
    }
  }
#endif /* #if  (_TP_BUFF_MGMT  == 0) */ 
  
  #if  (_TP_BUFF_MGMT  == 0U)
  #ifdef LIN_V_2_1
  /****************************************************************************
  ** Syntax           : uint8 ld_tx_status ( l_ifc_handle iii )              **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Asynchronous                                         **
  **                                                                         **
  ** Reentrancy       : reentrant                                            **
  **                                                                         **
  ** Parameters(in)   : l_ifc_handle iii                                     **
  **                                                                         **
  ** Parameters (out) : status of last called ld_send_message                **
  **                                                                         **
  ** Return value     : NULL                                                 **
  **                                                                         **
  ** Description      : This API returns the status of last made call to     **
  **                    ld_send_message.                                     **
  **                                                                         **
  ****************************************************************************/
  uint8 ld_tx_status( l_ifc_handle iii )
  {
    iii = (l_ifc_handle) 0;
    return(Lin_TpTxSts);
  }/* End of ld_tx_status */

  /****************************************************************************
  ** Syntax           : uint8 ld_rx_status ( l_ifc_handle iii )              **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Asynchronous                                         **
  **                                                                         **
  ** Reentrancy       : reentrant                                            **
  **                                                                         **
  ** Parameters(in)   : l_ifc_handle iii                                     **
  **                                                                         **
  ** Parameters (out) : status of last called ld_receive_message             **
  **                                                                         **
  ** Return value     : NULL                                                 **
  **                                                                         **
  ** Description      : This API returns the status of last made call to     **
  **                    ld_receive_message.                                  **
  **                                                                         **
  ****************************************************************************/
  uint8 ld_rx_status( l_ifc_handle iii )
  {
    iii = (l_ifc_handle) 0;
    return(Lin_TpRxSts);
  }/* End of ld_rx_status */

  /****************************************************************************
  ** Syntax           : void ld_receive_message ( l_ifc_handle iii.... )     **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Asynchronous                                         **
  **                                                                         **
  ** Reentrancy       : reentrant                                            **
  **                                                                         **
  ** Parameters(in)   : l_ifc_handle iii                                     **
  **                  : length--> At the call, length is set to maximum, when**
  **                    reception is completed, changed to the actual length **
  **                  : NAD-->NAD of the slave device. This is not used in   **
  **                  : slave nodes.                                         **
  **                                                                         **
  ** Parameters (out) : None                                                 **
  **                                                                         **
  ** Return value     : NULL                                                 **
  **                                                                         **
  ** Description      : This API prepares the LIN diagnostics module to      **
  **                    receive one message and store it in the buffer       **
  **                    pointed by data.                                     **
  **                                                                         **
  ****************************************************************************/
    /* Pointer to'u8Data' could be declared as pointing to const */
    /*lint -e818 */
  void ld_receive_message (
                        l_ifc_handle iii ,
                        uint16* const length,
                        uint8* const NAD,
                        uint8* const data_buff
                        )
  {
    iii = (l_ifc_handle) 0;
    /* Pointer is null */
    if(LIN_NULL_DATA != data_buff)
    {
      /* If already a previous rx_msg is under process return */
      if((uint8)LD_IN_PROGRESS != Lin_TpRxSts)
      {
        /* Cache the Pointers. */
        Lin_TpRxLenPtr       = length;    
        Lin_TpRxDataPtr      = data_buff;  
        Lin_TpRxFrmSerialNo  = 0U;
        Lin_TpBytesRxed      = 0U;  
        /* Indicate ld_receive_message is requested. */
        Lin_TpRxMsgPndg      = (uint8)LIN_TP_RX_PNDG;
      }/* End of if(LD_IN_PROGRESS != Lin_TpTxSts)*/
    }/* */
  }/* End of ld_receive_message */
  /****************************************************************************
  ** Syntax           : void ld_send_message ( l_ifc_handle iii.... )        **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Asynchronous                                         **
  **                                                                         **
  ** Reentrancy       : reentrant                                            **
  **                                                                         **
  ** Parameters(in)   : l_ifc_handle iii                                     **
  **                  : length--> At the call, length is set to maximum, when**
  **                    reception is completed, changed to the actual length **
  **                  : NAD-->NAD of the slave device. This is not used in   **
  **                  : slave nodes.                                         **
  **                                                                         **
  ** Parameters (out) : None                                                 **
  **                                                                         **
  ** Return value     : NULL                                                 **
  **                                                                         **
  ** Description      : This API packs the information specified by data and **
  **                    length into one or multiple diag frames.             **
  **                                                                         **
  ****************************************************************************/
  void ld_send_message (  l_ifc_handle iii ,
                        uint16* const length,
                        uint8* const NAD,
                        uint8* const data_buff
                        )
  {
    iii = (l_ifc_handle) 0;

    /* validate the length */
    if ( (*length < (uint16)LIN_TP_MSG_MAX_LEN ) )
    {
      /* If already a previous tx_msg is under process return */
      if((uint8)LD_IN_PROGRESS != Lin_TpTxSts)
      {
      	Lin_TpBytesTxed  = 0U;
        /* Check if it needs to be a SF or FF /CF */
        if( *length <= (uint8)LIN_TP_SF_LEN )
        {
          Lin_TpTxFirstFrm = (uint8)LIN_TP_SF;
        }
        else
        {
          Lin_TpTxFirstFrm = (uint8)LIN_TP_FF;
        }
        /* Cache the pointers */
        Lin_TpTxLenPtr  = length;
        Lin_TpTxDataPtr = data_buff;
        Lin_TpTxFrmSerialNo  = 1U;

        /* Set flag to indicate to indicate the buffer available */
        Lin_TpSendMsgPndg = (uint8) LIN_TP_TX_PNDG;
      }/* End of  if(LD_IN_PROGRESS != Lin_TpTxSts */
    }
  }/* End of ld_send_message */
  
  /*lint +e818 */
  /* Transport layer Functions */
  #endif /* #ifdef LIN_V_2_1 */
  #endif /* #if  (_TP_BUFF_MGMT  == 0) */
#endif /* Diagnostics */


#ifdef _IFC_SLAVE
  #if ((_FEATURES == LIN_ALL_FEATURES_SUPPORTED)  || \
      (_DGNSTC_FRM_SPRT == LIN_DIAG_SUPPORTED)  || \
      (_DGNSTC_ASGN_FRM_SPRT == 1U))
  /****************************************************************************
  ** Syntax           : Lin_lHandleNodeConfig                                **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : Data pointer                                         **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : Call back for the commands, Assing NAD, Assign Frame **
  **                     ID Range , Read by ID 0 and Conditional change NA   **
  **                                                                         **
  ****************************************************************************/
    /* Pointer to'u8Data' could be declared as pointing to const */
    /*lint -e818 */
    uint8 Lin_lHandleNodeConfig(uint8 *u8Data)
    {
      uint8   retVal   = 0U;
      uint8   old_id   = 0U;
      #ifdef LIN_V_2_1
        uint8   u8Result = 0U;
      #endif /* #ifdef LIN_V_2_1 */  
      #if ((_DGNSTC_ASGN_FRM_SPRT == 1U) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED )) 
        #ifndef LIN_V_2_1
          uint16  Frm_Info = 0U; 
        #endif/* #ifndef LIN_V_2_1 */
      #endif /* _DGNSTC_ASGN_FRM_SPRT... */  
      uint16  drvd_id0, drvd_id1;
    
      #if(_DGNSTC_ASGN_FRM_SPRT == 1U)
        #ifndef LIN_V_2_1
          uint8       new_id, nloop /*, nloop1*/;
          l_bool      flag1;
        #endif /* LIN_V_2_1 */
      #endif/* _DGNSTC_ASGN_FRM_SPRT */

      switch ( u8Data[0] )
      {
        /* Assign NAD */
        case LIN_DIAG_ASSIGN_NAD_SID:
        {
        	/* Extract the Supplier ID / Function ID and validate */ 
          drvd_id0  = u8Data[1];
          drvd_id0  |= (uint16)( (uint16)u8Data[2] << LIN_DIAG_EXTRACT_BYTE );
          drvd_id1  = u8Data[3];
          drvd_id1  |= (uint16)( (uint16)u8Data[4] << LIN_DIAG_EXTRACT_BYTE );
    
          /* Is supplier iD and function IDs are matching. */
          if ( ( ( (uint16)LIN_ANY_SUPPLIER   == drvd_id0 ) ||
                 ( (uint16)_SUPPLIER_ID      == drvd_id0 ) ) &&
                 ( ( (uint16)LIN_ANY_FUNCTION == drvd_id1 )||
                 ( (uint16)_FUNCTION_ID      == drvd_id1 ) )
             )
          {
          	#if  (_TP_BUFF_MGMT  == 1U) 
              Lin_TpTxBuff[0] = LIN_DIAG_ASSIGN_NAD_RSID;
              Lin_TpTxBuff[1] = LIN_DIAG_UNUSED_BYTE;
              Lin_TpTxBuff[2] = LIN_DIAG_UNUSED_BYTE;
              Lin_TpTxBuff[3] = LIN_DIAG_UNUSED_BYTE;
              Lin_TpTxBuff[4] = LIN_DIAG_UNUSED_BYTE;
              Lin_TpTxBuff[5] = LIN_DIAG_UNUSED_BYTE;

              /* update the byte indicating data length */
              Lin_TpTxLenPtr  = LIN_DIAG_PCI_1_BYTE;    
              retVal          = 1U;                   
            #else          
              lUpdate_DiagTxFifo( Lin_InitNAD, 
                                  LIN_DIAG_PCI_1_BYTE, 
                                  LIN_DIAG_ASSIGN_NAD_RSID,
                                  LIN_DIAG_UNUSED_BYTE, 
                                  LIN_DIAG_UNUSED_BYTE,
                                  LIN_DIAG_UNUSED_BYTE,
                                  LIN_DIAG_UNUSED_BYTE, 
                                  LIN_DIAG_UNUSED_BYTE );
              retVal          = 0U;                        
            #endif /* #if  (_TP_BUFF_MGMT  == 1)  */
            /* update old NAD with new NAD */
            Lin_NAD    = u8Data[5];
            Lin_OldNAD = u8Data[5];
          }
        }
        break;  /*0xb0 */
        
        #if ((_DGNSTC_ASGN_FRM_SPRT == 1U) || \
             (_FEATURES == LIN_ALL_FEATURES_SUPPORTED )) 
          #ifndef LIN_V_2_1
            /* Assign frame ID */
            case LIN_DIAG_ASSIGN_FRM_ID_SID:
            {	
              /* extract Supplier ID */
              drvd_id0 = u8Data[1];
              drvd_id0 |= (uint16)((uint16) u8Data[2] << LIN_DIAG_EXTRACT_BYTE);
              
              /* get Message ID */
              drvd_id1 = u8Data[3];
              drvd_id1 |= ( (uint16) u8Data[4] << LIN_DIAG_EXTRACT_BYTE );
              
              /* Is supplier ID matching */
              if ( ( ( (uint16)LIN_ANY_SUPPLIER == drvd_id0 )||
                     ( (uint16)_SUPPLIER_ID    == drvd_id0 ) 
                   )
                 )
              {                 
	              /* Get New ID */ 
	      			  if( 0x40U == u8Data[5])
	      			  {
	      			     new_id = u8Data[5];
	      			  }
	      			  else
	      			  {
	                new_id = ( u8Data[5] & LIN_GET_FRAME_ID );
	              }
	              /* check if Message ID is for a event triggered ID */
	              /* UTP AI00058380 */
					      #if ((_EVNT_SPRDC_FRM_SPRT == LIN_EVNT_SPRDC_FRM_SUPPORTED) || (_FEATURES == LIN_ALL_FEATURES_SUPPORTED) )
					        #if (LIN_SYS_CFG_NUM_OF_EVNT_FRMS > LIN_NO_EVNT_FRM_DEFINED)   	              
			              nloop = 0U;
			              flag1 = (l_bool)0;
			              do
			              {
			                if ( Lin_EventCache[nloop] == drvd_id1 )
			                {
			                  Lin_EvntSchTbl[nloop].frm_id = new_id; 
			                  Lin_FrmInfo[new_id] = 0x00U;
			                  flag1 = (l_bool)1;
			                  
					               /* Send positive response */
					               #if (_DGNSTC_TBUFF_SZ > 0U)	
					                 lUpdate_DiagTxFifo(
					                                    Lin_NAD, 
					                                    LIN_DIAG_PCI_1_BYTE, 
					                                    LIN_DIAG_ASSIGN_FRM_ID_RSID,
					                                    LIN_DIAG_UNUSED_BYTE, 
					                                    LIN_DIAG_UNUSED_BYTE, 
					                                    LIN_DIAG_UNUSED_BYTE,
					                                    LIN_DIAG_UNUSED_BYTE, 
					                                    LIN_DIAG_UNUSED_BYTE 
					                                    );
					               #endif /* */                
					               retVal            = 0U;     	                  
			                  break;
			                }
			                nloop++;
			              } while ( ( nloop < (uint8)LIN_SYS_CFG_NUM_OF_EVNT_FRMS ) );
		            
		                if ( ( flag1 == (l_bool)0 ) )
		             #endif /* */
		            #endif /* */    	
                {
                 nloop = 0U;
                 flag1 = (l_bool)0;
                 
  
                 /* Parse through message ID to locate the frame ID */
                 do
                 {
                   if ( Lin_SignalMsgId[nloop] == drvd_id1 )
                   {
                     old_id = nloop;
                     flag1  = (l_bool)1;
                   }
                   nloop++;
                 } while ( ( nloop <= (uint8)LIN_MAX_FRM_ID_UNCD ) && \
                           ( flag1 == (l_bool)0 ) );
                 
                 if ( ( flag1 == (l_bool)1 ) )
                 {
                   {
   				         /* change properties of a frame */                  
                     /* Lin_FrmInfo[new_id]   = Lin_FrmInfo[old_id]; */
           				  /* If it is un assign */        				  
           				  if( 0x40U == u8Data[5])
           				  {
                       Lin_FrmInfo[old_id]   &= (0x7FU);
           				  }
           				  else
           				  {
                       if(Lin_Status_FrmID == old_id)
             				  {
             				    Lin_Status_FrmID        = new_id;
             					  Lin_Status_FrmID_Index  =  new_id; 
             				  }
             				  	Frm_Info = Lin_FrmInfo[old_id] ;        				  	
             				    Lin_FrmInfo[old_id] = Lin_FrmInfo[new_id];
             				    
             				    Lin_FrmInfo[new_id] = (uint8)((uint16)( Frm_Info | 0x80U));
             				    
             				    Frm_Info = Lin_FrmOffset[old_id] ;        				  	
             				    Lin_FrmOffset[old_id] = Lin_FrmOffset[new_id];
             				    Lin_FrmOffset[new_id] = (uint8)Frm_Info;
             				    
             				    Frm_Info = Lin_SignalMsgId[old_id] ;        				  	
             				    Lin_SignalMsgId[old_id] = Lin_SignalMsgId[new_id];
             				    Lin_SignalMsgId[new_id] = Frm_Info;        				                				  
           				  }
                   }/* if ( ( flag1 == 1 ) && ( old_id != new_id ) ) */                  
                   
		               /* Send positive response */
		               #if (_DGNSTC_TBUFF_SZ > 0U)	
		                 lUpdate_DiagTxFifo(
		                                    Lin_NAD, 
		                                    LIN_DIAG_PCI_1_BYTE, 
		                                    LIN_DIAG_ASSIGN_FRM_ID_RSID,
		                                    LIN_DIAG_UNUSED_BYTE, 
		                                    LIN_DIAG_UNUSED_BYTE, 
		                                    LIN_DIAG_UNUSED_BYTE,
		                                    LIN_DIAG_UNUSED_BYTE, 
		                                    LIN_DIAG_UNUSED_BYTE 
		                                    );
		               #endif /* */                
		               retVal            = 0U;                         
                 }
                }                
              }/* Supplier ID is matching */            
						}	
          break;  /*0xb1 */
        #endif    /* #ifndef LIN_V_2_1 */
      #endif      /*assign frame ID support */

        /* read by ID */
        case LIN_DIAG_READ_BY_ID_SID:
        {
          /* ID */
          old_id = u8Data[1];

          /* Supplier ID */
          drvd_id0 = u8Data[2];
          drvd_id0 |= (uint16)( (uint16)u8Data[3] << (uint16)8 );

          /* Function ID */
          drvd_id1 = u8Data[4];
          drvd_id1 |= (uint16)( (uint16)u8Data[5] << (uint16)8 );

          /* Is ID, supplier iD and function IDs are matching */
          if ( ( ( (uint16)LIN_ANY_SUPPLIER == drvd_id0  ) ||
                 ( (uint16)_SUPPLIER_ID    == drvd_id0  ) 
                )&& 
               ( ( (uint16)LIN_ANY_FUNCTION == drvd_id1  )||
                 ( (uint16)_FUNCTION_ID    == drvd_id1  ) 
               ) 
             )
          {
        	#if  (_TP_BUFF_MGMT  == 1U) 
            Lin_TpTxBuff[0] = LIN_DIAG_READ_BY_ID_RSID;
            Lin_TpTxBuff[1] = (uint8)_SUPPLIER_ID;            
            /* supprss Lint warning */ 
            /*lint -e{572} */
            Lin_TpTxBuff[2] = (uint8)((uint16)(_SUPPLIER_ID) >> LIN_DIAG_EXTRACT_BYTE );
            Lin_TpTxBuff[3] = (uint8) ( _FUNCTION_ID );
            /* supprss Lint warning */
            /*lint -e{572} */                       
            Lin_TpTxBuff[4] = (uint8)((uint16)(_FUNCTION_ID) >> LIN_DIAG_EXTRACT_BYTE );
            Lin_TpTxBuff[5] = (uint8)( _VARIANT_ID );     
            
            /* update the byte indicating data length */
            Lin_TpTxLenPtr  = LIN_TP_SF_LEN; 
            retVal          = 1U;    
          #else
            #if _DGNSTC_TBUFF_SZ > 0U	
              lUpdate_DiagTxFifo( 
                                 Lin_NAD, 
                                 LIN_DIAG_PCI_6_BYTE,/*LIN_DIAG_PCI_1_BYTE,*/ 
                                 LIN_DIAG_READ_BY_ID_RSID,
                                 ( uint8 ) _SUPPLIER_ID, 
                                 /*lint -e{572} */
                                 /*lint -esym(960,12.7) */                                     
                                 ( uint8 ) ( (uint16)(_SUPPLIER_ID) >> LIN_DIAG_EXTRACT_BYTE ), 
                                 ( uint8 ) _FUNCTION_ID,
                                 ( uint8 ) ((uint16)(_FUNCTION_ID) >> LIN_DIAG_EXTRACT_BYTE),
                                 /*lint +esym(960,12.7) */
                                 ( uint8 ) _VARIANT_ID
                                 );
            #endif /* */                
            retVal            = 0U;          
          #endif /* */                   
          }   /*if(supplier_id === & function_id ==  ) */
        }
        break;  /*0xb2 */

        #ifdef LIN_V_2_1
          /* Assign Frame ID range */
          case LIN_DIAG_ASSIGN_FRM_ID_RANGE_SID:
          {
            /* Read the start index */
            drvd_id0 = u8Data[1];

            /* Start index should be within the range */
            if(drvd_id0 < LIN_SYS_NUM_FRMS)
            {
              /* Check if frames with IDs 60 - 63 are not changed */
              u8Result = 0U; 
              /*suppress lint MISRa rule 14.6, the break is added for robust code */
              /*lint -esym(960,14.6) */               
              for ( drvd_id1 = 2U; drvd_id1 <= 5U; drvd_id1++ )
              { 
				         if(drvd_id0 >= LIN_SYS_NUM_FRMS)
                 {
                 	 break;
                 }

                old_id = Lin_FrmTbl[drvd_id0];
                
                if ( ( old_id >= LIN_DGNSTC_REQ_FRM_NUM ) &&
                	   ( LIN_INVALID_FRM_ID > old_id  ) &&
                	  (u8Data[drvd_id1] != LIN_FRM_ID_DONT_CARE )
                	 ) 
                {	
                  u8Result = 1U;  	            	
                  break;
                }/* */              
              
                drvd_id0++;  
              }
              /*lint +esym(960,14.6) */
              /* 60 - 63 is not being changed */
              if( 0U == u8Result)
              {
                /* Read the start index */
                drvd_id0 = u8Data[1];

                if ( ( drvd_id0 + 3U ) < LIN_SYS_NUM_FRMS )
                {	
                  retVal = Lin_lAssignID((uint8)drvd_id0 , u8Data);
                }/*  if ( ( drvd_id0 + 3 ) < LIN_SYS_NUM_FRMS ) */  
                else
                {
                  /* Check how many are don't cares */
                  /* old_id = (uint8)(LIN_SYS_NUM_FRMS - 	drvd_id0); */
                  drvd_id1 = (LIN_SYS_NUM_FRMS - 	drvd_id0); 
                  /* No response to be sent if command cannot be executed */
                  retVal = 0U;
                  for ( drvd_id1 = (2U + /*old_id*/drvd_id1); drvd_id1 <= 5U; drvd_id1++ )
                  {                	
                  	if(u8Data[drvd_id1] != (uint8)LIN_FRM_ID_DONT_CARE)
                  	{
                  		u8Result = 1U;
                  		break;                		
                  	}	
                  }
                  if(0U == u8Result)
                  {
                    retVal = Lin_lAssignID((uint8)drvd_id0 , u8Data);                          	
                  }			
                }		    
              } /* if( 0U == retVal) */
            }/* if(drvd_id0 < LIN_SYS_NUM_FRMS) */
          }
          break;  /*0xb7 */
        #endif /* */

        /* Conditional change NAD */
        case LIN_DIAG_CONDITIONAL_NAD:
        {
          /* Get the ID and extract the byte information */
          if((u8Data[2]) <= 5U)
		      {
			      drvd_id0 = g_rid_params[(u8Data[2])];

    			  /* Do bitwise XOR with "invert" */
    			  drvd_id0 ^= u8Data[4];
    
    			  /* Do bit wise AND with "mask" */
    			  drvd_id0 &= u8Data[3];
    			  /* Check result is 0 , then only change the NAD */
    			  if((uint8)0 == drvd_id0)
    			  {
      				Lin_NAD    = u8Data[5];
      				/* Lin_OldNAD = u8Data[5]; */
      	            
      				/* send the response as condition has passed */              
      				#if  (_TP_BUFF_MGMT  == 1U) 
      				  Lin_TpTxBuff[0] = LIN_DIAG_CONDITIONAL_NAD_RSID;
      				  Lin_TpTxBuff[1] = LIN_DIAG_UNUSED_BYTE;
      				  Lin_TpTxBuff[2] = LIN_DIAG_UNUSED_BYTE;
      				  Lin_TpTxBuff[3] = LIN_DIAG_UNUSED_BYTE;
      				  Lin_TpTxBuff[4] = LIN_DIAG_UNUSED_BYTE;
      				  Lin_TpTxBuff[5] = LIN_DIAG_UNUSED_BYTE;         
      				  /* update the byte indicating data length */
      				  Lin_TpTxLenPtr  = LIN_DIAG_PCI_1_BYTE; 
      				  retVal          = 1U;                   
      				#else
                  		#if (_DGNSTC_TBUFF_SZ > 0U)              
      					 lUpdate_DiagTxFifo( 
      									   Lin_OldNAD, 
      									   LIN_DIAG_PCI_1_BYTE, 
      									   LIN_DIAG_CONDITIONAL_NAD_RSID,
      									   LIN_DIAG_UNUSED_BYTE,
      									   LIN_DIAG_UNUSED_BYTE,
      									   LIN_DIAG_UNUSED_BYTE,
      									   LIN_DIAG_UNUSED_BYTE,
      									   LIN_DIAG_UNUSED_BYTE
      									   );
      						  Lin_OldNAD     = Lin_NAD;
      				  #endif /* */                
      				  retVal            = (uint8)0;                
      				#endif /* #if  (_TP_BUFF_MGMT  == 1)  */                    
			      }  
		      }
        }	  
        break;  
    
        default:
        break ;
      }  
      return(retVal); 
    }/* Lin_lHandleNodeConfig */  
    
   #ifdef LIN_V_2_1 
  /****************************************************************************
  ** Syntax           : Lin_lAssignID                                        **
  **                                                                         **
  ** Service ID       : none / NA                                            **
  **                                                                         **
  ** Sync/Async       : Synchronous                                          **
  **                                                                         **
  ** Reentrancy       : non-reentrant                                        **
  **                                                                         **
  ** Parameters(in)   : Data pointer and start index                         **
  **                                                                         **
  ** Parameters (out) : none                                                 **
  **                                                                         **
  ** Return value     : NA                                                   **
  **                                                                         **
  ** Description      : The API populates the response for command Assign    **
  **                    Frame ID Range                                       ** 
  **                                                                         **
  ****************************************************************************/       
    uint8 Lin_lAssignID(uint8 drvd_id0 , uint8 *u8Data)
    {
      uint8 retVal = 0U;
      uint8 drvd_id1; 
    
      for ( drvd_id1 = 2U; drvd_id1 <= 5U; drvd_id1++ )
      {
      	/* Make sure IDs are valid , not unassign or don't care */
        if ( ( u8Data[drvd_id1] != (uint8)LIN_FRM_ID_UASSIGN ) &&
             ( u8Data[drvd_id1] != (uint8)LIN_FRM_ID_DONT_CARE ) )
        {
        	/* If Status Frame ID is changing, change the status 
        	   Frame Number before the ID is changed in the Frame 
        	   Table. 
        	*/                    		
        	#if (_IFC_RESP_ERR_FRM_NUM != LIN_RESP_ERR_SUPPORTED)
        	  if(Lin_Status_FrmID_Index == drvd_id0)
        	  {
        	    if(Lin_Status_FrmID != ((u8Data[drvd_id1] ) & LIN_GET_FRAME_ID))
        	    {
        	      Lin_Status_FrmID = ((u8Data[drvd_id1] ) & LIN_GET_FRAME_ID);	
        	    }	
        	  }		                      	
        	#endif /* _IFC_RESP_ERR_FRM_NUM */
        	                   
        	/* Update the information in Lin_FrmTbl */
          Lin_FrmTbl[drvd_id0] =
              ( ( u8Data[drvd_id1] ) & LIN_GET_FRAME_ID );
          /* The previous frame data as well invalid */
          Lin_FrmDataUpdtFlag[( drvd_id0 >> 3U )] &=
           (uint8)(~((uint8)(1U << (uint8)((uint8)drvd_id0 & 0x7U ))));                       
        }
        else 
        {
          if ( LIN_FRM_ID_UASSIGN == u8Data[drvd_id1] )/*(uint8)0x00 )*/
          {
            /* Frame number is not valid as per LIN specification */
            Lin_FrmTbl[drvd_id0] = LIN_INVALID_FRM_ID;/*(uint8)64 ;*/
          }
        }
        drvd_id0++;
      }   /*end of for loop */                  
        
      /* Send the response */
      #if  (_TP_BUFF_MGMT  == 1U) 
        Lin_TpTxBuff[0] = LIN_DIAG_ASSIGN_FRM_ID_RANGE_RSID;
        Lin_TpTxBuff[1] = LIN_DIAG_UNUSED_BYTE;
        Lin_TpTxBuff[2] = LIN_DIAG_UNUSED_BYTE;
        Lin_TpTxBuff[3] = LIN_DIAG_UNUSED_BYTE;
        Lin_TpTxBuff[4] = LIN_DIAG_UNUSED_BYTE;
        Lin_TpTxBuff[5] = LIN_DIAG_UNUSED_BYTE;   
        
        /* update the byte indicating data length */
        Lin_TpTxLenPtr  = 1U; 
        retVal          = 1U; 
      #else
        	#if (_DGNSTC_TBUFF_SZ > 0U)	
            lUpdate_DiagTxFifo( 
                               Lin_NAD, 
                               LIN_DIAG_PCI_1_BYTE, 
                               LIN_DIAG_ASSIGN_FRM_ID_RANGE_RSID,
                               LIN_DIAG_UNUSED_BYTE, 
                               LIN_DIAG_UNUSED_BYTE,
                               LIN_DIAG_UNUSED_BYTE,
                               LIN_DIAG_UNUSED_BYTE,
                               LIN_DIAG_UNUSED_BYTE
                               );
          #endif /* _DGNSTC_TBUFF_SZ */                
          retVal            = 0U;        
      #endif /* #if  (_TP_BUFF_MGMT  == 1)  */          
      return(retVal);                  
    }    
  #endif /* #ifdef LIN_V_2_1 */                        
  /*lint +e818 */
  #endif /* Diags Support */
#endif/* #ifdef _IFC_SLAVE */
/*lint +e438 */ 
/*lint +e550 */

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
**  FILENAME  : Lin_Idl.h                                                    **
**                                                                           **
**  VERSION   : 1.5.0                                                        **
**                                                                           **
**  DATE      : 2011.09.03                                                   **
**                                                                           **
**  PLATFORM  : Infineon XC2000                                              **
**                                                                           **
**  COMPILER  : Tasking - Viper v2.4 r2                                      **
**                                                                           **
**  PROJECT   : XC2000 LIN                                                   **
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
** AKA         Anoop Aggarwal                                                **
** PM          Puneetha Mukherjee                                            **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*
 * V1.5.0: 2011.09.03, PM   : UTP ID AI00059574  fixed.
 * V1.4.1: 2011.11.01, PM   : UTP ID AI00058130 is fixed.
 * V1.4.0: 2010.12.03, PM   : Updated for UTP ID AI00056260. 
 * V1.3.0: 2010.09.08, PM   : Updated for UTP ID AI00056265.
 * V1.2.0: 2010.07.23, PM   : Synchronization issue fixed.
 * V1.1.0: 2010.07.23, PM   : Updated for UTP ID: AI00055270 
 * V1.0.0: 2010.05.19, PM   : Added FIFO support  
 * V0.1.0: 2010.01.18, AKA  : Fixed timer issues and MISRA checking. . 
 * V0.0.1: 2010.18.01, AKA  : Added configurability for USIC and Ports, fixed
 *                            other issues during testing.
 * V0.0.2: 2009.18.12, AKA  : Initial version of IDL for LIN
 */

#ifndef _LIN_IDL_H_
#define _LIN_IDL_H_

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
/* UTP AI00059574 is fixed */
#include "LIN_LDF.h"
#include "Lin_SFR16.h"
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
#ifndef TRUE                                             /* conditional check*/
 #define TRUE      ((boolean) 1)
#endif

#ifndef FALSE                                            /* conditional check*/
 #define FALSE     ((boolean) 0)
#endif

/* System Frequency (Mention in MHz range) */
#define SYSTEM_FREQUENCY_IN_MHZ  (PRPL_FREQ/1000000U)

 /* avoid clash with existing definitions */
#ifndef ON            
   #define ON       (1)
#endif

/* avoid clash with existing definitions */
#ifndef OFF            
   #define OFF      (0)
#endif

#define USIC_IC_type __IC_type

/* break byte */
#define LIN_BREAK_BYTE               (0x00U)
/* sync byte */
#define LIN_SYNC_BYTE                (0x55U)
/* wakeup byte */
#define LIN_WAKEUP_BYTE              (0xE0U)/*(0xF0U)*/

#define ASC_PROTOCOL_SELECT          (2U)
#define USIC_PROCESS_FALLING_EDGES   (2U)


/* USIC_CHANNEL_OFFSET: Calculates user configured LIN channel offset address*/
#define USIC_CHANNEL_OFFSET(ch)      ((((ch) >> 1U) * 0x800U) + \
                                     (((ch) & 0x1U) * 0x200U))

/* USIC_CHANNEL_PTR: Points to the address space for the user configured USIC
   channel */
#define USIC_CHANNEL_PTR         ((USIC_RegMapType FAR *)(USIC_BASE_ADDRESS + \
                                  USIC_CHANNEL_OFFSET(LIN_CFG_CHANNEL_ID)) )

/* USIC_IC_PTR: Retrieves address for USIC Interrupt control registers based
   on the configured channel and service request */
#if LIN_CFG_CHANNEL_ID == USIC_U2C1_CHANNEL
  #define USIC_IC_PTR(ch,sr)       ((USIC_IC_type*)(((sr) == 0U) ? 0xF13EU : \
                                    (0xF180U + ((sr) * 2U))))
#else /* USIC 0/1 ; USIC 2 channel 0 configured */
  #define USIC_IC_PTR(ch,sr)       ((USIC_IC_type*) (0xF120U + ((ch) * 6U) + \
                                    ((sr) * 2U)))
#endif/* LIN_CFG_CHANNEL_ID */

/*
 Number of clock ticks required to program the timer to overflow
 to the configured value
 */ 
/*#define LIN_CFG_TMR_TICKS        ((uint16)(0xFFFF - \
                                 ((uint16)(( _TMR_BASE * \
                                 (PRPL_FREQ / 1000U) ) / 2048U))) + 1U)*/
                                 
                                 
/*#define LIN_TIMER_PERIOD              ((_TMR_BASE * (PRPL_FREQ / 1000U)))U  
#define LIN_TIMER_PER_RESOLUTION      ((LIN_TIMER_PERIOD / 2048U))U
#define LIN_CFG_TMR_TICKS             (65535U - LIN_TIMER_PER_RESOLUTION + 1U)U */

#define LIN_CFG_TMR_TICKS        ((65535U -  ((( _TMR_BASE * (PRPL_FREQ / 1000U)) / 2048U))) + 1U)
                               
/* Dummy function for XC22xx functionality */
#define idl_config_channel()

/* Enable UART */
#define IDL_EN_CHANNEL()        (USIC_CHANNEL_PTR->CCR.B.MODE = \
                                            (uint16)ASC_PROTOCOL_SELECT)

/* Enable UART */
#define IDL_EN_CHANNEL_INT()    (USIC_IC_PTR(LIN_CFG_CHANNEL_ID,1U)->B.IE = 1U)

/* Disable UART(channel) interrupt */
#define IDL_DIS_CHANNEL()

/* Disable UART(channel) interrupt */
#define IDL_DIS_CHANNEL_INT()   (USIC_IC_PTR(LIN_CFG_CHANNEL_ID,1U)->B.IE = 0U)


/* Configure the user baud rate and send sync byte(0x55) */
#define idl_send_sync_byte()      idl_channel_send(0x55U)

/* Set user baud rate and send the wakeup byte(0xFO) */
#define idl_send_wake_cmd()       idl_channel_send(0xE0U) /*(0xF0U)*/

/* Set the baud rate for 'break' singal and send break byte(00) */
#define idl_send_break_byte()     idl_channel_send(0x0U)

/* Slave sends the wakeup byte(0xF0) at already running baud rate */
#define IDL_SEND_WAKE_BYTE()      idl_channel_send(0xE0U) /*(0xF0U)*/

/* Read data byte from receive buffer */
#define IDL_READ_CHANNEL_BUFF()   (USIC_CHANNEL_PTR->RBUF.U)

/* *********** Interrupt functionality *******************/

/* Checks if the receive frame finished interrupt has occured */
#define IDL_CHANNEL_RX_INT()     /*lint -save -e506 */ (USIC_CHANNEL_PTR->PSR.B1.ST7 != 0U)/*lint -restore */

/* Clears receive frame finished interrupt status flag */
#define IDL_CLR_CHANNEL_RX_INT()  (USIC_CHANNEL_PTR->PSCR.B.CST7 = 1U)

/* Checks if the byte transmission completed interrupt has occured */
#define IDL_CHANNEL_TX_INT()      /*lint -save -e506 */(USIC_CHANNEL_PTR->PSR.B1.TBIF != 0U)/*lint -restore */

/* Clears transmit byte finished interrupt status flag */
#define IDL_CLR_CHANNEL_TX_INT()  (USIC_CHANNEL_PTR->PSCR.B.CTBIF = 1U)

/* Enable timer interrupt for sleep/wakeup */
#define IDL_EN_TIMEOUT_INT()      (USIC_CHANNEL_PTR->CCR.B.TSIEN = 1U)

#define IDL_CLR_SYNC_ERR_INT()    (USIC_CHANNEL_PTR->PSCR.B.CST5 = 1U)
#define IDL_CHK_FORMAT_ERROR_0()  (USIC_CHANNEL_PTR->PSR.B2.FER0 != 0U)
/* -------------------------------------------------------*/


/* ****** Flag checks, set and clear functionality ********/

/* Checks if break is received i.e. PSR.SBD = 1 */
#define IDL_CHK_BRK_RECEPTION()   /*lint -save -e506 */(USIC_CHANNEL_PTR->PSR.B2.SBD != 0U)/*lint -restore */

/* Clears the break received flag PSR.SBD */
#define IDL_CLR_BRK_RECEPTION()   (USIC_CHANNEL_PTR->PSCR.B.CST2 = 1U)

/* Checks if sync is received i.e. Receive frame finished flag is set = 1 */
#define IDL_CHK_SYNC_RECEPTION()  IDL_CHANNEL_RX_INT()

/* Clears the break received flag PSR.TSIF */
#define IDL_CLR_SYNC_RECEPTION()  (USIC_CHANNEL_PTR->PSCR.B.CTSIF = 1U)

/* Checks if format error in stop bit 0 occured */
/* Note: Sync error detection not available in XC2000 family */
#define IDL_CHK_SYNC_ERR()        (USIC_CHANNEL_PTR->PSR.B1.ST5 != 0U)

/* Following #define "IDL_CLR_SYNC_ERR" will be empty */
/* Note: Sync error detection not available in XC2000 family */
#define IDL_CLR_SYNC_ERR()

/* Following #define will be empty */
#define IDL_CNF_SYNC_DTCT()

/* Checks if break sync detection occured or autobaud detection (falling edge)
   interrupt occured */
#define IDL_CHK_ATBD_INT()        /*lint -save -e506 */(USIC_CHANNEL_PTR->PSR.B1.TSIF != 0U)/*lint -restore */

/* Clears autobaud detection (falling edge) interrupt */
#define IDL_CLR_ATBD_INT()        (USIC_CHANNEL_PTR->PSCR.B.CTSIF = 1U)

/* Disables autobaud detection mechanism */
#define IDL_STOP_ATBD_DTCT()      USIC_CHANNEL_PTR->CCR.B.TSIEN = 0U; \
                                  USIC_CHANNEL_PTR->BRGL.B.TMEN = 0U


/* Enables autobaud detection mechanism */
/* Note: Break detection is enabled earlier itself. This functionality is 
        implemented to take care of common source code concept. Here the f(PPP) 
        is set at 100k baud and falling edge interrupt trigger is enabled
 */
#define IDL_100K_AUTOBAUD_STEP     (1024U - (PRPL_FREQ / 100000U))

#define IDL_CNF_BRK_DTCT()                                              \
                USIC_CHANNEL_PTR->FDRL.B.STEP /= 32U; \
                USIC_CHANNEL_PTR->FDRL.B.DM = 2U;                     \
                USIC_CHANNEL_PTR->BRGL.B.TMEN = 1U;                     \
                USIC_CHANNEL_PTR->DX0CR.B.CM = USIC_PROCESS_FALLING_EDGES; \
                USIC_CHANNEL_PTR->DX1CR.B.CM = 0U; \
                USIC_CHANNEL_PTR->CCR.B.TSIEN = 1U
                
/* This API reinitializes the break detection */
#define IDL_REINIT_ATBD_DTCT()    idl_init_atbd_dtct()

/*  IDL_EN_ATBD_INT: This #define shall remain empty as the functionality is 
    integrated with IDL_CNF_BRK_DTCT() */
#define IDL_EN_ATBD_INT()

/* Disables the autobaud detection(Falling edge) interrupt */
#define IDL_DIS_ATBD_INT()        (USIC_CHANNEL_PTR->CCR.B.TSIEN = 0U)

/* Enables the schedular interrupt */
#define IDL_EN_SCHED_INT()        (_GPT12E_IC.B.IE = 1U)

/* macro to disable and clear interrupt service request in <x>IC register */
#define Idl_DisableClearIntRequest(IC_Ptr) \
                                  (*(IC_Ptr) &= ((uint16)((uint16)~(((uint16)(3U << 6U))))) )

#if _IFC_SCND_TMR_NUM == GPT_T2
#define IDL_STOP_TIMEOUT_INTR()    (_GPT12E_T3CON.B.T3R = 0U); \
                                  Idl_DisableClearIntRequest(&_GPT12E_IC.U)
#else
#define IDL_STOP_TIMEOUT_INTR()    (_GPT12E_T6CON.B.T6R = 0U); \
                                  Idl_DisableClearIntRequest(&_GPT12E_IC.U)
#endif

/* IDL_ISR_PRE_HOOK: This #define shall remain empty, for reusability purpose*/
#define IDL_ISR_PRE_HOOK()
/*IDL_ISR_POST_HOOK: This #define shall remain empty, for reusability purpose*/
#define IDL_ISR_POST_HOOK()

/* Start the timer with 'dummy' value. Don't enable interrupts */
#define idl_config_sch_timer()

/* 'dummy' implementations */
#define idl_config_channel()
#define idl_config_timeout_tmr()

/* Start the timer with 'dummy' value. Don't enable interrupts */
#define idl_cnf_wkup_timer()

#define IDL_STOP_TIMEOUT_TIMER()    IDL_STOP_SCHEDULER()

#if _IFC_SCND_TMR_NUM == GPT_T2
  #define IDL_STOP_SCHEDULER()        (_GPT12E_T3CON.B.T3R = 0U)
#else
  #define IDL_STOP_SCHEDULER()        (_GPT12E_T6CON.B.T6R = 0U)
#endif

/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/


void idl_Port_Connect(void);
void idl_channel_init(void);
void idl_cfg_atbd_dtct(void);
void idl_dis_atbd_dtct(void);
void idl_LockProtecReg(void);
uint16 idl_calc_bittime(void);
void idl_init_atbd_dtct(void);
uint16 idl_dis_sys_ints(void);
uint8 idl_change_context(void);
void idl_Port_Disconnect(void);
void idl_CfgWakeupDetect(void);
void idl_UnlockProtecReg(void);
void idl_Restart_AutoBaud(void);
void idl_channel_send(uint8 Data);
void idl_program_baud(uint16 bittime);
void idl_restore_context( uint8 Page );
void idl_start_scheduler(uint16  Value);
void idl_load_new_timeout(uint16  Value);
void idl_restore_sys_ints( uint8 previous );
void idl_ReadRxFiFo( uint8 u8FrmLen , uint8 * u8Data , uint8 u8TxDir);
void idl_Setup_TxFIFO( uint8 u8FrmLen , uint8 * u8Data , uint8 u8TxDir);


/*****************************************************************************
                            @Interrupt Vectors
******************************************************************************/

#if LIN_CFG_CHANNEL_ID == USIC_U0C0_CHANNEL
  /* SR0 of U0C0 */
  #define LIN_0INT        (0x50)    
  /* SR1 of U0C0 */
  #define LIN_1INT        (0x51)    
#elif LIN_CFG_CHANNEL_ID == USIC_U0C1_CHANNEL
  /* SR0 of U0C1 */
  #define LIN_0INT        (0x53)    
  /* SR1 of U0C1 */
  #define LIN_1INT        (0x54)    
#elif LIN_CFG_CHANNEL_ID == USIC_U1C0_CHANNEL
  /* SR0 of U1C0 */  
  #define LIN_0INT        (0x56)    
  /* SR1 of U1C0 */
  #define LIN_1INT        (0x57)    
#elif LIN_CFG_CHANNEL_ID == USIC_U1C1_CHANNEL
  /* SR0 of U1C1 */
  #define LIN_0INT        (0x59)    
  /* SR1 of U1C1 */
  #define LIN_1INT        (0x5A)    
#elif LIN_CFG_CHANNEL_ID == USIC_U2C0_CHANNEL
  /* SR0 of U2C0 */
  #define LIN_0INT        (0x5C)  
   /* SR1 of U2C0 */ 
  #define LIN_1INT        (0x5D)   
#elif LIN_CFG_CHANNEL_ID == USIC_U2C1_CHANNEL
  /* SR0 of U2C1 */
  #define LIN_0INT        (0x5F)    
  /* SR1 of U2C1 */
  #define LIN_1INT        (0x60)    
#endif /* LIN_CFG_CHANNEL_ID */

#if _IFC_SCND_TMR_NUM == GPT_T2
  /* GPT T2 Interrupt node */
  #define TIM_INT      (0x21)         
#else
  /* GPT T6 Interrupt node */
  #define TIM_INT      (0x24)         
#endif /* _IFC_SCND_TMR_NUM */
#endif /* _LIN_IDL_H_ */

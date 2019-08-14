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
**  FILENAME  : Lin_Idl.c                                                    **
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
 * V1.6.0: 2011.09.03, PM  : UTP ID AI00059574  fixed.
 * V1.5.0: 2011.11.01, PM  : UTP ID AI00058130 and AI00058345 and 
                             AI00058346 is fixed. 
 * V1.4.0: 2010.12.03, PM   : UTP AI00057719 fixed 
 * V1.3.0: 2010.09.08, PM   : UTP AI00056224 is fixed.
 * V1.2.0: 2010.08.12, PM   : UTP AI00056180 (Synchronization issue) is fixed.
 * V1.1.0: 2010.07.23, PM   : UTP AI00055270 fixed.
 * V0.1.1: 2010.05.19, PM   : Added FIFO support  
 * V0.1.0: 2010.01.18, AKA  : Fixed timer issues and MISRA checking. . 
 * V0.0.1: 2010.01.18, AKA  : Added configurability for USIC and Ports, fixed
 *                            other issues during testing.
 * V0.0.0: 2009.18.12, AKA  : Initial version of IDL for LIN
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
#include "Lin_idl.h"
#include "defines.h"
/*lint -e10 */
/*lint -e19 */
/*lint -e49 */
/*lint -e66 */
/*lint -e553 */
/*lint -e132 */
/*lint -esym(950,*) */
/*lint -esym(957,*) */
/*lint -esym(960,*) */
/*lint -esym(970,*) */
#include <stdlib.h> 
/*lint +e10 */
/*lint +e19 */
/*lint +e49 */
/*lint +e66 */
/*lint +e553 */
/*lint +e132 */
/*lint +esym(950,*) */
/*lint +esym(957,*) */
/*lint +esym(960,*) */
/*lint +esym(970,*) */
/* lint +elib(537) */
/*lint +esym(961,19.7) */
/*lint +esym(961, 19.13)*/ 

/*lint -e10 */
/*lint -e69 */
/*lint -e48 */
/*lint -e63 */
/*lint -e923 */

/* macros will be placed near the start of a file, before the first function 
  definition, but since stdlib.h is added 
*/  
/*lint -esym(960,19.5) */
/******************************************************************************
**                      Private Macro Definitions                            **
******************************************************************************/
#define LIN_FRM_TX       (1)

#define MODEN_WITH_BITPROT       ((uint16)(0x3))
#define USIC_INPUT_HIGH          (1U)
#define USIC_ASSERT_VALUE        (1U)
#define USIC_WORD_LENGTH         (7U)
#define USIC_FRAME_LENGTH        (7U)

#define USIC_PCTQ_VAL            (0U) 
#define USIC_PDIV_VAL            (50U)
#define USIC_DCTQ_VAL            (15U)
/* UTP AI00059574 is fixed */
#define USIC_BAUD_20             (LIN_SYS_CFG_BAUD / 1000U)  
#define USIC_BAUD_20K            (LIN_SYS_CFG_BAUD)
#define USIC_MAX_PDIV            (1023U)
  
#define USIC_SAMPLE_POINT_VAL    (1U | (uint16)( (uint16)(USIC_DCTQ_VAL >> 1)\
                                        << 8 ))


#if (_IFC_SCND_TMR_NUM == GPT_T2)
  /* GPT12E reload mode for timer T2 */
  #define GPT_GPT12E_T2_RELOAD_MODE    (0x0027U)
  #define GPT_PRESCALE_VAL             (0x1807U)
#else /* T6 timer is used */
  #define GPT_GPT12E_T6_RELOAD_MODE    (0x9007U)
#endif

/* Value:  number of ticks after which the timer shall
   over flow in the following macro. Currently the timer is configured at
   78.12 Khz. It can be changed using the BPS1 and T3I bitfields in T3CON
   
   
   
   
   register.
*/
#define USIC_RESET_STATUS_FLAGS      (0xFFFFU)
#define GPT_MODULE_EN_VAL            (0x0003U)

/*
  PortPin Direction
  - Output direction
  These values are written to Pn_IOCR register to set the direction of the
  port pin
*/
#define PORT_PIN_OUT                 ((uint16)((uint16)8 << 4))

/*
  Pin input characteristics
  - Pull-up characteristics is used for input pins and is written to Pn_IOCR
  register
*/
#define PORT_PIN_IN_PULL_UP          ((uint16)((uint16)2 << 4))

/*
  Port Pin Mode , i.e., Port output functions
  - ALT1
  - ALT2
  - ALT3
  These values are written to Pn_IOCR register to set the input/output function
  of the port pin
*/
#define PORT_PIN_MODE_ALT1        ((uint16)((uint16)1 << 4))
#define PORT_PIN_MODE_ALT2        ((uint16)((uint16)2 << 4))
#define PORT_PIN_MODE_ALT3        ((uint16)((uint16)3 << 4))

/* Port output alternate USIC selection */
#define PORT_2_PIN_3              (PORT_PIN_MODE_ALT1)
#define PORT_2_PIN_4              (PORT_PIN_MODE_ALT1)
#define PORT_2_PIN_9              (PORT_PIN_MODE_ALT1)
#define PORT_2_PIN_10             (PORT_PIN_MODE_ALT1)
#define PORT_2_PIN_13             (PORT_PIN_MODE_ALT1)

#define PORT_6_PIN_1              (PORT_PIN_MODE_ALT3)

#define PORT_10_PIN_0             (PORT_PIN_MODE_ALT1)
#define PORT_10_PIN_1             (PORT_PIN_MODE_ALT1)

#define PORT_10_PIN_5             (PORT_PIN_MODE_ALT3)
#if (LIN_CFG_CHANNEL_ID == USIC_U0C0_CHANNEL)
  #define PORT_10_PIN_6             (PORT_PIN_MODE_ALT1)
#else
  #define PORT_10_PIN_6             (PORT_PIN_MODE_ALT2)
#endif /* */  
#define PORT_10_PIN_7             (PORT_PIN_MODE_ALT1)

#define PORT_10_PIN_10             (PORT_PIN_MODE_ALT3)

#if (LIN_CFG_CHANNEL_ID == USIC_U1C0_CHANNEL)
  #define PORT_10_PIN_12            (PORT_PIN_MODE_ALT1)
#else
  #define PORT_10_PIN_12            (PORT_PIN_MODE_ALT2)
#endif 
  
#define PORT_10_PIN_13            (PORT_PIN_MODE_ALT1)
#define PORT_10_PIN_14            (PORT_PIN_MODE_ALT2)

#if (LIN_CFG_CHANNEL_ID == USIC_U0C1_CHANNEL)
  /* Alt value for USIC_U0C1_CHANNEL */
  #define PORT_10_PIN_15            (PORT_PIN_MODE_ALT2)
#else /* Alt value for USIC_U1C0_CHANNEL */
  #define PORT_10_PIN_15            (PORT_PIN_MODE_ALT3)
#endif

/*
  Port Input Data Line:
  These values are written to DX0CR register of USIC to select the desired
  input port pin
*/
#if (LIN_CFG_CHANNEL_ID == USIC_U0C0_CHANNEL)
  #define DATALINE_P2_3     (4U)
#else  /* U0C1 */
 #define DATALINE_P2_3      (3U)
#endif

#define DATALINE_P2_4       (5U)
#define DATALINE_P2_7       (0U)
#define DATALINE_P2_10      (4U)

#if (LIN_CFG_CHANNEL_ID == USIC_U1C1_CHANNEL)
  #define DATALINE_P2_13      (1U)
#else
  #define DATALINE_P2_13      (1U)
#endif /*  */    

#define DATALINE_P5_8       (5U)
#define DATALINE_P5_10      (5U)

#define DATALINE_P6_0       (4U)
#define DATALINE_P6_1       (0U)

#if (LIN_CFG_CHANNEL_ID == USIC_U1C1_CHANNEL)
  #define DATALINE_P10_0      (2U)
#else
  #define DATALINE_P10_0      (0U)
#endif /* */  

#define DATALINE_P10_1      (1U)

#if (LIN_CFG_CHANNEL_ID == USIC_U0C0_CHANNEL)
  #define DATALINE_P10_6      (2U)
#else  
  #define DATALINE_P10_6      (5U)
#endif   
#define DATALINE_P10_7      (1U)


#if (LIN_CFG_CHANNEL_ID == USIC_U0C0_CHANNEL)
  #define DATALINE_P10_12     (3U)
#else
  #define DATALINE_P10_12     (2U)
#endif 
  
#define DATALINE_P10_13     (3U)
#define DATALINE_P10_14     (2U)

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/

/******************************************************************************
**                      Private Macro like functions                         **
******************************************************************************/
/* Function-like macro defined in LIN_LDF.h */
/*lint -esym(961, 19.7)*/  
/* '#/##' operator used in LIN_LDF.h */
/*lint -esym(961, 19.13)*/ 

#define Get_Dataline_P2_Pin_Ref(pin)     (DATALINE_P2_ ## pin)
#define Get_Dataline_P2_Pin(pin)         (Get_Dataline_P2_Pin_Ref(pin))
#define DATALINE_P2                      (Get_Dataline_P2_Pin(LIN_PIN_IN))

#define Get_Dataline_P5_Pin_Ref(pin)     (DATALINE_P5_ ## pin)
#define Get_Dataline_P5_Pin(pin)         (Get_Dataline_P5_Pin_Ref(pin))
#define DATALINE_P5                      (Get_Dataline_P5_Pin(LIN_PIN_IN))

#define Get_Dataline_P6_Pin_Ref(pin)     (DATALINE_P6_ ## pin)
#define Get_Dataline_P6_Pin(pin)         (Get_Dataline_P6_Pin_Ref(pin))
#define DATALINE_P6                      (Get_Dataline_P6_Pin(LIN_PIN_IN))

#define Get_Dataline_P10_Pin_Ref(pin)    (DATALINE_P10_ ## pin)
#define Get_Dataline_P10_Pin(pin)        (Get_Dataline_P10_Pin_Ref(pin))
#define DATALINE_P10                     (Get_Dataline_P10_Pin(LIN_PIN_IN))

#define Get_Dataline_Ref(port)           (DATALINE_P ## port)
#define Get_Dataline(port)               Get_Dataline_Ref(port)

#define Get_P2_Pin_Alt(pin)              (PORT_2_PIN_ ## pin)
#define Get_P2_Pin(pin)                  Get_P2_Pin_Alt(pin)
#define P_2                              (Get_P2_Pin(LIN_PIN_OUT))

#define Get_P6_Pin_Alt(pin)              (PORT_6_PIN_ ## pin)
#define Get_P6_Pin(pin)                  Get_P6_Pin_Alt(pin)
#define P_6                              (Get_P6_Pin(LIN_PIN_OUT))

#define Get_P10_Pin_Alt(pin)             (PORT_10_PIN_ ## pin)
#define Get_P10_Pin(pin)                 Get_P10_Pin_Alt(pin)
#define P_10                             (Get_P10_Pin(LIN_PIN_OUT))
#define Get_Port(port)                   (P_ ## port)
/* Port_Get_IOCR_Out:
 * Calculates and retrieves the IOCR value for an output pin configured for LIN
 */
#define Port_Get_IOCR_Out(port)          ( (uint16)((uint16)PORT_PIN_OUT  |\
                                         (uint16)Get_Port(port) ) )

/* PORT_IOCR_IN:
 * IOCR register value for an input pin configured for LIN
 */
#define PORT_IOCR_IN                     ( (uint16)PORT_PIN_IN_PULL_UP )

/* Port_Set_Output_IOCR:
 * Used to set the IOCR registers for output pins configured for LIN
 */
#define Port_Set_Output_IOCR()   ((Port_IOCR_Address[LIN_PORT_OUT] + \
                                    LIN_PIN_OUT)->U =\
                                    Port_Get_IOCR_Out(LIN_PORT_OUT))

/* Port_Set_Input_IOCR:
 * Used to set the IOCR registers for input pins configured for LIN
 */
#define Port_Set_Input_IOCR()    ((Port_IOCR_Address[LIN_PORT_IN] + \
                                  LIN_PIN_IN)->U = PORT_IOCR_IN)

/*lint +esym(961,19.7) */
/*lint +esym(961, 19.13)*/ 
/*lint +esym(960,19.5) */
/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/

/******************************************************************************
**                      Private Function Declarations                        **
******************************************************************************/


/******************************************************************************
**                      Global Constant Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Global Variable Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Private Constant Definitions                         **
******************************************************************************/

/*  Port_IOCR_Address:
 *  Addresses of IOCR registers for ports required for USIC/LIN
 */
static __IOCR_type * const Port_IOCR_Address[11] =
{
   (__IOCR_type *)0xE800, /* P0_IOCRx */
   (__IOCR_type *)0xE820, /* P1_IOCRx */
   (__IOCR_type *)0xE840, /* P2_IOCRx */
   (__IOCR_type *)0,      /* Reserved */
   (__IOCR_type *)0xE880, /* P4_IOCRx */
   (__IOCR_type *)0,      /* Reserved */
   (__IOCR_type *)0xE8C0, /* P6_IOCRx */
   (__IOCR_type *)0xE8E0, /* P7_IOCRx */
   (__IOCR_type *)0,      /* Reserved */
   (__IOCR_type *)0,      /* Reserved */
   (__IOCR_type *)0xE940  /* P10_IOCRx */
};

/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/
static uint32 step ;
static uint16 pdiv ;


extern uint32 Lin_BaudRate; 

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
static void Baud_Cal(void);

/******************************************************************************
**                      Global Function Definitions                          **
******************************************************************************/
/******************************************************************************
** Syntax:          void Baud_Cal(void)                                      **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     Service for initializing the USIC channel, ports and     **
**                  timer configured by the user                             **
**                                                                           **
******************************************************************************/  
static void Baud_Cal(void)
{
  uint16 fPin ; 
  uint16 sys_clk; 
  uint16 step1,step2;
  uint16 u32Baudrate1 , u32Baudrate2 ;
  sint16 BaduRate_Tolerance1 , BaduRate_Tolerance2 ;  
    
  /* Initialize PDIV , system clock and fPin Values */  
  pdiv = (uint16)USIC_PDIV_VAL;   
  sys_clk = ((uint16)((uint32)PRPL_FREQ / 1000U));
  fPin    = (uint16)((uint16)(USIC_BAUD_20 * (USIC_PCTQ_VAL+(uint16)1) *
                     (USIC_DCTQ_VAL+(uint16)1) * (pdiv+(uint16)1)));
  
  /* Get idea PDIV value and hence step for 20K. */
  while (fPin >= sys_clk)
  {
    pdiv = pdiv / 2U; 
    fPin = (USIC_BAUD_20 * (USIC_PCTQ_VAL+1U) * (USIC_DCTQ_VAL+1U) * (pdiv+1U));  
  } 
  /* Calculate step value */
  sys_clk = sys_clk / 1000U; 
  step  = (uint32)(fPin / sys_clk);
  step  = step * 1024U; 
  step  = step /1000U; 
  
  /* step round to nearest integer */
  step1 = (uint16)(step+1U);
  step2 = (uint16)step;
  
  /* Baud rate which is closet to the actual value required */                                       
  u32Baudrate1 = (uint16)(( (PRPL_FREQ / 1024U)  * step1 ) / \
                   ((pdiv+1U) * (USIC_DCTQ_VAL+1U) * (USIC_PCTQ_VAL+1U)));  
  u32Baudrate2 = (uint16)(( (PRPL_FREQ / 1024U)  * step2 ) / \
                 ((pdiv+1U) * (USIC_DCTQ_VAL+1U) * (USIC_PCTQ_VAL+1U) ));
    
  /* Check which is nearest to the actualt baud rate required */
  BaduRate_Tolerance1 = abs(u32Baudrate1 - USIC_BAUD_20K) ; 
  BaduRate_Tolerance2 = abs(u32Baudrate2 - USIC_BAUD_20K) ;
 	
  if(BaduRate_Tolerance1 > BaduRate_Tolerance2)
  {	
  	step = step2;
  }
  else
  {	
  	step = step1;	
  } 
  
  Lin_BaudRate = USIC_BAUD_20K;   
}
/******************************************************************************
** Syntax:          void idl_channel_init(void)                              **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     Service for initializing the USIC channel, ports and     **
**                  timer configured by the user                             **
**                                                                           **
******************************************************************************/
/* Last value assigned to variable 'TempRead' not used */
/*lint -e438 */ 
void idl_channel_init(void)
{
   volatile uint16  TempRead;

   /* Select mode */
   /* Write MODEN=1 and BPMODEN=1 together for KSCFG register */
   USIC_CHANNEL_PTR->KSCFG.U = MODEN_WITH_BITPROT;

   /* To take care of pipe line effects */
   TempRead = (uint16)(USIC_CHANNEL_PTR->KSCFG.U);
   
   if((TempRead &= (uint16)0x0001) != (uint16)0x00)
   {	
     TempRead = (uint16)512;
   }  
   /* To take care of pipe line effects */
   	  
   /* Clock line Selection
     Always fractional dividers (Normal or Fractional) will be selected
     by default the value is zero, so no need load once again
     (No option to connect external clock instead of system clock)
   */
   /* CCR : First reset the Mode (If already used by another Driver ) */
   USIC_CHANNEL_PTR->CCR.B.MODE   = 0U;   
   USIC_CHANNEL_PTR->PSCR.B.CST7  = 1U;
   USIC_CHANNEL_PTR->PSCR.B.CTBIF = 1U;
   USIC_CHANNEL_PTR->PSCR.B.CST2  = 1U;
   USIC_CHANNEL_PTR->PSCR.B.CTSIF = 1U;
      
   Baud_Cal( );

   /* Initialize registers to set default baud rate to 20000 baud */
   /* Program the divider type and step value for 20000 baud */
   USIC_CHANNEL_PTR->FDRL.U   = (uint16)step;
   USIC_CHANNEL_PTR->FDRL.U   |= 0x8000U;

   /* Initialise PDIV value */
   USIC_CHANNEL_PTR->BRGH.U = pdiv;

   /* Initialise DCTQ value */
   USIC_CHANNEL_PTR->BRGL.B.DCTQ = USIC_DCTQ_VAL;

   /*
      Always 50% Sampling point has been provided
      Make Sample points (CTR[12:8]) equal to DCTQ/2 value
   */
   USIC_CHANNEL_PTR->PCRL.U = USIC_SAMPLE_POINT_VAL;

   /* Data Line Selection and initialization */
   USIC_CHANNEL_PTR->DX0CR.B.INSW = 0U;
   USIC_CHANNEL_PTR->DX0CR.B.DSEL = Get_Dataline(LIN_PORT_IN);   

   /* Clock line initialization for collision detection */
   USIC_CHANNEL_PTR->DX1CR.B.INSW = 0U;
   USIC_CHANNEL_PTR->DX1CR.B.DSEL = 0U;

   /* Control line initialization [Always High Input] */
   USIC_CHANNEL_PTR->DX2CR.B.INSW = 0U;
   USIC_CHANNEL_PTR->DX2CR.B.DSEL = USIC_INPUT_HIGH;

   /* Allot Interrupt Line 0 for Protocol and Transmit shift interrupt   */
   /* SR 1 for break / frame complete */
   USIC_CHANNEL_PTR->INPRH.B.PINP = 1U;  
   /* SR 0 for falling edge */
   USIC_CHANNEL_PTR->INPRL.B.TSINP = 0U;  

   /* Allot Interrupt Line 1 for RBUF interrupt   */
   /* SR 0 */
   USIC_CHANNEL_PTR->INPRL.B.RINP = 0U;  

   /* Choose Passive data level = 1 (PDL = 1) [Keep high out] */
   USIC_CHANNEL_PTR->SCTRL.B.PDL = USIC_ASSERT_VALUE;

   /* The shift control signal is considered active if it is at 1-level */
   USIC_CHANNEL_PTR->SCTRL.B.TRM = USIC_ASSERT_VALUE;

   /*
      Following is the default configuration :
      SCTRL.SDIR = 0 (LSB first),
      PCRL.STPB  = 0 (Number of Stop Bits)
      CCR.PM     = 0 (Parity Mode : Disabled )
   */
   /* Enable the Transmit of data in Single Shot */
   USIC_CHANNEL_PTR->TCSRL.U = 0U;
   USIC_CHANNEL_PTR->TCSRL.B.TDSSM = USIC_ASSERT_VALUE;
   USIC_CHANNEL_PTR->TCSRL.B.TDEN = USIC_ASSERT_VALUE;

   /* Initialize Word length and Frame length */
   USIC_CHANNEL_PTR->SCTRH.B.WLE = USIC_WORD_LENGTH;
   USIC_CHANNEL_PTR->SCTRH.B.FLE = USIC_FRAME_LENGTH;

   /* Enable frame finished protocol interrupt */
   USIC_CHANNEL_PTR->PCRL.B2.FFIEN  = 1U;
   
   /* Enable Format Error Interrupt */
   USIC_CHANNEL_PTR->PCRL.B2.FEIEN  = 1U; 
   /* Enable Format Error Interrupt */

   /* Enable Receiver Noise Interupt, UTP AI00057719 fixed */
   USIC_CHANNEL_PTR->PCRL.B2.RNIEN  = 1U; 
   
   /* Set interrupt priority for SR0, SR1 of USIC0 channel 0 */
   USIC_IC_PTR(LIN_CFG_CHANNEL_ID,0U)->B.ILVL = (uint8)USIC_REQ0_ILVL_PRIO;
   USIC_IC_PTR(LIN_CFG_CHANNEL_ID,1U)->B.ILVL = (uint8)USIC_REQ1_ILVL_PRIO;
   
   /* Enable Interrupt for SR0, SR1 after clearing pending interrupt */
   USIC_IC_PTR(LIN_CFG_CHANNEL_ID,0U)->B.IR = 0U;
   USIC_IC_PTR(LIN_CFG_CHANNEL_ID,1U)->B.IR = 0U;
   USIC_IC_PTR(LIN_CFG_CHANNEL_ID,0U)->B.IE = 1U;
   USIC_IC_PTR(LIN_CFG_CHANNEL_ID,1U)->B.IE = 1U;

   idl_start_scheduler(0xFFFFU);

   /* Set up CCR with following:
   * - Data Lost Interrupt - Disabled
   * - Transmit Buffer Interrupt - Disabled
   * - Receiver Start Interrupt - Disabled
   * - Transmit Shift Interrupt - Disabled (Required later for baud detection)
   * - Receive Interrupt - Disabled
   * - Alternative Receive Interrupt - Disabled
   * - Parity generation - Disabled
   * - Mode : ASC
   */
   USIC_CHANNEL_PTR->CCR.U =  0x0002U;
   
   /* Enable Data Lost Interrupt UTP AI00057719 fixed */
   USIC_CHANNEL_PTR->CCR.B.DLIEN = 1U;   
}
/*lint +e438 */ 
/******************************************************************************
** Syntax:          void idl_program_baud(uint16  bittime)                   **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  bittime - The PDIV (counter) value as measured by the    **
**                  Autobaud detection mechanism of the USIC hardware @ 20k  **
**                  baud rate.                                               **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     Service for programming the new baud rate as detected by **
**                  the Autobaud detection mechanism. Based on the baud rate **
**                  a fixed step value is taken, i.e. 1023 for > 5k baud and **
**                  1004 for <= 5k baud.The new PDIV value is then calculated**
**                  and written into the PDIV register.                      **
******************************************************************************/
void idl_program_baud(uint16  bittime)
{  
   /* make sure Bit time is within range og 1023 */
   if( (bittime < USIC_MAX_PDIV) && (bittime > 0))
   {	
     /* 
       PDIV is the bit value read, and step was lowered 
        during baud rate measurement, so re write.
     */   	
     USIC_CHANNEL_PTR->FDRL.B.STEP *= 2U * (USIC_DCTQ_VAL+1U);
     USIC_CHANNEL_PTR->BRGH.U = (bittime - 1U);
     
     /* Calculate the effective baud rate configured */                            
    Lin_BaudRate = ((PRPL_FREQ/1024) * (USIC_CHANNEL_PTR->FDRL.B.STEP))  /\
                    ((USIC_PCTQ_VAL+1U) * (USIC_DCTQ_VAL+1U) * bittime);                             
       
     /* Clear all status flags */
     USIC_CHANNEL_PTR->PSCR.U = USIC_RESET_STATUS_FLAGS;  
   } 
   else
   {
   	USIC_CHANNEL_PTR->FDRL.U   = (uint16)step;
   	USIC_CHANNEL_PTR->FDRL.U   |= 0x8000U;
    USIC_CHANNEL_PTR->BRGH.U   = pdiv;  
    /* UTP AI00057719 fixed */
    /*lint -e40 */
    Lin_BaudRate = USIC_BAUD_20K;   
   }	
}
/******************************************************************************
** Syntax:          void idl_Restart_AutoBaud(void)                          **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     The API re initializes the Auto baud feature.            **
******************************************************************************/
void idl_Restart_AutoBaud(void)
{
  USIC_CHANNEL_PTR->CCR.B.TSIEN = 0U;
  USIC_CHANNEL_PTR->FDRL.U      = (uint16)step;
  USIC_CHANNEL_PTR->FDRL.U      |= 0x8000U;
  USIC_CHANNEL_PTR->BRGH.U      = pdiv;   	
  USIC_CHANNEL_PTR->BRGL.B.TMEN = 0U;
  
  /* UTP AI00057719 fixed */
  Lin_BaudRate = USIC_BAUD_20K;   
}  
/******************************************************************************
** Syntax:          void idl_init_atbd_dtct(void)                            **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     Service for initializing the break sync detection. This  **
**                  is actually a triggering point for initializing the      **
**                  autobaud detection feature.                              **
******************************************************************************/
void idl_init_atbd_dtct(void)
{
   /* Initialize break detection */
   USIC_CHANNEL_PTR->PCRL.B1.CTR3 = 1U;
}


/******************************************************************************
** Syntax:          void idl_cfg_atbd_dtct(void)                             **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This routine is left empty as the register configuration **
**                  for autobaud detection is done during start of autobaud. **
******************************************************************************/
void idl_cfg_atbd_dtct(void)
{
   /* This can be a dummy API. All the interrupts / registers are initialized
      for USIC. For Autobaud detection, the same registers are required to be
      which can be done via API IDL_CNF_BRK_DTCT()
   */
   
   /* UTP AI00057719 fixed */
   idl_Restart_AutoBaud( );
}


/******************************************************************************
** Syntax:          void idl_calc_bittime(void)                              **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This service returns the bit time (PDIV) for the incoming**
**                  signal.                                                  **
******************************************************************************/
uint16 idl_calc_bittime(void)
{
    return (USIC_CHANNEL_PTR->BRGH.B.PDIV);
}


/******************************************************************************
** Syntax:          void idl_dis_atbd_dtct(void)                             **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This service shall disable the autobaud detect mechanism.**
******************************************************************************/
void idl_dis_atbd_dtct(void)
{
   /* TSIEN = 0 : Disable interrupt for edge during autobaud */
   USIC_CHANNEL_PTR->CCR.B.TSIEN = 0U;
   /* TMEN = 0 : Switch to normal baud generation */
   USIC_CHANNEL_PTR->BRGL.B.TMEN = 0U;
   /* Clear all status flags */
   USIC_CHANNEL_PTR->PSCR.U = USIC_RESET_STATUS_FLAGS;
   return;
}
/******************************************************************************
** Syntax:          void idl_load_new_timeout(uint16  Value)                 **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  Value - Timer ticks .                                    **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This service shall start the timer after configuring the **
**                  desired timer ticks.                                     **
******************************************************************************/
void idl_load_new_timeout(uint16  Value)
{
  /* T2 is configured */
  #if (_IFC_SCND_TMR_NUM == GPT_T2)  
    /* load timer and reload register with inverse value */
    _GPT12E_T3CON.B.T3R = 0U;
    _GPT12E_T3.U = Value;
    _GPT12E_T2.U = Value;
    _GPT12E_T3CON.B.T3R = 1U;
  
  #else /* T6 is configured */ 
    /* load timer and reload register with inverse value */
    _GPT12E_T6CON.B.T6R = 0U;
    _GPT12E_CAPREL.U = Value;
    _GPT12E_T6.U = Value;
    _GPT12E_T6CON.B.T6R = 1U;  
  #endif
}
/******************************************************************************
** Syntax:          void idl_start_scheduler(uint16  Value)                  **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  Value - Dummy value, ignored for XC2000 implementation.  **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This service shall initialize the user configured timer  **
**                  registers and the interrupts. The timer shall however run**
**                  when idl_load_new_timeout is called with the desired time**
**                  ticks as input.                                          **
******************************************************************************/
void idl_start_scheduler(uint16  Value)
{
  idl_UnlockProtecReg();

   /* Module Enable */
  _GPT12E_KSCCFG.U  = GPT_MODULE_EN_VAL;
  /*Ignoring return for nop */
  /*lint -e534 */
  NOP();
  NOP();
  /*lint +e534 */
  #if (_IFC_SCND_TMR_NUM == GPT_T2)
    /* timer T2: */
    /* Note: Timer T2 is used in conjunction with T3 to configure a reload
       timer. T3 reloads the value of T2 whenever it overflows. T3 is configured
       as an up counter. On an overflow, interrupt line of T3 is activated.
       To achieve above, T2 is configured in reload mode and T3 in timer mode.
       prescaler factor is 2048.
       This means : f(T3) = f(sys) / 2048. Please see table
       15.7 in XC2200n UM for details.
    */
    /* configure reload */
    _GPT12E_T2CON.U = GPT_GPT12E_T2_RELOAD_MODE;
 
    /* timer T3: configure timer, keep BPS bits */
    _GPT12E_T3CON.U = GPT_PRESCALE_VAL;
 
    /* start timer */
    _GPT12E_T3CON.B.T3R = 1U;
  #else /* GPT_T6 selected */  
    /* Timer T6: */
    /* Note: Timer T6 is used in timer mode. T6 reloads the value stored in
       CAPREL register whenever it overflows.
       On an overflow, interrupt line of T6 is activated.
       prescaler factor is 2048.
       This means : f(T6) = f(sys) / 2048. Please see table
       15.15 in XC2200n UM for details.
    */
    /* configure reload */
    _GPT12E_T6CON.U = GPT_GPT12E_T6_RELOAD_MODE;
 
    /* start timer */
    _GPT12E_T6CON.B.T6R = 1U;
  #endif
   /* Configure Interrupt priority level and interrupt group level(0) */
  _GPT12E_IC.B.ILVL = (uint8)(GPT_REQ_ILVL_PRIO);
  idl_LockProtecReg();
}

/******************************************************************************
** Syntax:          void idl_restore_sys_ints( uint8 previous )              **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  Previous - Previous interrupt status value.              **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This service shall restore various LIN interrupts to     **
**                  their previous settings.                                 **
******************************************************************************/
void idl_restore_sys_ints( uint8 previous )
{
  /* Restore timer interrupt */
  _GPT12E_IC.B.IE = (previous & 0x1U);
  previous = (uint8)(previous >> 1);
  /* Restore Autobaud interrupt */
  USIC_IC_PTR(LIN_CFG_CHANNEL_ID,0U)->B.IE = (previous & 0x1U);
  previous = previous >> 1U;
  /* Restore Channel(Rx) interrupt */
  USIC_IC_PTR(LIN_CFG_CHANNEL_ID,1U)->B.IE = (previous & 0x1U);
}


/******************************************************************************
** Syntax:          uint16 idl_dis_sys_ints(void)                            **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    uint16 - Current interrupt status values                 **
**                                                                           **
** Description:     This service shall disable the current LIN interrupts and**
**                  return the previous status.                              **
******************************************************************************/
uint16 idl_dis_sys_ints(void)
{
  uint16  value;

  value = 0U;
  /* Channel RX interrupt */
  value |= (USIC_IC_PTR(LIN_CFG_CHANNEL_ID,1U)->B.IE);
  USIC_IC_PTR(LIN_CFG_CHANNEL_ID,1U)->B.IE = 0U;
  value = (uint16)(value << 1);

  /* Autobaud interrupt */
  value |= (USIC_IC_PTR(LIN_CFG_CHANNEL_ID,0U)->B.IE);
  USIC_IC_PTR(LIN_CFG_CHANNEL_ID,0U)->B.IE = 0U;
  value = (uint16)(value << 1);

  /* Timer interrupt */
  value |= (_GPT12E_IC.B.IE);
  _GPT12E_IC.B.IE = 0U;

  return(value);
}

/******************************************************************************
** Syntax:          void idl_channel_send(uint8 Data)                        **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  Data - Date byte to be transmitted.                      **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This service shall transmit a byte via the configured    **
**                  LIN channel.                                             **
******************************************************************************/
void idl_channel_send(uint8 Data)
{
  /* Clear all status flags */
  USIC_CHANNEL_PTR->PSCR.U = USIC_RESET_STATUS_FLAGS;
  /* Send data */
  USIC_CHANNEL_PTR->TBUF00[0]= Data;
}

/******************************************************************************
** Syntax:          static void idl_Port_Connect(void)                       **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This service shall initialize the Ports for LIN channel  **
**                  as configured by the user.                               **
******************************************************************************/
void idl_Port_Connect(void)
{
  /* Set IOCR register with the configured pin control attributes-
     Pin Direction, Pin Mode and Pin electrical characteristics.

     The IOCR register is initialized so that when the direction is changed to
     output, the level is already set.
     The reserved bits are written with 0's
  */
  /*lint -e40 */
  /*lint -e409 */
  Port_Set_Input_IOCR();
  Port_Set_Output_IOCR();
  /*lint -e409 */
}
/******************************************************************************
** Syntax:          void idl_Port_Disconnect(void)                           **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This service shall de-initialize the Ports for LIN       **
**                  channel as configured by the user.                       **
******************************************************************************/
#ifdef LIN_V_2_0
  void idl_Port_Disconnect(void)
  {
 	
  }/* idl_Port_Disconnect */
#endif /* #ifdef LIN_V_2_0 */

/******************************************************************************
** Syntax:          idl_change_context                                       **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     dummy function as IIL is common for 8/16bit              **
******************************************************************************/
uint8 idl_change_context(void)
{
  return 0U;
}
/******************************************************************************
** Syntax:          idl_restore_context                                      **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     dummy function as IIL is common for 8/16bit              **
******************************************************************************/
void idl_restore_context( uint8  Page )
{

}

/******************************************************************************
** Syntax:          static void idl_UnlockProtecReg(void)                    **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This function makes it possible to write one protected   **
******************************************************************************/
void idl_UnlockProtecReg(void)
{
  uint16 uwPASSWORD;

  /* command 0 */
  SCU_SLC = 0xAAAAU;                   
  /* command 1 */
  SCU_SLC = 0x5554U;                   

  uwPASSWORD = SCU_SLS & 0x00FFU;
  uwPASSWORD = (~uwPASSWORD) & 0x00FFU;
  
  /* command 2 */
  SCU_SLC = 0x9600U | uwPASSWORD;
  /* command 3 */
  SCU_SLC = 0x0000U;            
}/* End of function idl_UnlockProtecReg */

/******************************************************************************
** Syntax:          static void idl_UnlockProtecReg(void)                    **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):  None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:     This function makes it possible to protect writting      **
**                  to register                                              **
******************************************************************************/
void idl_LockProtecReg(void)
{
  uint16 uwPASSWORD;
  
  /* command 0 */ 
  SCU_SLC = 0xAAAAU;                   
  /* command 1 */ 
  SCU_SLC = 0x5554U;                   

  uwPASSWORD = SCU_SLS & 0x00FFU;
  uwPASSWORD = (~uwPASSWORD) & 0x00FFU;
  
  /* command 2 */ 
  SCU_SLC = 0x9600U | uwPASSWORD;
  /* command 3: new PASSWOR is 0x00 */ 
  SCU_SLC = 0x1800U;

  uwPASSWORD = SCU_SLS & 0x00FFU;
  uwPASSWORD = (~uwPASSWORD) & 0x00FFU;
  /* command 4 */
  SCU_SLC = 0x8E00U | uwPASSWORD;      
} /*  End of function idl_LockProtecReg */

/******************************************************************************
** Syntax:          idl_Setup_TxFIFO                                         **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):   FIFO size , data uffer and the data direction           **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:    Sets up the FIFO                                          **
******************************************************************************/
/* Pointer to'u8Data' could be declared as pointing to const */
/*lint -e818 */
void idl_Setup_TxFIFO( uint8 u8FrmLen , uint8 * u8Data , uint8 u8TxDir)		  
{		  
  uint8 index ;
  
  /* Disable the Frame Finished Interrupt */
  USIC_CHANNEL_PTR->PCRL.U &= ((uint16)(~(uint16)(0x0080)));  
  
  /* Disable FIFO By Setting Size  = 0*/
  USIC_CHANNEL_PTR->TBCTRH.U    &= ((uint16)(~(uint16)(0x0700U)));
  
  /* Setup Fifo PTR and Limit: (Bits 8, 9, and 10 represent the size) */
  /*0x0700; */
  USIC_CHANNEL_PTR->TBCTRL.U  =  (uint16)(((uint16)(u8FrmLen) << (uint16)8) | 
                                 (uint16)0x0000U);
  
  /* Setup Fifo Size and Limits upon which interrupt should be triggered
      This is always set to 8 bytes. No Interrupts on Transmission is set     
  */
  USIC_CHANNEL_PTR->TBCTRH.U  =  0x0300;
  
  /* RX FIFO Setting:  Disable FIFO By Setting Size  = 0*/
  USIC_CHANNEL_PTR->RBCTRH.U    &= ((uint16)(~(uint16)(0x0700)));

  /* Setup Fifo PTR and Size, Always Fixed to size indicated by PID bytes  */
  /* 0x0708;*/
  USIC_CHANNEL_PTR->RBCTRL.U   =  (uint16)(((uint16)(u8FrmLen) << (uint16)8) |
                                  (uint16)0x0008);
  
  /* Enable FIFO and Interrupts*/
  
  /*Standard Rx Interrupt is used, Size is always 8 bytes */
  /*LOF Bit should be one*/
  /* THE FIRST BIT IS THE INTERRUPT SOURCE, this should be set to correct int */
  /* SR 1 for break / frame complete */
  USIC_CHANNEL_PTR->RBCTRH.U     =  0x5301U; 
  
  /*Prepare Data to be Transmitted*/
  /*Flush both FIFOS*/
  USIC_CHANNEL_PTR->TRBSCR.U  |= 0xC000U;
  
  if( (uint8)LIN_FRM_TX== u8TxDir)
  {
    /*Fill in the Tx Data*/
    for (index = (uint8)0 ; index <= u8FrmLen; index++)
    {
      USIC_CHANNEL_PTR->IN00[0]  = *( u8Data + index );
    }
  }  
}		 
/*lint +e818 */ 
/******************************************************************************
** Syntax:          idl_ReadRxFiFo                                           **
**                                                                           **
** Service ID:      NA                                                       **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      Non reentrant                                            **
**                                                                           **
** Parameters(in):   FIFO size , data uffer and the data direction           **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value:    None                                                     **
**                                                                           **
** Description:    Reads the data from FIFO, disables FIFO                   **
******************************************************************************/
void idl_ReadRxFiFo( uint8 u8FrmLen , uint8 * u8Data , uint8 u8TxDir)		  
{  
  uint8 index ; 
  
  /*Required Data Transmission has Finished*/
  if (/*lint -save -e506 */ USIC_CHANNEL_PTR->TRBSRL.U & 0x0001U)/*lint -restore */ 
  {	
  	/* Read the data and validate in case data transmission is receive */
  	for (index = (uint8)0 ; index < u8FrmLen; index++)
  	{
      *(u8Data + index) = (uint8)(USIC_CHANNEL_PTR->OUTRL.U & 0x00FFU);
  	}
  	/* Clear TB and RB Events */
  	USIC_CHANNEL_PTR->TRBSCR.U |= 0x0001U; 
  	
  	/* Flush both FIFO */ 
  	USIC_CHANNEL_PTR->TRBSCR.U  |= 0xC000U; 
  	
  	/*Disable FIFO By Setting Size to 0*/
  	USIC_CHANNEL_PTR->TBCTRH.U    = 0;
  	
  	/*Disable FIFO By Setting Size to 0*/
  	USIC_CHANNEL_PTR->RBCTRH.U    = 0 ;	
  
   	/* Clear the Frame Finished Interrupt here, so
   	 * that it does not enter in that loop anymore
   	 * This HW flag gets set even in case of FIFO
   	*/ 	 
   	/* clear PSR_ST7/RFF */
   	USIC_CHANNEL_PTR->PSCR.U   |= 0x0080U;         
   	USIC_CHANNEL_PTR->PSCR.U   |= 0x0100U;	
   	/* Setup Normal Interrupt Again so that Checksum can be calculated */
   	USIC_CHANNEL_PTR->PCRL.U |= 0x0080U;
 	} 
}/* idl_ReadRxFiFo */  
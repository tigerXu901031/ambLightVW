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
**  FILENAME  : Compiler.h                                                   **
**                                                                           **
**  VERSION   : 1.0.2                                                        **
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
**  DESCRIPTION  : This file contains functionality for compiler abstraction **
**  layer.                                                                   **
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
 * V1.0.2: 2011.11.01, PM  : UTP ID AI00058130 is fixed.
 * V1.0.1: 2010.07.23, PM  : Fixed MISRA checking
 * V1.0.0: 2010.05.19, PM  : Final Released Version
 * V0.1.0: 2010.04.16, PM  : Fixed MISRA checking. . 
 * V0.0.0: 2010.03.12, PM  : Initial version of IDL for LIN
 */

/******************************************************************************
**                      Includes                                             **
******************************************************************************/

#ifndef _COMPILER_H
#define _COMPILER_H

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

/*Keil C51 compiler */
#ifdef __C51__  
  #define KEIL_C51_COMPILER
#endif /*__C51__*/

/* Tasking C166 compiler */
#ifdef __C166__  
  #define TASKING_C166_COMPILER
#endif /*__C166__*/

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
/* typde definitions for data types */
/*  -128 .. +127     */
typedef signed char         sint8;     
/*  0 .. 255         */
typedef unsigned char       uint8;     
/*  -32768 .. +32767 */
typedef signed int          sint16;    
/*  0 .. 65535      */ 
typedef unsigned int        uint16;    

/* -2147483648 .. +2147483647 */
typedef signed long         sint32;    
/* 0 .. 4294967295  */
typedef unsigned long       uint32;    
typedef float               float32;                
typedef double              float64;                

typedef unsigned char       l_bool;

typedef uint8               l_u8;
typedef uint16              l_u16;

#ifdef KEIL_C51_COMPILER 
  typedef bit                 IFX_BIT;
  typedef signed long int     IFX_S32;
  typedef unsigned long int   IFX_U32;
  
  #define IFX_CODE            code
  #define IFX_BDATA           bdata
  #define IFX_IDATA           idata
  #define IFX_XDATA           xdata
  #define IFX_SBIT            sbit
  #define IFX_SFR             sfr
  #define IFX_SFR16           sfr16

  /* intrins.h file contains the decleration of pop and push intrinsic    
      functions,so this file is added automatically.
  */
  #include<intrins.h>

  #define PUSH(SFR_REG)       _push_(SFR_REG)
  #define POP(SFR_REG)        _pop_(SFR_REG)
  #define NOP                 _nop_()  

#elif defined  TASKING_C166_COMPILER  
  #define IFX_CODE  
  #define IFX_BDATA 
  #define IFX_SBIT  
  #define IFX_SFR   
  #define IFX_SFR16 
  
  #define IFX_PSRAM
  #define IFX_DSRAM
  
  #define NOP                 __nop
  #define INTERRUPT           __interrupt
  #define DISWDT              __diswdt
  #define FAR                 __far
  #define INLINE              inline
  #define MKSP                __mksp
  #define SHUGE               __shuge
#endif /* TASKING_C166_COMPILER / KEIL_C51_COMPILER */

/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
#endif /*_COMPILER_H*/

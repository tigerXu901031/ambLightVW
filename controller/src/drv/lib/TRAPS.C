/***********************************************************************/
/*  This file is part of the C166 Compiler package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 1996-2003                           */
/***********************************************************************/
/*                                                                     */
/*  TRAPS.C:  TRAP Handler for C16x/XC16x/ST10/Super10 hardware traps  */
/*                                                                     */
/*  To translate this file use C166 with the following invocation:     */
/*                                                                     */
/*     C166 TRAPS.C                                                    */
/*                                                                     */
/*  To link the modified TRAPS.OBJ file to your application use the    */
/*  following L166 invocation:                                         */
/*                                                                     */
/*     L166 <your object file list>, TRAPS.OBJ <controls>              */
/*                                                                     */
/***********************************************************************/

// #define PRINT_TRAP         // print trap information

#include <intrins.h>
#include <stdio.h>

/*
 * Non-Maskable Interrupt
 */
void NMI_trap (void) interrupt 0x02  {
  /* add your code here */
  while (1);                 /* end-less loop */
}


/*
 * Stack Overflow Interrupt
 */
void STKOF_trap (void) interrupt 0x04  {
  /* add your code here */
  while (1);                 /* end-less loop */
}


/*
 * Stack Underflow Interrupt
 */
void STKUF_trap (void) interrupt 0x06  {
  /* add your code here */
  while (1);                 /* end-less loop */
}


/*
 * Class B Hardware Trap:
 *   ->  Undefined Opcode
 *   ->  Protected Instruction Fault
 *   ->  Illegal Word Operand Access
 *   ->  Illegal Instruction Access
 *   ->  Illegal External Bus Access
 */

#ifdef PRINT_TRAP             // print trap information

#pragma NOFRAME               // do not save registers for interrupt

sfr TFR = 0xFFAC;             // TFR contais Trap Reason

/* TFR Bit  Conditions
 * TFR.0  = Illegal External Bus Access (no external BUS defined for address)
 * TFR.1  = Illegal Instruction Access  (branch to odd address)
 * TFR.2  = Illegal Word Operand Access (word read/write on odd address)
 * TFR.3  = Protection Fault (protected instruction with illegal format)
 * TFR.4  = Illegal or erroneous access to program memory interface
 * TFR.7  = Undefined Opcode (invalid 166/167 op-code)
 * TFR.12 = Software break event
 * TFR.13 = Stack Underflow
 * TFR.14 = Stack Overflow
 * TFR.15 = Non Maskable Interrupt
 */
#endif 

void Class_B_trap (void) interrupt 0x0A  {

#ifdef PRINT_TRAP
  unsigned int ip, csp;

  ip  = _pop_ ();
  csp = _pop_ ();
  printf ("\nClass B Trap at PC=0x%02X%04X TFR=0x%04X\n", csp, ip, TFR); 
#endif 
  /* add your code here */
  while (1);                 /* end-less loop */
}

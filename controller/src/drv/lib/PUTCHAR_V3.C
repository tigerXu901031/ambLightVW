/***********************************************************************/
/*  This file is part of the C166 Compiler package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 1992-2008                           */
/***********************************************************************/
/*                                                                     */
/*  PUTCHAR.C:  This routine is the general character output of C166.  */
/*              This version is adapted for XC2000 and XE16x devices.  */
/*                                                                     */
/*  To translate this file use C166 with the following invocation:     */
/*                                                                     */
/*     C166 PUTCHAR.C                                                  */
/*                                                                     */
/*  To link the modified PUTCHAR.OBJ file to your application use the  */
/*  following L166 invocation:                                         */
/*                                                                     */
/*     L166 <your object file list>, PUTCHAR.OBJ <controls>            */
/*                                                                     */
/***********************************************************************/

#include <XC2287.H>

#define XON  0x11
#define XOFF 0x13

signed char putchar (signed char c)  {

  if (c == '\n')  {
    if (U0C0_PSR & 0x4000)  {       // character received?
      if (U0C0_RBUF == XOFF)  {     // is it a XOFF?
        do  {
          U0C0_PSCR |= 0x4000;      //  clear receive indication flag
          while (!(U0C0_PSR & 0x4000));
        }
        while (U0C0_RBUF != XON);
        U0C0_PSCR |= 0x4000;        //  clear receive indication flag
      }
    }
    while (!(U0C0_PSR & 0x2000));   //  wait until TBUF is empty
    U0C0_PSCR     |= 0x2000;        //  clear transmit buffer indication flag
    U0C0_TBUF00    = 0x0d;          //  output CR
  }
  if (U0C0_PSR & 0x4000)  {         // character received?
    if (U0C0_RBUF == XOFF)  {       // is it a XOFF?
      do  {
        U0C0_PSCR |= 0x4000;        //  clear receive indication flag
        while (!(U0C0_PSR & 0x4000));
      }
      while (U0C0_RBUF != XON);
      U0C0_PSCR |= 0x4000;          //  clear receive indication flag
    }
  }
  while (!(U0C0_PSR & 0x2000));     //  wait until TBUF is empty
  U0C0_PSCR     |= 0x2000;          //  clear transmit buffer indication flag
  U0C0_TBUF00    = c;               //  output character
  return (c);
}

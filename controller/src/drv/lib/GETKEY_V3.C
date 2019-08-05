/***********************************************************************/
/*  This file is part of the C166 Compiler package                     */
/*  Copyright KEIL ELEKTRONIK GmbH 1992-2008                           */
/***********************************************************************/
/*                                                                     */
/*  GETKEY.C:  This routine is the general character input of C166.    */
/*             This version is adapted for XC2000 and XE16x devices.   */
/*                                                                     */
/*  To translate this file use C166 with the following invocation:     */
/*                                                                     */
/*     C166 GETKEY.C                                                   */
/*                                                                     */
/*  To link the modified GETKEY.OBJ file to your application use the   */
/*  following L166 invocation:                                         */
/*                                                                     */
/*     L166 <your object file list>, GETKEY.OBJ <controls>             */
/*                                                                     */
/***********************************************************************/

#include <XC2287.H>


signed char _getkey (void)  {
  char c;

  while (!(U0C0_PSR & 0x4000));
  c = (char) U0C0_RBUF;
  U0C0_PSCR |= 0x4000;        //  clear receive indication flag
  return (c);
}

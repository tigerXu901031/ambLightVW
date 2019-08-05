/*--------------------------------------------------------------------------
SETJMP.H

Prototypes for longjmp facility
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __SETJMP_H__
#define __SETJMP_H__

#ifndef _JMP_BUF_DEFINED
/*               MEDIUM            LARGE             HLARGE */
#if __MODEL__ == 3 || __MODEL__ == 4 || __MODEL__ == 6 || __MODEL__ == 7
 
  #define _JBLEN	14  /* RET-ADDR, SP, R0, R13, R14, R15 */
#else
  #define _JBLEN	12  /* RET-ADDR, SP, R0, R13, R14, R15 */
#endif

typedef  unsigned int jmp_buf[_JBLEN/2];
#define _JMP_BUF_DEFINED
#endif


#ifdef __cplusplus               // EC++
extern "C"  {
#endif

/* function prototypes */

int  setjmp  (jmp_buf jb);
void longjmp (jmp_buf jb, int val);

#ifdef __cplusplus               // EC++
}
#endif

#endif

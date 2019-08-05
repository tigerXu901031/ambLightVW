/*--------------------------------------------------------------------------
SROM.H

Handling for SROM MEMORY SECTIONS
for C166/EC++ Version 5.
Copyright (c) 1998-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __SROM_H__
#define __SROM_H__

#ifdef __cplusplus               // EC++
extern "C"  {
#endif

#define SROM_PS(n)                                                  \
extern unsigned char huge _PR_##n##_s_;  /* section source start */ \
extern unsigned char huge _PR_##n##_l_;  /* section len          */ \
extern unsigned char huge _PR_##n##_t_;  /* target address       */

#define SROM_PS_TRG(n) ((void *)       &_PR_##n##_t_)
#define SROM_PS_SRC(n) ((void *)       &_PR_##n##_s_)
#define SROM_PS_LEN(n) ((unsigned int) &_PR_##n##_l_)

#define CLASS_INFO(n)                                               \
extern unsigned char huge _##n##_l_;     /* class len            */ \
extern unsigned char huge _##n##_t_;     /* class start address  */

#define CLASS_START(n) ((void *) &_##n##_t_)
#define CLASS_LEN(n) ((unsigned long) &_##n##_l_)

#ifdef __cplusplus               // EC++
}
#endif

#endif
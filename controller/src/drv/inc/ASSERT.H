/*--------------------------------------------------------------------------
ASSERT.H

Assert function for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#undef assert

#ifndef	__ASSERT_H__
#include <stdio.h>	/* prototype for 'printf' */
#define	__ASSERT_H__
#endif

#ifndef NDEBUG

#define assert(expr) \
  if (expr) { ; } \
  else  {\
    printf("Assert failed: " #expr " (file %s line %d)\n", __FILE__, (int) __LINE__ );\
    while (1);\
  }
#else
#define	assert(expr)
#endif


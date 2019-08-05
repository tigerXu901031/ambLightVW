/*--------------------------------------------------------------------------
STDDEF.H

Standard definitions
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __STDDEF_H__
#define __STDDEF_H__

#ifndef NULL
 #ifdef __cplusplus              // EC++
   #define NULL   0
 #else
   #define NULL ((void *) 0)
 #endif
#endif

#ifndef _SIZE_T
 #define _SIZE_T
 typedef unsigned int size_t;
#endif


#ifndef _STDDEF_INCLUDED
#define _STDDEF_INCLUDED

typedef int          ptrdiff_t;
#define offsetof(s,m)	(size_t)&(((s *)0)->m)

#endif

#endif

/*--------------------------------------------------------------------------
STDARG.H

Prototypes for variable argument lists
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __STDARG_H__
#define __STDARG_H__

#ifndef NULL
 #ifdef __cplusplus              // EC++
   #define NULL   0
 #else
   #define NULL ((void *) 0)
 #endif
#endif


#ifdef __cplusplus               // EC++
extern "C"  {
#endif

typedef char *va_list;

#define va_start(ap,v) ap=(va_list)&v + ((sizeof(v)+1)&~1)
#define va_arg(ap,t) ((ap+=((sizeof(t)+1)&~1)),*((t*)(ap-((sizeof(t)+1)&~1))))
#define va_end(ap)

#ifdef __cplusplus               // EC++
}
#endif

#endif

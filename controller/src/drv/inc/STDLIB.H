/*--------------------------------------------------------------------------
STDLIB.H

Standard functions
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __STDLIB_H__
#define __STDLIB_H__

#ifndef NULL
 #ifdef __cplusplus              // EC++
   #define NULL   0
 #else
   #define NULL ((void *) 0)
 #endif
#endif


#ifdef __cplusplus               // EC++
extern "C"  {

 // for C++ standard definitions with plain char required 
 #ifndef _WCHAR_T_DEFINED_
  #define _WCHAR_T_DEFINED_
  typedef char wchar_t;
 #endif

#else 

// for C166 ensure: values are signed char (in case of UNSIGNED_CHAR directive)
 #ifndef _WCHAR_T_DEFINED_
  #define _WCHAR_T_DEFINED_
  typedef signed char wchar_t;
 #endif

#endif


#ifndef _SIZE_T
 #define _SIZE_T
 typedef unsigned int size_t;
#endif

#ifndef RAND_MAX
 #define RAND_MAX  32767u
#endif

extern int    abs  (int   val);
extern long  labs  (long  val);

extern double atof (void *s1);

#ifdef __cplusplus               // EC++

// for C++ standard definitions with plain char required 
  extern        double strtod  (const char *str, char **ptr);
  extern          long strtol  (const char *str, char **ptr, int base);
  extern unsigned long strtoul (const char *str, char **ptr, int base);

#else

// for C166 ensure: values are signed char (in case of UNSIGNED_CHAR directive)
  extern         double strtod (const signed char *str, signed char **ptr);
  extern          long strtol  (const signed char *str, signed char **ptr, int base);
  extern unsigned long strtoul (const signed char *str, signed char **ptr, int base);

#endif


extern long   atol (void *s1);
extern int    atoi (void *s1);
extern int    rand (void);
extern void   srand (unsigned int seed);


#if (__MODEL__ != 0)
 #if (__MODEL__ == 7)
   extern void xhuge *malloc    (size_t size);
   extern void free             (void xhuge *p);
   extern void init_mempool     (void xhuge *p, size_t size);
   extern void xhuge *realloc   (void xhuge *p, size_t size);
   extern void xhuge *calloc    (size_t size, size_t len);

   extern void huge *malloc_b   (size_t size);
   extern void free_b           (void huge *p);
   extern void init_mempool_b   (void xhuge *p, unsigned long size);
   extern void huge *realloc_b  (void huge *p, size_t size);
   extern void huge *calloc_b   (size_t size, size_t len);
 #elif (__MODEL__ == 5 || __MODEL__ == 6)
   extern void huge *malloc     (size_t size);
   extern void free             (void huge *p);
   extern void init_mempool     (void huge *p, size_t size);
   extern void huge *realloc    (void huge *p, size_t size);
   extern void huge *calloc     (size_t size, size_t len);

   extern void huge *malloc_b   (size_t size);
   extern void free_b           (void huge *p);
   extern void init_mempool_b   (void xhuge *p, unsigned long size);
   extern void huge *realloc_b  (void huge *p, size_t size);
   extern void huge *calloc_b   (size_t size, size_t len);
 #else
   extern void far *malloc      (size_t size);
   extern void free             (void far *p);
   extern void init_mempool     (void far *p, size_t size);
   extern void far *realloc     (void far *p, size_t size);
   extern void far *calloc      (size_t size, size_t len);

   extern void far *malloc_b    (size_t size);
   extern void free_b           (void far *p);
   extern void init_mempool_b   (void xhuge *p, unsigned long size);
   extern void far *realloc_b   (void far *p, size_t size);
   extern void far *calloc_b    (size_t size, size_t len);
 #endif

  extern void xhuge *xmalloc       (unsigned long size);
  extern void xhuge *xcalloc       (unsigned long size, unsigned long len);
  extern void xhuge *xrealloc      (void xhuge *p, unsigned long size);
  extern void        xinit_mempool (void xhuge *p, unsigned long size);
  extern void        xfree         (void xhuge *p);
#endif

#ifdef __cplusplus               // EC++
}
#endif

#endif

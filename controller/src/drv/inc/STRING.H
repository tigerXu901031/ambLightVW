/*--------------------------------------------------------------------------
STRING.H

String functions
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __STRING_H__
#define __STRING_H__

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

#ifdef __cplusplus               // EC++

extern "C"  {

// for C++ standard definitions with plain char required 
extern char *strcat  (char *s1, const char *s2);
extern char *strncat (char *s1, const char *s2, unsigned int n);

extern int   strcmp  (const char *s1, const char *s2);
extern int   strncmp (const char *s1, const char *s2, unsigned int n);

extern char *strcpy  (char *s1, const char *s2);
extern char *strncpy (char *s1, const char *s2, unsigned int n);

extern size_t strlen (const char *s);

extern char *strchr  (const char *s, char c);
extern int   strpos  (const char *s, char c);
extern char *strrchr (const char *s, char c);
extern int   strrpos (const char *s, char c);

extern int   strspn  (const char *s, const char *set);
extern int   strcspn (const char *s, const char *set);
extern char *strpbrk (const char *s, const char *set);
extern char *strrpbrk(const char *s, const char *set);
extern char *strstr  (const char *s, const char *sub);

extern int   memcmp  (const void *s1, const void *s2, unsigned int n);
extern void *memcpy  (void *s1,       const void *s2, unsigned int n);
extern void *memchr  (const void *s,  char val, unsigned int n);
extern void *memccpy (void *s1,       const void *s2, char val, unsigned int n);
extern void *memmove (void *s1,       const void *s2, unsigned int n);
extern void *memset  (void *s,        const char val, unsigned int n);

#if (__MODEL__ != 0)          /* if not tiny model */
extern char far *fstrcat  (char far *s1, const char far *s2);
extern char far *fstrncat (char far *s1, const char far *s2, unsigned int n);

extern int fstrcmp  (const char far *s1, const char far *s2);
extern int fstrncmp (const char far *s1, const char far *s2, unsigned int n);

extern char far *fstrcpy  (char far *s1, const char far *s2);
extern char far *fstrncpy (char far *s1, const char far *s2, unsigned int n);

extern size_t fstrlen (char far *s);

extern char far *fstrchr  (const char far *s, char c);
extern char far *fstrrchr (const char far *s, char c);
extern int       fstrpos  (const char far *s, char c);
extern int       fstrrpos (const char far *s, char c);

extern int       fstrspn  (const char far *s, const char far *set);
extern int       fstrcspn (const char far *s, const char far *set);
extern char far *fstrpbrk (const char far *s, const char far *set);
extern char far *fstrrpbrk(const char far *s, const char far *set);

extern      int  fmemcmp  (const void far *s1, const void far *s2, unsigned int n);
extern void far *fmemcpy  (void far *s1,       const void far *s2, unsigned int n);
extern void far *fmemchr  (const void far *s,  char val, unsigned int n);
extern void far *fmemccpy (void far *s1,       const void far *s2, char val, unsigned int n);
extern void far *fmemmove (void far *s1,       const void far *s2, unsigned int n);
extern void far *fmemset  (void far *s,        const char val, unsigned int n);

extern      int   hmemcmp (const void huge *s1, const void huge *s2, unsigned int n);
extern void huge *hmemcpy (void huge *s1,       const void huge *s2, unsigned int n);
extern      int   hstrcmp (const char huge *s1, const char huge *s2);
extern char huge *hstrcpy (char huge *s1,       const char huge *s2);

extern      int    xmemcmp  (const void xhuge *s1, const void xhuge *s2, unsigned long n);
extern void xhuge *xmemcpy  (void xhuge *s1, const void xhuge *s2, unsigned long n);
extern void xhuge *xmemchr  (void xhuge *s, char val, unsigned long n);
extern void xhuge *xmemccpy (void xhuge *s1, const void xhuge *s2, char val, unsigned long n);
extern void xhuge *xmemmove (void xhuge *s1, const void xhuge *s2, unsigned long n);
extern void xhuge *xmemset  (void xhuge *s, char val, unsigned long n);

extern unsigned int xstrlen  (const char xhuge *s);
extern          int xstrcmp  (const char xhuge *s1, const char xhuge *s2);
extern char xhuge  *xstrcpy  (char xhuge *s1,       const char xhuge *s2);
extern char xhuge  *xstrncpy (char xhuge *s1,       const char xhuge *s2, unsigned int n);
#endif

}

#else

// for C166 ensure: values are signed char (in case of UNSIGNED_CHAR directive)

extern signed char *strcat  (signed char *s1, const signed char *s2);
extern signed char *strncat (signed char *s1, const signed char *s2, unsigned int n);

extern int strcmp  (const signed char *s1, const signed char *s2);
extern int strncmp (const signed char *s1, const signed char *s2, unsigned int n);

extern signed char *strcpy  (signed char *s1, const signed char *s2);
extern signed char *strncpy (signed char *s1, const signed char *s2, unsigned int n);

extern size_t strlen (const signed char *s);

extern signed char *strchr   (const signed char *s, signed char c);
extern int          strpos   (const signed char *s, signed char c);
extern signed char *strrchr  (const signed char *s, signed char c);
extern int          strrpos  (const signed char *s, signed char c);

extern int          strspn   (const signed char *s, const signed char *set);
extern int          strcspn  (const signed char *s, const signed char *set);
extern signed char *strpbrk  (const signed char *s, const signed char *set);
extern signed char *strrpbrk (const signed char *s, const signed char *set);
extern signed char *strstr   (const signed char *s, const signed char *sub);

extern int   memcmp  (const void *s1, const void *s2, unsigned int n);
extern void *memcpy  (void *s1,       const void *s2, unsigned int n);
extern void *memchr  (const void *s,  signed char val, unsigned int n);
extern void *memccpy (void *s1,       const void *s2, char val, unsigned int n);
extern void *memmove (void *s1,       const void *s2, unsigned int n);
extern void *memset  (void *s,        signed char val, unsigned int n);

#if (__MODEL__ != 0)          /* if not tiny model */
extern signed char far *fstrcat  (signed char far *s1, const signed char far *s2);
extern signed char far *fstrncat (signed char far *s1, const signed char far *s2, unsigned int n);

extern int fstrcmp  (const signed char far *s1, const signed char far *s2);
extern int fstrncmp (const signed char far *s1, const signed char far *s2, unsigned int n);

extern signed char far *fstrcpy  (signed char far *s1, const signed char far *s2);
extern signed char far *fstrncpy (signed char far *s1, const signed char far *s2, unsigned int n);

extern size_t fstrlen (const signed char far *s);

extern signed char far *fstrchr  (const signed char far *s, char c);
extern signed char far *fstrrchr (const signed char far *s, char c);
extern int              fstrpos  (const signed char far *s, signed char c);
extern int              fstrrpos (const signed char far *s, signed char c);

extern int              fstrspn   (const signed char far *s, const signed char far *set);
extern int              fstrcspn  (const signed char far *s, const signed char far *set);
extern signed char far *fstrpbrk  (const signed char far *s, const signed char far *set);
extern signed char far *fstrrpbrk (const signed char far *s, const signed char far *set);

extern      int  fmemcmp  (const void far *s1, const void far *s2, unsigned int n);
extern void far *fmemcpy  (void far *s1,       const void far *s2, unsigned int n);
extern void far *fmemchr  (const void far *s,  signed char val, unsigned int n);
extern void far *fmemccpy (void far *s1,       const void far *s2, char val, unsigned int n);
extern void far *fmemmove (void far *s1,       const void far *s2, unsigned int n);
extern void far *fmemset  (void far *s,        signed char val, unsigned int n);

extern      int   hmemcmp  (const void huge *s1, const void huge *s2, unsigned int n);
extern void huge *hmemcpy  (void huge *s1,       const void huge *s2, unsigned int n);
extern      int   hstrcmp  (signed char huge *s1, signed char huge *s2);
extern signed char huge *hstrcpy  (signed char huge *s1, signed char huge *s2);

extern      int    xmemcmp  (const void xhuge *s1, const void xhuge *s2, unsigned long n);
extern void xhuge *xmemcpy  (void xhuge *s1,       const void xhuge *s2, unsigned long n);
extern void xhuge *xmemchr  (const void xhuge *s,  signed char val, unsigned long n);
extern void xhuge *xmemccpy (void xhuge *s1,       const void xhuge *s2, char val, unsigned long n);
extern void xhuge *xmemmove (void xhuge *s1,       const void xhuge *s2, unsigned long n);
extern void xhuge *xmemset  (void xhuge *s,  signed char val, unsigned long n);

extern unsigned int       xstrlen  (const char xhuge *s);
extern          int       xstrcmp  (const signed char xhuge *s1, const signed char xhuge *s2);
extern signed char xhuge *xstrcpy  (signed char xhuge *s1, const signed char xhuge *s2);
extern signed char xhuge *xstrncpy (signed char xhuge *s1, const signed char xhuge *s2, unsigned int n);

#endif

#endif

#endif

/*--------------------------------------------------------------------------
STDIO.H
Prototypes for standard I/O functions
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __STDIO_H__
#define __STDIO_H__

#ifndef EOF
 #define EOF -1
#endif

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
extern char _getkey   (void);
extern char getchar   (void);
extern char ungetchar (char ch);
extern char putchar   (char ch);
extern int  printf    (const char *fmt, ...);
extern int  sprintf   (char *buf, const char *fmt, ...);
extern int  vprintf   (const char *fmt, char *argptr);
extern int  vsprintf  (char *buf, const char *fmt, char *argptr);
extern char *gets (char *str, unsigned int len);
extern int  scanf (const char *fmt, ...);
extern int  sscanf (char *buf, const char *fmt, ...);
extern int  puts (const char *str);

}

#else

// for C166 ensure: values are signed char (in case of UNSIGNED_CHAR directive)
extern signed char _getkey   (void);
extern signed char getchar   (void);
extern signed char ungetchar (signed char ch);
extern signed char putchar (signed char ch);
extern int          printf (const signed char *fmt, ...);
extern int          sprintf (signed char *buf, const signed char *fmt, ...);
extern int          vprintf (const signed char *fmt, signed char *argptr);
extern int          vsprintf (signed char *buf, const signed char *fmt, signed char *argptr);
extern signed char *gets (signed char *str, unsigned int len);
extern int          scanf (const signed char *fmt, ...);
extern int          sscanf (signed char *buf, const signed char *fmt, ...);
extern int          puts (const signed char *str);

#endif

#endif

/*--------------------------------------------------------------------------
CTYPE.H

Prototypes for character functions
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __CTYPE_H__
#define __CTYPE_H__

#ifdef __cplusplus               // EC++
extern "C"  {
#endif

extern int isalpha  (int ch);
extern int isalnum  (int ch);
extern int iscntrl  (int ch);
extern int isdigit  (int ch);
extern int isgraph  (int ch);
extern int isprint  (int ch);
extern int ispunct  (int ch);
extern int islower  (int ch);
extern int isupper  (int ch);
extern int isspace  (int ch);
extern int isxdigit (int ch);
extern int tolower  (int ch);
extern int toupper  (int ch);
extern int toint    (int ch);

#define _tolower(c) ( (c)-'A'+'a' )
#define _toupper(c) ( (c)-'a'+'A' )
#define toascii(c)  ( (c) & 0x7F )

#ifdef __cplusplus               // EC++
}
#endif

#endif

/*--------------------------------------------------------------------------
ERRNO.H

ANSI standard include file
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef	__ERRNO_H__
#define __ERRNO_H__
#define errno  (0)

/* Floating point errors, currently not implemented in libraries          */
#define	ERANGE		1	/* Value out of range                     */
#define	EDOM		2	/* Floating point domain error            */

#endif

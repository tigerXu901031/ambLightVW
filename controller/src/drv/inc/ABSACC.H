/*--------------------------------------------------------------------------
ABSACC.H

Direct access to 166 memory areas for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __ABSACC_H__
#define __ABSACC_H__

#if (__MODEL__ == 0)
  #define MVAR(object, addr)   (*((object volatile *) (addr)))
  #define MARRAY(object, base) ((object volatile *) (base))
#else
  #define MVAR(object, addr)   (*((object volatile far *) (addr)))
  #define MARRAY(object, base) ((object volatile far *) (base))

  #define HVAR(object, addr)   (*((object volatile huge *) (addr)))
  #define HARRAY(object, base) ((object volatile huge *) (base))
  #define XVAR(object, addr)   (*((object volatile xhuge *) (addr)))
  #define XARRAY(object, base) ((object volatile xhuge *) (base))
#endif

#endif

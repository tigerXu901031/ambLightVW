/*--------------------------------------------------------------------------
FLOAT.H

Limits for floating point types
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __FLOAT_H__
#define __FLOAT_H__

#define FLT_RADIX        2
#define FLT_ROUNDS       1      /* round to nearest */

#define FLT_DIG          6
#define FLT_EPSILON      1.907348634e-6
#define FLT_MANT_DIG     24
#define FLT_MAX          3.40282e38
#define FLT_MAX_EXP      127
#define FLT_MAX_10_EXP   38
#define FLT_MIN          1.17549e-38
#define FLT_MIN_EXP      (-127)
#define FLT_MIN_10_EXP   -37

#if __FLOAT64__

#define DBL_RADIX       2
#define DBL_ROUNDS      1       /* round to nearest */
#define DBL_DIG         15
#define DBL_EPSILON     1.77635683940025040e-015
#define DBL_MANT_DIG    53
#define DBL_MAX         1.79769313486231500e+308
#define DBL_MAX_EXP     1023
#define DBL_MAX_10_EXP  308
#define DBL_MIN         2.22507385850720200e-308
#define DBL_MIN_EXP     (-1023)
#define DBL_MIN_10_EXP  -307

#define LDBL_RADIX      DBL_RADIX 
#define LDBL_ROUNDS     DBL_ROUNDS
#define LDBL_DIG        DBL_DIG
#define LDBL_EPSILON    DBL_EPSILON
#define LDBL_MANT_DIG   DBL_MANT_DIG
#define LDBL_MAX        DBL_MAX
#define LDBL_MAX_EXP    DBL_MAX_EXP
#define LDBL_MAX_10_EXP DBL_MAX_10_EXP
#define LDBL_MIN        DBL_MIN
#define LDBL_MIN_EXP    DBL_MIN_EXP
#define LDBL_MIN_10_EXP DBL_MIN_10_EXP


#else

#define DBL_RADIX       FLT_RADIX 
#define DBL_ROUNDS      FLT_ROUNDS
#define DBL_DIG         FLT_DIG
#define DBL_EPSILON     FLT_EPSILON
#define DBL_MANT_DIG    FLT_MANT_DIG
#define DBL_MAX         FLT_MAX
#define DBL_MAX_EXP     FLT_MAX_EXP
#define DBL_MAX_10_EXP  FLT_MAX_10_EXP
#define DBL_MIN         FLT_MIN
#define DBL_MIN_EXP     FLT_MIN_EXP
#define DBL_MIN_10_EXP  FLT_MIN_10_EXP

#define LDBL_RADIX      FLT_RADIX 
#define LDBL_ROUNDS     FLT_ROUNDS
#define LDBL_DIG        FLT_DIG
#define LDBL_EPSILON    FLT_EPSILON
#define LDBL_MANT_DIG   FLT_MANT_DIG
#define LDBL_MAX        FLT_MAX
#define LDBL_MAX_EXP    FLT_MAX_EXP
#define LDBL_MAX_10_EXP FLT_MAX_10_EXP
#define LDBL_MIN        FLT_MIN
#define LDBL_MIN_EXP    FLT_MIN_EXP
#define LDBL_MIN_10_EXP FLT_MIN_10_EXP

#endif

#endif

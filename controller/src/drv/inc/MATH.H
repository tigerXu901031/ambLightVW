/*--------------------------------------------------------------------------
MATH.H

Prototypes for mathematic functions
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __MATH_H__
#define __MATH_H__

#ifdef __cplusplus               // EC++
extern "C"  {
#endif

extern int     abs  (int   val);
extern long   labs  (long  val);
extern double fabs  (double val);
extern double sqrt  (double val);
extern double exp   (double val);
extern double log   (double val);
extern double log10 (double val);
extern double sin   (double val);
extern double cos   (double val);
extern double tan   (double val);
extern double asin  (double val);
extern double acos  (double val);
extern double atan  (double val);
extern double sinh  (double val);
extern double cosh  (double val);
extern double tanh  (double val);
extern double atan2 (double y, double x);

extern double ceil  (double val);
extern double floor (double val);
extern double modf  (double val, double *n);
extern double fmod  (double x, double y);
extern double pow   (double x, double y);

extern unsigned int _chkfloat_  (float x);
extern unsigned int _chkdouble_ (double x);

#ifdef __cplusplus               // EC++
}
#endif

#endif

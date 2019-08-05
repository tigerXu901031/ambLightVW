/*--------------------------------------------------------------------------
INTRINS.H

Intrinsic functions
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __INTRINS_H__
#define __INTRINS_H__

#ifdef __cplusplus               // EC++
extern "C"  {
#endif

void       _nop_ (void);
void      _idle_ (void);
void    _srvwdt_ (void);
void     _pwrdn_ (void);
void    _diswdt_ (void);
void     _einit_ (void);
void      _bfld_ (unsigned int sfr_, unsigned mask1, unsigned mask2);
void      _trap_ (int intno);
void    _atomic_ (int n_instr);
void _endatomic_ (void);
#if (__MODEL__ != 0)          /* if not tiny model */
unsigned int _sof_ (void huge *adr);
#else
unsigned int _sof_ (void *adr);
#endif
bit _testclear_ (bit);
bit _testset_   (bit);
extern unsigned char _crol_   (unsigned char v, int cnt);
extern unsigned int  _irol_   (unsigned int  v, int cnt);
extern unsigned long _lrol_   (unsigned long v, int cnt);
extern unsigned char _cror_   (unsigned char v, int cnt);
extern unsigned int  _iror_   (unsigned int  v, int cnt);
extern unsigned long _lror_   (unsigned long v, int cnt);
extern           int _prior_  (int v);
extern           int _priord_ (long v);
extern           int _pop_    (void);
extern          void _push_   (int v);


extern unsigned int _chkfloat_  (float x);
extern unsigned int _chkdouble_ (double x);

#ifdef __cplusplus               // EC++
}
#endif

#endif

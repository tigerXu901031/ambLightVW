
/*--------------------------------------------------------------------------
ST10MAC.H

ST10 MAC Intrinsic functions for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifdef __cplusplus               // EC++
extern "C"  {
#endif

/*
 * MAC Function Sub-Codes
 */
#define CoMUL        0xC0
#define CoMULu       0x00
#define CoMULus      0x80
#define CoMULsu      0x40
#define CoMUL_       0xC8
#define CoMULu_      0x08
#define CoMULus_     0x88
#define CoMULsu_     0x48
#define rndCoMUL     0xC1
#define rndCoMULu    0x01
#define rndCoMULus   0x81
#define rndCoMULsu   0x41
#define CoMAC        0xD0
#define CoMACu       0x10
#define CoMACus      0x90
#define CoMACsu      0x50
#define CoMAC_       0xE0
#define CoMACu_      0x20
#define CoMACus_     0xA0
#define CoMACsu_     0x60
#define rndCoMAC     0xD1
#define rndCoMACu    0x11
#define rndCoMACus   0x91
#define rndCoMACsu   0x51
#define rndCoMAC_    0xE1
#define rndCoMACu_   0x21
#define rndCoMACus_  0xA1
#define rndCoMACsu_  0x61
#define CoMACR       0xF0
#define CoMACRu      0x30
#define CoMACRus     0xB0
#define CoMACRsu     0x70
#define rndCoMACR    0xF1
#define rndCoMACRu   0x31
#define rndCoMACRus  0xB1
#define rndCoMACRsu  0x71
#define CoNOP        0x5A
#define CoNEG        0x32
#define rndCoNEG     0x72
#define CoABSacc     0x1A      // CoABS Op1,Op2
#define CoABS        0xCA      // CoABS no-Operands
#define CoMACM       0xD8
#define CoMACMu      0x18
#define CoMACMus     0x98
#define CoMACMsu     0x58
#define CoMACM_      0xE8
#define CoMACMu_     0x28
#define CoMACMus_    0xA8
#define CoMACMsu_    0x68
#define rndCoMACM    0xD9
#define rndCoMACMu   0x19
#define rndCoMACMus  0x99
#define rndCoMACMsu  0x59
#define CoMACMR      0xF8
#define CoMACMRu     0x38
#define CoMACMRus    0xB8
#define CoMACMRsu    0x78
#define rndCoMACMR   0xF9
#define rndCoMACMRu  0x39
#define rndCoMACMRus 0xB9
#define rndCoMACMRsu 0x79
#define CoADD        0x02
#define CoADD2       0x42
#define CoSUB        0x0A
#define CoSUB2       0x4A
#define CoSUBR       0x12
#define CoSUB2R      0x52
#define CoMAX        0x3A
#define CoMIN        0x7A
#define CoLOAD       0x22
#define CoLOAD_      0x2A
#define CoLOAD2      0x62
#define CoLOAD2_     0x6A
#define CoCMP        0xC2
#define CoSHLcnt     0x82
#define CoSHL        0x8A
#define CoSHRcnt     0x92
#define CoSHR        0x9A
#define CoASHRcnt    0xA2
#define CoASHR       0xAA
#define rndCoASHRcnt 0xB2
#define rndCoASHR    0xBA

/*
 * MAC Register Codes  (rcode)
 */
#define _IDX0_       0x01   // [IDX0]
#define _IDX0p_      0x02   // [IDX0+]
#define _IDX0m_      0x03   // [IDX0-]
#define _IDX0pQX0_   0x04   // [IDX0+QX0]
#define _IDX0mQX0_   0x05   // [IDX0-QX0]
#define _IDX0pQX1_   0x06   // [IDX0+QX0]
#define _IDX0mQX1_   0x07   // [IDX0-QX0]
#define _IDX1_       0x09   // [IDX1]
#define _IDX1p_      0x0A   // [IDX1+]
#define _IDX1m_      0x0B   // [IDX1-]
#define _IDX1pQX0_   0x0C   // [IDX1+QX0]
#define _IDX1mQX0_   0x0D   // [IDX1-QX0]
#define _IDX1pQX1_   0x0E   // [IDX1+QX0]
#define _IDX1mQX1_   0x0F   // [IDX1-QX0]

extern void _mac_  (unsigned char icode,   // instruction code constant
                    unsigned int  op1,     // value 1
                    unsigned int  op2);    // value 2
 
extern void _macl_ (unsigned char icode,   // instruction code constant
                    unsigned long op1);    // value 1

extern void _macv_ (unsigned char icode);  // value 1

extern void _maci_ (unsigned char icode,   // instruction code constant
                    unsigned char rcode,   // register code constant
                    unsigned int near *op2);    // pointer to value 2

extern void _macs_ (unsigned char icode,   // instruction code constant
                    unsigned int  op);     // value

extern unsigned long _lmac_ (void);        // returns MAH, MAL with CoStore
extern unsigned long _lmac_sat_ (void);    // returns MAS, MAL with CoStore
extern unsigned int  _imac_sat_ (void);    // returns MAS      with CoStore

extern void _mmov_ (void near *s, void near *p, unsigned int cnt);
                // generates CoMOV [IDX+],[Rx+]

#ifdef __cplusplus               // EC++
}
#endif

/*--------------------------------------------------------------------------
REG164.H

Register Declarations for C164Cx / Sx Processor
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __REG164_H__
#define __REG164_H__

/* A/D Converter */
sfr   ADCIC    = 0xFF98;
sfr   ADCON    = 0xFFA0;
sfr   ADDAT    = 0xFEA0;
sfr   ADEIC    = 0xFF9A;
sfr   ADDAT2   = 0xF0A0;
sbit  ADST     = ADCON^7;
sbit  ADBSY    = ADCON^8;
sbit  ADWR     = ADCON^9;
sbit  ADCIN    = ADCON^10;
sbit  ADCRQ    = ADCON^11;
sbit  ADCIE    = ADCIC^6;
sbit  ADCIR    = ADCIC^7;
sbit  ADEIE    = ADEIC^6;
sbit  ADEIR    = ADEIC^7;

/* Timer 0, Timer 1, Timer 7, Timer 8 */
sfr   CC8IC    = 0xFF88;
sfr   CC9IC    = 0xFF8A;
sfr   CC10IC   = 0xFF8C;
sfr   CC11IC   = 0xFF8E;
sfr   CC16     = 0xFE60;
sfr   CC16IC   = 0xF160;
sfr   CC17     = 0xFE62;
sfr   CC17IC   = 0xF162;
sfr   CC18     = 0xFE64;
sfr   CC18IC   = 0xF164;
sfr   CC19     = 0xFE66;
sfr   CC19IC   = 0xF166;
sfr   CC24     = 0xFE70;
sfr   CC24IC   = 0xF170;
sfr   CC25     = 0xFE72;
sfr   CC25IC   = 0xF172;
sfr   CC26     = 0xFE74;
sfr   CC26IC   = 0xF174;
sfr   CC27     = 0xFE76;
sfr   CC27IC   = 0xF176;

sfr   CCM4     = 0xFF22;
sfr   CCM6     = 0xFF26;
sfr   T7       = 0xF050;
sfr   T78CON   = 0xFF20;
sfr   T7IC     = 0xF17A;
sfr   T7REL    = 0xF054;
sfr   T8       = 0xF052;
sfr   T8IC     = 0xF17C;
sfr   T8REL    = 0xF056;
sbit  CC8IR    = CC8IC^7;
sbit  CC8IE    = CC8IC^6;
sbit  CC9IR    = CC9IC^7;
sbit  CC9IE    = CC9IC^6;
sbit  CC10IR   = CC10IC^7;
sbit  CC10IE   = CC10IC^6;
sbit  CC11IR   = CC11IC^7;
sbit  CC11IE   = CC11IC^6;
sbit  CC16IR   = CC16IC^7;
sbit  CC16IE   = CC16IC^6;
sbit  CC17IR   = CC17IC^7;
sbit  CC17IE   = CC17IC^6;
sbit  CC18IR   = CC18IC^7;
sbit  CC18IE   = CC18IC^6;
sbit  CC19IR   = CC19IC^7;
sbit  CC19IE   = CC19IC^6;
sbit  CC24IR   = CC24IC^7;
sbit  CC24IE   = CC24IC^6;
sbit  CC25IR   = CC25IC^7;
sbit  CC25IE   = CC25IC^6;
sbit  CC26IR   = CC26IC^7;
sbit  CC26IE   = CC26IC^6;
sbit  CC27IR   = CC27IC^7;
sbit  CC27IE   = CC27IC^6;
sbit  ACC16    = CCM4^3;
sbit  ACC17    = CCM4^7;
sbit  ACC18    = CCM4^11;
sbit  ACC19    = CCM4^15;
sbit  ACC24    = CCM6^3;
sbit  ACC25    = CCM6^7;
sbit  ACC26    = CCM6^11;
sbit  ACC27    = CCM6^15;
sbit  T7IE     = T7IC^6;
sbit  T7IR     = T7IC^7;
sbit  T7M      = T78CON^3;
sbit  T7R      = T78CON^6;
sbit  T8IE     = T8IC^6;
sbit  T8IR     = T8IC^7;
sbit  T8M      = T78CON^11;
sbit  T8R      = T78CON^14;

/* CPU */
sfr   CP       = 0xFE10;
sfr   CSP      = 0xFE08;
sfr   DPP0     = 0xFE00;
sfr   DPP1     = 0xFE02;
sfr   DPP2     = 0xFE04;
sfr   DPP3     = 0xFE06;
sfr   MDC      = 0xFF0E;
sfr   MDH      = 0xFE0C;
sfr   MDL      = 0xFE0E;
sfr   ONES     = 0xFF1E;
sfr   PSW      = 0xFF10;
sfr   SP       = 0xFE12;
sfr   STKOV    = 0xFE14;
sfr   STKUN    = 0xFE16;
sfr   SYSCON   = 0xFF12;
sfr   TFR      = 0xFFAC;
sfr   ZEROS    = 0xFF1C;
sfr   BUSCON0  = 0xFF0C;
sfr   BUSCON1  = 0xFF14;
sfr   BUSCON2  = 0xFF16;
sfr   BUSCON3  = 0xFF18;
sfr   BUSCON4  = 0xFF1A;
sfr   ADDRSEL1 = 0xFE18;
sfr   ADDRSEL2 = 0xFE1A;
sfr   ADDRSEL3 = 0xFE1C;
sfr   ADDRSEL4 = 0xFE1E;
sbit  WRCFG    = SYSCON^7;
sbit  CLKEN    = SYSCON^8;
sbit  BYTDIS   = SYSCON^9;
sbit  ROMEN    = SYSCON^10;
sbit  SGTEN    = SYSCON^11;
sbit  ROMS1    = SYSCON^12;
sbit  MDRIU    = MDC^4;
sbit  N        = PSW^0;
sbit  C        = PSW^1;
sbit  V        = PSW^2;
sbit  Z        = PSW^3;
sbit  E        = PSW^4;
sbit  MULIP    = PSW^5;
sbit  USR0     = PSW^6;
sbit  HLDEN    = PSW^10;
sbit  IEN      = PSW^11;
sbit  RWDC0    = BUSCON0^4;
sbit  MTTC0    = BUSCON0^5;
sbit  ALECTL0  = BUSCON0^9;
sbit  BUSACT0  = BUSCON0^10;
sbit  RDYEN0   = BUSCON0^12;
sbit  RWDC1    = BUSCON1^4;
sbit  MTTC1    = BUSCON1^5;
sbit  ALECTL1  = BUSCON1^9;
sbit  BUSACT1  = BUSCON1^10;
sbit  RDYEN1   = BUSCON1^12;
sbit  CSREN1   = BUSCON1^14;
sbit  CSWEN1   = BUSCON1^15;
sbit  RWDC2    = BUSCON2^4;
sbit  MTTC2    = BUSCON2^5;
sbit  ALECTL2  = BUSCON2^9;
sbit  BUSACT2  = BUSCON2^10;
sbit  RDYEN2   = BUSCON2^12;
sbit  CSREN2   = BUSCON2^14;
sbit  CSWEN2   = BUSCON2^15;
sbit  RWDC3    = BUSCON3^4;
sbit  MTTC3    = BUSCON3^5;
sbit  ALECTL3  = BUSCON3^9;
sbit  BUSACT3  = BUSCON3^10;
sbit  RDYEN3   = BUSCON3^12;
sbit  CSREN3   = BUSCON3^14;
sbit  CSWEN3   = BUSCON3^15;
sbit  RWDC4    = BUSCON4^4;
sbit  MTTC4    = BUSCON4^5;
sbit  ALECTL4  = BUSCON4^9;
sbit  BUSACT4  = BUSCON4^10;
sbit  RDYEN4   = BUSCON4^12;
sbit  CSREN4   = BUSCON4^14;
sbit  CSWEN4   = BUSCON4^15;
sbit  ILLBUS   = TFR^0;
sbit  ILLINA   = TFR^1;
sbit  ILLOPA   = TFR^2;
sbit  PRTFLT   = TFR^3;
sbit  UNDOPC   = TFR^7;
sbit  STKUF    = TFR^13;
sbit  STKOF    = TFR^14;
sbit  NMI      = TFR^15;
sfr   EXICON   = 0xF1C0;

/* PEC */
sfr   PECC0    = 0xFEC0;
sfr   PECC1    = 0xFEC2;
sfr   PECC2    = 0xFEC4;
sfr   PECC3    = 0xFEC6;
sfr   PECC4    = 0xFEC8;
sfr   PECC5    = 0xFECA;
sfr   PECC6    = 0xFECC;
sfr   PECC7    = 0xFECE;

#define  SRCP0 (*((unsigned int volatile sdata *) 0xFCE0))
#define  DSTP0 (*((unsigned int volatile sdata *) 0xFCE2))
#define  SRCP1 (*((unsigned int volatile sdata *) 0xFCE4))
#define  DSTP1 (*((unsigned int volatile sdata *) 0xFCE6))
#define  SRCP2 (*((unsigned int volatile sdata *) 0xFCE8))
#define  DSTP2 (*((unsigned int volatile sdata *) 0xFCEA))
#define  SRCP3 (*((unsigned int volatile sdata *) 0xFCEC))
#define  DSTP3 (*((unsigned int volatile sdata *) 0xFCEE))
#define  SRCP4 (*((unsigned int volatile sdata *) 0xFCF0))
#define  DSTP4 (*((unsigned int volatile sdata *) 0xFCF2))
#define  SRCP5 (*((unsigned int volatile sdata *) 0xFCF4))
#define  DSTP5 (*((unsigned int volatile sdata *) 0xFCF6))
#define  SRCP6 (*((unsigned int volatile sdata *) 0xFCF8))
#define  DSTP6 (*((unsigned int volatile sdata *) 0xFCFA))
#define  SRCP7 (*((unsigned int volatile sdata *) 0xFCFC))
#define  DSTP7 (*((unsigned int volatile sdata *) 0xFCFE))

/* added SFRs for OTP Programming */
#define  OPAD   (*((unsigned int volatile sdata *) 0xEDC2)) /* OTP Programming Interface Address Register */
#define  OPCTRL (*((unsigned int volatile sdata *) 0xEDC0)) /* OTP Programming Interface Control Register */
#define  OPDAT  (*((unsigned int volatile sdata *) 0xEDC4)) /* OTP Programming Interface Data Register    */

/* I/O Ports */
sfr   DP0L     = 0xF100;
sfr   DP0H     = 0xF102;
sfr   DP1L     = 0xF104;
sfr   DP1H     = 0xF106;
sfr   DP3      = 0xFFC6;
sfr   DP4      = 0xFFCA;
sfr   DP8      = 0xFFD6;
sfr   P0L      = 0xFF00;
sfr   P0H      = 0xFF02;
sfr   P1L      = 0xFF04;
sfr   P1H      = 0xFF06;
sfr   P3       = 0xFFC4;
sfr   P4       = 0xFFC8;
sfr   P5       = 0xFFA2;
sfr   P5DIDIS  = 0xFFA4;
sfr   P8       = 0xFFD4;
sfr   ODP3     = 0xF1C6;
sfr   ODP8     = 0xF1D6;
sfr   RP0H     = 0xF108;
sfr   PICON    = 0xF1C4;

/* Serial Interface */
sfr   S0BG     = 0xFEB4;
sfr   S0CON    = 0xFFB0;
sfr   S0EIC    = 0xFF70;
sfr   S0RBUF   = 0xFEB2;
sfr   S0RIC    = 0xFF6E;
sfr   S0TBUF   = 0xFEB0;
sfr   S0TIC    = 0xFF6C;
sfr   S0TBIC   = 0xF19C;
sbit  S0STP    = S0CON^3;
sbit  S0REN    = S0CON^4;
sbit  S0PEN    = S0CON^5;
sbit  S0FEN    = S0CON^6;
sbit  S0OEN    = S0CON^7;
sbit  S0PE     = S0CON^8;
sbit  S0FE     = S0CON^9;
sbit  S0OE     = S0CON^10;
sbit  S0ODD    = S0CON^12;
sbit  S0BRS    = S0CON^13;
sbit  S0LB     = S0CON^14;
sbit  S0R      = S0CON^15;
sbit  S0TIE    = S0TIC^6;
sbit  S0TIR    = S0TIC^7;
sbit  S0TBIE   = S0TBIC^6;
sbit  S0TBIR   = S0TBIC^7;
sbit  S0RIE    = S0RIC^6;
sbit  S0RIR    = S0RIC^7;
sbit  S0EIE    = S0EIC^6;
sbit  S0EIR    = S0EIC^7;

sfr   SSCTIC   = 0xFF72;
sfr   SSCRIC   = 0xFF74;
sfr   SSCEIC   = 0xFF76;
sfr   SSCTB    = 0xF0B0;
sfr   SSCRB    = 0xF0B2;
sfr   SSCBR    = 0xF0B4;
sfr   SSCCON   = 0xFFB2;
sbit  SSCHB    = SSCCON^4;
sbit  SSCPH    = SSCCON^5;
sbit  SSCPO    = SSCCON^6;
sbit  SSCTE    = SSCCON^8;
sbit  SSCTEN   = SSCCON^8;
sbit  SSCRE    = SSCCON^9;
sbit  SSCREN   = SSCCON^9;
sbit  SSCPE    = SSCCON^10;
sbit  SSCPEN   = SSCCON^10;
sbit  SSCBE    = SSCCON^11;
sbit  SSCBEN   = SSCCON^11;
sbit  SSCBSY   = SSCCON^12;
sbit  SSCMS    = SSCCON^14;
sbit  SSCEN    = SSCCON^15;
sbit  SSCTIR   = SSCTIC^7;
sbit  SSCTIE   = SSCTIC^6;
sbit  SSCRIR   = SSCRIC^7;
sbit  SSCRIE   = SSCRIC^6;
sbit  SSCEIR   = SSCEIC^7;
sbit  SSCEIE   = SSCEIC^6;

sfr   T2       = 0xFE40;
sfr   T2CON    = 0xFF40;
sfr   T2IC     = 0xFF60;
sfr   T3       = 0xFE42;
sfr   T3CON    = 0xFF42;
sfr   T3IC     = 0xFF62;
sfr   T4       = 0xFE44;
sfr   T4CON    = 0xFF44;
sfr   T4IC     = 0xFF64;
sfr   WDT      = 0xFEAE;
sfr   WDTCON   = 0xFFAE;
sbit  T2R      = T2CON^6;
sbit  T2UD     = T2CON^7;
sbit  T2UDE    = T2CON^8;
sbit  T2IE     = T2IC^6;
sbit  T2IR     = T2IC^7;
sbit  T3R      = T3CON^6;
sbit  T3UD     = T3CON^7;
sbit  T3UDE    = T3CON^8;
sbit  T3OE     = T3CON^9;
sbit  T3OTL    = T3CON^10;
sbit  T3IE     = T3IC^6;
sbit  T3IR     = T3IC^7;
sbit  T4R      = T4CON^6;
sbit  T4UD     = T4CON^7;
sbit  T4UDE    = T4CON^8;
sbit  T4IE     = T4IC^6;
sbit  T4IR     = T4IC^7;
sbit  T3IN     = P3^6;
sbit  T3EUD    = P3^4;
sbit  T2EUD    = P5^4;
sbit  T4EUD    = P5^5;
sbit  T2IN     = P5^6;
sbit  T4IN     = P5^7;
sbit  WDTIN    = WDTCON^0;
sbit  WDTR     = WDTCON^1;

sfr   CTCON    = 0xFF30;
sfr   CC6MCON  = 0xFF32;
sfr   TRCON    = 0xFF34;
sfr   CC6MIC   = 0xFF36;
sfr   CC60     = 0xFE30;
sfr   CC61     = 0xFE32;
sfr   CC62     = 0xFE34;
sfr   CMP13    = 0xFE36;
sfr   CC6IC    = 0xF17E;
sfr   CC6EIC   = 0xF188;
sfr   T12IC    = 0xF190;
sfr   T13IC    = 0xF198;
sfr   T12P     = 0xF030;
sfr   T13P     = 0xF032;
sfr   T12OF    = 0xF034;
sfr   CC6MSEL  = 0xF036;

sbit  CT12R    = CTCON^3;
sbit  CT12RES  = CTCON^4;
sbit  STE12    = CTCON^5;
sbit  ETRP     = CTCON^6;
sbit  CTM      = CTCON^7;
sbit  CT13R    = CTCON^11;
sbit  CT13RES  = CTCON^12;
sbit  STE13    = CTCON^13;
sbit  ECT13O   = CTCON^14;
sbit  CT13P    = CTCON^15;

sbit  CC0I     = CC6MCON^0;
sbit  COUT0I   = CC6MCON^1;
sbit  CC1I     = CC6MCON^2;
sbit  COUT1I   = CC6MCON^3;
sbit  CC2I     = CC6MCON^4;
sbit  COUT2I   = CC6MCON^5;
sbit  COUTXI   = CC6MCON^6;
sbit  COUT3I   = CC6MCON^7;
sbit  BCEN     = CC6MCON^10;
sbit  BCERR    = CC6MCON^11;
sbit  EBCE     = CC6MCON^12;
sbit  BCEM     = CC6MCON^15;

sbit  TREN0    = TRCON^8;
sbit  TREN1    = TRCON^9;
sbit  TREN2    = TRCON^10;
sbit  TREN3    = TRCON^11;
sbit  TREN4    = TRCON^12;
sbit  TREN5    = TRCON^13;
sbit  TRF      = TRCON^14;
sbit  TRPEN    = TRCON^15;

sbit  CC0REN   = CC6MIC^0;
sbit  CC0FEN   = CC6MIC^1;
sbit  CC1REN   = CC6MIC^2;
sbit  CC1FEN   = CC6MIC^3;
sbit  CC2REN   = CC6MIC^4;
sbit  CC2FEN   = CC6MIC^5;
sbit  ECTC     = CC6MIC^6;
sbit  ECTP     = CC6MIC^7;
sbit  CC0R     = CC6MIC^8;
sbit  CC0F     = CC6MIC^9;
sbit  CC1R     = CC6MIC^10;
sbit  CC1F     = CC6MIC^11;
sbit  CC2R     = CC6MIC^12;
sbit  CC2F     = CC6MIC^13;
sbit  CT12FC   = CC6MIC^14;
sbit  CT12FP   = CC6MIC^15;

sbit  T12IE    = T12IC^6;
sbit  T12IR    = T12IC^7;
sbit  T13IE    = T13IC^6;
sbit  T13IR    = T13IC^7;
sbit  CC6EIE   = CC6EIC^6;
sbit  CC6EIR   = CC6EIC^7;
sbit  CC6IE    = CC6IC^6;
sbit  CC6IR    = CC6IC^7;


sfr   IDPROG   = 0xF078;
sfr   IDMEM    = 0xF07A;
sfr   IDCHIP   = 0xF07C;
sfr   IDMANUF  = 0xF07E;

sfr   T14REL   = 0xF0D0;
sfr   T14      = 0xF0D2;
sfr   RTCL     = 0xF0D4;
sfr   RTCH     = 0xF0D6;

sfr   SYSCON2  = 0xF1D0;
sbit  RCS      = SYSCON2^6;
sbit  SCS      = SYSCON2^7;
sbit  CLKLOCK  = SYSCON2^15;
sfr   SYSCON3  = 0xF1D4;
sbit  ADCDIS   = SYSCON3^0;
sbit  ASC0DIS  = SYSCON3^1;
sbit  SSCDIS   = SYSCON3^2;
sbit  GPT1DIS  = SYSCON3^3;
sbit  DFMDIS   = SYSCON3^4;
sbit  PFMDIS   = SYSCON3^5;
sbit  CC2DIS   = SYSCON3^7;
sbit  CC6DIS   = SYSCON3^8;
sbit  CAN1DIS  = SYSCON3^13;
sbit  PCDDIS   = SYSCON3^15;

sfr   EXISEL   = 0xF1DA;

sfr   ISNC     = 0xF1DE;
sbit  RTCIR    = ISNC^0;
sbit  RTCIE    = ISNC^1;
sbit  PLLIR    = ISNC^2;
sbit  PLLIE    = ISNC^3;

sfr   FOCON    = 0xFFAA;

/* X-Peripherals */
sfr   XP0IC    = 0xF186;
sfr   XP3IC    = 0xF19E;
sbit  XP0IR    = XP0IC^7;
sbit  XP0IE    = XP0IC^6;
sbit  XP3IR    = XP3IC^7;
sbit  XP3IE    = XP3IC^6;

#endif

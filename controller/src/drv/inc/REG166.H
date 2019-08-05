/*--------------------------------------------------------------------------
REG166.H

Register Declarations for C166 Processor
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __REG166_H__
#define __REG166_H__

/* A/D Converter */
sfr   ADCIC    = 0xFF98;
sfr   ADCON    = 0xFFA0;
sfr   ADDAT    = 0xFEA0;
sfr   ADEIC    = 0xFF9A;
sbit  ADST     = ADCON^7;
sbit  ADBSY    = ADCON^8;
sbit  ADCIE    = ADCIC^6;
sbit  ADCIR    = ADCIC^7;
sbit  ADEIE    = ADEIC^6;
sbit  ADEIR    = ADEIC^7;

/* Timer 0, Timer 1 */
sfr   CC0      = 0xFE80;
sfr   CC0IC    = 0xFF78;
sfr   CC1      = 0xFE82;
sfr   CC1IC    = 0xFF7A;
sfr   CC2      = 0xFE84;
sfr   CC2IC    = 0xFF7C;
sfr   CC3      = 0xFE86;
sfr   CC3IC    = 0xFF7E;
sfr   CC4      = 0xFE88;
sfr   CC4IC    = 0xFF80;
sfr   CC5      = 0xFE8A;
sfr   CC5IC    = 0xFF82;
sfr   CC6      = 0xFE8C;
sfr   CC6IC    = 0xFF84;
sfr   CC7      = 0xFE8E;
sfr   CC7IC    = 0xFF86;
sfr   CC8      = 0xFE90;
sfr   CC8IC    = 0xFF88;
sfr   CC9      = 0xFE92;
sfr   CC9IC    = 0xFF8A;
sfr   CC10     = 0xFE94;
sfr   CC10IC   = 0xFF8C;
sfr   CC11     = 0xFE96;
sfr   CC11IC   = 0xFF8E;
sfr   CC12     = 0xFE98;
sfr   CC12IC   = 0xFF90;
sfr   CC13     = 0xFE9A;
sfr   CC13IC   = 0xFF92;
sfr   CC14     = 0xFE9C;
sfr   CC14IC   = 0xFF94;
sfr   CC15     = 0xFE9E;
sfr   CC15IC   = 0xFF96;
sfr   CCM0     = 0xFF52;
sfr   CCM1     = 0xFF54;
sfr   CCM2     = 0xFF56;
sfr   CCM3     = 0xFF58;
sfr   T0       = 0xFE50;
sfr   T01CON   = 0xFF50;
sfr   T0IC     = 0xFF9C;
sfr   T0REL    = 0xFE54;
sfr   T1       = 0xFE52;
sfr   T1IC     = 0xFF9E;
sfr   T1REL    = 0xFE56;
sbit  CC0IR    = CC0IC^7;
sbit  CC0IE    = CC0IC^6;
sbit  CC1IR    = CC1IC^7;
sbit  CC1IE    = CC1IC^6;
sbit  CC2IR    = CC2IC^7;
sbit  CC2IE    = CC2IC^6;
sbit  CC3IR    = CC3IC^7;
sbit  CC3IE    = CC3IC^6;
sbit  CC4IR    = CC4IC^7;
sbit  CC4IE    = CC4IC^6;
sbit  CC5IR    = CC5IC^7;
sbit  CC5IE    = CC5IC^6;
sbit  CC6IR    = CC6IC^7;
sbit  CC6IE    = CC6IC^6;
sbit  CC7IR    = CC7IC^7;
sbit  CC7IE    = CC7IC^6;
sbit  CC8IR    = CC8IC^7;
sbit  CC8IE    = CC8IC^6;
sbit  CC9IR    = CC9IC^7;
sbit  CC9IE    = CC9IC^6;
sbit  CC10IR   = CC10IC^7;
sbit  CC10IE   = CC10IC^6;
sbit  CC11IR   = CC11IC^7;
sbit  CC11IE   = CC11IC^6;
sbit  CC12IR   = CC12IC^7;
sbit  CC12IE   = CC12IC^6;
sbit  CC13IR   = CC13IC^7;
sbit  CC13IE   = CC13IC^6;
sbit  CC14IR   = CC14IC^7;
sbit  CC14IE   = CC14IC^6;
sbit  CC15IR   = CC15IC^7;
sbit  CC15IE   = CC15IC^6;
sbit  ACC0     = CCM0^3;
sbit  ACC1     = CCM0^7;
sbit  ACC2     = CCM0^11;
sbit  ACC3     = CCM0^15;
sbit  ACC4     = CCM1^3;
sbit  ACC5     = CCM1^7;
sbit  ACC6     = CCM1^11;
sbit  ACC7     = CCM1^15;
sbit  ACC8     = CCM2^3;
sbit  ACC9     = CCM2^7;
sbit  ACC10    = CCM2^11;
sbit  ACC11    = CCM2^15;
sbit  ACC12    = CCM3^3;
sbit  ACC13    = CCM3^7;
sbit  ACC14    = CCM3^11;
sbit  ACC15    = CCM3^15;
sbit  T0IE     = T0IC^6;
sbit  T0IR     = T0IC^7;
sbit  T0M      = T01CON^3;
sbit  T0R      = T01CON^6;
sbit  T1IE     = T1IC^6;
sbit  T1IR     = T1IC^7;
sbit  T1M      = T01CON^11;
sbit  T1R      = T01CON^14;

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
sfr   SYSCON   = 0xFF0C;
sfr   TFR      = 0xFFAC;
sfr   ZEROS    = 0xFF1C;
sfr   BUSCON1  = 0xFF14;
sfr   ADDRSEL1 = 0xFE18;
sbit  RWDC     = SYSCON^4;
sbit  MTTC     = SYSCON^5;
sbit  CLKEN    = SYSCON^8;
sbit  BYTDIS   = SYSCON^9;
sbit  BUSACT   = SYSCON^10;
sbit  SGTDIS   = SYSCON^11;
sbit  RDYEN    = SYSCON^12;
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
sbit  RWDC1    = BUSCON1^4;
sbit  MTTC1    = BUSCON1^5;
sbit  ALECTL1  = BUSCON1^9;
sbit  BUSACT1  = BUSCON1^10;
sbit  RDYEN1   = BUSCON1^12;
sbit  ILLBUS   = TFR^0;
sbit  ILLINA   = TFR^1;
sbit  ILLOPA   = TFR^2;
sbit  PRTFLT   = TFR^3;
sbit  UNDOPC   = TFR^7;
sbit  STKUF    = TFR^13;
sbit  STKOF    = TFR^14;
sbit  NMI      = TFR^15;

/* PEC */
sfr   PECC0    = 0xFEC0;
sfr   PECC1    = 0xFEC2;
sfr   PECC2    = 0xFEC4;
sfr   PECC3    = 0xFEC6;
sfr   PECC4    = 0xFEC8;
sfr   PECC5    = 0xFECA;
sfr   PECC6    = 0xFECC;
sfr   PECC7    = 0xFECE;

#define  SRCP0 (*((unsigned int volatile sdata *) 0xFDE0))
#define  DSTP0 (*((unsigned int volatile sdata *) 0xFDE2))
#define  SRCP1 (*((unsigned int volatile sdata *) 0xFDE4))
#define  DSTP1 (*((unsigned int volatile sdata *) 0xFDE6))
#define  SRCP2 (*((unsigned int volatile sdata *) 0xFDE8))
#define  DSTP2 (*((unsigned int volatile sdata *) 0xFDEA))
#define  SRCP3 (*((unsigned int volatile sdata *) 0xFDEC))
#define  DSTP3 (*((unsigned int volatile sdata *) 0xFDEE))
#define  SRCP4 (*((unsigned int volatile sdata *) 0xFDF0))
#define  DSTP4 (*((unsigned int volatile sdata *) 0xFDF2))
#define  SRCP5 (*((unsigned int volatile sdata *) 0xFDF4))
#define  DSTP5 (*((unsigned int volatile sdata *) 0xFDF6))
#define  SRCP6 (*((unsigned int volatile sdata *) 0xFDF8))
#define  DSTP6 (*((unsigned int volatile sdata *) 0xFDFA))
#define  SRCP7 (*((unsigned int volatile sdata *) 0xFDFC))
#define  DSTP7 (*((unsigned int volatile sdata *) 0xFDFE))

/* I/O Ports */
sfr   DP0      = 0xFF02;
sfr   DP1      = 0xFF06;
sfr   DP2      = 0xFFC2;
sfr   DP3      = 0xFFC6;
sfr   DP4      = 0xFF0A;
sfr   P0       = 0xFF00;
sfr   P1       = 0xFF04;
sfr   P2       = 0xFFC0;
sfr   P3       = 0xFFC4;
sfr   P4       = 0xFF08;
sfr   P5       = 0xFFA2;
sbit  A16      = P4^0;
sbit  A17      = P4^1;
sbit  CLKOUT   = P3^15;

/* Serial Interface */
sfr   S0BG     = 0xFEB4;
sfr   S0CON    = 0xFFB0;
sfr   S0EIC    = 0xFF70;
sfr   S0RBUF   = 0xFEB2;
sfr   S0RIC    = 0xFF6E;
sfr   S0TBUF   = 0xFEB0;
sfr   S0TIC    = 0xFF6C;
sfr   S1BG     = 0xFEBC;
sfr   S1CON    = 0xFFB8;
sfr   S1EIC    = 0xFF76;
sfr   S1RBUF   = 0xFEBA;
sfr   S1RIC    = 0xFF74;
sfr   S1TBUF   = 0xFEB8;
sfr   S1TIC    = 0xFF72;
sbit  S0STP    = S0CON^3;
sbit  S0REN    = S0CON^4;
sbit  S0PEN    = S0CON^5;
sbit  S0FEN    = S0CON^6;
sbit  S0OEN    = S0CON^7;
sbit  S0PE     = S0CON^8;
sbit  S0FE     = S0CON^9;
sbit  S0OE     = S0CON^10;
sbit  S0BRS    = S0CON^13;
sbit  S0LB     = S0CON^14;
sbit  S0R      = S0CON^15;
sbit  S0TIE    = S0TIC^6;
sbit  S0TIR    = S0TIC^7;
sbit  S0RIE    = S0RIC^6;
sbit  S0RIR    = S0RIC^7;
sbit  S0EIE    = S0EIC^6;
sbit  S0EIR    = S0EIC^7;
sbit  S1STP    = S1CON^3;
sbit  S1REN    = S1CON^4;
sbit  S1PEN    = S1CON^5;
sbit  S1FEN    = S1CON^6;
sbit  S1OEN    = S1CON^7;
sbit  S1PE     = S1CON^8;
sbit  S1FE     = S1CON^9;
sbit  S1OE     = S1CON^10;
sbit  S1BRS    = S1CON^13;
sbit  S1LB     = S1CON^14;
sbit  S1R      = S1CON^15;
sbit  S1TIE    = S1TIC^6;
sbit  S1TIR    = S1TIC^7;
sbit  S1RIE    = S1RIC^6;
sbit  S1RIR    = S1RIC^7;
sbit  S1EIE    = S1EIC^6;
sbit  S1EIR    = S1EIC^7;

/* GPT1, GPT2 */
sfr   CAPREL   = 0xFE4A;
sfr   CRIC     = 0xFF6A;
sfr   T2       = 0xFE40;
sfr   T2CON    = 0xFF40;
sfr   T2IC     = 0xFF60;
sfr   T3       = 0xFE42;
sfr   T3CON    = 0xFF42;
sfr   T3IC     = 0xFF62;
sfr   T4       = 0xFE44;
sfr   T4CON    = 0xFF44;
sfr   T4IC     = 0xFF64;
sfr   T5       = 0xFE46;
sfr   T5CON    = 0xFF46;
sfr   T5IC     = 0xFF66;
sfr   T6       = 0xFE48;
sfr   T6CON    = 0xFF48;
sfr   T6IC     = 0xFF68;
sfr   WDT      = 0xFEAE;
sfr   WDTCON   = 0xFFAE;
sbit  CRIE     = CRIC^6;
sbit  CRIR     = CRIC^7;
sbit  T2R      = T2CON^6;
sbit  T2UD     = T2CON^7;
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
sbit  T4IE     = T4IC^6;
sbit  T4IR     = T4IC^7;
sbit  T5R      = T5CON^6;
sbit  T5M      = T5CON^3;
sbit  T5UD     = T5CON^7;
sbit  T5CLR    = T5CON^14;
sbit  T5SC     = T5CON^15;
sbit  T5IE     = T5IC^6;
sbit  T5IR     = T5IC^7;
sbit  T6R      = T6CON^6;
sbit  T6UD     = T6CON^7;
sbit  T6OE     = T6CON^9;
sbit  T6OTL    = T6CON^10;
sbit  T6SR     = T6CON^15;
sbit  T6IE     = T6IC^6;
sbit  T6IR     = T6IC^7;
sbit  T0IN     = P3^0;
sbit  T2IN     = P3^7;
sbit  T3IN     = P3^6;
sbit  T4IN     = P3^5;
sbit  T3EUD    = P3^4;
sbit  T3OUT    = P3^3;
sbit  CAPIN    = P3^2;
sbit  T6OUT    = P3^1;
sbit  WDTIN    = WDTCON^0;
sbit  WDTR     = WDTCON^1;

#endif

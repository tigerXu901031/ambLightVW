/*--------------------------------------------------------------------------
REG161U.H

Register Declarations for C161U Processor
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __REG161U_H__
#define __REG161U_H__

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

/* I/O Ports */
sfr   DP0L     = 0xF100;
sfr   DP0H     = 0xF102;
sfr   DP1L     = 0xF104;
sfr   DP1H     = 0xF106;
sfr   DP2      = 0xFFC2;
sfr   DP3      = 0xFFC6;
sfr   DP4      = 0xFFCA;
sfr   DP6      = 0xFFCE;
sfr   P0L      = 0xFF00;
sfr   P0H      = 0xFF02;
sfr   P1L      = 0xFF04;
sfr   P1H      = 0xFF06;
sfr   P2       = 0xFFC0;
sfr   P3       = 0xFFC4;
sfr   P4       = 0xFFC8;
sfr   P5       = 0xFFA2;
sfr   P6       = 0xFFCC;
sfr   ODP2     = 0xF1C2;
sfr   ODP3     = 0xF1C6;
sfr   ODP4     = 0xF1CA;	
sfr   ODP6     = 0xF1CE;
sfr   XP0IC    = 0xF186;
sfr   XP1IC    = 0xF18E;
sfr   XP3IC    = 0xF19E;
sfr   RP0H     = 0xF108;
 sbit  XP0IR    = XP0IC^7;
 sbit  XP0IE    = XP0IC^6;
 sbit  XP1IR    = XP1IC^7;
 sbit  XP1IE    = XP1IC^6;
 sbit  XP3IR    = XP3IC^7;
 sbit  XP3IE    = XP3IC^6;

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
 sbit  SSCP0    = SSCCON^6;
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
 sbit  T5R      = T5CON^6;
 sbit  T5UD     = T5CON^7;
 sbit  T5UDE    = T5CON^8;
 sbit  T5CLR    = T5CON^14;
 sbit  T5SC     = T5CON^15;
 sbit  T5IE     = T5IC^6;
 sbit  T5IR     = T5IC^7;
 sbit  T6R      = T6CON^6;
 sbit  T6UD     = T6CON^7;
 sbit  T6UDE    = T6CON^8;
 sbit  T6OE     = T6CON^9;
 sbit  T6OTL    = T6CON^10;
 sbit  T6SR     = T6CON^15;
 sbit  T6IE     = T6IC^6;
 sbit  T6IR     = T6IC^7;
 sbit  T0IN     = P3^0;
 sbit  T2IN     = P3^7;
 sbit  T3IN     = P3^6;
 sbit  T4IN     = P3^5;
 sbit  T5IN     = P5^13;
 sbit  T6IN     = P5^12;
 sbit  T2EUD    = P5^15;
 sbit  T3EUD    = P3^4;
 sbit  T4EUD    = P5^14;
 sbit  T5EUD    = P5^11;
 sbit  T6EUD    = P5^10;
 sbit  T3OUT    = P3^3;
 sbit  CAPIN    = P3^2;
 sbit  T6OUT    = P3^1;
 sbit  WDTIN    = WDTCON^0;
 sbit  WDTR     = WDTCON^1;

/* External Interrupts */
sfr	ABENDIC	=	0xF18C;
sfr	ABS0CON	=	0xFEF8;
sfr	ABSTAT	=	0xFEFE;
sfr	ABSTIC	=	0xF194;

sfr	CLISNC	=	0xFFA8;

sfr	UCFGVIC	=	0xF16E;
sfr	ULCDIC	=	0xF176;
sfr     URD0IC	=	0xF17A;
sfr     URD1IC	=	0xFF9E;
sfr     URD2IC	=	0xFF9C;
sfr     URD3IC	=	0xFF78;
sfr     URD4IC	=	0xFF7A;
sfr     URD5IC	=	0xFF7C;
sfr     URD6IC	=	0xFF7E;
sfr     URD7IC	=	0xFF80;
sfr	URXRIC	=	0xF16A;
sfr	USETIC	=	0xF178;
sfr	USOFIC	=	0xF170;
sfr	USSIC	=	0xF174;
sfr	USSOIC	=	0xF172;
sfr	UTD0IC	=	0xFF82;
sfr	UTD1IC	=	0xFF84;
sfr	UTD2IC	=	0xFF86;
sfr	UTD3IC	=	0xF160;
sfr	UTD4IC	=	0xF162;
sfr	UTD5IC	=	0xF164;
sfr	UTD6IC	=	0xF166;
sfr	UTD7IC	=	0xF168;
sfr	UTXRIC	=	0xF16C;

sfr	XADRS1  =	0xF014;
sfr	XADRS2  =	0xF016;
sfr	XADRS3	=	0xF018;
sfr	XADRS4	=	0xF01A;
sfr	XADRS5	=	0xF01C;
sfr	XADRR6	=	0xF01E;
sfr     XBCON1	=	0xF114;
sfr     XBCON2	=	0xF116;
sfr     XBCON3	=	0xF118;
sfr     XBCON4	=	0xF11A;
sfr     XBCON5	=	0xF11C;
sfr     XBCON6	=	0xF11E;

sfr	SYSCON1	=	0xF1DC;
sfr	SYSCON2	=	0xF1D0;
sfr	SYSCON3	=	0xF1D4;

sfr	T14	=	0xF0D2;
sfr	T14REL	=	0xF0D0;

sfr	DTIDR	=	0xF0D8;
sfr	EMUCON	=	0xFE0A;
sfr	EPECIC	=	0xF17C;

sfr	EXISEL	=	0xF1DA;
sfr	FEI0IC	=	0xFF88;
sfr	FEI1IC	=	0xFF8A;

sfr	FOCON	=	0xFFAA;
sfr	GPTCLC	=	0xFE4C;
sfr	IDCHIP	=	0xF07C;
sfr	IDMANUF	=	0xF07E;
sfr	IDMEM	=	0xF07A;
sfr	IDMEM2	=	0xF076;
sfr	IDPROG	=	0xF078;
sfr	ISNC	=	0xF1DE;

sfr	ODP0H	=	0xFE22;
sfr	ODP1H	=	0xFE26;
sfr	ODP1L	=	0xFE24;
sfr	P0HPHEN	=	0xFE6A;
sfr	P0HPUDEN=	0xFE66;
sfr	P0HPUDSEL=	0xFE62;
sfr	P0LPHEN	=	0xFE68;
sfr	POLPUDEN=	0xFE64;
sfr	POLPUDSEL=	0xFE60;
sfr	P1HPEN	=	0xFE76;
sfr	P1HPUDEN=	0xFE72;
sfr	P1HPUDSEL=	0xFE6E;
sfr	P1LPHEN=	0xFE74;
sfr	P1LPUDSEL=	0xFE6C;
sfr	P2PHEN	=	0xFE7C;
sfr	P2PUDEN	=	0xFE7A;
sfr	P2PUDSEL=	0xFE78;
sfr	P3PHEN	=	0xFE82;
sfr	P3PUDEN	=	0xFE80;
sfr	P3PUDSEL=	0xFE7E;
sfr	P4PHEN	=	0xFE88;
sfr	P4PUDEN	=	0xFE86;
sfr	P4PUDSEL=	0xFE84;
sfr	P6PHEN	=	0xFE94;
sfr	P6PUDEN	=	0xFE92;
sfr	P6PUDSEL=	0xFE90;
sfr	PECCLIC	=	0xF180;
sfr	PECSN0	=	0xFED0;
sfr	PECSN1	=	0xFED2;
sfr	PECSN2	=	0xFED4;
sfr	PECSN3	=	0xFED6;
sfr	PECSN4	=	0xFED8;
sfr	PECSN5	=	0xFEDA;
sfr	PECSN6	=	0xFEDC;
sfr	PECSN7	=	0xFEDE;
sfr	PECXC0	=	0xFEF0;
sfr	PECXC1	=	0xFEF2;
sfr	XPERCON	=	0xF024;
sfr	RES1IC	=	0xF184;
sfr	RES4IC	=	0xFF98;
sfr	RES6IC	=	0xF19A;
sfr	RTCCLC	=	0xF0C8;
sfr	RTCCON	=	0xF1CC;
sfr	RTCH	=	0xF0D6;
sfr	RTCISNC	=	0xF1C8;
sfr	RTCL	=	0xF0D4;
sfr	RTCRELH	=	0xF0CE;
sfr	RTCRELL	=	0xF0CC;

sfr     S0CLC	=	0xFFBA;
sfr	S0FDV	=	0xFEB6;
sfr	S0PMW	=	0xFEAA;

sfr	SCUSLC	=	0xF0C0;
sfr	SCUSLS	=	0xF0C2;

sfr	SSCCLC  =	0xF0B6;

#endif

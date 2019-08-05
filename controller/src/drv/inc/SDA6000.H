/*--------------------------------------------------------------------------
SDA6000.H

Register Declarations for Infineon SDA6000 STEP A12 controllers
based on the MIRA SDA600_A12 SFR definitions REV 1999-06-25
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __SDA6000_H__
#define __SDA6000_H__


//////////////////////////////////////////////
// SSC Register - Synchronous serial channel

sfr	SSCCON	= 0xFFB2;
	sbit	SSCHB	 = SSCCON^4;		//SSC0BC
	sbit	SSCPH	 = SSCCON^5;
	sbit	SSCPO	 = SSCCON^6;
	sbit	SSC0LB	 = SSCCON^7;
	sbit	SSC0TEN	 = SSCCON^8;		//SSC0TE
	sbit	SSC0REN	 = SSCCON^9;		//SSC0RE
	sbit	SSC0PEN	 = SSCCON^10;		//SSC0PE
	sbit	SSC0BEN	 = SSCCON^11;		//SSC0BE
	sbit	SSC0AREN = SSCCON^12;		//SSC0BSY
	sbit	SSC0MS	 = SSCCON^14;		//SSC0MS
	sbit	SSC0EN	 = SSCCON^15;		//SSC0EN

sfr	SSCBR	= 0xF0B4;
sfr	SSCTB	= 0xF0B0;
sfr	SSCRB	= 0xF0B2;

//////////////////////////////////////////////
// ASC Regiter - Asynchronus serial channel

sfr	S0CON	= 0xFFB0;
	sbit	S0STP	= S0CON^3;
	sbit	S0REN	= S0CON^4;
	sbit	S0PEN	= S0CON^5;
	sbit	S0FEN	= S0CON^6;
	sbit	S0OEN	= S0CON^7;
	sbit	S0PE	= S0CON^8;
	sbit	S0FE	= S0CON^9;
	sbit	S0OE	= S0CON^10;
	sbit	S0FDE	= S0CON^11;
	sbit	S0ODD	= S0CON^12;
	sbit	S0BRS	= S0CON^13;
	sbit	S0LB	= S0CON^14;
	sbit	S0R		= S0CON^15;

sfr	S0BG	= 0xFEB4;
sfr	S0FDV	= 0xFEB6;
sfr	S0PWM	= 0xFEAA;
	sbit	S0IRPW	= S0PWM^8;

sfr	S0TBUF	= 0xFEB0;
sfr	S0RBUF	= 0xFEB2;

//////////////////////////////////////////////
// IIC Register

#define  ICCFG    (*((unsigned int volatile sdata *) 0xE810))
#define  ICCFG	  (*((unsigned int volatile sdata *) 0xE810))
#define  ICCON	  (*((unsigned int volatile sdata *) 0xE812))
#define  ICST	  (*((unsigned int volatile sdata *) 0xE814))
#define  ICADR	  (*((unsigned int volatile sdata *) 0xE816))
#define  ICRTBL	  (*((unsigned int volatile sdata *) 0xE818))
#define  ICRTBH	  (*((unsigned int volatile sdata *) 0xE81A))
#define  IICPISEL (*((unsigned int volatile sdata *) 0xE804))


//////////////////////////////////////////////
// WDT Regsiter - Watchdog Timer

sfr	WDTCON	= 0xFFAE;
	sbit	WDTIN	= WDTCON^0;
	sbit	WDTR	= WDTCON^1;
	sbit	SWR		= WDTCON^2;
	sbit	SHWR	= WDTCON^3;
	sbit	LHWR	= WDTCON^4;

sfr	WDT		= 0xFEAE;

//////////////////////////////////////////////
// RCR Register - Realtime Clock Register

sfr	RTCCON	= 0xF1CC;
	sbit	RTCT	= RTCCON^0;
	sbit	T14DEC	= RTCCON^2;
	sbit	T14INC	= RTCCON^3;

sfr	T14		= 0xF0D2;
sfr	T14REL	= 0xF0D0;
sfr	RTCL	= 0xF0D4;
sfr	RTCH	= 0xF0D6;
sfr	RTCRELL	= 0xF0CC;
sfr	RTCRELH	= 0xF0CE;
sfr	RTCISNC	= 0xF1C8;
	sbit	T14IE 	= RTCISNC^0;
	sbit	T14IR 	= RTCISNC^1;
	sbit  	RTC0IE	= RTCISNC^2;
	sbit	RTC0IR	= RTCISNC^3;
	sbit	RTC1IE	= RTCISNC^4;
	sbit	RTC1IR	= RTCISNC^5;
	sbit	RTC2IE	= RTCISNC^6;
	sbit	RTC2IR	= RTCISNC^7;
	sbit	RTC3IE	= RTCISNC^8;
	sbit	RTC3IR	= RTCISNC^9;

sfr	ISNC	= 0xF1DE;
	sbit	RTCINTIR	= ISNC^0;
	sbit	RTCINTIE	= ISNC^1;
	sbit	INT2IR  	= ISNC^2;
	sbit	INT2IE  	= ISNC^3;

//////////////////////////////////////////////
// GPT General Purpose Register

sfr	T2CON	= 0xFF40;
	sbit	T2R		= T2CON^6;
	sbit	T2UD	= T2CON^7;
	sbit	T2UDE	= T2CON^8;

sfr	T3CON	= 0xFF42;
	sbit	T3R  	= T3CON^6;
	sbit	T3UD 	= T3CON^7;
	sbit	T3UDE	= T3CON^8;
	sbit	T3OE 	= T3CON^9;
	sbit	T3OTL	= T3CON^10;
	sbit	FMI  	= T3CON^11;

sfr	T4CON	= 0xFF44;
	sbit	T4R  	= T4CON^6;
	sbit	T4UD   	= T4CON^7;
	sbit	T4UDE	= T4CON^8;

sfr	T5CON	= 0xFF46;
	sbit    T5R   	= T5CON^6;
	sbit    T5UD  	= T5CON^7;
	sbit    T5UDE 	= T5CON^8;
	sbit    CT3   	= T5CON^10;
	sbit    T5CLR 	= T5CON^14;
	sbit    T5SC  	= T5CON^15;

sfr	T6CON	= 0xFF48;
	sbit	T6R		= T6CON^6;
	sbit	T6UD	= T6CON^7;
	sbit	T6OTL	= T6CON^10;
	sbit	T6SR	= T6CON^15;

sfr	T2		= 0xFE40;
sfr	T3		= 0xFE42;
sfr	T4		= 0xFE44;
sfr	T5		= 0xFE46;
sfr	T6		= 0xFE48;
sfr	CAPREL	= 0xFE4A;

//////////////////////////////////////////////
// ADC Register - A/D converter

sfr	ADDAT1	= 0xFEA0;
sfr	ADDAT2	= 0xFEA2;
sfr	ADCCON	= 0xFEA4;
		sbit	ADWULE = ADCCON^4;


//////////////////////////////////////////////
//	ICR Register

sfr	T2IC	= 0xFF60;
	sbit	T2IE	= T2IC^6;
	sbit	T2IR	= T2IC^7;
sfr	T3IC    = 0xFF62;
	sbit	T3IE	= T3IC^6;
	sbit	T3IR	= T3IC^7;
sfr	T4IC    = 0xFF64;
	sbit	T4IE	= T4IC^6;
	sbit	T4IR	= T4IC^7;
sfr	T5IC    = 0xFF66;
	sbit	T5IE	= T5IC^6;
	sbit	T5IR	= T5IC^7;
sfr	T6IC    = 0xFF68;
	sbit	T6IE	= T6IC^6;
	sbit	T6IR	= T6IC^7;
sfr	CRIC   	= 0xFF6A;
	sbit	CRIE	= CRIC^6;
	sbit	CRIR	= CRIC^7;
sfr	EX0IC	= 0xFF88;               // changed names cc0ic-cc7ic in ex0ic-ex7ic
	sbit	EX0IE	= EX0IC^6;
	sbit	EX0IR	= EX0IC^7;
sfr	EX1IC	= 0xFF8A;
	sbit	EX1IE	= EX1IC^6;
	sbit	EX1IR	= EX1IC^7;
sfr	EX2IC	= 0xFF8C;
	sbit	EX2IE	= EX2IC^6;
	sbit	EX2IR	= EX2IC^7;
sfr	EX3IC	= 0xFF8E;
	sbit	EX3IE	= EX3IC^6;
	sbit	EX3IR	= EX3IC^7;
sfr	EX4IC	= 0xFF90;
	sbit	EX4IE 	= EX4IC^6;
	sbit	EX4IR	= EX4IC^7;
sfr	EX5IC	= 0xFF92;
	sbit	EX5IE	= EX5IC^6;
	sbit	EX5IR	= EX5IC^7;
sfr	EX6IC	= 0xFF94;
	sbit	EX6IE	= EX6IC^6;
	sbit	EX6IR 	= EX6IC^7;
sfr	EX7IC	= 0xFF96;
	sbit	EX7IE	= EX7IC^6;
	sbit	EX7IR	= EX7IC^7;
sfr	ADC1IC	= 0xFF98;
	sbit	ADC1IE	= ADC1IC^6;
	sbit	ADC1IR	= ADC1IC^7;
sfr	ADC2IC	= 0xFF9A;
	sbit	ADC2IE	= ADC2IC^6;
	sbit	ADC2IR	= ADC2IC^7;
sfr	ADWIC	= 0xF178;
	sbit	ADWICIE	= ADWIC^6;
	sbit	ADWICIR	= ADWIC^7;
sfr	SSCEIC	= 0xFF76;
	sbit	SSCEIE	= SSCEIC^6;
	sbit	SSCEIR	= SSCEIC^7;
sfr	SSCRIC	= 0xFF74;
	sbit	SSCRIE	= SSCRIC^6;
	sbit	SSCRIR	= SSCRIC^7;
sfr	SSCTIC	= 0xFF72;
	sbit	SSCTIE	= SSCTIC^6;
	sbit	SSCTIR	= SSCTIC^7;
sfr	S0EIC	= 0xFF70;
	sbit	S0EIE	= S0EIC^6;
	sbit	S0EIR	= S0EIC^7;
sfr	S0RIC	= 0xFF6E;
	sbit	S0RIE	= S0RIC^6;
	sbit	S0RIR	= S0RIC^7;
sfr	S0TIC	= 0xFF6C;
	sbit	S0TIE	= S0TIC^6;
	sbit	S0TIR	= S0TIC^7;
sfr	S0TBIC	= 0xF19C;
	sbit	S0TBICIE  = S0TBIC^6;
	sbit	S0TBICIR  = S0TBIC^7;
sfr	I2CTIC	= 0xF194;
	sbit	I2CTICIE  = I2CTIC^6;
	sbit	I2CTICIR  = I2CTIC^7;
sfr	I2CPIC	= 0xF18C;
	sbit	I2CPICIE  = I2CPIC^6;
	sbit	I2CPICIR  = I2CPIC^7;
sfr	I2CTEIC	= 0xF184;
	sbit	I2CTEICIE = I2CTEIC^6;
	sbit	I2CTEICIR = I2CTEIC^7;
sfr	ACQIC	= 0xF176;
	sbit	ACQICIE	  = ACQIC^6;
	sbit	ACQICIR	  = ACQIC^7;
sfr	VSDISIC	= 0xF174;
	sbit	VSDISICIE = VSDISIC^6;
	sbit	VSDISICIR = VSDISIC^7;
sfr	HSDISIC	= 0xF172;
	sbit	HSDISICIE = HSDISIC^6;
	sbit	HSDISICIR = HSDISIC^7;
sfr	GAFIC	= 0xFF9C;
	sbit	GAFICIE	  = GAFIC^6;
	sbit	GAFICIR	  = GAFIC^7;
sfr	RTCIC	= 0xF19E;
	sbit	RTCICIE	  = RTCIC^6;
	sbit	RTCICIR	  = RTCIC^7;
sfr	PECCLIC	= 0xF180;
	sbit	PECCLICIE = PECCLIC^6;
	sbit	PECCLICIR = PECCLIC^7;

//////////////////////////////////////////////
// PEC Peripheral Event Control

sfr	PECC0	= 0xFEC0;
sfr	PECC1	= 0xFEC2;
sfr	PECC2	= 0xFEC4;
sfr	PECC3	= 0xFEC6;
sfr	PECC4	= 0xFEC8;
sfr	PECC5	= 0xFECA;
sfr	PECC6	= 0xFECC;
sfr	PECC7	= 0xFECE;
sfr	PECSN0	= 0xFED0;
sfr	PECSN1	= 0xFED2;
sfr	PECSN2	= 0xFED4;
sfr	PECSN3	= 0xFED6;
sfr	PECSN4	= 0xFED8;
sfr	PECSN5	= 0xFEDA;
sfr	PECSN6	= 0xFEDC;
sfr	PECSN7	= 0xFEDE;

#define  SRCP0 (*((unsigned int volatile sdata *) 0xFCE0)) // PEC Channel 0 Control Register
#define  DSTP0 (*((unsigned int volatile sdata *) 0xFCE2)) // PEC Channel 0 Control Register
#define  SRCP1 (*((unsigned int volatile sdata *) 0xFCE4)) // PEC Channel 0 Control Register
#define  DSTP1 (*((unsigned int volatile sdata *) 0xFCE6)) // PEC Channel 0 Control Register
#define  SRCP2 (*((unsigned int volatile sdata *) 0xFCE8)) // PEC Channel 0 Control Register
#define  DSTP2 (*((unsigned int volatile sdata *) 0xFCEA)) // PEC Channel 0 Control Register
#define  SRCP3 (*((unsigned int volatile sdata *) 0xFCEC)) // PEC Channel 0 Control Register
#define  DSTP3 (*((unsigned int volatile sdata *) 0xFCEE)) // PEC Channel 0 Control Register
#define  SRCP4 (*((unsigned int volatile sdata *) 0xFCF0)) // PEC Channel 0 Control Register
#define  DSTP4 (*((unsigned int volatile sdata *) 0xFCF2)) // PEC Channel 0 Control Register
#define  SRCP5 (*((unsigned int volatile sdata *) 0xFCF4)) // PEC Channel 0 Control Register
#define  DSTP5 (*((unsigned int volatile sdata *) 0xFCF6)) // PEC Channel 0 Control Register
#define  SRCP6 (*((unsigned int volatile sdata *) 0xFCF8)) // PEC Channel 0 Control Register
#define  DSTP6 (*((unsigned int volatile sdata *) 0xFCFA)) // PEC Channel 0 Control Register
#define  SRCP7 (*((unsigned int volatile sdata *) 0xFCFC)) // PEC Channel 0 Control Register
#define  DSTP7 (*((unsigned int volatile sdata *) 0xFCFE)) // PEC Channel 0 Control Register


//////////////////////////////////////////////
//	Port Registers

sfr	RP0H	= 0xF108;
sfr	P2		= 0xFFC0;
	sbit	EX0IN	= P2^8;
	sbit	EX1IN	= P2^9;
	sbit	EX2IN	= P2^10;
	sbit	EX3IN	= P2^11;
	sbit	EX4IN	= P2^12;
	sbit	EX5IN	= P2^13;
	sbit	EX6IN	= P2^14;
	sbit	EX7IN	= P2^15;

sfr	P3	= 0xFFC4;
	sbit	SCL0	= P3^0;
	sbit	SDA0	= P3^1;
	sbit	PCAPIN	= P3^2;
	sbit	T3OUT	= P3^3;
	sbit	T3EUD	= P3^4;
	sbit	T4IN	= P3^5;
	sbit	T3IN	= P3^6;
	sbit	T2IN	= P3^7;
	sbit	MRST	= P3^8;
	sbit	MTSR	= P3^9;
	sbit	TxD0	= P3^10;
	sbit	RxD0	= P3^11;
	sbit	P3_12	= P3^12;
	sbit	SCLK	= P3^13;
	sbit	P3_15	= P3^15;

sfr	P4	= 0xFFC8;
	sbit	P4_0	= P4^0; //A16
	sbit	P4_1	= P4^1; //A17
	sbit	P4_2	= P4^2; //A18
	sbit	P4_3	= P4^3; //A19
	sbit	P4_4	= P4^4; //A20
	sbit	P4_5	= P4^5; //CS3

sfr	P5	= 0xFFA2;
	sbit	P5_0	= P5^0;	// AN.0
	sbit	P5_1	= P5^1;	// AN.1
	sbit	P5_2	= P5^2;	// AN.2
	sbit	P5_3	= P5^3;	// AN.3
	sbit	P5_4	= P5^4;
	sbit	P5_5	= P5^5;
	sbit	P5_6	= P5^6;
	sbit	P5_7	= P5^7;
	sbit	P5_8	= P5^8;
	sbit	P5_9	= P5^9;
   	sbit	P5_10	= P5^10;
	sbit	P5_11	= P5^11;
	sbit	P5_12	= P5^12;
	sbit	P5_13	= P5^13;
	sbit	T4EUD	= P5^14;
	sbit	T2EUD	= P5^15;

sfr	P6      = 0xFFCC;
	sbit	TRIG_IN	 = P6^0;
	sbit	TRIG_OUT = P6^1;
	sbit	P6_2	 = P6^2;
	sbit	SCL1	 = P6^3;
	sbit	SDA1	 = P6^4;
	sbit	P6_5	 = P6^5;
	sbit	SDA2	 = P6^6;

sfr	DP2       = 0xFFC2;
sfr DP3       = 0xFFC6;
sfr	DP6       = 0xFFCE;
sfr	ODP3      = 0xF1C6;
sfr	ODP6      = 0xF1CE;
sfr	P5BEN     = 0xF1C2;
sfr	ALTSEL0P6 = 0xF12C;

//////////////////////////////////////////////
//	SpCR Specific Control Registes

sfr	STRVBI	= 0xF1A0;
	sbit	ACQON	= STRVBI^15;
sfr	ACQISN	= 0xF1A2;
	sbit	VS1_IR	= ACQISN^0;
	sbit	VS1_IE	= ACQISN^1;
	sbit	HS1_IR	= ACQISN^2;
	sbit	HS1_IE	= ACQISN^3;
	sbit	VS2_IR	= ACQISN^4;
	sbit	VS2_IE	= ACQISN^5;
	sbit	HS2_IR	= ACQISN^6;
	sbit	HS2_IE	= ACQISN^7;
	sbit	L23_IR	= ACQISN^8;
	sbit	L23_IE	= ACQISN^9;
	sbit	CC_IR	= ACQISN^10;
	sbit	CC_IE	= ACQISN^11;
sfr	GPRGCRL	= 0xF1A4;
sfr	GPRGCRH	= 0xF1A6;
sfr	DGCON	= 0xFEFA;
	sbit	EADG	= DGCON^0;
	sbit	EODG	= DGCON^1;
	sbit	STGA	= DGCON^2;
sfr	SCR		= 0xF1A8;
	sbit	MAST  	= SCR^0;
	sbit	VCS   	= SCR^1;
	sbit	INT   	= SCR^2;
	sbit	VP    	= SCR^3;
	sbit	HP    	= SCR^4;
	sbit	CORP  	= SCR^5;
	sbit	BLANKP	= SCR^6;
	sbit	CORBL 	= SCR^11;
sfr	VLR     = 0xF1AA;
sfr	BVCR    = 0xFEF6;
sfr	EVCR    = 0xFEF8;
sfr	HPR     = 0xF1AC;
sfr	SDV     = 0xF1AE;
sfr	SDH     = 0xF1B0;
sfr	HCR     = 0xF1B2;
sfr	PFR     = 0xF1B6;
sfr	DACCON	= 0xF1B4;
	sbit	BWC	= DACCON^2;

//////////////////////////////////////////////
//	EBI External Bus

sfr	REDIR	= 0xF1BA;
sfr	REDIR1	= 0xF1CA;
sfr	EBICON	= 0xF1BC;
	sbit	EDMR  	= EBICON^0;
	sbit	EDMA  	= EBICON^1;
	sbit	SDRSZE	= EBICON^2;
	sbit	REFEN 	= EBICON^3;

sfr	EBIDIR	= 0xF1BE;
	sbit	ADR_10  = EBIDIR^0;
	sbit	WR_N    = EBIDIR^1;
	sbit	CAS_N   = EBIDIR^2;
	sbit	RAS_N   = EBICON^3;
	sbit	CS_N    = EBICON^4;
	sbit	CLKEN   = EBICON^5;


//////////////////////////////////////////////
//  OCDS Regsiters - On Chip Debbuging System

sfr	COMDATA	= 0xF068;
sfr	RWDATA	= 0xF06A;
sfr	IOSR	= 0xF06C;
sfr	DCMPLL	= 0xF0DC;
sfr	DCMPLH	= 0xF0DE;
sfr	DCMPGL	= 0xF0E0;
sfr	DCMPGH	= 0xF0E2;
sfr	DCMP0L	= 0xF0E4;
sfr	DCMP0H	= 0xF0E6;
sfr	DCMP1L	= 0xF0E8;
sfr	DCMP1H	= 0xF0EA;
sfr	DCMP2L	= 0xF0EC;
sfr	DCMP2H	= 0xF0EE;
sfr	DTREVT	= 0xF0F0;
sfr	DSWEVT	= 0xF0F4;
sfr	DEXEVT	= 0xF0F8;
sfr	DBGSR	= 0xF0FC;


//////////////////////////////////////////////
// SCR System & CPU Regsiters

sfr	TFR	= 0xFFAC;
	sbit	ILLBUS = TFR^0;
	sbit	ILLINA = TFR^1;
	sbit	ILLOPA = TFR^2;
	sbit	PRTFLT = TFR^3;
	sbit	UNDOPC = TFR^7;
	sbit	STKUF  = TFR^13;
	sbit	STKOF  = TFR^14;
	sbit	NMI    = TFR^15;

sfr	ADDRSEL4 = 0xFE1E;
sfr	BUSCON4	 = 0xFF1A;
	sbit	RWDC4    = BUSCON4^4;
	sbit	MTTC4    = BUSCON4^5;
	sbit	ALECTL4  = BUSCON4^9;
	sbit	BUSACT4  = BUSCON4^10;
	sbit	RDYEN4   = BUSCON4^12;
	sbit	CSREN4	 = BUSCON4^14;
	sbit	CSWEN4   = BUSCON4^15;

sfr	ADDRSEL3 = 0xFE1C;
sfr	BUSCON3	 = 0xFF18;
	sbit	RWDC3    = BUSCON3^4;
	sbit	MTTC3    = BUSCON3^5;
	sbit	ALECTL3  = BUSCON3^9;
	sbit	BUSACT3  = BUSCON3^10;
	sbit	RDYEN3   = BUSCON3^12;
	sbit	CSREN3	 = BUSCON3^14;
	sbit	CSWEN3   = BUSCON3^15;

sfr	ADDRSEL2 = 0xFE1A;
sfr	BUSCON2	 = 0xFF16;
	sbit	RWDC2    = BUSCON2^4;
	sbit	MTTC2    = BUSCON2^5;
	sbit	ALECTL2  = BUSCON2^9;
	sbit	BUSACT2  = BUSCON2^10;
	sbit	RDYEN2   = BUSCON2^12;
	sbit	CSREN2	 = BUSCON2^14;
	sbit	CSWEN2   = BUSCON2^15;

sfr	ADDRSEL1 = 0xFE18;
sfr	BUSCON1	 = 0xFF14;
	sbit	RWDC1    = BUSCON1^4;
	sbit	MTTC1    = BUSCON1^5;
	sbit	ALECTL1  = BUSCON1^9;
	sbit	BUSACT1  = BUSCON1^10;
	sbit	RDYEN1   = BUSCON1^12;
	sbit	CSREN1	 = BUSCON1^14;
	sbit	CSWEN1   = BUSCON1^15;

sfr	BUSCON0	= 0xFF0C;
	sbit	RWDC0    = BUSCON0^4;
	sbit	MTTC0    = BUSCON0^5;
	sbit	ALECTL0  = BUSCON0^9;
	sbit	BUSACT0  = BUSCON0^10;
	sbit	RDYEN0   = BUSCON0^12;
	sbit	CSREN0	 = BUSCON0^14;
	sbit	CSWEN0   = BUSCON0^15;

sfr SYSCON2	= 0xF1D0;
	sbit	SYSCON2_6 = SYSCON2^6;
	sbit	SYSCON2_7 = SYSCON2^7;
	sbit	CLLOCK	  = SYSCON2^15;
sfr	SYSCON1	= 0xF1DC;
sfr	SYSCON	= 0xFF12;
	sbit	XPEN   	= SYSCON^2;
	sbit	BDRSTEN	= SYSCON^3;
	sbit	ROMEN  	= SYSCON^10;
	sbit	SGTDIS	= SYSCON^11;
	sbit	ROMS1	= SYSCON^12;

sfr	XADRS6	= 0xF01E;
sfr	XADRS5	= 0xF01C;
sfr	XADRS4	= 0xF01A;
sfr	XADRS3	= 0xF018;
sfr	XADRS2	= 0xF016;
sfr	XADRS1	= 0xF014;
sfr	XBCON6	= 0xF11E;
sfr	XBCON5	= 0xF11C;
sfr	XBCON4	= 0xF11A;
sfr	XBCON3	= 0xF118;
sfr	XBCON2	= 0xF116;
sfr	XBCON1	= 0xF114;

sfr	DPP3	= 0xFE06;
sfr	DPP2	= 0xFE04;
sfr	DPP1	= 0xFE02;
sfr	DPP0	= 0xFE00;
sfr	MDH     = 0xFE0C;
sfr	MDL     = 0xFE0E;
sfr	MDC     = 0xFF0E;
	sbit	MDRIU	= MDC^4;

sfr PSW		= 0xFF10;
	sbit  	N       = PSW^0;
	sbit  	C       = PSW^1;
	sbit  	V       = PSW^2;
	sbit  	Z       = PSW^3;
	sbit  	E       = PSW^4;
	sbit  	MULIP   = PSW^5;
	sbit  	USR0    = PSW^6;
	sbit  	HLDEN   = PSW^10;
	sbit  	IEN     = PSW^11;

sfr	CLISNC	= 0xFFA8;
	sbit	C0IE	  = CLISNC^0;
	sbit	C0IR	  = CLISNC^1;
	sbit   	CLISNC_2  = CLISNC^2;
	sbit   	CLISNC_3  = CLISNC^3;
	sbit	C2IE	  = CLISNC^4;
	sbit	C2IR	  = CLISNC^5;
	sbit	CLISNC_6  = CLISNC^6;
	sbit	CLISNC_7  = CLISNC^7;
	sbit	C4IE	  = CLISNC^8;
	sbit	C4IR	  = CLISNC^9;
	sbit	CLISNC_10 = CLISNC^10;
	sbit	CLISNC_11 = CLISNC^11;
	sbit	C6IE	  = CLISNC^12;
	sbit	C6IR	  = CLISNC^13;
	sbit	CLISNC_14 = CLISNC^14;
	sbit	CLISNC_15 = CLISNC^15;

sfr	STKUN   = 0xFE16;
sfr	STKOV   = 0xFE14;
sfr	SP      = 0xFE12;
sfr	CP      = 0xFE10;
sfr	CSP	    = 0xFE08;
sfr	SCUSLC  = 0xF0C0;
sfr	SCUSLS  = 0xF0C2;
sfr	ZEROS   = 0xFF1C;
sfr	ONES    = 0xFF1E;
sfr	XPERCON = 0xF024;
sfr	EXISEL  = 0xF1DA;
sfr	EXICON	= 0xF1C0;
sfr	OSCCON	= 0xF1C4;
sfr	IDMANUF	= 0xF07E;
sfr	IDCHIP	= 0xF07C;
sfr	TM_HI	= 0xFEFE;
sfr	TM_LO	= 0xFEFC;

#endif

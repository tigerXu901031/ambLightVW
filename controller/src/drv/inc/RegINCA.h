/******************************************************************************/
/*                                                                            */
/*              I n f i n e o n   T e c h n o l o g i e s   A G               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  Device:             INCA                      File: RegINCA.h             */
/*                                                                            */
/*  Version:            1.12                      2001-11-05                  */
/*  Written by:         Christian Bodensteiner                                */
/*  Department:         COM A1 AE                                             */
/*                                                                            */
/*  Compiler:           Keil                                                  */
/*                                                                            */
/*  Description:        This file containes the declarations of               */
/*                      INCA special function registers                       */
/*                                                                            */
/******************************************************************************/
/*  Modification:                Version:   Date:           Author:           */
/*  INCA_ removed                1.01       2000-12-06      Arno Rabenstein   */
/*    FEX2INT included                                                        */
/*  USB Interrupt Enable         1.02       2000-12-12      Bodensteiner Chr. */
/*    Bits & Request Flags                                                    */
/*  IOM_CR added                 1.03       2000-12-27      Arno Rabenstein   */
/*  GPIO Pull up/down            1.04       2001-02-07      Arno Rabenstein   */
/*    registers added                                                         */
/*  PITRDU and PITRDD added      1.05       2001-02-13      Arno Rabenstein   */
/*  Port3 Functions              1.06       2001-05-06      Bodensteiner Chr. */	
/*  XBUS SFRs                    1.07       2001-07-11      Bodensteiner Chr. */ 	
/*  External Interrupts          1.08       2001-07-12      Bodensteiner Chr. */ 	
/*  IGSRn                        1.09       2001-07-19      Bodensteiner Chr. */ 
/*  I2C Register                 1.10       2001-07-25      Schmid            */
/*  I2C Register                 1.11       2001-10-23      Bodensteiner Chr. */
/*  Update External INTs         1.12       2001-11-05      Bodensteiner Chr. */
/******************************************************************************/

#ifndef __RegINCA_h__
#define __RegINCA_h__

#define  INCA_USB_BASE_ADDR   0xDD00
#define  INCA_IOM_BASE_ADDR   0xDE00

#define  INCA_IOM_TRANSFER_UNIT_OFFSET 0x90

//#define  UCHAR unsigned char

//------------------------------------------------------------------------------
//  Register Declarations for Controller
//------------------------------------------------------------------------------

//-- CPU -----------------------------------------------------------------------
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
sfr   XBCON3   = 0xF118;
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
#define  REXICON (*((unsigned int volatile sdata *) 0xDF38))

//-- PEC -----------------------------------------------------------------------
sfr   PECC0    = 0xFEC0;
sfr   PECC1    = 0xFEC2;
sfr   PECC2    = 0xFEC4;
sfr   PECC3    = 0xFEC6;
sfr   PECC4    = 0xFEC8;
sfr   PECC5    = 0xFECA;
sfr   PECC6    = 0xFECC;
sfr   PECC7    = 0xFECE;

//-- Extended-PEC -----------------------------------------------------------------------
sfr   PECxC0    = 0xFEF0;
sfr   PECxC1    = 0xFEF2;

sfr   PECSN0    = 0xFED0;
sfr   PECSN1    = 0xFED2;
sfr   PECSN2    = 0xFED4;
sfr   PECSN3    = 0xFED6;
sfr   PECSN4    = 0xFED8;
sfr   PECSN5    = 0xFEDA;
sfr   PECSN6    = 0xFEDC;
sfr   PECSN7    = 0xFEDE;

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

//-- I/O Ports -----------------------------------------------------------------
sfr   DP0L     = 0xF100;
sfr   DP0H     = 0xF102;
sfr   DP1L     = 0xF104;
sfr   DP1H     = 0xF106;
sfr   DP2      = 0xFFC2;
sfr   DP3      = 0xFFC6;
sfr   DP4      = 0xFFCA;
sfr   DP6      = 0xFFCE;
sfr   DP7      = 0xFFD2;
sfr   P0L      = 0xFF00;
sfr   P0H      = 0xFF02;
sfr   P1L      = 0xFF04;
sfr   P1H      = 0xFF06;
sfr   P2       = 0xFFC0;
sfr   P3       = 0xFFC4;
sfr   P4       = 0xFFC8;
sfr   P5       = 0xFFA2;
sfr   P6       = 0xFFCC;
sfr   P7       = 0xFFD0;

sfr   ODP2     = 0xF1C2;
sfr   ODP3     = 0xF1C6;
sfr   ODP6     = 0xF1CE;
sfr   ODP7     = 0xf1d2;

sfr   XP0IC    = 0xF186;
sfr   XP1IC    = 0xF18E;
sfr   XP2IC    = 0xF196;
sfr   XP3IC    = 0xF19E;
sfr   RP0H     = 0xF108;
sbit  XP0IR    = XP0IC^7;
sbit  XP0IE    = XP0IC^6;
sbit  XP1IR    = XP1IC^7;
sbit  XP1IE    = XP1IC^6;
sbit  XP2IR    = XP2IC^7;
sbit  XP2IE    = XP2IC^6;
sbit  XP3IR    = XP3IC^7;
sbit  XP3IE    = XP3IC^6;

sbit  P2_0 = P2^0;
sbit  P2_1 = P2^1;
sbit  P2_2 = P2^2;
sbit  P2_3 = P2^3;
sbit  P2_4 = P2^4;
sbit  P2_5 = P2^5;
sbit  P2_6 = P2^6;
sbit  P2_7 = P2^7;

sbit  P7_0 = P7^0;
sbit  P7_1 = P7^1;
sbit  P7_2 = P7^2;
sbit  P7_3 = P7^3;
sbit  P7_4 = P7^4;
sbit  P7_5 = P7^5;
sbit  P7_6 = P7^6;
sbit  P7_7 = P7^7;

sfr P2ALTSEL0  = 0xF122;
sfr P2ALTSEL1  = 0xF124;
sfr P3ALTSEL0  = 0xF126;
sfr P3ALTSEL1  = 0xF128;
sfr P6ALTSEL0  = 0xF12C;
sfr P7ALTSEL0  = 0xF12E;

sfr P0LPUDSEL  = 0xFE60;
sfr P0HPUDSEL  = 0xFE62;
sfr P1LPUDSEL  = 0xFE6C;
sfr P1HPUDSEL  = 0xFE6E;
sfr P2PUDSEL   = 0xFE78;
sfr P3PUDSEL   = 0xFE7E;
sfr P4PUDSEL   = 0xFE84;
sfr P6PUDSEL   = 0xFE90;
sfr P7PUDSEL   = 0xFE96;

sfr P0LPUDEN   = 0xFE64;
sfr P0HPUDEN   = 0xFE66;
sfr P1LPUDEN   = 0xFE70;
sfr P1HPUDEN   = 0xFE72;
sfr P2PUDEN    = 0xFE7A;
sfr P3PUDEN    = 0xFE80;
sfr P4PUDEN    = 0xFE86;
sfr P6PUDEN    = 0xFE92;
sfr P7PUDEN    = 0xFE98;

sfr P0LPHEN    = 0xFE68;
sfr P0HPHEN    = 0xFE6A;
sfr P1LPHEN    = 0xFE74;
sfr P1HPHEN    = 0xFE76;
sfr P2PPHEN    = 0xFE7C;
sfr P3PHEN     = 0xFE82;
sfr P4PHEN     = 0xFE88;
sfr P6PHEN     = 0xFE94;
sfr P7PHEN     = 0xFE9A;

//-- Serial Interface ----------------------------------------------------------
sfr   S0BG     = 0xFEB4;
sfr   S0CON    = 0xFFB0;
sfr   S0CLC    = 0xFFBA;
sfr   S0EIC    = 0xFF70;
sfr   S0RBUF   = 0xFEB2;
sfr   S0RIC    = 0xFF6E;
sfr   S0TBUF   = 0xFEB0;
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
sbit  S0TBIE   = S0TBIC^6;
sbit  S0TBIR   = S0TBIC^7;
sbit  S0RIE    = S0RIC^6;
sbit  S0RIR    = S0RIC^7;
sbit  S0EIE    = S0EIC^6;
sbit  S0EIR    = S0EIC^7;

sfr   SSCCLC   = 0xF0B6;
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

//-- GPT1, GPT2 ----------------------------------------------------------------
sfr   CAPREL   = 0xFE4A;
sfr   GPTCLC   = 0xFE4C;
sfr   CRIC     = 0xFF6A;
sfr   T2       = 0xFE40;
sfr   T2CON    = 0xFF40;
sfr   T2IC     = 0xFF86;
sfr   T3       = 0xFE42;
sfr   T3CON    = 0xFF42;
sfr   T3IC     = 0xFF9E;
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

/******************************************************************************/
/* Additional Register Declarations for INCA				      */
/******************************************************************************/

/** XBUS SFRs *****************************************************************/
#define SLEEPCON   	(*((unsigned int volatile sdata *) 0xDF3A))
#define PIDDCLC   	(*((unsigned int volatile sdata *) 0xDFAC))
#define PIDDCOM   	(*((unsigned int volatile sdata *) 0xDFAE))
#define PIDDSTAT   	(*((unsigned int volatile sdata *) 0xDFB0))
#define PIDDHWCFG   	(*((unsigned int volatile sdata *) 0xDFB2))
#define PIDDGPTC   	(*((unsigned int volatile sdata *) 0xDFB4))
#define PIDDGPTD   	(*((unsigned int volatile sdata *) 0xDFB6))


/** I2C-BUS **************************************************************/

#define I2CCLC 		(*((unsigned int volatile sdata *) 0xDF40))
#define ICCON 	 	(*((unsigned int volatile sdata *) 0xDF52))
#define ICST 	 	(*((unsigned int volatile sdata *) 0xDF54))
#define ICADR 	 	(*((unsigned int volatile sdata *) 0xDF56))
#define ICCFG 	 	(*((unsigned int volatile sdata *) 0xDF50))
#define RTBH 	 	(*((unsigned int volatile sdata *) 0xDF5A))
#define RTBL 	 	(*((unsigned int volatile sdata *) 0xDF58))

#define ICINTDIC 	(*((unsigned int volatile sdata *) 0xFF6A))
#define ICINTEIC 	(*((unsigned int volatile sdata *) 0xF194))

#ifndef __cplusplus              // EC++

sbit  	ICINTDIE = ICINTDIC^6;
sbit  	ICINTEIE = ICINTEIC^6;
sbit  	ICINTDIR = ICINTDIC^7;
sbit  	ICINTEIR = ICINTEIC^7;

#endif

#define  LRB_   	0x0008
#define  BB_   		0x0010
#define  IRQD_   	0x0020
#define  IRQP_   	0x0040
#define  IRQE_   	0x0080


/** HDLC, Transceiver *********************************************************/
#define RFIFO      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x00)))    
#define XFIFO      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x00)))
#define ISTAH      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x20)))
#define MASKH      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x20)))
#define STAR       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x21)))
#define CMDR       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x21)))
#define MODEH      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x22)))
#define EXMR       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x23)))
#define SAP1       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x25)))
#define SAP2       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x26)))
#define RBCL       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x26)))
#define RBCH       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x27)))
#define TEI1       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x27)))
#define TEI2       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x28)))
#define RSTA       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x28)))
#define TMH        (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x29)))
#define CIR0       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x2e)))
#define CIX0       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x2e)))
#define CIR1       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x2f)))
#define CIX1       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x2f)))
#define TR_CONF0   (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x30)))
#define TR_CONF1   (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x31)))
#define TR_CONF2   (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x32)))
#define TR_CMD     (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x34)))
#define MASKTR     (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x39)))
#define TR_MODE    (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x3A)))
#define CDA10      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x40)))
#define CDA11      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x41)))
#define CDA20      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x42)))
#define CDA21      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x43)))
#define CDA_TSDP10 (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x44)))
#define CDA_TSDP11 (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x45)))
#define CDA_TSDP20 (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x46)))
#define CDA_TSDP21 (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x47)))
#define CO_TSDP10  (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x48)))
#define CO_TSDP11  (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x49)))
#define CO_TSDP20  (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x4A)))
#define CO_TSDP21  (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x4B)))
#define TR_TSDP_B1 (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x4c)))
#define TR_TSDP_B2 (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x4d)))
#define CDA1_CR    (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x4e)))
#define CDA2_CR    (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x4f)))
#define TR_CR      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x50)))
#define BCHA_CR    (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x51)))
#define BCHB_CR    (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x52)))
#define IOM_CR     (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x57)))

#define ISTA       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x60)))
#define MASK       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x60)))
#define MODE1      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x62)))
#define SRES       (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x64)))

#define ITRDU      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x90)))
#define PITRDU     (INCA_IOM_BASE_ADDR + 0x90)
#define ITRDD      (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x91)))
#define PITRDD     (INCA_IOM_BASE_ADDR + 0x91)
#define ITRICV     (*((unsigned char volatile sdata *) (INCA_IOM_BASE_ADDR + 0x92)))

#define ITR_CR     (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0x94)))
#define ITR_MSK_0  (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0x96)))
#define ITR_MSK_1  (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0x98)))
#define ITR_MSK_2  (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0x9A)))
#define ITR_MSK_3  (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0x9C)))
#define ITR_MSK_4  (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0x9E)))
#define ITR_MSK_5  (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0xA0)))
#define ITR_MSK_6  (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0xA2)))
#define ITR_MSK_7  (*((unsigned int volatile sdata *)(INCA_IOM_BASE_ADDR + 0xA4)))

#define IRQ13_STA (*((unsigned int volatile sdata *) 0xdf20))
#define IRQ13_MSK (*((unsigned int volatile sdata *) 0xdf22))
#define IRQ14_STA (*((unsigned int volatile sdata *) 0xdf24))
#define IRQ14_MSK (*((unsigned int volatile sdata *) 0xdf26))

/** IEQ14_STA Register ********************************************************/ 
#define E7IR_	0x8000
#define E6IR_	0x4000
#define E5IR_	0x2000
#define E4IR_	0x1000
#define E3IR_	0x0800

/** IEQ14_MSK Register ********************************************************/ 
#define E7I_	0x8000
#define E6I_	0x4000
#define E5I_	0x2000
#define E4I_	0x1000
#define E3I_	0x0800
	
/** REXICON Register **********************************************************/ 
#define RE7LS2_	0x0200
#define RE7LS1_	0x0100

#define RE6LS2_	0x0080
#define RE6LS1_	0x0040
#define RE5LS2_	0x0020
#define RE5LS1_	0x0010
#define RE4LS2_	0x0008
#define RE4LS1_	0x0004
#define RE3LS2_	0x0002
#define RE3LS1_	0x0001

/** Terminal Specific Functions ***********************************************/
#define TSF_CONF     (*((unsigned int volatile sdata *) 0xDF12))
#define TSF_CONF_R   (*((unsigned int volatile sdata *) 0xDF1A))
#define KEY_CONF     (*((unsigned int volatile sdata *) 0xDF0A))
#define SREG0        (*((unsigned int volatile sdata *) 0xDF00))
#define SREG1        (*((unsigned int volatile sdata *) 0xDF02))
#define SREG23       (*((unsigned int volatile sdata *) 0xDF04))
#define SREG45       (*((unsigned int volatile sdata *) 0xDF06))
#define SREG6789     (*((unsigned int volatile sdata *) 0xDF08))
#define LEDMUX_CONF  (*((unsigned int volatile sdata *) 0xDF0C))
#define LED_REG1     (*((unsigned int volatile sdata *) 0xDF0E))
#define LED_REG2     (*((unsigned int volatile sdata *) 0xDF10))
#define PWM1_WIDTH   (*((unsigned int volatile sdata *) 0xDF14))
#define PWM2_WIDTH   (*((unsigned int volatile sdata *) 0xDF16))

/** Device specific USB registers *********************************************/
#define	USBCLC	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0000)))
#define	GESRL	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0001)))
#define	GESRH	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0002)))
#define	CIARL	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0003)))
#define	CIARH	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0004)))
#define	GEPIRL	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0005)))
#define	GEPIRH	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0006)))
#define	CIARI	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0007)))
#define	CIARIE	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0008)))
#define	DCR	 		(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0009)))
#define	DPWDR	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x000A)))
#define	DIER	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x000B)))
#define	DIRR	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x000C)))
#define	DSSR	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x000D)))
#define	FNRL	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x000E)))
#define	FRNH	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x000F)))
#define	DGSRL	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0010)))
#define	DGSRH	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0011)))
#define	IGSRL	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0012)))
#define	IGSRH	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0013)))
#define	IFCSEL	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0014)))
#define	ESTR	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0015)))
#define	ACTEP	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0016)))

#define	EGSR0L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0020)))
#define	EGSR1L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0021)))
#define	EGSR2L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0022)))
#define	EGSR3L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0023)))
#define	EGSR4L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0024)))
#define	EGSR5L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0025)))
#define	EGSR6L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0026)))
#define	EGSR7L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0027)))
#define	EGSR8L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0028)))
#define	EGSR9L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0029)))
#define	EGSR10L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x002A)))
#define	EGSR11L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x002B)))
#define	EGSR12L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x002C)))
#define	EGSR13L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x002D)))
#define	EGSR14L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x002E)))
#define	EGSR15L	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x002F)))

#define	EGSR0H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0030)))
#define	EGSR1H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0031)))
#define	EGSR2H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0032)))
#define	EGSR3H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0033)))
#define	EGSR4H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0034)))
#define	EGSR5H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0035)))
#define	EGSR6H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0036)))
#define	EGSR7H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0037)))
#define	EGSR8H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0038)))
#define	EGSR9H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0039)))
#define	EGSR10H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x003A)))
#define	EGSR11H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x003B)))
#define	EGSR12H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x003C)))
#define	EGSR13H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x003D)))
#define	EGSR14H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x003E)))
#define	EGSR15H	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x003F)))

#define	EPIE0	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0040)))
#define	EPIE1	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0041)))
#define	EPIE2	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0042)))
#define	EPIE3	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0043)))
#define	EPIE4	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0044)))
#define	EPIE5	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0045)))
#define	EPIE6	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0046)))
#define	EPIE7	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0047)))
#define	EPIE8	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0048)))
#define	EPIE9	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0049)))
#define	EPIE10	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x004A)))
#define	EPIE11	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x004B)))
#define	EPIE12	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x004C)))
#define	EPIE13	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x004D)))
#define	EPIE14	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x004E)))
#define	EPIE15	 	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x004F)))

#define	EPIR0	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0050)))
#define	EPIR1	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0051)))
#define	EPIR2	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0052)))
#define	EPIR3	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0053)))
#define	EPIR4	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0054)))
#define	EPIR5	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0055)))
#define	EPIR6	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0056)))
#define	EPIR7	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0057)))
#define	EPIR8	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0058)))
#define	EPIR9	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0059)))
#define	EPIR10	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x005A)))
#define	EPIR11	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x005B)))
#define	EPIR12	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x005C)))
#define	EPIR13	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x005D)))
#define	EPIR14	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x005E)))
#define	EPIR15	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x005F)))

#define	EPBC0	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0060)))
#define	EPBC1	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0061)))
#define	EPBC2	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0062)))
#define	EPBC3	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0063)))
#define	EPBC4	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0064)))
#define	EPBC5	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0065)))
#define	EPBC6	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0066)))
#define	EPBC7	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0067)))
#define	EPBC8	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0068)))
#define	EPBC9	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0069)))
#define	EPBC10	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x006A)))
#define	EPBC11	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x006B)))
#define	EPBC12	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x006C)))
#define	EPBC13	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x006D)))
#define	EPBC14	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x006E)))
#define	EPBC15	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x006F)))

#define	EPBS0	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0070)))
#define	EPBS1	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0071)))
#define	EPBS2	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0072)))
#define	EPBS3	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0073)))
#define	EPBS4	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0074)))
#define	EPBS5	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0075)))
#define	EPBS6	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0076)))
#define	EPBS7	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0077)))
#define	EPBS8	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0078)))
#define	EPBS9	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0079)))
#define	EPBS10	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x007A)))
#define	EPBS11	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x007B)))
#define	EPBS12	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x007C)))
#define	EPBS13	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x007D)))
#define	EPBS14	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x007E)))
#define	EPBS15	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x007F)))

#define	EPBA0	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0080)))
#define	EPBA1	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0081)))
#define	EPBA2	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0082)))
#define	EPBA3	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0083)))
#define	EPBA4	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0084)))
#define	EPBA5	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0085)))
#define	EPBA6	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0086)))
#define	EPBA7	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0087)))
#define	EPBA8	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0088)))
#define	EPBA9	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0089)))
#define	EPBA10	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x008A)))
#define	EPBA11	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x008B)))
#define	EPBA12	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x008C)))
#define	EPBA13	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x008D)))
#define	EPBA14	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x008E)))
#define	EPBA15	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x008F)))

#define	EPLEN0	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0090)))
#define	EPLEN1	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0091)))
#define	EPLEN2	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0092)))
#define	EPLEN3	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0093)))
#define	EPLEN4	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0094)))
#define	EPLEN5	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0095)))
#define	EPLEN6	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0096)))
#define	EPLEN7	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0097)))
#define	EPLEN8	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0098)))
#define	EPLEN9	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x0099)))
#define	EPLEN10	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x009A)))
#define	EPLEN11	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x009B)))
#define	EPLEN12	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x009C)))
#define	EPLEN13	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x009D)))
#define	EPLEN14	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x009E)))
#define	EPLEN15	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x009F)))

#define	ADROFF0	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A0)))
#define	ADROFF1	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A1)))
#define	ADROFF2	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A2)))
#define	ADROFF3	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A3)))
#define	ADROFF4	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A4)))
#define	ADROFF5	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A5)))
#define	ADROFF6	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A6)))
#define	ADROFF7	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A7)))
#define	ADROFF8	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A8)))
#define	ADROFF9	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00A9)))
#define	ADROFF10	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00AA)))
#define	ADROFF11	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00AB)))
#define	ADROFF12	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00AC)))
#define	ADROFF13	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00AD)))
#define	ADROFF14	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00AE)))
#define	ADROFF15	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00AF)))

#define	USBVAL0	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B0)))
#define	USBVAL1	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B1)))
#define	USBVAL2	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B2)))
#define	USBVAL3	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B3)))
#define	USBVAL4	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B4)))
#define	USBVAL5	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B5)))
#define	USBVAL6	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B6)))
#define	USBVAL7	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B7)))
#define	USBVAL8	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B8)))
#define	USBVAL9	    (*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00B9)))
#define	USBVAL10	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00BA)))
#define	USBVAL11	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00BB)))
#define	USBVAL12	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00BC)))
#define	USBVAL13	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00BD)))
#define	USBVAL14	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00BE)))
#define	USBVAL15	(*((unsigned char volatile sdata *) (INCA_USB_BASE_ADDR + 0x00BF)))
          
/** USBCLC ********************************************************************/
#define  USB_SUSPEND_   0x0004

/** GESR **********************************************************************/
#define  EPST0_   0x0001
#define  EPST1_   0x0002
#define  EPST2_   0x0004
#define  EPST3_   0x0008
#define  EPST4_   0x0010
#define  EPST5_   0x0020
#define  EPST6_   0x0040
#define  EPST7_   0x0080
#define  EPST8_   0x0100
#define  EPST9_   0x0200
#define  EPST10_  0x0400
#define  EPST11_  0x0800
#define  EPST12_  0x1000
#define  EPST13_  0x2000
#define  EPST14_  0x4000
#define  EPST15_  0x8000

/** CIAR **********************************************************************/
#define  AS0_     0x0001
#define  AS1_     0x0002
#define  AS2_     0x0004
#define  AS3_     0x0008
#define  IF0_     0x0010
#define  IF1_     0x0020
#define  IF2_     0x0040
#define  IF3_     0x0080
#define  CFG0_    0x0100
#define  CFG1_    0x0200
#define  CFG2_    0x0400
#define  CFG3_    0x0800

/** GEPIR *********************************************************************/
#define  EPI0_    0x0001

#define  EPI5_    0x0020
#define  EPI6_    0x0040
#define  EPI7_    0x0080
#define  EPI8_    0x0100
#define  EPI9_    0x0200
#define  EPI10_   0x0400
#define  EPI11_   0x0800
#define  EPI12_   0x1000
#define  EPI13_   0x2000
#define  EPI14_   0x4000
#define  EPI15_   0x8000

/** CIARI *********************************************************************/
#define  DRVI_    0x01

/** CIARIE *********************************************************************/
#define  DRVIE_    0x01

/** DCR ***********************************************************************/
#define  UCLK_    0x02
#define  RSM_     0x04
#define  DINIT_   0x08
#define  SUSP_    0x10
#define  SWR_     0x20

/** DPWDR *********************************************************************/
#define  RPWD_    0x01
#define  TPWD_    0x02

/** DIER **********************************************************************/
#define  SOFIE_   0x01
#define  SUIE_    0x02
#define  STIE_    0x04
#define  SEIE_    0x08
#define  SBIE_    0x10
#define  DDIE_    0x20
#define  DAIE_    0x40
#define  SE0IE_   0x80

/** DIRR **********************************************************************/
#define  SOFI_    0x01
#define  SUI_     0x02
#define  STI_     0x04
#define  SEI_     0x08
#define  SBI_     0x10
#define  DDI_     0x20
#define  DAI_     0x40
#define  SE0I_    0x80

/** DSSR **********************************************************************/
#define  IR_      0x01
#define  IE_      0x02

/** DGSR **********************************************************************/
#define  PSTAT_   0x01
#define  RWUP_    0x02

/** ESTR **********************************************************************/
#define  STRE_    0x80

/** EPIE **********************************************************************/
#define  SODIE_   0x01
#define  EODIE_   0x02
#define  NODIE_   0x04
#define  DNRIE_   0x08
#define  RLEIE_   0x20
#define  NAIE_    0x40
#define  AIE_     0x80

/** EPIR **********************************************************************/
#define  SOD_     0x01
#define  EOD_     0x02
#define  NOD_     0x04
#define  DNR_     0x08
#define  RLE_     0x20
#define  NACK_    0x40
#define  ACK_     0x80

/** EPBC **********************************************************************/
#define  DBM_     0x01
#define  INCE_    0x04
#define  SOFDE_   0x08
#define  GEPIE_   0x10
#define  STALL_   0x80

/** EPBS **********************************************************************/
#define  DONE_    0x01
#define  CLREP_   0x02
#define  SETWR_   0x04
#define  SETRD_   0x08
#define  ESP_     0x10
#define  DIR_     0x20
#define  CBF_     0x40
#define  UBF_     0x80

/** USBLED *******************************************************************/
#define  USBLED_     0x0020				// USB LED (D20)

//mschmid:
/** USBEN ********************************************************************/
sbit  	USBEN    = P3^5;				// USB Enable Pin at Port 3.5
sbit  	USBEND   = DP3^5;				// Direction bit for USB Enable Pin
//

/** Clock-Management *********************************************************/
#define CLK_CONF		(* ((unsigned int *) (0xDFAA)))

/** Interrupt registers ******************************************************/
sfr   USBIC       = 0xff9a;
sfr   USBEPIC     = 0xff98;
sfr   USBEP1IC    = 0xff9c;
sfr   USBEP2IC    = 0xff76;
sfr   USBEP3IC    = 0xff70;
sfr   USBEP4IC    = 0xff78;

sfr   IOM1IC  =  0xff84;
sfr   IOM2IC  =  0xff82;
sfr   IOM3IC  =  0xff80;
sfr   IOM4IC  =  0xff7e;
sfr   IOM5IC  =  0xff60;
sfr   IOM6IC  =  0xff62;
sfr   IOM7IC  =  0xff64;
sfr   IOM8IC  =  0xff66;

sfr   COMB1IC    = 0xff68;
sfr   COMB2IC    = 0xff6c;

sfr   FEX0IC     = 0xff88;
sfr   FEX1IC     = 0xff8a;
sfr   FEX2IC     = 0xff8c;

/** USB Interrupt Enable Bits ************************************************/
sbit  USBIE       =  USBIC^6;
sbit  USBEPIE     =  USBEPIC^6;
sbit  USBEP1IE    =  USBEP1IC^6;
sbit  USBEP2IE    =  USBEP2IC^6;
sbit  USBEP3IE    =  USBEP3IC^6;
sbit  USBEP4IE    =  USBEP4IC^6;

/** USB Interrupt Request Flags **********************************************/
sbit  USBIR       =  USBIC^7;
sbit  USBEPIR     =  USBEPIC^7;
sbit  USBEP1IR    =  USBEP1IC^7;
sbit  USBEP2IR    =  USBEP2IC^7;
sbit  USBEP3IR    =  USBEP3IC^7;
sbit  USBEP4IR    =  USBEP4IC^7;

sbit  IOM1IE   = IOM1IC^6;
sbit  IOM2IE   = IOM2IC^6;
sbit  IOM3IE   = IOM3IC^6;
sbit  IOM4IE   = IOM4IC^6;
sbit  IOM5IE   = IOM5IC^6;
sbit  IOM6IE   = IOM6IC^6;
sbit  IOM7IE   = IOM7IC^6;
sbit  IOM8IE   = IOM8IC^6;

sbit  IOM1IR   = IOM1IC^7;
sbit  IOM2IR   = IOM2IC^7;
sbit  IOM3IR   = IOM3IC^7;
sbit  IOM4IR   = IOM4IC^7;
sbit  IOM5IR   = IOM5IC^7;
sbit  IOM6IR   = IOM6IC^7;
sbit  IOM7IR   = IOM7IC^7;
sbit  IOM8Ir   = IOM8IC^7;


sbit  COMB1IE = COMB1IC^6;
sbit  COMB2IE = COMB2IC^6;

sbit  FEX0IE   = FEX0IC^6;
sbit  FEX1IE   = FEX1IC^6;
sbit  FEX2IE   = FEX2IC^6;

/** XBUS registers ***********************************************************/

/** CLK_CONF *****************************************************************/
#define  PLLEN_      0x0001
#define  USB_DIS_    0x0002
#define  LOCK_       0x0020
#define  DSP_BYP_    0x4000
#define  CPU_BYP_    0x8000

/** PIDD *****************************************************************/
#define  PIDD_RDY_   0x8000
#define  PIDD_ABT_   0x4000
#define  PIDD_COV_   0x2000
#define  PIDD_DTV_   0x0010
#define  PIDD_TG_    0x0004

#define  PIDDHW_PD_  0x0080

#endif


/******************************************************************************

                               No Warranty                                  

   Because the program is licensed free of charge, there is no warranty for 
   the program, to the extent permitted by applicable law.  Except when     
   otherwise stated in writing the copyright holders and/or other parties   
   provide the program "as is" without warranty of any kind, either         
   expressed or implied, including, but not limited to, the implied         
   warranties of merchantability and fitness for a particular purpose. The  
   entire risk as to the quality and performance of the program is with     
   you.  should the program prove defective, you assume the cost of all     
   necessary servicing, repair or correction.                               
                                                                            
   In no event unless required by applicable law or agreed to in writing    
   will any copyright holder, or any other party who may modify and/or      
   redistribute the program as permitted above, be liable to you for        
   damages, including any general, special, incidental or consequential     
   damages arising out of the use or inability to use the program           
   (including but not limited to loss of data or data being rendered        
   inaccurate or losses sustained by you or third parties or a failure of   
   the program to operate with any other programs), even if such holder or  
   other party has been advised of the possibility of such damages. 

******************************************************************************/

/*--------------------------------------------------------------------------
XC16X.h
Register Declarations for XC16x Family
Copyright (c)2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __XC16X_H__
#define __XC16X_H__


//XC16x Common SFRs

/* ADC */
sfr  ADC_CTR2             = 0xF09C;       //A/D Converter Control Register 2
sfr  ADC_CTR2IN           = 0xF09E;       //A/D Converter Injection Control Register 2
sfr  ADC_DAT2             = 0xF0A0;       //A/D Converter Result Register 2
sfr  ADC_DAT              = 0xFEA0;       //A/D Converter Result Register
sfr  ADC_ID               = 0xFEA8;       //A/D Converter ID Register
sfr  ADC_CON              = 0xFFA0;       //A/D Converter Control Register
sbit ADC_CON_ADST         = ADC_CON^7;
sbit ADC_CON_ADBSY        = ADC_CON^8;
sbit ADC_CON_ADWR         = ADC_CON^9;
sbit ADC_CON_ADCIN        = ADC_CON^10;
sbit ADC_CON_ADCRQ        = ADC_CON^11;
sfr  ADC_CON1             = 0xFFA6;       //A/D Converter Control Register 1
sbit ADC_CON1_RES         = ADC_CON1^12;
sbit ADC_CON1_CAL         = ADC_CON1^13;
sbit ADC_CON1_SAMPLE      = ADC_CON1^14;
sbit ADC_CON1_ICST        = ADC_CON1^15;
sfr  ADC_CTR0             = 0xFFBE;       //A/D Converter Control Register 0
sbit ADC_CTR0_ADST        = ADC_CTR0^7;
sbit ADC_CTR0_ADBSY       = ADC_CTR0^8;
sbit ADC_CTR0_ADWR        = ADC_CTR0^9;
sbit ADC_CTR0_ADCIN       = ADC_CTR0^10;
sbit ADC_CTR0_ADCRQ       = ADC_CTR0^11;
sbit ADC_CTR0_SAMPLE      = ADC_CTR0^14;
sbit ADC_CTR0_MD          = ADC_CTR0^15;

/* ASC0 */
sfr  ASC0_ABSTAT          = 0xF0B8;       //ASC0 Autobaud Status Register
sfr  ASC0_FSTAT           = 0xF0BA;       //FIFO Status Register
sfr  ASC0_TXFCON          = 0xF0C4;       //Transmit FIFO Control Register
sfr  ASC0_RXFCON          = 0xF0C6;       //Receive FIFO Control Register
sfr  ASC0_ABCON           = 0xF1B8;       //ASC0 Autobaud Control Register
sbit ASC0_ABCON_ABEN      = ASC0_ABCON^0;
sbit ASC0_ABCON_AUREN     = ASC0_ABCON^1;
sbit ASC0_ABCON_ABSTEN    = ASC0_ABCON^2;
sbit ASC0_ABCON_ABDETEN   = ASC0_ABCON^3;
sbit ASC0_ABCON_FCDETEN   = ASC0_ABCON^4;
sbit ASC0_ABCON_TXINV     = ASC0_ABCON^10;
sbit ASC0_ABCON_RXINV     = ASC0_ABCON^11;
sfr  ASC0_PMW             = 0xFEAA;       //ASC0 IrDA Pulse Mode and Width Reg.
sfr  ASC0_TBUF            = 0xFEB0;       //Serial Channel 0 Transmitter Buffer Register (WO)
sfr  ASC0_RBUF            = 0xFEB2;       //Serial Channel 0 Receiver Buffer Register (RO)
sfr  ASC0_BG              = 0xFEB4;       //Serial Channel 0 Baud Rate Generator Reload Register
sfr  ASC0_FDV             = 0xFEB6;       //Fractional Divider Register
sfr  ASC0_CON             = 0xFFB0;       //Serial Channel 0 Control Register
sbit ASC0_CON_STP         = ASC0_CON^3;
sbit ASC0_CON_REN         = ASC0_CON^4;
sbit ASC0_CON_PEN_RXDI    = ASC0_CON^5;
sbit ASC0_CON_FEN         = ASC0_CON^6;
sbit ASC0_CON_OEN         = ASC0_CON^7;
sbit ASC0_CON_PE          = ASC0_CON^8;
sbit ASC0_CON_FE          = ASC0_CON^9;
sbit ASC0_CON_OE          = ASC0_CON^10;
sbit ASC0_CON_S0FDE       = ASC0_CON^11;
sbit ASC0_CON_ODD         = ASC0_CON^12;
sbit ASC0_CON_BRS         = ASC0_CON^13;
sbit ASC0_CON_LB          = ASC0_CON^14;
sbit ASC0_CON_R           = ASC0_CON^15;
#define ASC0_ID    (*((unsigned int volatile sdata *) 0xFFE2))     //ASC0 Identification Register
/* ASC1 */
sfr  ASC1_TXFCON          = 0xF0A4;       //Transmit FIFO Control Register
sfr  ASC1_RXFCON          = 0xF0A6;       //Receive FIFO Control Register
sfr  ASC1_ABSTAT          = 0xF0BC;       //ASC1 Autobaud Status Register
sfr  ASC1_FSTAT           = 0xF0BE;       //FIFO Status Register
sfr  ASC1_ABCON           = 0xF1BC;       //ASC1 Autobaud Control Register
sbit ASC1_ABCON_ABEN      = ASC1_ABCON^0;
sbit ASC1_ABCON_AUREN     = ASC1_ABCON^1;
sbit ASC1_ABCON_ABSTEN    = ASC1_ABCON^2;
sbit ASC1_ABCON_ABDETEN   = ASC1_ABCON^3;
sbit ASC1_ABCON_FCDETEN   = ASC1_ABCON^4;
sbit ASC1_ABCON_TXINV     = ASC1_ABCON^10;
sbit ASC1_ABCON_RXINV     = ASC1_ABCON^11;
sfr  ASC1_PMW             = 0xFEAC;       //ASC1 IrDA Pulse Mode and Width Reg.
sfr  ASC1_TBUF            = 0xFEB8;       //Serial Channel 1 Transmitter Buffer Register (WO)
sfr  ASC1_RBUF            = 0xFEBA;       //Serial Channel 1 Receiver Buffer Register (RO)
sfr  ASC1_BG              = 0xFEBC;       //Serial Channel 1 Baud Rate Generator Reload Register
sfr  ASC1_FDV             = 0xFEBE;       //Fractional Divider Register
sfr  ASC1_CON             = 0xFFB8;       //Serial Channel 1 Control Register
sbit ASC1_CON_STP         = ASC1_CON^3;
sbit ASC1_CON_REN         = ASC1_CON^4;
sbit ASC1_CON_PEN         = ASC1_CON^5;
sbit ASC1_CON_FEN         = ASC1_CON^6;
sbit ASC1_CON_OEN         = ASC1_CON^7;
sbit ASC1_CON_PE          = ASC1_CON^8;
sbit ASC1_CON_FE          = ASC1_CON^9;
sbit ASC1_CON_OE          = ASC1_CON^10;
sbit ASC1_CON_S0FDE       = ASC1_CON^11;
sbit ASC1_CON_ODD         = ASC1_CON^12;
sbit ASC1_CON_BRS         = ASC1_CON^13;
sbit ASC1_CON_LB          = ASC1_CON^14;
sbit ASC1_CON_R           = ASC1_CON^15;
#define ASC1_ID    (*((unsigned int volatile sdata *) 0xFFF4))     //ASC1 Identification Register
/* IC */
sfr  ASC1_TBIC            = 0xF150;       //ASC1 Transmit Buffer Interrupt Control Register
sbit ASC1_TBIC_IE         = ASC1_TBIC^6;
sbit ASC1_TBIC_IR         = ASC1_TBIC^7;
sbit ASC1_TBIC_GPX        = ASC1_TBIC^8;
sfr  ASC1_TIC             = 0xF182;       //ASC1 Transmit Interrupt Control Register
sbit ASC1_TIC_IE          = ASC1_TIC^6;
sbit ASC1_TIC_IR          = ASC1_TIC^7;
sbit ASC1_TIC_GPX         = ASC1_TIC^8;
sfr  IIC_DIC              = 0xF186;       //IIC Data Interrupt Control Register
sbit IIC_DIC_IE           = IIC_DIC^6;
sbit IIC_DIC_IR           = IIC_DIC^7;
sbit IIC_DIC_GPX          = IIC_DIC^8;
sfr  ASC1_RIC             = 0xF18A;       //ASC1 Receive Interrupt Control Register
sbit ASC1_RIC_IE          = ASC1_RIC^6;
sbit ASC1_RIC_IR          = ASC1_RIC^7;
sbit ASC1_RIC_GPX         = ASC1_RIC^8;
sfr  IIC_PEIC             = 0xF18E;       //IIC Protocol Event Interrupt Control Register
sbit IIC_PEIC_IE          = IIC_PEIC^6;
sbit IIC_PEIC_IR          = IIC_PEIC^7;
sbit IIC_PEIC_GPX         = IIC_PEIC^8;
sfr  ASC1_EIC             = 0xF192;       //ASC1 Error Interrupt Control Register
sbit ASC1_EIC_IE          = ASC1_EIC^6;
sbit ASC1_EIC_IR          = ASC1_EIC^7;
sbit ASC1_EIC_GPX         = ASC1_EIC^8;
sfr  ASC1_ABIC            = 0xF1BA;       //ASC1 Autobaud Interrupt Control Register
sbit ASC1_ABIC_IE         = ASC1_ABIC^6;
sbit ASC1_ABIC_IR         = ASC1_ABIC^7;
sbit ASC1_ABIC_GPX        = ASC1_ABIC^8;


/* CC1 */
sfr  CC1_IOC              = 0xF062;       //CAPCOM1 IO Control
sfr  CC1_SEM              = 0xFE2C;       //CAPCOM 1 Single Event Control Register
sfr  CC1_SEE              = 0xFE2E;       //CAPCOM 1 Single Event Enable Register
sfr  CC1_T0               = 0xFE50;       //CAPCOM 1 Timer 0 Register
sfr  CC1_T1               = 0xFE52;       //CAPCOM 1 Timer 1 Register
sfr  CC1_T0REL            = 0xFE54;       //CAPCOM 1 Timer 0 Reload Register
sfr  CC1_T1REL            = 0xFE56;       //CC Timer 1 Reloed Register
sfr  CC1_CC0              = 0xFE80;       //CAPCOM 1 Register 0
sfr  CC1_CC1              = 0xFE82;       //CAPCOM 1 Register 1
sfr  CC1_CC2              = 0xFE84;       //CAPCOM 1 Register 2
sfr  CC1_CC3              = 0xFE86;       //CAPCOM 1 Register 3
sfr  CC1_CC4              = 0xFE88;       //CAPCOM 1 Register 4
sfr  CC1_CC5              = 0xFE8A;       //CAPCOM 1 Register 5
sfr  CC1_CC6              = 0xFE8C;       //CAPCOM 1 Register 6
sfr  CC1_CC7              = 0xFE8E;       //CAPCOM 1 Register 7
sfr  CC1_CC8              = 0xFE90;       //CAPCOM 1 Register 8
sfr  CC1_CC9              = 0xFE92;       //CAPCOM 1 Register 9
sfr  CC1_CC10             = 0xFE94;       //CAPCOM 1 Register 10
sfr  CC1_CC11             = 0xFE96;       //CAPCOM 1 Register 11
sfr  CC1_CC12             = 0xFE98;       //CAPCOM 1 Register 12
sfr  CC1_CC13             = 0xFE9A;       //CAPCOM 1 Register 13
sfr  CC1_CC14             = 0xFE9C;       //CAPCOM 1 Register 14
sfr  CC1_CC15             = 0xFE9E;       //CAPCOM 1 Register 15
sfr  CC1_T01CON           = 0xFF50;       //Timer 0/1 Control Register
sbit CC1_T01CON_T0M       = CC1_T01CON^3;
sbit CC1_T01CON_T0R       = CC1_T01CON^6;
sbit CC1_T01CON_T1M       = CC1_T01CON^11;
sbit CC1_T01CON_T1R       = CC1_T01CON^14;
sfr  CC1_M0               = 0xFF52;       //Capture/Compare Mode Registers for the CAPCOM Unit (CC0...CC3)
sbit CC1_M0_ACC0          = CC1_M0^3;
sbit CC1_M0_ACC1          = CC1_M0^7;
sbit CC1_M0_ACC2          = CC1_M0^11;
sbit CC1_M0_ACC3          = CC1_M0^15;
sfr  CC1_M1               = 0xFF54;       //Capture/Compare Mode Register for the CAPCOM Unit (CC4...CC79
sbit CC1_M1_ACC4          = CC1_M1^3;
sbit CC1_M1_ACC5          = CC1_M1^7;
sbit CC1_M1_ACC6          = CC1_M1^11;
sbit CC1_M1_ACC7          = CC1_M1^15;
sfr  CC1_M2               = 0xFF56;       //Capture/Compare Mode Registers for the CAPCOM Unit (CC8...CC11)
sbit CC1_M2_ACC8          = CC1_M2^3;
sbit CC1_M2_ACC9          = CC1_M2^7;
sbit CC1_M2_ACC10         = CC1_M2^11;
sbit CC1_M2_ACC11         = CC1_M2^15;
sfr  CC1_M3               = 0xFF58;       //Capture/Compare Mode Registers for the CAPCOM Unit (CC12...CC15)
sbit CC1_M3_ACC12         = CC1_M3^3;
sbit CC1_M3_ACC13         = CC1_M3^7;
sbit CC1_M3_ACC14         = CC1_M3^11;
sbit CC1_M3_ACC15         = CC1_M3^15;
sfr  CC1_DRM              = 0xFF5A;       //CAPCOM1 Double Register Mode Register
sfr  CC1_OUT              = 0xFF5C;       //CAPCOM1 Output Register
sbit CC1_OUT_CC0IO        = CC1_OUT^0;
sbit CC1_OUT_CC1IO        = CC1_OUT^1;
sbit CC1_OUT_CC2IO        = CC1_OUT^2;
sbit CC1_OUT_CC3IO        = CC1_OUT^3;
sbit CC1_OUT_CC4IO        = CC1_OUT^4;
sbit CC1_OUT_CC5IO        = CC1_OUT^5;
sbit CC1_OUT_CC6IO        = CC1_OUT^6;
sbit CC1_OUT_CC7IO        = CC1_OUT^7;
sbit CC1_OUT_CC8IO        = CC1_OUT^8;
sbit CC1_OUT_CC9IO        = CC1_OUT^9;
sbit CC1_OUT_CC10IO       = CC1_OUT^10;
sbit CC1_OUT_CC11IO       = CC1_OUT^11;
sbit CC1_OUT_CC12IO       = CC1_OUT^12;
sbit CC1_OUT_CC13IO       = CC1_OUT^13;
sbit CC1_OUT_CC14IO       = CC1_OUT^14;
sbit CC1_OUT_CC15IO       = CC1_OUT^15;

#define CC1_ID     (*((unsigned int volatile sdata *) 0xFFEC))     //CAPCOM1 Module Identification Register

/* CC2 */
sfr  CC2_T7               = 0xF050;       //CAPCOM 2 Timer 7 Register
sfr  CC2_T8               = 0xF052;       //CAPCOM 2 Timer 8 Register
sfr  CC2_T7REL            = 0xF054;       //CAPCOM 2 Timer 7 Reload Register
sfr  CC2_T8REL            = 0xF056;       //CAPCOM 2 Timer 8 Reload Register
sfr  CC2_IOC              = 0xF066;       //CAPCOM2 IO Control
sfr  CC2_SEM              = 0xFE28;       //CAPCOM 2 Single Event Control Register
sfr  CC2_SEE              = 0xFE2A;       //CAPCOM 2 Single Event Enable Register
sfr  CC2_CC16             = 0xFE60;       //CAPCOM 2 Register 16
sfr  CC2_CC17             = 0xFE62;       //CAPCOM 2 Register 17
sfr  CC2_CC18             = 0xFE64;       //CAPCOM 2 Register 18
sfr  CC2_CC19             = 0xFE66;       //CAPCOM 2 Register 19
sfr  CC2_CC20             = 0xFE68;       //CAPCOM 2 Register 20
sfr  CC2_CC21             = 0xFE6A;       //CAPCOM 2 Register 21
sfr  CC2_CC22             = 0xFE6C;       //CAPCOM 2 Register 22
sfr  CC2_CC23             = 0xFE6E;       //CAPCOM 2 Register 23
sfr  CC2_CC24             = 0xFE70;       //CAPCOM 2 Register 24
sfr  CC2_CC25             = 0xFE72;       //CAPCOM 2 Register 25
sfr  CC2_CC26             = 0xFE74;       //CAPCOM 2 Register 26
sfr  CC2_CC27             = 0xFE76;       //CAPCOM 2 Register 27
sfr  CC2_CC28             = 0xFE78;       //CAPCOM 2 Register 28
sfr  CC2_CC29             = 0xFE7A;       //CAPCOM 2 Register 29
sfr  CC2_CC30             = 0xFE7C;       //CAPCOM 2 Register 30
sfr  CC2_CC31             = 0xFE7E;       //CAPCOM 2 Register 31
sfr  CC2_T78CON           = 0xFF20;       //CAPCOM 2 Timer 7 and Timer 8 Control Register
sbit CC2_T78CON_T7M       = CC2_T78CON^3;
sbit CC2_T78CON_T7R       = CC2_T78CON^6;
sbit CC2_T78CON_T8M       = CC2_T78CON^11;
sbit CC2_T78CON_T8R       = CC2_T78CON^14;
sfr  CC2_M4               = 0xFF22;       //CC Mode Control Register 4
sbit CC2_M4_ACC16         = CC2_M4^3;
sbit CC2_M4_ACC17         = CC2_M4^7;
sbit CC2_M4_ACC18         = CC2_M4^11;
sbit CC2_M4_ACC19         = CC2_M4^15;
sfr  CC2_M5               = 0xFF24;       //CC Mode Control Register 5
sbit CC2_M5_ACC20         = CC2_M5^3;
sbit CC2_M5_ACC21         = CC2_M5^7;
sbit CC2_M5_ACC22         = CC2_M5^11;
sbit CC2_M5_ACC23         = CC2_M5^15;
sfr  CC2_M6               = 0xFF26;       //CC Mode Control Register 6
sbit CC2_M6_ACC24         = CC2_M6^3;
sbit CC2_M6_ACC25         = CC2_M6^7;
sbit CC2_M6_ACC26         = CC2_M6^11;
sbit CC2_M6_ACC27         = CC2_M6^15;
sfr  CC2_M7               = 0xFF28;       //CC Mode Control Register 7
sbit CC2_M7_ACC28         = CC2_M7^3;
sbit CC2_M7_ACC29         = CC2_M7^7;
sbit CC2_M7_ACC30         = CC2_M7^11;
sbit CC2_M7_ACC31         = CC2_M7^15;
sfr  CC2_DRM              = 0xFF2A;       //CAPCOM 2 Double Register Mode Register
sfr  CC2_OUT              = 0xFF2C;       //CAPCOM 2 Output Register
sbit CC2_OUT_CC0IO        = CC2_OUT^0;
sbit CC2_OUT_CC1IO        = CC2_OUT^1;
sbit CC2_OUT_CC2IO        = CC2_OUT^2;
sbit CC2_OUT_CC3IO        = CC2_OUT^3;
sbit CC2_OUT_CC4IO        = CC2_OUT^4;
sbit CC2_OUT_CC5IO        = CC2_OUT^5;
sbit CC2_OUT_CC6IO        = CC2_OUT^6;
sbit CC2_OUT_CC7IO        = CC2_OUT^7;
sbit CC2_OUT_CC8IO        = CC2_OUT^8;
sbit CC2_OUT_CC9IO        = CC2_OUT^9;
sbit CC2_OUT_CC10IO       = CC2_OUT^10;
sbit CC2_OUT_CC11IO       = CC2_OUT^11;
sbit CC2_OUT_CC12IO       = CC2_OUT^12;
sbit CC2_OUT_CC13IO       = CC2_OUT^13;
sbit CC2_OUT_CC14IO       = CC2_OUT^14;
sbit CC2_OUT_CC15IO       = CC2_OUT^15;
#define CC2_ID     (*((unsigned int volatile sdata *) 0xFFEE))     //CAPCOM2 Module Identification Register

/* CERBERUS */
sfr  COMDATA              = 0xF068;       //Communication Mode data register

/* CORE */
sfr  CPUID                = 0xF00C;       //CPU Identification Register
sfr  DPP0                 = 0xFE00;       //CPU Data Page Pointer 0 Register
sfr  DPP1                 = 0xFE02;       //CPU Data Page Pointer 1 Register
sfr  DPP2                 = 0xFE04;       //CPU Data Page Pointer 2 Register
sfr  DPP3                 = 0xFE06;       //CPU Data Page Pointer 3 Register
sfr  CSP                  = 0xFE08;       //CPU Code Segment Pointer Register
sfr  MDH                  = 0xFE0C;       //CPU Multiply Divide Register - High Word
sfr  MDL                  = 0xFE0E;       //CPU Multiply Divide Register - Low Word
sfr  CP                   = 0xFE10;       //CPU Context Pointer Register
sfr  SP                   = 0xFE12;       //CPU System Stack Pointer Register
sfr  STKOV                = 0xFE14;       //CPU Stack Overflow Pointer Register
sfr  STKUN                = 0xFE16;       //CPU Stack Underflow Pointer Register
sfr  CPUCON1              = 0xFE18;       //CPU Control Register 1
sfr  CPUCON2              = 0xFE1A;       //CPU Control Register 2
sfr  MAL                  = 0xFE5C;       //Accumulator Low Word
sfr  MAH                  = 0xFE5E;       //Accumulator High Word
sfr  IDX0                 = 0xFF08;       //Address Pointer
sfr  IDX1                 = 0xFF0A;       //Address Pointer
sfr  SPSEG                = 0xFF0C;       //Stack Pointer Segment Register
sfr  MDC                  = 0xFF0E;       //CPU Multiply Divide Control Register
sbit MDC_MDRIU            = MDC^4;
sfr  PSW                  = 0xFF10;       //Processor Status Word
sbit PSW_N                = PSW^0;
sbit PSW_C                = PSW^1;
sbit PSW_V                = PSW^2;
sbit PSW_Z                = PSW^3;
sbit PSW_E                = PSW^4;
sbit PSW_MULIP            = PSW^5;
sbit PSW_USR0             = PSW^6;
sbit PSW_USR1             = PSW^7;
sbit PSW_S1               = PSW^10;
sbit PSW_IEN              = PSW^11;
sfr  VECSEG               = 0xFF12;       //Vector  Segment Pointer
sfr  ZEROS                = 0xFF1C;       //Constant Value 0's Register
sfr  ONES                 = 0xFF1E;       //Constant Value 1's Register
sfr  MRW                  = 0xFFDA;       //MAC Repeat Word
sfr  MCW                  = 0xFFDC;       //MAC Control Word
sbit MCW_MS               = MCW^9;
sbit MCW_MP               = MCW^10;
sfr  MSW                  = 0xFFDE;       //MAC Unit Status Word
sbit MSW_MN               = MSW^8;
sbit MSW_MZ               = MSW^9;
sbit MSW_MC               = MSW^10;
sbit MSW_MSV              = MSW^11;
sbit MSW_ME               = MSW^12;
sbit MSW_MSL              = MSW^13;
sbit MSW_MV               = MSW^14;

/* GPT12 */
sfr  GPT12E_T2            = 0xFE40;       //GPT1 Timer 2 Register
sfr  GPT12E_T3            = 0xFE42;       //GPT1 Timer 3 Register
sfr  GPT12E_T4            = 0xFE44;       //GPT1 Timer 4 Register
sfr  GPT12E_T5            = 0xFE46;       //GPT2 Timer 5 Register
sfr  GPT12E_T6            = 0xFE48;       //GPT2 Timer 6 Register
sfr  GPT12E_CAPREL        = 0xFE4A;       //GPT12 Capture/Reload Register
sfr  GPT12E_T2CON         = 0xFF40;       //GPT1 Timer 2 Control Register
sbit GPT12E_T2CON_T2R     = GPT12E_T2CON^6;
sbit GPT12E_T2CON_T2UD    = GPT12E_T2CON^7;
sbit GPT12E_T2CON_T2UDE   = GPT12E_T2CON^8;
sbit GPT12E_T2CON_T2RC    = GPT12E_T2CON^9;
sbit GPT12E_T2CON_T2IRDIS = GPT12E_T2CON^12;
sbit GPT12E_T2CON_T2EDGE  = GPT12E_T2CON^13;
sbit GPT12E_T2CON_T2CHDIR = GPT12E_T2CON^14;
sbit GPT12E_T2CON_T2RDIR  = GPT12E_T2CON^15;
sfr  GPT12E_T3CON         = 0xFF42;       //GPT1 Timer 3 Control Register
sbit GPT12E_T3CON_T3R     = GPT12E_T3CON^6;
sbit GPT12E_T3CON_T3UD    = GPT12E_T3CON^7;
sbit GPT12E_T3CON_T3UDE   = GPT12E_T3CON^8;
sbit GPT12E_T3CON_T3OE    = GPT12E_T3CON^9;
sbit GPT12E_T3CON_T3OTL   = GPT12E_T3CON^10;
sbit GPT12E_T3CON_T3EDGE  = GPT12E_T3CON^13;
sbit GPT12E_T3CON_T3CHDIR = GPT12E_T3CON^14;
sbit GPT12E_T3CON_T3RDIR  = GPT12E_T3CON^15;
sfr  GPT12E_T4CON         = 0xFF44;       //GPT1 Timer 4 Control Register
sbit GPT12E_T4CON_T4R     = GPT12E_T4CON^6;
sbit GPT12E_T4CON_T4UD    = GPT12E_T4CON^7;
sbit GPT12E_T4CON_T4UDE   = GPT12E_T4CON^8;
sbit GPT12E_T4CON_T4RC    = GPT12E_T4CON^9;
sbit GPT12E_T4CON_T4IRDIS = GPT12E_T4CON^12;
sbit GPT12E_T4CON_T4EDGE  = GPT12E_T4CON^13;
sbit GPT12E_T4CON_T4CHDIR = GPT12E_T4CON^14;
sbit GPT12E_T4CON_T4RDIR  = GPT12E_T4CON^15;
sfr  GPT12E_T5CON         = 0xFF46;       //GPT2 Timer 5 Control Register
sbit GPT12E_T5CON_T5R     = GPT12E_T5CON^6;
sbit GPT12E_T5CON_T5UD    = GPT12E_T5CON^7;
sbit GPT12E_T5CON_T5UDE   = GPT12E_T5CON^8;
sbit GPT12E_T5CON_T5RC    = GPT12E_T5CON^9;
sbit GPT12E_T5CON_CT3     = GPT12E_T5CON^10;
sbit GPT12E_T5CON_T5CC    = GPT12E_T5CON^11;
sbit GPT12E_T5CON_T5CLR   = GPT12E_T5CON^14;
sbit GPT12E_T5CON_T5SC    = GPT12E_T5CON^15;
sfr  GPT12E_T6CON         = 0xFF48;       //GPT2 Timer 6 Control Register
sbit GPT12E_T6CON_T6R     = GPT12E_T6CON^6;
sbit GPT12E_T6CON_T6UD    = GPT12E_T6CON^7;
sbit GPT12E_T6CON_T6UDE   = GPT12E_T6CON^8;
sbit GPT12E_T6CON_T6OE    = GPT12E_T6CON^9;
sbit GPT12E_T6CON_T6OTL   = GPT12E_T6CON^10;
sbit GPT12E_T6CON_T6CLR   = GPT12E_T6CON^14;
sbit GPT12E_T6CON_T6SR    = GPT12E_T6CON^15;
#define GPT12E_ID  (*((unsigned int volatile sdata *) 0xFFE6))     //GPT Identification Register

/* IC */
sfr  CAN_1IC              = 0xF142;       //CAN Mode 1 Interrupt Control register
sbit CAN_1IC_IE           = CAN_1IC^6;
sbit CAN_1IC_IR           = CAN_1IC^7;
sbit CAN_1IC_GPX          = CAN_1IC^8;
sfr  CAN_2IC              = 0xF144;       //CAN Mode 2 Interrupt Control register
sbit CAN_2IC_IE           = CAN_2IC^6;
sbit CAN_2IC_IR           = CAN_2IC^7;
sbit CAN_2IC_GPX          = CAN_2IC^8;
sfr  CAN_3IC              = 0xF146;       //CAN Mode 3 Interrupt Control register
sbit CAN_3IC_IE           = CAN_3IC^6;
sbit CAN_3IC_IR           = CAN_3IC^7;
sbit CAN_3IC_GPX          = CAN_3IC^8;
sfr  CAN_4IC              = 0xF148;       //CAN Mode 4 Interrupt Control register
sbit CAN_4IC_IE           = CAN_4IC^6;
sbit CAN_4IC_IR           = CAN_4IC^7;
sbit CAN_4IC_GPX          = CAN_4IC^8;
sfr  CAN_5IC              = 0xF14A;       //CAN Mode 5 Interrupt Control register
sbit CAN_5IC_IE           = CAN_5IC^6;
sbit CAN_5IC_IR           = CAN_5IC^7;
sbit CAN_5IC_GPX          = CAN_5IC^8;
sfr  CAN_6IC              = 0xF14C;       //CAN Mode 6 Interrupt Control register
sbit CAN_6IC_IE           = CAN_6IC^6;
sbit CAN_6IC_IR           = CAN_6IC^7;
sbit CAN_6IC_GPX          = CAN_6IC^8;
sfr  CAN_7IC              = 0xF14E;       //CAN Mode 7 Interrupt Control register
sbit CAN_7IC_IE           = CAN_7IC^6;
sbit CAN_7IC_IR           = CAN_7IC^7;
sbit CAN_7IC_GPX          = CAN_7IC^8;
sfr  ASC0_ABIC            = 0xF15C;       //ASC0 Autobaud Interrupt Control Register
sbit ASC0_ABIC_IE         = ASC0_ABIC^6;
sbit ASC0_ABIC_IR         = ASC0_ABIC^7;
sbit ASC0_ABIC_GPX        = ASC0_ABIC^8;
sfr  CC2_CC16IC           = 0xF160;       //CAPCOM Channel 16 Interrupt Control Register
sbit CC2_CC16IC_IE        = CC2_CC16IC^6;
sbit CC2_CC16IC_IR        = CC2_CC16IC^7;
sbit CC2_CC16IC_GPX       = CC2_CC16IC^8;
sfr  CC2_CC17IC           = 0xF162;       //CAPCOM Channel 17 Interrupt Control Register
sbit CC2_CC17IC_IE        = CC2_CC17IC^6;
sbit CC2_CC17IC_IR        = CC2_CC17IC^7;
sbit CC2_CC17IC_GPX       = CC2_CC17IC^8;
sfr  CC2_CC18IC           = 0xF164;       //CAPCOM Channel 18 Interrupt Control Register
sbit CC2_CC18IC_IE        = CC2_CC18IC^6;
sbit CC2_CC18IC_IR        = CC2_CC18IC^7;
sbit CC2_CC18IC_GPX       = CC2_CC18IC^8;
sfr  CC2_CC19IC           = 0xF166;       //CAPCOM Channel 19 Interrupt Control Register
sbit CC2_CC19IC_IE        = CC2_CC19IC^6;
sbit CC2_CC19IC_IR        = CC2_CC19IC^7;
sbit CC2_CC19IC_GPX       = CC2_CC19IC^8;
sfr  CC2_CC20IC           = 0xF168;       //CAPCOM Channel 20 Interrupt Control Register
sbit CC2_CC20IC_IE        = CC2_CC20IC^6;
sbit CC2_CC20IC_IR        = CC2_CC20IC^7;
sbit CC2_CC20IC_GPX       = CC2_CC20IC^8;
sfr  CC2_CC21IC           = 0xF16A;       //CAPCOM Channel 21 Interrupt Control Register
sbit CC2_CC21IC_IE        = CC2_CC21IC^6;
sbit CC2_CC21IC_IR        = CC2_CC21IC^7;
sbit CC2_CC21IC_GPX       = CC2_CC21IC^8;
sfr  CC2_CC22IC           = 0xF16C;       //CAPCOM Channel 22 Interrupt Control Register
sbit CC2_CC22IC_IE        = CC2_CC22IC^6;
sbit CC2_CC22IC_IR        = CC2_CC22IC^7;
sbit CC2_CC22IC_GPX       = CC2_CC22IC^8;
sfr  CC2_CC23IC           = 0xF16E;       //CAPCOM Channel 23 Interrupt Control Register
sbit CC2_CC23IC_IE        = CC2_CC23IC^6;
sbit CC2_CC23IC_IR        = CC2_CC23IC^7;
sbit CC2_CC23IC_GPX       = CC2_CC23IC^8;
sfr  CC2_CC24IC           = 0xF170;       //CAPCOM Channel 24 Interrupt Control Register
sbit CC2_CC24IC_IE        = CC2_CC24IC^6;
sbit CC2_CC24IC_IR        = CC2_CC24IC^7;
sbit CC2_CC24IC_GPX       = CC2_CC24IC^8;
sfr  CC2_CC25IC           = 0xF172;       //CAPCOM Channel 25 Interrupt Control Register
sbit CC2_CC25IC_IE        = CC2_CC25IC^6;
sbit CC2_CC25IC_IR        = CC2_CC25IC^7;
sbit CC2_CC25IC_GPX       = CC2_CC25IC^8;
sfr  CC2_CC26IC           = 0xF174;       //CAPCOM Channel 26 Interrupt Control Register
sbit CC2_CC26IC_IE        = CC2_CC26IC^6;
sbit CC2_CC26IC_IR        = CC2_CC26IC^7;
sbit CC2_CC26IC_GPX       = CC2_CC26IC^8;
sfr  CC2_CC27IC           = 0xF176;       //CAPCOM Channel 27 Interrupt Control Register
sbit CC2_CC27IC_IE        = CC2_CC27IC^6;
sbit CC2_CC27IC_IR        = CC2_CC27IC^7;
sbit CC2_CC27IC_GPX       = CC2_CC27IC^8;
sfr  CC2_CC28IC           = 0xF178;       //CAPCOM Channel 28 Interrupt Control Register
sbit CC2_CC28IC_IE        = CC2_CC28IC^6;
sbit CC2_CC28IC_IR        = CC2_CC28IC^7;
sbit CC2_CC28IC_GPX       = CC2_CC28IC^8;
sfr  CC2_T7IC             = 0xF17A;       //CAPCOM 2 Timer 7 Interrupt Control Register
sbit CC2_T7IC_IE          = CC2_T7IC^6;
sbit CC2_T7IC_IR          = CC2_T7IC^7;
sbit CC2_T7IC_GPX         = CC2_T7IC^8;
sfr  CC2_T8IC             = 0xF17C;       //CAPCOM 2 Timer 8 Interrupt Control Register
sbit CC2_T8IC_IE          = CC2_T8IC^6;
sbit CC2_T8IC_IR          = CC2_T8IC^7;
sbit CC2_T8IC_GPX         = CC2_T8IC^8;
sfr  EOPIC                = 0xF180;       //Interrupt Control Register
sbit EOPIC_IE             = EOPIC^6;
sbit EOPIC_IR             = EOPIC^7;
sbit EOPIC_GPX            = EOPIC^8;
sfr  CC2_CC29IC           = 0xF184;       //CAPCOM Channel 29 Interrupt Control Register
sbit CC2_CC29IC_IE        = CC2_CC29IC^6;
sbit CC2_CC29IC_IR        = CC2_CC29IC^7;
sbit CC2_CC29IC_GPX       = CC2_CC29IC^8;
sfr  CC2_CC30IC           = 0xF18C;       //CAPCOM Channel 30 Interrupt Control Register
sbit CC2_CC30IC_IE        = CC2_CC30IC^6;
sbit CC2_CC30IC_IR        = CC2_CC30IC^7;
sbit CC2_CC30IC_GPX       = CC2_CC30IC^8;
sfr  CC2_CC31IC           = 0xF194;       //CAPCOM Channel 31 Interrupt Control Register
sbit CC2_CC31IC_IE        = CC2_CC31IC^6;
sbit CC2_CC31IC_IR        = CC2_CC31IC^7;
sbit CC2_CC31IC_GPX       = CC2_CC31IC^8;
sfr  CAN_0IC              = 0xF196;       //CAN Mode 0 Interrupt Control register
sbit CAN_0IC_IE           = CAN_0IC^6;
sbit CAN_0IC_IR           = CAN_0IC^7;
sbit CAN_0IC_GPX          = CAN_0IC^8;
sfr  SDLM_IC              = 0xF19A;       //SDLM Interrupt  Control Register
sbit SDLM_IC_IE           = SDLM_IC^6;
sbit SDLM_IC_IR           = SDLM_IC^7;
sbit SDLM_IC_GPX          = SDLM_IC^8;
sfr  ASC0_TBIC            = 0xF19C;       //ASC0 Transmit Buffer Interrupt Control Register
sbit ASC0_TBIC_IE         = ASC0_TBIC^6;
sbit ASC0_TBIC_IR         = ASC0_TBIC^7;
sbit ASC0_TBIC_GPX        = ASC0_TBIC^8;
sfr  PLLIC                = 0xF19E;       //PLL Interrupt Control Register
sbit PLLIC_IE             = PLLIC^6;
sbit PLLIC_IR             = PLLIC^7;
sbit PLLIC_GPX            = PLLIC^8;
sfr  RTC_IC               = 0xF1A0;       //RTC Interrupt Control Register
sbit RTC_IC_IE            = RTC_IC^6;
sbit RTC_IC_IR            = RTC_IC^7;
sbit RTC_IC_GPX           = RTC_IC^8;
sfr  SSC1_TIC             = 0xF1AA;       //SSC1 Transmit Interrupt Control Register
sbit SSC1_TIC_IE          = SSC1_TIC^6;
sbit SSC1_TIC_IR          = SSC1_TIC^7;
sbit SSC1_TIC_GPX         = SSC1_TIC^8;
sfr  SSC1_RIC             = 0xF1AC;       //SSC1 Receive Interrupt Control Register
sbit SSC1_RIC_IE          = SSC1_RIC^6;
sbit SSC1_RIC_IR          = SSC1_RIC^7;
sbit SSC1_RIC_GPX         = SSC1_RIC^8;
sfr  SSC1_EIC             = 0xF1AE;       //SSC Error Interrupt Control Register
sbit SSC1_EIC_IE          = SSC1_EIC^6;
sbit SSC1_EIC_IR          = SSC1_EIC^7;
sbit SSC1_EIC_GPX         = SSC1_EIC^8;
sfr  EXICON               = 0xF1C0;       //External Interrupt Control Register
sfr  GPT12E_T2IC          = 0xFF60;       //GPT1 Timer 2 Interrupt Control Register
sbit GPT12E_T2IC_IE       = GPT12E_T2IC^6;
sbit GPT12E_T2IC_IR       = GPT12E_T2IC^7;
sbit GPT12E_T2IC_GPX      = GPT12E_T2IC^8;
sfr  GPT12E_T3IC          = 0xFF62;       //GPT1 Timer 3 Interrupt Control Register
sbit GPT12E_T3IC_IE       = GPT12E_T3IC^6;
sbit GPT12E_T3IC_IR       = GPT12E_T3IC^7;
sbit GPT12E_T3IC_GPX      = GPT12E_T3IC^8;
sfr  GPT12E_T4IC          = 0xFF64;       //GPT1 Timer 4 Interrupt Control Register
sbit GPT12E_T4IC_IE       = GPT12E_T4IC^6;
sbit GPT12E_T4IC_IR       = GPT12E_T4IC^7;
sbit GPT12E_T4IC_GPX      = GPT12E_T4IC^8;
sfr  GPT12E_T5IC          = 0xFF66;       //GPT2 Timer 5 Interrupt Control Register
sbit GPT12E_T5IC_IE       = GPT12E_T5IC^6;
sbit GPT12E_T5IC_IR       = GPT12E_T5IC^7;
sbit GPT12E_T5IC_GPX      = GPT12E_T5IC^8;
sfr  GPT12E_T6IC          = 0xFF68;       //GPT2 Timer 6 Interrupt Control Register
sbit GPT12E_T6IC_IE       = GPT12E_T6IC^6;
sbit GPT12E_T6IC_IR       = GPT12E_T6IC^7;
sbit GPT12E_T6IC_GPX      = GPT12E_T6IC^8;
sfr  GPT12E_CRIC          = 0xFF6A;       //GPT2 CAPREL Interrupt Control Register
sbit GPT12E_CRIC_IE       = GPT12E_CRIC^6;
sbit GPT12E_CRIC_IR       = GPT12E_CRIC^7;
sbit GPT12E_CRIC_GPX      = GPT12E_CRIC^8;
sfr  ASC0_TIC             = 0xFF6C;       //ASC0 Transmit Interrupt Control Register
sbit ASC0_TIC_IE          = ASC0_TIC^6;
sbit ASC0_TIC_IR          = ASC0_TIC^7;
sbit ASC0_TIC_GPX         = ASC0_TIC^8;
sfr  ASC0_RIC             = 0xFF6E;       //ASC0 Receive Interrupt Control Register
sbit ASC0_RIC_IE          = ASC0_RIC^6;
sbit ASC0_RIC_IR          = ASC0_RIC^7;
sbit ASC0_RIC_GPX         = ASC0_RIC^8;
sfr  ASC0_EIC             = 0xFF70;       //ASC0 Error Interrupt Control Register
sbit ASC0_EIC_IE          = ASC0_EIC^6;
sbit ASC0_EIC_IR          = ASC0_EIC^7;
sbit ASC0_EIC_GPX         = ASC0_EIC^8;
sfr  SSC0_TIC             = 0xFF72;       //SSC0 Transmit Interrupt Control Register
sbit SSC0_TIC_IE          = SSC0_TIC^6;
sbit SSC0_TIC_IR          = SSC0_TIC^7;
sbit SSC0_TIC_GPX         = SSC0_TIC^8;
sfr  SSC0_RIC             = 0xFF74;       //SSC0 Receive Interrupt Control Register
sbit SSC0_RIC_IE          = SSC0_RIC^6;
sbit SSC0_RIC_IR          = SSC0_RIC^7;
sbit SSC0_RIC_GPX         = SSC0_RIC^8;
sfr  SSC0_EIC             = 0xFF76;       //SSC0 Error Interrupt Control Register
sbit SSC0_EIC_IE          = SSC0_EIC^6;
sbit SSC0_EIC_IR          = SSC0_EIC^7;
sbit SSC0_EIC_GPX         = SSC0_EIC^8;
sfr  CC1_CC0IC            = 0xFF78;       //CAPCOM Channel 0 Interrupt Control Register
sbit CC1_CC0IC_IE         = CC1_CC0IC^6;
sbit CC1_CC0IC_IR         = CC1_CC0IC^7;
sbit CC1_CC0IC_GPX        = CC1_CC0IC^8;
sfr  CC1_CC1IC            = 0xFF7A;       //CAPCOM Channel 1 Interrupt Control Register
sbit CC1_CC1IC_IE         = CC1_CC1IC^6;
sbit CC1_CC1IC_IR         = CC1_CC1IC^7;
sbit CC1_CC1IC_GPX        = CC1_CC1IC^8;
sfr  CC1_CC2IC            = 0xFF7C;       //CAPCOM Channel 2 Interrupt Control Register
sbit CC1_CC2IC_IE         = CC1_CC2IC^6;
sbit CC1_CC2IC_IR         = CC1_CC2IC^7;
sbit CC1_CC2IC_GPX        = CC1_CC2IC^8;
sfr  CC1_CC3IC            = 0xFF7E;       //CAPCOM Channel 3 Interrupt Control Register
sbit CC1_CC3IC_IE         = CC1_CC3IC^6;
sbit CC1_CC3IC_IR         = CC1_CC3IC^7;
sbit CC1_CC3IC_GPX        = CC1_CC3IC^8;
sfr  CC1_CC4IC            = 0xFF80;       //CAPCOM Channel 4 Interrupt Control Register
sbit CC1_CC4IC_IE         = CC1_CC4IC^6;
sbit CC1_CC4IC_IR         = CC1_CC4IC^7;
sbit CC1_CC4IC_GPX        = CC1_CC4IC^8;
sfr  CC1_CC5IC            = 0xFF82;       //CAPCOM Channel 5 Interrupt Control Register
sbit CC1_CC5IC_IE         = CC1_CC5IC^6;
sbit CC1_CC5IC_IR         = CC1_CC5IC^7;
sbit CC1_CC5IC_GPX        = CC1_CC5IC^8;
sfr  CC1_CC6IC            = 0xFF84;       //CAPCOM Channel 6 Interrupt Control Register
sbit CC1_CC6IC_IE         = CC1_CC6IC^6;
sbit CC1_CC6IC_IR         = CC1_CC6IC^7;
sbit CC1_CC6IC_GPX        = CC1_CC6IC^8;
sfr  CC1_CC7IC            = 0xFF86;       //CC Register 7 Interrupt Control Register
sbit CC1_CC7IC_IE         = CC1_CC7IC^6;
sbit CC1_CC7IC_IR         = CC1_CC7IC^7;
sbit CC1_CC7IC_GPX        = CC1_CC7IC^8;
sfr  CC1_CC8IC            = 0xFF88;       //CC Register 8 Interrupt Control Register
sbit CC1_CC8IC_IE         = CC1_CC8IC^6;
sbit CC1_CC8IC_IR         = CC1_CC8IC^7;
sbit CC1_CC8IC_GPX        = CC1_CC8IC^8;
sfr  CC1_CC9IC            = 0xFF8A;       //CC Register 9 Interrupt Control Register
sbit CC1_CC9IC_IE         = CC1_CC9IC^6;
sbit CC1_CC9IC_IR         = CC1_CC9IC^7;
sbit CC1_CC9IC_GPX        = CC1_CC9IC^8;
sfr  CC1_CC10IC           = 0xFF8C;       //CAPCOM Channel 10 Interrupt Control Register
sbit CC1_CC10IC_IE        = CC1_CC10IC^6;
sbit CC1_CC10IC_IR        = CC1_CC10IC^7;
sbit CC1_CC10IC_GPX       = CC1_CC10IC^8;
sfr  CC1_CC11IC           = 0xFF8E;       //CAPCOM Channel 11 Interrupt Control Register
sbit CC1_CC11IC_IE        = CC1_CC11IC^6;
sbit CC1_CC11IC_IR        = CC1_CC11IC^7;
sbit CC1_CC11IC_GPX       = CC1_CC11IC^8;
sfr  CC1_CC12IC           = 0xFF90;       //CAPCOM Channel 12 Interrupt Control Register
sbit CC1_CC12IC_IE        = CC1_CC12IC^6;
sbit CC1_CC12IC_IR        = CC1_CC12IC^7;
sbit CC1_CC12IC_GPX       = CC1_CC12IC^8;
sfr  CC1_CC13IC           = 0xFF92;       //CAPCOM Channel 13 Interrupt Control Register
sbit CC1_CC13IC_IE        = CC1_CC13IC^6;
sbit CC1_CC13IC_IR        = CC1_CC13IC^7;
sbit CC1_CC13IC_GPX       = CC1_CC13IC^8;
sfr  CC1_CC14IC           = 0xFF94;       //CAPCOM Channel 14 Interrupt Control Register
sbit CC1_CC14IC_IE        = CC1_CC14IC^6;
sbit CC1_CC14IC_IR        = CC1_CC14IC^7;
sbit CC1_CC14IC_GPX       = CC1_CC14IC^8;
sfr  CC1_CC15IC           = 0xFF96;       //CAPCOM Channel 15 Interrupt Control Register
sbit CC1_CC15IC_IE        = CC1_CC15IC^6;
sbit CC1_CC15IC_IR        = CC1_CC15IC^7;
sbit CC1_CC15IC_GPX       = CC1_CC15IC^8;
sfr  ADC_CIC              = 0xFF98;       //ADC End of Conversion Interrupt Control Register
sbit ADC_CIC_IE           = ADC_CIC^6;
sbit ADC_CIC_IR           = ADC_CIC^7;
sbit ADC_CIC_GPX          = ADC_CIC^8;
sfr  ADC_EIC              = 0xFF9A;       //ADC Overrun Error Control Register
sbit ADC_EIC_IE           = ADC_EIC^6;
sbit ADC_EIC_IR           = ADC_EIC^7;
sbit ADC_EIC_GPX          = ADC_EIC^8;
sfr  CC1_T0IC             = 0xFF9C;       //CAPCOM 1 Timer 0 Interrupt Control Register
sbit CC1_T0IC_IE          = CC1_T0IC^6;
sbit CC1_T0IC_IR          = CC1_T0IC^7;
sbit CC1_T0IC_GPX         = CC1_T0IC^8;
sfr  CC1_T1IC             = 0xFF9E;       //CC Timer 1 Interrupt Control Register
sbit CC1_T1IC_IE          = CC1_T1IC^6;
sbit CC1_T1IC_IR          = CC1_T1IC^7;
sbit CC1_T1IC_GPX         = CC1_T1IC^8;

/* LONDONCORE */
sfr  TFR                  = 0xFFAC;       //Trap Flag Register
sbit TFR_ILLOPA           = TFR^2;
sbit TFR_PRTFLT           = TFR^3;
sbit TFR_PACER            = TFR^4;
sbit TFR_UNDOPC           = TFR^7;
sbit TFR_SOFTBRK          = TFR^12;
sbit TFR_STKUF            = TFR^13;
sbit TFR_STKOF            = TFR^14;
sbit TFR_NMI              = TFR^15;

/* MAC */
sfr  QX0                  = 0xF000;       //Offset Register
sfr  QX1                  = 0xF002;       //Offset Register
sfr  QR0                  = 0xF004;       //Offset Register
sfr  QR1                  = 0xF006;       //Offset Register

/* PEC */
sfr  PECC0                = 0xFEC0;       //PEC Channel 0 Control Register
sfr  PECC1                = 0xFEC2;       //PEC Channel 1 Control Register
sfr  PECC2                = 0xFEC4;       //PEC Channel 2 Control Register
sfr  PECC3                = 0xFEC6;       //PEC Channel 3 Control Register
sfr  PECC4                = 0xFEC8;       //PEC Channel 4 Control Register
sfr  PECC5                = 0xFECA;       //PEC Channel 5 Control Register
sfr  PECC6                = 0xFECC;       //PEC Channel 6 Control Register
sfr  PECC7                = 0xFECE;       //PEC Channel 7 Control Register
sfr  PECISNC              = 0xFFA8;       //PEC Interrupt Subnode Control Register
sbit PECISNC_C0IE         = PECISNC^0;
sbit PECISNC_C0IR         = PECISNC^1;
sbit PECISNC_C1IE         = PECISNC^2;
sbit PECISNC_C1IR         = PECISNC^3;
sbit PECISNC_C2IE         = PECISNC^4;
sbit PECISNC_C2IR         = PECISNC^5;
sbit PECISNC_C3IE         = PECISNC^6;
sbit PECISNC_C3IR         = PECISNC^7;
sbit PECISNC_C4IE         = PECISNC^8;
sbit PECISNC_C4IR         = PECISNC^9;
sbit PECISNC_C5IE         = PECISNC^10;
sbit PECISNC_C5IR         = PECISNC^11;
sbit PECISNC_C6IE         = PECISNC^12;
sbit PECISNC_C6IR         = PECISNC^13;
sbit PECISNC_C7IE         = PECISNC^14;
sbit PECISNC_C7IR         = PECISNC^15;

/* PORT */
sfr  POCON0L              = 0xF080;       //Port P0L Output Control Register
sfr  POCON0H              = 0xF082;       //Port P0H Output Control Register
sfr  POCON1L              = 0xF084;       //Port P1L Output Control Register
sfr  POCON1H              = 0xF086;       //Port P1H Output Control Register
sfr  POCON3               = 0xF08A;       //Port P3 Output Control Port
sfr  POCON4               = 0xF08C;       //Port P4 Output Control Port
sfr  POCON9               = 0xF094;       //Port 9 Output Control Register
sfr  POCON20              = 0xF0AA;       //Dedicated Pin Output Control Register
sfr  DP0L                 = 0xF100;       //P0L Direction Control Register
sbit DP0L_P0              = DP0L^0;
sbit DP0L_P1              = DP0L^1;
sbit DP0L_P2              = DP0L^2;
sbit DP0L_P3              = DP0L^3;
sbit DP0L_P4              = DP0L^4;
sbit DP0L_P5              = DP0L^5;
sbit DP0L_P6              = DP0L^6;
sbit DP0L_P7              = DP0L^7;
sfr  DP0H                 = 0xF102;       //P0H Direction Control Register
sbit DP0H_P0              = DP0H^0;
sbit DP0H_P1              = DP0H^1;
sbit DP0H_P2              = DP0H^2;
sbit DP0H_P3              = DP0H^3;
sbit DP0H_P4              = DP0H^4;
sbit DP0H_P5              = DP0H^5;
sbit DP0H_P6              = DP0H^6;
sbit DP0H_P7              = DP0H^7;
sfr  DP1L                 = 0xF104;       //P1L Direction Control Register
sbit DP1L_P0              = DP1L^0;
sbit DP1L_P1              = DP1L^1;
sbit DP1L_P2              = DP1L^2;
sbit DP1L_P3              = DP1L^3;
sbit DP1L_P4              = DP1L^4;
sbit DP1L_P5              = DP1L^5;
sbit DP1L_P6              = DP1L^6;
sbit DP1L_P7              = DP1L^7;
sfr  DP1H                 = 0xF106;       //P1H Direction Control Register
sbit DP1H_P0              = DP1H^0;
sbit DP1H_P1              = DP1H^1;
sbit DP1H_P2              = DP1H^2;
sbit DP1H_P3              = DP1H^3;
sbit DP1H_P4              = DP1H^4;
sbit DP1H_P5              = DP1H^5;
sbit DP1H_P6              = DP1H^6;
sbit DP1H_P7              = DP1H^7;
sfr  ALTSEL0P1H           = 0xF120;       //Alternate I/O Source 0 Port P1H
sbit ALTSEL0P1H_P0        = ALTSEL0P1H^0;
sbit ALTSEL0P1H_P1        = ALTSEL0P1H^1;
sbit ALTSEL0P1H_P2        = ALTSEL0P1H^2;
sbit ALTSEL0P1H_P3        = ALTSEL0P1H^3;
sbit ALTSEL0P1H_P4        = ALTSEL0P1H^4;
sbit ALTSEL0P1H_P5        = ALTSEL0P1H^5;
sbit ALTSEL0P1H_P6        = ALTSEL0P1H^6;
sbit ALTSEL0P1H_P7        = ALTSEL0P1H^7;
sfr  ALTSEL0P3            = 0xF126;       //Alternate I/O Source Port 3 Selection
sbit ALTSEL0P3_P1         = ALTSEL0P3^1;
sbit ALTSEL0P3_P3         = ALTSEL0P3^3;
sbit ALTSEL0P3_P5         = ALTSEL0P3^5;
sbit ALTSEL0P3_P8         = ALTSEL0P3^8;
sbit ALTSEL0P3_P9         = ALTSEL0P3^9;
sbit ALTSEL0P3_P10        = ALTSEL0P3^10;
sbit ALTSEL0P3_P11        = ALTSEL0P3^11;
sbit ALTSEL0P3_P13        = ALTSEL0P3^13;
sfr  ALTSEL1P3            = 0xF128;       //Alternate I/O Source 1 Port P3
sbit ALTSEL1P3_P1         = ALTSEL1P3^1;
sfr  ALTSEL0P4            = 0xF12A;       //Alternate I/O Source 0 Port P4
sbit ALTSEL0P4_P6         = ALTSEL0P4^6;
sbit ALTSEL0P4_P7         = ALTSEL0P4^7;
sfr  ALTSEL0P1L           = 0xF130;       //P1L Alternate Select Register 0
sbit ALTSEL0P1L_P0        = ALTSEL0P1L^0;
sbit ALTSEL0P1L_P1        = ALTSEL0P1L^1;
sbit ALTSEL0P1L_P2        = ALTSEL0P1L^2;
sbit ALTSEL0P1L_P3        = ALTSEL0P1L^3;
sbit ALTSEL0P1L_P4        = ALTSEL0P1L^4;
sbit ALTSEL0P1L_P5        = ALTSEL0P1L^5;
sbit ALTSEL0P1L_P6        = ALTSEL0P1L^6;
sbit ALTSEL0P1L_P7        = ALTSEL0P1L^7;
sfr  ALTSEL1P4            = 0xF136;       //Alternate I/O Source 1 Port P4
sbit ALTSEL1P4_P7         = ALTSEL1P4^7;
sfr  ALTSEL0P9            = 0xF138;       //Alternate I/O Source 0 Port P9
sbit ALTSEL0P9_P0         = ALTSEL0P9^0;
sbit ALTSEL0P9_P1         = ALTSEL0P9^1;
sbit ALTSEL0P9_P2         = ALTSEL0P9^2;
sbit ALTSEL0P9_P3         = ALTSEL0P9^3;
sbit ALTSEL0P9_P4         = ALTSEL0P9^4;
sbit ALTSEL0P9_P5         = ALTSEL0P9^5;
sfr  ALTSEL1P9            = 0xF13A;       //Alternate I/O Source 1 Port P9
sbit ALTSEL1P9_P0         = ALTSEL1P9^0;
sbit ALTSEL1P9_P1         = ALTSEL1P9^1;
sbit ALTSEL1P9_P2         = ALTSEL1P9^2;
sbit ALTSEL1P9_P3         = ALTSEL1P9^3;
sbit ALTSEL1P9_P4         = ALTSEL1P9^4;
sbit ALTSEL1P9_P5         = ALTSEL1P9^5;
sfr  PICON                = 0xF1C4;       //Port Input Control Register
sbit PICON_P3LIN          = PICON^2;
sbit PICON_P3HIN          = PICON^3;
sbit PICON_P4LIN          = PICON^4;
sbit PICON_P9LIN          = PICON^7;
sbit PICON_P20LIN         = PICON^8;
sbit PICON_P20HIN         = PICON^9;
sfr  ODP3                 = 0xF1C6;       //Port 3 Open Drain Control Register
sbit ODP3_P0              = ODP3^0;
sbit ODP3_P1              = ODP3^1;
sbit ODP3_P2              = ODP3^2;
sbit ODP3_P3              = ODP3^3;
sbit ODP3_P4              = ODP3^4;
sbit ODP3_P5              = ODP3^5;
sbit ODP3_P6              = ODP3^6;
sbit ODP3_P7              = ODP3^7;
sbit ODP3_P8              = ODP3^8;
sbit ODP3_P9              = ODP3^9;
sbit ODP3_P10             = ODP3^10;
sbit ODP3_P11             = ODP3^11;
sbit ODP3_P13             = ODP3^13;
sfr  ODP4                 = 0xF1CA;       //Port 4 Open Drain Control Register
sbit ODP4_P0              = ODP4^0;
sbit ODP4_P1              = ODP4^1;
sbit ODP4_P2              = ODP4^2;
sbit ODP4_P3              = ODP4^3;
sbit ODP4_P4              = ODP4^4;
sbit ODP4_P5              = ODP4^5;
sbit ODP4_P6              = ODP4^6;
sbit ODP4_P7              = ODP4^7;
sfr  P0L                  = 0xFF00;       //PORT0 Low Register
sbit P0L_P0               = P0L^0;
sbit P0L_P1               = P0L^1;
sbit P0L_P2               = P0L^2;
sbit P0L_P3               = P0L^3;
sbit P0L_P4               = P0L^4;
sbit P0L_P5               = P0L^5;
sbit P0L_P6               = P0L^6;
sbit P0L_P7               = P0L^7;
sfr  P0H                  = 0xFF02;       //Port 0 High Register (Upper half of Port 0)
sbit P0H_P0               = P0H^0;
sbit P0H_P1               = P0H^1;
sbit P0H_P2               = P0H^2;
sbit P0H_P3               = P0H^3;
sbit P0H_P4               = P0H^4;
sbit P0H_P5               = P0H^5;
sbit P0H_P6               = P0H^6;
sbit P0H_P7               = P0H^7;
sfr  P1L                  = 0xFF04;       //Port 1 Low Register
sbit P1L_P0               = P1L^0;
sbit P1L_P1               = P1L^1;
sbit P1L_P2               = P1L^2;
sbit P1L_P3               = P1L^3;
sbit P1L_P4               = P1L^4;
sbit P1L_P5               = P1L^5;
sbit P1L_P6               = P1L^6;
sbit P1L_P7               = P1L^7;
sfr  P1H                  = 0xFF06;       //Port 1 High Register
sbit P1H_P0               = P1H^0;
sbit P1H_P1               = P1H^1;
sbit P1H_P2               = P1H^2;
sbit P1H_P3               = P1H^3;
sbit P1H_P4               = P1H^4;
sbit P1H_P5               = P1H^5;
sbit P1H_P6               = P1H^6;
sbit P1H_P7               = P1H^7;
sfr  P9                   = 0xFF16;       //Port 9 Data Register
sbit P9_P0                = P9^0;
sbit P9_P1                = P9^1;
sbit P9_P2                = P9^2;
sbit P9_P3                = P9^3;
sbit P9_P4                = P9^4;
sbit P9_P5                = P9^5;
sfr  DP9                  = 0xFF18;       //Port 9 Direction Control Register
sbit DP9_P0               = DP9^0;
sbit DP9_P1               = DP9^1;
sbit DP9_P2               = DP9^2;
sbit DP9_P3               = DP9^3;
sbit DP9_P4               = DP9^4;
sbit DP9_P5               = DP9^5;
sfr  ODP9                 = 0xFF1A;       //Port 9 Open Drain Control Register
sbit ODP9_P0              = ODP9^0;
sbit ODP9_P1              = ODP9^1;
sbit ODP9_P2              = ODP9^2;
sbit ODP9_P3              = ODP9^3;
sbit ODP9_P4              = ODP9^4;
sbit ODP9_P5              = ODP9^5;
sfr  P5                   = 0xFFA2;       //Port 5 Data Register
sbit P5_P0                = P5^0;
sbit P5_P1                = P5^1;
sbit P5_P2                = P5^2;
sbit P5_P3                = P5^3;
sbit P5_P4                = P5^4;
sbit P5_P5                = P5^5;
sbit P5_P6                = P5^6;
sbit P5_P7                = P5^7;
sbit P5_P10               = P5^10;
sbit P5_P11               = P5^11;
sbit P5_P12               = P5^12;
sbit P5_P13               = P5^13;
sbit P5_P14               = P5^14;
sbit P5_P15               = P5^15;
sfr  P5DIDIS              = 0xFFA4;       //Port 5 Digital Inp. Disable Reg.
sbit P5DIDIS_P0           = P5DIDIS^0;
sbit P5DIDIS_P1           = P5DIDIS^1;
sbit P5DIDIS_P2           = P5DIDIS^2;
sbit P5DIDIS_P3           = P5DIDIS^3;
sbit P5DIDIS_P4           = P5DIDIS^4;
sbit P5DIDIS_P5           = P5DIDIS^5;
sbit P5DIDIS_P6           = P5DIDIS^6;
sbit P5DIDIS_P7           = P5DIDIS^7;
sbit P5DIDIS_P10          = P5DIDIS^10;
sbit P5DIDIS_P11          = P5DIDIS^11;
sbit P5DIDIS_P12          = P5DIDIS^12;
sbit P5DIDIS_P13          = P5DIDIS^13;
sbit P5DIDIS_P14          = P5DIDIS^14;
sbit P5DIDIS_P15          = P5DIDIS^15;
sfr  P20                  = 0xFFB4;       //Port 20 Data Register
sbit P20_P0               = P20^0;
sbit P20_P1               = P20^1;
sbit P20_P4               = P20^4;
sbit P20_P5               = P20^5;
sbit P20_P12              = P20^12;
sfr  DP20                 = 0xFFB6;       //Port 20 Direction Control Register
sbit DP20_P0              = DP20^0;
sbit DP20_P1              = DP20^1;
sbit DP20_P4              = DP20^4;
sbit DP20_P5              = DP20^5;
sbit DP20_P12             = DP20^12;
sfr  P3                   = 0xFFC4;       //Port 3 Data Register
sbit P3_P1                = P3^1;
sbit P3_P2                = P3^2;
sbit P3_P3                = P3^3;
sbit P3_P4                = P3^4;
sbit P3_P5                = P3^5;
sbit P3_P6                = P3^6;
sbit P3_P7                = P3^7;
sbit P3_P8                = P3^8;
sbit P3_P9                = P3^9;
sbit P3_P10               = P3^10;
sbit P3_P11               = P3^11;
sbit P3_P12               = P3^12;
sbit P3_P13               = P3^13;
sbit P3_P15               = P3^15;
sfr  DP3                  = 0xFFC6;       //Port 3 Direction Control Register
sbit DP3_P0               = DP3^0;
sbit DP3_P1               = DP3^1;
sbit DP3_P2               = DP3^2;
sbit DP3_P3               = DP3^3;
sbit DP3_P4               = DP3^4;
sbit DP3_P5               = DP3^5;
sbit DP3_P6               = DP3^6;
sbit DP3_P7               = DP3^7;
sbit DP3_P8               = DP3^8;
sbit DP3_P9               = DP3^9;
sbit DP3_P10              = DP3^10;
sbit DP3_P11              = DP3^11;
sbit DP3_P12              = DP3^12;
sbit DP3_P13              = DP3^13;
sbit DP3_P15              = DP3^15;
sfr  P4                   = 0xFFC8;       //Port 4 Data Register
sbit P4_P0                = P4^0;
sbit P4_P1                = P4^1;
sbit P4_P2                = P4^2;
sbit P4_P3                = P4^3;
sbit P4_P4                = P4^4;
sbit P4_P5                = P4^5;
sbit P4_P6                = P4^6;
sbit P4_P7                = P4^7;
sfr  DP4                  = 0xFFCA;       //Port 4 Direction Control Register
sbit DP4_P0               = DP4^0;
sbit DP4_P1               = DP4^1;
sbit DP4_P2               = DP4^2;
sbit DP4_P3               = DP4^3;
sbit DP4_P4               = DP4^4;
sbit DP4_P5               = DP4^5;
sbit DP4_P6               = DP4^6;
sbit DP4_P7               = DP4^7;

/* RTC */
sfr  RTC_RELL             = 0xF0CC;       //RTC Timer Reload Low Register
sfr  RTC_RELH             = 0xF0CE;       //RTC Timer Reload High Register
sfr  RTC_T14REL           = 0xF0D0;       //Timer 14 Reload Register
sfr  RTC_T14              = 0xF0D2;       //Timer 14 Register
sfr  RTC_RTCL             = 0xF0D4;       //RTC Timer Low Register
sfr  RTC_RTCH             = 0xF0D6;       //RTC Timer High Register
sfr  RTC_ISNC             = 0xF10C;       //Reload Register
sbit RTC_ISNC_T14IE       = RTC_ISNC^0;
sbit RTC_ISNC_T14IR       = RTC_ISNC^1;
sbit RTC_ISNC_CNT0IE      = RTC_ISNC^2;
sbit RTC_ISNC_CNT0IR      = RTC_ISNC^3;
sbit RTC_ISNC_CNT1IE      = RTC_ISNC^4;
sbit RTC_ISNC_CNT1IR      = RTC_ISNC^5;
sbit RTC_ISNC_CNT2IE      = RTC_ISNC^6;
sbit RTC_ISNC_CNT2IR      = RTC_ISNC^7;
sbit RTC_ISNC_CNT3IE      = RTC_ISNC^8;
sbit RTC_ISNC_CNT3IR      = RTC_ISNC^9;
sfr  RTC_CON              = 0xF110;       //Control Register
sbit RTC_CON_RUN          = RTC_CON^0;
sbit RTC_CON_PRE          = RTC_CON^1;
sbit RTC_CON_T14DEC       = RTC_CON^2;
sbit RTC_CON_T14INC       = RTC_CON^3;
sbit RTC_CON_REFCLK       = RTC_CON^4;
sbit RTC_CON_ACCPOS       = RTC_CON^15;
#define RTC_ID     (*((unsigned int volatile sdata *) 0xFFF8))     //RTC Identification Register

/* SCU */
sfr  IDRT                 = 0xF070;       //Identifier Silicon Correction
sfr  IDMEM2               = 0xF076;       //Identifier
sfr  IDPROG               = 0xF078;       //Identifier
sfr  IDMEM                = 0xF07A;       //Identifier
sfr  IDCHIP               = 0xF07C;       //Identifier
sfr  IDMANUF              = 0xF07E;       //Identifier
sfr  SCUSLC               = 0xF0C0;       //Security Level Command Register
sfr  SCUSLS               = 0xF0C2;       //Security Level Status Register
sfr  IMBCTR               = 0xF0FE;       //Instruction Memory Block Control Register
sfr  RSTCFG               = 0xF108;       //Reset Configuration Register
sbit RSTCFG_ROC           = RSTCFG^0;
sbit RSTCFG_ADP           = RSTCFG^1;
sbit RSTCFG_WRC           = RSTCFG^8;
sfr  SYSCON0              = 0xF1BE;       //General System Control Register
sbit SYSCON0_RTCCM        = SYSCON0^14;
sbit SYSCON0_RTCRST       = SYSCON0^15;
sfr  PLLCON               = 0xF1D0;       //PLL Control Register
sbit PLLCON_PLLCSF        = PLLCON^15;
sfr  SYSCON3              = 0xF1D4;       //CPU System Configuration Register 3
sbit SYSCON3_ADCDIS       = SYSCON3^0;
sbit SYSCON3_ASC0DIS      = SYSCON3^1;
sbit SYSCON3_SSC0DIS      = SYSCON3^2;
sbit SYSCON3_GPTDIS       = SYSCON3^3;
sbit SYSCON3_PFMDIS       = SYSCON3^5;
sbit SYSCON3_CC1DIS       = SYSCON3^6;
sbit SYSCON3_CC2DIS       = SYSCON3^7;
sbit SYSCON3_CC6DIS       = SYSCON3^8;
sbit SYSCON3_CANDIS       = SYSCON3^13;
sbit SYSCON3_SSC1DIS      = SYSCON3^15;
sfr  EXISEL1              = 0xF1D8;       //External Interrupt Input Select Register
sfr  EXISEL0              = 0xF1DA;       //External Interrupt Input Select Register
sfr  SYSCON1              = 0xF1DC;       //CPU System Configuration Register 1
#define RSTCON     (*((unsigned int volatile sdata *) 0xF1E0))     //Reset Control Register
#define RSTCON2    (*((unsigned int volatile sdata *) 0xF1E2))     //Reset Control Register 2
#define SYSSTAT    (*((unsigned int volatile sdata *) 0xF1E4))     //System Status Register
sfr  OPSEN                = 0xFE58;       //OCE/OCDS P-Susp. En. Reg
sfr  FOCON                = 0xFFAA;       //Frequency Output Control Register
sbit FOCON_FOTL           = FOCON^6;
sbit FOCON_CLKEN          = FOCON^7;
sbit FOCON_FOSS           = FOCON^14;
sbit FOCON_FOEN           = FOCON^15;
sfr  WDTCON               = 0xFFAE;       //Watchdog Timer Control Register

/* OCDS */
sfr  DTIDR                = 0xF0D8;       //Task ID register
sfr  DCMPSP               = 0xF0EC;       //Select and Programming Register for DCMPx
sfr  DCMPDP               = 0xF0EE;       //Data programming register for DCMPx
sfr  DTREVT               = 0xF0F0;       //Hardware Trigger Combination Debug Event Control Register
sfr  DEXEVT               = 0xF0F2;       //Break Pin Event Control Register
sfr  DSWEVT               = 0xF0F4;       //Software Debug Event Control Register
sfr  CMADR                = 0xF0F8;       //Call a monitor target address register
sfr  CMCTR                = 0xF0FA;       //Call a Monitor Control Register
sfr  DBGSR                = 0xF0FC;       //Debug Status Register

/* SSC0 */
sfr  SSC0_TB              = 0xF0B0;       //SSC Transmit Buffer (WO)
sfr  SSC0_RB              = 0xF0B2;       //SSC Receive Buffer (RO)
sfr  SSC0_BR              = 0xF0B4;       //SSC Baudrate Register
sfr  SSC0_CON             = 0xFFB2;       //SSC Control Register
sbit SSC0_CON_HB          = SSC0_CON^4;
sbit SSC0_CON_PH          = SSC0_CON^5;
sbit SSC0_CON_PO          = SSC0_CON^6;
sbit SSC0_CON_LB          = SSC0_CON^7;
sbit SSC0_CON_TEN         = SSC0_CON^8;
sbit SSC0_CON_TE          = SSC0_CON^8;
sbit SSC0_CON_REN         = SSC0_CON^9;
sbit SSC0_CON_RE          = SSC0_CON^9;
sbit SSC0_CON_PEN         = SSC0_CON^10;
sbit SSC0_CON_PE          = SSC0_CON^10;
sbit SSC0_CON_BEN         = SSC0_CON^11;
sbit SSC0_CON_BE          = SSC0_CON^11;
sbit SSC0_CON_AREN        = SSC0_CON^12;
sbit SSC0_CON_BSY         = SSC0_CON^12;
sbit SSC0_CON_MS          = SSC0_CON^14;
sbit SSC0_CON_EN          = SSC0_CON^15;
#define SSC0_ID    (*((unsigned int volatile sdata *) 0xFFE4))     //SSC0 Module Identification Register

/* SSC1 */
sfr  SSC1_TB              = 0xF05A;       //SSC Transmit Buffer (WO)
sfr  SSC1_RB              = 0xF05C;       //SSC Receive Buffer (RO)
sfr  SSC1_BR              = 0xF05E;       //SSC Baudrate Register
sfr  SSC1_CON             = 0xFF5E;       //SSC1 Control Register
sbit SSC1_CON_HB          = SSC1_CON^4;
sbit SSC1_CON_PH          = SSC1_CON^5;
sbit SSC1_CON_PO          = SSC1_CON^6;
sbit SSC1_CON_LB          = SSC1_CON^7;
sbit SSC1_CON_TEN         = SSC1_CON^8;
sbit SSC1_CON_TE          = SSC1_CON^8;
sbit SSC1_CON_REN         = SSC1_CON^9;
sbit SSC1_CON_RE          = SSC1_CON^9;
sbit SSC1_CON_PEN         = SSC1_CON^10;
sbit SSC1_CON_PE          = SSC1_CON^10;
sbit SSC1_CON_BEN         = SSC1_CON^11;
sbit SSC1_CON_BE          = SSC1_CON^11;
sbit SSC1_CON_AREN        = SSC1_CON^12;
sbit SSC1_CON_BSY         = SSC1_CON^12;
sbit SSC1_CON_MS          = SSC1_CON^14;
sbit SSC1_CON_EN          = SSC1_CON^15;
#define SSC1_ID    (*((unsigned int volatile sdata *) 0xFFF6))     //SSC1 Module Identification Register

/* WDT */
sfr  WDT                  = 0xFEAE;       //Watchdog Timer Register (read only)

/* TWINCAN-16BIT */
#define CAN_PISEL       (*((unsigned int volatile huge  *) 0x200004))       //TwinCAN Port Input Select Register
#define CAN_ID          (*((unsigned int volatile huge  *) 0x200008))       //CAN Module Identification Register
#define CAN_ACR         (*((unsigned int volatile huge  *) 0x200200))       //Node A Control Register
#define CAN_ASR         (*((unsigned int volatile huge  *) 0x200204))       //Node A Status Register
#define CAN_AIR         (*((unsigned int volatile huge  *) 0x200208))       //Node A Interrupt Pending Register
#define CAN_ABTRL       (*((unsigned int volatile huge  *) 0x20020C))       //Node A Bit Timing Register Low
#define CAN_ABTRH       (*((unsigned int volatile huge  *) 0x20020E))       //Node A Bit Timing Register High
#define CAN_AGINP       (*((unsigned int volatile huge  *) 0x200210))       //Node A Global Interrupt Node Pointer Register
#define CAN_AFCRL       (*((unsigned int volatile huge  *) 0x200214))       //Node A Frame Counter Register Low
#define CAN_AFCRH       (*((unsigned int volatile huge  *) 0x200216))       //Node A Frame Counter Register High
#define CAN_AIMRL0      (*((unsigned int volatile huge  *) 0x200218))       //Node A INTID Mask Register 0 Low
#define CAN_AIMRH0      (*((unsigned int volatile huge  *) 0x20021A))       //Node A INTID Mask Register 0 High
#define CAN_AIMR4       (*((unsigned int volatile huge  *) 0x20021C))       //Node A INTID Mask Register 4 Low
#define CAN_AECNTL      (*((unsigned int volatile huge  *) 0x200220))       //Node A Error Counter Register Low
#define CAN_AECNTH      (*((unsigned int volatile huge  *) 0x200222))       //Node A Error Counter Register High
#define CAN_BCR         (*((unsigned int volatile huge  *) 0x200240))       //Node B Control Register
#define CAN_BSR         (*((unsigned int volatile huge  *) 0x200244))       //Node B Status Register
#define CAN_BIR         (*((unsigned int volatile huge  *) 0x200248))       //Node B Interrupt Pending Register
#define CAN_BBTRL       (*((unsigned int volatile huge  *) 0x20024C))       //Node B Bit Timing Register Low
#define CAN_BBTRH       (*((unsigned int volatile huge  *) 0x20024E))       //Node B Bit Timing Register High
#define CAN_BGINP       (*((unsigned int volatile huge  *) 0x200250))       //Node B Global Interrupt Node Pointer Register
#define CAN_BFCRL       (*((unsigned int volatile huge  *) 0x200254))       //Node B Frame Counter Register Low
#define CAN_BFCRH       (*((unsigned int volatile huge  *) 0x200256))       //Node B Frame Counter Register High
#define CAN_BIMRL0      (*((unsigned int volatile huge  *) 0x200258))       //Node B INTID Mask Register 0 Low
#define CAN_BIMRH0      (*((unsigned int volatile huge  *) 0x20025A))       //Node B INTID Mask Register 0 High
#define CAN_BIMR4       (*((unsigned int volatile huge  *) 0x20025C))       //Node B INTID Mask Register 4 Low
#define CAN_BECNTL      (*((unsigned int volatile huge  *) 0x200260))       //Node B Error Counter Register Low
#define CAN_BECNTH      (*((unsigned int volatile huge  *) 0x200262))       //Node B Error Counter Register High
#define CAN_RXIPNDL     (*((unsigned int volatile huge  *) 0x200284))       //Receive Interrupt Pending Register Low
#define CAN_RXIPNDH     (*((unsigned int volatile huge  *) 0x200286))       //Receive Interrupt Pending Register High
#define CAN_TXIPNDL     (*((unsigned int volatile huge  *) 0x200288))       //Transmit Interrupt Pending Register Low
#define CAN_TXIPNDH     (*((unsigned int volatile huge  *) 0x20028A))       //Transmit Interrupt Pending Register High
#define CAN_MSGDRL00    (*((unsigned int volatile huge  *) 0x200300))       //Message Object 0 Data Register 0 Low
#define CAN_MSGDRH00    (*((unsigned int volatile huge  *) 0x200302))       //Message Object 0 Data Register 0 High
#define CAN_MSGDRL04    (*((unsigned int volatile huge  *) 0x200304))       //Message Object 0 Data Register 4 Low
#define CAN_MSGDRH04    (*((unsigned int volatile huge  *) 0x200306))       //Message Object 0 Data Register 4 High
#define CAN_MSGARL0     (*((unsigned int volatile huge  *) 0x200308))       //Message Object 0 Arbitration Register Low
#define CAN_MSGARH0     (*((unsigned int volatile huge  *) 0x20030A))       //Message Object 0 Arbitration Register High
#define CAN_MSGAMRL0    (*((unsigned int volatile huge  *) 0x20030C))       //Message Object 0 Arbitration Mask Register Low
#define CAN_MSGAMRH0    (*((unsigned int volatile huge  *) 0x20030E))       //Message Object 0 Arbitration Mask Register High
#define CAN_MSGCTRL0    (*((unsigned int volatile huge  *) 0x200310))       //Message Object 0 Message Control Register Low
#define CAN_MSGCTRH0    (*((unsigned int volatile huge  *) 0x200312))       //Message Object 0 Message Control Register High
#define CAN_MSGCFGL0    (*((unsigned int volatile huge  *) 0x200314))       //Message Object 0 Message Configuration Register Low
#define CAN_MSGCFGH0    (*((unsigned int volatile huge  *) 0x200316))       //Message Object 0 Message Configuration Register High
#define CAN_MSGFGCRL0   (*((unsigned int volatile huge  *) 0x200318))       //Message Object 0 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH0   (*((unsigned int volatile huge  *) 0x20031A))       //Message Object 0 FIFO/Gateway Control Register High
#define CAN_MSGDRL10    (*((unsigned int volatile huge  *) 0x200320))       //Message Object 1 Data Register 0 Low
#define CAN_MSGDRH10    (*((unsigned int volatile huge  *) 0x200322))       //Message Object 1 Data Register 0 High
#define CAN_MSGDRL14    (*((unsigned int volatile huge  *) 0x200324))       //Message Object 1 Data Register 4 Low
#define CAN_MSGDRH14    (*((unsigned int volatile huge  *) 0x200326))       //Message Object 1 Data Register 4 High
#define CAN_MSGARL1     (*((unsigned int volatile huge  *) 0x200328))       //Message Object 1 Arbitration Register Low
#define CAN_MSGARH1     (*((unsigned int volatile huge  *) 0x20032A))       //Message Object 1 Arbitration Register High
#define CAN_MSGAMRL1    (*((unsigned int volatile huge  *) 0x20032C))       //Message Object 1 Arbitration Mask Register Low
#define CAN_MSGAMRH1    (*((unsigned int volatile huge  *) 0x20032E))       //Message Object 1 Arbitration Mask Register High
#define CAN_MSGCTRL1    (*((unsigned int volatile huge  *) 0x200330))       //Message Object 1 Message Control Register Low
#define CAN_MSGCTRH1    (*((unsigned int volatile huge  *) 0x200332))       //Message Object 1 Message Control Register High
#define CAN_MSGCFGL1    (*((unsigned int volatile huge  *) 0x200334))       //Message Object 1 Message Configuration Register Low
#define CAN_MSGCFGH1    (*((unsigned int volatile huge  *) 0x200336))       //Message Object 1 Message Configuration Register High
#define CAN_MSGFGCRL1   (*((unsigned int volatile huge  *) 0x200338))       //Message Object 1 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH1   (*((unsigned int volatile huge  *) 0x20033A))       //Message Object 1 FIFO/Gateway Control Register High
#define CAN_MSGDRL20    (*((unsigned int volatile huge  *) 0x200340))       //Message Object 2 Data Register 0 Low
#define CAN_MSGDRH20    (*((unsigned int volatile huge  *) 0x200342))       //Message Object 2 Data Register 0 High
#define CAN_MSGDRL24    (*((unsigned int volatile huge  *) 0x200344))       //Message Object 2 Data Register 4 Low
#define CAN_MSGDRH24    (*((unsigned int volatile huge  *) 0x200346))       //Message Object 2 Data Register 4 High
#define CAN_MSGARL2     (*((unsigned int volatile huge  *) 0x200348))       //Message Object 2 Arbitration Register Low
#define CAN_MSGARH2     (*((unsigned int volatile huge  *) 0x20034A))       //Message Object 2 Arbitration Register High
#define CAN_MSGAMRL2    (*((unsigned int volatile huge  *) 0x20034C))       //Message Object 2 Arbitration Mask Register Low
#define CAN_MSGAMRH2    (*((unsigned int volatile huge  *) 0x20034E))       //Message Object 2 Arbitration Mask Register High
#define CAN_MSGCTRL2    (*((unsigned int volatile huge  *) 0x200350))       //Message Object 2 Message Control Register Low
#define CAN_MSGCTRH2    (*((unsigned int volatile huge  *) 0x200352))       //Message Object 2 Message Control Register High
#define CAN_MSGCFGL2    (*((unsigned int volatile huge  *) 0x200354))       //Message Object 2 Message Configuration Register Low
#define CAN_MSGCFGH2    (*((unsigned int volatile huge  *) 0x200356))       //Message Object 2 Message Configuration Register High
#define CAN_MSGFGCRL2   (*((unsigned int volatile huge  *) 0x200358))       //Message Object 2 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH2   (*((unsigned int volatile huge  *) 0x20035A))       //Message Object 2 FIFO/Gateway Control Register High
#define CAN_MSGDRL30    (*((unsigned int volatile huge  *) 0x200360))       //Message Object 3 Data Register 0 Low
#define CAN_MSGDRH30    (*((unsigned int volatile huge  *) 0x200362))       //Message Object 3 Data Register 0 High
#define CAN_MSGDRL34    (*((unsigned int volatile huge  *) 0x200364))       //Message Object 3 Data Register 4 Low
#define CAN_MSGDRH34    (*((unsigned int volatile huge  *) 0x200366))       //Message Object 3 Data Register 4 High
#define CAN_MSGARL3     (*((unsigned int volatile huge  *) 0x200368))       //Message Object 3 Arbitration Register Low
#define CAN_MSGARH3     (*((unsigned int volatile huge  *) 0x20036A))       //Message Object 3 Arbitration Register High
#define CAN_MSGAMRL3    (*((unsigned int volatile huge  *) 0x20036C))       //Message Object 3 Arbitration Mask Register Low
#define CAN_MSGAMRH3    (*((unsigned int volatile huge  *) 0x20036E))       //Message Object 3 Arbitration Mask Register High
#define CAN_MSGCTRL3    (*((unsigned int volatile huge  *) 0x200370))       //Message Object 3 Message Control Register Low
#define CAN_MSGCTRH3    (*((unsigned int volatile huge  *) 0x200372))       //Message Object 3 Message Control Register High
#define CAN_MSGCFGL3    (*((unsigned int volatile huge  *) 0x200374))       //Message Object 3 Message Configuration Register Low
#define CAN_MSGCFGH3    (*((unsigned int volatile huge  *) 0x200376))       //Message Object 3 Message Configuration Register High
#define CAN_MSGFGCRL3   (*((unsigned int volatile huge  *) 0x200378))       //Message Object 3 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH3   (*((unsigned int volatile huge  *) 0x20037A))       //Message Object 3 FIFO/Gateway Control Register High
#define CAN_MSGDRL40    (*((unsigned int volatile huge  *) 0x200380))       //Message Object 4 Data Register 0 Low
#define CAN_MSGDRH40    (*((unsigned int volatile huge  *) 0x200382))       //Message Object 4 Data Register 0 High
#define CAN_MSGDRL44    (*((unsigned int volatile huge  *) 0x200384))       //Message Object 4 Data Register 4 Low
#define CAN_MSGDRH44    (*((unsigned int volatile huge  *) 0x200386))       //Message Object 4 Data Register 4 High
#define CAN_MSGARL4     (*((unsigned int volatile huge  *) 0x200388))       //Message Object 4 Arbitration Register Low
#define CAN_MSGARH4     (*((unsigned int volatile huge  *) 0x20038A))       //Message Object 4 Arbitration Register High
#define CAN_MSGAMRL4    (*((unsigned int volatile huge  *) 0x20038C))       //Message Object 4 Arbitration Mask Register Low
#define CAN_MSGAMRH4    (*((unsigned int volatile huge  *) 0x20038E))       //Message Object 4 Arbitration Mask Register High
#define CAN_MSGCTRL4    (*((unsigned int volatile huge  *) 0x200390))       //Message Object 4 Message Control Register Low
#define CAN_MSGCTRH4    (*((unsigned int volatile huge  *) 0x200392))       //Message Object 4 Message Control Register High
#define CAN_MSGCFGL4    (*((unsigned int volatile huge  *) 0x200394))       //Message Object 4 Message Configuration Register Low
#define CAN_MSGCFGH4    (*((unsigned int volatile huge  *) 0x200396))       //Message Object 4 Message Configuration Register High
#define CAN_MSGFGCRL4   (*((unsigned int volatile huge  *) 0x200398))       //Message Object 4 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH4   (*((unsigned int volatile huge  *) 0x20039A))       //Message Object 4 FIFO/Gateway Control Register High
#define CAN_MSGDRL50    (*((unsigned int volatile huge  *) 0x2003A0))       //Message Object 5 Data Register 0 Low
#define CAN_MSGDRH50    (*((unsigned int volatile huge  *) 0x2003A2))       //Message Object 5 Data Register 0 High
#define CAN_MSGDRL54    (*((unsigned int volatile huge  *) 0x2003A4))       //Message Object 5 Data Register 4 Low
#define CAN_MSGDRH54    (*((unsigned int volatile huge  *) 0x2003A6))       //Message Object 5 Data Register 4 High
#define CAN_MSGARL5     (*((unsigned int volatile huge  *) 0x2003A8))       //Message Object 5 Arbitration Register Low
#define CAN_MSGARH5     (*((unsigned int volatile huge  *) 0x2003AA))       //Message Object 5 Arbitration Register High
#define CAN_MSGAMRL5    (*((unsigned int volatile huge  *) 0x2003AC))       //Message Object 5 Arbitration Mask Register Low
#define CAN_MSGAMRH5    (*((unsigned int volatile huge  *) 0x2003AE))       //Message Object 5 Arbitration Mask Register High
#define CAN_MSGCTRL5    (*((unsigned int volatile huge  *) 0x2003B0))       //Message Object 5 Message Control Register Low
#define CAN_MSGCTRH5    (*((unsigned int volatile huge  *) 0x2003B2))       //Message Object 5 Message Control Register High
#define CAN_MSGCFGL5    (*((unsigned int volatile huge  *) 0x2003B4))       //Message Object 5 Message Configuration Register Low
#define CAN_MSGCFGH5    (*((unsigned int volatile huge  *) 0x2003B6))       //Message Object 5 Message Configuration Register High
#define CAN_MSGFGCRL5   (*((unsigned int volatile huge  *) 0x2003B8))       //Message Object 5 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH5   (*((unsigned int volatile huge  *) 0x2003BA))       //Message Object 5 FIFO/Gateway Control Register High
#define CAN_MSGDRL60    (*((unsigned int volatile huge  *) 0x2003C0))       //Message Object 6 Data Register 0 Low
#define CAN_MSGDRH60    (*((unsigned int volatile huge  *) 0x2003C2))       //Message Object 6 Data Register 0 High
#define CAN_MSGDRL64    (*((unsigned int volatile huge  *) 0x2003C4))       //Message Object 6 Data Register 4 Low
#define CAN_MSGDRH64    (*((unsigned int volatile huge  *) 0x2003C6))       //Message Object 6 Data Register 4 High
#define CAN_MSGARL6     (*((unsigned int volatile huge  *) 0x2003C8))       //Message Object 6 Arbitration Register Low
#define CAN_MSGARH6     (*((unsigned int volatile huge  *) 0x2003CA))       //Message Object 6 Arbitration Register High
#define CAN_MSGAMRL6    (*((unsigned int volatile huge  *) 0x2003CC))       //Message Object 6 Arbitration Mask Register Low
#define CAN_MSGAMRH6    (*((unsigned int volatile huge  *) 0x2003CE))       //Message Object 6 Arbitration Mask Register High
#define CAN_MSGCTRL6    (*((unsigned int volatile huge  *) 0x2003D0))       //Message Object 6 Message Control Register Low
#define CAN_MSGCTRH6    (*((unsigned int volatile huge  *) 0x2003D2))       //Message Object 6 Message Control Register High
#define CAN_MSGCFGL6    (*((unsigned int volatile huge  *) 0x2003D4))       //Message Object 6 Message Configuration Register Low
#define CAN_MSGCFGH6    (*((unsigned int volatile huge  *) 0x2003D6))       //Message Object 6 Message Configuration Register High
#define CAN_MSGFGCRL6   (*((unsigned int volatile huge  *) 0x2003D8))       //Message Object 6 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH6   (*((unsigned int volatile huge  *) 0x2003DA))       //Message Object 6 FIFO/Gateway Control Register High
#define CAN_MSGDRL70    (*((unsigned int volatile huge  *) 0x2003E0))       //Message Object 7 Data Register 0 Low
#define CAN_MSGDRH70    (*((unsigned int volatile huge  *) 0x2003E2))       //Message Object 7 Data Register 0 High
#define CAN_MSGDRL74    (*((unsigned int volatile huge  *) 0x2003E4))       //Message Object 7 Data Register 4 Low
#define CAN_MSGDRH74    (*((unsigned int volatile huge  *) 0x2003E6))       //Message Object 7 Data Register 4 High
#define CAN_MSGARL7     (*((unsigned int volatile huge  *) 0x2003E8))       //Message Object 7 Arbitration Register Low
#define CAN_MSGARH7     (*((unsigned int volatile huge  *) 0x2003EA))       //Message Object 7 Arbitration Register High
#define CAN_MSGAMRL7    (*((unsigned int volatile huge  *) 0x2003EC))       //Message Object 7 Arbitration Mask Register Low
#define CAN_MSGAMRH7    (*((unsigned int volatile huge  *) 0x2003EE))       //Message Object 7 Arbitration Mask Register High
#define CAN_MSGCTRL7    (*((unsigned int volatile huge  *) 0x2003F0))       //Message Object 7 Message Control Register Low
#define CAN_MSGCTRH7    (*((unsigned int volatile huge  *) 0x2003F2))       //Message Object 7 Message Control Register High
#define CAN_MSGCFGL7    (*((unsigned int volatile huge  *) 0x2003F4))       //Message Object 7 Message Configuration Register Low
#define CAN_MSGCFGH7    (*((unsigned int volatile huge  *) 0x2003F6))       //Message Object 7 Message Configuration Register High
#define CAN_MSGFGCRL7   (*((unsigned int volatile huge  *) 0x2003F8))       //Message Object 7 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH7   (*((unsigned int volatile huge  *) 0x2003FA))       //Message Object 7 FIFO/Gateway Control Register High
#define CAN_MSGDRL80    (*((unsigned int volatile huge  *) 0x200400))       //Message Object 8 Data Register 0 Low
#define CAN_MSGDRH80    (*((unsigned int volatile huge  *) 0x200402))       //Message Object 8 Data Register 0 High
#define CAN_MSGDRL84    (*((unsigned int volatile huge  *) 0x200404))       //Message Object 8 Data Register 4 Low
#define CAN_MSGDRH84    (*((unsigned int volatile huge  *) 0x200406))       //Message Object 8 Data Register 4 High
#define CAN_MSGARL8     (*((unsigned int volatile huge  *) 0x200408))       //Message Object 8 Arbitration Register Low
#define CAN_MSGARH8     (*((unsigned int volatile huge  *) 0x20040A))       //Message Object 8 Arbitration Register High
#define CAN_MSGAMRL8    (*((unsigned int volatile huge  *) 0x20040C))       //Message Object 8 Arbitration Mask Register Low
#define CAN_MSGAMRH8    (*((unsigned int volatile huge  *) 0x20040E))       //Message Object 8 Arbitration Mask Register High
#define CAN_MSGCTRL8    (*((unsigned int volatile huge  *) 0x200410))       //Message Object 8 Message Control Register Low
#define CAN_MSGCTRH8    (*((unsigned int volatile huge  *) 0x200412))       //Message Object 8 Message Control Register High
#define CAN_MSGCFGL8    (*((unsigned int volatile huge  *) 0x200414))       //Message Object 8 Message Configuration Register Low
#define CAN_MSGCFGH8    (*((unsigned int volatile huge  *) 0x200416))       //Message Object 8 Message Configuration Register High
#define CAN_MSGFGCRL8   (*((unsigned int volatile huge  *) 0x200418))       //Message Object 8 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH8   (*((unsigned int volatile huge  *) 0x20041A))       //Message Object 8 FIFO/Gateway Control Register High
#define CAN_MSGDRL90    (*((unsigned int volatile huge  *) 0x200420))       //Message Object 9 Data Register 0 Low
#define CAN_MSGDRH90    (*((unsigned int volatile huge  *) 0x200422))       //Message Object 9 Data Register 0 High
#define CAN_MSGDRL94    (*((unsigned int volatile huge  *) 0x200424))       //Message Object 9 Data Register 4 Low
#define CAN_MSGDRH94    (*((unsigned int volatile huge  *) 0x200426))       //Message Object 9 Data Register 4 High
#define CAN_MSGARL9     (*((unsigned int volatile huge  *) 0x200428))       //Message Object 9 Arbitration Register Low
#define CAN_MSGARH9     (*((unsigned int volatile huge  *) 0x20042A))       //Message Object 9 Arbitration Register High
#define CAN_MSGAMRL9    (*((unsigned int volatile huge  *) 0x20042C))       //Message Object 9 Arbitration Mask Register Low
#define CAN_MSGAMRH9    (*((unsigned int volatile huge  *) 0x20042E))       //Message Object 9 Arbitration Mask Register High
#define CAN_MSGCTRL9    (*((unsigned int volatile huge  *) 0x200430))       //Message Object 9 Message Control Register Low
#define CAN_MSGCTRH9    (*((unsigned int volatile huge  *) 0x200432))       //Message Object 9 Message Control Register High
#define CAN_MSGCFGL9    (*((unsigned int volatile huge  *) 0x200434))       //Message Object 9 Message Configuration Register Low
#define CAN_MSGCFGH9    (*((unsigned int volatile huge  *) 0x200436))       //Message Object 9 Message Configuration Register High
#define CAN_MSGFGCRL9   (*((unsigned int volatile huge  *) 0x200438))       //Message Object 9 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH9   (*((unsigned int volatile huge  *) 0x20043A))       //Message Object 9 FIFO/Gateway Control Register High
#define CAN_MSGDRL100   (*((unsigned int volatile huge  *) 0x200440))       //Message Object 10 Data Register 0 Low
#define CAN_MSGDRH100   (*((unsigned int volatile huge  *) 0x200442))       //Message Object 10 Data Register 0 High
#define CAN_MSGDRL104   (*((unsigned int volatile huge  *) 0x200444))       //Message Object 10 Data Register 4 Low
#define CAN_MSGDRH104   (*((unsigned int volatile huge  *) 0x200446))       //Message Object 10 Data Register 4 High
#define CAN_MSGARL10    (*((unsigned int volatile huge  *) 0x200448))       //Message Object 10 Arbitration Register Low
#define CAN_MSGARH10    (*((unsigned int volatile huge  *) 0x20044A))       //Message Object 10 Arbitration Register High
#define CAN_MSGAMRL10   (*((unsigned int volatile huge  *) 0x20044C))       //Message Object 10 Arbitration Mask Register Low
#define CAN_MSGAMRH10   (*((unsigned int volatile huge  *) 0x20044E))       //Message Object 10 Arbitration Mask Register High
#define CAN_MSGCTRL10   (*((unsigned int volatile huge  *) 0x200450))       //Message Object 10 Message Control Register Low
#define CAN_MSGCTRH10   (*((unsigned int volatile huge  *) 0x200452))       //Message Object 10 Message Control Register High
#define CAN_MSGCFGL10   (*((unsigned int volatile huge  *) 0x200454))       //Message Object 10 Message Configuration Register Low
#define CAN_MSGCFGH10   (*((unsigned int volatile huge  *) 0x200456))       //Message Object 10 Message Configuration Register High
#define CAN_MSGFGCRL10  (*((unsigned int volatile huge  *) 0x200458))       //Message Object 10 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH10  (*((unsigned int volatile huge  *) 0x20045A))       //Message Object 10 FIFO/Gateway Control Register High
#define CAN_MSGDRL110   (*((unsigned int volatile huge  *) 0x200460))       //Message Object 11 Data Register 0 Low
#define CAN_MSGDRH110   (*((unsigned int volatile huge  *) 0x200462))       //Message Object 11 Data Register 0 High
#define CAN_MSGDRL114   (*((unsigned int volatile huge  *) 0x200464))       //Message Object 11 Data Register 4 Low
#define CAN_MSGDRH114   (*((unsigned int volatile huge  *) 0x200466))       //Message Object 11 Data Register 4 High
#define CAN_MSGARL11    (*((unsigned int volatile huge  *) 0x200468))       //Message Object 11 Arbitration Register Low
#define CAN_MSGARH11    (*((unsigned int volatile huge  *) 0x20046A))       //Message Object 11 Arbitration Register High
#define CAN_MSGAMRL11   (*((unsigned int volatile huge  *) 0x20046C))       //Message Object 11 Arbitration Mask Register Low
#define CAN_MSGAMRH11   (*((unsigned int volatile huge  *) 0x20046E))       //Message Object 11 Arbitration Mask Register High
#define CAN_MSGCTRL11   (*((unsigned int volatile huge  *) 0x200470))       //Message Object 11 Message Control Register Low
#define CAN_MSGCTRH11   (*((unsigned int volatile huge  *) 0x200472))       //Message Object 11 Message Control Register High
#define CAN_MSGCFGL11   (*((unsigned int volatile huge  *) 0x200474))       //Message Object 11 Message Configuration Register Low
#define CAN_MSGCFGH11   (*((unsigned int volatile huge  *) 0x200476))       //Message Object 11 Message Configuration Register High
#define CAN_MSGFGCRL11  (*((unsigned int volatile huge  *) 0x200478))       //Message Object 11 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH11  (*((unsigned int volatile huge  *) 0x20047A))       //Message Object 11 FIFO/Gateway Control Register High
#define CAN_MSGDRL120   (*((unsigned int volatile huge  *) 0x200480))       //Message Object 12 Data Register 0 Low
#define CAN_MSGDRH120   (*((unsigned int volatile huge  *) 0x200482))       //Message Object 12 Data Register 0 High
#define CAN_MSGDRL124   (*((unsigned int volatile huge  *) 0x200484))       //Message Object 12 Data Register 4 Low
#define CAN_MSGDRH124   (*((unsigned int volatile huge  *) 0x200486))       //Message Object 12 Data Register 4 High
#define CAN_MSGARL12    (*((unsigned int volatile huge  *) 0x200488))       //Message Object 12 Arbitration Register Low
#define CAN_MSGARH12    (*((unsigned int volatile huge  *) 0x20048A))       //Message Object 12 Arbitration Register High
#define CAN_MSGAMRL12   (*((unsigned int volatile huge  *) 0x20048C))       //Message Object 12 Arbitration Mask Register Low
#define CAN_MSGAMRH12   (*((unsigned int volatile huge  *) 0x20048E))       //Message Object 12 Arbitration Mask Register High
#define CAN_MSGCTRL12   (*((unsigned int volatile huge  *) 0x200490))       //Message Object 12 Message Control Register Low
#define CAN_MSGCTRH12   (*((unsigned int volatile huge  *) 0x200492))       //Message Object 12 Message Control Register High
#define CAN_MSGCFGL12   (*((unsigned int volatile huge  *) 0x200494))       //Message Object 12 Message Configuration Register Low
#define CAN_MSGCFGH12   (*((unsigned int volatile huge  *) 0x200496))       //Message Object 12 Message Configuration Register High
#define CAN_MSGFGCRL12  (*((unsigned int volatile huge  *) 0x200498))       //Message Object 12 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH12  (*((unsigned int volatile huge  *) 0x20049A))       //Message Object 12 FIFO/Gateway Control Register High
#define CAN_MSGDRL130   (*((unsigned int volatile huge  *) 0x2004A0))       //Message Object 13 Data Register 0 Low
#define CAN_MSGDRH130   (*((unsigned int volatile huge  *) 0x2004A2))       //Message Object 13 Data Register 0 High
#define CAN_MSGDRL134   (*((unsigned int volatile huge  *) 0x2004A4))       //Message Object 13 Data Register 4 Low
#define CAN_MSGDRH134   (*((unsigned int volatile huge  *) 0x2004A6))       //Message Object 13 Data Register 4 High
#define CAN_MSGARL13    (*((unsigned int volatile huge  *) 0x2004A8))       //Message Object 13 Arbitration Register Low
#define CAN_MSGARH13    (*((unsigned int volatile huge  *) 0x2004AA))       //Message Object 13 Arbitration Register High
#define CAN_MSGAMRL13   (*((unsigned int volatile huge  *) 0x2004AC))       //Message Object 13 Arbitration Mask Register Low
#define CAN_MSGAMRH13   (*((unsigned int volatile huge  *) 0x2004AE))       //Message Object 13 Arbitration Mask Register High
#define CAN_MSGCTRL13   (*((unsigned int volatile huge  *) 0x2004B0))       //Message Object 13 Message Control Register Low
#define CAN_MSGCTRH13   (*((unsigned int volatile huge  *) 0x2004B2))       //Message Object 13 Message Control Register High
#define CAN_MSGCFGL13   (*((unsigned int volatile huge  *) 0x2004B4))       //Message Object 13 Message Configuration Register Low
#define CAN_MSGCFGH13   (*((unsigned int volatile huge  *) 0x2004B6))       //Message Object 13 Message Configuration Register High
#define CAN_MSGFGCRL13  (*((unsigned int volatile huge  *) 0x2004B8))       //Message Object 13 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH13  (*((unsigned int volatile huge  *) 0x2004BA))       //Message Object 13 FIFO/Gateway Control Register High
#define CAN_MSGDRL140   (*((unsigned int volatile huge  *) 0x2004C0))       //Message Object 14 Data Register 0 Low
#define CAN_MSGDRH140   (*((unsigned int volatile huge  *) 0x2004C2))       //Message Object 14 Data Register 0 High
#define CAN_MSGDRL144   (*((unsigned int volatile huge  *) 0x2004C4))       //Message Object 14 Data Register 4 Low
#define CAN_MSGDRH144   (*((unsigned int volatile huge  *) 0x2004C6))       //Message Object 14 Data Register 4 High
#define CAN_MSGARL14    (*((unsigned int volatile huge  *) 0x2004C8))       //Message Object 14 Arbitration Register Low
#define CAN_MSGARH14    (*((unsigned int volatile huge  *) 0x2004CA))       //Message Object 14 Arbitration Register High
#define CAN_MSGAMRL14   (*((unsigned int volatile huge  *) 0x2004CC))       //Message Object 14 Arbitration Mask Register Low
#define CAN_MSGAMRH14   (*((unsigned int volatile huge  *) 0x2004CE))       //Message Object 14 Arbitration Mask Register High
#define CAN_MSGCTRL14   (*((unsigned int volatile huge  *) 0x2004D0))       //Message Object 14 Message Control Register Low
#define CAN_MSGCTRH14   (*((unsigned int volatile huge  *) 0x2004D2))       //Message Object 14 Message Control Register High
#define CAN_MSGCFGL14   (*((unsigned int volatile huge  *) 0x2004D4))       //Message Object 14 Message Configuration Reg Low
#define CAN_MSGCFGH14   (*((unsigned int volatile huge  *) 0x2004D6))       //Message Object 14 Message Configuration Register High
#define CAN_MSGFGCRL14  (*((unsigned int volatile huge  *) 0x2004D8))       //Message Object 14 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH14  (*((unsigned int volatile huge  *) 0x2004DA))       //Message Object 14 FIFO/Gateway Control Register High
#define CAN_MSGDRL150   (*((unsigned int volatile huge  *) 0x2004E0))       //Message Object 15 Data Register 0 Low
#define CAN_MSGDRH150   (*((unsigned int volatile huge  *) 0x2004E2))       //Message Object 15 Data Register 0 High
#define CAN_MSGDRL154   (*((unsigned int volatile huge  *) 0x2004E4))       //Message Object 15 Data Register 4 Low
#define CAN_MSGDRH154   (*((unsigned int volatile huge  *) 0x2004E6))       //Message Object 15 Data Register 4 High
#define CAN_MSGARL15    (*((unsigned int volatile huge  *) 0x2004E8))       //Message Object 15 Arbitration Register Low
#define CAN_MSGARH15    (*((unsigned int volatile huge  *) 0x2004EA))       //Message Object 15 Arbitration Register High
#define CAN_MSGAMRL15   (*((unsigned int volatile huge  *) 0x2004EC))       //Message Object 15 Arbitration Mask Register Low
#define CAN_MSGAMRH15   (*((unsigned int volatile huge  *) 0x2004EE))       //Message Object 15 Arbitration Mask Register High
#define CAN_MSGCTRL15   (*((unsigned int volatile huge  *) 0x2004F0))       //Message Object 15 Message Control Register Low
#define CAN_MSGCTRH15   (*((unsigned int volatile huge  *) 0x2004F2))       //Message Object 15 Message Control Register High
#define CAN_MSGCFGL15   (*((unsigned int volatile huge  *) 0x2004F4))       //Message Object 15 Message Configuration Register Low
#define CAN_MSGCFGH15   (*((unsigned int volatile huge  *) 0x2004F6))       //Message Object 15 Message Configuration Register High
#define CAN_MSGFGCRL15  (*((unsigned int volatile huge  *) 0x2004F8))       //Message Object 15 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH15  (*((unsigned int volatile huge  *) 0x2004FA))       //Message Object 15 FIFO/Gateway Control Register High
#define CAN_MSGDRL160   (*((unsigned int volatile huge  *) 0x200500))       //Message Object 16 Data Register 0 Low
#define CAN_MSGDRH160   (*((unsigned int volatile huge  *) 0x200502))       //Message Object 16 Data Register 0 High
#define CAN_MSGDRL164   (*((unsigned int volatile huge  *) 0x200504))       //Message Object 16 Data Register 4 Low
#define CAN_MSGDRH164   (*((unsigned int volatile huge  *) 0x200506))       //Message Object 16 Data Register 4 High
#define CAN_MSGARL16    (*((unsigned int volatile huge  *) 0x200508))       //Message Object 16 Arbitration Register Low
#define CAN_MSGARH16    (*((unsigned int volatile huge  *) 0x20050A))       //Message Object 16 Arbitration Register High
#define CAN_MSGAMRL16   (*((unsigned int volatile huge  *) 0x20050C))       //Message Object 16 Arbitration Mask Register Low
#define CAN_MSGAMRH16   (*((unsigned int volatile huge  *) 0x20050E))       //Message Object 16 Arbitration Mask Register High
#define CAN_MSGCTRL16   (*((unsigned int volatile huge  *) 0x200510))       //Message Object 16 Message Control Register Low
#define CAN_MSGCTRH16   (*((unsigned int volatile huge  *) 0x200512))       //Message Object 16 Message Control Register High
#define CAN_MSGCFGL16   (*((unsigned int volatile huge  *) 0x200514))       //Message Object 16 Message Configuration Register Low
#define CAN_MSGCFGH16   (*((unsigned int volatile huge  *) 0x200516))       //Message Object 16 Message Configuration Register High
#define CAN_MSGFGCRL16  (*((unsigned int volatile huge  *) 0x200518))       //Message Object 16 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH16  (*((unsigned int volatile huge  *) 0x20051A))       //Message Object 16 FIFO/Gateway Control Register High
#define CAN_MSGDRL170   (*((unsigned int volatile huge  *) 0x200520))       //Message Object 17 Data Register 0 Low
#define CAN_MSGDRH170   (*((unsigned int volatile huge  *) 0x200522))       //Message Object 17 Data Register 0 High
#define CAN_MSGDRL174   (*((unsigned int volatile huge  *) 0x200524))       //Message Object 17 Data Register 4 Low
#define CAN_MSGDRH174   (*((unsigned int volatile huge  *) 0x200526))       //Message Object 17 Data Register 4 High
#define CAN_MSGARL17    (*((unsigned int volatile huge  *) 0x200528))       //Message Object 17 Arbitration Register Low
#define CAN_MSGARH17    (*((unsigned int volatile huge  *) 0x20052A))       //Message Object 17 Arbitration Register High
#define CAN_MSGAMRL17   (*((unsigned int volatile huge  *) 0x20052C))       //Message Object 17 Arbitration Mask Register Low
#define CAN_MSGAMRH17   (*((unsigned int volatile huge  *) 0x20052E))       //Message Object 17 Arbitration Mask Register High
#define CAN_MSGCTRL17   (*((unsigned int volatile huge  *) 0x200530))       //Message Object 17 Message Control Register Low
#define CAN_MSGCTRH17   (*((unsigned int volatile huge  *) 0x200532))       //Message Object 17 Message Control Register High
#define CAN_MSGCFGL17   (*((unsigned int volatile huge  *) 0x200534))       //Message Object 17 Message Configuration Register Low
#define CAN_MSGCFGH17   (*((unsigned int volatile huge  *) 0x200536))       //Message Object 17 Message Configuration Register High
#define CAN_MSGFGCRL17  (*((unsigned int volatile huge  *) 0x200538))       //Message Object 17 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH17  (*((unsigned int volatile huge  *) 0x20053A))       //Message Object 17 FIFO/Gateway Control Register High
#define CAN_MSGDRL180   (*((unsigned int volatile huge  *) 0x200540))       //Message Object 18 Data Register 0 Low
#define CAN_MSGDRH180   (*((unsigned int volatile huge  *) 0x200542))       //Message Object 18 Data Register 0 High
#define CAN_MSGDRL184   (*((unsigned int volatile huge  *) 0x200544))       //Message Object 18 Data Register 4 Low
#define CAN_MSGDRH184   (*((unsigned int volatile huge  *) 0x200546))       //Message Object 18 Data Register 4 High
#define CAN_MSGARL18    (*((unsigned int volatile huge  *) 0x200548))       //Message Object 18 Arbitration Register Low
#define CAN_MSGARH18    (*((unsigned int volatile huge  *) 0x20054A))       //Message Object 18 Arbitration Register High
#define CAN_MSGAMRL18   (*((unsigned int volatile huge  *) 0x20054C))       //Message Object 18 Arbitration Mask Register Low
#define CAN_MSGAMRH18   (*((unsigned int volatile huge  *) 0x20054E))       //Message Object 18 Arbitration Mask Register High
#define CAN_MSGCTRL18   (*((unsigned int volatile huge  *) 0x200550))       //Message Object 18 Message Control Register Low
#define CAN_MSGCTRH18   (*((unsigned int volatile huge  *) 0x200552))       //Message Object 18 Message Control Register High
#define CAN_MSGCFGL18   (*((unsigned int volatile huge  *) 0x200554))       //Message Object 18 Message Configuration Register Low
#define CAN_MSGCFGH18   (*((unsigned int volatile huge  *) 0x200556))       //Message Object 18 Message Configuration Register High
#define CAN_MSGFGCRL18  (*((unsigned int volatile huge  *) 0x200558))       //Message Object 18 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH18  (*((unsigned int volatile huge  *) 0x20055A))       //Message Object 18 FIFO/Gateway Control Register High
#define CAN_MSGDRL190   (*((unsigned int volatile huge  *) 0x200560))       //Message Object 19 Data Register 0 Low
#define CAN_MSGDRH190   (*((unsigned int volatile huge  *) 0x200562))       //Message Object 19 Data Register 0 High
#define CAN_MSGDRL194   (*((unsigned int volatile huge  *) 0x200564))       //Message Object 19 Data Register 4 Low
#define CAN_MSGDRH194   (*((unsigned int volatile huge  *) 0x200566))       //Message Object 19 Data Register 4 High
#define CAN_MSGARL19    (*((unsigned int volatile huge  *) 0x200568))       //Message Object 19 Arbitration Register Low
#define CAN_MSGARH19    (*((unsigned int volatile huge  *) 0x20056A))       //Message Object 19 Arbitration Register High
#define CAN_MSGAMRL19   (*((unsigned int volatile huge  *) 0x20056C))       //Message Object 19 Arbitration Mask Register Low
#define CAN_MSGAMRH19   (*((unsigned int volatile huge  *) 0x20056E))       //Message Object 19 Arbitration Mask Register High
#define CAN_MSGCTRL19   (*((unsigned int volatile huge  *) 0x200570))       //Message Object 19 Message Control Register Low
#define CAN_MSGCTRH19   (*((unsigned int volatile huge  *) 0x200572))       //Message Object 19 Message Control Register High
#define CAN_MSGCFGL19   (*((unsigned int volatile huge  *) 0x200574))       //Message Object 19 Message Configuration Register Low
#define CAN_MSGCFGH19   (*((unsigned int volatile huge  *) 0x200576))       //Message Object 19 Message Configuration Register High
#define CAN_MSGFGCRL19  (*((unsigned int volatile huge  *) 0x200578))       //Message Object 19 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH19  (*((unsigned int volatile huge  *) 0x20057A))       //Message Object 19 FIFO/Gateway Control Register High
#define CAN_MSGDRL200   (*((unsigned int volatile huge  *) 0x200580))       //Message Object 20 Data Register 0 Low
#define CAN_MSGDRH200   (*((unsigned int volatile huge  *) 0x200582))       //Message Object 20 Data Register 0 High
#define CAN_MSGDRL204   (*((unsigned int volatile huge  *) 0x200584))       //Message Object 20 Data Register 4 Low
#define CAN_MSGDRH204   (*((unsigned int volatile huge  *) 0x200586))       //Message Object 20 Data Register 4 High
#define CAN_MSGARL20    (*((unsigned int volatile huge  *) 0x200588))       //Message Object 20 Arbitration Register Low
#define CAN_MSGARH20    (*((unsigned int volatile huge  *) 0x20058A))       //Message Object 20 Arbitration Register High
#define CAN_MSGAMRL20   (*((unsigned int volatile huge  *) 0x20058C))       //Message Object 20 Arbitration Mask Register Low
#define CAN_MSGAMRH20   (*((unsigned int volatile huge  *) 0x20058E))       //Message Object 20 Arbitration Mask Register High
#define CAN_MSGCTRL20   (*((unsigned int volatile huge  *) 0x200590))       //Message Object 20 Message Control Register Low
#define CAN_MSGCTRH20   (*((unsigned int volatile huge  *) 0x200592))       //Message Object 20 Message Control Register High
#define CAN_MSGCFGL20   (*((unsigned int volatile huge  *) 0x200594))       //Message Object 20 Message Configuration Register Low
#define CAN_MSGCFGH20   (*((unsigned int volatile huge  *) 0x200596))       //Message Object 20 Message Configuration Register High
#define CAN_MSGFGCRL20  (*((unsigned int volatile huge  *) 0x200598))       //Message Object 20 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH20  (*((unsigned int volatile huge  *) 0x20059A))       //Message Object 20 FIFO/Gateway Control Register High
#define CAN_MSGDRL210   (*((unsigned int volatile huge  *) 0x2005A0))       //Message Object 21 Data Register 0 Low
#define CAN_MSGDRH210   (*((unsigned int volatile huge  *) 0x2005A2))       //Message Object 21 Data Register 0 High
#define CAN_MSGDRL214   (*((unsigned int volatile huge  *) 0x2005A4))       //Message Object 21 Data Register 4 Low
#define CAN_MSGDRH214   (*((unsigned int volatile huge  *) 0x2005A6))       //Message Object 21 Data Register 4 High
#define CAN_MSGARL21    (*((unsigned int volatile huge  *) 0x2005A8))       //Message Object 21 Arbitration Register Low
#define CAN_MSGARH21    (*((unsigned int volatile huge  *) 0x2005AA))       //Message Object 21 Arbitration Register High
#define CAN_MSGAMRL21   (*((unsigned int volatile huge  *) 0x2005AC))       //Message Object 21 Arbitration Mask Register Low
#define CAN_MSGAMRH21   (*((unsigned int volatile huge  *) 0x2005AE))       //Message Object 21 Arbitration Mask Register High
#define CAN_MSGCTRL21   (*((unsigned int volatile huge  *) 0x2005B0))       //Message Object 21 Message Control Register Low
#define CAN_MSGCTRH21   (*((unsigned int volatile huge  *) 0x2005B2))       //Message Object 21 Message Control Register High
#define CAN_MSGCFGL21   (*((unsigned int volatile huge  *) 0x2005B4))       //Message Object 21 Message Configuration Register Low
#define CAN_MSGCFGH21   (*((unsigned int volatile huge  *) 0x2005B6))       //Message Object 21 Message Configuration Register High
#define CAN_MSGFGCRL21  (*((unsigned int volatile huge  *) 0x2005B8))       //Message Object 21 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH21  (*((unsigned int volatile huge  *) 0x2005BA))       //Message Object 21 FIFO/Gateway Control Register High
#define CAN_MSGDRL220   (*((unsigned int volatile huge  *) 0x2005C0))       //Message Object 22 Data Register 0 Low
#define CAN_MSGDRH220   (*((unsigned int volatile huge  *) 0x2005C2))       //Message Object 22 Data Register 0 High
#define CAN_MSGDRL224   (*((unsigned int volatile huge  *) 0x2005C4))       //Message Object 22 Data Register 4 Low
#define CAN_MSGDRH224   (*((unsigned int volatile huge  *) 0x2005C6))       //Message Object 22 Data Register 4 High
#define CAN_MSGARL22    (*((unsigned int volatile huge  *) 0x2005C8))       //Message Object 22 Arbitration Register Low
#define CAN_MSGARH22    (*((unsigned int volatile huge  *) 0x2005CA))       //Message Object 22 Arbitration Register High
#define CAN_MSGAMRL22   (*((unsigned int volatile huge  *) 0x2005CC))       //Message Object 22 Arbitration Mask Register Low
#define CAN_MSGAMRH22   (*((unsigned int volatile huge  *) 0x2005CE))       //Message Object 22 Arbitration Mask Register High
#define CAN_MSGCTRL22   (*((unsigned int volatile huge  *) 0x2005D0))       //Message Object 22 Message Control Register Low
#define CAN_MSGCTRH22   (*((unsigned int volatile huge  *) 0x2005D2))       //Message Object 22 Message Control Register High
#define CAN_MSGCFGL22   (*((unsigned int volatile huge  *) 0x2005D4))       //Message Object 22 Message Configuration Register Low
#define CAN_MSGCFGH22   (*((unsigned int volatile huge  *) 0x2005D6))       //Message Object 22 Message Configuration Register High
#define CAN_MSGFGCRL22  (*((unsigned int volatile huge  *) 0x2005D8))       //Message Object 22 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH22  (*((unsigned int volatile huge  *) 0x2005DA))       //Message Object 22 FIFO/Gateway Control Register High
#define CAN_MSGDRL230   (*((unsigned int volatile huge  *) 0x2005E0))       //Message Object 23 Data Register 0 Low
#define CAN_MSGDRH230   (*((unsigned int volatile huge  *) 0x2005E2))       //Message Object 23 Data Register 0 High
#define CAN_MSGDRL234   (*((unsigned int volatile huge  *) 0x2005E4))       //Message Object 23 Data Register 4 Low
#define CAN_MSGDRH234   (*((unsigned int volatile huge  *) 0x2005E6))       //Message Object 23 Data Register 4 High
#define CAN_MSGARL23    (*((unsigned int volatile huge  *) 0x2005E8))       //Message Object 23 Arbitration Register Low
#define CAN_MSGARH23    (*((unsigned int volatile huge  *) 0x2005EA))       //Message Object 23 Arbitration Register High
#define CAN_MSGAMRL23   (*((unsigned int volatile huge  *) 0x2005EC))       //Message Object 23 Arbitration Mask Register Low
#define CAN_MSGAMRH23   (*((unsigned int volatile huge  *) 0x2005EE))       //Message Object 23 Arbitration Mask Register High
#define CAN_MSGCTRL23   (*((unsigned int volatile huge  *) 0x2005F0))       //Message Object 23 Message Control Register Low
#define CAN_MSGCTRH23   (*((unsigned int volatile huge  *) 0x2005F2))       //Message Object 23 Message Control Register High
#define CAN_MSGCFGL23   (*((unsigned int volatile huge  *) 0x2005F4))       //Message Object 23 Message Configuration Register Low
#define CAN_MSGCFGH23   (*((unsigned int volatile huge  *) 0x2005F6))       //Message Object 23 Message Configuration Register High
#define CAN_MSGFGCRL23  (*((unsigned int volatile huge  *) 0x2005F8))       //Message Object 23 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH23  (*((unsigned int volatile huge  *) 0x2005FA))       //Message Object 23 FIFO/Gateway Control Register High
#define CAN_MSGDRL240   (*((unsigned int volatile huge  *) 0x200600))       //Message Object 24 Data Register 0 Low
#define CAN_MSGDRH240   (*((unsigned int volatile huge  *) 0x200602))       //Message Object 24 Data Register 0 High
#define CAN_MSGDRL244   (*((unsigned int volatile huge  *) 0x200604))       //Message Object 24 Data Register 4 Low
#define CAN_MSGDRH244   (*((unsigned int volatile huge  *) 0x200606))       //Message Object 24 Data Register 4 High
#define CAN_MSGARL24    (*((unsigned int volatile huge  *) 0x200608))       //Message Object 24 Arbitration Register Low
#define CAN_MSGARH24    (*((unsigned int volatile huge  *) 0x20060A))       //Message Object 24 Arbitration Register High
#define CAN_MSGAMRL24   (*((unsigned int volatile huge  *) 0x20060C))       //Message Object 24 Arbitration Mask Register Low
#define CAN_MSGAMRH24   (*((unsigned int volatile huge  *) 0x20060E))       //Message Object 24 Arbitration Mask Register High
#define CAN_MSGCTRL24   (*((unsigned int volatile huge  *) 0x200610))       //Message Object 24 Message Control Register Low
#define CAN_MSGCTRH24   (*((unsigned int volatile huge  *) 0x200612))       //Message Object 24 Message Control Register High
#define CAN_MSGCFGL24   (*((unsigned int volatile huge  *) 0x200614))       //Message Object 24 Message Configuration Register Low
#define CAN_MSGCFGH24   (*((unsigned int volatile huge  *) 0x200616))       //Message Object 24 Message Configuration Register High
#define CAN_MSGFGCRL24  (*((unsigned int volatile huge  *) 0x200618))       //Message Object 24 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH24  (*((unsigned int volatile huge  *) 0x20061A))       //Message Object 24 FIFO/Gateway Control Register High
#define CAN_MSGDRL250   (*((unsigned int volatile huge  *) 0x200620))       //Message Object 25 Data Register 0 Low
#define CAN_MSGDRH250   (*((unsigned int volatile huge  *) 0x200622))       //Message Object 25 Data Register 0 High
#define CAN_MSGDRL254   (*((unsigned int volatile huge  *) 0x200624))       //Message Object 25 Data Register 4 Low
#define CAN_MSGDRH254   (*((unsigned int volatile huge  *) 0x200626))       //Message Object 25 Data Register 4 High
#define CAN_MSGARL25    (*((unsigned int volatile huge  *) 0x200628))       //Message Object 25 Arbitration Register Low
#define CAN_MSGARH25    (*((unsigned int volatile huge  *) 0x20062A))       //Message Object 25 Arbitration Register High
#define CAN_MSGAMRL25   (*((unsigned int volatile huge  *) 0x20062C))       //Message Object 25 Arbitration Mask Register Low
#define CAN_MSGAMRH25   (*((unsigned int volatile huge  *) 0x20062E))       //Message Object 25 Arbitration Mask Register High
#define CAN_MSGCTRL25   (*((unsigned int volatile huge  *) 0x200630))       //Message Object 25 Message Control Register Low
#define CAN_MSGCTRH25   (*((unsigned int volatile huge  *) 0x200632))       //Message Object 25 Message Control Register High
#define CAN_MSGCFGL25   (*((unsigned int volatile huge  *) 0x200634))       //Message Object 25 Message Configuration Register Low
#define CAN_MSGCFGH25   (*((unsigned int volatile huge  *) 0x200636))       //Message Object 25 Message Configuration Register High
#define CAN_MSGFGCRL25  (*((unsigned int volatile huge  *) 0x200638))       //Message Object 25 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH25  (*((unsigned int volatile huge  *) 0x20063A))       //Message Object 25 FIFO/Gateway Control Register High
#define CAN_MSGDRL260   (*((unsigned int volatile huge  *) 0x200640))       //Message Object 26 Data Register 0 Low
#define CAN_MSGDRH260   (*((unsigned int volatile huge  *) 0x200642))       //Message Object 26 Data Register 0 High
#define CAN_MSGDRL264   (*((unsigned int volatile huge  *) 0x200644))       //Message Object 26 Data Register 4 Low
#define CAN_MSGDRH264   (*((unsigned int volatile huge  *) 0x200646))       //Message Object 26 Data Register 4 High
#define CAN_MSGARL26    (*((unsigned int volatile huge  *) 0x200648))       //Message Object 26 Arbitration Register Low
#define CAN_MSGARH26    (*((unsigned int volatile huge  *) 0x20064A))       //Message Object 26 Arbitration Register High
#define CAN_MSGAMRL26   (*((unsigned int volatile huge  *) 0x20064C))       //Message Object 26 Arbitration Mask Register Low
#define CAN_MSGAMRH26   (*((unsigned int volatile huge  *) 0x20064E))       //Message Object 26 Arbitration Mask Register High
#define CAN_MSGCTRL26   (*((unsigned int volatile huge  *) 0x200650))       //Message Object 26 Message Control Register Low
#define CAN_MSGCTRH26   (*((unsigned int volatile huge  *) 0x200652))       //Message Object 26 Message Control Register High
#define CAN_MSGCFGL26   (*((unsigned int volatile huge  *) 0x200654))       //Message Object 26 Message Configuration Register Low
#define CAN_MSGCFGH26   (*((unsigned int volatile huge  *) 0x200656))       //Message Object 26 Message Configuration Register High
#define CAN_MSGFGCRL26  (*((unsigned int volatile huge  *) 0x200658))       //Message Object 26 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH26  (*((unsigned int volatile huge  *) 0x20065A))       //Message Object 26 FIFO/Gateway Control Register High
#define CAN_MSGDRL270   (*((unsigned int volatile huge  *) 0x200660))       //Message Object 27 Data Register 0 Low
#define CAN_MSGDRH270   (*((unsigned int volatile huge  *) 0x200662))       //Message Object 27 Data Register 0 High
#define CAN_MSGDRL274   (*((unsigned int volatile huge  *) 0x200664))       //Message Object 27 Data Register 4 Low
#define CAN_MSGDRH274   (*((unsigned int volatile huge  *) 0x200666))       //Message Object 27 Data Register 4 High
#define CAN_MSGARL27    (*((unsigned int volatile huge  *) 0x200668))       //Message Object 27 Arbitration Register Low
#define CAN_MSGARH27    (*((unsigned int volatile huge  *) 0x20066A))       //Message Object 27 Arbitration Register High
#define CAN_MSGAMRL27   (*((unsigned int volatile huge  *) 0x20066C))       //Message Object 27 Arbitration Mask Register Low
#define CAN_MSGAMRH27   (*((unsigned int volatile huge  *) 0x20066E))       //Message Object 27 Arbitration Mask Register High
#define CAN_MSGCTRL27   (*((unsigned int volatile huge  *) 0x200670))       //Message Object 27 Message Control Register Low
#define CAN_MSGCTRH27   (*((unsigned int volatile huge  *) 0x200672))       //Message Object 27 Message Control Register High
#define CAN_MSGCFGL27   (*((unsigned int volatile huge  *) 0x200674))       //Message Object 27 Message Configuration Register Low
#define CAN_MSGCFGH27   (*((unsigned int volatile huge  *) 0x200676))       //Message Object 27 Message Configuration Register High
#define CAN_MSGFGCRL27  (*((unsigned int volatile huge  *) 0x200678))       //Message Object 27 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH27  (*((unsigned int volatile huge  *) 0x20067A))       //Message Object 27 FIFO/Gateway Control Register High
#define CAN_MSGDRL280   (*((unsigned int volatile huge  *) 0x200680))       //Message Object 28 Data Register 0 Low
#define CAN_MSGDRH280   (*((unsigned int volatile huge  *) 0x200682))       //Message Object 28 Data Register 0 High
#define CAN_MSGDRL284   (*((unsigned int volatile huge  *) 0x200684))       //Message Object 28 Data Register 4 Low
#define CAN_MSGDRH284   (*((unsigned int volatile huge  *) 0x200686))       //Message Object 28 Data Register 4 High
#define CAN_MSGARL28    (*((unsigned int volatile huge  *) 0x200688))       //Message Object 28 Arbitration Register Low
#define CAN_MSGARH28    (*((unsigned int volatile huge  *) 0x20068A))       //Message Object 28 Arbitration Register High
#define CAN_MSGAMRL28   (*((unsigned int volatile huge  *) 0x20068C))       //Message Object 28 Arbitration Mask Register Low
#define CAN_MSGAMRH28   (*((unsigned int volatile huge  *) 0x20068E))       //Message Object 28 Arbitration Mask Register High
#define CAN_MSGCTRL28   (*((unsigned int volatile huge  *) 0x200690))       //Message Object 28 Message Control Register Low
#define CAN_MSGCTRH28   (*((unsigned int volatile huge  *) 0x200692))       //Message Object 28 Message Control Register High
#define CAN_MSGCFGL28   (*((unsigned int volatile huge  *) 0x200694))       //Message Object 28 Message Configuration Register Low
#define CAN_MSGCFGH28   (*((unsigned int volatile huge  *) 0x200696))       //Message Object 28 Message Configuration Register High
#define CAN_MSGFGCRL28  (*((unsigned int volatile huge  *) 0x200698))       //Message Object 28 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH28  (*((unsigned int volatile huge  *) 0x20069A))       //Message Object 28 FIFO/Gateway Control Register High
#define CAN_MSGDRL290   (*((unsigned int volatile huge  *) 0x2006A0))       //Message Object 29 Data Register 0 Low
#define CAN_MSGDRH290   (*((unsigned int volatile huge  *) 0x2006A2))       //Message Object 29 Data Register 0 High
#define CAN_MSGDRL294   (*((unsigned int volatile huge  *) 0x2006A4))       //Message Object 29 Data Register 4 Low
#define CAN_MSGDRH294   (*((unsigned int volatile huge  *) 0x2006A6))       //Message Object 29 Data Register 4 High
#define CAN_MSGARL29    (*((unsigned int volatile huge  *) 0x2006A8))       //Message Object 29 Arbitration Register Low
#define CAN_MSGARH29    (*((unsigned int volatile huge  *) 0x2006AA))       //Message Object 29 Arbitration Register High
#define CAN_MSGAMRL29   (*((unsigned int volatile huge  *) 0x2006AC))       //Message Object 29 Arbitration Mask Register Low
#define CAN_MSGAMRH29   (*((unsigned int volatile huge  *) 0x2006AE))       //Message Object 29 Arbitration Mask Register High
#define CAN_MSGCTRL29   (*((unsigned int volatile huge  *) 0x2006B0))       //Message Object 29 Message Control Register Low
#define CAN_MSGCTRH29   (*((unsigned int volatile huge  *) 0x2006B2))       //Message Object 29 Message Control Register High
#define CAN_MSGCFGL29   (*((unsigned int volatile huge  *) 0x2006B4))       //Message Object 29 Message Configuration Register Low
#define CAN_MSGCFGH29   (*((unsigned int volatile huge  *) 0x2006B6))       //Message Object 29 Message Configuration Register High
#define CAN_MSGFGCRL29  (*((unsigned int volatile huge  *) 0x2006B8))       //Message Object 29 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH29  (*((unsigned int volatile huge  *) 0x2006BA))       //Message Object 29 FIFO/Gateway Control Register High
#define CAN_MSGDRL300   (*((unsigned int volatile huge  *) 0x2006C0))       //Message Object 30 Data Register 0 Low
#define CAN_MSGDRH300   (*((unsigned int volatile huge  *) 0x2006C2))       //Message Object 30 Data Register 0 High
#define CAN_MSGDRL304   (*((unsigned int volatile huge  *) 0x2006C4))       //Message Object 30 Data Register 4 Low
#define CAN_MSGDRH304   (*((unsigned int volatile huge  *) 0x2006C6))       //Message Object 30 Data Register 4 High
#define CAN_MSGARL30    (*((unsigned int volatile huge  *) 0x2006C8))       //Message Object 30 Arbitration Register Low
#define CAN_MSGARH30    (*((unsigned int volatile huge  *) 0x2006CA))       //Message Object 30 Arbitration Register High
#define CAN_MSGAMRL30   (*((unsigned int volatile huge  *) 0x2006CC))       //Message Object 30 Arbitration Mask Register Low
#define CAN_MSGAMRH30   (*((unsigned int volatile huge  *) 0x2006CE))       //Message Object 30 Arbitration Mask Register High
#define CAN_MSGCTRL30   (*((unsigned int volatile huge  *) 0x2006D0))       //Message Object 30 Message Control Register Low
#define CAN_MSGCTRH30   (*((unsigned int volatile huge  *) 0x2006D2))       //Message Object 30 Message Control Register High
#define CAN_MSGCFGL30   (*((unsigned int volatile huge  *) 0x2006D4))       //Message Object 30 Message Configuration Register Low
#define CAN_MSGCFGH30   (*((unsigned int volatile huge  *) 0x2006D6))       //Message Object 30 Message Configuration Register High
#define CAN_MSGFGCRL30  (*((unsigned int volatile huge  *) 0x2006D8))       //Message Object 30 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH30  (*((unsigned int volatile huge  *) 0x2006DA))       //Message Object 30 FIFO/Gateway Control Register High
#define CAN_MSGDRL310   (*((unsigned int volatile huge  *) 0x2006E0))       //Message Object 31 Data Register 0 Low
#define CAN_MSGDRH310   (*((unsigned int volatile huge  *) 0x2006E2))       //Message Object 31 Data Register 0 High
#define CAN_MSGDRL314   (*((unsigned int volatile huge  *) 0x2006E4))       //Message Object 31 Data Register 4 Low
#define CAN_MSGDRH314   (*((unsigned int volatile huge  *) 0x2006E6))       //Message Object 31 Data Register 4 High
#define CAN_MSGARL31    (*((unsigned int volatile huge  *) 0x2006E8))       //Message Object 31 Arbitration Register Low
#define CAN_MSGARH31    (*((unsigned int volatile huge  *) 0x2006EA))       //Message Object 31 Arbitration Register High
#define CAN_MSGAMRL31   (*((unsigned int volatile huge  *) 0x2006EC))       //Message Object 31 Arbitration Mask Register Low
#define CAN_MSGAMRH31   (*((unsigned int volatile huge  *) 0x2006EE))       //Message Object 31 Arbitration Mask Register High
#define CAN_MSGCTRL31   (*((unsigned int volatile huge  *) 0x2006F0))       //Message Object 31 Message Control Register Low
#define CAN_MSGCTRH31   (*((unsigned int volatile huge  *) 0x2006F2))       //Message Object 31 Message Control Register High
#define CAN_MSGCFGL31   (*((unsigned int volatile huge  *) 0x2006F4))       //Message Object 31 Message Configuration Register Low
#define CAN_MSGCFGH31   (*((unsigned int volatile huge  *) 0x2006F6))       //Message Object 31 Message Configuration Register High
#define CAN_MSGFGCRL31  (*((unsigned int volatile huge  *) 0x2006F8))       //Message Object 31 FIFO/Gateway Control Register Low
#define CAN_MSGFGCRH31  (*((unsigned int volatile huge  *) 0x2006FA))       //Message Object 31 FIFO/Gateway Control Register High

/* IIC */
#define IIC_CFG         (*((unsigned int volatile sdata *) 0xE600))       //IIC Configuration Register
#define IIC_CON         (*((unsigned int volatile sdata *) 0xE602))       //IIC Control Register
#define IIC_ST          (*((unsigned int volatile sdata *) 0xE604))       //IIC Status Register
#define IIC_ADR         (*((unsigned int volatile sdata *) 0xE606))       //IIC Address Register
#define IIC_RTBL        (*((unsigned int volatile sdata *) 0xE608))       //IIC Receive/Transmit Buffer Low Register
#define IIC_RTBH        (*((unsigned int volatile sdata *) 0xE60A))       //IIC Receive/Transmit Buffer High Register
#define IIC_ID          (*((unsigned int volatile sdata *) 0xE60C))       //IIC Module Identification Register

/* SDLM */
#define SDLM_PISEL      (*((unsigned int volatile sdata *) 0xE904))       //SDLM Port Input Select Register
#define SDLM_ID         (*((unsigned int volatile sdata *) 0xE908))       //SDLM Module Identification Register
#define SDLM_GLOBCON    (*((unsigned int volatile sdata *) 0xE910))       //Global Control Register
#define SDLM_CLKDIV     (*((unsigned int volatile sdata *) 0xE914))       //Clock Divider Register
#define SDLM_TXDELAY    (*((unsigned int volatile sdata *) 0xE916))       //Transceiver Delay Register
#define SDLM_IFRVAL     (*((unsigned int volatile sdata *) 0xE918))       //In-Frame Response Value Register
#define SDLM_BUFFSTAT   (*((unsigned int volatile sdata *) 0xE91C))       //Buffer Status Register
#define SDLM_TRANSSTAT  (*((unsigned int volatile sdata *) 0xE91E))       //Transfer Register
#define SDLM_BUSSTAT    (*((unsigned int volatile sdata *) 0xE920))       //Bus Status Register
#define SDLM_ERRSTAT    (*((unsigned int volatile sdata *) 0xE922))       //Error Status Register
#define SDLM_BUFFCON    (*((unsigned int volatile sdata *) 0xE924))       //Buffer Control Register
#define SDLM_FLAGRST    (*((unsigned int volatile sdata *) 0xE928))       //Flag Reset Register
#define SDLM_INTCON     (*((unsigned int volatile sdata *) 0xE92C))       //Interrupt Control Register
#define SDLM_TXD0       (*((unsigned int volatile sdata *) 0xE930))       //Transmit Data Register
#define SDLM_TXD2       (*((unsigned int volatile sdata *) 0xE932))       //Transmit Data Register
#define SDLM_TXD4       (*((unsigned int volatile sdata *) 0xE934))       //Transmit Data Register
#define SDLM_TXD6       (*((unsigned int volatile sdata *) 0xE936))       //Transmit Data Register
#define SDLM_TXD8       (*((unsigned int volatile sdata *) 0xE938))       //Transmit Data Register
#define SDLM_TXD10      (*((unsigned int volatile sdata *) 0xE93A))       //Transmit Data Register
#define SDLM_TXCNT      (*((unsigned int volatile sdata *) 0xE93C))       //Bus Transmit Byte Counter
#define SDLM_TXCPU      (*((unsigned int volatile sdata *) 0xE93E))       //CPU Transmit Byte Counter
#define SDLM_RXD00      (*((unsigned int volatile sdata *) 0xE940))       //Receive Data Register
#define SDLM_RXD02      (*((unsigned int volatile sdata *) 0xE942))       //Receive Data Register
#define SDLM_RXD04      (*((unsigned int volatile sdata *) 0xE944))       //Receive Data Register
#define SDLM_RXD06      (*((unsigned int volatile sdata *) 0xE946))       //Receive Data Register
#define SDLM_RXD08      (*((unsigned int volatile sdata *) 0xE948))       //Receive Data Register
#define SDLM_RXD010     (*((unsigned int volatile sdata *) 0xE94A))       //Receive Data Register
#define SDLM_RXCNT      (*((unsigned int volatile sdata *) 0xE94C))       //Bus Receive Byte Counter
#define SDLM_RXCPU      (*((unsigned int volatile sdata *) 0xE94E))       //CPU Receive Byte Counter
#define SDLM_RXD10      (*((unsigned int volatile sdata *) 0xE950))       //Receive Data Register
#define SDLM_RXD12      (*((unsigned int volatile sdata *) 0xE952))       //Receive Data Register
#define SDLM_RXD14      (*((unsigned int volatile sdata *) 0xE954))       //Receive Data Register
#define SDLM_RXD16      (*((unsigned int volatile sdata *) 0xE956))       //Receive Data Register
#define SDLM_RXD18      (*((unsigned int volatile sdata *) 0xE958))       //Receive Data Register
#define SDLM_RXD110     (*((unsigned int volatile sdata *) 0xE95A))       //Receive Data Register
#define SDLM_RXCNTB     (*((unsigned int volatile sdata *) 0xE95C))       //Bus Receive Byte Counter Register (on bus side)
#define SDLM_SOFPTR     (*((unsigned int volatile sdata *) 0xE960))       //Start-of-Frame Pointer Register

/* IAI */
#define FINT0CSP        (*((unsigned int volatile sdata *) 0xEC00))       //Fast Interrupt Control Register 0
#define FINT0ADDR       (*((unsigned int volatile sdata *) 0xEC02))       //Fast Interrupt  Address Register 0
#define FINT1CSP        (*((unsigned int volatile sdata *) 0xEC04))       //Fast Interrupt Control Register 1
#define FINT1ADDR       (*((unsigned int volatile sdata *) 0xEC06))       //Fast Interrupt  Address Register 1
#define BNKSEL0         (*((unsigned int volatile sdata *) 0xEC20))       //Register Bank Selection Register 0
#define BNKSEL1         (*((unsigned int volatile sdata *) 0xEC22))       //Register Bank Selection Register 1
#define BNKSEL2         (*((unsigned int volatile sdata *) 0xEC24))       //Register Bank Selection Register 2
#define BNKSEL3         (*((unsigned int volatile sdata *) 0xEC26))       //Register Bank Selection Register 3
#define SRCP0           (*((unsigned int volatile sdata *) 0xEC40))       //PEC Channel 0 Source Pointer
#define DSTP0           (*((unsigned int volatile sdata *) 0xEC42))       //PEC Channel 0 Destination Pointer
#define SRCP1           (*((unsigned int volatile sdata *) 0xEC44))       //PEC Channel 1 Source Pointer
#define DSTP1           (*((unsigned int volatile sdata *) 0xEC46))       //PEC Channel 1 Destination Pointer
#define SRCP2           (*((unsigned int volatile sdata *) 0xEC48))       //PEC Channel 2 Source Pointer
#define DSTP2           (*((unsigned int volatile sdata *) 0xEC4A))       //PEC Channel 2 Destination Pointer
#define SRCP3           (*((unsigned int volatile sdata *) 0xEC4C))       //PEC Channel 3 Source Pointer
#define DSTP3           (*((unsigned int volatile sdata *) 0xEC4E))       //PEC Channel 3 Destination Pointer
#define SRCP4           (*((unsigned int volatile sdata *) 0xEC50))       //PEC Channel 4 Source Pointer
#define DSTP4           (*((unsigned int volatile sdata *) 0xEC52))       //PEC Channel 4 Destination Pointer
#define SRCP5           (*((unsigned int volatile sdata *) 0xEC54))       //PEC Channel 5 Source Pointer
#define DSTP5           (*((unsigned int volatile sdata *) 0xEC56))       //PEC Channel 5 Destination Pointer
#define SRCP6           (*((unsigned int volatile sdata *) 0xEC58))       //PEC Channel 6 Source Pointer
#define DSTP6           (*((unsigned int volatile sdata *) 0xEC5A))       //PEC Channel 6 Destination Pointer
#define SRCP7           (*((unsigned int volatile sdata *) 0xEC5C))       //PEC Channel 7 Source Pointer
#define DSTP7           (*((unsigned int volatile sdata *) 0xEC5E))       //PEC Channel 7 Destination Pointer
#define PECSEG0         (*((unsigned int volatile sdata *) 0xEC80))       //PEC Pointer 0 Segment Address Register
#define PECSEG1         (*((unsigned int volatile sdata *) 0xEC82))       //PEC Pointer 1 Segment Address Register
#define PECSEG2         (*((unsigned int volatile sdata *) 0xEC84))       //PEC Pointer 2 Segment Address Register
#define PECSEG3         (*((unsigned int volatile sdata *) 0xEC86))       //PEC Pointer 3 Segment Address Register
#define PECSEG4         (*((unsigned int volatile sdata *) 0xEC88))       //PEC Pointer 4 Segment Address Register
#define PECSEG5         (*((unsigned int volatile sdata *) 0xEC8A))       //PEC Pointer 5 Segment Address Register
#define PECSEG6         (*((unsigned int volatile sdata *) 0xEC8C))       //PEC Pointer 6 Segment Address Register
#define PECSEG7         (*((unsigned int volatile sdata *) 0xEC8E))       //PEC Pointer 7 Segment Address Register

/* EBC */
#define EBCMOD0         (*((unsigned int volatile sdata *) 0xEE00))       //EBC Mode Control Register 0
#define EBCMOD1         (*((unsigned int volatile sdata *) 0xEE02))       //EBC Mode Control Register 1
#define TCONCSMM        (*((unsigned int volatile sdata *) 0xEE0C))       //Monitor Memory CS Timing Configuration Register
#define TCONCSSM        (*((unsigned int volatile sdata *) 0xEE0E))       //Startup Memory CS Timing Configuration Register
#define TCONCS0         (*((unsigned int volatile sdata *) 0xEE10))       //CS0 Timing Configuration Register
#define FCONCS0         (*((unsigned int volatile sdata *) 0xEE12))       //CS0 Function Configuration Register
#define TCONCS1         (*((unsigned int volatile sdata *) 0xEE18))       //CS1 Timing Configuration Register
#define FCONCS1         (*((unsigned int volatile sdata *) 0xEE1A))       //CS1 Function Configuration Register
#define ADDRSEL1        (*((unsigned int volatile sdata *) 0xEE1E))       //CS1 Address Range and Size Selection Register
#define TCONCS2         (*((unsigned int volatile sdata *) 0xEE20))       //CS2 Timing Configuration Register
#define FCONCS2         (*((unsigned int volatile sdata *) 0xEE22))       //CS2 Function Configuration Register
#define ADDRSEL2        (*((unsigned int volatile sdata *) 0xEE26))       //CS2 Address Range and Size Selection Register
#define TCONCS3         (*((unsigned int volatile sdata *) 0xEE28))       //CS3 Timing Configuration Register
#define FCONCS3         (*((unsigned int volatile sdata *) 0xEE2A))       //CS3 Function Configuration Register
#define ADDRSEL3        (*((unsigned int volatile sdata *) 0xEE2E))       //CS3 Address Range and Size Selection Register
#define TCONCS4         (*((unsigned int volatile sdata *) 0xEE30))       //CS4 Timing Configuration Register
#define FCONCS4         (*((unsigned int volatile sdata *) 0xEE32))       //CS4 Function Configuration Register
#define ADDRSEL4        (*((unsigned int volatile sdata *) 0xEE36))       //CS4 Address Range and Size Selection Register
#define TCONCS5         (*((unsigned int volatile sdata *) 0xEE38))       //CS5 Timing Configuration Register
#define FCONCS5         (*((unsigned int volatile sdata *) 0xEE3A))       //CS5 Function Configuration Register
#define ADDRSEL5        (*((unsigned int volatile sdata *) 0xEE3E))       //CS5 Address Range and Size Selection Register
#define TCONCS6         (*((unsigned int volatile sdata *) 0xEE40))       //CS6 Timing Configuration Register
#define FCONCS6         (*((unsigned int volatile sdata *) 0xEE42))       //CS6 Function Configuration Register
#define ADDRSEL6        (*((unsigned int volatile sdata *) 0xEE46))       //CS6 Address Range and Size Selection Register
#define TCONCS7         (*((unsigned int volatile sdata *) 0xEE48))       //CS7 Timing Configuration Register
#define FCONCS7         (*((unsigned int volatile sdata *) 0xEE4A))       //CS7 Function Configuration Register
#define ADDRSEL7        (*((unsigned int volatile sdata *) 0xEE4E))       //CS7 Address Range and Size Selection Register


//XC161/XC167 SFRs
#if defined (__XC161_H__) || defined (__XC167_H__)

/* CC1 */
sfr  CC1_PISEL            = 0xF060;       //Port Input Select Register

/* CC2 */
sfr  CC2_PISEL            = 0xF064;       //Port Input Select Register

/* CERBERUS */
sfr  RWDATA               = 0xF06A;       //RW mode data register
sfr  IOSR                 = 0xF06C;       //Status and Control Register

/* GPT12 */
sfr  GPT12E_PISEL         = 0xFE4C;       //Port Input Select Register

/* PORT */
sfr  POCON2               = 0xF088;       //Port P2 Output Control Register
sfr  POCON6               = 0xF08E;       //Port P6 Output Control Port
sfr  POCON7               = 0xF090;       //Port P7 Output Control Port
sbit ALTSEL0P3_P0         = ALTSEL0P3^0;
sfr  ALTSEL0P6            = 0xF12C;       //Alternate I/O Source 0 Port P6
sbit ALTSEL0P6_P0         = ALTSEL0P6^0;
sbit ALTSEL0P6_P1         = ALTSEL0P6^1;
sbit ALTSEL0P6_P2         = ALTSEL0P6^2;
sbit ALTSEL0P6_P3         = ALTSEL0P6^3;
sbit ALTSEL0P6_P4         = ALTSEL0P6^4;
sbit ALTSEL0P6_P5         = ALTSEL0P6^5;
sbit ALTSEL0P6_P6         = ALTSEL0P6^6;
sbit ALTSEL0P6_P7         = ALTSEL0P6^7;
sfr  ALTSEL0P7            = 0xF13C;       //Alternate I/O Source 0 Port P7
sbit ALTSEL0P7_P4         = ALTSEL0P7^4;
sbit ALTSEL0P7_P5         = ALTSEL0P7^5;
sbit ALTSEL0P7_P6         = ALTSEL0P7^6;
sbit ALTSEL0P7_P7         = ALTSEL0P7^7;
sfr  ALTSEL1P7            = 0xF13E;       //Alternate I/O Source 1 Port P7
sbit ALTSEL1P7_P4         = ALTSEL1P7^4;
sbit ALTSEL1P7_P5         = ALTSEL1P7^5;
sbit ALTSEL1P7_P6         = ALTSEL1P7^6;
sbit ALTSEL1P7_P7         = ALTSEL1P7^7;
sfr  ALTSEL0P2            = 0xF122;       //Alternate I/O Source 0 Port P2
sbit ALTSEL0P2_P8         = ALTSEL0P2^8;
sbit ALTSEL0P2_P9         = ALTSEL0P2^9;
sbit ALTSEL0P2_P10        = ALTSEL0P2^10;
sbit ALTSEL0P2_P11        = ALTSEL0P2^11;
sbit ALTSEL0P2_P12        = ALTSEL0P2^12;
sbit ALTSEL0P2_P13        = ALTSEL0P2^13;
sbit ALTSEL0P2_P14        = ALTSEL0P2^14;
sbit ALTSEL0P2_P15        = ALTSEL0P2^15;
sfr  ODP2                 = 0xF1C2;       //Port 2 Open Drain Control Register
sbit ODP2_P8              = ODP2^8;
sbit ODP2_P9              = ODP2^9;
sbit ODP2_P10             = ODP2^10;
sbit ODP2_P11             = ODP2^11;
sbit ODP2_P12             = ODP2^12;
sbit ODP2_P13             = ODP2^13;
sbit ODP2_P14             = ODP2^14;
sbit ODP2_P15             = ODP2^15;
sbit PICON_P2HIN          = PICON^1;
sbit PICON_P6LIN          = PICON^5;
sbit PICON_P7LIN          = PICON^6;
sfr  ODP6                 = 0xF1CE;       //Port 6 Open Drain Control Register
sbit ODP6_P0              = ODP6^0;
sbit ODP6_P1              = ODP6^1;
sbit ODP6_P2              = ODP6^2;
sbit ODP6_P3              = ODP6^3;
sbit ODP6_P4              = ODP6^4;
sbit ODP6_P5              = ODP6^5;
sbit ODP6_P6              = ODP6^6;
sbit ODP6_P7              = ODP6^7;
sfr  ODP7                 = 0xF1D2;       //Port 7 Open Drain Control Register
sbit ODP7_P4              = ODP7^4;
sbit ODP7_P5              = ODP7^5;
sbit ODP7_P6              = ODP7^6;
sbit ODP7_P7              = ODP7^7;
sbit P5_P8                = P5^8;
sbit P5_P9                = P5^9;
sbit P5DIDIS_P8           = P5DIDIS^8;
sbit P5DIDIS_P9           = P5DIDIS^9;
sbit P20_P2               = P20^2;
sbit DP20_P2              = DP20^2;
sfr  P2                   = 0xFFC0;       //Port 2 Data Register
sbit P2_P8                = P2^8;
sbit P2_P9                = P2^9;
sbit P2_P10               = P2^10;
sbit P2_P11               = P2^11;
sbit P2_P12               = P2^12;
sbit P2_P13               = P2^13;
sbit P2_P14               = P2^14;
sbit P2_P15               = P2^15;
sfr  DP2                  = 0xFFC2;       //Port 2 Direction Control Register
sbit DP2_P8               = DP2^8;
sbit DP2_P9               = DP2^9;
sbit DP2_P10              = DP2^10;
sbit DP2_P11              = DP2^11;
sbit DP2_P12              = DP2^12;
sbit DP2_P13              = DP2^13;
sbit DP2_P14              = DP2^14;
sbit DP2_P15              = DP2^15;
sbit P3_P0                = P3^0;
sfr  P6                   = 0xFFCC;       //Port 6 Data Register
sbit P6_P0                = P6^0;
sbit P6_P1                = P6^1;
sbit P6_P2                = P6^2;
sbit P6_P3                = P6^3;
sbit P6_P4                = P6^4;
sbit P6_P5                = P6^5;
sbit P6_P6                = P6^6;
sbit P6_P7                = P6^7;
sfr  DP6                  = 0xFFCE;       //Port 6 Direction Control Register
sbit DP6_P0               = DP6^0;
sbit DP6_P1               = DP6^1;
sbit DP6_P2               = DP6^2;
sbit DP6_P3               = DP6^3;
sbit DP6_P4               = DP6^4;
sbit DP6_P5               = DP6^5;
sbit DP6_P6               = DP6^6;
sbit DP6_P7               = DP6^7;
sfr  P7                   = 0xFFD0;       //Port 7 Data Register
sbit P7_P4                = P7^4;
sbit P7_P5                = P7^5;
sbit P7_P6                = P7^6;
sbit P7_P7                = P7^7;
sfr  DP7                  = 0xFFD2;       //Port 7 Direction Control Register
sbit DP7_P4               = DP7^4;
sbit DP7_P5               = DP7^5;
sbit DP7_P6               = DP7^6;
sbit DP7_P7               = DP7^7;

/* RTC */
sfr  RTC_ISNCH            = 0xF10E;       //RTC Interrupt Sub Node Control Register High
sfr  RTC_CONH             = 0xF112;       //RTC Control Register High
#define RTC_IDH    (*((unsigned int volatile sdata *) 0xFFFA))     //RTC Identification Register High

/* SCU */
sbit SYSCON3_ASC1DIS      = SYSCON3^10;
sbit SYSCON3_I2CDIS       = SYSCON3^11;
sbit SYSCON3_SDLMDIS      = SYSCON3^12;
sfr  EMUCON               = 0xFE0A;       //Emulation Control Reg.
sfr  TSTMOD               = 0xFE5A;       //Test-Mode Register
#endif


//XC164/XC167 SFRs
#if defined (__XC164_H__) || defined (__XC167_H__)


/* IC */
sfr  CCU6_IC              = 0xF140;       //CAPCOM 6 Interrupt Control Register
sbit CCU6_IC_IE           = CCU6_IC^6;
sbit CCU6_IC_IR           = CCU6_IC^7;
sbit CCU6_IC_GPX          = CCU6_IC^8;
sfr  CCU6_EIC             = 0xF188;       //CAPCOM 6 Emergency Interrupt Control Register
sbit CCU6_EIC_IE          = CCU6_EIC^6;
sbit CCU6_EIC_IR          = CCU6_EIC^7;
sbit CCU6_EIC_GPX         = CCU6_EIC^8;
sfr  CCU6_T12IC           = 0xF190;       //CAPCOM 6 Timer 12 Interrupt Control Register
sbit CCU6_T12IC_IE        = CCU6_T12IC^6;
sbit CCU6_T12IC_IR        = CCU6_T12IC^7;
sbit CCU6_T12IC_GPX       = CCU6_T12IC^8;
sfr  CCU6_T13IC           = 0xF198;       //CAPCOM 6 Timer 13 Interrupt Control Register
sbit CCU6_T13IC_IE        = CCU6_T13IC^6;
sbit CCU6_T13IC_IR        = CCU6_T13IC^7;
sbit CCU6_T13IC_GPX       = CCU6_T13IC^8;

/* CCU6 */
#define CCU6_PISEL      (*((unsigned int volatile sdata *) 0xE884))       //Port Input Select Register
#define CCU6_ID         (*((unsigned int volatile sdata *) 0xE888))       //Module Identification Register
#define CCU6_T12        (*((unsigned int volatile sdata *) 0xE890))       //Timer T12 Counter Register
#define CCU6_T12PR      (*((unsigned int volatile sdata *) 0xE892))       //Timer 12 Period Register
#define CCU6_T12DTC     (*((unsigned int volatile sdata *) 0xE894))       //Dead-Time Control Register for Timer 12
#define CCU6_CC60R      (*((unsigned int volatile sdata *) 0xE898))       //Capture/Compare Register for Channel CC60
#define CCU6_CC61R      (*((unsigned int volatile sdata *) 0xE89A))       //Capture/Compare Register for Channel CC61
#define CCU6_CC62R      (*((unsigned int volatile sdata *) 0xE89C))       //Capture/Compare Register for Channel CC62
#define CCU6_CC60SR     (*((unsigned int volatile sdata *) 0xE8A0))       //Capture/Compare Shadow Register for Channel 0
#define CCU6_CC61SR     (*((unsigned int volatile sdata *) 0xE8A2))       //Capture/Compare Shadow Register for Channel 1
#define CCU6_CC62SR     (*((unsigned int volatile sdata *) 0xE8A4))       //Capture/Compare Shadow Register for Channel 2
#define CCU6_TCTR4      (*((unsigned int volatile sdata *) 0xE8A6))       //Timer Control Register 4
#define CCU6_CMPSTAT    (*((unsigned int volatile sdata *) 0xE8A8))       //Compare Status Register
#define CCU6_CMPMODIF   (*((unsigned int volatile sdata *) 0xE8AA))       //Compare State Modification Register
#define CCU6_TCTR0      (*((unsigned int volatile sdata *) 0xE8AC))       //Timer Control Register 0
#define CCU6_TCTR2      (*((unsigned int volatile sdata *) 0xE8AE))       //Timer Control Register 2
#define CCU6_T13        (*((unsigned int volatile sdata *) 0xE8B0))       //Timer T13 Counter Register
#define CCU6_T13PR      (*((unsigned int volatile sdata *) 0xE8B2))       //Timer 13 Period Register
#define CCU6_CC63R      (*((unsigned int volatile sdata *) 0xE8B4))       //Compare Register for Channel CC63
#define CCU6_CC63SR     (*((unsigned int volatile sdata *) 0xE8B6))       //Compare Shadow Register for Channel  CC63
#define CCU6_MODCTR     (*((unsigned int volatile sdata *) 0xE8C0))       //Modulation Control Register
#define CCU6_TRPCTR     (*((unsigned int volatile sdata *) 0xE8C2))       //Trap Control Register
#define CCU6_PSLR       (*((unsigned int volatile sdata *) 0xE8C4))       //Passive State Level Register
#define CCU6_T12MSEL    (*((unsigned int volatile sdata *) 0xE8C6))       //T12 Capture/Compare Mode Select Register
#define CCU6_MCMOUTS    (*((unsigned int volatile sdata *) 0xE8CA))       //Multi-Channel Mode Output Shadow Register
#define CCU6_MCMOUT     (*((unsigned int volatile sdata *) 0xE8CC))       //Multi-Channel Mode Output Register
#define CCU6_MCMCTR     (*((unsigned int volatile sdata *) 0xE8CE))       //Multi-Channel Mode Control Register
#define CCU6_IS         (*((unsigned int volatile sdata *) 0xE8D0))       //Capture/Compare Interrupt Status Register
#define CCU6_ISS        (*((unsigned int volatile sdata *) 0xE8D2))       //Capture/Compare Interrupt Status Set Register
#define CCU6_ISR        (*((unsigned int volatile sdata *) 0xE8D4))       //Capture/Compare Interrupt Status Reset Register
#define CCU6_INP        (*((unsigned int volatile sdata *) 0xE8D6))       //Capture/Compare Interrupt Node Pointer Register
#define CCU6_IEN        (*((unsigned int volatile sdata *) 0xE8D8))       //Capture/Compare Interrupt Enable Register

#endif

#endif

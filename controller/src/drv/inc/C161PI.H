/*--------------------------------------------------------------------------
C161PI.H 

Register Declarations for Infineon C161PI controller in alphabetic order
Based on the Infineon C161PI Data Sheet  1999-07 - Preliminary

Copyright (c) 1988-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.

corrected: 12/08/1999: bit positions of RTCIR, RTCIE, PLLIR, PLLIE in ISNC register
corrected: 13/11/2000: Added Registers for External Interrupt Control
corrected: 24/04/2003: Added sfr SYSCON1 and sbit ULOCK (SYSCON2.2)
corrected: 06/05/2003: Added sfr PICON and correponding bits and ADWR, ADCIN
---------------------------------------------------------------------------*/
#ifndef __C161PI_H__
#define __C161PI_H__

sfr ADCIC    = 0xFF98; // A/D Converter End of Conversion Interrupt Control Register
sfr ADCON    = 0xFFA0; // A/D Converter Control Register
sfr ADDAT    = 0xFEA0; // A/D Converter Result Register
sfr ADDAT2   = 0xF0A0; // A/D Converter 2 Result Register
sfr ADDRSEL1 = 0xFE18; // Address Select Register 1
sfr ADDRSEL2 = 0xFE1A; // Address Select Register 2
sfr ADDRSEL3 = 0xFE1C; // Address Select Register 3
sfr ADDRSEL4 = 0xFE1E; // Address Select Register 4
sfr ADEIC    = 0xFF9A; // A/D Converter Overrun Error Interrupt Control Register
sfr BUSCON0  = 0xFF0C; // Bus Configuration Register 0
sfr BUSCON1  = 0xFF14; // Bus Configuration Register 1
sfr BUSCON2  = 0xFF16; // Bus Configuration Register 2
sfr BUSCON3  = 0xFF18; // Bus Configuration Register 3
sfr BUSCON4  = 0xFF1A; // Bus Configuration Register 4
sfr CAPREL   = 0xFE4A; // GPT2 Capture/Reload Register

sfr CC8IC    = 0xFF88; // External Interrupt 0 Control Register
sfr CC9IC    = 0xFF8A; // External Interrupt 0 Control Register
sfr CC10IC   = 0xFF8C; // External Interrupt 0 Control Register
sfr CC11IC   = 0xFF8E; // External Interrupt 0 Control Register
sfr CC12IC   = 0xFF90; // External Interrupt 0 Control Register
sfr CC13IC   = 0xFF92; // External Interrupt 0 Control Register
sfr CC14IC   = 0xFF94; // External Interrupt 0 Control Register
sfr CC15IC   = 0xFF96; // External Interrupt 0 Control Register

sfr CP       = 0xFE10; // CPU Context Pointer Register FC00 H
sfr CRIC     = 0xFF6A; // GPT2 CAPREL Interrupt Ctrl. Register
sfr CSP      = 0xFE08; // CPU Code Segment Pointer Register(8 bits, not directly writeable)0000 H
sfr DP0L     = 0xF100; // P0L Direction Control Register
sfr DP0H     = 0xF102; // P0H Direction Control Register
sfr DP1L     = 0xF104; // P1L Direction Control Register
sfr DP1H     = 0xF106; // P1H Direction Control Register
sfr DP2      = 0xFFC2; // Port 2 Direction Control Register
sfr DP3      = 0xFFC6; // Port 3 Direction Control Register
sfr DP4      = 0xFFCA; // Port 4 Direction Control Register
sfr DP6      = 0xFFCE; // Port 6 Direction Control Register
sfr DPP0     = 0xFE00; // CPU Data Page Pointer 0 Register (10 bits)
sfr DPP1     = 0xFE02; // CPU Data Page Pointer 1 Reg. (10 bits)
sfr DPP2     = 0xFE04; // CPU Data Page Pointer 2 Reg. (10 bits)
sfr DPP3     = 0xFE06; // CPU Data Page Pointer 3 Reg. (10 bits)
sfr EXICON   = 0xF1C0; // External Interrupt Control Register
sfr IDCHIP   = 0xF07C; // Identifier
sfr IDMANUF  = 0xF07E; // Identifier 
sfr IDMEM    = 0xF07A; // Identifier
sfr IDPROG   = 0xF078; // Identifier
sfr ISNC     = 0xF1DE; // Interrupt Subnode Control Register
sfr MDC      = 0xFF0E; // CPU Multiply Divide Control Register
sfr MDH      = 0xFE0C; // CPU Multiply Divide Reg. – High Word
sfr MDL      = 0xFE0E; // CPU Multiply Divide Reg. – Low Word
sfr ODP2     = 0xF1C2; // Port 2 Open Drain Control Register
sfr ODP3     = 0xF1C6; // Port 3 Open Drain Control Register
sfr ODP6     = 0xF1CE; // Port 6 Open Drain Control Register
sfr ONES     = 0xFF1E; // Constant Value 1’s Register (read only)
sfr P0L      = 0xFF00; // Port 0 Low Reg. (Lower half of PORT0)
sfr P0H      = 0xFF02; // Port 0 High Reg. (Upper half of PORT0)
sfr P1L      = 0xFF04; // Port 1 Low Reg. (Lower half of PORT1)
sfr P1H      = 0xFF06; // Port 1 High Reg. (Upper half of PORT1)
sfr P2       = 0xFFC0; // Port 2 Register
sfr P3       = 0xFFC4; // Port 3 Register
sfr P4       = 0xFFC8; // Port 4 Register (7 bits) 00 H
sfr P5       = 0xFFA2; // Port 5 Register (read only)
sfr P5DIDIS  = 0xFFA4; // Port 5 Digital Input Disable Register
sfr P6       = 0xFFCC; // Port 6 Register (8 bits) 00 H
sfr PECC0    = 0xFEC0; // PEC Channel 0 Control Register
sfr PECC1    = 0xFEC2; // PEC Channel 1 Control Register
sfr PECC2    = 0xFEC4; // PEC Channel 2 Control Register
sfr PECC3    = 0xFEC6; // PEC Channel 3 Control Register
sfr PECC4    = 0xFEC8; // PEC Channel 4 Control Register
sfr PECC5    = 0xFECA; // PEC Channel 5 Control Register
sfr PECC6    = 0xFECC; // PEC Channel 6 Control Register
sfr PECC7    = 0xFECE; // PEC Channel 7 Control Register
sfr PSW      = 0xFF10; // CPU Program Status Word
sfr PDCR     = 0xF0AA; // Pin Driver Control Register
sfr PICON    = 0xF1C4; // Port Input Control Register
sfr RP0H     = 0xF108; // System Startup Config. Reg. (Rd. only)
sfr RTCH     = 0xF0D6; // RTC High Register no
sfr RTCL     = 0xF0D4; // RTC Low Register no
sfr S0BG     = 0xFEB4; // Serial Channel 0 Baud Rate Generator Reload Register
sfr S0CON    = 0xFFB0; // Serial Channel 0 Control Register
sfr S0EIC    = 0xFF70; // Serial Channel 0 Error Interrupt Control Register
sfr S0RBUF   = 0xFEB2; // Serial Channel 0 Receive Buffer Reg.(read only)
sfr S0RIC    = 0xFF6E; // Serial Channel 0 Receive InterruptControl Register
sfr S0TBIC   = 0xF19C; // Serial Channel 0 Transmit BufferInterrupt Control Register
sfr S0TBUF   = 0xFEB0; // Serial Channel 0 Transmit Buffer Reg.(write only)
sfr S0TIC    = 0xFF6C; // Serial Channel 0 Transmit Interrupt Control Register
sfr SP       = 0xFE12; // CPU System Stack Pointer Register
sfr SSCBR    = 0xF0B4; // SSC Baudrate Register
sfr SSCCON   = 0xFFB2; // SSC Control Register
sfr SSCEIC   = 0xFF76; // SSC Error Interrupt Control Register
sfr SSCRB    = 0xF0B2; // SSC Receive Buffer
sfr SSCRIC   = 0xFF74; // SSC Receive Interrupt Control Register
sfr SSCTB    = 0xF0B0; // SSC Transmit Buffer
sfr SSCTIC   = 0xFF72; // SSC Transmit Interrupt Control Register
sfr STKOV    = 0xFE14; // CPU Stack Overflow Pointer Register
sfr STKUN    = 0xFE16; // CPU Stack Underflow Pointer Register
sfr SYSCON   = 0xFF12; // CPU System Configuration Register 1)
sfr SYSCON2  = 0xF1D0; // CPU System Configuration Register 2
sfr SYSCON3  = 0xF1D4; // CPU System Configuration Register 3
sfr T14      = 0xF0D2; // RTC Timer 14 Register 
sfr T14REL   = 0xF0D0; // RTC Timer 14 Reload Register 
sfr T2       = 0xFE40; // GPT1 Timer 2 Register
sfr T2CON    = 0xFF40; // GPT1 Timer 2 Control Register
sfr T2IC     = 0xFF60; // GPT1 Timer 2 Interrupt Control Register
sfr T3       = 0xFE42; // GPT1 Timer 3 Register
sfr T3CON    = 0xFF42; // GPT1 Timer 3 Control Register
sfr T3IC     = 0xFF62; // GPT1 Timer 3 Interrupt Control Register
sfr T4       = 0xFE44; // GPT1 Timer 4 Register
sfr T4CON    = 0xFF44; // GPT1 Timer 4 Control Register
sfr T4IC     = 0xFF64; // GPT1 Timer 4 Interrupt Control Register
sfr T5       = 0xFE46; // GPT2 Timer 5 Register
sfr T5CON    = 0xFF46; // GPT2 Timer 5 Control Register
sfr T5IC     = 0xFF66; // GPT2 Timer 5 Interrupt Control Register
sfr T6       = 0xFE48; // GPT2 Timer 6 Register
sfr T6CON    = 0xFF48; // GPT2 Timer 6 Control Register
sfr T6IC     = 0xFF68; // GPT2 Timer 6 Interrupt Control Register
sfr TFR      = 0xFFAC; // Trap Flag Register
sfr WDT      = 0xFEAE; // Watchdog Timer Register (read only)
sfr WDTCON   = 0xFFAE; // Watchdog Timer Control Register 2) 00xx H
sfr XP0IC    = 0xF186; // I²C Data Interrupt Control Register
sfr XP1IC    = 0xF18E; // I²C Protocol Interrupt Control Register
sfr XP2IC    = 0xF196; // X-Peripheral 2 Interrupt Control Register
sfr XP3IC    = 0xF19E; // RTC Interrupt Control Register
sfr ZEROS    = 0xFF1C; // Constant Value 0’s Register (read only)

sfr SYSCON1  = 0xF1DC; // Added for C161PI (Low Power 

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

#define  ICADR  (*((unsigned int volatile sdata *) 0xED06)) // I²C Address Register
#define  ICCFG  (*((unsigned int volatile sdata *) 0xED00)) // I²C Configuration Register
#define  ICCON  (*((unsigned int volatile sdata *) 0xED02)) // I²C Control Register
#define  ICRTB  (*((unsigned int volatile sdata *) 0xED08)) // I²C Receive/Transmit Buffer
#define  ICST   (*((unsigned int volatile sdata *) 0xED04)) // I²C Status Register

// SBIT Definitions
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
sbit  ADST     = ADCON^7;
sbit  ADBSY    = ADCON^8;
sbit  ADWR     = ADCON^9;
sbit  ADCIN    = ADCON^10;
sbit  ADCRQ    = ADCON^11;
sbit  ADCIE    = ADCIC^6;
sbit  ADCIR    = ADCIC^7;
sbit  ADEIE    = ADEIC^6;
sbit  ADEIR    = ADEIC^7;
sbit  RTCIR    = ISNC^0;
sbit  RTCIE    = ISNC^1;
sbit  PLLIR    = ISNC^2;
sbit  PLLIE    = ISNC^3;
sbit  P3LIN    = PICON^2;
sbit  P3HIN    = PICON^3;
sbit  P4LIN    = PICON^4;
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
sbit  UNLOCK   = SYSCON2^2;
sbit  RCS      = SYSCON2^6;
sbit  SCS      = SYSCON2^7;
sbit  CLKLOCK  = SYSCON2^15;
sbit  ADCDIS   = SYSCON3^0;
sbit  ASC0DIS  = SYSCON3^1;
sbit  SSCDIS   = SYSCON3^2;
sbit  GPT1DIS  = SYSCON3^3;
sbit  GPT2DIS  = SYSCON3^4;
sbit  FMDIS    = SYSCON3^5;
sbit  CC1DIS   = SYSCON3^6;
sbit  CC2DIS   = SYSCON3^7;
sbit  PWMDIS   = SYSCON3^9;
sbit  ASC1DIS  = SYSCON3^10;
sbit  I2CDIS   = SYSCON3^11;
sbit  CAN1DIS  = SYSCON3^13;
sbit  PCDDIS   = SYSCON3^15;
sbit  XP0IE    = XP0IC^6;
sbit  XP0IR    = XP0IC^7;
sbit  XP1IE    = XP1IC^6;
sbit  XP1IR    = XP1IC^7;
sbit  XP2IE    = XP2IC^6;
sbit  XP2IR    = XP2IC^7;
sbit  XP3IE    = XP3IC^6;
sbit  XP3IR    = XP3IC^7;

#endif


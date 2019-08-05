/*C164CXSX.H

Register Declarations for Infineon C164CR/CI/SI/CL/SL/CH/SH  Processor
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __C164CXSX_H__
#define __C164CXSX_H__

///////////////////////////////////////////////////////////////////////
//
// SFR Register Definitions
//
///////////////////////////////////////////////////////////////////////

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
sfr CAPREL   = 0xFE4A; // C164CR ONLY - GPT2 Capture/Relode Register
sfr CC10IC   = 0xFF8C; // External Interrupt 2 Control Register
sfr CC11IC   = 0xFF8E; // External Interrupt 3 Control Register
sfr CC16     = 0xFE60; // 30 H CAPCOM Register 16
sfr CC16IC   = 0xF160; // CAPCOM Reg. 16 Interrupt Control Register
sfr CC17     = 0xFE62; // CAPCOM Register 17
sfr CC17IC   = 0xF162; // CAPCOM Reg. 17 Interrupt Control Register
sfr CC18     = 0xFE64; // CAPCOM Register 18
sfr CC18IC   = 0xF164; // CAPCOM Reg. 18 Interrupt Control Register
sfr CC19     = 0xFE66; // CAPCOM Register 19
sfr CC19IC   = 0xF166; // CAPCOM Reg. 19 Interrupt Control Register
sfr CC20     = 0xFE68; // CAPCOM Register 20
sfr CC20IC   = 0xF168; // CAPCOM Reg. 20 Interrupt Control Register
sfr CC21     = 0xFE6A; // CAPCOM Register 21
sfr CC21IC   = 0xF16A; // CAPCOM Reg. 21 Interrupt Control Register
sfr CC22     = 0xFE6C; // CAPCOM Register 22
sfr CC22IC   = 0xF16C; // CAPCOM Reg. 22 Interrupt Control Register
sfr CC23     = 0xFE6E; // CAPCOM Register 23
sfr CC23IC   = 0xF16E; // CAPCOM Reg. 23 Interrupt Control Register
sfr CC24     = 0xFE70; // CAPCOM Register 24
sfr CC24IC   = 0xF170; // CAPCOM Reg. 24 Interrupt Control Register
sfr CC25     = 0xFE72; // CAPCOM Register 25
sfr CC25IC   = 0xF172; // CAPCOM Reg. 25 Interrupt Control Register
sfr CC26     = 0xFE74; // CAPCOM Register 26
sfr CC26IC   = 0xF174; // CAPCOM Reg. 26 Interrupt Control Register
sfr CC27     = 0xFE76; // CAPCOM Register 27
sfr CC27IC   = 0xF176; // CAPCOM Reg. 27 Interrupt Control Register
sfr CC28     = 0xFE78; // CAPCOM Register 28
sfr CC28IC   = 0xF178; // CAPCOM Reg. 28 Interrupt Control Register
sfr CC29     = 0xFE7A; // CAPCOM Register 29
sfr CC29IC   = 0xF184; // CAPCOM Reg. 29 Interrupt Control Register
sfr CC30     = 0xFE7C; // CAPCOM Register 30
sfr CC30IC   = 0xF18C; // CAPCOM Reg. 30 Interrupt Control Register
sfr CC31     = 0xFE7E; // CAPCOM Register 31
sfr CC31IC   = 0xF194; // CAPCOM Reg. 31 Interrupt Control Register
sfr CC60     = 0xFE30; // CAPCOM 6 Register 0
sfr CC61     = 0xFE32; // CAPCOM 6 Register 1
sfr CC62     = 0xFE34; // CAPCOM 6 Register 2
sfr CC6EIC   = 0xF188; // CAPCOM 6 Emergency Interrrupt Control Register
sfr CC6IC    = 0xF17E; // CAPCOM 6 Interrupt Control Register
sfr CC6MCON  = 0xFF32; // CAPCOM 6 Mode Control Register
sfr CC6MIC   = 0xFF36; // CAPCOM 6 Mode Interrupt Control Register
sfr CC6MSEL  = 0xF036; // CAPCOM 6 Mode Select Register
sfr CC8IC    = 0xFF88; // External Interrupt 0 Control Register
sfr CC9IC    = 0xFF8A; // External Interrupt 1 Control Register
sfr CCM4     = 0xFF22; // CAPCOM Mode Control Register 4
sfr CCM5     = 0xFF24; // CAPCOM Mode Control Register 5
sfr CCM6     = 0xFF26; // CAPCOM Mode Control Register 6
sfr CCM7     = 0xFF28; // CAPCOM Mode Control Register 7
sfr CMP13    = 0xFE36; // CAPCOM 6 Timer 13 Compare Reg.
sfr CP       = 0xFE10; // CPU Context Pointer Register
sfr CRIC     = 0xFF6A; // C164CR ONLY - GPT2 CAPREL Interrupt Reload Register
sfr CSP      = 0xFE08; // CPU Code Segment Pointer Register (8 bits, not directly writeable)
sfr CTCON    = 0xFF30; // CAPCOM 6 Compare Timer Control Register
sfr DP0H     = 0xF102; // P0H Direction Control Register
sfr DP0L     = 0xF100; // P0L Direction Control Register
sfr DP1H     = 0xF106; // P1H Direction Control Register
sfr DP1L     = 0xF104; // P1L Direction Control Register
sfr DP3      = 0xFFC6; // Port 3 Direction Control Register
sfr DP4      = 0xFFCA; // Port 4 Direction Control Register
sfr DP8      = 0xFFD6; // Port 8 Direction Control Register
sfr DPP0     = 0xFE00; // CPU Data Page Pointer 0 Reg. (10 bits)
sfr DPP1     = 0xFE02; // CPU Data Page Pointer 1 Reg. (10 bits)
sfr DPP2     = 0xFE04; // CPU Data Page Pointer 2 Reg. (10 bits)
sfr DPP3     = 0xFE06; // CPU Data Page Pointer 3 Reg. (10 bits)
sfr EXICON   = 0xF1C0; // External Interrupt Control Register
sfr EXISEL   = 0xF1DA; // External Interrupt Source Select Reg.
sfr IDCHIP   = 0xF07C; // Identifier
sfr IDMANUF  = 0xF07E; // Identifier
sfr IDMEM    = 0xF07A; // Identifier
sfr IDPROG   = 0xF078; // Identifier
sfr ISNC     = 0xF1DE; // Interrupt Subnode Control Register
sfr MDC      = 0xFF0E; // CPU Multiply Divide Control Register
sfr MDH      = 0xFE0C; // CPU Multiply Divide Reg. – High Word
sfr MDL      = 0xFE0E; // CPU Multiply Divide Reg. – Low Word
sfr ODP3     = 0xF1C6; // Port 3 Open Drain Control Register
sfr ODP4     = 0xF1CA; // Port 4 Open Drain Control Register
sfr ODP8     = 0xF1D6; // Port 8 Open Drain Control Register
sfr ONES     = 0xFF1E; // Constant Value 1’s Register (read only)
sfr P0H      = 0xFF02; // Port 0 High Reg. (Upper half of PORT0)
sfr P0L      = 0xFF00; // Port 0 Low Reg. (Lower half of PORT0)
sfr P1H      = 0xFF06; // Port 1 High Reg. (Upper half of PORT1)
sfr P1L      = 0xFF04; // Port 1 Low Reg. (Lower half of PORT1)
sfr P3       = 0xFFC4; // Port 3 Register
sfr P4       = 0xFFC8; // Port 4 Register (7 bits)
sfr P5       = 0xFFA2; // Port 5 Register (read only)
sfr P5DIDIS  = 0xFFA4; // Port 5 Digital Input Disable Register
sfr P8       = 0xFFD4; // Port 8 Register (8 bits)
sfr PECC0    = 0xFEC0; // PEC Channel 0 Control Register
sfr PECC1    = 0xFEC2; // PEC Channel 1 Control Register
sfr PECC2    = 0xFEC4; // PEC Channel 2 Control Register
sfr PECC3    = 0xFEC6; // PEC Channel 3 Control Register
sfr PECC4    = 0xFEC8; // PEC Channel 4 Control Register
sfr PECC5    = 0xFECA; // PEC Channel 5 Control Register
sfr PECC6    = 0xFECC; // PEC Channel 6 Control Register
sfr PECC7    = 0xFECE; // PEC Channel 7 Control Register
sfr PICON    = 0xF1C4; // Port Input Threshold Control Register
sfr POCON0H  = 0xF082; // Port P0H Output Control Register
sfr POCON0L  = 0xF080; // Port P0L Output Control Register
sfr POCON1H  = 0xF086; // Port P1H Output Control Register
sfr POCON1L  = 0xF084; // Port P1L Output Control Register
sfr POCON20  = 0xF0AA; // Dedicated Pin Output Control Register
sfr POCON3   = 0xF08A; // Port P3 Output Control Register
sfr POCON4   = 0xF08C; // Port P4 Output Control Register
sfr POCON8   = 0xF092; // Port P8 Output Control Register
sfr PSW      = 0xFF10; // CPU Program Status Word
sfr PTCR     = 0xF0AE; // Port Temperature Compensation Reg.
sfr RP0H     = 0xF108; // System Startup Config. Reg. (Rd. only)
sfr RTCH     = 0xF0D6; // RTC High Register no
sfr RTCL     = 0xF0D4; // RTC Low Register no
sfr S0BG     = 0xFEB4; // Serial Channel 0 Baud Rate Generator Reload Register
sfr S0CON    = 0xFFB0; // Serial Channel 0 Control Register
sfr S0EIC    = 0xFF70; // Serial Channel 0 Error Interrupt Control Register
sfr S0RBUF   = 0xFEB2; // Serial Channel 0 Receive Buffer Reg.(read only)
sfr S0RIC    = 0xFF6E; // Serial Channel 0 Receive Interrupt Control Register
sfr S0TBIC   = 0xF19C; // Serial Channel 0 Transmit Buffer Interrupt Control Register
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
sfr SYSCON1  = 0xF1DC; // CPU System Configuration Register 1
sfr SYSCON2  = 0xF1D0; // CPU System Configuration Register 2
sfr SYSCON3  = 0xF1D4; // CPU System Configuration Register 3
sfr T12IC    = 0xF190; // CAPCOM 6 Timer 12 Interrupt Control Register
sfr T12OF    = 0xF034; // CAPCOM 6 Timer 12 Offset Register
sfr T12P     = 0xF030; // CAPCOM 6 Timer 12 Period Register
sfr T13IC    = 0xF198; // CAPCOM 6 Timer 13 Interrupt Control Register
sfr T13P     = 0xF032; // CAPCOM 6 Timer 13 Period Register
sfr T14      = 0xF0D2; // RTC Timer 14 Register no
sfr T14REL   = 0xF0D0; // RTC Timer 14 Reload Register no
sfr T2       = 0xFE40; // GPT1 Timer 2 Register
sfr T2CON    = 0xFF40; // GPT1 Timer 2 Control Register
sfr T2IC     = 0xFF60; // GPT1 Timer 2 Interrupt Control Register
sfr T3       = 0xFE42; // GPT1 Timer 3 Register
sfr T3CON    = 0xFF42; // GPT1 Timer 3 Control Register
sfr T3IC     = 0xFF62; // GPT1 Timer 3 Interrupt Control Register
sfr T4       = 0xFE44; // GPT1 Timer 4 Register
sfr T4CON    = 0xFF44; // GPT1 Timer 4 Control Register
sfr T4IC     = 0xFF64; // BGPT1 Timer 4 Interrupt Control Register
sfr T5       = 0xFE46; // C164CR ONLY - GPT2 Timer 5 Register
sfr T5CON    = 0xFF46; // C164CR ONLY - GPT2 Timer 5 Control Register
sfr T5IC     = 0xFF66; // C164CR ONLY - GPT2 Timer 5 Interrupt Control Register
sfr T6       = 0xFE48; // C164CR ONLY - GPT2 Timer 6 Register
sfr T6CON    = 0xFF48; // C164CR ONLY - GPT2 Timer 6 Control Register
sfr T6IC     = 0xFF68; // C164CR ONLY - GPT2 Timer 6 Interrupt Control Register
sfr T7       = 0xF050; // CAPCOM Timer 7 Register
sfr T78CON   = 0xFF20; // CAPCOM Timer 7 and 8 Control Register
sfr T7IC     = 0xF17A; // CAPCOM Timer 7 Interrupt Control Register
sfr T7REL    = 0xF054; // CAPCOM Timer 7 Reload Register
sfr T8       = 0xF052; // CAPCOM Timer 8 Register
sfr T8IC     = 0xF17C; // CAPCOM Timer 8 Interrupt Control Register
sfr T8REL    = 0xF056; // CAPCOM Timer 8 Reload Register
sfr TFR      = 0xFFAC; // Trap Flag Register
sfr TRCON    = 0xFF34; // CAPCOM 6 Trap Enable Control Register
sfr WDT      = 0xFEAE; // Watchdog Timer Register (read only)
sfr WDTCON   = 0xFFAE; // Watchdog Timer Control Register 2)
sfr XP0IC    = 0xF186; // CAN1 Module Interrupt Control Register
sfr XP1IC    = 0xF18E; // Flash Termination Interrupt Control Reg.
sfr XP3IC    = 0xF19E; // PLL/RTC Interrupt Control Register
sfr ZEROS    = 0xFF1C; // Constant Value 0’s Register (read only)

#define RSTCON (*((unsigned int volatile sdata *) 0xF1E0))  // Reset Control Register

// PEC
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

// added SFRs for OTP Programming
#define  OPAD   (*((unsigned int volatile sdata *) 0xEDC2)) /* OTP Programming Interface Address Register */
#define  OPCTRL (*((unsigned int volatile sdata *) 0xEDC0)) /* OTP Programming Interface Control Register */
#define  OPDAT  (*((unsigned int volatile sdata *) 0xEDC4)) /* OTP Programming Interface Data Register    */

// CAN
// Following CAN Control Registers are already defined in the CAN.H file
//  C1BTR    = CAN1 Bit Timing Register
//  C1CSR    = CAN1 Control / Status Register
//  C1GMS    = CAN1 Global Mask Short
//  C1LGML   = CAN1 Lower Global Mask Long
//  C1LMLM   = CAN1 Lower Mask of Last Message
//  C1PCIR   = CAN1 Port Control / Interrupt Register
//  C1UGML   = CAN1 Upper Global Mask Long
//  C1UMLM   = CAN1 Upper Mask of Last Message


///////////////////////////////////////////////////////////////////////
//
// BIT Definitions
//
///////////////////////////////////////////////////////////////////////

// CPU
sbit  VISIBLE  = SYSCON^1;
sbit  XPEN     = SYSCON^2;
sbit  BDRSTEN  = SYSCON^3;
sbit  OWDDIS   = SYSCON^4;
sbit  CSSFG    = SYSCON^6;
sbit  WRCFG    = SYSCON^7;
sbit  CLKEN    = SYSCON^8;
sbit  BYTDIS   = SYSCON^9;
sbit  ROMEN    = SYSCON^10;
sbit  SGTDIS   = SYSCON^11; //changed from SGTEN to SGTDIS
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

// AD Converter
sbit  ADST     = ADCON^7;
sbit  ADBSY    = ADCON^8;
sbit  ADWR     = ADCON^9;
sbit  ADCIN    = ADCON^10;
sbit  ADCRQ    = ADCON^11;
sbit  ADCIE    = ADCIC^6;
sbit  ADCIR    = ADCIC^7;
sbit  ADEIE    = ADEIC^6;
sbit  ADEIR    = ADEIC^7;

// Trap Flag Register
sbit  ILLBUS   = TFR^0;
sbit  ILLINA   = TFR^1;
sbit  ILLOPA   = TFR^2;
sbit  PRTFLT   = TFR^3;
sbit  UNDOPC   = TFR^7;
sbit  STKUF    = TFR^13;
sbit  STKOF    = TFR^14;
sbit  NMI      = TFR^15;

// Port Input Control Register
sbit  P3LIN   = PICON^2;
sbit  P3HIN   = PICON^3;
sbit  P4LIN   = PICON^4;
sbit  P8LIN   = PICON^7;

// CAPCOM Interrupt Control Registers
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
sbit  CC20IR   = CC20IC^7;
sbit  CC20IE   = CC20IC^6;
sbit  CC21IR   = CC21IC^7;
sbit  CC21IE   = CC21IC^6;
sbit  CC22IR   = CC22IC^7;
sbit  CC22IE   = CC22IC^6;
sbit  CC23IR   = CC23IC^7;
sbit  CC23IE   = CC23IC^6;
sbit  CC24IR   = CC24IC^7;
sbit  CC24IE   = CC24IC^6;
sbit  CC25IR   = CC25IC^7;
sbit  CC25IE   = CC25IC^6;
sbit  CC26IR   = CC26IC^7;
sbit  CC26IE   = CC26IC^6;
sbit  CC27IR   = CC27IC^7;
sbit  CC27IE   = CC27IC^6;
sbit  CC28IR   = CC28IC^7;
sbit  CC28IE   = CC28IC^6;
sbit  CC29IR   = CC29IC^7;
sbit  CC29IE   = CC29IC^6;
sbit  CC30IR   = CC30IC^7;
sbit  CC30IE   = CC30IC^6;
sbit  CC31IR   = CC31IC^7;
sbit  CC31IE   = CC31IC^6;
//CAPCOM Mode Control Register 4
sbit  ACC16    = CCM4^3;
sbit  ACC17    = CCM4^7;
sbit  ACC18    = CCM4^11;
sbit  ACC19    = CCM4^15;
//CAPCOM Mode Control Register 5
sbit  ACC20    = CCM5^3;
sbit  ACC21    = CCM5^7;
sbit  ACC22    = CCM5^11;
sbit  ACC23    = CCM5^15;
//CAPCOM Mode Control Register 6
sbit  ACC24    = CCM6^3;
sbit  ACC25    = CCM6^7;
sbit  ACC26    = CCM6^11;
sbit  ACC27    = CCM6^15;
//CAPCOM Mode Control Register 7
sbit  ACC28    = CCM7^3;
sbit  ACC29    = CCM7^7;
sbit  ACC30    = CCM7^11;
sbit  ACC31    = CCM7^15;
// GPT1 CAPCOM T7 Interrupt Control Register
sbit  T7IE     = T7IC^6;
sbit  T7IR     = T7IC^7;
sbit  T7M      = T78CON^3;
sbit  T7R      = T78CON^6;
// GPT1 CAPCOM T8 Interrupt Control Register
sbit  T8IE     = T8IC^6;
sbit  T8IR     = T8IC^7;
sbit  T8M      = T78CON^11;
sbit  T8R      = T78CON^14;

// Serial Interface 
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

// GPT1 Timer2 Control Register & Interrupt Ctrl. Reg.
sbit  T2R      = T2CON^6;
sbit  T2UD     = T2CON^7;
sbit  T2UDE    = T2CON^8;
sbit  T2IE     = T2IC^6;
sbit  T2IR     = T2IC^7;
// GPT1 Timer3 Control Register & Interrupt Ctrl. Reg.
sbit  T3R      = T3CON^6;
sbit  T3UD     = T3CON^7;
sbit  T3UDE    = T3CON^8;
sbit  T3OE     = T3CON^9;
sbit  T3OTL    = T3CON^10;
sbit  T3IE     = T3IC^6;
sbit  T3IR     = T3IC^7;
// GPT1 Timer4 Control Register & Interrupt Ctrl. Reg.
sbit  T4R      = T4CON^6;
sbit  T4UD     = T4CON^7;
sbit  T4UDE    = T4CON^8;
sbit  T4IE     = T4IC^6;
sbit  T4IR     = T4IC^7;

// Port 3              
sbit  P3_0     = P3^0;  // C164CR only
sbit  T6OUT    = P3^1;  // C164CR only
sbit  CAPIN    = P3^2;  // C164CR only
sbit  T3OUT    = P3^3;  // C164CR only
sbit  T3EUD    = P3^4; 
sbit  T3IN     = P3^6; 
                       
// Port 4              
sbit  P4_4     = P4^4;  // C164CR only
sbit  P4_7     = P4^7;  // C164CR only
                       
// Port 5              
sbit  P5_8     = P5^8;  // C164CR only
sbit  P5_9     = P5^9;  // C164CR only
sbit  T6EUD    = P5^10; // C164CR only
sbit  T5EUD    = P5^11; // C164CR only
sbit  T6IN     = P5^12; // C164CR only
sbit  T5IN     = P5^13; // C164CR only
sbit  T4EUD    = P5^14; // C164CR only
sbit  T2EUD    = P5^15; // C164CR only
                       
// Port 8              
sbit  CC20IO   = P8^4;  // C164CR only
sbit  CC21IO   = P8^5;  // C164CR only
sbit  CC22IO   = P8^6;  // C164CR only
sbit  CC23IO   = P8^7;  // C164CR only

// GPT2 (C164CR only)
sbit  CRIE     = CRIC^6;
sbit  CRIR     = CRIC^7;
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

// Watchdog Timer
sbit  WDTIN    = WDTCON^0;
sbit  WDTR     = WDTCON^1;
sbit  SWR      = WDTCON^2;
sbit  SHWR     = WDTCON^3;
sbit  LHWR     = WDTCON^4;
sbit  WDTPRE   = WDTCON^7;

// Interrupt Subnode Control Register
sbit  RTCIR    = ISNC^0;
sbit  RTCIE    = ISNC^1;
sbit  PLLIR    = ISNC^2;
sbit  PLLIE    = ISNC^3;

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
sbit  BCMP     = CC6MCON^15;
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

sbit  RCS      = SYSCON2^6;
sbit  SCS      = SYSCON2^7;
sbit  CLKLOCK  = SYSCON2^15;
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

#endif

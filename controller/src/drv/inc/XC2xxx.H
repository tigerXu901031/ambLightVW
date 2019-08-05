//****************************************************************************
// Description
//       Register Definition File for Infineon XC2xxx devices
// --------------------------------------------------------------------------
// History:
//
//       Rev.             Date        Description
//       ---------------------------------------------------------------------
//       1.0              13.04.07    Initial version
//
//
//****************************************************************************



#ifndef _XC2XXXREGS_H_
#define _XC2XXXREGS_H_

//****************************************************************************
// @Declaration of SFRs
//****************************************************************************



// Alias Register 0
#define ADC0_ALR0              (*((unsigned int volatile sdata *) 0xE01C))

// Arbitration Slot Enable Register
#define ADC0_ASENR             (*((unsigned int volatile sdata *) 0xE018))

// Ch. 0 Control Register
#define ADC0_CHCTR0            (*((unsigned int volatile sdata *) 0xE020))

// Ch. 1 Control Register
#define ADC0_CHCTR1            (*((unsigned int volatile sdata *) 0xE022))

// Ch. 10 Control Register
#define ADC0_CHCTR10           (*((unsigned int volatile sdata *) 0xE034))

// Ch. 11 Control Register
#define ADC0_CHCTR11           (*((unsigned int volatile sdata *) 0xE036))

// Ch. 12 Control Register
#define ADC0_CHCTR12           (*((unsigned int volatile sdata *) 0xE038))

// Ch. 13 Control Register
#define ADC0_CHCTR13           (*((unsigned int volatile sdata *) 0xE03A))

// Ch. 14 Control Register
#define ADC0_CHCTR14           (*((unsigned int volatile sdata *) 0xE03C))

// Ch. 15 Control Register
#define ADC0_CHCTR15           (*((unsigned int volatile sdata *) 0xE03E))

// Ch. 2 Control Register
#define ADC0_CHCTR2            (*((unsigned int volatile sdata *) 0xE024))

// Ch. 3 Control Register
#define ADC0_CHCTR3            (*((unsigned int volatile sdata *) 0xE026))

// Ch. 4 Control Register
#define ADC0_CHCTR4            (*((unsigned int volatile sdata *) 0xE028))

// Ch. 5 Control Register
#define ADC0_CHCTR5            (*((unsigned int volatile sdata *) 0xE02A))

// Ch. 6 Control Register
#define ADC0_CHCTR6            (*((unsigned int volatile sdata *) 0xE02C))

// Ch. 7 Control Register
#define ADC0_CHCTR7            (*((unsigned int volatile sdata *) 0xE02E))

// Ch. 8 Control Register
#define ADC0_CHCTR8            (*((unsigned int volatile sdata *) 0xE030))

// Ch. 9 Control Register
#define ADC0_CHCTR9            (*((unsigned int volatile sdata *) 0xE032))

// Channel Interrupt Clear Register
#define ADC0_CHINCR            (*((unsigned int volatile sdata *) 0xE092))

// Channel Interrupt Flag Register
#define ADC0_CHINFR            (*((unsigned int volatile sdata *) 0xE090))

// Channel Interrupt Node Pointer Register 0
#define ADC0_CHINPR0           (*((unsigned int volatile sdata *) 0xE098))

// Channel Interrupt Node Pointer Register 12
#define ADC0_CHINPR12          (*((unsigned int volatile sdata *) 0xE09E))

// Channel Interrupt Node Pointer Register 4
#define ADC0_CHINPR4           (*((unsigned int volatile sdata *) 0xE09A))

// Channel Interrupt Node Pointer Register 8
#define ADC0_CHINPR8           (*((unsigned int volatile sdata *) 0xE09C))

// Conversion Request Control Register 1
#define ADC0_CRCR1             (*((unsigned int volatile sdata *) 0xE0E8))

// Conversion Request Mode Register 1
#define ADC0_CRMR1             (*((unsigned int volatile sdata *) 0xE0EC))

// Conversion Request Pending Register 1
#define ADC0_CRPR1             (*((unsigned int volatile sdata *) 0xE0EA))

// External Multiplexer Control Register
#define ADC0_EMCTR             (*((unsigned int volatile sdata *) 0xE0D0))

// External Multiplexer Enable Register
#define ADC0_EMENR             (*((unsigned int volatile sdata *) 0xE0D6))

// Event Interrupt Clear Register
#define ADC0_EVINCR            (*((unsigned int volatile sdata *) 0xE0A2))

// Event Interrupt Flag Register
#define ADC0_EVINFR            (*((unsigned int volatile sdata *) 0xE0A0))

// Event Interrupt Node Pointer Register 0
#define ADC0_EVINPR0           (*((unsigned int volatile sdata *) 0xE0A8))

// Event Interrupt Node Pointer Register 12
#define ADC0_EVINPR12          (*((unsigned int volatile sdata *) 0xE0AE))

// Event Interrupt Node Pointer Register 4
#define ADC0_EVINPR4           (*((unsigned int volatile sdata *) 0xE0AA))

// Event Interrupt Node Pointer Register 8
#define ADC0_EVINPR8           (*((unsigned int volatile sdata *) 0xE0AC))

// Global Control Register
#define ADC0_GLOBCTR           (*((unsigned int volatile sdata *) 0xE010))

// Global Status Register
#define ADC0_GLOBSTR           (*((unsigned int volatile sdata *) 0xE012))

// Input Class Register 0
#define ADC0_INPCR0            (*((unsigned int volatile sdata *) 0xE0C0))

// Input Class Register 1
#define ADC0_INPCR1            (*((unsigned int volatile sdata *) 0xE0C2))

// Kernel State Configuration Register
#define ADC0_KSCFG             (*((unsigned int volatile sdata *) 0xE00C))

// Limit Check Boundary Register 0
#define ADC0_LCBR0             (*((unsigned int volatile sdata *) 0xE084))

// Limit Check Boundary Register 1
#define ADC0_LCBR1             (*((unsigned int volatile sdata *) 0xE086))

// Limit Check Boundary Register 2
#define ADC0_LCBR2             (*((unsigned int volatile sdata *) 0xE088))

// Limit Check Boundary Register 3
#define ADC0_LCBR3             (*((unsigned int volatile sdata *) 0xE08A))

// Port Input Select Register
#define ADC0_PISEL             (*((unsigned int volatile sdata *) 0xE004))

// Queue 0 Register 0
#define ADC0_Q0R0              (*((unsigned int volatile sdata *) 0xE0E4))

// Queue 0 Register 2
#define ADC0_Q0R2              (*((unsigned int volatile sdata *) 0xE0F4))

// Queue Backup Register 0
#define ADC0_QBUR0             (*((unsigned int volatile sdata *) 0xE0E6))

// Queue Backup Register 2
#define ADC0_QBUR2             (*((unsigned int volatile sdata *) 0xE0F6))

// Queue Input Register 0
#define ADC0_QINR0             (*((unsigned int volatile sdata *) 0xE0E6))

// Queue Input Register 2
#define ADC0_QINR2             (*((unsigned int volatile sdata *) 0xE0F6))

// Queue Mode Register 0
#define ADC0_QMR0              (*((unsigned int volatile sdata *) 0xE0E0))

// Queue Mode Register 2
#define ADC0_QMR2              (*((unsigned int volatile sdata *) 0xE0F0))

// Queue Status Register 0
#define ADC0_QSR0              (*((unsigned int volatile sdata *) 0xE0E2))

// Queue Status Register 2
#define ADC0_QSR2              (*((unsigned int volatile sdata *) 0xE0F2))

// Result Control Register 0
#define ADC0_RCR0              (*((unsigned int volatile sdata *) 0xE0B0))

// Result Control Register 1
#define ADC0_RCR1              (*((unsigned int volatile sdata *) 0xE0B2))

// Result Control Register 2
#define ADC0_RCR2              (*((unsigned int volatile sdata *) 0xE0B4))

// Result Control Register 3
#define ADC0_RCR3              (*((unsigned int volatile sdata *) 0xE0B6))

// Result Control Register 4
#define ADC0_RCR4              (*((unsigned int volatile sdata *) 0xE0B8))

// Result Control Register 5
#define ADC0_RCR5              (*((unsigned int volatile sdata *) 0xE0BA))

// Result Control Register 6
#define ADC0_RCR6              (*((unsigned int volatile sdata *) 0xE0BC))

// Result Control Register 7
#define ADC0_RCR7              (*((unsigned int volatile sdata *) 0xE0BE))

// Result Register 0
#define ADC0_RESR0             (*((unsigned int volatile sdata *) 0xE040))

// Result Register 1
#define ADC0_RESR1             (*((unsigned int volatile sdata *) 0xE042))

// Result Register 2
#define ADC0_RESR2             (*((unsigned int volatile sdata *) 0xE044))

// Result Register 3
#define ADC0_RESR3             (*((unsigned int volatile sdata *) 0xE046))

// Result Register 4
#define ADC0_RESR4             (*((unsigned int volatile sdata *) 0xE048))

// Result Register 5
#define ADC0_RESR5             (*((unsigned int volatile sdata *) 0xE04A))

// Result Register 6
#define ADC0_RESR6             (*((unsigned int volatile sdata *) 0xE04C))

// Result Register 7
#define ADC0_RESR7             (*((unsigned int volatile sdata *) 0xE04E))

// Result Register 0, View A
#define ADC0_RESRA0            (*((unsigned int volatile sdata *) 0xE050))

// Result Register 1, View A
#define ADC0_RESRA1            (*((unsigned int volatile sdata *) 0xE052))

// Result Register 2, View A
#define ADC0_RESRA2            (*((unsigned int volatile sdata *) 0xE054))

// Result Register 3, View A
#define ADC0_RESRA3            (*((unsigned int volatile sdata *) 0xE056))

// Result Register 4, View A
#define ADC0_RESRA4            (*((unsigned int volatile sdata *) 0xE058))

// Result Register 5, View A
#define ADC0_RESRA5            (*((unsigned int volatile sdata *) 0xE05A))

// Result Register 6, View A
#define ADC0_RESRA6            (*((unsigned int volatile sdata *) 0xE05C))

// Result Register 7, View A
#define ADC0_RESRA7            (*((unsigned int volatile sdata *) 0xE05E))

// Result Register 0, View AV
#define ADC0_RESRAV0           (*((unsigned int volatile sdata *) 0xE070))

// Result Register 1, View AV
#define ADC0_RESRAV1           (*((unsigned int volatile sdata *) 0xE072))

// Result Register 2, View AV
#define ADC0_RESRAV2           (*((unsigned int volatile sdata *) 0xE074))

// Result Register 3, View AV
#define ADC0_RESRAV3           (*((unsigned int volatile sdata *) 0xE076))

// Result Register 4, View AV
#define ADC0_RESRAV4           (*((unsigned int volatile sdata *) 0xE078))

// Result Register 5, View AV
#define ADC0_RESRAV5           (*((unsigned int volatile sdata *) 0xE07A))

// Result Register 6, View AV
#define ADC0_RESRAV6           (*((unsigned int volatile sdata *) 0xE07C))

// Result Register 7, View AV
#define ADC0_RESRAV7           (*((unsigned int volatile sdata *) 0xE07E))

// Result Register 0, View V
#define ADC0_RESRV0            (*((unsigned int volatile sdata *) 0xE060))

// Result Register 1, View V
#define ADC0_RESRV1            (*((unsigned int volatile sdata *) 0xE062))

// Result Register 2, View V
#define ADC0_RESRV2            (*((unsigned int volatile sdata *) 0xE064))

// Result Register 3, View V
#define ADC0_RESRV3            (*((unsigned int volatile sdata *) 0xE066))

// Result Register 4, View V
#define ADC0_RESRV4            (*((unsigned int volatile sdata *) 0xE068))

// Result Register 5, View V
#define ADC0_RESRV5            (*((unsigned int volatile sdata *) 0xE06A))

// Result Register 6, View V
#define ADC0_RESRV6            (*((unsigned int volatile sdata *) 0xE06C))

// Result Register 7, View V
#define ADC0_RESRV7            (*((unsigned int volatile sdata *) 0xE06E))

// Request Source Priority Register 0
#define ADC0_RSPR0             (*((unsigned int volatile sdata *) 0xE014))

// Result Status Shadow Register
#define ADC0_RSSR              (*((unsigned int volatile sdata *) 0xE082))

// Synchronization Control Register
#define ADC0_SYNCTR            (*((unsigned int volatile sdata *) 0xE01A))

// Valid Flag Register
#define ADC0_VFR               (*((unsigned int volatile sdata *) 0xE080))

// Alias Register 0
#define ADC1_ALR0              (*((unsigned int volatile sdata *) 0xE11C))

// Arbitration Slot Enable Register
#define ADC1_ASENR             (*((unsigned int volatile sdata *) 0xE118))

// Ch. 0 Control Register
#define ADC1_CHCTR0            (*((unsigned int volatile sdata *) 0xE120))

// Ch. 1 Control Register
#define ADC1_CHCTR1            (*((unsigned int volatile sdata *) 0xE122))

// Ch. 10 Control Register
#define ADC1_CHCTR10           (*((unsigned int volatile sdata *) 0xE134))

// Ch. 11 Control Register
#define ADC1_CHCTR11           (*((unsigned int volatile sdata *) 0xE136))

// Ch. 12 Control Register
#define ADC1_CHCTR12           (*((unsigned int volatile sdata *) 0xE138))

// Ch. 13 Control Register
#define ADC1_CHCTR13           (*((unsigned int volatile sdata *) 0xE13A))

// Ch. 14 Control Register
#define ADC1_CHCTR14           (*((unsigned int volatile sdata *) 0xE13C))

// Ch. 15 Control Register
#define ADC1_CHCTR15           (*((unsigned int volatile sdata *) 0xE13E))

// Ch. 2 Control Register
#define ADC1_CHCTR2            (*((unsigned int volatile sdata *) 0xE124))

// Ch. 3 Control Register
#define ADC1_CHCTR3            (*((unsigned int volatile sdata *) 0xE126))

// Ch. 4 Control Register
#define ADC1_CHCTR4            (*((unsigned int volatile sdata *) 0xE128))

// Ch. 5 Control Register
#define ADC1_CHCTR5            (*((unsigned int volatile sdata *) 0xE12A))

// Ch. 6 Control Register
#define ADC1_CHCTR6            (*((unsigned int volatile sdata *) 0xE12C))

// Ch. 7 Control Register
#define ADC1_CHCTR7            (*((unsigned int volatile sdata *) 0xE12E))

// Ch. 8 Control Register
#define ADC1_CHCTR8            (*((unsigned int volatile sdata *) 0xE130))

// Ch. 9 Control Register
#define ADC1_CHCTR9            (*((unsigned int volatile sdata *) 0xE132))

// Channel Interrupt Clear Register
#define ADC1_CHINCR            (*((unsigned int volatile sdata *) 0xE192))

// Channel Interrupt Flag Register
#define ADC1_CHINFR            (*((unsigned int volatile sdata *) 0xE190))

// Channel Interrupt Node Pointer Register 0
#define ADC1_CHINPR0           (*((unsigned int volatile sdata *) 0xE198))

// Channel Interrupt Node Pointer Register 12
#define ADC1_CHINPR12          (*((unsigned int volatile sdata *) 0xE19E))

// Channel Interrupt Node Pointer Register 4
#define ADC1_CHINPR4           (*((unsigned int volatile sdata *) 0xE19A))

// Channel Interrupt Node Pointer Register 8
#define ADC1_CHINPR8           (*((unsigned int volatile sdata *) 0xE19C))

// Conversion Request Control Register 1
#define ADC1_CRCR1             (*((unsigned int volatile sdata *) 0xE1E8))

// Conversion Request Mode Register 1
#define ADC1_CRMR1             (*((unsigned int volatile sdata *) 0xE1EC))

// Conversion Request Pending Register 1
#define ADC1_CRPR1             (*((unsigned int volatile sdata *) 0xE1EA))

// External Multiplexer Control Register
#define ADC1_EMCTR             (*((unsigned int volatile sdata *) 0xE1D0))

// External Multiplexer Enable Register
#define ADC1_EMENR             (*((unsigned int volatile sdata *) 0xE1D6))

// Event Interrupt Clear Register
#define ADC1_EVINCR            (*((unsigned int volatile sdata *) 0xE1A2))

// Event Interrupt Flag Register
#define ADC1_EVINFR            (*((unsigned int volatile sdata *) 0xE1A0))

// Event Interrupt Node Pointer Register 0
#define ADC1_EVINPR0           (*((unsigned int volatile sdata *) 0xE1A8))

// Event Interrupt Node Pointer Register 12
#define ADC1_EVINPR12          (*((unsigned int volatile sdata *) 0xE1AE))

// Event Interrupt Node Pointer Register 4
#define ADC1_EVINPR4           (*((unsigned int volatile sdata *) 0xE1AA))

// Event Interrupt Node Pointer Register 8
#define ADC1_EVINPR8           (*((unsigned int volatile sdata *) 0xE1AC))

// Global Control Register
#define ADC1_GLOBCTR           (*((unsigned int volatile sdata *) 0xE110))

// Global Status Register
#define ADC1_GLOBSTR           (*((unsigned int volatile sdata *) 0xE112))

// Input Class Register 0
#define ADC1_INPCR0            (*((unsigned int volatile sdata *) 0xE1C0))

// Input Class Register 1
#define ADC1_INPCR1            (*((unsigned int volatile sdata *) 0xE1C2))

// Limit Check Boundary Register 0
#define ADC1_LCBR0             (*((unsigned int volatile sdata *) 0xE184))

// Limit Check Boundary Register 1
#define ADC1_LCBR1             (*((unsigned int volatile sdata *) 0xE186))

// Limit Check Boundary Register 2
#define ADC1_LCBR2             (*((unsigned int volatile sdata *) 0xE188))

// Limit Check Boundary Register 3
#define ADC1_LCBR3             (*((unsigned int volatile sdata *) 0xE18A))

// Port Input Select Register
#define ADC1_PISEL             (*((unsigned int volatile sdata *) 0xE104))

// Queue 0 Register 0
#define ADC1_Q0R0              (*((unsigned int volatile sdata *) 0xE1E4))

// Queue 0 Register 2
#define ADC1_Q0R2              (*((unsigned int volatile sdata *) 0xE1F4))

// Queue Backup Register 0
#define ADC1_QBUR0             (*((unsigned int volatile sdata *) 0xE1E6))

// Queue Backup Register 2
#define ADC1_QBUR2             (*((unsigned int volatile sdata *) 0xE1F6))

// Queue Input Register 0
#define ADC1_QINR0             (*((unsigned int volatile sdata *) 0xE1E6))

// Queue Input Register 2
#define ADC1_QINR2             (*((unsigned int volatile sdata *) 0xE1F6))

// Queue Mode Register 0
#define ADC1_QMR0              (*((unsigned int volatile sdata *) 0xE1E0))

// Queue Mode Register 2
#define ADC1_QMR2              (*((unsigned int volatile sdata *) 0xE1F0))

// Queue Status Register 0
#define ADC1_QSR0              (*((unsigned int volatile sdata *) 0xE1E2))

// Queue Status Register 2
#define ADC1_QSR2              (*((unsigned int volatile sdata *) 0xE1F2))

// Result Control Register 0
#define ADC1_RCR0              (*((unsigned int volatile sdata *) 0xE1B0))

// Result Control Register 1
#define ADC1_RCR1              (*((unsigned int volatile sdata *) 0xE1B2))

// Result Control Register 2
#define ADC1_RCR2              (*((unsigned int volatile sdata *) 0xE1B4))

// Result Control Register 3
#define ADC1_RCR3              (*((unsigned int volatile sdata *) 0xE1B6))

// Result Control Register 4
#define ADC1_RCR4              (*((unsigned int volatile sdata *) 0xE1B8))

// Result Control Register 5
#define ADC1_RCR5              (*((unsigned int volatile sdata *) 0xE1BA))

// Result Control Register 6
#define ADC1_RCR6              (*((unsigned int volatile sdata *) 0xE1BC))

// Result Control Register 7
#define ADC1_RCR7              (*((unsigned int volatile sdata *) 0xE1BE))

// Result Register 0
#define ADC1_RESR0             (*((unsigned int volatile sdata *) 0xE140))

// Result Register 1
#define ADC1_RESR1             (*((unsigned int volatile sdata *) 0xE142))

// Result Register 2
#define ADC1_RESR2             (*((unsigned int volatile sdata *) 0xE144))

// Result Register 3
#define ADC1_RESR3             (*((unsigned int volatile sdata *) 0xE146))

// Result Register 4
#define ADC1_RESR4             (*((unsigned int volatile sdata *) 0xE148))

// Result Register 5
#define ADC1_RESR5             (*((unsigned int volatile sdata *) 0xE14A))

// Result Register 6
#define ADC1_RESR6             (*((unsigned int volatile sdata *) 0xE14C))

// Result Register 7
#define ADC1_RESR7             (*((unsigned int volatile sdata *) 0xE14E))

// Result Register 0, View A
#define ADC1_RESRA0            (*((unsigned int volatile sdata *) 0xE150))

// Result Register 1, View A
#define ADC1_RESRA1            (*((unsigned int volatile sdata *) 0xE152))

// Result Register 2, View A
#define ADC1_RESRA2            (*((unsigned int volatile sdata *) 0xE154))

// Result Register 3, View A
#define ADC1_RESRA3            (*((unsigned int volatile sdata *) 0xE156))

// Result Register 4, View A
#define ADC1_RESRA4            (*((unsigned int volatile sdata *) 0xE158))

// Result Register 5, View A
#define ADC1_RESRA5            (*((unsigned int volatile sdata *) 0xE15A))

// Result Register 6, View A
#define ADC1_RESRA6            (*((unsigned int volatile sdata *) 0xE15C))

// Result Register 7, View A
#define ADC1_RESRA7            (*((unsigned int volatile sdata *) 0xE15E))

// Result Register 0, View AV
#define ADC1_RESRAV0           (*((unsigned int volatile sdata *) 0xE170))

// Result Register 1, View AV
#define ADC1_RESRAV1           (*((unsigned int volatile sdata *) 0xE172))

// Result Register 2, View AV
#define ADC1_RESRAV2           (*((unsigned int volatile sdata *) 0xE174))

// Result Register 3, View AV
#define ADC1_RESRAV3           (*((unsigned int volatile sdata *) 0xE176))

// Result Register 4, View AV
#define ADC1_RESRAV4           (*((unsigned int volatile sdata *) 0xE178))

// Result Register 5, View AV
#define ADC1_RESRAV5           (*((unsigned int volatile sdata *) 0xE17A))

// Result Register 6, View AV
#define ADC1_RESRAV6           (*((unsigned int volatile sdata *) 0xE17C))

// Result Register 7, View AV
#define ADC1_RESRAV7           (*((unsigned int volatile sdata *) 0xE17E))

// Result Register 0, View V
#define ADC1_RESRV0            (*((unsigned int volatile sdata *) 0xE160))

// Result Register 1, View V
#define ADC1_RESRV1            (*((unsigned int volatile sdata *) 0xE162))

// Result Register 2, View V
#define ADC1_RESRV2            (*((unsigned int volatile sdata *) 0xE164))

// Result Register 3, View V
#define ADC1_RESRV3            (*((unsigned int volatile sdata *) 0xE166))

// Result Register 4, View V
#define ADC1_RESRV4            (*((unsigned int volatile sdata *) 0xE168))

// Result Register 5, View V
#define ADC1_RESRV5            (*((unsigned int volatile sdata *) 0xE16A))

// Result Register 6, View V
#define ADC1_RESRV6            (*((unsigned int volatile sdata *) 0xE16C))

// Result Register 7, View V
#define ADC1_RESRV7            (*((unsigned int volatile sdata *) 0xE16E))

// Request Source Priority Register 0
#define ADC1_RSPR0             (*((unsigned int volatile sdata *) 0xE114))

// Result Status Shadow Register
#define ADC1_RSSR              (*((unsigned int volatile sdata *) 0xE182))

// Synchronization Control Register
#define ADC1_SYNCTR            (*((unsigned int volatile sdata *) 0xE11A))

// Valid Flag Register
#define ADC1_VFR               (*((unsigned int volatile sdata *) 0xE180))

// ADC Interrupt Control Reg. 0
sfr  ADC_0IC                          = 0xFF70;
sbit ADC_0IC_GPX                      = ADC_0IC^8;
sbit ADC_0IC_IE                       = ADC_0IC^6;
sbit ADC_0IC_IR                       = ADC_0IC^7;

// ADC Interrupt Control Reg. 1
sfr  ADC_1IC                          = 0xFF72;
sbit ADC_1IC_GPX                      = ADC_1IC^8;
sbit ADC_1IC_IE                       = ADC_1IC^6;
sbit ADC_1IC_IR                       = ADC_1IC^7;

// ADC Interrupt Control Reg. 2
sfr  ADC_2IC                          = 0xFF74;
sbit ADC_2IC_GPX                      = ADC_2IC^8;
sbit ADC_2IC_IE                       = ADC_2IC^6;
sbit ADC_2IC_IR                       = ADC_2IC^7;

// ADC Interrupt Control Reg. 3
sfr  ADC_3IC                          = 0xFF76;
sbit ADC_3IC_GPX                      = ADC_3IC^8;
sbit ADC_3IC_IE                       = ADC_3IC^6;
sbit ADC_3IC_IR                       = ADC_3IC^7;

// ADC Interrupt Control Reg. 4
sfr  ADC_4IC                          = 0xFF78;
sbit ADC_4IC_GPX                      = ADC_4IC^8;
sbit ADC_4IC_IE                       = ADC_4IC^6;
sbit ADC_4IC_IR                       = ADC_4IC^7;

// ADC Interrupt Control Reg. 5
sfr  ADC_5IC                          = 0xFF7A;
sbit ADC_5IC_GPX                      = ADC_5IC^8;
sbit ADC_5IC_IE                       = ADC_5IC^6;
sbit ADC_5IC_IR                       = ADC_5IC^7;

// ADC Interrupt Control Reg. 6
sfr  ADC_6IC                          = 0xFF7C;
sbit ADC_6IC_GPX                      = ADC_6IC^8;
sbit ADC_6IC_IE                       = ADC_6IC^6;
sbit ADC_6IC_IR                       = ADC_6IC^7;

// ADC Interrupt Control Reg. 7
sfr  ADC_7IC                          = 0xFF7E;
sbit ADC_7IC_GPX                      = ADC_7IC^8;
sbit ADC_7IC_IE                       = ADC_7IC^6;
sbit ADC_7IC_IR                       = ADC_7IC^7;

// Register Bank Selection Reg. 0
#define BNKSEL0                (*((unsigned int volatile sdata *) 0xEC20))

// Register Bank Selection Reg. 1
#define BNKSEL1                (*((unsigned int volatile sdata *) 0xEC22))

// Register Bank Selection Reg. 2
#define BNKSEL2                (*((unsigned int volatile sdata *) 0xEC24))

// Register Bank Selection Reg. 3
#define BNKSEL3                (*((unsigned int volatile sdata *) 0xEC26))

// CAN Interrupt Control Reg. 0
sfr  CAN_0IC                          = 0xF140;
sbit CAN_0IC_GPX                      = CAN_0IC^8;
sbit CAN_0IC_IE                       = CAN_0IC^6;
sbit CAN_0IC_IR                       = CAN_0IC^7;

// CAN Interrupt Control Reg. 10
sfr  CAN_10IC                         = 0xF154;
sbit CAN_10IC_GPX                      = CAN_10IC^8;
sbit CAN_10IC_IE                       = CAN_10IC^6;
sbit CAN_10IC_IR                       = CAN_10IC^7;

// CAN Interrupt Control Reg. 11
sfr  CAN_11IC                         = 0xF156;
sbit CAN_11IC_GPX                      = CAN_11IC^8;
sbit CAN_11IC_IE                       = CAN_11IC^6;
sbit CAN_11IC_IR                       = CAN_11IC^7;

// CAN Interrupt Control Reg. 12
sfr  CAN_12IC                         = 0xF158;
sbit CAN_12IC_GPX                      = CAN_12IC^8;
sbit CAN_12IC_IE                       = CAN_12IC^6;
sbit CAN_12IC_IR                       = CAN_12IC^7;

// CAN Interrupt Control Reg. 13
sfr  CAN_13IC                         = 0xF15A;
sbit CAN_13IC_GPX                      = CAN_13IC^8;
sbit CAN_13IC_IE                       = CAN_13IC^6;
sbit CAN_13IC_IR                       = CAN_13IC^7;

// CAN Interrupt Control Reg. 14
sfr  CAN_14IC                         = 0xF15C;
sbit CAN_14IC_GPX                      = CAN_14IC^8;
sbit CAN_14IC_IE                       = CAN_14IC^6;
sbit CAN_14IC_IR                       = CAN_14IC^7;

// CAN Interrupt Control Reg. 15
sfr  CAN_15IC                         = 0xF15E;
sbit CAN_15IC_GPX                      = CAN_15IC^8;
sbit CAN_15IC_IE                       = CAN_15IC^6;
sbit CAN_15IC_IR                       = CAN_15IC^7;

// CAN Interrupt Control Reg. 1
sfr  CAN_1IC                          = 0xF142;
sbit CAN_1IC_GPX                      = CAN_1IC^8;
sbit CAN_1IC_IE                       = CAN_1IC^6;
sbit CAN_1IC_IR                       = CAN_1IC^7;

// CAN Interrupt Control Reg. 2
sfr  CAN_2IC                          = 0xF144;
sbit CAN_2IC_GPX                      = CAN_2IC^8;
sbit CAN_2IC_IE                       = CAN_2IC^6;
sbit CAN_2IC_IR                       = CAN_2IC^7;

// CAN Interrupt Control Reg. 3
sfr  CAN_3IC                          = 0xF146;
sbit CAN_3IC_GPX                      = CAN_3IC^8;
sbit CAN_3IC_IE                       = CAN_3IC^6;
sbit CAN_3IC_IR                       = CAN_3IC^7;

// CAN Interrupt Control Reg. 4
sfr  CAN_4IC                          = 0xF148;
sbit CAN_4IC_GPX                      = CAN_4IC^8;
sbit CAN_4IC_IE                       = CAN_4IC^6;
sbit CAN_4IC_IR                       = CAN_4IC^7;

// CAN Interrupt Control Reg. 5
sfr  CAN_5IC                          = 0xF14A;
sbit CAN_5IC_GPX                      = CAN_5IC^8;
sbit CAN_5IC_IE                       = CAN_5IC^6;
sbit CAN_5IC_IR                       = CAN_5IC^7;

// CAN Interrupt Control Reg. 6
sfr  CAN_6IC                          = 0xF14C;
sbit CAN_6IC_GPX                      = CAN_6IC^8;
sbit CAN_6IC_IE                       = CAN_6IC^6;
sbit CAN_6IC_IR                       = CAN_6IC^7;

// CAN Interrupt Control Reg. 7
sfr  CAN_7IC                          = 0xF14E;
sbit CAN_7IC_GPX                      = CAN_7IC^8;
sbit CAN_7IC_IE                       = CAN_7IC^6;
sbit CAN_7IC_IR                       = CAN_7IC^7;

// CAN Interrupt Control Reg. 8
sfr  CAN_8IC                          = 0xF150;
sbit CAN_8IC_GPX                      = CAN_8IC^8;
sbit CAN_8IC_IE                       = CAN_8IC^6;
sbit CAN_8IC_IR                       = CAN_8IC^7;

// CAN Interrupt Control Reg. 9
sfr  CAN_9IC                          = 0xF152;
sbit CAN_9IC_GPX                      = CAN_9IC^8;
sbit CAN_9IC_IE                       = CAN_9IC^6;
sbit CAN_9IC_IR                       = CAN_9IC^7;

// Fractional Divider Register H
#define CAN_FDRH               (*((unsigned int volatile huge *) 0x20000E))

// Fractional Divider Register L
#define CAN_FDRL               (*((unsigned int volatile huge *) 0x20000C))

// List Register 0 High
#define CAN_LIST0H             (*((unsigned int volatile huge *) 0x200102))

// List Register 0 Low
#define CAN_LIST0L             (*((unsigned int volatile huge *) 0x200100))

// List Register 1 High
#define CAN_LIST1H             (*((unsigned int volatile huge *) 0x200106))

// List Register 1 Low
#define CAN_LIST1L             (*((unsigned int volatile huge *) 0x200104))

// List Register 2 High
#define CAN_LIST2H             (*((unsigned int volatile huge *) 0x20010A))

// List Register 2 Low
#define CAN_LIST2L             (*((unsigned int volatile huge *) 0x200108))

// List Register 3 High
#define CAN_LIST3H             (*((unsigned int volatile huge *) 0x20010E))

// List Register 3 Low
#define CAN_LIST3L             (*((unsigned int volatile huge *) 0x20010C))

// List Register 4 High
#define CAN_LIST4H             (*((unsigned int volatile huge *) 0x200112))

// List Register 4 Low
#define CAN_LIST4L             (*((unsigned int volatile huge *) 0x200110))

// List Register 5 High
#define CAN_LIST5H             (*((unsigned int volatile huge *) 0x200116))

// List Register 5 Low
#define CAN_LIST5L             (*((unsigned int volatile huge *) 0x200114))

// List Register 6 High
#define CAN_LIST6H             (*((unsigned int volatile huge *) 0x20011A))

// List Register 6 Low
#define CAN_LIST6L             (*((unsigned int volatile huge *) 0x200118))

// List Register 7 High
#define CAN_LIST7H             (*((unsigned int volatile huge *) 0x20011E))

// List Register 7 Low
#define CAN_LIST7L             (*((unsigned int volatile huge *) 0x20011C))

// Module Control Register
#define CAN_MCR                (*((unsigned int volatile huge *) 0x2001C8))

// Module Interrupt Trigger Register
#define CAN_MITR               (*((unsigned int volatile huge *) 0x2001CC))

// Message Object 0 Acceptance Mask Register High
#define CAN_MOAMR0H            (*((unsigned int volatile huge *) 0x20100E))

// Message Object 0 Acceptance Mask Register Low
#define CAN_MOAMR0L            (*((unsigned int volatile huge *) 0x20100C))

// Message Object 100 Acceptance Mask Register High
#define CAN_MOAMR100H          (*((unsigned int volatile huge *) 0x201C8E))

// Message Object 100 Acceptance Mask Register Low
#define CAN_MOAMR100L          (*((unsigned int volatile huge *) 0x201C8C))

// Message Object 101 Acceptance Mask Register High
#define CAN_MOAMR101H          (*((unsigned int volatile huge *) 0x201CAE))

// Message Object 101 Acceptance Mask Register Low
#define CAN_MOAMR101L          (*((unsigned int volatile huge *) 0x201CAC))

// Message Object 102 Acceptance Mask Register High
#define CAN_MOAMR102H          (*((unsigned int volatile huge *) 0x201CCE))

// Message Object 102 Acceptance Mask Register Low
#define CAN_MOAMR102L          (*((unsigned int volatile huge *) 0x201CCC))

// Message Object 103 Acceptance Mask Register High
#define CAN_MOAMR103H          (*((unsigned int volatile huge *) 0x201CEE))

// Message Object 103 Acceptance Mask Register Low
#define CAN_MOAMR103L          (*((unsigned int volatile huge *) 0x201CEC))

// Message Object 104 Acceptance Mask Register High
#define CAN_MOAMR104H          (*((unsigned int volatile huge *) 0x201D0E))

// Message Object 104 Acceptance Mask Register Low
#define CAN_MOAMR104L          (*((unsigned int volatile huge *) 0x201D0C))

// Message Object 105 Acceptance Mask Register High
#define CAN_MOAMR105H          (*((unsigned int volatile huge *) 0x201D2E))

// Message Object 105 Acceptance Mask Register Low
#define CAN_MOAMR105L          (*((unsigned int volatile huge *) 0x201D2C))

// Message Object 106 Acceptance Mask Register High
#define CAN_MOAMR106H          (*((unsigned int volatile huge *) 0x201D4E))

// Message Object 106 Acceptance Mask Register Low
#define CAN_MOAMR106L          (*((unsigned int volatile huge *) 0x201D4C))

// Message Object 107 Acceptance Mask Register High
#define CAN_MOAMR107H          (*((unsigned int volatile huge *) 0x201D6E))

// Message Object 107 Acceptance Mask Register Low
#define CAN_MOAMR107L          (*((unsigned int volatile huge *) 0x201D6C))

// Message Object 108 Acceptance Mask Register High
#define CAN_MOAMR108H          (*((unsigned int volatile huge *) 0x201D8E))

// Message Object 108 Acceptance Mask Register Low
#define CAN_MOAMR108L          (*((unsigned int volatile huge *) 0x201D8C))

// Message Object 109 Acceptance Mask Register High
#define CAN_MOAMR109H          (*((unsigned int volatile huge *) 0x201DAE))

// Message Object 109 Acceptance Mask Register Low
#define CAN_MOAMR109L          (*((unsigned int volatile huge *) 0x201DAC))

// Message Object 10 Acceptance Mask Register High
#define CAN_MOAMR10H           (*((unsigned int volatile huge *) 0x20114E))

// Message Object 10 Acceptance Mask Register Low
#define CAN_MOAMR10L           (*((unsigned int volatile huge *) 0x20114C))

// Message Object 110 Acceptance Mask Register High
#define CAN_MOAMR110H          (*((unsigned int volatile huge *) 0x201DCE))

// Message Object 110 Acceptance Mask Register Low
#define CAN_MOAMR110L          (*((unsigned int volatile huge *) 0x201DCC))

// Message Object 111 Acceptance Mask Register High
#define CAN_MOAMR111H          (*((unsigned int volatile huge *) 0x201DEE))

// Message Object 111 Acceptance Mask Register Low
#define CAN_MOAMR111L          (*((unsigned int volatile huge *) 0x201DEC))

// Message Object 112 Acceptance Mask Register High
#define CAN_MOAMR112H          (*((unsigned int volatile huge *) 0x201E0E))

// Message Object 112 Acceptance Mask Register Low
#define CAN_MOAMR112L          (*((unsigned int volatile huge *) 0x201E0C))

// Message Object 113 Acceptance Mask Register High
#define CAN_MOAMR113H          (*((unsigned int volatile huge *) 0x201E2E))

// Message Object 113 Acceptance Mask Register Low
#define CAN_MOAMR113L          (*((unsigned int volatile huge *) 0x201E2C))

// Message Object 114 Acceptance Mask Register High
#define CAN_MOAMR114H          (*((unsigned int volatile huge *) 0x201E4E))

// Message Object 114 Acceptance Mask Register Low
#define CAN_MOAMR114L          (*((unsigned int volatile huge *) 0x201E4C))

// Message Object 115 Acceptance Mask Register High
#define CAN_MOAMR115H          (*((unsigned int volatile huge *) 0x201E6E))

// Message Object 115 Acceptance Mask Register Low
#define CAN_MOAMR115L          (*((unsigned int volatile huge *) 0x201E6C))

// Message Object 116 Acceptance Mask Register High
#define CAN_MOAMR116H          (*((unsigned int volatile huge *) 0x201E8E))

// Message Object 116 Acceptance Mask Register Low
#define CAN_MOAMR116L          (*((unsigned int volatile huge *) 0x201E8C))

// Message Object 117 Acceptance Mask Register High
#define CAN_MOAMR117H          (*((unsigned int volatile huge *) 0x201EAE))

// Message Object 117 Acceptance Mask Register Low
#define CAN_MOAMR117L          (*((unsigned int volatile huge *) 0x201EAC))

// Message Object 118 Acceptance Mask Register High
#define CAN_MOAMR118H          (*((unsigned int volatile huge *) 0x201ECE))

// Message Object 118 Acceptance Mask Register Low
#define CAN_MOAMR118L          (*((unsigned int volatile huge *) 0x201ECC))

// Message Object 119 Acceptance Mask Register High
#define CAN_MOAMR119H          (*((unsigned int volatile huge *) 0x201EEE))

// Message Object 119 Acceptance Mask Register Low
#define CAN_MOAMR119L          (*((unsigned int volatile huge *) 0x201EEC))

// Message Object 11 Acceptance Mask Register High
#define CAN_MOAMR11H           (*((unsigned int volatile huge *) 0x20116E))

// Message Object 11 Acceptance Mask Register Low
#define CAN_MOAMR11L           (*((unsigned int volatile huge *) 0x20116C))

// Message Object 120 Acceptance Mask Register High
#define CAN_MOAMR120H          (*((unsigned int volatile huge *) 0x201F0E))

// Message Object 120 Acceptance Mask Register Low
#define CAN_MOAMR120L          (*((unsigned int volatile huge *) 0x201F0C))

// Message Object 121 Acceptance Mask Register High
#define CAN_MOAMR121H          (*((unsigned int volatile huge *) 0x201F2E))

// Message Object 121 Acceptance Mask Register Low
#define CAN_MOAMR121L          (*((unsigned int volatile huge *) 0x201F2C))

// Message Object 122 Acceptance Mask Register High
#define CAN_MOAMR122H          (*((unsigned int volatile huge *) 0x201F4E))

// Message Object 122 Acceptance Mask Register Low
#define CAN_MOAMR122L          (*((unsigned int volatile huge *) 0x201F4C))

// Message Object 123 Acceptance Mask Register High
#define CAN_MOAMR123H          (*((unsigned int volatile huge *) 0x201F6E))

// Message Object 123 Acceptance Mask Register Low
#define CAN_MOAMR123L          (*((unsigned int volatile huge *) 0x201F6C))

// Message Object 124 Acceptance Mask Register High
#define CAN_MOAMR124H          (*((unsigned int volatile huge *) 0x201F8E))

// Message Object 124 Acceptance Mask Register Low
#define CAN_MOAMR124L          (*((unsigned int volatile huge *) 0x201F8C))

// Message Object 125 Acceptance Mask Register High
#define CAN_MOAMR125H          (*((unsigned int volatile huge *) 0x201FAE))

// Message Object 125 Acceptance Mask Register Low
#define CAN_MOAMR125L          (*((unsigned int volatile huge *) 0x201FAC))

// Message Object 126 Acceptance Mask Register High
#define CAN_MOAMR126H          (*((unsigned int volatile huge *) 0x201FCE))

// Message Object 126 Acceptance Mask Register Low
#define CAN_MOAMR126L          (*((unsigned int volatile huge *) 0x201FCC))

// Message Object 127 Acceptance Mask Register High
#define CAN_MOAMR127H          (*((unsigned int volatile huge *) 0x201FEE))

// Message Object 127 Acceptance Mask Register Low
#define CAN_MOAMR127L          (*((unsigned int volatile huge *) 0x201FEC))

// Message Object 12 Acceptance Mask Register High
#define CAN_MOAMR12H           (*((unsigned int volatile huge *) 0x20118E))

// Message Object 12 Acceptance Mask Register Low
#define CAN_MOAMR12L           (*((unsigned int volatile huge *) 0x20118C))

// Message Object 13 Acceptance Mask Register High
#define CAN_MOAMR13H           (*((unsigned int volatile huge *) 0x2011AE))

// Message Object 13 Acceptance Mask Register Low
#define CAN_MOAMR13L           (*((unsigned int volatile huge *) 0x2011AC))

// Message Object 14 Acceptance Mask Register High
#define CAN_MOAMR14H           (*((unsigned int volatile huge *) 0x2011CE))

// Message Object 14 Acceptance Mask Register Low
#define CAN_MOAMR14L           (*((unsigned int volatile huge *) 0x2011CC))

// Message Object 15 Acceptance Mask Register High
#define CAN_MOAMR15H           (*((unsigned int volatile huge *) 0x2011EE))

// Message Object 15 Acceptance Mask Register Low
#define CAN_MOAMR15L           (*((unsigned int volatile huge *) 0x2011EC))

// Message Object 16 Acceptance Mask Register High
#define CAN_MOAMR16H           (*((unsigned int volatile huge *) 0x20120E))

// Message Object 16 Acceptance Mask Register Low
#define CAN_MOAMR16L           (*((unsigned int volatile huge *) 0x20120C))

// Message Object 17 Acceptance Mask Register High
#define CAN_MOAMR17H           (*((unsigned int volatile huge *) 0x20122E))

// Message Object 17 Acceptance Mask Register Low
#define CAN_MOAMR17L           (*((unsigned int volatile huge *) 0x20122C))

// Message Object 18 Acceptance Mask Register High
#define CAN_MOAMR18H           (*((unsigned int volatile huge *) 0x20124E))

// Message Object 18 Acceptance Mask Register Low
#define CAN_MOAMR18L           (*((unsigned int volatile huge *) 0x20124C))

// Message Object 19 Acceptance Mask Register High
#define CAN_MOAMR19H           (*((unsigned int volatile huge *) 0x20126E))

// Message Object 19 Acceptance Mask Register Low
#define CAN_MOAMR19L           (*((unsigned int volatile huge *) 0x20126C))

// Message Object 1 Acceptance Mask Register High
#define CAN_MOAMR1H            (*((unsigned int volatile huge *) 0x20102E))

// Message Object 1 Acceptance Mask Register Low
#define CAN_MOAMR1L            (*((unsigned int volatile huge *) 0x20102C))

// Message Object 20 Acceptance Mask Register High
#define CAN_MOAMR20H           (*((unsigned int volatile huge *) 0x20128E))

// Message Object 20 Acceptance Mask Register Low
#define CAN_MOAMR20L           (*((unsigned int volatile huge *) 0x20128C))

// Message Object 21 Acceptance Mask Register High
#define CAN_MOAMR21H           (*((unsigned int volatile huge *) 0x2012AE))

// Message Object 21 Acceptance Mask Register Low
#define CAN_MOAMR21L           (*((unsigned int volatile huge *) 0x2012AC))

// Message Object 22 Acceptance Mask Register High
#define CAN_MOAMR22H           (*((unsigned int volatile huge *) 0x2012CE))

// Message Object 22 Acceptance Mask Register Low
#define CAN_MOAMR22L           (*((unsigned int volatile huge *) 0x2012CC))

// Message Object 23 Acceptance Mask Register High
#define CAN_MOAMR23H           (*((unsigned int volatile huge *) 0x2012EE))

// Message Object 23 Acceptance Mask Register Low
#define CAN_MOAMR23L           (*((unsigned int volatile huge *) 0x2012EC))

// Message Object 24 Acceptance Mask Register High
#define CAN_MOAMR24H           (*((unsigned int volatile huge *) 0x20130E))

// Message Object 24 Acceptance Mask Register Low
#define CAN_MOAMR24L           (*((unsigned int volatile huge *) 0x20130C))

// Message Object 25 Acceptance Mask Register High
#define CAN_MOAMR25H           (*((unsigned int volatile huge *) 0x20132E))

// Message Object 25 Acceptance Mask Register Low
#define CAN_MOAMR25L           (*((unsigned int volatile huge *) 0x20132C))

// Message Object 26 Acceptance Mask Register High
#define CAN_MOAMR26H           (*((unsigned int volatile huge *) 0x20134E))

// Message Object 26 Acceptance Mask Register Low
#define CAN_MOAMR26L           (*((unsigned int volatile huge *) 0x20134C))

// Message Object 27 Acceptance Mask Register High
#define CAN_MOAMR27H           (*((unsigned int volatile huge *) 0x20136E))

// Message Object 27 Acceptance Mask Register Low
#define CAN_MOAMR27L           (*((unsigned int volatile huge *) 0x20136C))

// Message Object 28 Acceptance Mask Register High
#define CAN_MOAMR28H           (*((unsigned int volatile huge *) 0x20138E))

// Message Object 28 Acceptance Mask Register Low
#define CAN_MOAMR28L           (*((unsigned int volatile huge *) 0x20138C))

// Message Object 29 Acceptance Mask Register High
#define CAN_MOAMR29H           (*((unsigned int volatile huge *) 0x2013AE))

// Message Object 29 Acceptance Mask Register Low
#define CAN_MOAMR29L           (*((unsigned int volatile huge *) 0x2013AC))

// Message Object 2 Acceptance Mask Register High
#define CAN_MOAMR2H            (*((unsigned int volatile huge *) 0x20104E))

// Message Object 2 Acceptance Mask Register Low
#define CAN_MOAMR2L            (*((unsigned int volatile huge *) 0x20104C))

// Message Object 30 Acceptance Mask Register High
#define CAN_MOAMR30H           (*((unsigned int volatile huge *) 0x2013CE))

// Message Object 30 Acceptance Mask Register Low
#define CAN_MOAMR30L           (*((unsigned int volatile huge *) 0x2013CC))

// Message Object 31 Acceptance Mask Register High
#define CAN_MOAMR31H           (*((unsigned int volatile huge *) 0x2013EE))

// Message Object 31 Acceptance Mask Register Low
#define CAN_MOAMR31L           (*((unsigned int volatile huge *) 0x2013EC))

// Message Object 32 Acceptance Mask Register High
#define CAN_MOAMR32H           (*((unsigned int volatile huge *) 0x20140E))

// Message Object 32 Acceptance Mask Register Low
#define CAN_MOAMR32L           (*((unsigned int volatile huge *) 0x20140C))

// Message Object 33 Acceptance Mask Register High
#define CAN_MOAMR33H           (*((unsigned int volatile huge *) 0x20142E))

// Message Object 33 Acceptance Mask Register Low
#define CAN_MOAMR33L           (*((unsigned int volatile huge *) 0x20142C))

// Message Object 34 Acceptance Mask Register High
#define CAN_MOAMR34H           (*((unsigned int volatile huge *) 0x20144E))

// Message Object 34 Acceptance Mask Register Low
#define CAN_MOAMR34L           (*((unsigned int volatile huge *) 0x20144C))

// Message Object 35 Acceptance Mask Register High
#define CAN_MOAMR35H           (*((unsigned int volatile huge *) 0x20146E))

// Message Object 35 Acceptance Mask Register Low
#define CAN_MOAMR35L           (*((unsigned int volatile huge *) 0x20146C))

// Message Object 36 Acceptance Mask Register High
#define CAN_MOAMR36H           (*((unsigned int volatile huge *) 0x20148E))

// Message Object 36 Acceptance Mask Register Low
#define CAN_MOAMR36L           (*((unsigned int volatile huge *) 0x20148C))

// Message Object 37 Acceptance Mask Register High
#define CAN_MOAMR37H           (*((unsigned int volatile huge *) 0x2014AE))

// Message Object 37 Acceptance Mask Register Low
#define CAN_MOAMR37L           (*((unsigned int volatile huge *) 0x2014AC))

// Message Object 38 Acceptance Mask Register High
#define CAN_MOAMR38H           (*((unsigned int volatile huge *) 0x2014CE))

// Message Object 38 Acceptance Mask Register Low
#define CAN_MOAMR38L           (*((unsigned int volatile huge *) 0x2014CC))

// Message Object 39 Acceptance Mask Register High
#define CAN_MOAMR39H           (*((unsigned int volatile huge *) 0x2014EE))

// Message Object 39 Acceptance Mask Register Low
#define CAN_MOAMR39L           (*((unsigned int volatile huge *) 0x2014EC))

// Message Object 3 Acceptance Mask Register High
#define CAN_MOAMR3H            (*((unsigned int volatile huge *) 0x20106E))

// Message Object 3 Acceptance Mask Register Low
#define CAN_MOAMR3L            (*((unsigned int volatile huge *) 0x20106C))

// Message Object 40 Acceptance Mask Register High
#define CAN_MOAMR40H           (*((unsigned int volatile huge *) 0x20150E))

// Message Object 40 Acceptance Mask Register Low
#define CAN_MOAMR40L           (*((unsigned int volatile huge *) 0x20150C))

// Message Object 41 Acceptance Mask Register High
#define CAN_MOAMR41H           (*((unsigned int volatile huge *) 0x20152E))

// Message Object 41 Acceptance Mask Register Low
#define CAN_MOAMR41L           (*((unsigned int volatile huge *) 0x20152C))

// Message Object 42 Acceptance Mask Register High
#define CAN_MOAMR42H           (*((unsigned int volatile huge *) 0x20154E))

// Message Object 42 Acceptance Mask Register Low
#define CAN_MOAMR42L           (*((unsigned int volatile huge *) 0x20154C))

// Message Object 43 Acceptance Mask Register High
#define CAN_MOAMR43H           (*((unsigned int volatile huge *) 0x20156E))

// Message Object 43 Acceptance Mask Register Low
#define CAN_MOAMR43L           (*((unsigned int volatile huge *) 0x20156C))

// Message Object 44 Acceptance Mask Register High
#define CAN_MOAMR44H           (*((unsigned int volatile huge *) 0x20158E))

// Message Object 44 Acceptance Mask Register Low
#define CAN_MOAMR44L           (*((unsigned int volatile huge *) 0x20158C))

// Message Object 45 Acceptance Mask Register High
#define CAN_MOAMR45H           (*((unsigned int volatile huge *) 0x2015AE))

// Message Object 45 Acceptance Mask Register Low
#define CAN_MOAMR45L           (*((unsigned int volatile huge *) 0x2015AC))

// Message Object 46 Acceptance Mask Register High
#define CAN_MOAMR46H           (*((unsigned int volatile huge *) 0x2015CE))

// Message Object 46 Acceptance Mask Register Low
#define CAN_MOAMR46L           (*((unsigned int volatile huge *) 0x2015CC))

// Message Object 47 Acceptance Mask Register High
#define CAN_MOAMR47H           (*((unsigned int volatile huge *) 0x2015EE))

// Message Object 47 Acceptance Mask Register Low
#define CAN_MOAMR47L           (*((unsigned int volatile huge *) 0x2015EC))

// Message Object 48 Acceptance Mask Register High
#define CAN_MOAMR48H           (*((unsigned int volatile huge *) 0x20160E))

// Message Object 48 Acceptance Mask Register Low
#define CAN_MOAMR48L           (*((unsigned int volatile huge *) 0x20160C))

// Message Object 49 Acceptance Mask Register High
#define CAN_MOAMR49H           (*((unsigned int volatile huge *) 0x20162E))

// Message Object 49 Acceptance Mask Register Low
#define CAN_MOAMR49L           (*((unsigned int volatile huge *) 0x20162C))

// Message Object 4 Acceptance Mask Register High
#define CAN_MOAMR4H            (*((unsigned int volatile huge *) 0x20108E))

// Message Object 4 Acceptance Mask Register Low
#define CAN_MOAMR4L            (*((unsigned int volatile huge *) 0x20108C))

// Message Object 50 Acceptance Mask Register High
#define CAN_MOAMR50H           (*((unsigned int volatile huge *) 0x20164E))

// Message Object 50 Acceptance Mask Register Low
#define CAN_MOAMR50L           (*((unsigned int volatile huge *) 0x20164C))

// Message Object 51 Acceptance Mask Register High
#define CAN_MOAMR51H           (*((unsigned int volatile huge *) 0x20166E))

// Message Object 51 Acceptance Mask Register Low
#define CAN_MOAMR51L           (*((unsigned int volatile huge *) 0x20166C))

// Message Object 52 Acceptance Mask Register High
#define CAN_MOAMR52H           (*((unsigned int volatile huge *) 0x20168E))

// Message Object 52 Acceptance Mask Register Low
#define CAN_MOAMR52L           (*((unsigned int volatile huge *) 0x20168C))

// Message Object 53 Acceptance Mask Register High
#define CAN_MOAMR53H           (*((unsigned int volatile huge *) 0x2016AE))

// Message Object 53 Acceptance Mask Register Low
#define CAN_MOAMR53L           (*((unsigned int volatile huge *) 0x2016AC))

// Message Object 54 Acceptance Mask Register High
#define CAN_MOAMR54H           (*((unsigned int volatile huge *) 0x2016CE))

// Message Object 54 Acceptance Mask Register Low
#define CAN_MOAMR54L           (*((unsigned int volatile huge *) 0x2016CC))

// Message Object 55 Acceptance Mask Register High
#define CAN_MOAMR55H           (*((unsigned int volatile huge *) 0x2016EE))

// Message Object 55 Acceptance Mask Register Low
#define CAN_MOAMR55L           (*((unsigned int volatile huge *) 0x2016EC))

// Message Object 56 Acceptance Mask Register High
#define CAN_MOAMR56H           (*((unsigned int volatile huge *) 0x20170E))

// Message Object 56 Acceptance Mask Register Low
#define CAN_MOAMR56L           (*((unsigned int volatile huge *) 0x20170C))

// Message Object 57 Acceptance Mask Register High
#define CAN_MOAMR57H           (*((unsigned int volatile huge *) 0x20172E))

// Message Object 57 Acceptance Mask Register Low
#define CAN_MOAMR57L           (*((unsigned int volatile huge *) 0x20172C))

// Message Object 58 Acceptance Mask Register High
#define CAN_MOAMR58H           (*((unsigned int volatile huge *) 0x20174E))

// Message Object 58 Acceptance Mask Register Low
#define CAN_MOAMR58L           (*((unsigned int volatile huge *) 0x20174C))

// Message Object 59 Acceptance Mask Register High
#define CAN_MOAMR59H           (*((unsigned int volatile huge *) 0x20176E))

// Message Object 59 Acceptance Mask Register Low
#define CAN_MOAMR59L           (*((unsigned int volatile huge *) 0x20176C))

// Message Object 5 Acceptance Mask Register High
#define CAN_MOAMR5H            (*((unsigned int volatile huge *) 0x2010AE))

// Message Object 5 Acceptance Mask Register Low
#define CAN_MOAMR5L            (*((unsigned int volatile huge *) 0x2010AC))

// Message Object 60 Acceptance Mask Register High
#define CAN_MOAMR60H           (*((unsigned int volatile huge *) 0x20178E))

// Message Object 60 Acceptance Mask Register Low
#define CAN_MOAMR60L           (*((unsigned int volatile huge *) 0x20178C))

// Message Object 61 Acceptance Mask Register High
#define CAN_MOAMR61H           (*((unsigned int volatile huge *) 0x2017AE))

// Message Object 61 Acceptance Mask Register Low
#define CAN_MOAMR61L           (*((unsigned int volatile huge *) 0x2017AC))

// Message Object 62 Acceptance Mask Register High
#define CAN_MOAMR62H           (*((unsigned int volatile huge *) 0x2017CE))

// Message Object 62 Acceptance Mask Register Low
#define CAN_MOAMR62L           (*((unsigned int volatile huge *) 0x2017CC))

// Message Object 63 Acceptance Mask Register High
#define CAN_MOAMR63H           (*((unsigned int volatile huge *) 0x2017EE))

// Message Object 63 Acceptance Mask Register Low
#define CAN_MOAMR63L           (*((unsigned int volatile huge *) 0x2017EC))

// Message Object 64 Acceptance Mask Register High
#define CAN_MOAMR64H           (*((unsigned int volatile huge *) 0x20180E))

// Message Object 64 Acceptance Mask Register Low
#define CAN_MOAMR64L           (*((unsigned int volatile huge *) 0x20180C))

// Message Object 65 Acceptance Mask Register High
#define CAN_MOAMR65H           (*((unsigned int volatile huge *) 0x20182E))

// Message Object 65 Acceptance Mask Register Low
#define CAN_MOAMR65L           (*((unsigned int volatile huge *) 0x20182C))

// Message Object 66 Acceptance Mask Register High
#define CAN_MOAMR66H           (*((unsigned int volatile huge *) 0x20184E))

// Message Object 66 Acceptance Mask Register Low
#define CAN_MOAMR66L           (*((unsigned int volatile huge *) 0x20184C))

// Message Object 67 Acceptance Mask Register High
#define CAN_MOAMR67H           (*((unsigned int volatile huge *) 0x20186E))

// Message Object 67 Acceptance Mask Register Low
#define CAN_MOAMR67L           (*((unsigned int volatile huge *) 0x20186C))

// Message Object 68 Acceptance Mask Register High
#define CAN_MOAMR68H           (*((unsigned int volatile huge *) 0x20188E))

// Message Object 68 Acceptance Mask Register Low
#define CAN_MOAMR68L           (*((unsigned int volatile huge *) 0x20188C))

// Message Object 69 Acceptance Mask Register High
#define CAN_MOAMR69H           (*((unsigned int volatile huge *) 0x2018AE))

// Message Object 69 Acceptance Mask Register Low
#define CAN_MOAMR69L           (*((unsigned int volatile huge *) 0x2018AC))

// Message Object 6 Acceptance Mask Register High
#define CAN_MOAMR6H            (*((unsigned int volatile huge *) 0x2010CE))

// Message Object 6 Acceptance Mask Register Low
#define CAN_MOAMR6L            (*((unsigned int volatile huge *) 0x2010CC))

// Message Object 70 Acceptance Mask Register High
#define CAN_MOAMR70H           (*((unsigned int volatile huge *) 0x2018CE))

// Message Object 70 Acceptance Mask Register Low
#define CAN_MOAMR70L           (*((unsigned int volatile huge *) 0x2018CC))

// Message Object 71 Acceptance Mask Register High
#define CAN_MOAMR71H           (*((unsigned int volatile huge *) 0x2018EE))

// Message Object 71 Acceptance Mask Register Low
#define CAN_MOAMR71L           (*((unsigned int volatile huge *) 0x2018EC))

// Message Object 72 Acceptance Mask Register High
#define CAN_MOAMR72H           (*((unsigned int volatile huge *) 0x20190E))

// Message Object 72 Acceptance Mask Register Low
#define CAN_MOAMR72L           (*((unsigned int volatile huge *) 0x20190C))

// Message Object 73 Acceptance Mask Register High
#define CAN_MOAMR73H           (*((unsigned int volatile huge *) 0x20192E))

// Message Object 73 Acceptance Mask Register Low
#define CAN_MOAMR73L           (*((unsigned int volatile huge *) 0x20192C))

// Message Object 74 Acceptance Mask Register High
#define CAN_MOAMR74H           (*((unsigned int volatile huge *) 0x20194E))

// Message Object 74 Acceptance Mask Register Low
#define CAN_MOAMR74L           (*((unsigned int volatile huge *) 0x20194C))

// Message Object 75 Acceptance Mask Register High
#define CAN_MOAMR75H           (*((unsigned int volatile huge *) 0x20196E))

// Message Object 75 Acceptance Mask Register Low
#define CAN_MOAMR75L           (*((unsigned int volatile huge *) 0x20196C))

// Message Object 76 Acceptance Mask Register High
#define CAN_MOAMR76H           (*((unsigned int volatile huge *) 0x20198E))

// Message Object 76 Acceptance Mask Register Low
#define CAN_MOAMR76L           (*((unsigned int volatile huge *) 0x20198C))

// Message Object 77 Acceptance Mask Register High
#define CAN_MOAMR77H           (*((unsigned int volatile huge *) 0x2019AE))

// Message Object 77 Acceptance Mask Register Low
#define CAN_MOAMR77L           (*((unsigned int volatile huge *) 0x2019AC))

// Message Object 78 Acceptance Mask Register High
#define CAN_MOAMR78H           (*((unsigned int volatile huge *) 0x2019CE))

// Message Object 78 Acceptance Mask Register Low
#define CAN_MOAMR78L           (*((unsigned int volatile huge *) 0x2019CC))

// Message Object 79 Acceptance Mask Register High
#define CAN_MOAMR79H           (*((unsigned int volatile huge *) 0x2019EE))

// Message Object 79 Acceptance Mask Register Low
#define CAN_MOAMR79L           (*((unsigned int volatile huge *) 0x2019EC))

// Message Object 7 Acceptance Mask Register High
#define CAN_MOAMR7H            (*((unsigned int volatile huge *) 0x2010EE))

// Message Object 7 Acceptance Mask Register Low
#define CAN_MOAMR7L            (*((unsigned int volatile huge *) 0x2010EC))

// Message Object 80 Acceptance Mask Register High
#define CAN_MOAMR80H           (*((unsigned int volatile huge *) 0x201A0E))

// Message Object 80 Acceptance Mask Register Low
#define CAN_MOAMR80L           (*((unsigned int volatile huge *) 0x201A0C))

// Message Object 81 Acceptance Mask Register High
#define CAN_MOAMR81H           (*((unsigned int volatile huge *) 0x201A2E))

// Message Object 81 Acceptance Mask Register Low
#define CAN_MOAMR81L           (*((unsigned int volatile huge *) 0x201A2C))

// Message Object 82 Acceptance Mask Register High
#define CAN_MOAMR82H           (*((unsigned int volatile huge *) 0x201A4E))

// Message Object 82 Acceptance Mask Register Low
#define CAN_MOAMR82L           (*((unsigned int volatile huge *) 0x201A4C))

// Message Object 83 Acceptance Mask Register High
#define CAN_MOAMR83H           (*((unsigned int volatile huge *) 0x201A6E))

// Message Object 83 Acceptance Mask Register Low
#define CAN_MOAMR83L           (*((unsigned int volatile huge *) 0x201A6C))

// Message Object 84 Acceptance Mask Register High
#define CAN_MOAMR84H           (*((unsigned int volatile huge *) 0x201A8E))

// Message Object 84 Acceptance Mask Register Low
#define CAN_MOAMR84L           (*((unsigned int volatile huge *) 0x201A8C))

// Message Object 85 Acceptance Mask Register High
#define CAN_MOAMR85H           (*((unsigned int volatile huge *) 0x201AAE))

// Message Object 85 Acceptance Mask Register Low
#define CAN_MOAMR85L           (*((unsigned int volatile huge *) 0x201AAC))

// Message Object 86 Acceptance Mask Register High
#define CAN_MOAMR86H           (*((unsigned int volatile huge *) 0x201ACE))

// Message Object 86 Acceptance Mask Register Low
#define CAN_MOAMR86L           (*((unsigned int volatile huge *) 0x201ACC))

// Message Object 87 Acceptance Mask Register High
#define CAN_MOAMR87H           (*((unsigned int volatile huge *) 0x201AEE))

// Message Object 87 Acceptance Mask Register Low
#define CAN_MOAMR87L           (*((unsigned int volatile huge *) 0x201AEC))

// Message Object 88 Acceptance Mask Register High
#define CAN_MOAMR88H           (*((unsigned int volatile huge *) 0x201B0E))

// Message Object 88 Acceptance Mask Register Low
#define CAN_MOAMR88L           (*((unsigned int volatile huge *) 0x201B0C))

// Message Object 89 Acceptance Mask Register High
#define CAN_MOAMR89H           (*((unsigned int volatile huge *) 0x201B2E))

// Message Object 89 Acceptance Mask Register Low
#define CAN_MOAMR89L           (*((unsigned int volatile huge *) 0x201B2C))

// Message Object 8 Acceptance Mask Register High
#define CAN_MOAMR8H            (*((unsigned int volatile huge *) 0x20110E))

// Message Object 8 Acceptance Mask Register Low
#define CAN_MOAMR8L            (*((unsigned int volatile huge *) 0x20110C))

// Message Object 90 Acceptance Mask Register High
#define CAN_MOAMR90H           (*((unsigned int volatile huge *) 0x201B4E))

// Message Object 90 Acceptance Mask Register Low
#define CAN_MOAMR90L           (*((unsigned int volatile huge *) 0x201B4C))

// Message Object 91 Acceptance Mask Register High
#define CAN_MOAMR91H           (*((unsigned int volatile huge *) 0x201B6E))

// Message Object 91 Acceptance Mask Register Low
#define CAN_MOAMR91L           (*((unsigned int volatile huge *) 0x201B6C))

// Message Object 92 Acceptance Mask Register High
#define CAN_MOAMR92H           (*((unsigned int volatile huge *) 0x201B8E))

// Message Object 92 Acceptance Mask Register Low
#define CAN_MOAMR92L           (*((unsigned int volatile huge *) 0x201B8C))

// Message Object 93 Acceptance Mask Register High
#define CAN_MOAMR93H           (*((unsigned int volatile huge *) 0x201BAE))

// Message Object 93 Acceptance Mask Register Low
#define CAN_MOAMR93L           (*((unsigned int volatile huge *) 0x201BAC))

// Message Object 94 Acceptance Mask Register High
#define CAN_MOAMR94H           (*((unsigned int volatile huge *) 0x201BCE))

// Message Object 94 Acceptance Mask Register Low
#define CAN_MOAMR94L           (*((unsigned int volatile huge *) 0x201BCC))

// Message Object 95 Acceptance Mask Register High
#define CAN_MOAMR95H           (*((unsigned int volatile huge *) 0x201BEE))

// Message Object 95 Acceptance Mask Register Low
#define CAN_MOAMR95L           (*((unsigned int volatile huge *) 0x201BEC))

// Message Object 96 Acceptance Mask Register High
#define CAN_MOAMR96H           (*((unsigned int volatile huge *) 0x201C0E))

// Message Object 96 Acceptance Mask Register Low
#define CAN_MOAMR96L           (*((unsigned int volatile huge *) 0x201C0C))

// Message Object 97 Acceptance Mask Register High
#define CAN_MOAMR97H           (*((unsigned int volatile huge *) 0x201C2E))

// Message Object 97 Acceptance Mask Register Low
#define CAN_MOAMR97L           (*((unsigned int volatile huge *) 0x201C2C))

// Message Object 98 Acceptance Mask Register High
#define CAN_MOAMR98H           (*((unsigned int volatile huge *) 0x201C4E))

// Message Object 98 Acceptance Mask Register Low
#define CAN_MOAMR98L           (*((unsigned int volatile huge *) 0x201C4C))

// Message Object 99 Acceptance Mask Register High
#define CAN_MOAMR99H           (*((unsigned int volatile huge *) 0x201C6E))

// Message Object 99 Acceptance Mask Register Low
#define CAN_MOAMR99L           (*((unsigned int volatile huge *) 0x201C6C))

// Message Object 9 Acceptance Mask Register High
#define CAN_MOAMR9H            (*((unsigned int volatile huge *) 0x20112E))

// Message Object 9 Acceptance Mask Register Low
#define CAN_MOAMR9L            (*((unsigned int volatile huge *) 0x20112C))

// Message Object 0 Arbitration Register High
#define CAN_MOAR0H             (*((unsigned int volatile huge *) 0x20101A))

// Message Object 0 Arbitration Register Low
#define CAN_MOAR0L             (*((unsigned int volatile huge *) 0x201018))

// Message Object 100 Arbitration Register High
#define CAN_MOAR100H           (*((unsigned int volatile huge *) 0x201C9A))

// Message Object 100 Arbitration Register Low
#define CAN_MOAR100L           (*((unsigned int volatile huge *) 0x201C98))

// Message Object 101 Arbitration Register High
#define CAN_MOAR101H           (*((unsigned int volatile huge *) 0x201CBA))

// Message Object 101 Arbitration Register Low
#define CAN_MOAR101L           (*((unsigned int volatile huge *) 0x201CB8))

// Message Object 102 Arbitration Register High
#define CAN_MOAR102H           (*((unsigned int volatile huge *) 0x201CDA))

// Message Object 102 Arbitration Register Low
#define CAN_MOAR102L           (*((unsigned int volatile huge *) 0x201CD8))

// Message Object 103 Arbitration Register High
#define CAN_MOAR103H           (*((unsigned int volatile huge *) 0x201CFA))

// Message Object 103 Arbitration Register Low
#define CAN_MOAR103L           (*((unsigned int volatile huge *) 0x201CF8))

// Message Object 104 Arbitration Register High
#define CAN_MOAR104H           (*((unsigned int volatile huge *) 0x201D1A))

// Message Object 104 Arbitration Register Low
#define CAN_MOAR104L           (*((unsigned int volatile huge *) 0x201D18))

// Message Object 105 Arbitration Register High
#define CAN_MOAR105H           (*((unsigned int volatile huge *) 0x201D3A))

// Message Object 105 Arbitration Register Low
#define CAN_MOAR105L           (*((unsigned int volatile huge *) 0x201D38))

// Message Object 106 Arbitration Register High
#define CAN_MOAR106H           (*((unsigned int volatile huge *) 0x201D5A))

// Message Object 106 Arbitration Register Low
#define CAN_MOAR106L           (*((unsigned int volatile huge *) 0x201D58))

// Message Object 107 Arbitration Register High
#define CAN_MOAR107H           (*((unsigned int volatile huge *) 0x201D7A))

// Message Object 107 Arbitration Register Low
#define CAN_MOAR107L           (*((unsigned int volatile huge *) 0x201D78))

// Message Object 108 Arbitration Register High
#define CAN_MOAR108H           (*((unsigned int volatile huge *) 0x201D9A))

// Message Object 108 Arbitration Register Low
#define CAN_MOAR108L           (*((unsigned int volatile huge *) 0x201D98))

// Message Object 109 Arbitration Register High
#define CAN_MOAR109H           (*((unsigned int volatile huge *) 0x201DBA))

// Message Object 109 Arbitration Register Low
#define CAN_MOAR109L           (*((unsigned int volatile huge *) 0x201DB8))

// Message Object 10 Arbitration Register High
#define CAN_MOAR10H            (*((unsigned int volatile huge *) 0x20115A))

// Message Object 10 Arbitration Register Low
#define CAN_MOAR10L            (*((unsigned int volatile huge *) 0x201158))

// Message Object 110 Arbitration Register High
#define CAN_MOAR110H           (*((unsigned int volatile huge *) 0x201DDA))

// Message Object 110 Arbitration Register Low
#define CAN_MOAR110L           (*((unsigned int volatile huge *) 0x201DD8))

// Message Object 111 Arbitration Register High
#define CAN_MOAR111H           (*((unsigned int volatile huge *) 0x201DFA))

// Message Object 111 Arbitration Register Low
#define CAN_MOAR111L           (*((unsigned int volatile huge *) 0x201DF8))

// Message Object 112 Arbitration Register High
#define CAN_MOAR112H           (*((unsigned int volatile huge *) 0x201E1A))

// Message Object 112 Arbitration Register Low
#define CAN_MOAR112L           (*((unsigned int volatile huge *) 0x201E18))

// Message Object 113 Arbitration Register High
#define CAN_MOAR113H           (*((unsigned int volatile huge *) 0x201E3A))

// Message Object 113 Arbitration Register Low
#define CAN_MOAR113L           (*((unsigned int volatile huge *) 0x201E38))

// Message Object 114 Arbitration Register High
#define CAN_MOAR114H           (*((unsigned int volatile huge *) 0x201E5A))

// Message Object 114 Arbitration Register Low
#define CAN_MOAR114L           (*((unsigned int volatile huge *) 0x201E58))

// Message Object 115 Arbitration Register High
#define CAN_MOAR115H           (*((unsigned int volatile huge *) 0x201E7A))

// Message Object 115 Arbitration Register Low
#define CAN_MOAR115L           (*((unsigned int volatile huge *) 0x201E78))

// Message Object 116 Arbitration Register High
#define CAN_MOAR116H           (*((unsigned int volatile huge *) 0x201E9A))

// Message Object 116 Arbitration Register Low
#define CAN_MOAR116L           (*((unsigned int volatile huge *) 0x201E98))

// Message Object 117 Arbitration Register High
#define CAN_MOAR117H           (*((unsigned int volatile huge *) 0x201EBA))

// Message Object 117 Arbitration Register Low
#define CAN_MOAR117L           (*((unsigned int volatile huge *) 0x201EB8))

// Message Object 118 Arbitration Register High
#define CAN_MOAR118H           (*((unsigned int volatile huge *) 0x201EDA))

// Message Object 118 Arbitration Register Low
#define CAN_MOAR118L           (*((unsigned int volatile huge *) 0x201ED8))

// Message Object 119 Arbitration Register High
#define CAN_MOAR119H           (*((unsigned int volatile huge *) 0x201EFA))

// Message Object 119 Arbitration Register Low
#define CAN_MOAR119L           (*((unsigned int volatile huge *) 0x201EF8))

// Message Object 11 Arbitration Register High
#define CAN_MOAR11H            (*((unsigned int volatile huge *) 0x20117A))

// Message Object 11 Arbitration Register Low
#define CAN_MOAR11L            (*((unsigned int volatile huge *) 0x201178))

// Message Object 120 Arbitration Register High
#define CAN_MOAR120H           (*((unsigned int volatile huge *) 0x201F1A))

// Message Object 120 Arbitration Register Low
#define CAN_MOAR120L           (*((unsigned int volatile huge *) 0x201F18))

// Message Object 121 Arbitration Register High
#define CAN_MOAR121H           (*((unsigned int volatile huge *) 0x201F3A))

// Message Object 121 Arbitration Register Low
#define CAN_MOAR121L           (*((unsigned int volatile huge *) 0x201F38))

// Message Object 122 Arbitration Register High
#define CAN_MOAR122H           (*((unsigned int volatile huge *) 0x201F5A))

// Message Object 122 Arbitration Register Low
#define CAN_MOAR122L           (*((unsigned int volatile huge *) 0x201F58))

// Message Object 123 Arbitration Register High
#define CAN_MOAR123H           (*((unsigned int volatile huge *) 0x201F7A))

// Message Object 123 Arbitration Register Low
#define CAN_MOAR123L           (*((unsigned int volatile huge *) 0x201F78))

// Message Object 124 Arbitration Register High
#define CAN_MOAR124H           (*((unsigned int volatile huge *) 0x201F9A))

// Message Object 124 Arbitration Register Low
#define CAN_MOAR124L           (*((unsigned int volatile huge *) 0x201F98))

// Message Object 125 Arbitration Register High
#define CAN_MOAR125H           (*((unsigned int volatile huge *) 0x201FBA))

// Message Object 125 Arbitration Register Low
#define CAN_MOAR125L           (*((unsigned int volatile huge *) 0x201FB8))

// Message Object 126 Arbitration Register High
#define CAN_MOAR126H           (*((unsigned int volatile huge *) 0x201FDA))

// Message Object 126 Arbitration Register Low
#define CAN_MOAR126L           (*((unsigned int volatile huge *) 0x201FD8))

// Message Object 127 Arbitration Register High
#define CAN_MOAR127H           (*((unsigned int volatile huge *) 0x201FFA))

// Message Object 127 Arbitration Register Low
#define CAN_MOAR127L           (*((unsigned int volatile huge *) 0x201FF8))

// Message Object 12 Arbitration Register High
#define CAN_MOAR12H            (*((unsigned int volatile huge *) 0x20119A))

// Message Object 12 Arbitration Register Low
#define CAN_MOAR12L            (*((unsigned int volatile huge *) 0x201198))

// Message Object 13 Arbitration Register High
#define CAN_MOAR13H            (*((unsigned int volatile huge *) 0x2011BA))

// Message Object 13 Arbitration Register Low
#define CAN_MOAR13L            (*((unsigned int volatile huge *) 0x2011B8))

// Message Object 14 Arbitration Register High
#define CAN_MOAR14H            (*((unsigned int volatile huge *) 0x2011DA))

// Message Object 14 Arbitration Register Low
#define CAN_MOAR14L            (*((unsigned int volatile huge *) 0x2011D8))

// Message Object 15 Arbitration Register High
#define CAN_MOAR15H            (*((unsigned int volatile huge *) 0x2011FA))

// Message Object 15 Arbitration Register Low
#define CAN_MOAR15L            (*((unsigned int volatile huge *) 0x2011F8))

// Message Object 16 Arbitration Register High
#define CAN_MOAR16H            (*((unsigned int volatile huge *) 0x20121A))

// Message Object 16 Arbitration Register Low
#define CAN_MOAR16L            (*((unsigned int volatile huge *) 0x201218))

// Message Object 17 Arbitration Register High
#define CAN_MOAR17H            (*((unsigned int volatile huge *) 0x20123A))

// Message Object 17 Arbitration Register Low
#define CAN_MOAR17L            (*((unsigned int volatile huge *) 0x201238))

// Message Object 18 Arbitration Register High
#define CAN_MOAR18H            (*((unsigned int volatile huge *) 0x20125A))

// Message Object 18 Arbitration Register Low
#define CAN_MOAR18L            (*((unsigned int volatile huge *) 0x201258))

// Message Object 19 Arbitration Register High
#define CAN_MOAR19H            (*((unsigned int volatile huge *) 0x20127A))

// Message Object 19 Arbitration Register Low
#define CAN_MOAR19L            (*((unsigned int volatile huge *) 0x201278))

// Message Object 1 Arbitration Register High
#define CAN_MOAR1H             (*((unsigned int volatile huge *) 0x20103A))

// Message Object 1 Arbitration Register Low
#define CAN_MOAR1L             (*((unsigned int volatile huge *) 0x201038))

// Message Object 20 Arbitration Register High
#define CAN_MOAR20H            (*((unsigned int volatile huge *) 0x20129A))

// Message Object 20 Arbitration Register Low
#define CAN_MOAR20L            (*((unsigned int volatile huge *) 0x201298))

// Message Object 21 Arbitration Register High
#define CAN_MOAR21H            (*((unsigned int volatile huge *) 0x2012BA))

// Message Object 21 Arbitration Register Low
#define CAN_MOAR21L            (*((unsigned int volatile huge *) 0x2012B8))

// Message Object 22 Arbitration Register High
#define CAN_MOAR22H            (*((unsigned int volatile huge *) 0x2012DA))

// Message Object 22 Arbitration Register Low
#define CAN_MOAR22L            (*((unsigned int volatile huge *) 0x2012D8))

// Message Object 23 Arbitration Register High
#define CAN_MOAR23H            (*((unsigned int volatile huge *) 0x2012FA))

// Message Object 23 Arbitration Register Low
#define CAN_MOAR23L            (*((unsigned int volatile huge *) 0x2012F8))

// Message Object 24 Arbitration Register High
#define CAN_MOAR24H            (*((unsigned int volatile huge *) 0x20131A))

// Message Object 24 Arbitration Register Low
#define CAN_MOAR24L            (*((unsigned int volatile huge *) 0x201318))

// Message Object 25 Arbitration Register High
#define CAN_MOAR25H            (*((unsigned int volatile huge *) 0x20133A))

// Message Object 25 Arbitration Register Low
#define CAN_MOAR25L            (*((unsigned int volatile huge *) 0x201338))

// Message Object 26 Arbitration Register High
#define CAN_MOAR26H            (*((unsigned int volatile huge *) 0x20135A))

// Message Object 26 Arbitration Register Low
#define CAN_MOAR26L            (*((unsigned int volatile huge *) 0x201358))

// Message Object 27 Arbitration Register High
#define CAN_MOAR27H            (*((unsigned int volatile huge *) 0x20137A))

// Message Object 27 Arbitration Register Low
#define CAN_MOAR27L            (*((unsigned int volatile huge *) 0x201378))

// Message Object 28 Arbitration Register High
#define CAN_MOAR28H            (*((unsigned int volatile huge *) 0x20139A))

// Message Object 28 Arbitration Register Low
#define CAN_MOAR28L            (*((unsigned int volatile huge *) 0x201398))

// Message Object 29 Arbitration Register High
#define CAN_MOAR29H            (*((unsigned int volatile huge *) 0x2013BA))

// Message Object 29 Arbitration Register Low
#define CAN_MOAR29L            (*((unsigned int volatile huge *) 0x2013B8))

// Message Object 2 Arbitration Register High
#define CAN_MOAR2H             (*((unsigned int volatile huge *) 0x20105A))

// Message Object 2 Arbitration Register Low
#define CAN_MOAR2L             (*((unsigned int volatile huge *) 0x201058))

// Message Object 30 Arbitration Register High
#define CAN_MOAR30H            (*((unsigned int volatile huge *) 0x2013DA))

// Message Object 30 Arbitration Register Low
#define CAN_MOAR30L            (*((unsigned int volatile huge *) 0x2013D8))

// Message Object 31 Arbitration Register High
#define CAN_MOAR31H            (*((unsigned int volatile huge *) 0x2013FA))

// Message Object 31 Arbitration Register Low
#define CAN_MOAR31L            (*((unsigned int volatile huge *) 0x2013F8))

// Message Object 32 Arbitration Register High
#define CAN_MOAR32H            (*((unsigned int volatile huge *) 0x20141A))

// Message Object 32 Arbitration Register Low
#define CAN_MOAR32L            (*((unsigned int volatile huge *) 0x201418))

// Message Object 33 Arbitration Register High
#define CAN_MOAR33H            (*((unsigned int volatile huge *) 0x20143A))

// Message Object 33 Arbitration Register Low
#define CAN_MOAR33L            (*((unsigned int volatile huge *) 0x201438))

// Message Object 34 Arbitration Register High
#define CAN_MOAR34H            (*((unsigned int volatile huge *) 0x20145A))

// Message Object 34 Arbitration Register Low
#define CAN_MOAR34L            (*((unsigned int volatile huge *) 0x201458))

// Message Object 35 Arbitration Register High
#define CAN_MOAR35H            (*((unsigned int volatile huge *) 0x20147A))

// Message Object 35 Arbitration Register Low
#define CAN_MOAR35L            (*((unsigned int volatile huge *) 0x201478))

// Message Object 36 Arbitration Register High
#define CAN_MOAR36H            (*((unsigned int volatile huge *) 0x20149A))

// Message Object 36 Arbitration Register Low
#define CAN_MOAR36L            (*((unsigned int volatile huge *) 0x201498))

// Message Object 37 Arbitration Register High
#define CAN_MOAR37H            (*((unsigned int volatile huge *) 0x2014BA))

// Message Object 37 Arbitration Register Low
#define CAN_MOAR37L            (*((unsigned int volatile huge *) 0x2014B8))

// Message Object 38 Arbitration Register High
#define CAN_MOAR38H            (*((unsigned int volatile huge *) 0x2014DA))

// Message Object 38 Arbitration Register Low
#define CAN_MOAR38L            (*((unsigned int volatile huge *) 0x2014D8))

// Message Object 39 Arbitration Register High
#define CAN_MOAR39H            (*((unsigned int volatile huge *) 0x2014FA))

// Message Object 39 Arbitration Register Low
#define CAN_MOAR39L            (*((unsigned int volatile huge *) 0x2014F8))

// Message Object 3 Arbitration Register High
#define CAN_MOAR3H             (*((unsigned int volatile huge *) 0x20107A))

// Message Object 3 Arbitration Register Low
#define CAN_MOAR3L             (*((unsigned int volatile huge *) 0x201078))

// Message Object 40 Arbitration Register High
#define CAN_MOAR40H            (*((unsigned int volatile huge *) 0x20151A))

// Message Object 40 Arbitration Register Low
#define CAN_MOAR40L            (*((unsigned int volatile huge *) 0x201518))

// Message Object 41 Arbitration Register High
#define CAN_MOAR41H            (*((unsigned int volatile huge *) 0x20153A))

// Message Object 41 Arbitration Register Low
#define CAN_MOAR41L            (*((unsigned int volatile huge *) 0x201538))

// Message Object 42 Arbitration Register High
#define CAN_MOAR42H            (*((unsigned int volatile huge *) 0x20155A))

// Message Object 42 Arbitration Register Low
#define CAN_MOAR42L            (*((unsigned int volatile huge *) 0x201558))

// Message Object 43 Arbitration Register High
#define CAN_MOAR43H            (*((unsigned int volatile huge *) 0x20157A))

// Message Object 43 Arbitration Register Low
#define CAN_MOAR43L            (*((unsigned int volatile huge *) 0x201578))

// Message Object 44 Arbitration Register High
#define CAN_MOAR44H            (*((unsigned int volatile huge *) 0x20159A))

// Message Object 44 Arbitration Register Low
#define CAN_MOAR44L            (*((unsigned int volatile huge *) 0x201598))

// Message Object 45 Arbitration Register High
#define CAN_MOAR45H            (*((unsigned int volatile huge *) 0x2015BA))

// Message Object 45 Arbitration Register Low
#define CAN_MOAR45L            (*((unsigned int volatile huge *) 0x2015B8))

// Message Object 46 Arbitration Register High
#define CAN_MOAR46H            (*((unsigned int volatile huge *) 0x2015DA))

// Message Object 46 Arbitration Register Low
#define CAN_MOAR46L            (*((unsigned int volatile huge *) 0x2015D8))

// Message Object 47 Arbitration Register High
#define CAN_MOAR47H            (*((unsigned int volatile huge *) 0x2015FA))

// Message Object 47 Arbitration Register Low
#define CAN_MOAR47L            (*((unsigned int volatile huge *) 0x2015F8))

// Message Object 48 Arbitration Register High
#define CAN_MOAR48H            (*((unsigned int volatile huge *) 0x20161A))

// Message Object 48 Arbitration Register Low
#define CAN_MOAR48L            (*((unsigned int volatile huge *) 0x201618))

// Message Object 49 Arbitration Register High
#define CAN_MOAR49H            (*((unsigned int volatile huge *) 0x20163A))

// Message Object 49 Arbitration Register Low
#define CAN_MOAR49L            (*((unsigned int volatile huge *) 0x201638))

// Message Object 4 Arbitration Register High
#define CAN_MOAR4H             (*((unsigned int volatile huge *) 0x20109A))

// Message Object 4 Arbitration Register Low
#define CAN_MOAR4L             (*((unsigned int volatile huge *) 0x201098))

// Message Object 50 Arbitration Register High
#define CAN_MOAR50H            (*((unsigned int volatile huge *) 0x20165A))

// Message Object 50 Arbitration Register Low
#define CAN_MOAR50L            (*((unsigned int volatile huge *) 0x201658))

// Message Object 51 Arbitration Register High
#define CAN_MOAR51H            (*((unsigned int volatile huge *) 0x20167A))

// Message Object 51 Arbitration Register Low
#define CAN_MOAR51L            (*((unsigned int volatile huge *) 0x201678))

// Message Object 52 Arbitration Register High
#define CAN_MOAR52H            (*((unsigned int volatile huge *) 0x20169A))

// Message Object 52 Arbitration Register Low
#define CAN_MOAR52L            (*((unsigned int volatile huge *) 0x201698))

// Message Object 53 Arbitration Register High
#define CAN_MOAR53H            (*((unsigned int volatile huge *) 0x2016BA))

// Message Object 53 Arbitration Register Low
#define CAN_MOAR53L            (*((unsigned int volatile huge *) 0x2016B8))

// Message Object 54 Arbitration Register High
#define CAN_MOAR54H            (*((unsigned int volatile huge *) 0x2016DA))

// Message Object 54 Arbitration Register Low
#define CAN_MOAR54L            (*((unsigned int volatile huge *) 0x2016D8))

// Message Object 55 Arbitration Register High
#define CAN_MOAR55H            (*((unsigned int volatile huge *) 0x2016FA))

// Message Object 55 Arbitration Register Low
#define CAN_MOAR55L            (*((unsigned int volatile huge *) 0x2016F8))

// Message Object 56 Arbitration Register High
#define CAN_MOAR56H            (*((unsigned int volatile huge *) 0x20171A))

// Message Object 56 Arbitration Register Low
#define CAN_MOAR56L            (*((unsigned int volatile huge *) 0x201718))

// Message Object 57 Arbitration Register High
#define CAN_MOAR57H            (*((unsigned int volatile huge *) 0x20173A))

// Message Object 57 Arbitration Register Low
#define CAN_MOAR57L            (*((unsigned int volatile huge *) 0x201738))

// Message Object 58 Arbitration Register High
#define CAN_MOAR58H            (*((unsigned int volatile huge *) 0x20175A))

// Message Object 58 Arbitration Register Low
#define CAN_MOAR58L            (*((unsigned int volatile huge *) 0x201758))

// Message Object 59 Arbitration Register High
#define CAN_MOAR59H            (*((unsigned int volatile huge *) 0x20177A))

// Message Object 59 Arbitration Register Low
#define CAN_MOAR59L            (*((unsigned int volatile huge *) 0x201778))

// Message Object 5 Arbitration Register High
#define CAN_MOAR5H             (*((unsigned int volatile huge *) 0x2010BA))

// Message Object 5 Arbitration Register Low
#define CAN_MOAR5L             (*((unsigned int volatile huge *) 0x2010B8))

// Message Object 60 Arbitration Register High
#define CAN_MOAR60H            (*((unsigned int volatile huge *) 0x20179A))

// Message Object 60 Arbitration Register Low
#define CAN_MOAR60L            (*((unsigned int volatile huge *) 0x201798))

// Message Object 61 Arbitration Register High
#define CAN_MOAR61H            (*((unsigned int volatile huge *) 0x2017BA))

// Message Object 61 Arbitration Register Low
#define CAN_MOAR61L            (*((unsigned int volatile huge *) 0x2017B8))

// Message Object 62 Arbitration Register High
#define CAN_MOAR62H            (*((unsigned int volatile huge *) 0x2017DA))

// Message Object 62 Arbitration Register Low
#define CAN_MOAR62L            (*((unsigned int volatile huge *) 0x2017D8))

// Message Object 63 Arbitration Register High
#define CAN_MOAR63H            (*((unsigned int volatile huge *) 0x2017FA))

// Message Object 63 Arbitration Register Low
#define CAN_MOAR63L            (*((unsigned int volatile huge *) 0x2017F8))

// Message Object 64 Arbitration Register High
#define CAN_MOAR64H            (*((unsigned int volatile huge *) 0x20181A))

// Message Object 64 Arbitration Register Low
#define CAN_MOAR64L            (*((unsigned int volatile huge *) 0x201818))

// Message Object 65 Arbitration Register High
#define CAN_MOAR65H            (*((unsigned int volatile huge *) 0x20183A))

// Message Object 65 Arbitration Register Low
#define CAN_MOAR65L            (*((unsigned int volatile huge *) 0x201838))

// Message Object 66 Arbitration Register High
#define CAN_MOAR66H            (*((unsigned int volatile huge *) 0x20185A))

// Message Object 66 Arbitration Register Low
#define CAN_MOAR66L            (*((unsigned int volatile huge *) 0x201858))

// Message Object 67 Arbitration Register High
#define CAN_MOAR67H            (*((unsigned int volatile huge *) 0x20187A))

// Message Object 67 Arbitration Register Low
#define CAN_MOAR67L            (*((unsigned int volatile huge *) 0x201878))

// Message Object 68 Arbitration Register High
#define CAN_MOAR68H            (*((unsigned int volatile huge *) 0x20189A))

// Message Object 68 Arbitration Register Low
#define CAN_MOAR68L            (*((unsigned int volatile huge *) 0x201898))

// Message Object 69 Arbitration Register High
#define CAN_MOAR69H            (*((unsigned int volatile huge *) 0x2018BA))

// Message Object 69 Arbitration Register Low
#define CAN_MOAR69L            (*((unsigned int volatile huge *) 0x2018B8))

// Message Object 6 Arbitration Register High
#define CAN_MOAR6H             (*((unsigned int volatile huge *) 0x2010DA))

// Message Object 6 Arbitration Register Low
#define CAN_MOAR6L             (*((unsigned int volatile huge *) 0x2010D8))

// Message Object 70 Arbitration Register High
#define CAN_MOAR70H            (*((unsigned int volatile huge *) 0x2018DA))

// Message Object 70 Arbitration Register Low
#define CAN_MOAR70L            (*((unsigned int volatile huge *) 0x2018D8))

// Message Object 71 Arbitration Register High
#define CAN_MOAR71H            (*((unsigned int volatile huge *) 0x2018FA))

// Message Object 71 Arbitration Register Low
#define CAN_MOAR71L            (*((unsigned int volatile huge *) 0x2018F8))

// Message Object 72 Arbitration Register High
#define CAN_MOAR72H            (*((unsigned int volatile huge *) 0x20191A))

// Message Object 72 Arbitration Register Low
#define CAN_MOAR72L            (*((unsigned int volatile huge *) 0x201918))

// Message Object 73 Arbitration Register High
#define CAN_MOAR73H            (*((unsigned int volatile huge *) 0x20193A))

// Message Object 73 Arbitration Register Low
#define CAN_MOAR73L            (*((unsigned int volatile huge *) 0x201938))

// Message Object 74 Arbitration Register High
#define CAN_MOAR74H            (*((unsigned int volatile huge *) 0x20195A))

// Message Object 74 Arbitration Register Low
#define CAN_MOAR74L            (*((unsigned int volatile huge *) 0x201958))

// Message Object 75 Arbitration Register High
#define CAN_MOAR75H            (*((unsigned int volatile huge *) 0x20197A))

// Message Object 75 Arbitration Register Low
#define CAN_MOAR75L            (*((unsigned int volatile huge *) 0x201978))

// Message Object 76 Arbitration Register High
#define CAN_MOAR76H            (*((unsigned int volatile huge *) 0x20199A))

// Message Object 76 Arbitration Register Low
#define CAN_MOAR76L            (*((unsigned int volatile huge *) 0x201998))

// Message Object 77 Arbitration Register High
#define CAN_MOAR77H            (*((unsigned int volatile huge *) 0x2019BA))

// Message Object 77 Arbitration Register Low
#define CAN_MOAR77L            (*((unsigned int volatile huge *) 0x2019B8))

// Message Object 78 Arbitration Register High
#define CAN_MOAR78H            (*((unsigned int volatile huge *) 0x2019DA))

// Message Object 78 Arbitration Register Low
#define CAN_MOAR78L            (*((unsigned int volatile huge *) 0x2019D8))

// Message Object 79 Arbitration Register High
#define CAN_MOAR79H            (*((unsigned int volatile huge *) 0x2019FA))

// Message Object 79 Arbitration Register Low
#define CAN_MOAR79L            (*((unsigned int volatile huge *) 0x2019F8))

// Message Object 7 Arbitration Register High
#define CAN_MOAR7H             (*((unsigned int volatile huge *) 0x2010FA))

// Message Object 7 Arbitration Register Low
#define CAN_MOAR7L             (*((unsigned int volatile huge *) 0x2010F8))

// Message Object 80 Arbitration Register High
#define CAN_MOAR80H            (*((unsigned int volatile huge *) 0x201A1A))

// Message Object 80 Arbitration Register Low
#define CAN_MOAR80L            (*((unsigned int volatile huge *) 0x201A18))

// Message Object 81 Arbitration Register High
#define CAN_MOAR81H            (*((unsigned int volatile huge *) 0x201A3A))

// Message Object 81 Arbitration Register Low
#define CAN_MOAR81L            (*((unsigned int volatile huge *) 0x201A38))

// Message Object 82 Arbitration Register High
#define CAN_MOAR82H            (*((unsigned int volatile huge *) 0x201A5A))

// Message Object 82 Arbitration Register Low
#define CAN_MOAR82L            (*((unsigned int volatile huge *) 0x201A58))

// Message Object 83 Arbitration Register High
#define CAN_MOAR83H            (*((unsigned int volatile huge *) 0x201A7A))

// Message Object 83 Arbitration Register Low
#define CAN_MOAR83L            (*((unsigned int volatile huge *) 0x201A78))

// Message Object 84 Arbitration Register High
#define CAN_MOAR84H            (*((unsigned int volatile huge *) 0x201A9A))

// Message Object 84 Arbitration Register Low
#define CAN_MOAR84L            (*((unsigned int volatile huge *) 0x201A98))

// Message Object 85 Arbitration Register High
#define CAN_MOAR85H            (*((unsigned int volatile huge *) 0x201ABA))

// Message Object 85 Arbitration Register Low
#define CAN_MOAR85L            (*((unsigned int volatile huge *) 0x201AB8))

// Message Object 86 Arbitration Register High
#define CAN_MOAR86H            (*((unsigned int volatile huge *) 0x201ADA))

// Message Object 86 Arbitration Register Low
#define CAN_MOAR86L            (*((unsigned int volatile huge *) 0x201AD8))

// Message Object 87 Arbitration Register High
#define CAN_MOAR87H            (*((unsigned int volatile huge *) 0x201AFA))

// Message Object 87 Arbitration Register Low
#define CAN_MOAR87L            (*((unsigned int volatile huge *) 0x201AF8))

// Message Object 88 Arbitration Register High
#define CAN_MOAR88H            (*((unsigned int volatile huge *) 0x201B1A))

// Message Object 88 Arbitration Register Low
#define CAN_MOAR88L            (*((unsigned int volatile huge *) 0x201B18))

// Message Object 89 Arbitration Register High
#define CAN_MOAR89H            (*((unsigned int volatile huge *) 0x201B3A))

// Message Object 89 Arbitration Register Low
#define CAN_MOAR89L            (*((unsigned int volatile huge *) 0x201B38))

// Message Object 8 Arbitration Register High
#define CAN_MOAR8H             (*((unsigned int volatile huge *) 0x20111A))

// Message Object 8 Arbitration Register Low
#define CAN_MOAR8L             (*((unsigned int volatile huge *) 0x201118))

// Message Object 90 Arbitration Register High
#define CAN_MOAR90H            (*((unsigned int volatile huge *) 0x201B5A))

// Message Object 90 Arbitration Register Low
#define CAN_MOAR90L            (*((unsigned int volatile huge *) 0x201B58))

// Message Object 91 Arbitration Register High
#define CAN_MOAR91H            (*((unsigned int volatile huge *) 0x201B7A))

// Message Object 91 Arbitration Register Low
#define CAN_MOAR91L            (*((unsigned int volatile huge *) 0x201B78))

// Message Object 92 Arbitration Register High
#define CAN_MOAR92H            (*((unsigned int volatile huge *) 0x201B9A))

// Message Object 92 Arbitration Register Low
#define CAN_MOAR92L            (*((unsigned int volatile huge *) 0x201B98))

// Message Object 93 Arbitration Register High
#define CAN_MOAR93H            (*((unsigned int volatile huge *) 0x201BBA))

// Message Object 93 Arbitration Register Low
#define CAN_MOAR93L            (*((unsigned int volatile huge *) 0x201BB8))

// Message Object 94 Arbitration Register High
#define CAN_MOAR94H            (*((unsigned int volatile huge *) 0x201BDA))

// Message Object 94 Arbitration Register Low
#define CAN_MOAR94L            (*((unsigned int volatile huge *) 0x201BD8))

// Message Object 95 Arbitration Register High
#define CAN_MOAR95H            (*((unsigned int volatile huge *) 0x201BFA))

// Message Object 95 Arbitration Register Low
#define CAN_MOAR95L            (*((unsigned int volatile huge *) 0x201BF8))

// Message Object 96 Arbitration Register High
#define CAN_MOAR96H            (*((unsigned int volatile huge *) 0x201C1A))

// Message Object 96 Arbitration Register Low
#define CAN_MOAR96L            (*((unsigned int volatile huge *) 0x201C18))

// Message Object 97 Arbitration Register High
#define CAN_MOAR97H            (*((unsigned int volatile huge *) 0x201C3A))

// Message Object 97 Arbitration Register Low
#define CAN_MOAR97L            (*((unsigned int volatile huge *) 0x201C38))

// Message Object 98 Arbitration Register High
#define CAN_MOAR98H            (*((unsigned int volatile huge *) 0x201C5A))

// Message Object 98 Arbitration Register Low
#define CAN_MOAR98L            (*((unsigned int volatile huge *) 0x201C58))

// Message Object 99 Arbitration Register High
#define CAN_MOAR99H            (*((unsigned int volatile huge *) 0x201C7A))

// Message Object 99 Arbitration Register Low
#define CAN_MOAR99L            (*((unsigned int volatile huge *) 0x201C78))

// Message Object 9 Arbitration Register High
#define CAN_MOAR9H             (*((unsigned int volatile huge *) 0x20113A))

// Message Object 9 Arbitration Register Low
#define CAN_MOAR9L             (*((unsigned int volatile huge *) 0x201138))

// Message Object 0 Control Register High
#define CAN_MOCTR0H            (*((unsigned int volatile huge *) 0x20101E))

// Message Object 0 Control Register Low
#define CAN_MOCTR0L            (*((unsigned int volatile huge *) 0x20101C))

// Message Object 100 Control Register High
#define CAN_MOCTR100H          (*((unsigned int volatile huge *) 0x201C9E))

// Message Object 100 Control Register Low
#define CAN_MOCTR100L          (*((unsigned int volatile huge *) 0x201C9C))

// Message Object 101 Control Register High
#define CAN_MOCTR101H          (*((unsigned int volatile huge *) 0x201CBE))

// Message Object 101 Control Register Low
#define CAN_MOCTR101L          (*((unsigned int volatile huge *) 0x201CBC))

// Message Object 102 Control Register High
#define CAN_MOCTR102H          (*((unsigned int volatile huge *) 0x201CDE))

// Message Object 102 Control Register Low
#define CAN_MOCTR102L          (*((unsigned int volatile huge *) 0x201CDC))

// Message Object 103 Control Register High
#define CAN_MOCTR103H          (*((unsigned int volatile huge *) 0x201CFE))

// Message Object 103 Control Register Low
#define CAN_MOCTR103L          (*((unsigned int volatile huge *) 0x201CFC))

// Message Object 104 Control Register High
#define CAN_MOCTR104H          (*((unsigned int volatile huge *) 0x201D1E))

// Message Object 104 Control Register Low
#define CAN_MOCTR104L          (*((unsigned int volatile huge *) 0x201D1C))

// Message Object 105 Control Register High
#define CAN_MOCTR105H          (*((unsigned int volatile huge *) 0x201D3E))

// Message Object 105 Control Register Low
#define CAN_MOCTR105L          (*((unsigned int volatile huge *) 0x201D3C))

// Message Object 106 Control Register High
#define CAN_MOCTR106H          (*((unsigned int volatile huge *) 0x201D5E))

// Message Object 106 Control Register Low
#define CAN_MOCTR106L          (*((unsigned int volatile huge *) 0x201D5C))

// Message Object 107 Control Register High
#define CAN_MOCTR107H          (*((unsigned int volatile huge *) 0x201D7E))

// Message Object 107 Control Register Low
#define CAN_MOCTR107L          (*((unsigned int volatile huge *) 0x201D7C))

// Message Object 108 Control Register High
#define CAN_MOCTR108H          (*((unsigned int volatile huge *) 0x201D9E))

// Message Object 108 Control Register Low
#define CAN_MOCTR108L          (*((unsigned int volatile huge *) 0x201D9C))

// Message Object 109 Control Register High
#define CAN_MOCTR109H          (*((unsigned int volatile huge *) 0x201DBE))

// Message Object 109 Control Register Low
#define CAN_MOCTR109L          (*((unsigned int volatile huge *) 0x201DBC))

// Message Object 10 Control Register High
#define CAN_MOCTR10H           (*((unsigned int volatile huge *) 0x20115E))

// Message Object 10 Control Register Low
#define CAN_MOCTR10L           (*((unsigned int volatile huge *) 0x20115C))

// Message Object 110 Control Register High
#define CAN_MOCTR110H          (*((unsigned int volatile huge *) 0x201DDE))

// Message Object 110 Control Register Low
#define CAN_MOCTR110L          (*((unsigned int volatile huge *) 0x201DDC))

// Message Object 111 Control Register High
#define CAN_MOCTR111H          (*((unsigned int volatile huge *) 0x201DFE))

// Message Object 111 Control Register Low
#define CAN_MOCTR111L          (*((unsigned int volatile huge *) 0x201DFC))

// Message Object 112 Control Register High
#define CAN_MOCTR112H          (*((unsigned int volatile huge *) 0x201E1E))

// Message Object 112 Control Register Low
#define CAN_MOCTR112L          (*((unsigned int volatile huge *) 0x201E1C))

// Message Object 113 Control Register High
#define CAN_MOCTR113H          (*((unsigned int volatile huge *) 0x201E3E))

// Message Object 113 Control Register Low
#define CAN_MOCTR113L          (*((unsigned int volatile huge *) 0x201E3C))

// Message Object 114 Control Register High
#define CAN_MOCTR114H          (*((unsigned int volatile huge *) 0x201E5E))

// Message Object 114 Control Register Low
#define CAN_MOCTR114L          (*((unsigned int volatile huge *) 0x201E5C))

// Message Object 115 Control Register High
#define CAN_MOCTR115H          (*((unsigned int volatile huge *) 0x201E7E))

// Message Object 115 Control Register Low
#define CAN_MOCTR115L          (*((unsigned int volatile huge *) 0x201E7C))

// Message Object 116 Control Register High
#define CAN_MOCTR116H          (*((unsigned int volatile huge *) 0x201E9E))

// Message Object 116 Control Register Low
#define CAN_MOCTR116L          (*((unsigned int volatile huge *) 0x201E9C))

// Message Object 117 Control Register High
#define CAN_MOCTR117H          (*((unsigned int volatile huge *) 0x201EBE))

// Message Object 117 Control Register Low
#define CAN_MOCTR117L          (*((unsigned int volatile huge *) 0x201EBC))

// Message Object 118 Control Register High
#define CAN_MOCTR118H          (*((unsigned int volatile huge *) 0x201EDE))

// Message Object 118 Control Register Low
#define CAN_MOCTR118L          (*((unsigned int volatile huge *) 0x201EDC))

// Message Object 119 Control Register High
#define CAN_MOCTR119H          (*((unsigned int volatile huge *) 0x201EFE))

// Message Object 119 Control Register Low
#define CAN_MOCTR119L          (*((unsigned int volatile huge *) 0x201EFC))

// Message Object 11 Control Register High
#define CAN_MOCTR11H           (*((unsigned int volatile huge *) 0x20117E))

// Message Object 11 Control Register Low
#define CAN_MOCTR11L           (*((unsigned int volatile huge *) 0x20117C))

// Message Object 120 Control Register High
#define CAN_MOCTR120H          (*((unsigned int volatile huge *) 0x201F1E))

// Message Object 120 Control Register Low
#define CAN_MOCTR120L          (*((unsigned int volatile huge *) 0x201F1C))

// Message Object 121 Control Register High
#define CAN_MOCTR121H          (*((unsigned int volatile huge *) 0x201F3E))

// Message Object 121 Control Register Low
#define CAN_MOCTR121L          (*((unsigned int volatile huge *) 0x201F3C))

// Message Object 122 Control Register High
#define CAN_MOCTR122H          (*((unsigned int volatile huge *) 0x201F5E))

// Message Object 122 Control Register Low
#define CAN_MOCTR122L          (*((unsigned int volatile huge *) 0x201F5C))

// Message Object 123 Control Register High
#define CAN_MOCTR123H          (*((unsigned int volatile huge *) 0x201F7E))

// Message Object 123 Control Register Low
#define CAN_MOCTR123L          (*((unsigned int volatile huge *) 0x201F7C))

// Message Object 124 Control Register High
#define CAN_MOCTR124H          (*((unsigned int volatile huge *) 0x201F9E))

// Message Object 124 Control Register Low
#define CAN_MOCTR124L          (*((unsigned int volatile huge *) 0x201F9C))

// Message Object 125 Control Register High
#define CAN_MOCTR125H          (*((unsigned int volatile huge *) 0x201FBE))

// Message Object 125 Control Register Low
#define CAN_MOCTR125L          (*((unsigned int volatile huge *) 0x201FBC))

// Message Object 126 Control Register High
#define CAN_MOCTR126H          (*((unsigned int volatile huge *) 0x201FDE))

// Message Object 126 Control Register Low
#define CAN_MOCTR126L          (*((unsigned int volatile huge *) 0x201FDC))

// Message Object 127 Control Register High
#define CAN_MOCTR127H          (*((unsigned int volatile huge *) 0x201FFE))

// Message Object 127 Control Register Low
#define CAN_MOCTR127L          (*((unsigned int volatile huge *) 0x201FFC))

// Message Object 12 Control Register High
#define CAN_MOCTR12H           (*((unsigned int volatile huge *) 0x20119E))

// Message Object 12 Control Register Low
#define CAN_MOCTR12L           (*((unsigned int volatile huge *) 0x20119C))

// Message Object 13 Control Register High
#define CAN_MOCTR13H           (*((unsigned int volatile huge *) 0x2011BE))

// Message Object 13 Control Register Low
#define CAN_MOCTR13L           (*((unsigned int volatile huge *) 0x2011BC))

// Message Object 14 Control Register High
#define CAN_MOCTR14H           (*((unsigned int volatile huge *) 0x2011DE))

// Message Object 14 Control Register Low
#define CAN_MOCTR14L           (*((unsigned int volatile huge *) 0x2011DC))

// Message Object 15 Control Register High
#define CAN_MOCTR15H           (*((unsigned int volatile huge *) 0x2011FE))

// Message Object 15 Control Register Low
#define CAN_MOCTR15L           (*((unsigned int volatile huge *) 0x2011FC))

// Message Object 16 Control Register High
#define CAN_MOCTR16H           (*((unsigned int volatile huge *) 0x20121E))

// Message Object 16 Control Register Low
#define CAN_MOCTR16L           (*((unsigned int volatile huge *) 0x20121C))

// Message Object 17 Control Register High
#define CAN_MOCTR17H           (*((unsigned int volatile huge *) 0x20123E))

// Message Object 17 Control Register Low
#define CAN_MOCTR17L           (*((unsigned int volatile huge *) 0x20123C))

// Message Object 18 Control Register High
#define CAN_MOCTR18H           (*((unsigned int volatile huge *) 0x20125E))

// Message Object 18 Control Register Low
#define CAN_MOCTR18L           (*((unsigned int volatile huge *) 0x20125C))

// Message Object 19 Control Register High
#define CAN_MOCTR19H           (*((unsigned int volatile huge *) 0x20127E))

// Message Object 19 Control Register Low
#define CAN_MOCTR19L           (*((unsigned int volatile huge *) 0x20127C))

// Message Object 1 Control Register High
#define CAN_MOCTR1H            (*((unsigned int volatile huge *) 0x20103E))

// Message Object 1 Control Register Low
#define CAN_MOCTR1L            (*((unsigned int volatile huge *) 0x20103C))

// Message Object 20 Control Register High
#define CAN_MOCTR20H           (*((unsigned int volatile huge *) 0x20129E))

// Message Object 20 Control Register Low
#define CAN_MOCTR20L           (*((unsigned int volatile huge *) 0x20129C))

// Message Object 21 Control Register High
#define CAN_MOCTR21H           (*((unsigned int volatile huge *) 0x2012BE))

// Message Object 21 Control Register Low
#define CAN_MOCTR21L           (*((unsigned int volatile huge *) 0x2012BC))

// Message Object 22 Control Register High
#define CAN_MOCTR22H           (*((unsigned int volatile huge *) 0x2012DE))

// Message Object 22 Control Register Low
#define CAN_MOCTR22L           (*((unsigned int volatile huge *) 0x2012DC))

// Message Object 23 Control Register High
#define CAN_MOCTR23H           (*((unsigned int volatile huge *) 0x2012FE))

// Message Object 23 Control Register Low
#define CAN_MOCTR23L           (*((unsigned int volatile huge *) 0x2012FC))

// Message Object 24 Control Register High
#define CAN_MOCTR24H           (*((unsigned int volatile huge *) 0x20131E))

// Message Object 24 Control Register Low
#define CAN_MOCTR24L           (*((unsigned int volatile huge *) 0x20131C))

// Message Object 25 Control Register High
#define CAN_MOCTR25H           (*((unsigned int volatile huge *) 0x20133E))

// Message Object 25 Control Register Low
#define CAN_MOCTR25L           (*((unsigned int volatile huge *) 0x20133C))

// Message Object 26 Control Register High
#define CAN_MOCTR26H           (*((unsigned int volatile huge *) 0x20135E))

// Message Object 26 Control Register Low
#define CAN_MOCTR26L           (*((unsigned int volatile huge *) 0x20135C))

// Message Object 27 Control Register High
#define CAN_MOCTR27H           (*((unsigned int volatile huge *) 0x20137E))

// Message Object 27 Control Register Low
#define CAN_MOCTR27L           (*((unsigned int volatile huge *) 0x20137C))

// Message Object 28 Control Register High
#define CAN_MOCTR28H           (*((unsigned int volatile huge *) 0x20139E))

// Message Object 28 Control Register Low
#define CAN_MOCTR28L           (*((unsigned int volatile huge *) 0x20139C))

// Message Object 29 Control Register High
#define CAN_MOCTR29H           (*((unsigned int volatile huge *) 0x2013BE))

// Message Object 29 Control Register Low
#define CAN_MOCTR29L           (*((unsigned int volatile huge *) 0x2013BC))

// Message Object 2 Control Register High
#define CAN_MOCTR2H            (*((unsigned int volatile huge *) 0x20105E))

// Message Object 2 Control Register Low
#define CAN_MOCTR2L            (*((unsigned int volatile huge *) 0x20105C))

// Message Object 30 Control Register High
#define CAN_MOCTR30H           (*((unsigned int volatile huge *) 0x2013DE))

// Message Object 30 Control Register Low
#define CAN_MOCTR30L           (*((unsigned int volatile huge *) 0x2013DC))

// Message Object 31 Control Register High
#define CAN_MOCTR31H           (*((unsigned int volatile huge *) 0x2013FE))

// Message Object 31 Control Register Low
#define CAN_MOCTR31L           (*((unsigned int volatile huge *) 0x2013FC))

// Message Object 32 Control Register High
#define CAN_MOCTR32H           (*((unsigned int volatile huge *) 0x20141E))

// Message Object 32 Control Register Low
#define CAN_MOCTR32L           (*((unsigned int volatile huge *) 0x20141C))

// Message Object 33 Control Register High
#define CAN_MOCTR33H           (*((unsigned int volatile huge *) 0x20143E))

// Message Object 33 Control Register Low
#define CAN_MOCTR33L           (*((unsigned int volatile huge *) 0x20143C))

// Message Object 34 Control Register High
#define CAN_MOCTR34H           (*((unsigned int volatile huge *) 0x20145E))

// Message Object 34 Control Register Low
#define CAN_MOCTR34L           (*((unsigned int volatile huge *) 0x20145C))

// Message Object 35 Control Register High
#define CAN_MOCTR35H           (*((unsigned int volatile huge *) 0x20147E))

// Message Object 35 Control Register Low
#define CAN_MOCTR35L           (*((unsigned int volatile huge *) 0x20147C))

// Message Object 36 Control Register High
#define CAN_MOCTR36H           (*((unsigned int volatile huge *) 0x20149E))

// Message Object 36 Control Register Low
#define CAN_MOCTR36L           (*((unsigned int volatile huge *) 0x20149C))

// Message Object 37 Control Register High
#define CAN_MOCTR37H           (*((unsigned int volatile huge *) 0x2014BE))

// Message Object 37 Control Register Low
#define CAN_MOCTR37L           (*((unsigned int volatile huge *) 0x2014BC))

// Message Object 38 Control Register High
#define CAN_MOCTR38H           (*((unsigned int volatile huge *) 0x2014DE))

// Message Object 38 Control Register Low
#define CAN_MOCTR38L           (*((unsigned int volatile huge *) 0x2014DC))

// Message Object 39 Control Register High
#define CAN_MOCTR39H           (*((unsigned int volatile huge *) 0x2014FE))

// Message Object 39 Control Register Low
#define CAN_MOCTR39L           (*((unsigned int volatile huge *) 0x2014FC))

// Message Object 3 Control Register High
#define CAN_MOCTR3H            (*((unsigned int volatile huge *) 0x20107E))

// Message Object 3 Control Register Low
#define CAN_MOCTR3L            (*((unsigned int volatile huge *) 0x20107C))

// Message Object 40 Control Register High
#define CAN_MOCTR40H           (*((unsigned int volatile huge *) 0x20151E))

// Message Object 40 Control Register Low
#define CAN_MOCTR40L           (*((unsigned int volatile huge *) 0x20151C))

// Message Object 41 Control Register High
#define CAN_MOCTR41H           (*((unsigned int volatile huge *) 0x20153E))

// Message Object 41 Control Register Low
#define CAN_MOCTR41L           (*((unsigned int volatile huge *) 0x20153C))

// Message Object 42 Control Register High
#define CAN_MOCTR42H           (*((unsigned int volatile huge *) 0x20155E))

// Message Object 42 Control Register Low
#define CAN_MOCTR42L           (*((unsigned int volatile huge *) 0x20155C))

// Message Object 43 Control Register High
#define CAN_MOCTR43H           (*((unsigned int volatile huge *) 0x20157E))

// Message Object 43 Control Register Low
#define CAN_MOCTR43L           (*((unsigned int volatile huge *) 0x20157C))

// Message Object 44 Control Register High
#define CAN_MOCTR44H           (*((unsigned int volatile huge *) 0x20159E))

// Message Object 44 Control Register Low
#define CAN_MOCTR44L           (*((unsigned int volatile huge *) 0x20159C))

// Message Object 45 Control Register High
#define CAN_MOCTR45H           (*((unsigned int volatile huge *) 0x2015BE))

// Message Object 45 Control Register Low
#define CAN_MOCTR45L           (*((unsigned int volatile huge *) 0x2015BC))

// Message Object 46 Control Register High
#define CAN_MOCTR46H           (*((unsigned int volatile huge *) 0x2015DE))

// Message Object 46 Control Register Low
#define CAN_MOCTR46L           (*((unsigned int volatile huge *) 0x2015DC))

// Message Object 47 Control Register High
#define CAN_MOCTR47H           (*((unsigned int volatile huge *) 0x2015FE))

// Message Object 47 Control Register Low
#define CAN_MOCTR47L           (*((unsigned int volatile huge *) 0x2015FC))

// Message Object 48 Control Register High
#define CAN_MOCTR48H           (*((unsigned int volatile huge *) 0x20161E))

// Message Object 48 Control Register Low
#define CAN_MOCTR48L           (*((unsigned int volatile huge *) 0x20161C))

// Message Object 49 Control Register High
#define CAN_MOCTR49H           (*((unsigned int volatile huge *) 0x20163E))

// Message Object 49 Control Register Low
#define CAN_MOCTR49L           (*((unsigned int volatile huge *) 0x20163C))

// Message Object 4 Control Register High
#define CAN_MOCTR4H            (*((unsigned int volatile huge *) 0x20109E))

// Message Object 4 Control Register Low
#define CAN_MOCTR4L            (*((unsigned int volatile huge *) 0x20109C))

// Message Object 50 Control Register High
#define CAN_MOCTR50H           (*((unsigned int volatile huge *) 0x20165E))

// Message Object 50 Control Register Low
#define CAN_MOCTR50L           (*((unsigned int volatile huge *) 0x20165C))

// Message Object 51 Control Register High
#define CAN_MOCTR51H           (*((unsigned int volatile huge *) 0x20167E))

// Message Object 51 Control Register Low
#define CAN_MOCTR51L           (*((unsigned int volatile huge *) 0x20167C))

// Message Object 52 Control Register High
#define CAN_MOCTR52H           (*((unsigned int volatile huge *) 0x20169E))

// Message Object 52 Control Register Low
#define CAN_MOCTR52L           (*((unsigned int volatile huge *) 0x20169C))

// Message Object 53 Control Register High
#define CAN_MOCTR53H           (*((unsigned int volatile huge *) 0x2016BE))

// Message Object 53 Control Register Low
#define CAN_MOCTR53L           (*((unsigned int volatile huge *) 0x2016BC))

// Message Object 54 Control Register High
#define CAN_MOCTR54H           (*((unsigned int volatile huge *) 0x2016DE))

// Message Object 54 Control Register Low
#define CAN_MOCTR54L           (*((unsigned int volatile huge *) 0x2016DC))

// Message Object 55 Control Register High
#define CAN_MOCTR55H           (*((unsigned int volatile huge *) 0x2016FE))

// Message Object 55 Control Register Low
#define CAN_MOCTR55L           (*((unsigned int volatile huge *) 0x2016FC))

// Message Object 56 Control Register High
#define CAN_MOCTR56H           (*((unsigned int volatile huge *) 0x20171E))

// Message Object 56 Control Register Low
#define CAN_MOCTR56L           (*((unsigned int volatile huge *) 0x20171C))

// Message Object 57 Control Register High
#define CAN_MOCTR57H           (*((unsigned int volatile huge *) 0x20173E))

// Message Object 57 Control Register Low
#define CAN_MOCTR57L           (*((unsigned int volatile huge *) 0x20173C))

// Message Object 58 Control Register High
#define CAN_MOCTR58H           (*((unsigned int volatile huge *) 0x20175E))

// Message Object 58 Control Register Low
#define CAN_MOCTR58L           (*((unsigned int volatile huge *) 0x20175C))

// Message Object 59 Control Register High
#define CAN_MOCTR59H           (*((unsigned int volatile huge *) 0x20177E))

// Message Object 59 Control Register Low
#define CAN_MOCTR59L           (*((unsigned int volatile huge *) 0x20177C))

// Message Object 5 Control Register High
#define CAN_MOCTR5H            (*((unsigned int volatile huge *) 0x2010BE))

// Message Object 5 Control Register Low
#define CAN_MOCTR5L            (*((unsigned int volatile huge *) 0x2010BC))

// Message Object 60 Control Register High
#define CAN_MOCTR60H           (*((unsigned int volatile huge *) 0x20179E))

// Message Object 60 Control Register Low
#define CAN_MOCTR60L           (*((unsigned int volatile huge *) 0x20179C))

// Message Object 61 Control Register High
#define CAN_MOCTR61H           (*((unsigned int volatile huge *) 0x2017BE))

// Message Object 61 Control Register Low
#define CAN_MOCTR61L           (*((unsigned int volatile huge *) 0x2017BC))

// Message Object 62 Control Register High
#define CAN_MOCTR62H           (*((unsigned int volatile huge *) 0x2017DE))

// Message Object 62 Control Register Low
#define CAN_MOCTR62L           (*((unsigned int volatile huge *) 0x2017DC))

// Message Object 63 Control Register High
#define CAN_MOCTR63H           (*((unsigned int volatile huge *) 0x2017FE))

// Message Object 63 Control Register Low
#define CAN_MOCTR63L           (*((unsigned int volatile huge *) 0x2017FC))

// Message Object 64 Control Register High
#define CAN_MOCTR64H           (*((unsigned int volatile huge *) 0x20181E))

// Message Object 64 Control Register Low
#define CAN_MOCTR64L           (*((unsigned int volatile huge *) 0x20181C))

// Message Object 65 Control Register High
#define CAN_MOCTR65H           (*((unsigned int volatile huge *) 0x20183E))

// Message Object 65 Control Register Low
#define CAN_MOCTR65L           (*((unsigned int volatile huge *) 0x20183C))

// Message Object 66 Control Register High
#define CAN_MOCTR66H           (*((unsigned int volatile huge *) 0x20185E))

// Message Object 66 Control Register Low
#define CAN_MOCTR66L           (*((unsigned int volatile huge *) 0x20185C))

// Message Object 67 Control Register High
#define CAN_MOCTR67H           (*((unsigned int volatile huge *) 0x20187E))

// Message Object 67 Control Register Low
#define CAN_MOCTR67L           (*((unsigned int volatile huge *) 0x20187C))

// Message Object 68 Control Register High
#define CAN_MOCTR68H           (*((unsigned int volatile huge *) 0x20189E))

// Message Object 68 Control Register Low
#define CAN_MOCTR68L           (*((unsigned int volatile huge *) 0x20189C))

// Message Object 69 Control Register High
#define CAN_MOCTR69H           (*((unsigned int volatile huge *) 0x2018BE))

// Message Object 69 Control Register Low
#define CAN_MOCTR69L           (*((unsigned int volatile huge *) 0x2018BC))

// Message Object 6 Control Register High
#define CAN_MOCTR6H            (*((unsigned int volatile huge *) 0x2010DE))

// Message Object 6 Control Register Low
#define CAN_MOCTR6L            (*((unsigned int volatile huge *) 0x2010DC))

// Message Object 70 Control Register High
#define CAN_MOCTR70H           (*((unsigned int volatile huge *) 0x2018DE))

// Message Object 70 Control Register Low
#define CAN_MOCTR70L           (*((unsigned int volatile huge *) 0x2018DC))

// Message Object 71 Control Register High
#define CAN_MOCTR71H           (*((unsigned int volatile huge *) 0x2018FE))

// Message Object 71 Control Register Low
#define CAN_MOCTR71L           (*((unsigned int volatile huge *) 0x2018FC))

// Message Object 72 Control Register High
#define CAN_MOCTR72H           (*((unsigned int volatile huge *) 0x20191E))

// Message Object 72 Control Register Low
#define CAN_MOCTR72L           (*((unsigned int volatile huge *) 0x20191C))

// Message Object 73 Control Register High
#define CAN_MOCTR73H           (*((unsigned int volatile huge *) 0x20193E))

// Message Object 73 Control Register Low
#define CAN_MOCTR73L           (*((unsigned int volatile huge *) 0x20193C))

// Message Object 74 Control Register High
#define CAN_MOCTR74H           (*((unsigned int volatile huge *) 0x20195E))

// Message Object 74 Control Register Low
#define CAN_MOCTR74L           (*((unsigned int volatile huge *) 0x20195C))

// Message Object 75 Control Register High
#define CAN_MOCTR75H           (*((unsigned int volatile huge *) 0x20197E))

// Message Object 75 Control Register Low
#define CAN_MOCTR75L           (*((unsigned int volatile huge *) 0x20197C))

// Message Object 76 Control Register High
#define CAN_MOCTR76H           (*((unsigned int volatile huge *) 0x20199E))

// Message Object 76 Control Register Low
#define CAN_MOCTR76L           (*((unsigned int volatile huge *) 0x20199C))

// Message Object 77 Control Register High
#define CAN_MOCTR77H           (*((unsigned int volatile huge *) 0x2019BE))

// Message Object 77 Control Register Low
#define CAN_MOCTR77L           (*((unsigned int volatile huge *) 0x2019BC))

// Message Object 78 Control Register High
#define CAN_MOCTR78H           (*((unsigned int volatile huge *) 0x2019DE))

// Message Object 78 Control Register Low
#define CAN_MOCTR78L           (*((unsigned int volatile huge *) 0x2019DC))

// Message Object 79 Control Register High
#define CAN_MOCTR79H           (*((unsigned int volatile huge *) 0x2019FE))

// Message Object 79 Control Register Low
#define CAN_MOCTR79L           (*((unsigned int volatile huge *) 0x2019FC))

// Message Object 7 Control Register High
#define CAN_MOCTR7H            (*((unsigned int volatile huge *) 0x2010FE))

// Message Object 7 Control Register Low
#define CAN_MOCTR7L            (*((unsigned int volatile huge *) 0x2010FC))

// Message Object 80 Control Register High
#define CAN_MOCTR80H           (*((unsigned int volatile huge *) 0x201A1E))

// Message Object 80 Control Register Low
#define CAN_MOCTR80L           (*((unsigned int volatile huge *) 0x201A1C))

// Message Object 81 Control Register High
#define CAN_MOCTR81H           (*((unsigned int volatile huge *) 0x201A3E))

// Message Object 81 Control Register Low
#define CAN_MOCTR81L           (*((unsigned int volatile huge *) 0x201A3C))

// Message Object 82 Control Register High
#define CAN_MOCTR82H           (*((unsigned int volatile huge *) 0x201A5E))

// Message Object 82 Control Register Low
#define CAN_MOCTR82L           (*((unsigned int volatile huge *) 0x201A5C))

// Message Object 83 Control Register High
#define CAN_MOCTR83H           (*((unsigned int volatile huge *) 0x201A7E))

// Message Object 83 Control Register Low
#define CAN_MOCTR83L           (*((unsigned int volatile huge *) 0x201A7C))

// Message Object 84 Control Register High
#define CAN_MOCTR84H           (*((unsigned int volatile huge *) 0x201A9E))

// Message Object 84 Control Register Low
#define CAN_MOCTR84L           (*((unsigned int volatile huge *) 0x201A9C))

// Message Object 85 Control Register High
#define CAN_MOCTR85H           (*((unsigned int volatile huge *) 0x201ABE))

// Message Object 85 Control Register Low
#define CAN_MOCTR85L           (*((unsigned int volatile huge *) 0x201ABC))

// Message Object 86 Control Register High
#define CAN_MOCTR86H           (*((unsigned int volatile huge *) 0x201ADE))

// Message Object 86 Control Register Low
#define CAN_MOCTR86L           (*((unsigned int volatile huge *) 0x201ADC))

// Message Object 87 Control Register High
#define CAN_MOCTR87H           (*((unsigned int volatile huge *) 0x201AFE))

// Message Object 87 Control Register Low
#define CAN_MOCTR87L           (*((unsigned int volatile huge *) 0x201AFC))

// Message Object 88 Control Register High
#define CAN_MOCTR88H           (*((unsigned int volatile huge *) 0x201B1E))

// Message Object 88 Control Register Low
#define CAN_MOCTR88L           (*((unsigned int volatile huge *) 0x201B1C))

// Message Object 89 Control Register High
#define CAN_MOCTR89H           (*((unsigned int volatile huge *) 0x201B3E))

// Message Object 89 Control Register Low
#define CAN_MOCTR89L           (*((unsigned int volatile huge *) 0x201B3C))

// Message Object 8 Control Register High
#define CAN_MOCTR8H            (*((unsigned int volatile huge *) 0x20111E))

// Message Object 8 Control Register Low
#define CAN_MOCTR8L            (*((unsigned int volatile huge *) 0x20111C))

// Message Object 90 Control Register High
#define CAN_MOCTR90H           (*((unsigned int volatile huge *) 0x201B5E))

// Message Object 90 Control Register Low
#define CAN_MOCTR90L           (*((unsigned int volatile huge *) 0x201B5C))

// Message Object 91 Control Register High
#define CAN_MOCTR91H           (*((unsigned int volatile huge *) 0x201B7E))

// Message Object 91 Control Register Low
#define CAN_MOCTR91L           (*((unsigned int volatile huge *) 0x201B7C))

// Message Object 92 Control Register High
#define CAN_MOCTR92H           (*((unsigned int volatile huge *) 0x201B9E))

// Message Object 92 Control Register Low
#define CAN_MOCTR92L           (*((unsigned int volatile huge *) 0x201B9C))

// Message Object 93 Control Register High
#define CAN_MOCTR93H           (*((unsigned int volatile huge *) 0x201BBE))

// Message Object 93 Control Register Low
#define CAN_MOCTR93L           (*((unsigned int volatile huge *) 0x201BBC))

// Message Object 94 Control Register High
#define CAN_MOCTR94H           (*((unsigned int volatile huge *) 0x201BDE))

// Message Object 94 Control Register Low
#define CAN_MOCTR94L           (*((unsigned int volatile huge *) 0x201BDC))

// Message Object 95 Control Register High
#define CAN_MOCTR95H           (*((unsigned int volatile huge *) 0x201BFE))

// Message Object 95 Control Register Low
#define CAN_MOCTR95L           (*((unsigned int volatile huge *) 0x201BFC))

// Message Object 96 Control Register High
#define CAN_MOCTR96H           (*((unsigned int volatile huge *) 0x201C1E))

// Message Object 96 Control Register Low
#define CAN_MOCTR96L           (*((unsigned int volatile huge *) 0x201C1C))

// Message Object 97 Control Register High
#define CAN_MOCTR97H           (*((unsigned int volatile huge *) 0x201C3E))

// Message Object 97 Control Register Low
#define CAN_MOCTR97L           (*((unsigned int volatile huge *) 0x201C3C))

// Message Object 98 Control Register High
#define CAN_MOCTR98H           (*((unsigned int volatile huge *) 0x201C5E))

// Message Object 98 Control Register Low
#define CAN_MOCTR98L           (*((unsigned int volatile huge *) 0x201C5C))

// Message Object 99 Control Register High
#define CAN_MOCTR99H           (*((unsigned int volatile huge *) 0x201C7E))

// Message Object 99 Control Register Low
#define CAN_MOCTR99L           (*((unsigned int volatile huge *) 0x201C7C))

// Message Object 9 Control Register High
#define CAN_MOCTR9H            (*((unsigned int volatile huge *) 0x20113E))

// Message Object 9 Control Register Low
#define CAN_MOCTR9L            (*((unsigned int volatile huge *) 0x20113C))

// Message Object 0 Data Register High High
#define CAN_MODATA0HH          (*((unsigned int volatile huge *) 0x201016))

// Message Object 0 Data Register High Low
#define CAN_MODATA0HL          (*((unsigned int volatile huge *) 0x201014))

// Message Object 0 Data Register Low High
#define CAN_MODATA0LH          (*((unsigned int volatile huge *) 0x201012))

// Message Object 0 Data Register Low Low
#define CAN_MODATA0LL          (*((unsigned int volatile huge *) 0x201010))

// Message Object 100 Data Register High High
#define CAN_MODATA100HH        (*((unsigned int volatile huge *) 0x201C96))

// Message Object 100 Data Register High Low
#define CAN_MODATA100HL        (*((unsigned int volatile huge *) 0x201C94))

// Message Object 100 Data Register Low High
#define CAN_MODATA100LH        (*((unsigned int volatile huge *) 0x201C92))

// Message Object 100 Data Register Low Low
#define CAN_MODATA100LL        (*((unsigned int volatile huge *) 0x201C90))

// Message Object 101 Data Register High High
#define CAN_MODATA101HH        (*((unsigned int volatile huge *) 0x201CB6))

// Message Object 101 Data Register High Low
#define CAN_MODATA101HL        (*((unsigned int volatile huge *) 0x201CB4))

// Message Object 101 Data Register Low High
#define CAN_MODATA101LH        (*((unsigned int volatile huge *) 0x201CB2))

// Message Object 101 Data Register Low Low
#define CAN_MODATA101LL        (*((unsigned int volatile huge *) 0x201CB0))

// Message Object 102 Data Register High High
#define CAN_MODATA102HH        (*((unsigned int volatile huge *) 0x201CD6))

// Message Object 102 Data Register High Low
#define CAN_MODATA102HL        (*((unsigned int volatile huge *) 0x201CD4))

// Message Object 102 Data Register Low High
#define CAN_MODATA102LH        (*((unsigned int volatile huge *) 0x201CD2))

// Message Object 102 Data Register Low Low
#define CAN_MODATA102LL        (*((unsigned int volatile huge *) 0x201CD0))

// Message Object 103 Data Register High High
#define CAN_MODATA103HH        (*((unsigned int volatile huge *) 0x201CF6))

// Message Object 103 Data Register High Low
#define CAN_MODATA103HL        (*((unsigned int volatile huge *) 0x201CF4))

// Message Object 103 Data Register Low High
#define CAN_MODATA103LH        (*((unsigned int volatile huge *) 0x201CF2))

// Message Object 103 Data Register Low Low
#define CAN_MODATA103LL        (*((unsigned int volatile huge *) 0x201CF0))

// Message Object 104 Data Register High High
#define CAN_MODATA104HH        (*((unsigned int volatile huge *) 0x201D16))

// Message Object 104 Data Register High Low
#define CAN_MODATA104HL        (*((unsigned int volatile huge *) 0x201D14))

// Message Object 104 Data Register Low High
#define CAN_MODATA104LH        (*((unsigned int volatile huge *) 0x201D12))

// Message Object 104 Data Register Low Low
#define CAN_MODATA104LL        (*((unsigned int volatile huge *) 0x201D10))

// Message Object 105 Data Register High High
#define CAN_MODATA105HH        (*((unsigned int volatile huge *) 0x201D36))

// Message Object 105 Data Register High Low
#define CAN_MODATA105HL        (*((unsigned int volatile huge *) 0x201D34))

// Message Object 105 Data Register Low High
#define CAN_MODATA105LH        (*((unsigned int volatile huge *) 0x201D32))

// Message Object 105 Data Register Low Low
#define CAN_MODATA105LL        (*((unsigned int volatile huge *) 0x201D30))

// Message Object 106 Data Register High High
#define CAN_MODATA106HH        (*((unsigned int volatile huge *) 0x201D56))

// Message Object 106 Data Register High Low
#define CAN_MODATA106HL        (*((unsigned int volatile huge *) 0x201D54))

// Message Object 106 Data Register Low High
#define CAN_MODATA106LH        (*((unsigned int volatile huge *) 0x201D52))

// Message Object 106 Data Register Low Low
#define CAN_MODATA106LL        (*((unsigned int volatile huge *) 0x201D50))

// Message Object 107 Data Register High High
#define CAN_MODATA107HH        (*((unsigned int volatile huge *) 0x201D76))

// Message Object 107 Data Register High Low
#define CAN_MODATA107HL        (*((unsigned int volatile huge *) 0x201D74))

// Message Object 107 Data Register Low High
#define CAN_MODATA107LH        (*((unsigned int volatile huge *) 0x201D72))

// Message Object 107 Data Register Low Low
#define CAN_MODATA107LL        (*((unsigned int volatile huge *) 0x201D70))

// Message Object 108 Data Register High High
#define CAN_MODATA108HH        (*((unsigned int volatile huge *) 0x201D96))

// Message Object 108 Data Register High Low
#define CAN_MODATA108HL        (*((unsigned int volatile huge *) 0x201D94))

// Message Object 108 Data Register Low High
#define CAN_MODATA108LH        (*((unsigned int volatile huge *) 0x201D92))

// Message Object 108 Data Register Low Low
#define CAN_MODATA108LL        (*((unsigned int volatile huge *) 0x201D90))

// Message Object 109 Data Register High High
#define CAN_MODATA109HH        (*((unsigned int volatile huge *) 0x201DB6))

// Message Object 109 Data Register High Low
#define CAN_MODATA109HL        (*((unsigned int volatile huge *) 0x201DB4))

// Message Object 109 Data Register Low High
#define CAN_MODATA109LH        (*((unsigned int volatile huge *) 0x201DB2))

// Message Object 109 Data Register Low Low
#define CAN_MODATA109LL        (*((unsigned int volatile huge *) 0x201DB0))

// Message Object 10 Data Register High High
#define CAN_MODATA10HH         (*((unsigned int volatile huge *) 0x201156))

// Message Object 10 Data Register High Low
#define CAN_MODATA10HL         (*((unsigned int volatile huge *) 0x201154))

// Message Object 10 Data Register Low High
#define CAN_MODATA10LH         (*((unsigned int volatile huge *) 0x201152))

// Message Object 10 Data Register Low Low
#define CAN_MODATA10LL         (*((unsigned int volatile huge *) 0x201150))

// Message Object 110 Data Register High High
#define CAN_MODATA110HH        (*((unsigned int volatile huge *) 0x201DD6))

// Message Object 110 Data Register High Low
#define CAN_MODATA110HL        (*((unsigned int volatile huge *) 0x201DD4))

// Message Object 110 Data Register Low High
#define CAN_MODATA110LH        (*((unsigned int volatile huge *) 0x201DD2))

// Message Object 110 Data Register Low Low
#define CAN_MODATA110LL        (*((unsigned int volatile huge *) 0x201DD0))

// Message Object 111 Data Register High High
#define CAN_MODATA111HH        (*((unsigned int volatile huge *) 0x201DF6))

// Message Object 111 Data Register High Low
#define CAN_MODATA111HL        (*((unsigned int volatile huge *) 0x201DF4))

// Message Object 111 Data Register Low High
#define CAN_MODATA111LH        (*((unsigned int volatile huge *) 0x201DF2))

// Message Object 111 Data Register Low Low
#define CAN_MODATA111LL        (*((unsigned int volatile huge *) 0x201DF0))

// Message Object 112 Data Register High High
#define CAN_MODATA112HH        (*((unsigned int volatile huge *) 0x201E16))

// Message Object 112 Data Register High Low
#define CAN_MODATA112HL        (*((unsigned int volatile huge *) 0x201E14))

// Message Object 112 Data Register Low High
#define CAN_MODATA112LH        (*((unsigned int volatile huge *) 0x201E12))

// Message Object 112 Data Register Low Low
#define CAN_MODATA112LL        (*((unsigned int volatile huge *) 0x201E10))

// Message Object 113 Data Register High High
#define CAN_MODATA113HH        (*((unsigned int volatile huge *) 0x201E36))

// Message Object 113 Data Register High Low
#define CAN_MODATA113HL        (*((unsigned int volatile huge *) 0x201E34))

// Message Object 113 Data Register Low High
#define CAN_MODATA113LH        (*((unsigned int volatile huge *) 0x201E32))

// Message Object 113 Data Register Low Low
#define CAN_MODATA113LL        (*((unsigned int volatile huge *) 0x201E30))

// Message Object 114 Data Register High High
#define CAN_MODATA114HH        (*((unsigned int volatile huge *) 0x201E56))

// Message Object 114 Data Register High Low
#define CAN_MODATA114HL        (*((unsigned int volatile huge *) 0x201E54))

// Message Object 114 Data Register Low High
#define CAN_MODATA114LH        (*((unsigned int volatile huge *) 0x201E52))

// Message Object 114 Data Register Low Low
#define CAN_MODATA114LL        (*((unsigned int volatile huge *) 0x201E50))

// Message Object 115 Data Register High High
#define CAN_MODATA115HH        (*((unsigned int volatile huge *) 0x201E76))

// Message Object 115 Data Register High Low
#define CAN_MODATA115HL        (*((unsigned int volatile huge *) 0x201E74))

// Message Object 115 Data Register Low High
#define CAN_MODATA115LH        (*((unsigned int volatile huge *) 0x201E72))

// Message Object 115 Data Register Low Low
#define CAN_MODATA115LL        (*((unsigned int volatile huge *) 0x201E70))

// Message Object 116 Data Register High High
#define CAN_MODATA116HH        (*((unsigned int volatile huge *) 0x201E96))

// Message Object 116 Data Register High Low
#define CAN_MODATA116HL        (*((unsigned int volatile huge *) 0x201E94))

// Message Object 116 Data Register Low High
#define CAN_MODATA116LH        (*((unsigned int volatile huge *) 0x201E92))

// Message Object 116 Data Register Low Low
#define CAN_MODATA116LL        (*((unsigned int volatile huge *) 0x201E90))

// Message Object 117 Data Register High High
#define CAN_MODATA117HH        (*((unsigned int volatile huge *) 0x201EB6))

// Message Object 117 Data Register High Low
#define CAN_MODATA117HL        (*((unsigned int volatile huge *) 0x201EB4))

// Message Object 117 Data Register Low High
#define CAN_MODATA117LH        (*((unsigned int volatile huge *) 0x201EB2))

// Message Object 117 Data Register Low Low
#define CAN_MODATA117LL        (*((unsigned int volatile huge *) 0x201EB0))

// Message Object 118 Data Register High High
#define CAN_MODATA118HH        (*((unsigned int volatile huge *) 0x201ED6))

// Message Object 118 Data Register High Low
#define CAN_MODATA118HL        (*((unsigned int volatile huge *) 0x201ED4))

// Message Object 118 Data Register Low High
#define CAN_MODATA118LH        (*((unsigned int volatile huge *) 0x201ED2))

// Message Object 118 Data Register Low Low
#define CAN_MODATA118LL        (*((unsigned int volatile huge *) 0x201ED0))

// Message Object 119 Data Register High High
#define CAN_MODATA119HH        (*((unsigned int volatile huge *) 0x201EF6))

// Message Object 119 Data Register High Low
#define CAN_MODATA119HL        (*((unsigned int volatile huge *) 0x201EF4))

// Message Object 119 Data Register Low High
#define CAN_MODATA119LH        (*((unsigned int volatile huge *) 0x201EF2))

// Message Object 119 Data Register Low Low
#define CAN_MODATA119LL        (*((unsigned int volatile huge *) 0x201EF0))

// Message Object 11 Data Register High High
#define CAN_MODATA11HH         (*((unsigned int volatile huge *) 0x201176))

// Message Object 11 Data Register High Low
#define CAN_MODATA11HL         (*((unsigned int volatile huge *) 0x201174))

// Message Object 11 Data Register Low High
#define CAN_MODATA11LH         (*((unsigned int volatile huge *) 0x201172))

// Message Object 11 Data Register Low Low
#define CAN_MODATA11LL         (*((unsigned int volatile huge *) 0x201170))

// Message Object 120 Data Register High High
#define CAN_MODATA120HH        (*((unsigned int volatile huge *) 0x201F16))

// Message Object 120 Data Register High Low
#define CAN_MODATA120HL        (*((unsigned int volatile huge *) 0x201F14))

// Message Object 120 Data Register Low High
#define CAN_MODATA120LH        (*((unsigned int volatile huge *) 0x201F12))

// Message Object 120 Data Register Low Low
#define CAN_MODATA120LL        (*((unsigned int volatile huge *) 0x201F10))

// Message Object 121 Data Register High High
#define CAN_MODATA121HH        (*((unsigned int volatile huge *) 0x201F36))

// Message Object 121 Data Register High Low
#define CAN_MODATA121HL        (*((unsigned int volatile huge *) 0x201F34))

// Message Object 121 Data Register Low High
#define CAN_MODATA121LH        (*((unsigned int volatile huge *) 0x201F32))

// Message Object 121 Data Register Low Low
#define CAN_MODATA121LL        (*((unsigned int volatile huge *) 0x201F30))

// Message Object 122 Data Register High High
#define CAN_MODATA122HH        (*((unsigned int volatile huge *) 0x201F56))

// Message Object 122 Data Register High Low
#define CAN_MODATA122HL        (*((unsigned int volatile huge *) 0x201F54))

// Message Object 122 Data Register Low High
#define CAN_MODATA122LH        (*((unsigned int volatile huge *) 0x201F52))

// Message Object 122 Data Register Low Low
#define CAN_MODATA122LL        (*((unsigned int volatile huge *) 0x201F50))

// Message Object 123 Data Register High High
#define CAN_MODATA123HH        (*((unsigned int volatile huge *) 0x201F76))

// Message Object 123 Data Register High Low
#define CAN_MODATA123HL        (*((unsigned int volatile huge *) 0x201F74))

// Message Object 123 Data Register Low High
#define CAN_MODATA123LH        (*((unsigned int volatile huge *) 0x201F72))

// Message Object 123 Data Register Low Low
#define CAN_MODATA123LL        (*((unsigned int volatile huge *) 0x201F70))

// Message Object 124 Data Register High High
#define CAN_MODATA124HH        (*((unsigned int volatile huge *) 0x201F96))

// Message Object 124 Data Register High Low
#define CAN_MODATA124HL        (*((unsigned int volatile huge *) 0x201F94))

// Message Object 124 Data Register Low High
#define CAN_MODATA124LH        (*((unsigned int volatile huge *) 0x201F92))

// Message Object 124 Data Register Low Low
#define CAN_MODATA124LL        (*((unsigned int volatile huge *) 0x201F90))

// Message Object 125 Data Register High High
#define CAN_MODATA125HH        (*((unsigned int volatile huge *) 0x201FB6))

// Message Object 125 Data Register High Low
#define CAN_MODATA125HL        (*((unsigned int volatile huge *) 0x201FB4))

// Message Object 125 Data Register Low High
#define CAN_MODATA125LH        (*((unsigned int volatile huge *) 0x201FB2))

// Message Object 125 Data Register Low Low
#define CAN_MODATA125LL        (*((unsigned int volatile huge *) 0x201FB0))

// Message Object 126 Data Register High High
#define CAN_MODATA126HH        (*((unsigned int volatile huge *) 0x201FD6))

// Message Object 126 Data Register High Low
#define CAN_MODATA126HL        (*((unsigned int volatile huge *) 0x201FD4))

// Message Object 126 Data Register Low High
#define CAN_MODATA126LH        (*((unsigned int volatile huge *) 0x201FD2))

// Message Object 126 Data Register Low Low
#define CAN_MODATA126LL        (*((unsigned int volatile huge *) 0x201FD0))

// Message Object 127 Data Register High High
#define CAN_MODATA127HH        (*((unsigned int volatile huge *) 0x201FF6))

// Message Object 127 Data Register High Low
#define CAN_MODATA127HL        (*((unsigned int volatile huge *) 0x201FF4))

// Message Object 127 Data Register Low High
#define CAN_MODATA127LH        (*((unsigned int volatile huge *) 0x201FF2))

// Message Object 127 Data Register Low Low
#define CAN_MODATA127LL        (*((unsigned int volatile huge *) 0x201FF0))

// Message Object 12 Data Register High High
#define CAN_MODATA12HH         (*((unsigned int volatile huge *) 0x201196))

// Message Object 12 Data Register High Low
#define CAN_MODATA12HL         (*((unsigned int volatile huge *) 0x201194))

// Message Object 12 Data Register Low High
#define CAN_MODATA12LH         (*((unsigned int volatile huge *) 0x201192))

// Message Object 12 Data Register Low Low
#define CAN_MODATA12LL         (*((unsigned int volatile huge *) 0x201190))

// Message Object 13 Data Register High High
#define CAN_MODATA13HH         (*((unsigned int volatile huge *) 0x2011B6))

// Message Object 13 Data Register High Low
#define CAN_MODATA13HL         (*((unsigned int volatile huge *) 0x2011B4))

// Message Object 13 Data Register Low High
#define CAN_MODATA13LH         (*((unsigned int volatile huge *) 0x2011B2))

// Message Object 13 Data Register Low Low
#define CAN_MODATA13LL         (*((unsigned int volatile huge *) 0x2011B0))

// Message Object 14 Data Register High High
#define CAN_MODATA14HH         (*((unsigned int volatile huge *) 0x2011D6))

// Message Object 14 Data Register High Low
#define CAN_MODATA14HL         (*((unsigned int volatile huge *) 0x2011D4))

// Message Object 14 Data Register Low High
#define CAN_MODATA14LH         (*((unsigned int volatile huge *) 0x2011D2))

// Message Object 14 Data Register Low Low
#define CAN_MODATA14LL         (*((unsigned int volatile huge *) 0x2011D0))

// Message Object 15 Data Register High High
#define CAN_MODATA15HH         (*((unsigned int volatile huge *) 0x2011F6))

// Message Object 15 Data Register High Low
#define CAN_MODATA15HL         (*((unsigned int volatile huge *) 0x2011F4))

// Message Object 15 Data Register Low High
#define CAN_MODATA15LH         (*((unsigned int volatile huge *) 0x2011F2))

// Message Object 15 Data Register Low Low
#define CAN_MODATA15LL         (*((unsigned int volatile huge *) 0x2011F0))

// Message Object 16 Data Register High High
#define CAN_MODATA16HH         (*((unsigned int volatile huge *) 0x201216))

// Message Object 16 Data Register High Low
#define CAN_MODATA16HL         (*((unsigned int volatile huge *) 0x201214))

// Message Object 16 Data Register Low High
#define CAN_MODATA16LH         (*((unsigned int volatile huge *) 0x201212))

// Message Object 16 Data Register Low Low
#define CAN_MODATA16LL         (*((unsigned int volatile huge *) 0x201210))

// Message Object 17 Data Register High High
#define CAN_MODATA17HH         (*((unsigned int volatile huge *) 0x201236))

// Message Object 17 Data Register High Low
#define CAN_MODATA17HL         (*((unsigned int volatile huge *) 0x201234))

// Message Object 17 Data Register Low High
#define CAN_MODATA17LH         (*((unsigned int volatile huge *) 0x201232))

// Message Object 17 Data Register Low Low
#define CAN_MODATA17LL         (*((unsigned int volatile huge *) 0x201230))

// Message Object 18 Data Register High High
#define CAN_MODATA18HH         (*((unsigned int volatile huge *) 0x201256))

// Message Object 18 Data Register High Low
#define CAN_MODATA18HL         (*((unsigned int volatile huge *) 0x201254))

// Message Object 18 Data Register Low High
#define CAN_MODATA18LH         (*((unsigned int volatile huge *) 0x201252))

// Message Object 18 Data Register Low Low
#define CAN_MODATA18LL         (*((unsigned int volatile huge *) 0x201250))

// Message Object 19 Data Register High High
#define CAN_MODATA19HH         (*((unsigned int volatile huge *) 0x201276))

// Message Object 19 Data Register High Low
#define CAN_MODATA19HL         (*((unsigned int volatile huge *) 0x201274))

// Message Object 19 Data Register Low High
#define CAN_MODATA19LH         (*((unsigned int volatile huge *) 0x201272))

// Message Object 19 Data Register Low Low
#define CAN_MODATA19LL         (*((unsigned int volatile huge *) 0x201270))

// Message Object 1 Data Register High High
#define CAN_MODATA1HH          (*((unsigned int volatile huge *) 0x201036))

// Message Object 1 Data Register High Low
#define CAN_MODATA1HL          (*((unsigned int volatile huge *) 0x201034))

// Message Object 1 Data Register Low High
#define CAN_MODATA1LH          (*((unsigned int volatile huge *) 0x201032))

// Message Object 1 Data Register Low Low
#define CAN_MODATA1LL          (*((unsigned int volatile huge *) 0x201030))

// Message Object 20 Data Register High High
#define CAN_MODATA20HH         (*((unsigned int volatile huge *) 0x201296))

// Message Object 20 Data Register High Low
#define CAN_MODATA20HL         (*((unsigned int volatile huge *) 0x201294))

// Message Object 20 Data Register Low High
#define CAN_MODATA20LH         (*((unsigned int volatile huge *) 0x201292))

// Message Object 20 Data Register Low Low
#define CAN_MODATA20LL         (*((unsigned int volatile huge *) 0x201290))

// Message Object 21 Data Register High High
#define CAN_MODATA21HH         (*((unsigned int volatile huge *) 0x2012B6))

// Message Object 21 Data Register High Low
#define CAN_MODATA21HL         (*((unsigned int volatile huge *) 0x2012B4))

// Message Object 21 Data Register Low High
#define CAN_MODATA21LH         (*((unsigned int volatile huge *) 0x2012B2))

// Message Object 21 Data Register Low Low
#define CAN_MODATA21LL         (*((unsigned int volatile huge *) 0x2012B0))

// Message Object 22 Data Register High High
#define CAN_MODATA22HH         (*((unsigned int volatile huge *) 0x2012D6))

// Message Object 22 Data Register High Low
#define CAN_MODATA22HL         (*((unsigned int volatile huge *) 0x2012D4))

// Message Object 22 Data Register Low High
#define CAN_MODATA22LH         (*((unsigned int volatile huge *) 0x2012D2))

// Message Object 22 Data Register Low Low
#define CAN_MODATA22LL         (*((unsigned int volatile huge *) 0x2012D0))

// Message Object 23 Data Register High High
#define CAN_MODATA23HH         (*((unsigned int volatile huge *) 0x2012F6))

// Message Object 23 Data Register High Low
#define CAN_MODATA23HL         (*((unsigned int volatile huge *) 0x2012F4))

// Message Object 23 Data Register Low High
#define CAN_MODATA23LH         (*((unsigned int volatile huge *) 0x2012F2))

// Message Object 23 Data Register Low Low
#define CAN_MODATA23LL         (*((unsigned int volatile huge *) 0x2012F0))

// Message Object 24 Data Register High High
#define CAN_MODATA24HH         (*((unsigned int volatile huge *) 0x201316))

// Message Object 24 Data Register High Low
#define CAN_MODATA24HL         (*((unsigned int volatile huge *) 0x201314))

// Message Object 24 Data Register Low High
#define CAN_MODATA24LH         (*((unsigned int volatile huge *) 0x201312))

// Message Object 24 Data Register Low Low
#define CAN_MODATA24LL         (*((unsigned int volatile huge *) 0x201310))

// Message Object 25 Data Register High High
#define CAN_MODATA25HH         (*((unsigned int volatile huge *) 0x201336))

// Message Object 25 Data Register High Low
#define CAN_MODATA25HL         (*((unsigned int volatile huge *) 0x201334))

// Message Object 25 Data Register Low High
#define CAN_MODATA25LH         (*((unsigned int volatile huge *) 0x201332))

// Message Object 25 Data Register Low Low
#define CAN_MODATA25LL         (*((unsigned int volatile huge *) 0x201330))

// Message Object 26 Data Register High High
#define CAN_MODATA26HH         (*((unsigned int volatile huge *) 0x201356))

// Message Object 26 Data Register High Low
#define CAN_MODATA26HL         (*((unsigned int volatile huge *) 0x201354))

// Message Object 26 Data Register Low High
#define CAN_MODATA26LH         (*((unsigned int volatile huge *) 0x201352))

// Message Object 26 Data Register Low Low
#define CAN_MODATA26LL         (*((unsigned int volatile huge *) 0x201350))

// Message Object 27 Data Register High High
#define CAN_MODATA27HH         (*((unsigned int volatile huge *) 0x201376))

// Message Object 27 Data Register High Low
#define CAN_MODATA27HL         (*((unsigned int volatile huge *) 0x201374))

// Message Object 27 Data Register Low High
#define CAN_MODATA27LH         (*((unsigned int volatile huge *) 0x201372))

// Message Object 27 Data Register Low Low
#define CAN_MODATA27LL         (*((unsigned int volatile huge *) 0x201370))

// Message Object 28 Data Register High High
#define CAN_MODATA28HH         (*((unsigned int volatile huge *) 0x201396))

// Message Object 28 Data Register High Low
#define CAN_MODATA28HL         (*((unsigned int volatile huge *) 0x201394))

// Message Object 28 Data Register Low High
#define CAN_MODATA28LH         (*((unsigned int volatile huge *) 0x201392))

// Message Object 28 Data Register Low Low
#define CAN_MODATA28LL         (*((unsigned int volatile huge *) 0x201390))

// Message Object 29 Data Register High High
#define CAN_MODATA29HH         (*((unsigned int volatile huge *) 0x2013B6))

// Message Object 29 Data Register High Low
#define CAN_MODATA29HL         (*((unsigned int volatile huge *) 0x2013B4))

// Message Object 29 Data Register Low High
#define CAN_MODATA29LH         (*((unsigned int volatile huge *) 0x2013B2))

// Message Object 29 Data Register Low Low
#define CAN_MODATA29LL         (*((unsigned int volatile huge *) 0x2013B0))

// Message Object 2 Data Register High High
#define CAN_MODATA2HH          (*((unsigned int volatile huge *) 0x201056))

// Message Object 2 Data Register High Low
#define CAN_MODATA2HL          (*((unsigned int volatile huge *) 0x201054))

// Message Object 2 Data Register Low High
#define CAN_MODATA2LH          (*((unsigned int volatile huge *) 0x201052))

// Message Object 2 Data Register Low Low
#define CAN_MODATA2LL          (*((unsigned int volatile huge *) 0x201050))

// Message Object 30 Data Register High High
#define CAN_MODATA30HH         (*((unsigned int volatile huge *) 0x2013D6))

// Message Object 30 Data Register High Low
#define CAN_MODATA30HL         (*((unsigned int volatile huge *) 0x2013D4))

// Message Object 30 Data Register Low High
#define CAN_MODATA30LH         (*((unsigned int volatile huge *) 0x2013D2))

// Message Object 30 Data Register Low Low
#define CAN_MODATA30LL         (*((unsigned int volatile huge *) 0x2013D0))

// Message Object 31 Data Register High High
#define CAN_MODATA31HH         (*((unsigned int volatile huge *) 0x2013F6))

// Message Object 31 Data Register High Low
#define CAN_MODATA31HL         (*((unsigned int volatile huge *) 0x2013F4))

// Message Object 31 Data Register Low High
#define CAN_MODATA31LH         (*((unsigned int volatile huge *) 0x2013F2))

// Message Object 31 Data Register Low Low
#define CAN_MODATA31LL         (*((unsigned int volatile huge *) 0x2013F0))

// Message Object 32 Data Register High High
#define CAN_MODATA32HH         (*((unsigned int volatile huge *) 0x201416))

// Message Object 32 Data Register High Low
#define CAN_MODATA32HL         (*((unsigned int volatile huge *) 0x201414))

// Message Object 32 Data Register Low High
#define CAN_MODATA32LH         (*((unsigned int volatile huge *) 0x201412))

// Message Object 32 Data Register Low Low
#define CAN_MODATA32LL         (*((unsigned int volatile huge *) 0x201410))

// Message Object 33 Data Register High High
#define CAN_MODATA33HH         (*((unsigned int volatile huge *) 0x201436))

// Message Object 33 Data Register High Low
#define CAN_MODATA33HL         (*((unsigned int volatile huge *) 0x201434))

// Message Object 33 Data Register Low High
#define CAN_MODATA33LH         (*((unsigned int volatile huge *) 0x201432))

// Message Object 33 Data Register Low Low
#define CAN_MODATA33LL         (*((unsigned int volatile huge *) 0x201430))

// Message Object 34 Data Register High High
#define CAN_MODATA34HH         (*((unsigned int volatile huge *) 0x201456))

// Message Object 34 Data Register High Low
#define CAN_MODATA34HL         (*((unsigned int volatile huge *) 0x201454))

// Message Object 34 Data Register Low High
#define CAN_MODATA34LH         (*((unsigned int volatile huge *) 0x201452))

// Message Object 34 Data Register Low Low
#define CAN_MODATA34LL         (*((unsigned int volatile huge *) 0x201450))

// Message Object 35 Data Register High High
#define CAN_MODATA35HH         (*((unsigned int volatile huge *) 0x201476))

// Message Object 35 Data Register High Low
#define CAN_MODATA35HL         (*((unsigned int volatile huge *) 0x201474))

// Message Object 35 Data Register Low High
#define CAN_MODATA35LH         (*((unsigned int volatile huge *) 0x201472))

// Message Object 35 Data Register Low Low
#define CAN_MODATA35LL         (*((unsigned int volatile huge *) 0x201470))

// Message Object 36 Data Register High High
#define CAN_MODATA36HH         (*((unsigned int volatile huge *) 0x201496))

// Message Object 36 Data Register High Low
#define CAN_MODATA36HL         (*((unsigned int volatile huge *) 0x201494))

// Message Object 36 Data Register Low High
#define CAN_MODATA36LH         (*((unsigned int volatile huge *) 0x201492))

// Message Object 36 Data Register Low Low
#define CAN_MODATA36LL         (*((unsigned int volatile huge *) 0x201490))

// Message Object 37 Data Register High High
#define CAN_MODATA37HH         (*((unsigned int volatile huge *) 0x2014B6))

// Message Object 37 Data Register High Low
#define CAN_MODATA37HL         (*((unsigned int volatile huge *) 0x2014B4))

// Message Object 37 Data Register Low High
#define CAN_MODATA37LH         (*((unsigned int volatile huge *) 0x2014B2))

// Message Object 37 Data Register Low Low
#define CAN_MODATA37LL         (*((unsigned int volatile huge *) 0x2014B0))

// Message Object 38 Data Register High High
#define CAN_MODATA38HH         (*((unsigned int volatile huge *) 0x2014D6))

// Message Object 38 Data Register High Low
#define CAN_MODATA38HL         (*((unsigned int volatile huge *) 0x2014D4))

// Message Object 38 Data Register Low High
#define CAN_MODATA38LH         (*((unsigned int volatile huge *) 0x2014D2))

// Message Object 38 Data Register Low Low
#define CAN_MODATA38LL         (*((unsigned int volatile huge *) 0x2014D0))

// Message Object 39 Data Register High High
#define CAN_MODATA39HH         (*((unsigned int volatile huge *) 0x2014F6))

// Message Object 39 Data Register High Low
#define CAN_MODATA39HL         (*((unsigned int volatile huge *) 0x2014F4))

// Message Object 39 Data Register Low High
#define CAN_MODATA39LH         (*((unsigned int volatile huge *) 0x2014F2))

// Message Object 39 Data Register Low Low
#define CAN_MODATA39LL         (*((unsigned int volatile huge *) 0x2014F0))

// Message Object 3 Data Register High High
#define CAN_MODATA3HH          (*((unsigned int volatile huge *) 0x201076))

// Message Object 3 Data Register High Low
#define CAN_MODATA3HL          (*((unsigned int volatile huge *) 0x201074))

// Message Object 3 Data Register Low High
#define CAN_MODATA3LH          (*((unsigned int volatile huge *) 0x201072))

// Message Object 3 Data Register Low Low
#define CAN_MODATA3LL          (*((unsigned int volatile huge *) 0x201070))

// Message Object 40 Data Register High High
#define CAN_MODATA40HH         (*((unsigned int volatile huge *) 0x201516))

// Message Object 40 Data Register High Low
#define CAN_MODATA40HL         (*((unsigned int volatile huge *) 0x201514))

// Message Object 40 Data Register Low High
#define CAN_MODATA40LH         (*((unsigned int volatile huge *) 0x201512))

// Message Object 40 Data Register Low Low
#define CAN_MODATA40LL         (*((unsigned int volatile huge *) 0x201510))

// Message Object 41 Data Register High High
#define CAN_MODATA41HH         (*((unsigned int volatile huge *) 0x201536))

// Message Object 41 Data Register High Low
#define CAN_MODATA41HL         (*((unsigned int volatile huge *) 0x201534))

// Message Object 41 Data Register Low High
#define CAN_MODATA41LH         (*((unsigned int volatile huge *) 0x201532))

// Message Object 41 Data Register Low Low
#define CAN_MODATA41LL         (*((unsigned int volatile huge *) 0x201530))

// Message Object 42 Data Register High High
#define CAN_MODATA42HH         (*((unsigned int volatile huge *) 0x201556))

// Message Object 42 Data Register High Low
#define CAN_MODATA42HL         (*((unsigned int volatile huge *) 0x201554))

// Message Object 42 Data Register Low High
#define CAN_MODATA42LH         (*((unsigned int volatile huge *) 0x201552))

// Message Object 42 Data Register Low Low
#define CAN_MODATA42LL         (*((unsigned int volatile huge *) 0x201550))

// Message Object 43 Data Register High High
#define CAN_MODATA43HH         (*((unsigned int volatile huge *) 0x201576))

// Message Object 43 Data Register High Low
#define CAN_MODATA43HL         (*((unsigned int volatile huge *) 0x201574))

// Message Object 43 Data Register Low High
#define CAN_MODATA43LH         (*((unsigned int volatile huge *) 0x201572))

// Message Object 43 Data Register Low Low
#define CAN_MODATA43LL         (*((unsigned int volatile huge *) 0x201570))

// Message Object 44 Data Register High High
#define CAN_MODATA44HH         (*((unsigned int volatile huge *) 0x201596))

// Message Object 44 Data Register High Low
#define CAN_MODATA44HL         (*((unsigned int volatile huge *) 0x201594))

// Message Object 44 Data Register Low High
#define CAN_MODATA44LH         (*((unsigned int volatile huge *) 0x201592))

// Message Object 44 Data Register Low Low
#define CAN_MODATA44LL         (*((unsigned int volatile huge *) 0x201590))

// Message Object 45 Data Register High High
#define CAN_MODATA45HH         (*((unsigned int volatile huge *) 0x2015B6))

// Message Object 45 Data Register High Low
#define CAN_MODATA45HL         (*((unsigned int volatile huge *) 0x2015B4))

// Message Object 45 Data Register Low High
#define CAN_MODATA45LH         (*((unsigned int volatile huge *) 0x2015B2))

// Message Object 45 Data Register Low Low
#define CAN_MODATA45LL         (*((unsigned int volatile huge *) 0x2015B0))

// Message Object 46 Data Register High High
#define CAN_MODATA46HH         (*((unsigned int volatile huge *) 0x2015D6))

// Message Object 46 Data Register High Low
#define CAN_MODATA46HL         (*((unsigned int volatile huge *) 0x2015D4))

// Message Object 46 Data Register Low High
#define CAN_MODATA46LH         (*((unsigned int volatile huge *) 0x2015D2))

// Message Object 46 Data Register Low Low
#define CAN_MODATA46LL         (*((unsigned int volatile huge *) 0x2015D0))

// Message Object 47 Data Register High High
#define CAN_MODATA47HH         (*((unsigned int volatile huge *) 0x2015F6))

// Message Object 47 Data Register High Low
#define CAN_MODATA47HL         (*((unsigned int volatile huge *) 0x2015F4))

// Message Object 47 Data Register Low High
#define CAN_MODATA47LH         (*((unsigned int volatile huge *) 0x2015F2))

// Message Object 47 Data Register Low Low
#define CAN_MODATA47LL         (*((unsigned int volatile huge *) 0x2015F0))

// Message Object 48 Data Register High High
#define CAN_MODATA48HH         (*((unsigned int volatile huge *) 0x201616))

// Message Object 48 Data Register High Low
#define CAN_MODATA48HL         (*((unsigned int volatile huge *) 0x201614))

// Message Object 48 Data Register Low High
#define CAN_MODATA48LH         (*((unsigned int volatile huge *) 0x201612))

// Message Object 48 Data Register Low Low
#define CAN_MODATA48LL         (*((unsigned int volatile huge *) 0x201610))

// Message Object 49 Data Register High High
#define CAN_MODATA49HH         (*((unsigned int volatile huge *) 0x201636))

// Message Object 49 Data Register High Low
#define CAN_MODATA49HL         (*((unsigned int volatile huge *) 0x201634))

// Message Object 49 Data Register Low High
#define CAN_MODATA49LH         (*((unsigned int volatile huge *) 0x201632))

// Message Object 49 Data Register Low Low
#define CAN_MODATA49LL         (*((unsigned int volatile huge *) 0x201630))

// Message Object 4 Data Register High High
#define CAN_MODATA4HH          (*((unsigned int volatile huge *) 0x201096))

// Message Object 4 Data Register High Low
#define CAN_MODATA4HL          (*((unsigned int volatile huge *) 0x201094))

// Message Object 4 Data Register Low High
#define CAN_MODATA4LH          (*((unsigned int volatile huge *) 0x201092))

// Message Object 4 Data Register Low Low
#define CAN_MODATA4LL          (*((unsigned int volatile huge *) 0x201090))

// Message Object 50 Data Register High High
#define CAN_MODATA50HH         (*((unsigned int volatile huge *) 0x201656))

// Message Object 50 Data Register High Low
#define CAN_MODATA50HL         (*((unsigned int volatile huge *) 0x201654))

// Message Object 50 Data Register Low High
#define CAN_MODATA50LH         (*((unsigned int volatile huge *) 0x201652))

// Message Object 50 Data Register Low Low
#define CAN_MODATA50LL         (*((unsigned int volatile huge *) 0x201650))

// Message Object 51 Data Register High High
#define CAN_MODATA51HH         (*((unsigned int volatile huge *) 0x201676))

// Message Object 51 Data Register High Low
#define CAN_MODATA51HL         (*((unsigned int volatile huge *) 0x201674))

// Message Object 51 Data Register Low High
#define CAN_MODATA51LH         (*((unsigned int volatile huge *) 0x201672))

// Message Object 51 Data Register Low Low
#define CAN_MODATA51LL         (*((unsigned int volatile huge *) 0x201670))

// Message Object 52 Data Register High High
#define CAN_MODATA52HH         (*((unsigned int volatile huge *) 0x201696))

// Message Object 52 Data Register High Low
#define CAN_MODATA52HL         (*((unsigned int volatile huge *) 0x201694))

// Message Object 52 Data Register Low High
#define CAN_MODATA52LH         (*((unsigned int volatile huge *) 0x201692))

// Message Object 52 Data Register Low Low
#define CAN_MODATA52LL         (*((unsigned int volatile huge *) 0x201690))

// Message Object 53 Data Register High High
#define CAN_MODATA53HH         (*((unsigned int volatile huge *) 0x2016B6))

// Message Object 53 Data Register High Low
#define CAN_MODATA53HL         (*((unsigned int volatile huge *) 0x2016B4))

// Message Object 53 Data Register Low High
#define CAN_MODATA53LH         (*((unsigned int volatile huge *) 0x2016B2))

// Message Object 53 Data Register Low Low
#define CAN_MODATA53LL         (*((unsigned int volatile huge *) 0x2016B0))

// Message Object 54 Data Register High High
#define CAN_MODATA54HH         (*((unsigned int volatile huge *) 0x2016D6))

// Message Object 54 Data Register High Low
#define CAN_MODATA54HL         (*((unsigned int volatile huge *) 0x2016D4))

// Message Object 54 Data Register Low High
#define CAN_MODATA54LH         (*((unsigned int volatile huge *) 0x2016D2))

// Message Object 54 Data Register Low Low
#define CAN_MODATA54LL         (*((unsigned int volatile huge *) 0x2016D0))

// Message Object 55 Data Register High High
#define CAN_MODATA55HH         (*((unsigned int volatile huge *) 0x2016F6))

// Message Object 55 Data Register High Low
#define CAN_MODATA55HL         (*((unsigned int volatile huge *) 0x2016F4))

// Message Object 55 Data Register Low High
#define CAN_MODATA55LH         (*((unsigned int volatile huge *) 0x2016F2))

// Message Object 55 Data Register Low Low
#define CAN_MODATA55LL         (*((unsigned int volatile huge *) 0x2016F0))

// Message Object 56 Data Register High High
#define CAN_MODATA56HH         (*((unsigned int volatile huge *) 0x201716))

// Message Object 56 Data Register High Low
#define CAN_MODATA56HL         (*((unsigned int volatile huge *) 0x201714))

// Message Object 56 Data Register Low High
#define CAN_MODATA56LH         (*((unsigned int volatile huge *) 0x201712))

// Message Object 56 Data Register Low Low
#define CAN_MODATA56LL         (*((unsigned int volatile huge *) 0x201710))

// Message Object 57 Data Register High High
#define CAN_MODATA57HH         (*((unsigned int volatile huge *) 0x201736))

// Message Object 57 Data Register High Low
#define CAN_MODATA57HL         (*((unsigned int volatile huge *) 0x201734))

// Message Object 57 Data Register Low High
#define CAN_MODATA57LH         (*((unsigned int volatile huge *) 0x201732))

// Message Object 57 Data Register Low Low
#define CAN_MODATA57LL         (*((unsigned int volatile huge *) 0x201730))

// Message Object 58 Data Register High High
#define CAN_MODATA58HH         (*((unsigned int volatile huge *) 0x201756))

// Message Object 58 Data Register High Low
#define CAN_MODATA58HL         (*((unsigned int volatile huge *) 0x201754))

// Message Object 58 Data Register Low High
#define CAN_MODATA58LH         (*((unsigned int volatile huge *) 0x201752))

// Message Object 58 Data Register Low Low
#define CAN_MODATA58LL         (*((unsigned int volatile huge *) 0x201750))

// Message Object 59 Data Register High High
#define CAN_MODATA59HH         (*((unsigned int volatile huge *) 0x201776))

// Message Object 59 Data Register High Low
#define CAN_MODATA59HL         (*((unsigned int volatile huge *) 0x201774))

// Message Object 59 Data Register Low High
#define CAN_MODATA59LH         (*((unsigned int volatile huge *) 0x201772))

// Message Object 59 Data Register Low Low
#define CAN_MODATA59LL         (*((unsigned int volatile huge *) 0x201770))

// Message Object 5 Data Register High High
#define CAN_MODATA5HH          (*((unsigned int volatile huge *) 0x2010B6))

// Message Object 5 Data Register High Low
#define CAN_MODATA5HL          (*((unsigned int volatile huge *) 0x2010B4))

// Message Object 5 Data Register Low High
#define CAN_MODATA5LH          (*((unsigned int volatile huge *) 0x2010B2))

// Message Object 5 Data Register Low Low
#define CAN_MODATA5LL          (*((unsigned int volatile huge *) 0x2010B0))

// Message Object 60 Data Register High High
#define CAN_MODATA60HH         (*((unsigned int volatile huge *) 0x201796))

// Message Object 60 Data Register High Low
#define CAN_MODATA60HL         (*((unsigned int volatile huge *) 0x201794))

// Message Object 60 Data Register Low High
#define CAN_MODATA60LH         (*((unsigned int volatile huge *) 0x201792))

// Message Object 60 Data Register Low Low
#define CAN_MODATA60LL         (*((unsigned int volatile huge *) 0x201790))

// Message Object 61 Data Register High High
#define CAN_MODATA61HH         (*((unsigned int volatile huge *) 0x2017B6))

// Message Object 61 Data Register High Low
#define CAN_MODATA61HL         (*((unsigned int volatile huge *) 0x2017B4))

// Message Object 61 Data Register Low High
#define CAN_MODATA61LH         (*((unsigned int volatile huge *) 0x2017B2))

// Message Object 61 Data Register Low Low
#define CAN_MODATA61LL         (*((unsigned int volatile huge *) 0x2017B0))

// Message Object 62 Data Register High High
#define CAN_MODATA62HH         (*((unsigned int volatile huge *) 0x2017D6))

// Message Object 62 Data Register High Low
#define CAN_MODATA62HL         (*((unsigned int volatile huge *) 0x2017D4))

// Message Object 62 Data Register Low High
#define CAN_MODATA62LH         (*((unsigned int volatile huge *) 0x2017D2))

// Message Object 62 Data Register Low Low
#define CAN_MODATA62LL         (*((unsigned int volatile huge *) 0x2017D0))

// Message Object 63 Data Register High High
#define CAN_MODATA63HH         (*((unsigned int volatile huge *) 0x2017F6))

// Message Object 63 Data Register High Low
#define CAN_MODATA63HL         (*((unsigned int volatile huge *) 0x2017F4))

// Message Object 63 Data Register Low High
#define CAN_MODATA63LH         (*((unsigned int volatile huge *) 0x2017F2))

// Message Object 63 Data Register Low Low
#define CAN_MODATA63LL         (*((unsigned int volatile huge *) 0x2017F0))

// Message Object 64 Data Register High High
#define CAN_MODATA64HH         (*((unsigned int volatile huge *) 0x201816))

// Message Object 64 Data Register High Low
#define CAN_MODATA64HL         (*((unsigned int volatile huge *) 0x201814))

// Message Object 64 Data Register Low High
#define CAN_MODATA64LH         (*((unsigned int volatile huge *) 0x201812))

// Message Object 64 Data Register Low Low
#define CAN_MODATA64LL         (*((unsigned int volatile huge *) 0x201810))

// Message Object 65 Data Register High High
#define CAN_MODATA65HH         (*((unsigned int volatile huge *) 0x201836))

// Message Object 65 Data Register High Low
#define CAN_MODATA65HL         (*((unsigned int volatile huge *) 0x201834))

// Message Object 65 Data Register Low High
#define CAN_MODATA65LH         (*((unsigned int volatile huge *) 0x201832))

// Message Object 65 Data Register Low Low
#define CAN_MODATA65LL         (*((unsigned int volatile huge *) 0x201830))

// Message Object 66 Data Register High High
#define CAN_MODATA66HH         (*((unsigned int volatile huge *) 0x201856))

// Message Object 66 Data Register High Low
#define CAN_MODATA66HL         (*((unsigned int volatile huge *) 0x201854))

// Message Object 66 Data Register Low High
#define CAN_MODATA66LH         (*((unsigned int volatile huge *) 0x201852))

// Message Object 66 Data Register Low Low
#define CAN_MODATA66LL         (*((unsigned int volatile huge *) 0x201850))

// Message Object 67 Data Register High High
#define CAN_MODATA67HH         (*((unsigned int volatile huge *) 0x201876))

// Message Object 67 Data Register High Low
#define CAN_MODATA67HL         (*((unsigned int volatile huge *) 0x201874))

// Message Object 67 Data Register Low High
#define CAN_MODATA67LH         (*((unsigned int volatile huge *) 0x201872))

// Message Object 67 Data Register Low Low
#define CAN_MODATA67LL         (*((unsigned int volatile huge *) 0x201870))

// Message Object 68 Data Register High High
#define CAN_MODATA68HH         (*((unsigned int volatile huge *) 0x201896))

// Message Object 68 Data Register High Low
#define CAN_MODATA68HL         (*((unsigned int volatile huge *) 0x201894))

// Message Object 68 Data Register Low High
#define CAN_MODATA68LH         (*((unsigned int volatile huge *) 0x201892))

// Message Object 68 Data Register Low Low
#define CAN_MODATA68LL         (*((unsigned int volatile huge *) 0x201890))

// Message Object 69 Data Register High High
#define CAN_MODATA69HH         (*((unsigned int volatile huge *) 0x2018B6))

// Message Object 69 Data Register High Low
#define CAN_MODATA69HL         (*((unsigned int volatile huge *) 0x2018B4))

// Message Object 69 Data Register Low High
#define CAN_MODATA69LH         (*((unsigned int volatile huge *) 0x2018B2))

// Message Object 69 Data Register Low Low
#define CAN_MODATA69LL         (*((unsigned int volatile huge *) 0x2018B0))

// Message Object 6 Data Register High High
#define CAN_MODATA6HH          (*((unsigned int volatile huge *) 0x2010D6))

// Message Object 6 Data Register High Low
#define CAN_MODATA6HL          (*((unsigned int volatile huge *) 0x2010D4))

// Message Object 6 Data Register Low High
#define CAN_MODATA6LH          (*((unsigned int volatile huge *) 0x2010D2))

// Message Object 6 Data Register Low Low
#define CAN_MODATA6LL          (*((unsigned int volatile huge *) 0x2010D0))

// Message Object 70 Data Register High High
#define CAN_MODATA70HH         (*((unsigned int volatile huge *) 0x2018D6))

// Message Object 70 Data Register High Low
#define CAN_MODATA70HL         (*((unsigned int volatile huge *) 0x2018D4))

// Message Object 70 Data Register Low High
#define CAN_MODATA70LH         (*((unsigned int volatile huge *) 0x2018D2))

// Message Object 70 Data Register Low Low
#define CAN_MODATA70LL         (*((unsigned int volatile huge *) 0x2018D0))

// Message Object 71 Data Register High High
#define CAN_MODATA71HH         (*((unsigned int volatile huge *) 0x2018F6))

// Message Object 71 Data Register High Low
#define CAN_MODATA71HL         (*((unsigned int volatile huge *) 0x2018F4))

// Message Object 71 Data Register Low High
#define CAN_MODATA71LH         (*((unsigned int volatile huge *) 0x2018F2))

// Message Object 71 Data Register Low Low
#define CAN_MODATA71LL         (*((unsigned int volatile huge *) 0x2018F0))

// Message Object 72 Data Register High High
#define CAN_MODATA72HH         (*((unsigned int volatile huge *) 0x201916))

// Message Object 72 Data Register High Low
#define CAN_MODATA72HL         (*((unsigned int volatile huge *) 0x201914))

// Message Object 72 Data Register Low High
#define CAN_MODATA72LH         (*((unsigned int volatile huge *) 0x201912))

// Message Object 72 Data Register Low Low
#define CAN_MODATA72LL         (*((unsigned int volatile huge *) 0x201910))

// Message Object 73 Data Register High High
#define CAN_MODATA73HH         (*((unsigned int volatile huge *) 0x201936))

// Message Object 73 Data Register High Low
#define CAN_MODATA73HL         (*((unsigned int volatile huge *) 0x201934))

// Message Object 73 Data Register Low High
#define CAN_MODATA73LH         (*((unsigned int volatile huge *) 0x201932))

// Message Object 73 Data Register Low Low
#define CAN_MODATA73LL         (*((unsigned int volatile huge *) 0x201930))

// Message Object 74 Data Register High High
#define CAN_MODATA74HH         (*((unsigned int volatile huge *) 0x201956))

// Message Object 74 Data Register High Low
#define CAN_MODATA74HL         (*((unsigned int volatile huge *) 0x201954))

// Message Object 74 Data Register Low High
#define CAN_MODATA74LH         (*((unsigned int volatile huge *) 0x201952))

// Message Object 74 Data Register Low Low
#define CAN_MODATA74LL         (*((unsigned int volatile huge *) 0x201950))

// Message Object 75 Data Register High High
#define CAN_MODATA75HH         (*((unsigned int volatile huge *) 0x201976))

// Message Object 75 Data Register High Low
#define CAN_MODATA75HL         (*((unsigned int volatile huge *) 0x201974))

// Message Object 75 Data Register Low High
#define CAN_MODATA75LH         (*((unsigned int volatile huge *) 0x201972))

// Message Object 75 Data Register Low Low
#define CAN_MODATA75LL         (*((unsigned int volatile huge *) 0x201970))

// Message Object 76 Data Register High High
#define CAN_MODATA76HH         (*((unsigned int volatile huge *) 0x201996))

// Message Object 76 Data Register High Low
#define CAN_MODATA76HL         (*((unsigned int volatile huge *) 0x201994))

// Message Object 76 Data Register Low High
#define CAN_MODATA76LH         (*((unsigned int volatile huge *) 0x201992))

// Message Object 76 Data Register Low Low
#define CAN_MODATA76LL         (*((unsigned int volatile huge *) 0x201990))

// Message Object 77 Data Register High High
#define CAN_MODATA77HH         (*((unsigned int volatile huge *) 0x2019B6))

// Message Object 77 Data Register High Low
#define CAN_MODATA77HL         (*((unsigned int volatile huge *) 0x2019B4))

// Message Object 77 Data Register Low High
#define CAN_MODATA77LH         (*((unsigned int volatile huge *) 0x2019B2))

// Message Object 77 Data Register Low Low
#define CAN_MODATA77LL         (*((unsigned int volatile huge *) 0x2019B0))

// Message Object 78 Data Register High High
#define CAN_MODATA78HH         (*((unsigned int volatile huge *) 0x2019D6))

// Message Object 78 Data Register High Low
#define CAN_MODATA78HL         (*((unsigned int volatile huge *) 0x2019D4))

// Message Object 78 Data Register Low High
#define CAN_MODATA78LH         (*((unsigned int volatile huge *) 0x2019D2))

// Message Object 78 Data Register Low Low
#define CAN_MODATA78LL         (*((unsigned int volatile huge *) 0x2019D0))

// Message Object 79 Data Register High High
#define CAN_MODATA79HH         (*((unsigned int volatile huge *) 0x2019F6))

// Message Object 79 Data Register High Low
#define CAN_MODATA79HL         (*((unsigned int volatile huge *) 0x2019F4))

// Message Object 79 Data Register Low High
#define CAN_MODATA79LH         (*((unsigned int volatile huge *) 0x2019F2))

// Message Object 79 Data Register Low Low
#define CAN_MODATA79LL         (*((unsigned int volatile huge *) 0x2019F0))

// Message Object 7 Data Register High High
#define CAN_MODATA7HH          (*((unsigned int volatile huge *) 0x2010F6))

// Message Object 7 Data Register High Low
#define CAN_MODATA7HL          (*((unsigned int volatile huge *) 0x2010F4))

// Message Object 7 Data Register Low High
#define CAN_MODATA7LH          (*((unsigned int volatile huge *) 0x2010F2))

// Message Object 7 Data Register Low Low
#define CAN_MODATA7LL          (*((unsigned int volatile huge *) 0x2010F0))

// Message Object 80 Data Register High High
#define CAN_MODATA80HH         (*((unsigned int volatile huge *) 0x201A16))

// Message Object 80 Data Register High Low
#define CAN_MODATA80HL         (*((unsigned int volatile huge *) 0x201A14))

// Message Object 80 Data Register Low High
#define CAN_MODATA80LH         (*((unsigned int volatile huge *) 0x201A12))

// Message Object 80 Data Register Low Low
#define CAN_MODATA80LL         (*((unsigned int volatile huge *) 0x201A10))

// Message Object 81 Data Register High High
#define CAN_MODATA81HH         (*((unsigned int volatile huge *) 0x201A36))

// Message Object 81 Data Register High Low
#define CAN_MODATA81HL         (*((unsigned int volatile huge *) 0x201A34))

// Message Object 81 Data Register Low High
#define CAN_MODATA81LH         (*((unsigned int volatile huge *) 0x201A32))

// Message Object 81 Data Register Low Low
#define CAN_MODATA81LL         (*((unsigned int volatile huge *) 0x201A30))

// Message Object 82 Data Register High High
#define CAN_MODATA82HH         (*((unsigned int volatile huge *) 0x201A56))

// Message Object 82 Data Register High Low
#define CAN_MODATA82HL         (*((unsigned int volatile huge *) 0x201A54))

// Message Object 82 Data Register Low High
#define CAN_MODATA82LH         (*((unsigned int volatile huge *) 0x201A52))

// Message Object 82 Data Register Low Low
#define CAN_MODATA82LL         (*((unsigned int volatile huge *) 0x201A50))

// Message Object 83 Data Register High High
#define CAN_MODATA83HH         (*((unsigned int volatile huge *) 0x201A76))

// Message Object 83 Data Register High Low
#define CAN_MODATA83HL         (*((unsigned int volatile huge *) 0x201A74))

// Message Object 83 Data Register Low High
#define CAN_MODATA83LH         (*((unsigned int volatile huge *) 0x201A72))

// Message Object 83 Data Register Low Low
#define CAN_MODATA83LL         (*((unsigned int volatile huge *) 0x201A70))

// Message Object 84 Data Register High High
#define CAN_MODATA84HH         (*((unsigned int volatile huge *) 0x201A96))

// Message Object 84 Data Register High Low
#define CAN_MODATA84HL         (*((unsigned int volatile huge *) 0x201A94))

// Message Object 84 Data Register Low High
#define CAN_MODATA84LH         (*((unsigned int volatile huge *) 0x201A92))

// Message Object 84 Data Register Low Low
#define CAN_MODATA84LL         (*((unsigned int volatile huge *) 0x201A90))

// Message Object 85 Data Register High High
#define CAN_MODATA85HH         (*((unsigned int volatile huge *) 0x201AB6))

// Message Object 85 Data Register High Low
#define CAN_MODATA85HL         (*((unsigned int volatile huge *) 0x201AB4))

// Message Object 85 Data Register Low High
#define CAN_MODATA85LH         (*((unsigned int volatile huge *) 0x201AB2))

// Message Object 85 Data Register Low Low
#define CAN_MODATA85LL         (*((unsigned int volatile huge *) 0x201AB0))

// Message Object 86 Data Register High High
#define CAN_MODATA86HH         (*((unsigned int volatile huge *) 0x201AD6))

// Message Object 86 Data Register High Low
#define CAN_MODATA86HL         (*((unsigned int volatile huge *) 0x201AD4))

// Message Object 86 Data Register Low High
#define CAN_MODATA86LH         (*((unsigned int volatile huge *) 0x201AD2))

// Message Object 86 Data Register Low Low
#define CAN_MODATA86LL         (*((unsigned int volatile huge *) 0x201AD0))

// Message Object 87 Data Register High High
#define CAN_MODATA87HH         (*((unsigned int volatile huge *) 0x201AF6))

// Message Object 87 Data Register High Low
#define CAN_MODATA87HL         (*((unsigned int volatile huge *) 0x201AF4))

// Message Object 87 Data Register Low High
#define CAN_MODATA87LH         (*((unsigned int volatile huge *) 0x201AF2))

// Message Object 87 Data Register Low Low
#define CAN_MODATA87LL         (*((unsigned int volatile huge *) 0x201AF0))

// Message Object 88 Data Register High High
#define CAN_MODATA88HH         (*((unsigned int volatile huge *) 0x201B16))

// Message Object 88 Data Register High Low
#define CAN_MODATA88HL         (*((unsigned int volatile huge *) 0x201B14))

// Message Object 88 Data Register Low High
#define CAN_MODATA88LH         (*((unsigned int volatile huge *) 0x201B12))

// Message Object 88 Data Register Low Low
#define CAN_MODATA88LL         (*((unsigned int volatile huge *) 0x201B10))

// Message Object 89 Data Register High High
#define CAN_MODATA89HH         (*((unsigned int volatile huge *) 0x201B36))

// Message Object 89 Data Register High Low
#define CAN_MODATA89HL         (*((unsigned int volatile huge *) 0x201B34))

// Message Object 89 Data Register Low High
#define CAN_MODATA89LH         (*((unsigned int volatile huge *) 0x201B32))

// Message Object 89 Data Register Low Low
#define CAN_MODATA89LL         (*((unsigned int volatile huge *) 0x201B30))

// Message Object 8 Data Register High High
#define CAN_MODATA8HH          (*((unsigned int volatile huge *) 0x201116))

// Message Object 8 Data Register High Low
#define CAN_MODATA8HL          (*((unsigned int volatile huge *) 0x201114))

// Message Object 8 Data Register Low High
#define CAN_MODATA8LH          (*((unsigned int volatile huge *) 0x201112))

// Message Object 8 Data Register Low Low
#define CAN_MODATA8LL          (*((unsigned int volatile huge *) 0x201110))

// Message Object 90 Data Register High High
#define CAN_MODATA90HH         (*((unsigned int volatile huge *) 0x201B56))

// Message Object 90 Data Register High Low
#define CAN_MODATA90HL         (*((unsigned int volatile huge *) 0x201B54))

// Message Object 90 Data Register Low High
#define CAN_MODATA90LH         (*((unsigned int volatile huge *) 0x201B52))

// Message Object 90 Data Register Low Low
#define CAN_MODATA90LL         (*((unsigned int volatile huge *) 0x201B50))

// Message Object 91 Data Register High High
#define CAN_MODATA91HH         (*((unsigned int volatile huge *) 0x201B76))

// Message Object 91 Data Register High Low
#define CAN_MODATA91HL         (*((unsigned int volatile huge *) 0x201B74))

// Message Object 91 Data Register Low High
#define CAN_MODATA91LH         (*((unsigned int volatile huge *) 0x201B72))

// Message Object 91 Data Register Low Low
#define CAN_MODATA91LL         (*((unsigned int volatile huge *) 0x201B70))

// Message Object 92 Data Register High High
#define CAN_MODATA92HH         (*((unsigned int volatile huge *) 0x201B96))

// Message Object 92 Data Register High Low
#define CAN_MODATA92HL         (*((unsigned int volatile huge *) 0x201B94))

// Message Object 92 Data Register Low High
#define CAN_MODATA92LH         (*((unsigned int volatile huge *) 0x201B92))

// Message Object 92 Data Register Low Low
#define CAN_MODATA92LL         (*((unsigned int volatile huge *) 0x201B90))

// Message Object 93 Data Register High High
#define CAN_MODATA93HH         (*((unsigned int volatile huge *) 0x201BB6))

// Message Object 93 Data Register High Low
#define CAN_MODATA93HL         (*((unsigned int volatile huge *) 0x201BB4))

// Message Object 93 Data Register Low High
#define CAN_MODATA93LH         (*((unsigned int volatile huge *) 0x201BB2))

// Message Object 93 Data Register Low Low
#define CAN_MODATA93LL         (*((unsigned int volatile huge *) 0x201BB0))

// Message Object 94 Data Register High High
#define CAN_MODATA94HH         (*((unsigned int volatile huge *) 0x201BD6))

// Message Object 94 Data Register High Low
#define CAN_MODATA94HL         (*((unsigned int volatile huge *) 0x201BD4))

// Message Object 94 Data Register Low High
#define CAN_MODATA94LH         (*((unsigned int volatile huge *) 0x201BD2))

// Message Object 94 Data Register Low Low
#define CAN_MODATA94LL         (*((unsigned int volatile huge *) 0x201BD0))

// Message Object 95 Data Register High High
#define CAN_MODATA95HH         (*((unsigned int volatile huge *) 0x201BF6))

// Message Object 95 Data Register High Low
#define CAN_MODATA95HL         (*((unsigned int volatile huge *) 0x201BF4))

// Message Object 95 Data Register Low High
#define CAN_MODATA95LH         (*((unsigned int volatile huge *) 0x201BF2))

// Message Object 95 Data Register Low Low
#define CAN_MODATA95LL         (*((unsigned int volatile huge *) 0x201BF0))

// Message Object 96 Data Register High High
#define CAN_MODATA96HH         (*((unsigned int volatile huge *) 0x201C16))

// Message Object 96 Data Register High Low
#define CAN_MODATA96HL         (*((unsigned int volatile huge *) 0x201C14))

// Message Object 96 Data Register Low High
#define CAN_MODATA96LH         (*((unsigned int volatile huge *) 0x201C12))

// Message Object 96 Data Register Low Low
#define CAN_MODATA96LL         (*((unsigned int volatile huge *) 0x201C10))

// Message Object 97 Data Register High High
#define CAN_MODATA97HH         (*((unsigned int volatile huge *) 0x201C36))

// Message Object 97 Data Register High Low
#define CAN_MODATA97HL         (*((unsigned int volatile huge *) 0x201C34))

// Message Object 97 Data Register Low High
#define CAN_MODATA97LH         (*((unsigned int volatile huge *) 0x201C32))

// Message Object 97 Data Register Low Low
#define CAN_MODATA97LL         (*((unsigned int volatile huge *) 0x201C30))

// Message Object 98 Data Register High High
#define CAN_MODATA98HH         (*((unsigned int volatile huge *) 0x201C56))

// Message Object 98 Data Register High Low
#define CAN_MODATA98HL         (*((unsigned int volatile huge *) 0x201C54))

// Message Object 98 Data Register Low High
#define CAN_MODATA98LH         (*((unsigned int volatile huge *) 0x201C52))

// Message Object 98 Data Register Low Low
#define CAN_MODATA98LL         (*((unsigned int volatile huge *) 0x201C50))

// Message Object 99 Data Register High High
#define CAN_MODATA99HH         (*((unsigned int volatile huge *) 0x201C76))

// Message Object 99 Data Register High Low
#define CAN_MODATA99HL         (*((unsigned int volatile huge *) 0x201C74))

// Message Object 99 Data Register Low High
#define CAN_MODATA99LH         (*((unsigned int volatile huge *) 0x201C72))

// Message Object 99 Data Register Low Low
#define CAN_MODATA99LL         (*((unsigned int volatile huge *) 0x201C70))

// Message Object 9 Data Register High High
#define CAN_MODATA9HH          (*((unsigned int volatile huge *) 0x201136))

// Message Object 9 Data Register High Low
#define CAN_MODATA9HL          (*((unsigned int volatile huge *) 0x201134))

// Message Object 9 Data Register Low High
#define CAN_MODATA9LH          (*((unsigned int volatile huge *) 0x201132))

// Message Object 9 Data Register Low Low
#define CAN_MODATA9LL          (*((unsigned int volatile huge *) 0x201130))

// Message Object 0 Function Control Register High
#define CAN_MOFCR0H            (*((unsigned int volatile huge *) 0x201002))

// Message Object 0 Function Control Register Low
#define CAN_MOFCR0L            (*((unsigned int volatile huge *) 0x201000))

// Message Object 100 Function Control Register High
#define CAN_MOFCR100H          (*((unsigned int volatile huge *) 0x201C82))

// Message Object 100 Function Control Register Low
#define CAN_MOFCR100L          (*((unsigned int volatile huge *) 0x201C80))

// Message Object 101 Function Control Register High
#define CAN_MOFCR101H          (*((unsigned int volatile huge *) 0x201CA2))

// Message Object 101 Function Control Register Low
#define CAN_MOFCR101L          (*((unsigned int volatile huge *) 0x201CA0))

// Message Object 102 Function Control Register High
#define CAN_MOFCR102H          (*((unsigned int volatile huge *) 0x201CC2))

// Message Object 102 Function Control Register Low
#define CAN_MOFCR102L          (*((unsigned int volatile huge *) 0x201CC0))

// Message Object 103 Function Control Register High
#define CAN_MOFCR103H          (*((unsigned int volatile huge *) 0x201CE2))

// Message Object 103 Function Control Register Low
#define CAN_MOFCR103L          (*((unsigned int volatile huge *) 0x201CE0))

// Message Object 104 Function Control Register High
#define CAN_MOFCR104H          (*((unsigned int volatile huge *) 0x201D02))

// Message Object 104 Function Control Register Low
#define CAN_MOFCR104L          (*((unsigned int volatile huge *) 0x201D00))

// Message Object 105 Function Control Register High
#define CAN_MOFCR105H          (*((unsigned int volatile huge *) 0x201D22))

// Message Object 105 Function Control Register Low
#define CAN_MOFCR105L          (*((unsigned int volatile huge *) 0x201D20))

// Message Object 106 Function Control Register High
#define CAN_MOFCR106H          (*((unsigned int volatile huge *) 0x201D42))

// Message Object 106 Function Control Register Low
#define CAN_MOFCR106L          (*((unsigned int volatile huge *) 0x201D40))

// Message Object 107 Function Control Register High
#define CAN_MOFCR107H          (*((unsigned int volatile huge *) 0x201D62))

// Message Object 107 Function Control Register Low
#define CAN_MOFCR107L          (*((unsigned int volatile huge *) 0x201D60))

// Message Object 108 Function Control Register High
#define CAN_MOFCR108H          (*((unsigned int volatile huge *) 0x201D82))

// Message Object 108 Function Control Register Low
#define CAN_MOFCR108L          (*((unsigned int volatile huge *) 0x201D80))

// Message Object 109 Function Control Register High
#define CAN_MOFCR109H          (*((unsigned int volatile huge *) 0x201DA2))

// Message Object 109 Function Control Register Low
#define CAN_MOFCR109L          (*((unsigned int volatile huge *) 0x201DA0))

// Message Object 10 Function Control Register High
#define CAN_MOFCR10H           (*((unsigned int volatile huge *) 0x201142))

// Message Object 10 Function Control Register Low
#define CAN_MOFCR10L           (*((unsigned int volatile huge *) 0x201140))

// Message Object 110 Function Control Register High
#define CAN_MOFCR110H          (*((unsigned int volatile huge *) 0x201DC2))

// Message Object 110 Function Control Register Low
#define CAN_MOFCR110L          (*((unsigned int volatile huge *) 0x201DC0))

// Message Object 111 Function Control Register High
#define CAN_MOFCR111H          (*((unsigned int volatile huge *) 0x201DE2))

// Message Object 111 Function Control Register Low
#define CAN_MOFCR111L          (*((unsigned int volatile huge *) 0x201DE0))

// Message Object 112 Function Control Register High
#define CAN_MOFCR112H          (*((unsigned int volatile huge *) 0x201E02))

// Message Object 112 Function Control Register Low
#define CAN_MOFCR112L          (*((unsigned int volatile huge *) 0x201E00))

// Message Object 113 Function Control Register High
#define CAN_MOFCR113H          (*((unsigned int volatile huge *) 0x201E22))

// Message Object 113 Function Control Register Low
#define CAN_MOFCR113L          (*((unsigned int volatile huge *) 0x201E20))

// Message Object 114 Function Control Register High
#define CAN_MOFCR114H          (*((unsigned int volatile huge *) 0x201E42))

// Message Object 114 Function Control Register Low
#define CAN_MOFCR114L          (*((unsigned int volatile huge *) 0x201E40))

// Message Object 115 Function Control Register High
#define CAN_MOFCR115H          (*((unsigned int volatile huge *) 0x201E62))

// Message Object 115 Function Control Register Low
#define CAN_MOFCR115L          (*((unsigned int volatile huge *) 0x201E60))

// Message Object 116 Function Control Register High
#define CAN_MOFCR116H          (*((unsigned int volatile huge *) 0x201E82))

// Message Object 116 Function Control Register Low
#define CAN_MOFCR116L          (*((unsigned int volatile huge *) 0x201E80))

// Message Object 117 Function Control Register High
#define CAN_MOFCR117H          (*((unsigned int volatile huge *) 0x201EA2))

// Message Object 117 Function Control Register Low
#define CAN_MOFCR117L          (*((unsigned int volatile huge *) 0x201EA0))

// Message Object 118 Function Control Register High
#define CAN_MOFCR118H          (*((unsigned int volatile huge *) 0x201EC2))

// Message Object 118 Function Control Register Low
#define CAN_MOFCR118L          (*((unsigned int volatile huge *) 0x201EC0))

// Message Object 119 Function Control Register High
#define CAN_MOFCR119H          (*((unsigned int volatile huge *) 0x201EE2))

// Message Object 119 Function Control Register Low
#define CAN_MOFCR119L          (*((unsigned int volatile huge *) 0x201EE0))

// Message Object 11 Function Control Register High
#define CAN_MOFCR11H           (*((unsigned int volatile huge *) 0x201162))

// Message Object 11 Function Control Register Low
#define CAN_MOFCR11L           (*((unsigned int volatile huge *) 0x201160))

// Message Object 120 Function Control Register High
#define CAN_MOFCR120H          (*((unsigned int volatile huge *) 0x201F02))

// Message Object 120 Function Control Register Low
#define CAN_MOFCR120L          (*((unsigned int volatile huge *) 0x201F00))

// Message Object 121 Function Control Register High
#define CAN_MOFCR121H          (*((unsigned int volatile huge *) 0x201F22))

// Message Object 121 Function Control Register Low
#define CAN_MOFCR121L          (*((unsigned int volatile huge *) 0x201F20))

// Message Object 122 Function Control Register High
#define CAN_MOFCR122H          (*((unsigned int volatile huge *) 0x201F42))

// Message Object 122 Function Control Register Low
#define CAN_MOFCR122L          (*((unsigned int volatile huge *) 0x201F40))

// Message Object 123 Function Control Register High
#define CAN_MOFCR123H          (*((unsigned int volatile huge *) 0x201F62))

// Message Object 123 Function Control Register Low
#define CAN_MOFCR123L          (*((unsigned int volatile huge *) 0x201F60))

// Message Object 124 Function Control Register High
#define CAN_MOFCR124H          (*((unsigned int volatile huge *) 0x201F82))

// Message Object 124 Function Control Register Low
#define CAN_MOFCR124L          (*((unsigned int volatile huge *) 0x201F80))

// Message Object 125 Function Control Register High
#define CAN_MOFCR125H          (*((unsigned int volatile huge *) 0x201FA2))

// Message Object 125 Function Control Register Low
#define CAN_MOFCR125L          (*((unsigned int volatile huge *) 0x201FA0))

// Message Object 126 Function Control Register High
#define CAN_MOFCR126H          (*((unsigned int volatile huge *) 0x201FC2))

// Message Object 126 Function Control Register Low
#define CAN_MOFCR126L          (*((unsigned int volatile huge *) 0x201FC0))

// Message Object 127 Function Control Register High
#define CAN_MOFCR127H          (*((unsigned int volatile huge *) 0x201FE2))

// Message Object 127 Function Control Register Low
#define CAN_MOFCR127L          (*((unsigned int volatile huge *) 0x201FE0))

// Message Object 12 Function Control Register High
#define CAN_MOFCR12H           (*((unsigned int volatile huge *) 0x201182))

// Message Object 12 Function Control Register Low
#define CAN_MOFCR12L           (*((unsigned int volatile huge *) 0x201180))

// Message Object 13 Function Control Register High
#define CAN_MOFCR13H           (*((unsigned int volatile huge *) 0x2011A2))

// Message Object 13 Function Control Register Low
#define CAN_MOFCR13L           (*((unsigned int volatile huge *) 0x2011A0))

// Message Object 14 Function Control Register High
#define CAN_MOFCR14H           (*((unsigned int volatile huge *) 0x2011C2))

// Message Object 14 Function Control Register Low
#define CAN_MOFCR14L           (*((unsigned int volatile huge *) 0x2011C0))

// Message Object 15 Function Control Register High
#define CAN_MOFCR15H           (*((unsigned int volatile huge *) 0x2011E2))

// Message Object 15 Function Control Register Low
#define CAN_MOFCR15L           (*((unsigned int volatile huge *) 0x2011E0))

// Message Object 16 Function Control Register High
#define CAN_MOFCR16H           (*((unsigned int volatile huge *) 0x201202))

// Message Object 16 Function Control Register Low
#define CAN_MOFCR16L           (*((unsigned int volatile huge *) 0x201200))

// Message Object 17 Function Control Register High
#define CAN_MOFCR17H           (*((unsigned int volatile huge *) 0x201222))

// Message Object 17 Function Control Register Low
#define CAN_MOFCR17L           (*((unsigned int volatile huge *) 0x201220))

// Message Object 18 Function Control Register High
#define CAN_MOFCR18H           (*((unsigned int volatile huge *) 0x201242))

// Message Object 18 Function Control Register Low
#define CAN_MOFCR18L           (*((unsigned int volatile huge *) 0x201240))

// Message Object 19 Function Control Register High
#define CAN_MOFCR19H           (*((unsigned int volatile huge *) 0x201262))

// Message Object 19 Function Control Register Low
#define CAN_MOFCR19L           (*((unsigned int volatile huge *) 0x201260))

// Message Object 1 Function Control Register High
#define CAN_MOFCR1H            (*((unsigned int volatile huge *) 0x201022))

// Message Object 1 Function Control Register Low
#define CAN_MOFCR1L            (*((unsigned int volatile huge *) 0x201020))

// Message Object 20 Function Control Register High
#define CAN_MOFCR20H           (*((unsigned int volatile huge *) 0x201282))

// Message Object 20 Function Control Register Low
#define CAN_MOFCR20L           (*((unsigned int volatile huge *) 0x201280))

// Message Object 21 Function Control Register High
#define CAN_MOFCR21H           (*((unsigned int volatile huge *) 0x2012A2))

// Message Object 21 Function Control Register Low
#define CAN_MOFCR21L           (*((unsigned int volatile huge *) 0x2012A0))

// Message Object 22 Function Control Register High
#define CAN_MOFCR22H           (*((unsigned int volatile huge *) 0x2012C2))

// Message Object 22 Function Control Register Low
#define CAN_MOFCR22L           (*((unsigned int volatile huge *) 0x2012C0))

// Message Object 23 Function Control Register High
#define CAN_MOFCR23H           (*((unsigned int volatile huge *) 0x2012E2))

// Message Object 23 Function Control Register Low
#define CAN_MOFCR23L           (*((unsigned int volatile huge *) 0x2012E0))

// Message Object 24 Function Control Register High
#define CAN_MOFCR24H           (*((unsigned int volatile huge *) 0x201302))

// Message Object 24 Function Control Register Low
#define CAN_MOFCR24L           (*((unsigned int volatile huge *) 0x201300))

// Message Object 25 Function Control Register High
#define CAN_MOFCR25H           (*((unsigned int volatile huge *) 0x201322))

// Message Object 25 Function Control Register Low
#define CAN_MOFCR25L           (*((unsigned int volatile huge *) 0x201320))

// Message Object 26 Function Control Register High
#define CAN_MOFCR26H           (*((unsigned int volatile huge *) 0x201342))

// Message Object 26 Function Control Register Low
#define CAN_MOFCR26L           (*((unsigned int volatile huge *) 0x201340))

// Message Object 27 Function Control Register High
#define CAN_MOFCR27H           (*((unsigned int volatile huge *) 0x201362))

// Message Object 27 Function Control Register Low
#define CAN_MOFCR27L           (*((unsigned int volatile huge *) 0x201360))

// Message Object 28 Function Control Register High
#define CAN_MOFCR28H           (*((unsigned int volatile huge *) 0x201382))

// Message Object 28 Function Control Register Low
#define CAN_MOFCR28L           (*((unsigned int volatile huge *) 0x201380))

// Message Object 29 Function Control Register High
#define CAN_MOFCR29H           (*((unsigned int volatile huge *) 0x2013A2))

// Message Object 29 Function Control Register Low
#define CAN_MOFCR29L           (*((unsigned int volatile huge *) 0x2013A0))

// Message Object 2 Function Control Register High
#define CAN_MOFCR2H            (*((unsigned int volatile huge *) 0x201042))

// Message Object 2 Function Control Register Low
#define CAN_MOFCR2L            (*((unsigned int volatile huge *) 0x201040))

// Message Object 30 Function Control Register High
#define CAN_MOFCR30H           (*((unsigned int volatile huge *) 0x2013C2))

// Message Object 30 Function Control Register Low
#define CAN_MOFCR30L           (*((unsigned int volatile huge *) 0x2013C0))

// Message Object 31 Function Control Register High
#define CAN_MOFCR31H           (*((unsigned int volatile huge *) 0x2013E2))

// Message Object 31 Function Control Register Low
#define CAN_MOFCR31L           (*((unsigned int volatile huge *) 0x2013E0))

// Message Object 32 Function Control Register High
#define CAN_MOFCR32H           (*((unsigned int volatile huge *) 0x201402))

// Message Object 32 Function Control Register Low
#define CAN_MOFCR32L           (*((unsigned int volatile huge *) 0x201400))

// Message Object 33 Function Control Register High
#define CAN_MOFCR33H           (*((unsigned int volatile huge *) 0x201422))

// Message Object 33 Function Control Register Low
#define CAN_MOFCR33L           (*((unsigned int volatile huge *) 0x201420))

// Message Object 34 Function Control Register High
#define CAN_MOFCR34H           (*((unsigned int volatile huge *) 0x201442))

// Message Object 34 Function Control Register Low
#define CAN_MOFCR34L           (*((unsigned int volatile huge *) 0x201440))

// Message Object 35 Function Control Register High
#define CAN_MOFCR35H           (*((unsigned int volatile huge *) 0x201462))

// Message Object 35 Function Control Register Low
#define CAN_MOFCR35L           (*((unsigned int volatile huge *) 0x201460))

// Message Object 36 Function Control Register High
#define CAN_MOFCR36H           (*((unsigned int volatile huge *) 0x201482))

// Message Object 36 Function Control Register Low
#define CAN_MOFCR36L           (*((unsigned int volatile huge *) 0x201480))

// Message Object 37 Function Control Register High
#define CAN_MOFCR37H           (*((unsigned int volatile huge *) 0x2014A2))

// Message Object 37 Function Control Register Low
#define CAN_MOFCR37L           (*((unsigned int volatile huge *) 0x2014A0))

// Message Object 38 Function Control Register High
#define CAN_MOFCR38H           (*((unsigned int volatile huge *) 0x2014C2))

// Message Object 38 Function Control Register Low
#define CAN_MOFCR38L           (*((unsigned int volatile huge *) 0x2014C0))

// Message Object 39 Function Control Register High
#define CAN_MOFCR39H           (*((unsigned int volatile huge *) 0x2014E2))

// Message Object 39 Function Control Register Low
#define CAN_MOFCR39L           (*((unsigned int volatile huge *) 0x2014E0))

// Message Object 3 Function Control Register High
#define CAN_MOFCR3H            (*((unsigned int volatile huge *) 0x201062))

// Message Object 3 Function Control Register Low
#define CAN_MOFCR3L            (*((unsigned int volatile huge *) 0x201060))

// Message Object 40 Function Control Register High
#define CAN_MOFCR40H           (*((unsigned int volatile huge *) 0x201502))

// Message Object 40 Function Control Register Low
#define CAN_MOFCR40L           (*((unsigned int volatile huge *) 0x201500))

// Message Object 41 Function Control Register High
#define CAN_MOFCR41H           (*((unsigned int volatile huge *) 0x201522))

// Message Object 41 Function Control Register Low
#define CAN_MOFCR41L           (*((unsigned int volatile huge *) 0x201520))

// Message Object 42 Function Control Register High
#define CAN_MOFCR42H           (*((unsigned int volatile huge *) 0x201542))

// Message Object 42 Function Control Register Low
#define CAN_MOFCR42L           (*((unsigned int volatile huge *) 0x201540))

// Message Object 43 Function Control Register High
#define CAN_MOFCR43H           (*((unsigned int volatile huge *) 0x201562))

// Message Object 43 Function Control Register Low
#define CAN_MOFCR43L           (*((unsigned int volatile huge *) 0x201560))

// Message Object 44 Function Control Register High
#define CAN_MOFCR44H           (*((unsigned int volatile huge *) 0x201582))

// Message Object 44 Function Control Register Low
#define CAN_MOFCR44L           (*((unsigned int volatile huge *) 0x201580))

// Message Object 45 Function Control Register High
#define CAN_MOFCR45H           (*((unsigned int volatile huge *) 0x2015A2))

// Message Object 45 Function Control Register Low
#define CAN_MOFCR45L           (*((unsigned int volatile huge *) 0x2015A0))

// Message Object 46 Function Control Register High
#define CAN_MOFCR46H           (*((unsigned int volatile huge *) 0x2015C2))

// Message Object 46 Function Control Register Low
#define CAN_MOFCR46L           (*((unsigned int volatile huge *) 0x2015C0))

// Message Object 47 Function Control Register High
#define CAN_MOFCR47H           (*((unsigned int volatile huge *) 0x2015E2))

// Message Object 47 Function Control Register Low
#define CAN_MOFCR47L           (*((unsigned int volatile huge *) 0x2015E0))

// Message Object 48 Function Control Register High
#define CAN_MOFCR48H           (*((unsigned int volatile huge *) 0x201602))

// Message Object 48 Function Control Register Low
#define CAN_MOFCR48L           (*((unsigned int volatile huge *) 0x201600))

// Message Object 49 Function Control Register High
#define CAN_MOFCR49H           (*((unsigned int volatile huge *) 0x201622))

// Message Object 49 Function Control Register Low
#define CAN_MOFCR49L           (*((unsigned int volatile huge *) 0x201620))

// Message Object 4 Function Control Register High
#define CAN_MOFCR4H            (*((unsigned int volatile huge *) 0x201082))

// Message Object 4 Function Control Register Low
#define CAN_MOFCR4L            (*((unsigned int volatile huge *) 0x201080))

// Message Object 50 Function Control Register High
#define CAN_MOFCR50H           (*((unsigned int volatile huge *) 0x201642))

// Message Object 50 Function Control Register Low
#define CAN_MOFCR50L           (*((unsigned int volatile huge *) 0x201640))

// Message Object 51 Function Control Register High
#define CAN_MOFCR51H           (*((unsigned int volatile huge *) 0x201662))

// Message Object 51 Function Control Register Low
#define CAN_MOFCR51L           (*((unsigned int volatile huge *) 0x201660))

// Message Object 52 Function Control Register High
#define CAN_MOFCR52H           (*((unsigned int volatile huge *) 0x201682))

// Message Object 52 Function Control Register Low
#define CAN_MOFCR52L           (*((unsigned int volatile huge *) 0x201680))

// Message Object 53 Function Control Register High
#define CAN_MOFCR53H           (*((unsigned int volatile huge *) 0x2016A2))

// Message Object 53 Function Control Register Low
#define CAN_MOFCR53L           (*((unsigned int volatile huge *) 0x2016A0))

// Message Object 54 Function Control Register High
#define CAN_MOFCR54H           (*((unsigned int volatile huge *) 0x2016C2))

// Message Object 54 Function Control Register Low
#define CAN_MOFCR54L           (*((unsigned int volatile huge *) 0x2016C0))

// Message Object 55 Function Control Register High
#define CAN_MOFCR55H           (*((unsigned int volatile huge *) 0x2016E2))

// Message Object 55 Function Control Register Low
#define CAN_MOFCR55L           (*((unsigned int volatile huge *) 0x2016E0))

// Message Object 56 Function Control Register High
#define CAN_MOFCR56H           (*((unsigned int volatile huge *) 0x201702))

// Message Object 56 Function Control Register Low
#define CAN_MOFCR56L           (*((unsigned int volatile huge *) 0x201700))

// Message Object 57 Function Control Register High
#define CAN_MOFCR57H           (*((unsigned int volatile huge *) 0x201722))

// Message Object 57 Function Control Register Low
#define CAN_MOFCR57L           (*((unsigned int volatile huge *) 0x201720))

// Message Object 58 Function Control Register High
#define CAN_MOFCR58H           (*((unsigned int volatile huge *) 0x201742))

// Message Object 58 Function Control Register Low
#define CAN_MOFCR58L           (*((unsigned int volatile huge *) 0x201740))

// Message Object 59 Function Control Register High
#define CAN_MOFCR59H           (*((unsigned int volatile huge *) 0x201762))

// Message Object 59 Function Control Register Low
#define CAN_MOFCR59L           (*((unsigned int volatile huge *) 0x201760))

// Message Object 5 Function Control Register High
#define CAN_MOFCR5H            (*((unsigned int volatile huge *) 0x2010A2))

// Message Object 5 Function Control Register Low
#define CAN_MOFCR5L            (*((unsigned int volatile huge *) 0x2010A0))

// Message Object 60 Function Control Register High
#define CAN_MOFCR60H           (*((unsigned int volatile huge *) 0x201782))

// Message Object 60 Function Control Register Low
#define CAN_MOFCR60L           (*((unsigned int volatile huge *) 0x201780))

// Message Object 61 Function Control Register High
#define CAN_MOFCR61H           (*((unsigned int volatile huge *) 0x2017A2))

// Message Object 61 Function Control Register Low
#define CAN_MOFCR61L           (*((unsigned int volatile huge *) 0x2017A0))

// Message Object 62 Function Control Register High
#define CAN_MOFCR62H           (*((unsigned int volatile huge *) 0x2017C2))

// Message Object 62 Function Control Register Low
#define CAN_MOFCR62L           (*((unsigned int volatile huge *) 0x2017C0))

// Message Object 63 Function Control Register High
#define CAN_MOFCR63H           (*((unsigned int volatile huge *) 0x2017E2))

// Message Object 63 Function Control Register Low
#define CAN_MOFCR63L           (*((unsigned int volatile huge *) 0x2017E0))

// Message Object 64 Function Control Register High
#define CAN_MOFCR64H           (*((unsigned int volatile huge *) 0x201802))

// Message Object 64 Function Control Register Low
#define CAN_MOFCR64L           (*((unsigned int volatile huge *) 0x201800))

// Message Object 65 Function Control Register High
#define CAN_MOFCR65H           (*((unsigned int volatile huge *) 0x201822))

// Message Object 65 Function Control Register Low
#define CAN_MOFCR65L           (*((unsigned int volatile huge *) 0x201820))

// Message Object 66 Function Control Register High
#define CAN_MOFCR66H           (*((unsigned int volatile huge *) 0x201842))

// Message Object 66 Function Control Register Low
#define CAN_MOFCR66L           (*((unsigned int volatile huge *) 0x201840))

// Message Object 67 Function Control Register High
#define CAN_MOFCR67H           (*((unsigned int volatile huge *) 0x201862))

// Message Object 67 Function Control Register Low
#define CAN_MOFCR67L           (*((unsigned int volatile huge *) 0x201860))

// Message Object 68 Function Control Register High
#define CAN_MOFCR68H           (*((unsigned int volatile huge *) 0x201882))

// Message Object 68 Function Control Register Low
#define CAN_MOFCR68L           (*((unsigned int volatile huge *) 0x201880))

// Message Object 69 Function Control Register High
#define CAN_MOFCR69H           (*((unsigned int volatile huge *) 0x2018A2))

// Message Object 69 Function Control Register Low
#define CAN_MOFCR69L           (*((unsigned int volatile huge *) 0x2018A0))

// Message Object 6 Function Control Register High
#define CAN_MOFCR6H            (*((unsigned int volatile huge *) 0x2010C2))

// Message Object 6 Function Control Register Low
#define CAN_MOFCR6L            (*((unsigned int volatile huge *) 0x2010C0))

// Message Object 70 Function Control Register High
#define CAN_MOFCR70H           (*((unsigned int volatile huge *) 0x2018C2))

// Message Object 70 Function Control Register Low
#define CAN_MOFCR70L           (*((unsigned int volatile huge *) 0x2018C0))

// Message Object 71 Function Control Register High
#define CAN_MOFCR71H           (*((unsigned int volatile huge *) 0x2018E2))

// Message Object 71 Function Control Register Low
#define CAN_MOFCR71L           (*((unsigned int volatile huge *) 0x2018E0))

// Message Object 72 Function Control Register High
#define CAN_MOFCR72H           (*((unsigned int volatile huge *) 0x201902))

// Message Object 72 Function Control Register Low
#define CAN_MOFCR72L           (*((unsigned int volatile huge *) 0x201900))

// Message Object 73 Function Control Register High
#define CAN_MOFCR73H           (*((unsigned int volatile huge *) 0x201922))

// Message Object 73 Function Control Register Low
#define CAN_MOFCR73L           (*((unsigned int volatile huge *) 0x201920))

// Message Object 74 Function Control Register High
#define CAN_MOFCR74H           (*((unsigned int volatile huge *) 0x201942))

// Message Object 74 Function Control Register Low
#define CAN_MOFCR74L           (*((unsigned int volatile huge *) 0x201940))

// Message Object 75 Function Control Register High
#define CAN_MOFCR75H           (*((unsigned int volatile huge *) 0x201962))

// Message Object 75 Function Control Register Low
#define CAN_MOFCR75L           (*((unsigned int volatile huge *) 0x201960))

// Message Object 76 Function Control Register High
#define CAN_MOFCR76H           (*((unsigned int volatile huge *) 0x201982))

// Message Object 76 Function Control Register Low
#define CAN_MOFCR76L           (*((unsigned int volatile huge *) 0x201980))

// Message Object 77 Function Control Register High
#define CAN_MOFCR77H           (*((unsigned int volatile huge *) 0x2019A2))

// Message Object 77 Function Control Register Low
#define CAN_MOFCR77L           (*((unsigned int volatile huge *) 0x2019A0))

// Message Object 78 Function Control Register High
#define CAN_MOFCR78H           (*((unsigned int volatile huge *) 0x2019C2))

// Message Object 78 Function Control Register Low
#define CAN_MOFCR78L           (*((unsigned int volatile huge *) 0x2019C0))

// Message Object 79 Function Control Register High
#define CAN_MOFCR79H           (*((unsigned int volatile huge *) 0x2019E2))

// Message Object 79 Function Control Register Low
#define CAN_MOFCR79L           (*((unsigned int volatile huge *) 0x2019E0))

// Message Object 7 Function Control Register High
#define CAN_MOFCR7H            (*((unsigned int volatile huge *) 0x2010E2))

// Message Object 7 Function Control Register Low
#define CAN_MOFCR7L            (*((unsigned int volatile huge *) 0x2010E0))

// Message Object 80 Function Control Register High
#define CAN_MOFCR80H           (*((unsigned int volatile huge *) 0x201A02))

// Message Object 80 Function Control Register Low
#define CAN_MOFCR80L           (*((unsigned int volatile huge *) 0x201A00))

// Message Object 81 Function Control Register High
#define CAN_MOFCR81H           (*((unsigned int volatile huge *) 0x201A22))

// Message Object 81 Function Control Register Low
#define CAN_MOFCR81L           (*((unsigned int volatile huge *) 0x201A20))

// Message Object 82 Function Control Register High
#define CAN_MOFCR82H           (*((unsigned int volatile huge *) 0x201A42))

// Message Object 82 Function Control Register Low
#define CAN_MOFCR82L           (*((unsigned int volatile huge *) 0x201A40))

// Message Object 83 Function Control Register High
#define CAN_MOFCR83H           (*((unsigned int volatile huge *) 0x201A62))

// Message Object 83 Function Control Register Low
#define CAN_MOFCR83L           (*((unsigned int volatile huge *) 0x201A60))

// Message Object 84 Function Control Register High
#define CAN_MOFCR84H           (*((unsigned int volatile huge *) 0x201A82))

// Message Object 84 Function Control Register Low
#define CAN_MOFCR84L           (*((unsigned int volatile huge *) 0x201A80))

// Message Object 85 Function Control Register High
#define CAN_MOFCR85H           (*((unsigned int volatile huge *) 0x201AA2))

// Message Object 85 Function Control Register Low
#define CAN_MOFCR85L           (*((unsigned int volatile huge *) 0x201AA0))

// Message Object 86 Function Control Register High
#define CAN_MOFCR86H           (*((unsigned int volatile huge *) 0x201AC2))

// Message Object 86 Function Control Register Low
#define CAN_MOFCR86L           (*((unsigned int volatile huge *) 0x201AC0))

// Message Object 87 Function Control Register High
#define CAN_MOFCR87H           (*((unsigned int volatile huge *) 0x201AE2))

// Message Object 87 Function Control Register Low
#define CAN_MOFCR87L           (*((unsigned int volatile huge *) 0x201AE0))

// Message Object 88 Function Control Register High
#define CAN_MOFCR88H           (*((unsigned int volatile huge *) 0x201B02))

// Message Object 88 Function Control Register Low
#define CAN_MOFCR88L           (*((unsigned int volatile huge *) 0x201B00))

// Message Object 89 Function Control Register High
#define CAN_MOFCR89H           (*((unsigned int volatile huge *) 0x201B22))

// Message Object 89 Function Control Register Low
#define CAN_MOFCR89L           (*((unsigned int volatile huge *) 0x201B20))

// Message Object 8 Function Control Register High
#define CAN_MOFCR8H            (*((unsigned int volatile huge *) 0x201102))

// Message Object 8 Function Control Register Low
#define CAN_MOFCR8L            (*((unsigned int volatile huge *) 0x201100))

// Message Object 90 Function Control Register High
#define CAN_MOFCR90H           (*((unsigned int volatile huge *) 0x201B42))

// Message Object 90 Function Control Register Low
#define CAN_MOFCR90L           (*((unsigned int volatile huge *) 0x201B40))

// Message Object 91 Function Control Register High
#define CAN_MOFCR91H           (*((unsigned int volatile huge *) 0x201B62))

// Message Object 91 Function Control Register Low
#define CAN_MOFCR91L           (*((unsigned int volatile huge *) 0x201B60))

// Message Object 92 Function Control Register High
#define CAN_MOFCR92H           (*((unsigned int volatile huge *) 0x201B82))

// Message Object 92 Function Control Register Low
#define CAN_MOFCR92L           (*((unsigned int volatile huge *) 0x201B80))

// Message Object 93 Function Control Register High
#define CAN_MOFCR93H           (*((unsigned int volatile huge *) 0x201BA2))

// Message Object 93 Function Control Register Low
#define CAN_MOFCR93L           (*((unsigned int volatile huge *) 0x201BA0))

// Message Object 94 Function Control Register High
#define CAN_MOFCR94H           (*((unsigned int volatile huge *) 0x201BC2))

// Message Object 94 Function Control Register Low
#define CAN_MOFCR94L           (*((unsigned int volatile huge *) 0x201BC0))

// Message Object 95 Function Control Register High
#define CAN_MOFCR95H           (*((unsigned int volatile huge *) 0x201BE2))

// Message Object 95 Function Control Register Low
#define CAN_MOFCR95L           (*((unsigned int volatile huge *) 0x201BE0))

// Message Object 96 Function Control Register High
#define CAN_MOFCR96H           (*((unsigned int volatile huge *) 0x201C02))

// Message Object 96 Function Control Register Low
#define CAN_MOFCR96L           (*((unsigned int volatile huge *) 0x201C00))

// Message Object 97 Function Control Register High
#define CAN_MOFCR97H           (*((unsigned int volatile huge *) 0x201C22))

// Message Object 97 Function Control Register Low
#define CAN_MOFCR97L           (*((unsigned int volatile huge *) 0x201C20))

// Message Object 98 Function Control Register High
#define CAN_MOFCR98H           (*((unsigned int volatile huge *) 0x201C42))

// Message Object 98 Function Control Register Low
#define CAN_MOFCR98L           (*((unsigned int volatile huge *) 0x201C40))

// Message Object 99 Function Control Register High
#define CAN_MOFCR99H           (*((unsigned int volatile huge *) 0x201C62))

// Message Object 99 Function Control Register Low
#define CAN_MOFCR99L           (*((unsigned int volatile huge *) 0x201C60))

// Message Object 9 Function Control Register High
#define CAN_MOFCR9H            (*((unsigned int volatile huge *) 0x201122))

// Message Object 9 Function Control Register Low
#define CAN_MOFCR9L            (*((unsigned int volatile huge *) 0x201120))

// Message Object 0 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR0H           (*((unsigned int volatile huge *) 0x201006))

// Message Object 0 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR0L           (*((unsigned int volatile huge *) 0x201004))

// Message Object 100 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR100H         (*((unsigned int volatile huge *) 0x201C86))

// Message Object 100 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR100L         (*((unsigned int volatile huge *) 0x201C84))

// Message Object 101 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR101H         (*((unsigned int volatile huge *) 0x201CA6))

// Message Object 101 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR101L         (*((unsigned int volatile huge *) 0x201CA4))

// Message Object 102 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR102H         (*((unsigned int volatile huge *) 0x201CC6))

// Message Object 102 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR102L         (*((unsigned int volatile huge *) 0x201CC4))

// Message Object 103 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR103H         (*((unsigned int volatile huge *) 0x201CE6))

// Message Object 103 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR103L         (*((unsigned int volatile huge *) 0x201CE4))

// Message Object 104 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR104H         (*((unsigned int volatile huge *) 0x201D06))

// Message Object 104 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR104L         (*((unsigned int volatile huge *) 0x201D04))

// Message Object 105 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR105H         (*((unsigned int volatile huge *) 0x201D26))

// Message Object 105 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR105L         (*((unsigned int volatile huge *) 0x201D24))

// Message Object 106 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR106H         (*((unsigned int volatile huge *) 0x201D46))

// Message Object 106 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR106L         (*((unsigned int volatile huge *) 0x201D44))

// Message Object 107 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR107H         (*((unsigned int volatile huge *) 0x201D66))

// Message Object 107 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR107L         (*((unsigned int volatile huge *) 0x201D64))

// Message Object 108 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR108H         (*((unsigned int volatile huge *) 0x201D86))

// Message Object 108 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR108L         (*((unsigned int volatile huge *) 0x201D84))

// Message Object 109 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR109H         (*((unsigned int volatile huge *) 0x201DA6))

// Message Object 109 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR109L         (*((unsigned int volatile huge *) 0x201DA4))

// Message Object 10 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR10H          (*((unsigned int volatile huge *) 0x201146))

// Message Object 10 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR10L          (*((unsigned int volatile huge *) 0x201144))

// Message Object 110 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR110H         (*((unsigned int volatile huge *) 0x201DC6))

// Message Object 110 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR110L         (*((unsigned int volatile huge *) 0x201DC4))

// Message Object 111 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR111H         (*((unsigned int volatile huge *) 0x201DE6))

// Message Object 111 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR111L         (*((unsigned int volatile huge *) 0x201DE4))

// Message Object 112 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR112H         (*((unsigned int volatile huge *) 0x201E06))

// Message Object 112 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR112L         (*((unsigned int volatile huge *) 0x201E04))

// Message Object 113 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR113H         (*((unsigned int volatile huge *) 0x201E26))

// Message Object 113 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR113L         (*((unsigned int volatile huge *) 0x201E24))

// Message Object 114 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR114H         (*((unsigned int volatile huge *) 0x201E46))

// Message Object 114 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR114L         (*((unsigned int volatile huge *) 0x201E44))

// Message Object 115 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR115H         (*((unsigned int volatile huge *) 0x201E66))

// Message Object 115 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR115L         (*((unsigned int volatile huge *) 0x201E64))

// Message Object 116 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR116H         (*((unsigned int volatile huge *) 0x201E86))

// Message Object 116 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR116L         (*((unsigned int volatile huge *) 0x201E84))

// Message Object 117 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR117H         (*((unsigned int volatile huge *) 0x201EA6))

// Message Object 117 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR117L         (*((unsigned int volatile huge *) 0x201EA4))

// Message Object 118 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR118H         (*((unsigned int volatile huge *) 0x201EC6))

// Message Object 118 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR118L         (*((unsigned int volatile huge *) 0x201EC4))

// Message Object 119 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR119H         (*((unsigned int volatile huge *) 0x201EE6))

// Message Object 119 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR119L         (*((unsigned int volatile huge *) 0x201EE4))

// Message Object 11 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR11H          (*((unsigned int volatile huge *) 0x201166))

// Message Object 11 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR11L          (*((unsigned int volatile huge *) 0x201164))

// Message Object 120 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR120H         (*((unsigned int volatile huge *) 0x201F06))

// Message Object 120 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR120L         (*((unsigned int volatile huge *) 0x201F04))

// Message Object 121 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR121H         (*((unsigned int volatile huge *) 0x201F26))

// Message Object 121 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR121L         (*((unsigned int volatile huge *) 0x201F24))

// Message Object 122 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR122H         (*((unsigned int volatile huge *) 0x201F46))

// Message Object 122 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR122L         (*((unsigned int volatile huge *) 0x201F44))

// Message Object 123 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR123H         (*((unsigned int volatile huge *) 0x201F66))

// Message Object 123 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR123L         (*((unsigned int volatile huge *) 0x201F64))

// Message Object 124 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR124H         (*((unsigned int volatile huge *) 0x201F86))

// Message Object 124 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR124L         (*((unsigned int volatile huge *) 0x201F84))

// Message Object 125 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR125H         (*((unsigned int volatile huge *) 0x201FA6))

// Message Object 125 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR125L         (*((unsigned int volatile huge *) 0x201FA4))

// Message Object 126 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR126H         (*((unsigned int volatile huge *) 0x201FC6))

// Message Object 126 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR126L         (*((unsigned int volatile huge *) 0x201FC4))

// Message Object 127 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR127H         (*((unsigned int volatile huge *) 0x201FE6))

// Message Object 127 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR127L         (*((unsigned int volatile huge *) 0x201FE4))

// Message Object 12 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR12H          (*((unsigned int volatile huge *) 0x201186))

// Message Object 12 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR12L          (*((unsigned int volatile huge *) 0x201184))

// Message Object 13 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR13H          (*((unsigned int volatile huge *) 0x2011A6))

// Message Object 13 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR13L          (*((unsigned int volatile huge *) 0x2011A4))

// Message Object 14 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR14H          (*((unsigned int volatile huge *) 0x2011C6))

// Message Object 14 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR14L          (*((unsigned int volatile huge *) 0x2011C4))

// Message Object 15 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR15H          (*((unsigned int volatile huge *) 0x2011E6))

// Message Object 15 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR15L          (*((unsigned int volatile huge *) 0x2011E4))

// Message Object 16 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR16H          (*((unsigned int volatile huge *) 0x201206))

// Message Object 16 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR16L          (*((unsigned int volatile huge *) 0x201204))

// Message Object 17 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR17H          (*((unsigned int volatile huge *) 0x201226))

// Message Object 17 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR17L          (*((unsigned int volatile huge *) 0x201224))

// Message Object 18 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR18H          (*((unsigned int volatile huge *) 0x201246))

// Message Object 18 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR18L          (*((unsigned int volatile huge *) 0x201244))

// Message Object 19 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR19H          (*((unsigned int volatile huge *) 0x201266))

// Message Object 19 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR19L          (*((unsigned int volatile huge *) 0x201264))

// Message Object 1 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR1H           (*((unsigned int volatile huge *) 0x201026))

// Message Object 1 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR1L           (*((unsigned int volatile huge *) 0x201024))

// Message Object 20 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR20H          (*((unsigned int volatile huge *) 0x201286))

// Message Object 20 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR20L          (*((unsigned int volatile huge *) 0x201284))

// Message Object 21 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR21H          (*((unsigned int volatile huge *) 0x2012A6))

// Message Object 21 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR21L          (*((unsigned int volatile huge *) 0x2012A4))

// Message Object 22 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR22H          (*((unsigned int volatile huge *) 0x2012C6))

// Message Object 22 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR22L          (*((unsigned int volatile huge *) 0x2012C4))

// Message Object 23 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR23H          (*((unsigned int volatile huge *) 0x2012E6))

// Message Object 23 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR23L          (*((unsigned int volatile huge *) 0x2012E4))

// Message Object 24 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR24H          (*((unsigned int volatile huge *) 0x201306))

// Message Object 24 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR24L          (*((unsigned int volatile huge *) 0x201304))

// Message Object 25 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR25H          (*((unsigned int volatile huge *) 0x201326))

// Message Object 25 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR25L          (*((unsigned int volatile huge *) 0x201324))

// Message Object 26 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR26H          (*((unsigned int volatile huge *) 0x201346))

// Message Object 26 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR26L          (*((unsigned int volatile huge *) 0x201344))

// Message Object 27 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR27H          (*((unsigned int volatile huge *) 0x201366))

// Message Object 27 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR27L          (*((unsigned int volatile huge *) 0x201364))

// Message Object 28 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR28H          (*((unsigned int volatile huge *) 0x201386))

// Message Object 28 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR28L          (*((unsigned int volatile huge *) 0x201384))

// Message Object 29 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR29H          (*((unsigned int volatile huge *) 0x2013A6))

// Message Object 29 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR29L          (*((unsigned int volatile huge *) 0x2013A4))

// Message Object 2 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR2H           (*((unsigned int volatile huge *) 0x201046))

// Message Object 2 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR2L           (*((unsigned int volatile huge *) 0x201044))

// Message Object 30 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR30H          (*((unsigned int volatile huge *) 0x2013C6))

// Message Object 30 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR30L          (*((unsigned int volatile huge *) 0x2013C4))

// Message Object 31 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR31H          (*((unsigned int volatile huge *) 0x2013E6))

// Message Object 31 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR31L          (*((unsigned int volatile huge *) 0x2013E4))

// Message Object 32 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR32H          (*((unsigned int volatile huge *) 0x201406))

// Message Object 32 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR32L          (*((unsigned int volatile huge *) 0x201404))

// Message Object 33 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR33H          (*((unsigned int volatile huge *) 0x201426))

// Message Object 33 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR33L          (*((unsigned int volatile huge *) 0x201424))

// Message Object 34 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR34H          (*((unsigned int volatile huge *) 0x201446))

// Message Object 34 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR34L          (*((unsigned int volatile huge *) 0x201444))

// Message Object 35 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR35H          (*((unsigned int volatile huge *) 0x201466))

// Message Object 35 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR35L          (*((unsigned int volatile huge *) 0x201464))

// Message Object 36 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR36H          (*((unsigned int volatile huge *) 0x201486))

// Message Object 36 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR36L          (*((unsigned int volatile huge *) 0x201484))

// Message Object 37 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR37H          (*((unsigned int volatile huge *) 0x2014A6))

// Message Object 37 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR37L          (*((unsigned int volatile huge *) 0x2014A4))

// Message Object 38 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR38H          (*((unsigned int volatile huge *) 0x2014C6))

// Message Object 38 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR38L          (*((unsigned int volatile huge *) 0x2014C4))

// Message Object 39 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR39H          (*((unsigned int volatile huge *) 0x2014E6))

// Message Object 39 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR39L          (*((unsigned int volatile huge *) 0x2014E4))

// Message Object 3 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR3H           (*((unsigned int volatile huge *) 0x201066))

// Message Object 3 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR3L           (*((unsigned int volatile huge *) 0x201064))

// Message Object 40 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR40H          (*((unsigned int volatile huge *) 0x201506))

// Message Object 40 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR40L          (*((unsigned int volatile huge *) 0x201504))

// Message Object 41 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR41H          (*((unsigned int volatile huge *) 0x201526))

// Message Object 41 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR41L          (*((unsigned int volatile huge *) 0x201524))

// Message Object 42 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR42H          (*((unsigned int volatile huge *) 0x201546))

// Message Object 42 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR42L          (*((unsigned int volatile huge *) 0x201544))

// Message Object 43 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR43H          (*((unsigned int volatile huge *) 0x201566))

// Message Object 43 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR43L          (*((unsigned int volatile huge *) 0x201564))

// Message Object 44 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR44H          (*((unsigned int volatile huge *) 0x201586))

// Message Object 44 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR44L          (*((unsigned int volatile huge *) 0x201584))

// Message Object 45 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR45H          (*((unsigned int volatile huge *) 0x2015A6))

// Message Object 45 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR45L          (*((unsigned int volatile huge *) 0x2015A4))

// Message Object 46 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR46H          (*((unsigned int volatile huge *) 0x2015C6))

// Message Object 46 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR46L          (*((unsigned int volatile huge *) 0x2015C4))

// Message Object 47 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR47H          (*((unsigned int volatile huge *) 0x2015E6))

// Message Object 47 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR47L          (*((unsigned int volatile huge *) 0x2015E4))

// Message Object 48 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR48H          (*((unsigned int volatile huge *) 0x201606))

// Message Object 48 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR48L          (*((unsigned int volatile huge *) 0x201604))

// Message Object 49 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR49H          (*((unsigned int volatile huge *) 0x201626))

// Message Object 49 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR49L          (*((unsigned int volatile huge *) 0x201624))

// Message Object 4 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR4H           (*((unsigned int volatile huge *) 0x201086))

// Message Object 4 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR4L           (*((unsigned int volatile huge *) 0x201084))

// Message Object 50 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR50H          (*((unsigned int volatile huge *) 0x201646))

// Message Object 50 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR50L          (*((unsigned int volatile huge *) 0x201644))

// Message Object 51 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR51H          (*((unsigned int volatile huge *) 0x201666))

// Message Object 51 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR51L          (*((unsigned int volatile huge *) 0x201664))

// Message Object 52 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR52H          (*((unsigned int volatile huge *) 0x201686))

// Message Object 52 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR52L          (*((unsigned int volatile huge *) 0x201684))

// Message Object 53 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR53H          (*((unsigned int volatile huge *) 0x2016A6))

// Message Object 53 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR53L          (*((unsigned int volatile huge *) 0x2016A4))

// Message Object 54 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR54H          (*((unsigned int volatile huge *) 0x2016C6))

// Message Object 54 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR54L          (*((unsigned int volatile huge *) 0x2016C4))

// Message Object 55 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR55H          (*((unsigned int volatile huge *) 0x2016E6))

// Message Object 55 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR55L          (*((unsigned int volatile huge *) 0x2016E4))

// Message Object 56 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR56H          (*((unsigned int volatile huge *) 0x201706))

// Message Object 56 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR56L          (*((unsigned int volatile huge *) 0x201704))

// Message Object 57 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR57H          (*((unsigned int volatile huge *) 0x201726))

// Message Object 57 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR57L          (*((unsigned int volatile huge *) 0x201724))

// Message Object 58 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR58H          (*((unsigned int volatile huge *) 0x201746))

// Message Object 58 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR58L          (*((unsigned int volatile huge *) 0x201744))

// Message Object 59 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR59H          (*((unsigned int volatile huge *) 0x201766))

// Message Object 59 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR59L          (*((unsigned int volatile huge *) 0x201764))

// Message Object 5 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR5H           (*((unsigned int volatile huge *) 0x2010A6))

// Message Object 5 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR5L           (*((unsigned int volatile huge *) 0x2010A4))

// Message Object 60 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR60H          (*((unsigned int volatile huge *) 0x201786))

// Message Object 60 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR60L          (*((unsigned int volatile huge *) 0x201784))

// Message Object 61 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR61H          (*((unsigned int volatile huge *) 0x2017A6))

// Message Object 61 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR61L          (*((unsigned int volatile huge *) 0x2017A4))

// Message Object 62 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR62H          (*((unsigned int volatile huge *) 0x2017C6))

// Message Object 62 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR62L          (*((unsigned int volatile huge *) 0x2017C4))

// Message Object 63 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR63H          (*((unsigned int volatile huge *) 0x2017E6))

// Message Object 63 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR63L          (*((unsigned int volatile huge *) 0x2017E4))

// Message Object 64 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR64H          (*((unsigned int volatile huge *) 0x201806))

// Message Object 64 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR64L          (*((unsigned int volatile huge *) 0x201804))

// Message Object 65 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR65H          (*((unsigned int volatile huge *) 0x201826))

// Message Object 65 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR65L          (*((unsigned int volatile huge *) 0x201824))

// Message Object 66 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR66H          (*((unsigned int volatile huge *) 0x201846))

// Message Object 66 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR66L          (*((unsigned int volatile huge *) 0x201844))

// Message Object 67 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR67H          (*((unsigned int volatile huge *) 0x201866))

// Message Object 67 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR67L          (*((unsigned int volatile huge *) 0x201864))

// Message Object 68 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR68H          (*((unsigned int volatile huge *) 0x201886))

// Message Object 68 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR68L          (*((unsigned int volatile huge *) 0x201884))

// Message Object 69 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR69H          (*((unsigned int volatile huge *) 0x2018A6))

// Message Object 69 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR69L          (*((unsigned int volatile huge *) 0x2018A4))

// Message Object 6 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR6H           (*((unsigned int volatile huge *) 0x2010C6))

// Message Object 6 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR6L           (*((unsigned int volatile huge *) 0x2010C4))

// Message Object 70 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR70H          (*((unsigned int volatile huge *) 0x2018C6))

// Message Object 70 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR70L          (*((unsigned int volatile huge *) 0x2018C4))

// Message Object 71 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR71H          (*((unsigned int volatile huge *) 0x2018E6))

// Message Object 71 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR71L          (*((unsigned int volatile huge *) 0x2018E4))

// Message Object 72 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR72H          (*((unsigned int volatile huge *) 0x201906))

// Message Object 72 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR72L          (*((unsigned int volatile huge *) 0x201904))

// Message Object 73 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR73H          (*((unsigned int volatile huge *) 0x201926))

// Message Object 73 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR73L          (*((unsigned int volatile huge *) 0x201924))

// Message Object 74 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR74H          (*((unsigned int volatile huge *) 0x201946))

// Message Object 74 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR74L          (*((unsigned int volatile huge *) 0x201944))

// Message Object 75 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR75H          (*((unsigned int volatile huge *) 0x201966))

// Message Object 75 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR75L          (*((unsigned int volatile huge *) 0x201964))

// Message Object 76 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR76H          (*((unsigned int volatile huge *) 0x201986))

// Message Object 76 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR76L          (*((unsigned int volatile huge *) 0x201984))

// Message Object 77 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR77H          (*((unsigned int volatile huge *) 0x2019A6))

// Message Object 77 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR77L          (*((unsigned int volatile huge *) 0x2019A4))

// Message Object 78 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR78H          (*((unsigned int volatile huge *) 0x2019C6))

// Message Object 78 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR78L          (*((unsigned int volatile huge *) 0x2019C4))

// Message Object 79 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR79H          (*((unsigned int volatile huge *) 0x2019E6))

// Message Object 79 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR79L          (*((unsigned int volatile huge *) 0x2019E4))

// Message Object 7 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR7H           (*((unsigned int volatile huge *) 0x2010E6))

// Message Object 7 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR7L           (*((unsigned int volatile huge *) 0x2010E4))

// Message Object 80 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR80H          (*((unsigned int volatile huge *) 0x201A06))

// Message Object 80 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR80L          (*((unsigned int volatile huge *) 0x201A04))

// Message Object 81 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR81H          (*((unsigned int volatile huge *) 0x201A26))

// Message Object 81 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR81L          (*((unsigned int volatile huge *) 0x201A24))

// Message Object 82 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR82H          (*((unsigned int volatile huge *) 0x201A46))

// Message Object 82 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR82L          (*((unsigned int volatile huge *) 0x201A44))

// Message Object 83 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR83H          (*((unsigned int volatile huge *) 0x201A66))

// Message Object 83 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR83L          (*((unsigned int volatile huge *) 0x201A64))

// Message Object 84 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR84H          (*((unsigned int volatile huge *) 0x201A86))

// Message Object 84 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR84L          (*((unsigned int volatile huge *) 0x201A84))

// Message Object 85 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR85H          (*((unsigned int volatile huge *) 0x201AA6))

// Message Object 85 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR85L          (*((unsigned int volatile huge *) 0x201AA4))

// Message Object 86 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR86H          (*((unsigned int volatile huge *) 0x201AC6))

// Message Object 86 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR86L          (*((unsigned int volatile huge *) 0x201AC4))

// Message Object 87 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR87H          (*((unsigned int volatile huge *) 0x201AE6))

// Message Object 87 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR87L          (*((unsigned int volatile huge *) 0x201AE4))

// Message Object 88 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR88H          (*((unsigned int volatile huge *) 0x201B06))

// Message Object 88 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR88L          (*((unsigned int volatile huge *) 0x201B04))

// Message Object 89 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR89H          (*((unsigned int volatile huge *) 0x201B26))

// Message Object 89 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR89L          (*((unsigned int volatile huge *) 0x201B24))

// Message Object 8 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR8H           (*((unsigned int volatile huge *) 0x201106))

// Message Object 8 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR8L           (*((unsigned int volatile huge *) 0x201104))

// Message Object 90 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR90H          (*((unsigned int volatile huge *) 0x201B46))

// Message Object 90 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR90L          (*((unsigned int volatile huge *) 0x201B44))

// Message Object 91 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR91H          (*((unsigned int volatile huge *) 0x201B66))

// Message Object 91 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR91L          (*((unsigned int volatile huge *) 0x201B64))

// Message Object 92 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR92H          (*((unsigned int volatile huge *) 0x201B86))

// Message Object 92 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR92L          (*((unsigned int volatile huge *) 0x201B84))

// Message Object 93 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR93H          (*((unsigned int volatile huge *) 0x201BA6))

// Message Object 93 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR93L          (*((unsigned int volatile huge *) 0x201BA4))

// Message Object 94 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR94H          (*((unsigned int volatile huge *) 0x201BC6))

// Message Object 94 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR94L          (*((unsigned int volatile huge *) 0x201BC4))

// Message Object 95 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR95H          (*((unsigned int volatile huge *) 0x201BE6))

// Message Object 95 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR95L          (*((unsigned int volatile huge *) 0x201BE4))

// Message Object 96 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR96H          (*((unsigned int volatile huge *) 0x201C06))

// Message Object 96 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR96L          (*((unsigned int volatile huge *) 0x201C04))

// Message Object 97 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR97H          (*((unsigned int volatile huge *) 0x201C26))

// Message Object 97 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR97L          (*((unsigned int volatile huge *) 0x201C24))

// Message Object 98 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR98H          (*((unsigned int volatile huge *) 0x201C46))

// Message Object 98 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR98L          (*((unsigned int volatile huge *) 0x201C44))

// Message Object 99 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR99H          (*((unsigned int volatile huge *) 0x201C66))

// Message Object 99 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR99L          (*((unsigned int volatile huge *) 0x201C64))

// Message Object 9 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR9H           (*((unsigned int volatile huge *) 0x201126))

// Message Object 9 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR9L           (*((unsigned int volatile huge *) 0x201124))

// Message Object 0 Interrupt Pointer Register High
#define CAN_MOIPR0H            (*((unsigned int volatile huge *) 0x20100A))

// Message Object 0 Interrupt Pointer Register Low
#define CAN_MOIPR0L            (*((unsigned int volatile huge *) 0x201008))

// Message Object 100 Interrupt Pointer Register High
#define CAN_MOIPR100H          (*((unsigned int volatile huge *) 0x201C8A))

// Message Object 100 Interrupt Pointer Register Low
#define CAN_MOIPR100L          (*((unsigned int volatile huge *) 0x201C88))

// Message Object 101 Interrupt Pointer Register High
#define CAN_MOIPR101H          (*((unsigned int volatile huge *) 0x201CAA))

// Message Object 101 Interrupt Pointer Register Low
#define CAN_MOIPR101L          (*((unsigned int volatile huge *) 0x201CA8))

// Message Object 102 Interrupt Pointer Register High
#define CAN_MOIPR102H          (*((unsigned int volatile huge *) 0x201CCA))

// Message Object 102 Interrupt Pointer Register Low
#define CAN_MOIPR102L          (*((unsigned int volatile huge *) 0x201CC8))

// Message Object 103 Interrupt Pointer Register High
#define CAN_MOIPR103H          (*((unsigned int volatile huge *) 0x201CEA))

// Message Object 103 Interrupt Pointer Register Low
#define CAN_MOIPR103L          (*((unsigned int volatile huge *) 0x201CE8))

// Message Object 104 Interrupt Pointer Register High
#define CAN_MOIPR104H          (*((unsigned int volatile huge *) 0x201D0A))

// Message Object 104 Interrupt Pointer Register Low
#define CAN_MOIPR104L          (*((unsigned int volatile huge *) 0x201D08))

// Message Object 105 Interrupt Pointer Register High
#define CAN_MOIPR105H          (*((unsigned int volatile huge *) 0x201D2A))

// Message Object 105 Interrupt Pointer Register Low
#define CAN_MOIPR105L          (*((unsigned int volatile huge *) 0x201D28))

// Message Object 106 Interrupt Pointer Register High
#define CAN_MOIPR106H          (*((unsigned int volatile huge *) 0x201D4A))

// Message Object 106 Interrupt Pointer Register Low
#define CAN_MOIPR106L          (*((unsigned int volatile huge *) 0x201D48))

// Message Object 107 Interrupt Pointer Register High
#define CAN_MOIPR107H          (*((unsigned int volatile huge *) 0x201D6A))

// Message Object 107 Interrupt Pointer Register Low
#define CAN_MOIPR107L          (*((unsigned int volatile huge *) 0x201D68))

// Message Object 108 Interrupt Pointer Register High
#define CAN_MOIPR108H          (*((unsigned int volatile huge *) 0x201D8A))

// Message Object 108 Interrupt Pointer Register Low
#define CAN_MOIPR108L          (*((unsigned int volatile huge *) 0x201D88))

// Message Object 109 Interrupt Pointer Register High
#define CAN_MOIPR109H          (*((unsigned int volatile huge *) 0x201DAA))

// Message Object 109 Interrupt Pointer Register Low
#define CAN_MOIPR109L          (*((unsigned int volatile huge *) 0x201DA8))

// Message Object 10 Interrupt Pointer Register High
#define CAN_MOIPR10H           (*((unsigned int volatile huge *) 0x20114A))

// Message Object 10 Interrupt Pointer Register Low
#define CAN_MOIPR10L           (*((unsigned int volatile huge *) 0x201148))

// Message Object 110 Interrupt Pointer Register High
#define CAN_MOIPR110H          (*((unsigned int volatile huge *) 0x201DCA))

// Message Object 110 Interrupt Pointer Register Low
#define CAN_MOIPR110L          (*((unsigned int volatile huge *) 0x201DC8))

// Message Object 111 Interrupt Pointer Register High
#define CAN_MOIPR111H          (*((unsigned int volatile huge *) 0x201DEA))

// Message Object 111 Interrupt Pointer Register Low
#define CAN_MOIPR111L          (*((unsigned int volatile huge *) 0x201DE8))

// Message Object 112 Interrupt Pointer Register High
#define CAN_MOIPR112H          (*((unsigned int volatile huge *) 0x201E0A))

// Message Object 112 Interrupt Pointer Register Low
#define CAN_MOIPR112L          (*((unsigned int volatile huge *) 0x201E08))

// Message Object 113 Interrupt Pointer Register High
#define CAN_MOIPR113H          (*((unsigned int volatile huge *) 0x201E2A))

// Message Object 113 Interrupt Pointer Register Low
#define CAN_MOIPR113L          (*((unsigned int volatile huge *) 0x201E28))

// Message Object 114 Interrupt Pointer Register High
#define CAN_MOIPR114H          (*((unsigned int volatile huge *) 0x201E4A))

// Message Object 114 Interrupt Pointer Register Low
#define CAN_MOIPR114L          (*((unsigned int volatile huge *) 0x201E48))

// Message Object 115 Interrupt Pointer Register High
#define CAN_MOIPR115H          (*((unsigned int volatile huge *) 0x201E6A))

// Message Object 115 Interrupt Pointer Register Low
#define CAN_MOIPR115L          (*((unsigned int volatile huge *) 0x201E68))

// Message Object 116 Interrupt Pointer Register High
#define CAN_MOIPR116H          (*((unsigned int volatile huge *) 0x201E8A))

// Message Object 116 Interrupt Pointer Register Low
#define CAN_MOIPR116L          (*((unsigned int volatile huge *) 0x201E88))

// Message Object 117 Interrupt Pointer Register High
#define CAN_MOIPR117H          (*((unsigned int volatile huge *) 0x201EAA))

// Message Object 117 Interrupt Pointer Register Low
#define CAN_MOIPR117L          (*((unsigned int volatile huge *) 0x201EA8))

// Message Object 118 Interrupt Pointer Register High
#define CAN_MOIPR118H          (*((unsigned int volatile huge *) 0x201ECA))

// Message Object 118 Interrupt Pointer Register Low
#define CAN_MOIPR118L          (*((unsigned int volatile huge *) 0x201EC8))

// Message Object 119 Interrupt Pointer Register High
#define CAN_MOIPR119H          (*((unsigned int volatile huge *) 0x201EEA))

// Message Object 119 Interrupt Pointer Register Low
#define CAN_MOIPR119L          (*((unsigned int volatile huge *) 0x201EE8))

// Message Object 11 Interrupt Pointer Register High
#define CAN_MOIPR11H           (*((unsigned int volatile huge *) 0x20116A))

// Message Object 11 Interrupt Pointer Register Low
#define CAN_MOIPR11L           (*((unsigned int volatile huge *) 0x201168))

// Message Object 120 Interrupt Pointer Register High
#define CAN_MOIPR120H          (*((unsigned int volatile huge *) 0x201F0A))

// Message Object 120 Interrupt Pointer Register Low
#define CAN_MOIPR120L          (*((unsigned int volatile huge *) 0x201F08))

// Message Object 121 Interrupt Pointer Register High
#define CAN_MOIPR121H          (*((unsigned int volatile huge *) 0x201F2A))

// Message Object 121 Interrupt Pointer Register Low
#define CAN_MOIPR121L          (*((unsigned int volatile huge *) 0x201F28))

// Message Object 122 Interrupt Pointer Register High
#define CAN_MOIPR122H          (*((unsigned int volatile huge *) 0x201F4A))

// Message Object 122 Interrupt Pointer Register Low
#define CAN_MOIPR122L          (*((unsigned int volatile huge *) 0x201F48))

// Message Object 123 Interrupt Pointer Register High
#define CAN_MOIPR123H          (*((unsigned int volatile huge *) 0x201F6A))

// Message Object 123 Interrupt Pointer Register Low
#define CAN_MOIPR123L          (*((unsigned int volatile huge *) 0x201F68))

// Message Object 124 Interrupt Pointer Register High
#define CAN_MOIPR124H          (*((unsigned int volatile huge *) 0x201F8A))

// Message Object 124 Interrupt Pointer Register Low
#define CAN_MOIPR124L          (*((unsigned int volatile huge *) 0x201F88))

// Message Object 125 Interrupt Pointer Register High
#define CAN_MOIPR125H          (*((unsigned int volatile huge *) 0x201FAA))

// Message Object 125 Interrupt Pointer Register Low
#define CAN_MOIPR125L          (*((unsigned int volatile huge *) 0x201FA8))

// Message Object 126 Interrupt Pointer Register High
#define CAN_MOIPR126H          (*((unsigned int volatile huge *) 0x201FCA))

// Message Object 126 Interrupt Pointer Register Low
#define CAN_MOIPR126L          (*((unsigned int volatile huge *) 0x201FC8))

// Message Object 127 Interrupt Pointer Register High
#define CAN_MOIPR127H          (*((unsigned int volatile huge *) 0x201FEA))

// Message Object 127 Interrupt Pointer Register Low
#define CAN_MOIPR127L          (*((unsigned int volatile huge *) 0x201FE8))

// Message Object 12 Interrupt Pointer Register High
#define CAN_MOIPR12H           (*((unsigned int volatile huge *) 0x20118A))

// Message Object 12 Interrupt Pointer Register Low
#define CAN_MOIPR12L           (*((unsigned int volatile huge *) 0x201188))

// Message Object 13 Interrupt Pointer Register High
#define CAN_MOIPR13H           (*((unsigned int volatile huge *) 0x2011AA))

// Message Object 13 Interrupt Pointer Register Low
#define CAN_MOIPR13L           (*((unsigned int volatile huge *) 0x2011A8))

// Message Object 14 Interrupt Pointer Register High
#define CAN_MOIPR14H           (*((unsigned int volatile huge *) 0x2011CA))

// Message Object 14 Interrupt Pointer Register Low
#define CAN_MOIPR14L           (*((unsigned int volatile huge *) 0x2011C8))

// Message Object 15 Interrupt Pointer Register High
#define CAN_MOIPR15H           (*((unsigned int volatile huge *) 0x2011EA))

// Message Object 15 Interrupt Pointer Register Low
#define CAN_MOIPR15L           (*((unsigned int volatile huge *) 0x2011E8))

// Message Object 16 Interrupt Pointer Register High
#define CAN_MOIPR16H           (*((unsigned int volatile huge *) 0x20120A))

// Message Object 16 Interrupt Pointer Register Low
#define CAN_MOIPR16L           (*((unsigned int volatile huge *) 0x201208))

// Message Object 17 Interrupt Pointer Register High
#define CAN_MOIPR17H           (*((unsigned int volatile huge *) 0x20122A))

// Message Object 17 Interrupt Pointer Register Low
#define CAN_MOIPR17L           (*((unsigned int volatile huge *) 0x201228))

// Message Object 18 Interrupt Pointer Register High
#define CAN_MOIPR18H           (*((unsigned int volatile huge *) 0x20124A))

// Message Object 18 Interrupt Pointer Register Low
#define CAN_MOIPR18L           (*((unsigned int volatile huge *) 0x201248))

// Message Object 19 Interrupt Pointer Register High
#define CAN_MOIPR19H           (*((unsigned int volatile huge *) 0x20126A))

// Message Object 19 Interrupt Pointer Register Low
#define CAN_MOIPR19L           (*((unsigned int volatile huge *) 0x201268))

// Message Object 1 Interrupt Pointer Register High
#define CAN_MOIPR1H            (*((unsigned int volatile huge *) 0x20102A))

// Message Object 1 Interrupt Pointer Register Low
#define CAN_MOIPR1L            (*((unsigned int volatile huge *) 0x201028))

// Message Object 20 Interrupt Pointer Register High
#define CAN_MOIPR20H           (*((unsigned int volatile huge *) 0x20128A))

// Message Object 20 Interrupt Pointer Register Low
#define CAN_MOIPR20L           (*((unsigned int volatile huge *) 0x201288))

// Message Object 21 Interrupt Pointer Register High
#define CAN_MOIPR21H           (*((unsigned int volatile huge *) 0x2012AA))

// Message Object 21 Interrupt Pointer Register Low
#define CAN_MOIPR21L           (*((unsigned int volatile huge *) 0x2012A8))

// Message Object 22 Interrupt Pointer Register High
#define CAN_MOIPR22H           (*((unsigned int volatile huge *) 0x2012CA))

// Message Object 22 Interrupt Pointer Register Low
#define CAN_MOIPR22L           (*((unsigned int volatile huge *) 0x2012C8))

// Message Object 23 Interrupt Pointer Register High
#define CAN_MOIPR23H           (*((unsigned int volatile huge *) 0x2012EA))

// Message Object 23 Interrupt Pointer Register Low
#define CAN_MOIPR23L           (*((unsigned int volatile huge *) 0x2012E8))

// Message Object 24 Interrupt Pointer Register High
#define CAN_MOIPR24H           (*((unsigned int volatile huge *) 0x20130A))

// Message Object 24 Interrupt Pointer Register Low
#define CAN_MOIPR24L           (*((unsigned int volatile huge *) 0x201308))

// Message Object 25 Interrupt Pointer Register High
#define CAN_MOIPR25H           (*((unsigned int volatile huge *) 0x20132A))

// Message Object 25 Interrupt Pointer Register Low
#define CAN_MOIPR25L           (*((unsigned int volatile huge *) 0x201328))

// Message Object 26 Interrupt Pointer Register High
#define CAN_MOIPR26H           (*((unsigned int volatile huge *) 0x20134A))

// Message Object 26 Interrupt Pointer Register Low
#define CAN_MOIPR26L           (*((unsigned int volatile huge *) 0x201348))

// Message Object 27 Interrupt Pointer Register High
#define CAN_MOIPR27H           (*((unsigned int volatile huge *) 0x20136A))

// Message Object 27 Interrupt Pointer Register Low
#define CAN_MOIPR27L           (*((unsigned int volatile huge *) 0x201368))

// Message Object 28 Interrupt Pointer Register High
#define CAN_MOIPR28H           (*((unsigned int volatile huge *) 0x20138A))

// Message Object 28 Interrupt Pointer Register Low
#define CAN_MOIPR28L           (*((unsigned int volatile huge *) 0x201388))

// Message Object 29 Interrupt Pointer Register High
#define CAN_MOIPR29H           (*((unsigned int volatile huge *) 0x2013AA))

// Message Object 29 Interrupt Pointer Register Low
#define CAN_MOIPR29L           (*((unsigned int volatile huge *) 0x2013A8))

// Message Object 2 Interrupt Pointer Register High
#define CAN_MOIPR2H            (*((unsigned int volatile huge *) 0x20104A))

// Message Object 2 Interrupt Pointer Register Low
#define CAN_MOIPR2L            (*((unsigned int volatile huge *) 0x201048))

// Message Object 30 Interrupt Pointer Register High
#define CAN_MOIPR30H           (*((unsigned int volatile huge *) 0x2013CA))

// Message Object 30 Interrupt Pointer Register Low
#define CAN_MOIPR30L           (*((unsigned int volatile huge *) 0x2013C8))

// Message Object 31 Interrupt Pointer Register High
#define CAN_MOIPR31H           (*((unsigned int volatile huge *) 0x2013EA))

// Message Object 31 Interrupt Pointer Register Low
#define CAN_MOIPR31L           (*((unsigned int volatile huge *) 0x2013E8))

// Message Object 32 Interrupt Pointer Register High
#define CAN_MOIPR32H           (*((unsigned int volatile huge *) 0x20140A))

// Message Object 32 Interrupt Pointer Register Low
#define CAN_MOIPR32L           (*((unsigned int volatile huge *) 0x201408))

// Message Object 33 Interrupt Pointer Register High
#define CAN_MOIPR33H           (*((unsigned int volatile huge *) 0x20142A))

// Message Object 33 Interrupt Pointer Register Low
#define CAN_MOIPR33L           (*((unsigned int volatile huge *) 0x201428))

// Message Object 34 Interrupt Pointer Register High
#define CAN_MOIPR34H           (*((unsigned int volatile huge *) 0x20144A))

// Message Object 34 Interrupt Pointer Register Low
#define CAN_MOIPR34L           (*((unsigned int volatile huge *) 0x201448))

// Message Object 35 Interrupt Pointer Register High
#define CAN_MOIPR35H           (*((unsigned int volatile huge *) 0x20146A))

// Message Object 35 Interrupt Pointer Register Low
#define CAN_MOIPR35L           (*((unsigned int volatile huge *) 0x201468))

// Message Object 36 Interrupt Pointer Register High
#define CAN_MOIPR36H           (*((unsigned int volatile huge *) 0x20148A))

// Message Object 36 Interrupt Pointer Register Low
#define CAN_MOIPR36L           (*((unsigned int volatile huge *) 0x201488))

// Message Object 37 Interrupt Pointer Register High
#define CAN_MOIPR37H           (*((unsigned int volatile huge *) 0x2014AA))

// Message Object 37 Interrupt Pointer Register Low
#define CAN_MOIPR37L           (*((unsigned int volatile huge *) 0x2014A8))

// Message Object 38 Interrupt Pointer Register High
#define CAN_MOIPR38H           (*((unsigned int volatile huge *) 0x2014CA))

// Message Object 38 Interrupt Pointer Register Low
#define CAN_MOIPR38L           (*((unsigned int volatile huge *) 0x2014C8))

// Message Object 39 Interrupt Pointer Register High
#define CAN_MOIPR39H           (*((unsigned int volatile huge *) 0x2014EA))

// Message Object 39 Interrupt Pointer Register Low
#define CAN_MOIPR39L           (*((unsigned int volatile huge *) 0x2014E8))

// Message Object 3 Interrupt Pointer Register High
#define CAN_MOIPR3H            (*((unsigned int volatile huge *) 0x20106A))

// Message Object 3 Interrupt Pointer Register Low
#define CAN_MOIPR3L            (*((unsigned int volatile huge *) 0x201068))

// Message Object 40 Interrupt Pointer Register High
#define CAN_MOIPR40H           (*((unsigned int volatile huge *) 0x20150A))

// Message Object 40 Interrupt Pointer Register Low
#define CAN_MOIPR40L           (*((unsigned int volatile huge *) 0x201508))

// Message Object 41 Interrupt Pointer Register High
#define CAN_MOIPR41H           (*((unsigned int volatile huge *) 0x20152A))

// Message Object 41 Interrupt Pointer Register Low
#define CAN_MOIPR41L           (*((unsigned int volatile huge *) 0x201528))

// Message Object 42 Interrupt Pointer Register High
#define CAN_MOIPR42H           (*((unsigned int volatile huge *) 0x20154A))

// Message Object 42 Interrupt Pointer Register Low
#define CAN_MOIPR42L           (*((unsigned int volatile huge *) 0x201548))

// Message Object 43 Interrupt Pointer Register High
#define CAN_MOIPR43H           (*((unsigned int volatile huge *) 0x20156A))

// Message Object 43 Interrupt Pointer Register Low
#define CAN_MOIPR43L           (*((unsigned int volatile huge *) 0x201568))

// Message Object 44 Interrupt Pointer Register High
#define CAN_MOIPR44H           (*((unsigned int volatile huge *) 0x20158A))

// Message Object 44 Interrupt Pointer Register Low
#define CAN_MOIPR44L           (*((unsigned int volatile huge *) 0x201588))

// Message Object 45 Interrupt Pointer Register High
#define CAN_MOIPR45H           (*((unsigned int volatile huge *) 0x2015AA))

// Message Object 45 Interrupt Pointer Register Low
#define CAN_MOIPR45L           (*((unsigned int volatile huge *) 0x2015A8))

// Message Object 46 Interrupt Pointer Register High
#define CAN_MOIPR46H           (*((unsigned int volatile huge *) 0x2015CA))

// Message Object 46 Interrupt Pointer Register Low
#define CAN_MOIPR46L           (*((unsigned int volatile huge *) 0x2015C8))

// Message Object 47 Interrupt Pointer Register High
#define CAN_MOIPR47H           (*((unsigned int volatile huge *) 0x2015EA))

// Message Object 47 Interrupt Pointer Register Low
#define CAN_MOIPR47L           (*((unsigned int volatile huge *) 0x2015E8))

// Message Object 48 Interrupt Pointer Register High
#define CAN_MOIPR48H           (*((unsigned int volatile huge *) 0x20160A))

// Message Object 48 Interrupt Pointer Register Low
#define CAN_MOIPR48L           (*((unsigned int volatile huge *) 0x201608))

// Message Object 49 Interrupt Pointer Register High
#define CAN_MOIPR49H           (*((unsigned int volatile huge *) 0x20162A))

// Message Object 49 Interrupt Pointer Register Low
#define CAN_MOIPR49L           (*((unsigned int volatile huge *) 0x201628))

// Message Object 4 Interrupt Pointer Register High
#define CAN_MOIPR4H            (*((unsigned int volatile huge *) 0x20108A))

// Message Object 4 Interrupt Pointer Register Low
#define CAN_MOIPR4L            (*((unsigned int volatile huge *) 0x201088))

// Message Object 50 Interrupt Pointer Register High
#define CAN_MOIPR50H           (*((unsigned int volatile huge *) 0x20164A))

// Message Object 50 Interrupt Pointer Register Low
#define CAN_MOIPR50L           (*((unsigned int volatile huge *) 0x201648))

// Message Object 51 Interrupt Pointer Register High
#define CAN_MOIPR51H           (*((unsigned int volatile huge *) 0x20166A))

// Message Object 51 Interrupt Pointer Register Low
#define CAN_MOIPR51L           (*((unsigned int volatile huge *) 0x201668))

// Message Object 52 Interrupt Pointer Register High
#define CAN_MOIPR52H           (*((unsigned int volatile huge *) 0x20168A))

// Message Object 52 Interrupt Pointer Register Low
#define CAN_MOIPR52L           (*((unsigned int volatile huge *) 0x201688))

// Message Object 53 Interrupt Pointer Register High
#define CAN_MOIPR53H           (*((unsigned int volatile huge *) 0x2016AA))

// Message Object 53 Interrupt Pointer Register Low
#define CAN_MOIPR53L           (*((unsigned int volatile huge *) 0x2016A8))

// Message Object 54 Interrupt Pointer Register High
#define CAN_MOIPR54H           (*((unsigned int volatile huge *) 0x2016CA))

// Message Object 54 Interrupt Pointer Register Low
#define CAN_MOIPR54L           (*((unsigned int volatile huge *) 0x2016C8))

// Message Object 55 Interrupt Pointer Register High
#define CAN_MOIPR55H           (*((unsigned int volatile huge *) 0x2016EA))

// Message Object 55 Interrupt Pointer Register Low
#define CAN_MOIPR55L           (*((unsigned int volatile huge *) 0x2016E8))

// Message Object 56 Interrupt Pointer Register High
#define CAN_MOIPR56H           (*((unsigned int volatile huge *) 0x20170A))

// Message Object 56 Interrupt Pointer Register Low
#define CAN_MOIPR56L           (*((unsigned int volatile huge *) 0x201708))

// Message Object 57 Interrupt Pointer Register High
#define CAN_MOIPR57H           (*((unsigned int volatile huge *) 0x20172A))

// Message Object 57 Interrupt Pointer Register Low
#define CAN_MOIPR57L           (*((unsigned int volatile huge *) 0x201728))

// Message Object 58 Interrupt Pointer Register High
#define CAN_MOIPR58H           (*((unsigned int volatile huge *) 0x20174A))

// Message Object 58 Interrupt Pointer Register Low
#define CAN_MOIPR58L           (*((unsigned int volatile huge *) 0x201748))

// Message Object 59 Interrupt Pointer Register High
#define CAN_MOIPR59H           (*((unsigned int volatile huge *) 0x20176A))

// Message Object 59 Interrupt Pointer Register Low
#define CAN_MOIPR59L           (*((unsigned int volatile huge *) 0x201768))

// Message Object 5 Interrupt Pointer Register High
#define CAN_MOIPR5H            (*((unsigned int volatile huge *) 0x2010AA))

// Message Object 5 Interrupt Pointer Register Low
#define CAN_MOIPR5L            (*((unsigned int volatile huge *) 0x2010A8))

// Message Object 60 Interrupt Pointer Register High
#define CAN_MOIPR60H           (*((unsigned int volatile huge *) 0x20178A))

// Message Object 60 Interrupt Pointer Register Low
#define CAN_MOIPR60L           (*((unsigned int volatile huge *) 0x201788))

// Message Object 61 Interrupt Pointer Register High
#define CAN_MOIPR61H           (*((unsigned int volatile huge *) 0x2017AA))

// Message Object 61 Interrupt Pointer Register Low
#define CAN_MOIPR61L           (*((unsigned int volatile huge *) 0x2017A8))

// Message Object 62 Interrupt Pointer Register High
#define CAN_MOIPR62H           (*((unsigned int volatile huge *) 0x2017CA))

// Message Object 62 Interrupt Pointer Register Low
#define CAN_MOIPR62L           (*((unsigned int volatile huge *) 0x2017C8))

// Message Object 63 Interrupt Pointer Register High
#define CAN_MOIPR63H           (*((unsigned int volatile huge *) 0x2017EA))

// Message Object 63 Interrupt Pointer Register Low
#define CAN_MOIPR63L           (*((unsigned int volatile huge *) 0x2017E8))

// Message Object 64 Interrupt Pointer Register High
#define CAN_MOIPR64H           (*((unsigned int volatile huge *) 0x20180A))

// Message Object 64 Interrupt Pointer Register Low
#define CAN_MOIPR64L           (*((unsigned int volatile huge *) 0x201808))

// Message Object 65 Interrupt Pointer Register High
#define CAN_MOIPR65H           (*((unsigned int volatile huge *) 0x20182A))

// Message Object 65 Interrupt Pointer Register Low
#define CAN_MOIPR65L           (*((unsigned int volatile huge *) 0x201828))

// Message Object 66 Interrupt Pointer Register High
#define CAN_MOIPR66H           (*((unsigned int volatile huge *) 0x20184A))

// Message Object 66 Interrupt Pointer Register Low
#define CAN_MOIPR66L           (*((unsigned int volatile huge *) 0x201848))

// Message Object 67 Interrupt Pointer Register High
#define CAN_MOIPR67H           (*((unsigned int volatile huge *) 0x20186A))

// Message Object 67 Interrupt Pointer Register Low
#define CAN_MOIPR67L           (*((unsigned int volatile huge *) 0x201868))

// Message Object 68 Interrupt Pointer Register High
#define CAN_MOIPR68H           (*((unsigned int volatile huge *) 0x20188A))

// Message Object 68 Interrupt Pointer Register Low
#define CAN_MOIPR68L           (*((unsigned int volatile huge *) 0x201888))

// Message Object 69 Interrupt Pointer Register High
#define CAN_MOIPR69H           (*((unsigned int volatile huge *) 0x2018AA))

// Message Object 69 Interrupt Pointer Register Low
#define CAN_MOIPR69L           (*((unsigned int volatile huge *) 0x2018A8))

// Message Object 6 Interrupt Pointer Register High
#define CAN_MOIPR6H            (*((unsigned int volatile huge *) 0x2010CA))

// Message Object 6 Interrupt Pointer Register Low
#define CAN_MOIPR6L            (*((unsigned int volatile huge *) 0x2010C8))

// Message Object 70 Interrupt Pointer Register High
#define CAN_MOIPR70H           (*((unsigned int volatile huge *) 0x2018CA))

// Message Object 70 Interrupt Pointer Register Low
#define CAN_MOIPR70L           (*((unsigned int volatile huge *) 0x2018C8))

// Message Object 71 Interrupt Pointer Register High
#define CAN_MOIPR71H           (*((unsigned int volatile huge *) 0x2018EA))

// Message Object 71 Interrupt Pointer Register Low
#define CAN_MOIPR71L           (*((unsigned int volatile huge *) 0x2018E8))

// Message Object 72 Interrupt Pointer Register High
#define CAN_MOIPR72H           (*((unsigned int volatile huge *) 0x20190A))

// Message Object 72 Interrupt Pointer Register Low
#define CAN_MOIPR72L           (*((unsigned int volatile huge *) 0x201908))

// Message Object 73 Interrupt Pointer Register High
#define CAN_MOIPR73H           (*((unsigned int volatile huge *) 0x20192A))

// Message Object 73 Interrupt Pointer Register Low
#define CAN_MOIPR73L           (*((unsigned int volatile huge *) 0x201928))

// Message Object 74 Interrupt Pointer Register High
#define CAN_MOIPR74H           (*((unsigned int volatile huge *) 0x20194A))

// Message Object 74 Interrupt Pointer Register Low
#define CAN_MOIPR74L           (*((unsigned int volatile huge *) 0x201948))

// Message Object 75 Interrupt Pointer Register High
#define CAN_MOIPR75H           (*((unsigned int volatile huge *) 0x20196A))

// Message Object 75 Interrupt Pointer Register Low
#define CAN_MOIPR75L           (*((unsigned int volatile huge *) 0x201968))

// Message Object 76 Interrupt Pointer Register High
#define CAN_MOIPR76H           (*((unsigned int volatile huge *) 0x20198A))

// Message Object 76 Interrupt Pointer Register Low
#define CAN_MOIPR76L           (*((unsigned int volatile huge *) 0x201988))

// Message Object 77 Interrupt Pointer Register High
#define CAN_MOIPR77H           (*((unsigned int volatile huge *) 0x2019AA))

// Message Object 77 Interrupt Pointer Register Low
#define CAN_MOIPR77L           (*((unsigned int volatile huge *) 0x2019A8))

// Message Object 78 Interrupt Pointer Register High
#define CAN_MOIPR78H           (*((unsigned int volatile huge *) 0x2019CA))

// Message Object 78 Interrupt Pointer Register Low
#define CAN_MOIPR78L           (*((unsigned int volatile huge *) 0x2019C8))

// Message Object 79 Interrupt Pointer Register High
#define CAN_MOIPR79H           (*((unsigned int volatile huge *) 0x2019EA))

// Message Object 79 Interrupt Pointer Register Low
#define CAN_MOIPR79L           (*((unsigned int volatile huge *) 0x2019E8))

// Message Object 7 Interrupt Pointer Register High
#define CAN_MOIPR7H            (*((unsigned int volatile huge *) 0x2010EA))

// Message Object 7 Interrupt Pointer Register Low
#define CAN_MOIPR7L            (*((unsigned int volatile huge *) 0x2010E8))

// Message Object 80 Interrupt Pointer Register High
#define CAN_MOIPR80H           (*((unsigned int volatile huge *) 0x201A0A))

// Message Object 80 Interrupt Pointer Register Low
#define CAN_MOIPR80L           (*((unsigned int volatile huge *) 0x201A08))

// Message Object 81 Interrupt Pointer Register High
#define CAN_MOIPR81H           (*((unsigned int volatile huge *) 0x201A2A))

// Message Object 81 Interrupt Pointer Register Low
#define CAN_MOIPR81L           (*((unsigned int volatile huge *) 0x201A28))

// Message Object 82 Interrupt Pointer Register High
#define CAN_MOIPR82H           (*((unsigned int volatile huge *) 0x201A4A))

// Message Object 82 Interrupt Pointer Register Low
#define CAN_MOIPR82L           (*((unsigned int volatile huge *) 0x201A48))

// Message Object 83 Interrupt Pointer Register High
#define CAN_MOIPR83H           (*((unsigned int volatile huge *) 0x201A6A))

// Message Object 83 Interrupt Pointer Register Low
#define CAN_MOIPR83L           (*((unsigned int volatile huge *) 0x201A68))

// Message Object 84 Interrupt Pointer Register High
#define CAN_MOIPR84H           (*((unsigned int volatile huge *) 0x201A8A))

// Message Object 84 Interrupt Pointer Register Low
#define CAN_MOIPR84L           (*((unsigned int volatile huge *) 0x201A88))

// Message Object 85 Interrupt Pointer Register High
#define CAN_MOIPR85H           (*((unsigned int volatile huge *) 0x201AAA))

// Message Object 85 Interrupt Pointer Register Low
#define CAN_MOIPR85L           (*((unsigned int volatile huge *) 0x201AA8))

// Message Object 86 Interrupt Pointer Register High
#define CAN_MOIPR86H           (*((unsigned int volatile huge *) 0x201ACA))

// Message Object 86 Interrupt Pointer Register Low
#define CAN_MOIPR86L           (*((unsigned int volatile huge *) 0x201AC8))

// Message Object 87 Interrupt Pointer Register High
#define CAN_MOIPR87H           (*((unsigned int volatile huge *) 0x201AEA))

// Message Object 87 Interrupt Pointer Register Low
#define CAN_MOIPR87L           (*((unsigned int volatile huge *) 0x201AE8))

// Message Object 88 Interrupt Pointer Register High
#define CAN_MOIPR88H           (*((unsigned int volatile huge *) 0x201B0A))

// Message Object 88 Interrupt Pointer Register Low
#define CAN_MOIPR88L           (*((unsigned int volatile huge *) 0x201B08))

// Message Object 89 Interrupt Pointer Register High
#define CAN_MOIPR89H           (*((unsigned int volatile huge *) 0x201B2A))

// Message Object 89 Interrupt Pointer Register Low
#define CAN_MOIPR89L           (*((unsigned int volatile huge *) 0x201B28))

// Message Object 8 Interrupt Pointer Register High
#define CAN_MOIPR8H            (*((unsigned int volatile huge *) 0x20110A))

// Message Object 8 Interrupt Pointer Register Low
#define CAN_MOIPR8L            (*((unsigned int volatile huge *) 0x201108))

// Message Object 90 Interrupt Pointer Register High
#define CAN_MOIPR90H           (*((unsigned int volatile huge *) 0x201B4A))

// Message Object 90 Interrupt Pointer Register Low
#define CAN_MOIPR90L           (*((unsigned int volatile huge *) 0x201B48))

// Message Object 91 Interrupt Pointer Register High
#define CAN_MOIPR91H           (*((unsigned int volatile huge *) 0x201B6A))

// Message Object 91 Interrupt Pointer Register Low
#define CAN_MOIPR91L           (*((unsigned int volatile huge *) 0x201B68))

// Message Object 92 Interrupt Pointer Register High
#define CAN_MOIPR92H           (*((unsigned int volatile huge *) 0x201B8A))

// Message Object 92 Interrupt Pointer Register Low
#define CAN_MOIPR92L           (*((unsigned int volatile huge *) 0x201B88))

// Message Object 93 Interrupt Pointer Register High
#define CAN_MOIPR93H           (*((unsigned int volatile huge *) 0x201BAA))

// Message Object 93 Interrupt Pointer Register Low
#define CAN_MOIPR93L           (*((unsigned int volatile huge *) 0x201BA8))

// Message Object 94 Interrupt Pointer Register High
#define CAN_MOIPR94H           (*((unsigned int volatile huge *) 0x201BCA))

// Message Object 94 Interrupt Pointer Register Low
#define CAN_MOIPR94L           (*((unsigned int volatile huge *) 0x201BC8))

// Message Object 95 Interrupt Pointer Register High
#define CAN_MOIPR95H           (*((unsigned int volatile huge *) 0x201BEA))

// Message Object 95 Interrupt Pointer Register Low
#define CAN_MOIPR95L           (*((unsigned int volatile huge *) 0x201BE8))

// Message Object 96 Interrupt Pointer Register High
#define CAN_MOIPR96H           (*((unsigned int volatile huge *) 0x201C0A))

// Message Object 96 Interrupt Pointer Register Low
#define CAN_MOIPR96L           (*((unsigned int volatile huge *) 0x201C08))

// Message Object 97 Interrupt Pointer Register High
#define CAN_MOIPR97H           (*((unsigned int volatile huge *) 0x201C2A))

// Message Object 97 Interrupt Pointer Register Low
#define CAN_MOIPR97L           (*((unsigned int volatile huge *) 0x201C28))

// Message Object 98 Interrupt Pointer Register High
#define CAN_MOIPR98H           (*((unsigned int volatile huge *) 0x201C4A))

// Message Object 98 Interrupt Pointer Register Low
#define CAN_MOIPR98L           (*((unsigned int volatile huge *) 0x201C48))

// Message Object 99 Interrupt Pointer Register High
#define CAN_MOIPR99H           (*((unsigned int volatile huge *) 0x201C6A))

// Message Object 99 Interrupt Pointer Register Low
#define CAN_MOIPR99L           (*((unsigned int volatile huge *) 0x201C68))

// Message Object 9 Interrupt Pointer Register High
#define CAN_MOIPR9H            (*((unsigned int volatile huge *) 0x20112A))

// Message Object 9 Interrupt Pointer Register Low
#define CAN_MOIPR9L            (*((unsigned int volatile huge *) 0x201128))

// Message Index Register 0
#define CAN_MSID0              (*((unsigned int volatile huge *) 0x200180))

// Message Index Register 1
#define CAN_MSID1              (*((unsigned int volatile huge *) 0x200184))

// Message Index Register 2
#define CAN_MSID2              (*((unsigned int volatile huge *) 0x200188))

// Message Index Register 3
#define CAN_MSID3              (*((unsigned int volatile huge *) 0x20018C))

// Message Index Register 4
#define CAN_MSID4              (*((unsigned int volatile huge *) 0x200190))

// Message Index Register 5
#define CAN_MSID5              (*((unsigned int volatile huge *) 0x200194))

// Message Index Register 6
#define CAN_MSID6              (*((unsigned int volatile huge *) 0x200198))

// Message Index Register 7
#define CAN_MSID7              (*((unsigned int volatile huge *) 0x20019C))

// Message Index Mask Register High
#define CAN_MSIMASKH           (*((unsigned int volatile huge *) 0x2001C2))

// Message Index Mask Register Low
#define CAN_MSIMASKL           (*((unsigned int volatile huge *) 0x2001C0))

// Message Pending Register 0 High
#define CAN_MSPND0H            (*((unsigned int volatile huge *) 0x200142))

// Message Pending Register 0 Low
#define CAN_MSPND0L            (*((unsigned int volatile huge *) 0x200140))

// Message Pending Register 1 High
#define CAN_MSPND1H            (*((unsigned int volatile huge *) 0x200146))

// Message Pending Register 1 Low
#define CAN_MSPND1L            (*((unsigned int volatile huge *) 0x200144))

// Message Pending Register 2 High
#define CAN_MSPND2H            (*((unsigned int volatile huge *) 0x20014A))

// Message Pending Register 2 Low
#define CAN_MSPND2L            (*((unsigned int volatile huge *) 0x200148))

// Message Pending Register 3 High
#define CAN_MSPND3H            (*((unsigned int volatile huge *) 0x20014E))

// Message Pending Register 3 Low
#define CAN_MSPND3L            (*((unsigned int volatile huge *) 0x20014C))

// Message Pending Register 4 High
#define CAN_MSPND4H            (*((unsigned int volatile huge *) 0x200152))

// Message Pending Register 4 Low
#define CAN_MSPND4L            (*((unsigned int volatile huge *) 0x200150))

// Message Pending Register 5 High
#define CAN_MSPND5H            (*((unsigned int volatile huge *) 0x200156))

// Message Pending Register 5 Low
#define CAN_MSPND5L            (*((unsigned int volatile huge *) 0x200154))

// Message Pending Register 6 High
#define CAN_MSPND6H            (*((unsigned int volatile huge *) 0x20015A))

// Message Pending Register 6 Low
#define CAN_MSPND6L            (*((unsigned int volatile huge *) 0x200158))

// Message Pending Register 7 High
#define CAN_MSPND7H            (*((unsigned int volatile huge *) 0x20015E))

// Message Pending Register 7 Low
#define CAN_MSPND7L            (*((unsigned int volatile huge *) 0x20015C))

// Node 0 Bit Timing Register High
#define CAN_NBTR0H             (*((unsigned int volatile huge *) 0x200212))

// Node 0 Bit Timing Register Low
#define CAN_NBTR0L             (*((unsigned int volatile huge *) 0x200210))

// Node 1 Bit Timing Register High
#define CAN_NBTR1H             (*((unsigned int volatile huge *) 0x200312))

// Node 1 Bit Timing Register Low
#define CAN_NBTR1L             (*((unsigned int volatile huge *) 0x200310))

// Node 2 Bit Timing Register High
#define CAN_NBTR2H             (*((unsigned int volatile huge *) 0x200412))

// Node 2 Bit Timing Register Low
#define CAN_NBTR2L             (*((unsigned int volatile huge *) 0x200410))

// Node 3 Bit Timing Register High
#define CAN_NBTR3H             (*((unsigned int volatile huge *) 0x200512))

// Node 3 Bit Timing Register Low
#define CAN_NBTR3L             (*((unsigned int volatile huge *) 0x200510))

// Node 4 Bit Timing Register High
#define CAN_NBTR4H             (*((unsigned int volatile huge *) 0x200612))

// Node 4 Bit Timing Register Low
#define CAN_NBTR4L             (*((unsigned int volatile huge *) 0x200610))

// Node 0 Control Register
#define CAN_NCR0               (*((unsigned int volatile huge *) 0x200200))

// Node 1 Control Register
#define CAN_NCR1               (*((unsigned int volatile huge *) 0x200300))

// Node 2 Control Register
#define CAN_NCR2               (*((unsigned int volatile huge *) 0x200400))

// Node 3 Control Register
#define CAN_NCR3               (*((unsigned int volatile huge *) 0x200500))

// Node 4 Control Register
#define CAN_NCR4               (*((unsigned int volatile huge *) 0x200600))

// Node 0 Error Counter Register High
#define CAN_NECNT0H            (*((unsigned int volatile huge *) 0x200216))

// Node 0 Error Counter Register Low
#define CAN_NECNT0L            (*((unsigned int volatile huge *) 0x200214))

// Node 1 Error Counter Register High
#define CAN_NECNT1H            (*((unsigned int volatile huge *) 0x200316))

// Node 1 Error Counter Register Low
#define CAN_NECNT1L            (*((unsigned int volatile huge *) 0x200314))

// Node 2 Error Counter Register High
#define CAN_NECNT2H            (*((unsigned int volatile huge *) 0x200416))

// Node 2 Error Counter Register Low
#define CAN_NECNT2L            (*((unsigned int volatile huge *) 0x200414))

// Node 3 Error Counter Register High
#define CAN_NECNT3H            (*((unsigned int volatile huge *) 0x200516))

// Node 3 Error Counter Register Low
#define CAN_NECNT3L            (*((unsigned int volatile huge *) 0x200514))

// Node 4 Error Counter Register High
#define CAN_NECNT4H            (*((unsigned int volatile huge *) 0x200616))

// Node 4 Error Counter Register Low
#define CAN_NECNT4L            (*((unsigned int volatile huge *) 0x200614))

// Node 0 Frame Counter Register High
#define CAN_NFCR0H             (*((unsigned int volatile huge *) 0x20021A))

// Node 0 Frame Counter Register Low
#define CAN_NFCR0L             (*((unsigned int volatile huge *) 0x200218))

// Node 1 Frame Counter Register High
#define CAN_NFCR1H             (*((unsigned int volatile huge *) 0x20031A))

// Node 1 Frame Counter Register Low
#define CAN_NFCR1L             (*((unsigned int volatile huge *) 0x200318))

// Node 2 Frame Counter Register High
#define CAN_NFCR2H             (*((unsigned int volatile huge *) 0x20041A))

// Node 2 Frame Counter Register Low
#define CAN_NFCR2L             (*((unsigned int volatile huge *) 0x200418))

// Node 3 Frame Counter Register High
#define CAN_NFCR3H             (*((unsigned int volatile huge *) 0x20051A))

// Node 3 Frame Counter Register Low
#define CAN_NFCR3L             (*((unsigned int volatile huge *) 0x200518))

// Node 4 Frame Counter Register High
#define CAN_NFCR4H             (*((unsigned int volatile huge *) 0x20061A))

// Node 4 Frame Counter Register Low
#define CAN_NFCR4L             (*((unsigned int volatile huge *) 0x200618))

// Node 0 Interrupt Pointer Register
#define CAN_NIPR0              (*((unsigned int volatile huge *) 0x200208))

// Node 1 Interrupt Pointer Register
#define CAN_NIPR1              (*((unsigned int volatile huge *) 0x200308))

// Node 2 Interrupt Pointer Register
#define CAN_NIPR2              (*((unsigned int volatile huge *) 0x200408))

// Node 3 Interrupt Pointer Register
#define CAN_NIPR3              (*((unsigned int volatile huge *) 0x200508))

// Node 4 Interrupt Pointer Register
#define CAN_NIPR4              (*((unsigned int volatile huge *) 0x200608))

// Node 0 Port Control Register
#define CAN_NPCR0              (*((unsigned int volatile huge *) 0x20020C))

// Node 1 Port Control Register
#define CAN_NPCR1              (*((unsigned int volatile huge *) 0x20030C))

// Node 2 Port Control Register
#define CAN_NPCR2              (*((unsigned int volatile huge *) 0x20040C))

// Node 3 Port Control Register
#define CAN_NPCR3              (*((unsigned int volatile huge *) 0x20050C))

// Node 4 Port Control Register
#define CAN_NPCR4              (*((unsigned int volatile huge *) 0x20060C))

// Node 0 Status Register
#define CAN_NSR0               (*((unsigned int volatile huge *) 0x200204))

// Node 1 Status Register
#define CAN_NSR1               (*((unsigned int volatile huge *) 0x200304))

// Node 2 Status Register
#define CAN_NSR2               (*((unsigned int volatile huge *) 0x200404))

// Node 3 Status Register
#define CAN_NSR3               (*((unsigned int volatile huge *) 0x200504))

// Node 4 Status Register
#define CAN_NSR4               (*((unsigned int volatile huge *) 0x200604))

// Panel Control Register
#define CAN_PANCTRH            (*((unsigned int volatile huge *) 0x2001C6))

// Panel Control Register
#define CAN_PANCTRL            (*((unsigned int volatile huge *) 0x2001C4))

// Capture/Compare Register 16
sfr  CC2_CC16                         = 0xFE60;

// CAPCOM Interrupt Control Reg. 16
sfr  CC2_CC16IC                       = 0xF1C0;
sbit CC2_CC16IC_GPX                      = CC2_CC16IC^8;
sbit CC2_CC16IC_IE                       = CC2_CC16IC^6;
sbit CC2_CC16IC_IR                       = CC2_CC16IC^7;

// Capture/Compare Register 17
sfr  CC2_CC17                         = 0xFE62;

// CAPCOM Interrupt Control Reg. 17
sfr  CC2_CC17IC                       = 0xF1C2;
sbit CC2_CC17IC_GPX                      = CC2_CC17IC^8;
sbit CC2_CC17IC_IE                       = CC2_CC17IC^6;
sbit CC2_CC17IC_IR                       = CC2_CC17IC^7;

// Capture/Compare Register 18
sfr  CC2_CC18                         = 0xFE64;

// CAPCOM Interrupt Control Reg. 18
sfr  CC2_CC18IC                       = 0xF1C4;
sbit CC2_CC18IC_GPX                      = CC2_CC18IC^8;
sbit CC2_CC18IC_IE                       = CC2_CC18IC^6;
sbit CC2_CC18IC_IR                       = CC2_CC18IC^7;

// Capture/Compare Register 19
sfr  CC2_CC19                         = 0xFE66;

// CAPCOM Interrupt Control Reg. 19
sfr  CC2_CC19IC                       = 0xF1C6;
sbit CC2_CC19IC_GPX                      = CC2_CC19IC^8;
sbit CC2_CC19IC_IE                       = CC2_CC19IC^6;
sbit CC2_CC19IC_IR                       = CC2_CC19IC^7;

// Capture/Compare Register 20
sfr  CC2_CC20                         = 0xFE68;

// CAPCOM Interrupt Control Reg. 20
sfr  CC2_CC20IC                       = 0xF1C8;
sbit CC2_CC20IC_GPX                      = CC2_CC20IC^8;
sbit CC2_CC20IC_IE                       = CC2_CC20IC^6;
sbit CC2_CC20IC_IR                       = CC2_CC20IC^7;

// Capture/Compare Register 21
sfr  CC2_CC21                         = 0xFE6A;

// CAPCOM Interrupt Control Reg. 21
sfr  CC2_CC21IC                       = 0xF1CA;
sbit CC2_CC21IC_GPX                      = CC2_CC21IC^8;
sbit CC2_CC21IC_IE                       = CC2_CC21IC^6;
sbit CC2_CC21IC_IR                       = CC2_CC21IC^7;

// Capture/Compare Register 22
sfr  CC2_CC22                         = 0xFE6C;

// CAPCOM Interrupt Control Reg. 22
sfr  CC2_CC22IC                       = 0xF1CC;
sbit CC2_CC22IC_GPX                      = CC2_CC22IC^8;
sbit CC2_CC22IC_IE                       = CC2_CC22IC^6;
sbit CC2_CC22IC_IR                       = CC2_CC22IC^7;

// Capture/Compare Register 23
sfr  CC2_CC23                         = 0xFE6E;

// CAPCOM Interrupt Control Reg. 23
sfr  CC2_CC23IC                       = 0xF1CE;
sbit CC2_CC23IC_GPX                      = CC2_CC23IC^8;
sbit CC2_CC23IC_IE                       = CC2_CC23IC^6;
sbit CC2_CC23IC_IR                       = CC2_CC23IC^7;

// Capture/Compare Register 24
sfr  CC2_CC24                         = 0xFE70;

// CAPCOM Interrupt Control Reg. 24
sfr  CC2_CC24IC                       = 0xF1D0;
sbit CC2_CC24IC_GPX                      = CC2_CC24IC^8;
sbit CC2_CC24IC_IE                       = CC2_CC24IC^6;
sbit CC2_CC24IC_IR                       = CC2_CC24IC^7;

// Capture/Compare Register 25
sfr  CC2_CC25                         = 0xFE72;

// CAPCOM Interrupt Control Reg. 25
sfr  CC2_CC25IC                       = 0xF1D2;
sbit CC2_CC25IC_GPX                      = CC2_CC25IC^8;
sbit CC2_CC25IC_IE                       = CC2_CC25IC^6;
sbit CC2_CC25IC_IR                       = CC2_CC25IC^7;

// Capture/Compare Register 26
sfr  CC2_CC26                         = 0xFE74;

// CAPCOM Interrupt Control Reg. 26
sfr  CC2_CC26IC                       = 0xF1D4;
sbit CC2_CC26IC_GPX                      = CC2_CC26IC^8;
sbit CC2_CC26IC_IE                       = CC2_CC26IC^6;
sbit CC2_CC26IC_IR                       = CC2_CC26IC^7;

// Capture/Compare Register 27
sfr  CC2_CC27                         = 0xFE76;

// CAPCOM Interrupt Control Reg. 27
sfr  CC2_CC27IC                       = 0xF1D6;
sbit CC2_CC27IC_GPX                      = CC2_CC27IC^8;
sbit CC2_CC27IC_IE                       = CC2_CC27IC^6;
sbit CC2_CC27IC_IR                       = CC2_CC27IC^7;

// Capture/Compare Register 28
sfr  CC2_CC28                         = 0xFE78;

// CAPCOM Interrupt Control Reg. 28
sfr  CC2_CC28IC                       = 0xF1D8;
sbit CC2_CC28IC_GPX                      = CC2_CC28IC^8;
sbit CC2_CC28IC_IE                       = CC2_CC28IC^6;
sbit CC2_CC28IC_IR                       = CC2_CC28IC^7;

// Capture/Compare Register 29
sfr  CC2_CC29                         = 0xFE7A;

// CAPCOM Interrupt Control Reg. 29
sfr  CC2_CC29IC                       = 0xF1DA;
sbit CC2_CC29IC_GPX                      = CC2_CC29IC^8;
sbit CC2_CC29IC_IE                       = CC2_CC29IC^6;
sbit CC2_CC29IC_IR                       = CC2_CC29IC^7;

// Capture/Compare Register 30
sfr  CC2_CC30                         = 0xFE7C;

// CAPCOM Interrupt Control Reg. 30
sfr  CC2_CC30IC                       = 0xF1DC;
sbit CC2_CC30IC_GPX                      = CC2_CC30IC^8;
sbit CC2_CC30IC_IE                       = CC2_CC30IC^6;
sbit CC2_CC30IC_IR                       = CC2_CC30IC^7;

// Capture/Compare Register 31
sfr  CC2_CC31                         = 0xFE7E;

// CAPCOM Interrupt Control Reg. 31
sfr  CC2_CC31IC                       = 0xF1DE;
sbit CC2_CC31IC_GPX                      = CC2_CC31IC^8;
sbit CC2_CC31IC_IE                       = CC2_CC31IC^6;
sbit CC2_CC31IC_IR                       = CC2_CC31IC^7;

// Double-Register Compare Mode Register
sfr  CC2_DRM                          = 0xFF2A;

// I/O Control Register
sfr  CC2_IOC                          = 0xF066;

// CC2 Kernel State Con. Register
sfr  CC2_KSCCFG                       = 0xFE24;

// Capture/Compare Mode Registers for the CAPCOM Unit [CC16...CC19]
sfr  CC2_M4                           = 0xFF22;
sbit CC2_M4_ACC16                    = CC2_M4^3;
sbit CC2_M4_ACC17                    = CC2_M4^7;
sbit CC2_M4_ACC18                    = CC2_M4^11;
sbit CC2_M4_ACC19                    = CC2_M4^15;

// Capture/Compare Mode Registers for the CAPCOM Unit [CC20...CC23]
sfr  CC2_M5                           = 0xFF24;
sbit CC2_M5_ACC20                    = CC2_M5^3;
sbit CC2_M5_ACC21                    = CC2_M5^7;
sbit CC2_M5_ACC22                    = CC2_M5^11;
sbit CC2_M5_ACC23                    = CC2_M5^15;

// Capture/Compare Mode Registers for the CAPCOM Unit [CC24...CC27]
sfr  CC2_M6                           = 0xFF26;
sbit CC2_M6_ACC24                    = CC2_M6^3;
sbit CC2_M6_ACC25                    = CC2_M6^7;
sbit CC2_M6_ACC26                    = CC2_M6^11;
sbit CC2_M6_ACC27                    = CC2_M6^15;

// Capture/Compare Mode Registers for the CAPCOM Unit [CC28...CC31]
sfr  CC2_M7                           = 0xFF28;
sbit CC2_M7_ACC28                    = CC2_M7^3;
sbit CC2_M7_ACC29                    = CC2_M7^7;
sbit CC2_M7_ACC30                    = CC2_M7^11;
sbit CC2_M7_ACC31                    = CC2_M7^15;

// Compare Output Register
sfr  CC2_OUT                          = 0xFF2C;
sbit CC2_OUT_CC0IO                    = CC2_OUT^0;
sbit CC2_OUT_CC10IO                   = CC2_OUT^10;
sbit CC2_OUT_CC11IO                   = CC2_OUT^11;
sbit CC2_OUT_CC12IO                   = CC2_OUT^12;
sbit CC2_OUT_CC13IO                   = CC2_OUT^13;
sbit CC2_OUT_CC14IO                   = CC2_OUT^14;
sbit CC2_OUT_CC15IO                   = CC2_OUT^15;
sbit CC2_OUT_CC1IO                    = CC2_OUT^1;
sbit CC2_OUT_CC2IO                    = CC2_OUT^2;
sbit CC2_OUT_CC3IO                    = CC2_OUT^3;
sbit CC2_OUT_CC4IO                    = CC2_OUT^4;
sbit CC2_OUT_CC5IO                    = CC2_OUT^5;
sbit CC2_OUT_CC6IO                    = CC2_OUT^6;
sbit CC2_OUT_CC7IO                    = CC2_OUT^7;
sbit CC2_OUT_CC8IO                    = CC2_OUT^8;
sbit CC2_OUT_CC9IO                    = CC2_OUT^9;

// Single Event Enable Register
sfr  CC2_SEE                          = 0xFE2A;

// Single Event Mode Register
sfr  CC2_SEM                          = 0xFE28;

// Timer 7 Register
sfr  CC2_T7                           = 0xF050;

// Timer 7/8 Control Register
sfr  CC2_T78CON                       = 0xFF20;
sbit CC2_T78CON_T7M                      = CC2_T78CON^3;
sbit CC2_T78CON_T7R                      = CC2_T78CON^6;
sbit CC2_T78CON_T8M                      = CC2_T78CON^11;
sbit CC2_T78CON_T8R                      = CC2_T78CON^14;

// CAPCOM TIMER 7 IC
sfr  CC2_T7IC                         = 0xFF6C;
sbit CC2_T7IC_GPX                      = CC2_T7IC^8;
sbit CC2_T7IC_IE                       = CC2_T7IC^6;
sbit CC2_T7IC_IR                       = CC2_T7IC^7;

// Timer 7 Reload Register
sfr  CC2_T7REL                        = 0xF054;

// Timer 8 Register
sfr  CC2_T8                           = 0xF052;

// CAPCOM TIMER 8 IC
sfr  CC2_T8IC                         = 0xFF6E;
sbit CC2_T8IC_GPX                      = CC2_T8IC^8;
sbit CC2_T8IC_IE                       = CC2_T8IC^6;
sbit CC2_T8IC_IR                       = CC2_T8IC^7;

// Timer 8 Reload Register
sfr  CC2_T8REL                        = 0xF056;

// CCU60 Interrupt Control Reg. 0
sfr  CCU60_0IC                        = 0xF160;
sbit CCU60_0IC_GPX                      = CCU60_0IC^8;
sbit CCU60_0IC_IE                       = CCU60_0IC^6;
sbit CCU60_0IC_IR                       = CCU60_0IC^7;

// CCU60 Interrupt Control Reg. 1
sfr  CCU60_1IC                        = 0xF162;
sbit CCU60_1IC_GPX                      = CCU60_1IC^8;
sbit CCU60_1IC_IE                       = CCU60_1IC^6;
sbit CCU60_1IC_IR                       = CCU60_1IC^7;

// CCU60 Interrupt Control Reg. 2
sfr  CCU60_2IC                        = 0xF164;
sbit CCU60_2IC_GPX                      = CCU60_2IC^8;
sbit CCU60_2IC_IE                       = CCU60_2IC^6;
sbit CCU60_2IC_IR                       = CCU60_2IC^7;

// CCU60 Interrupt Control Reg. 3
sfr  CCU60_3IC                        = 0xF166;
sbit CCU60_3IC_GPX                      = CCU60_3IC^8;
sbit CCU60_3IC_IE                       = CCU60_3IC^6;
sbit CCU60_3IC_IR                       = CCU60_3IC^7;

// Capture/Compare Register for Channel CC60
#define CCU60_CC60R            (*((unsigned int volatile sdata *) 0xEA18))

// Capture/Compare Shadow Reg. for Channel CC60
#define CCU60_CC60SR           (*((unsigned int volatile sdata *) 0xEA20))

// Capture/Compare Register for Channel CC61
#define CCU60_CC61R            (*((unsigned int volatile sdata *) 0xEA1A))

// Capture/Compare Shadow Reg. for Channel CC61
#define CCU60_CC61SR           (*((unsigned int volatile sdata *) 0xEA22))

// Capture/Compare Register for Channel CC62
#define CCU60_CC62R            (*((unsigned int volatile sdata *) 0xEA1C))

// Capture/Compare Shadow Reg. for Channel CC62
#define CCU60_CC62SR           (*((unsigned int volatile sdata *) 0xEA24))

// Compare Register for T13
#define CCU60_CC63R            (*((unsigned int volatile sdata *) 0xEA34))

// Compare Shadow Register for T13
#define CCU60_CC63SR           (*((unsigned int volatile sdata *) 0xEA36))

// Compare State Modification Register
#define CCU60_CMPMODIF         (*((unsigned int volatile sdata *) 0xEA2A))

// Compare State Register
#define CCU60_CMPSTAT          (*((unsigned int volatile sdata *) 0xEA28))

// Interrupt Enable Register
#define CCU60_IEN              (*((unsigned int volatile sdata *) 0xEA58))

// Interrupt Node Pointer Register
#define CCU60_INP              (*((unsigned int volatile sdata *) 0xEA56))

// Interrupt Status Register
#define CCU60_IS               (*((unsigned int volatile sdata *) 0xEA50))

// Interrupt Status Reset Register
#define CCU60_ISR              (*((unsigned int volatile sdata *) 0xEA54))

// Interrupt Status Set Register
#define CCU60_ISS              (*((unsigned int volatile sdata *) 0xEA52))

// Kernel State Configuration Register
#define CCU60_KSCFG            (*((unsigned int volatile sdata *) 0xEA00))

// Kernel State Control Sensitivity Register
#define CCU60_KSCSR            (*((unsigned int volatile sdata *) 0xEA0E))

// Module Configuration Register
#define CCU60_MCFG             (*((unsigned int volatile sdata *) 0xEA0C))

// Multi-Channel Mode Control Register
#define CCU60_MCMCTR           (*((unsigned int volatile sdata *) 0xEA4E))

// Multi-Channel Mode Output Register
#define CCU60_MCMOUT           (*((unsigned int volatile sdata *) 0xEA4C))

// Multi-Channel Mode Output Shadow Register
#define CCU60_MCMOUTS          (*((unsigned int volatile sdata *) 0xEA4A))

// Modulation Control Register
#define CCU60_MODCTR           (*((unsigned int volatile sdata *) 0xEA40))

// Port Input Select Register High
#define CCU60_PISELH           (*((unsigned int volatile sdata *) 0xEA06))

// Port Input Select Register Low
#define CCU60_PISELL           (*((unsigned int volatile sdata *) 0xEA04))

// Passive State Level Register
#define CCU60_PSLR             (*((unsigned int volatile sdata *) 0xEA44))

// Timer T12 Counter Register
#define CCU60_T12              (*((unsigned int volatile sdata *) 0xEA10))

// Dead-Time Contol Register for Timer12
#define CCU60_T12DTC           (*((unsigned int volatile sdata *) 0xEA14))

// T12 Capture/Compare Mode Select Register
#define CCU60_T12MSEL          (*((unsigned int volatile sdata *) 0xEA46))

// Timer 12 Period Register
#define CCU60_T12PR            (*((unsigned int volatile sdata *) 0xEA12))

// Timer T13 Counter Register
#define CCU60_T13              (*((unsigned int volatile sdata *) 0xEA30))

// Timer 13 Period Register
#define CCU60_T13PR            (*((unsigned int volatile sdata *) 0xEA32))

// Timer Control Register 0
#define CCU60_TCTR0            (*((unsigned int volatile sdata *) 0xEA2C))

// Timer Control Register 2
#define CCU60_TCTR2            (*((unsigned int volatile sdata *) 0xEA2E))

// Timer Control Register 4
#define CCU60_TCTR4            (*((unsigned int volatile sdata *) 0xEA26))

// Trap Control Register
#define CCU60_TRPCTR           (*((unsigned int volatile sdata *) 0xEA42))

// CCU61 Interrupt Control Reg. 0
sfr  CCU61_0IC                        = 0xF168;
sbit CCU61_0IC_GPX                      = CCU61_0IC^8;
sbit CCU61_0IC_IE                       = CCU61_0IC^6;
sbit CCU61_0IC_IR                       = CCU61_0IC^7;

// CCU61 Interrupt Control Reg. 1
sfr  CCU61_1IC                        = 0xF16A;
sbit CCU61_1IC_GPX                      = CCU61_1IC^8;
sbit CCU61_1IC_IE                       = CCU61_1IC^6;
sbit CCU61_1IC_IR                       = CCU61_1IC^7;

// CCU61 Interrupt Control Reg. 2
sfr  CCU61_2IC                        = 0xF16C;
sbit CCU61_2IC_GPX                      = CCU61_2IC^8;
sbit CCU61_2IC_IE                       = CCU61_2IC^6;
sbit CCU61_2IC_IR                       = CCU61_2IC^7;

// CCU61 Interrupt Control Reg. 3
sfr  CCU61_3IC                        = 0xF16E;
sbit CCU61_3IC_GPX                      = CCU61_3IC^8;
sbit CCU61_3IC_IE                       = CCU61_3IC^6;
sbit CCU61_3IC_IR                       = CCU61_3IC^7;

// Capture/Compare Register for Channel CC60
#define CCU61_CC60R            (*((unsigned int volatile sdata *) 0xEA98))

// Capture/Compare Shadow Reg. for Channel CC60
#define CCU61_CC60SR           (*((unsigned int volatile sdata *) 0xEAA0))

// Capture/Compare Register for Channel CC61
#define CCU61_CC61R            (*((unsigned int volatile sdata *) 0xEA9A))

// Capture/Compare Shadow Reg. for Channel CC61
#define CCU61_CC61SR           (*((unsigned int volatile sdata *) 0xEAA2))

// Capture/Compare Register for Channel CC62
#define CCU61_CC62R            (*((unsigned int volatile sdata *) 0xEA9C))

// Capture/Compare Shadow Reg. for Channel CC62
#define CCU61_CC62SR           (*((unsigned int volatile sdata *) 0xEAA4))

// Compare Register for T13
#define CCU61_CC63R            (*((unsigned int volatile sdata *) 0xEAB4))

// Compare Shadow Register for T13
#define CCU61_CC63SR           (*((unsigned int volatile sdata *) 0xEAB6))

// Compare State Modification Register
#define CCU61_CMPMODIF         (*((unsigned int volatile sdata *) 0xEAAA))

// Compare State Register
#define CCU61_CMPSTAT          (*((unsigned int volatile sdata *) 0xEAA8))

// Interrupt Enable Register
#define CCU61_IEN              (*((unsigned int volatile sdata *) 0xEAD8))

// Interrupt Node Pointer Register
#define CCU61_INP              (*((unsigned int volatile sdata *) 0xEAD6))

// Interrupt Status Register
#define CCU61_IS               (*((unsigned int volatile sdata *) 0xEAD0))

// Interrupt Status Reset Register
#define CCU61_ISR              (*((unsigned int volatile sdata *) 0xEAD4))

// Interrupt Status Set Register
#define CCU61_ISS              (*((unsigned int volatile sdata *) 0xEAD2))

// Kernel State Configuration Register
#define CCU61_KSCFG            (*((unsigned int volatile sdata *) 0xEA80))

// Kernel State Control Sensitivity Register
#define CCU61_KSCSR            (*((unsigned int volatile sdata *) 0xEA8E))

// Module Configuration Register
#define CCU61_MCFG             (*((unsigned int volatile sdata *) 0xEA8C))

// Multi-Channel Mode Control Register
#define CCU61_MCMCTR           (*((unsigned int volatile sdata *) 0xEACE))

// Multi-Channel Mode Output Register
#define CCU61_MCMOUT           (*((unsigned int volatile sdata *) 0xEACC))

// Multi-Channel Mode Output Shadow Register
#define CCU61_MCMOUTS          (*((unsigned int volatile sdata *) 0xEACA))

// Modulation Control Register
#define CCU61_MODCTR           (*((unsigned int volatile sdata *) 0xEAC0))

// Port Input Select Register High
#define CCU61_PISELH           (*((unsigned int volatile sdata *) 0xEA86))

// Port Input Select Register Low
#define CCU61_PISELL           (*((unsigned int volatile sdata *) 0xEA84))

// Passive State Level Register
#define CCU61_PSLR             (*((unsigned int volatile sdata *) 0xEAC4))

// Timer T12 Counter Register
#define CCU61_T12              (*((unsigned int volatile sdata *) 0xEA90))

// Dead-Time Contol Register for Timer12
#define CCU61_T12DTC           (*((unsigned int volatile sdata *) 0xEA94))

// T12 Capture/Compare Mode Select Register
#define CCU61_T12MSEL          (*((unsigned int volatile sdata *) 0xEAC6))

// Timer 12 Period Register
#define CCU61_T12PR            (*((unsigned int volatile sdata *) 0xEA92))

// Timer T13 Counter Register
#define CCU61_T13              (*((unsigned int volatile sdata *) 0xEAB0))

// Timer 13 Period Register
#define CCU61_T13PR            (*((unsigned int volatile sdata *) 0xEAB2))

// Timer Control Register 0
#define CCU61_TCTR0            (*((unsigned int volatile sdata *) 0xEAAC))

// Timer Control Register 2
#define CCU61_TCTR2            (*((unsigned int volatile sdata *) 0xEAAE))

// Timer Control Register 4
#define CCU61_TCTR4            (*((unsigned int volatile sdata *) 0xEAA6))

// Trap Control Register
#define CCU61_TRPCTR           (*((unsigned int volatile sdata *) 0xEAC2))

// CCU62 Interrupt Control Reg. 0
sfr  CCU62_0IC                        = 0xF170;
sbit CCU62_0IC_GPX                      = CCU62_0IC^8;
sbit CCU62_0IC_IE                       = CCU62_0IC^6;
sbit CCU62_0IC_IR                       = CCU62_0IC^7;

// CCU62 Interrupt Control Reg. 1
sfr  CCU62_1IC                        = 0xF172;
sbit CCU62_1IC_GPX                      = CCU62_1IC^8;
sbit CCU62_1IC_IE                       = CCU62_1IC^6;
sbit CCU62_1IC_IR                       = CCU62_1IC^7;

// CCU62 Interrupt Control Reg. 2
sfr  CCU62_2IC                        = 0xF174;
sbit CCU62_2IC_GPX                      = CCU62_2IC^8;
sbit CCU62_2IC_IE                       = CCU62_2IC^6;
sbit CCU62_2IC_IR                       = CCU62_2IC^7;

// CCU62 Interrupt Control Reg. 3
sfr  CCU62_3IC                        = 0xF176;
sbit CCU62_3IC_GPX                      = CCU62_3IC^8;
sbit CCU62_3IC_IE                       = CCU62_3IC^6;
sbit CCU62_3IC_IR                       = CCU62_3IC^7;

// Capture/Compare Register for Channel CC60
#define CCU62_CC60R            (*((unsigned int volatile sdata *) 0xEB18))

// Capture/Compare Shadow Reg. for Channel CC60
#define CCU62_CC60SR           (*((unsigned int volatile sdata *) 0xEB20))

// Capture/Compare Register for Channel CC61
#define CCU62_CC61R            (*((unsigned int volatile sdata *) 0xEB1A))

// Capture/Compare Shadow Reg. for Channel CC61
#define CCU62_CC61SR           (*((unsigned int volatile sdata *) 0xEB22))

// Capture/Compare Register for Channel CC62
#define CCU62_CC62R            (*((unsigned int volatile sdata *) 0xEB1C))

// Capture/Compare Shadow Reg. for Channel CC62
#define CCU62_CC62SR           (*((unsigned int volatile sdata *) 0xEB24))

// Compare Register for T13
#define CCU62_CC63R            (*((unsigned int volatile sdata *) 0xEB34))

// Compare Shadow Register for T13
#define CCU62_CC63SR           (*((unsigned int volatile sdata *) 0xEB36))

// Compare State Modification Register
#define CCU62_CMPMODIF         (*((unsigned int volatile sdata *) 0xEB2A))

// Compare State Register
#define CCU62_CMPSTAT          (*((unsigned int volatile sdata *) 0xEB28))

// Interrupt Enable Register
#define CCU62_IEN              (*((unsigned int volatile sdata *) 0xEB58))

// Interrupt Node Pointer Register
#define CCU62_INP              (*((unsigned int volatile sdata *) 0xEB56))

// Interrupt Status Register
#define CCU62_IS               (*((unsigned int volatile sdata *) 0xEB50))

// Interrupt Status Reset Register
#define CCU62_ISR              (*((unsigned int volatile sdata *) 0xEB54))

// Interrupt Status Set Register
#define CCU62_ISS              (*((unsigned int volatile sdata *) 0xEB52))

// Kernel State Configuration Register
#define CCU62_KSCFG            (*((unsigned int volatile sdata *) 0xEB00))

// Kernel State Control Sensitivity Register
#define CCU62_KSCSR            (*((unsigned int volatile sdata *) 0xEB0E))

// Module Configuration Register
#define CCU62_MCFG             (*((unsigned int volatile sdata *) 0xEB0C))

// Multi-Channel Mode Control Register
#define CCU62_MCMCTR           (*((unsigned int volatile sdata *) 0xEB4E))

// Multi-Channel Mode Output Register
#define CCU62_MCMOUT           (*((unsigned int volatile sdata *) 0xEB4C))

// Multi-Channel Mode Output Shadow Register
#define CCU62_MCMOUTS          (*((unsigned int volatile sdata *) 0xEB4A))

// Modulation Control Register
#define CCU62_MODCTR           (*((unsigned int volatile sdata *) 0xEB40))

// Port Input Select Register High
#define CCU62_PISELH           (*((unsigned int volatile sdata *) 0xEB06))

// Port Input Select Register Low
#define CCU62_PISELL           (*((unsigned int volatile sdata *) 0xEB04))

// Passive State Level Register
#define CCU62_PSLR             (*((unsigned int volatile sdata *) 0xEB44))

// Timer T12 Counter Register
#define CCU62_T12              (*((unsigned int volatile sdata *) 0xEB10))

// Dead-Time Contol Register for Timer12
#define CCU62_T12DTC           (*((unsigned int volatile sdata *) 0xEB14))

// T12 Capture/Compare Mode Select Register
#define CCU62_T12MSEL          (*((unsigned int volatile sdata *) 0xEB46))

// Timer 12 Period Register
#define CCU62_T12PR            (*((unsigned int volatile sdata *) 0xEB12))

// Timer T13 Counter Register
#define CCU62_T13              (*((unsigned int volatile sdata *) 0xEB30))

// Timer 13 Period Register
#define CCU62_T13PR            (*((unsigned int volatile sdata *) 0xEB32))

// Timer Control Register 0
#define CCU62_TCTR0            (*((unsigned int volatile sdata *) 0xEB2C))

// Timer Control Register 2
#define CCU62_TCTR2            (*((unsigned int volatile sdata *) 0xEB2E))

// Timer Control Register 4
#define CCU62_TCTR4            (*((unsigned int volatile sdata *) 0xEB26))

// Trap Control Register
#define CCU62_TRPCTR           (*((unsigned int volatile sdata *) 0xEB42))

// CCU63 Interrupt Control Reg. 0
sfr  CCU63_0IC                        = 0xF178;
sbit CCU63_0IC_GPX                      = CCU63_0IC^8;
sbit CCU63_0IC_IE                       = CCU63_0IC^6;
sbit CCU63_0IC_IR                       = CCU63_0IC^7;

// CCU63 Interrupt Control Reg. 1
sfr  CCU63_1IC                        = 0xF17A;
sbit CCU63_1IC_GPX                      = CCU63_1IC^8;
sbit CCU63_1IC_IE                       = CCU63_1IC^6;
sbit CCU63_1IC_IR                       = CCU63_1IC^7;

// CCU63 Interrupt Control Reg. 2
sfr  CCU63_2IC                        = 0xF17C;
sbit CCU63_2IC_GPX                      = CCU63_2IC^8;
sbit CCU63_2IC_IE                       = CCU63_2IC^6;
sbit CCU63_2IC_IR                       = CCU63_2IC^7;

// CCU63 Interrupt Control Reg. 3
sfr  CCU63_3IC                        = 0xF17E;
sbit CCU63_3IC_GPX                      = CCU63_3IC^8;
sbit CCU63_3IC_IE                       = CCU63_3IC^6;
sbit CCU63_3IC_IR                       = CCU63_3IC^7;

// Capture/Compare Register for Channel CC60
#define CCU63_CC60R            (*((unsigned int volatile sdata *) 0xEB98))

// Capture/Compare Shadow Reg. for Channel CC60
#define CCU63_CC60SR           (*((unsigned int volatile sdata *) 0xEBA0))

// Capture/Compare Register for Channel CC61
#define CCU63_CC61R            (*((unsigned int volatile sdata *) 0xEB9A))

// Capture/Compare Shadow Reg. for Channel CC61
#define CCU63_CC61SR           (*((unsigned int volatile sdata *) 0xEBA2))

// Capture/Compare Register for Channel CC62
#define CCU63_CC62R            (*((unsigned int volatile sdata *) 0xEB9C))

// Capture/Compare Shadow Reg. for Channel CC62
#define CCU63_CC62SR           (*((unsigned int volatile sdata *) 0xEBA4))

// Compare Register for T13
#define CCU63_CC63R            (*((unsigned int volatile sdata *) 0xEBB4))

// Compare Shadow Register for T13
#define CCU63_CC63SR           (*((unsigned int volatile sdata *) 0xEBB6))

// Compare State Modification Register
#define CCU63_CMPMODIF         (*((unsigned int volatile sdata *) 0xEBAA))

// Compare State Register
#define CCU63_CMPSTAT          (*((unsigned int volatile sdata *) 0xEBA8))

// Interrupt Enable Register
#define CCU63_IEN              (*((unsigned int volatile sdata *) 0xEBD8))

// Interrupt Node Pointer Register
#define CCU63_INP              (*((unsigned int volatile sdata *) 0xEBD6))

// Interrupt Status Register
#define CCU63_IS               (*((unsigned int volatile sdata *) 0xEBD0))

// Interrupt Status Reset Register
#define CCU63_ISR              (*((unsigned int volatile sdata *) 0xEBD4))

// Interrupt Status Set Register
#define CCU63_ISS              (*((unsigned int volatile sdata *) 0xEBD2))

// Kernel State Configuration Register
#define CCU63_KSCFG            (*((unsigned int volatile sdata *) 0xEB80))

// Kernel State Control Sensitivity Register
#define CCU63_KSCSR            (*((unsigned int volatile sdata *) 0xEB8E))

// Module Configuration Register
#define CCU63_MCFG             (*((unsigned int volatile sdata *) 0xEB8C))

// Multi-Channel Mode Control Register
#define CCU63_MCMCTR           (*((unsigned int volatile sdata *) 0xEBCE))

// Multi-Channel Mode Output Register
#define CCU63_MCMOUT           (*((unsigned int volatile sdata *) 0xEBCC))

// Multi-Channel Mode Output Shadow Register
#define CCU63_MCMOUTS          (*((unsigned int volatile sdata *) 0xEBCA))

// Modulation Control Register
#define CCU63_MODCTR           (*((unsigned int volatile sdata *) 0xEBC0))

// Port Input Select Register High
#define CCU63_PISELH           (*((unsigned int volatile sdata *) 0xEB86))

// Port Input Select Register Low
#define CCU63_PISELL           (*((unsigned int volatile sdata *) 0xEB84))

// Passive State Level Register
#define CCU63_PSLR             (*((unsigned int volatile sdata *) 0xEBC4))

// Timer T12 Counter Register
#define CCU63_T12              (*((unsigned int volatile sdata *) 0xEB90))

// Dead-Time Contol Register for Timer12
#define CCU63_T12DTC           (*((unsigned int volatile sdata *) 0xEB94))

// T12 Capture/Compare Mode Select Register
#define CCU63_T12MSEL          (*((unsigned int volatile sdata *) 0xEBC6))

// Timer 12 Period Register
#define CCU63_T12PR            (*((unsigned int volatile sdata *) 0xEB92))

// Timer T13 Counter Register
#define CCU63_T13              (*((unsigned int volatile sdata *) 0xEBB0))

// Timer 13 Period Register
#define CCU63_T13PR            (*((unsigned int volatile sdata *) 0xEBB2))

// Timer Control Register 0
#define CCU63_TCTR0            (*((unsigned int volatile sdata *) 0xEBAC))

// Timer Control Register 2
#define CCU63_TCTR2            (*((unsigned int volatile sdata *) 0xEBAE))

// Timer Control Register 4
#define CCU63_TCTR4            (*((unsigned int volatile sdata *) 0xEBA6))

// Trap Control Register
#define CCU63_TRPCTR           (*((unsigned int volatile sdata *) 0xEBC2))

// Monitor target ADdress register
sfr  CMADR                            = 0xF0F8;

// Monitor Control and Break Level register
sfr  CMCTR                            = 0xF0FA;

// COMDATA in Monitor Controlled Tracing Mode
sfr  COMDATA                          = 0xF068;

// Data Register in Communication Mode
sfr  COMDATA                          = 0xF068;

// Context Pointer
sfr  CP                               = 0xFE10;

// CPU Control Register 1
sfr  CPUCON1                          = 0xFE18;

// CPU Control Register 2
sfr  CPUCON2                          = 0xFE1A;

// Code Segment Pointer
sfr  CSP                              = 0xFE08;

// Debug Status Register
sfr  DBGSR                            = 0xF0FC;

// Data Compare Data Programming register
sfr  DCMPDP                           = 0xF0EE;

// Data Compare Select Programming register
sfr  DCMPSP                           = 0xF0EC;

// Break Pin Event Control Register
sfr  DEXEVT                           = 0xF0F2;

// Data Page Pointer 0
sfr  DPP0                             = 0xFE00;

// Data Page Pointer 1
sfr  DPP1                             = 0xFE02;

// Data Page Pointer 2
sfr  DPP2                             = 0xFE04;

// Data Page Pointer 3
sfr  DPP3                             = 0xFE06;

// PEC Destination Pointer 0
#define DSTP0                  (*((unsigned int volatile sdata *) 0xEC42))

// PEC Destination Pointer 1
#define DSTP1                  (*((unsigned int volatile sdata *) 0xEC46))

// PEC Destination Pointer 2
#define DSTP2                  (*((unsigned int volatile sdata *) 0xEC4A))

// PEC Destination Pointer 3
#define DSTP3                  (*((unsigned int volatile sdata *) 0xEC4E))

// PEC Destination Pointer 4
#define DSTP4                  (*((unsigned int volatile sdata *) 0xEC52))

// PEC Destination Pointer 5
#define DSTP5                  (*((unsigned int volatile sdata *) 0xEC56))

// PEC Destination Pointer 6
#define DSTP6                  (*((unsigned int volatile sdata *) 0xEC5A))

// PEC Destination Pointer 7
#define DSTP7                  (*((unsigned int volatile sdata *) 0xEC5E))

// Software Debug Event Control Register
sfr  DSWEVT                           = 0xF0F4;

// Task ID Register
sfr  DTIDR                            = 0xF0D8;

// Hardware Trigger Event Control Register
sfr  DTREVT                           = 0xF0F0;

// Address Range/Size for CS1
#define EBC_ADDRSEL1           (*((unsigned int volatile sdata *) 0xEE1E))

// Address Range/Size for CS2
#define EBC_ADDRSEL2           (*((unsigned int volatile sdata *) 0xEE26))

// Address Range/Size for CS3
#define EBC_ADDRSEL3           (*((unsigned int volatile sdata *) 0xEE2E))

// Address Range/Size for CS4
#define EBC_ADDRSEL4           (*((unsigned int volatile sdata *) 0xEE36))

// Address Range/Size for CS7
#define EBC_ADDRSEL7           (*((unsigned int volatile sdata *) 0xEE4E))

// EBC Mode Register 0
#define EBC_EBCMOD0            (*((unsigned int volatile sdata *) 0xEE00))

// EBC Mode Register 1
#define EBC_EBCMOD1            (*((unsigned int volatile sdata *) 0xEE02))

// Function Cfg. Reg. for CS0
#define EBC_FCONCS0            (*((unsigned int volatile sdata *) 0xEE12))

// Function Cfg. Reg. for CS1
#define EBC_FCONCS1            (*((unsigned int volatile sdata *) 0xEE1A))

// Function Cfg. Reg. for CS2
#define EBC_FCONCS2            (*((unsigned int volatile sdata *) 0xEE22))

// Function Cfg. Reg. for CS3
#define EBC_FCONCS3            (*((unsigned int volatile sdata *) 0xEE2A))

// Function Cfg. Reg. for CS4
#define EBC_FCONCS4            (*((unsigned int volatile sdata *) 0xEE32))

// Function Cfg. Reg. for CSx
#define EBC_FCONCS7            (*((unsigned int volatile sdata *) 0xEE4A))

// Timing Cfg. Reg. for CS0
#define EBC_TCONCS0            (*((unsigned int volatile sdata *) 0xEE10))

// Timing Cfg. Reg. for CS1
#define EBC_TCONCS1            (*((unsigned int volatile sdata *) 0xEE18))

// Timing Cfg. Reg. for CS2
#define EBC_TCONCS2            (*((unsigned int volatile sdata *) 0xEE20))

// Timing Cfg. Reg. for CS3
#define EBC_TCONCS3            (*((unsigned int volatile sdata *) 0xEE28))

// Timing Cfg. Reg. for CS4
#define EBC_TCONCS4            (*((unsigned int volatile sdata *) 0xEE30))

// Timing Cfg. Reg. for CS7
#define EBC_TCONCS7            (*((unsigned int volatile sdata *) 0xEE48))

// EOP Interrupt Control Reg.
sfr  EOPIC                            = 0xF19E;
sbit EOPIC_EOPIE                    = EOPIC^6;
sbit EOPIC_EOPIR                    = EOPIC^7;
sbit EOPIC_GPX                      = EOPIC^8;

// Fast Interrupt Address Reg. 0
#define FINT0ADDR              (*((unsigned int volatile sdata *) 0xEC02))

// Fast Interrupt Control Reg. 0
#define FINT0CSP               (*((unsigned int volatile sdata *) 0xEC00))

// Fast Interrupt Address Reg. 1
#define FINT1ADDR              (*((unsigned int volatile sdata *) 0xEC06))

// Fast Interrupt Control Reg. 1
#define FINT1CSP               (*((unsigned int volatile sdata *) 0xEC04))

// Flash Kernel State Con. Register
sfr  FL_KSCCFG                        = 0xFE22;

// Capture/Reload Register
sfr  GPT12E_CAPREL                    = 0xFE4A;

// GPT12 CAPREL IC
sfr  GPT12E_CRIC                      = 0xFF6A;
sbit GPT12E_CRIC_GPX                      = GPT12E_CRIC^8;
sbit GPT12E_CRIC_IE                       = GPT12E_CRIC^6;
sbit GPT12E_CRIC_IR                       = GPT12E_CRIC^7;

// GPT12E Kernel State Con. Register
sfr  GPT12E_KSCCFG                    = 0xFE1C;

// Timer 2
sfr  GPT12E_T2                        = 0xFE40;

// Timer 2 Control Register
sfr  GPT12E_T2CON                     = 0xFF40;
sbit GPT12E_T2CON_T2CHDIR                  = GPT12E_T2CON^14;
sbit GPT12E_T2CON_T2EDGE                   = GPT12E_T2CON^13;
sbit GPT12E_T2CON_T2IRDIS                  = GPT12E_T2CON^12;
sbit GPT12E_T2CON_T2R                      = GPT12E_T2CON^6;
sbit GPT12E_T2CON_T2RC                     = GPT12E_T2CON^9;
sbit GPT12E_T2CON_T2RDIR                   = GPT12E_T2CON^15;
sbit GPT12E_T2CON_T2UD                     = GPT12E_T2CON^7;
sbit GPT12E_T2CON_T2UDE                    = GPT12E_T2CON^8;

// GPT12 TIMER 2 IC
sfr  GPT12E_T2IC                      = 0xFF60;
sbit GPT12E_T2IC_GPX                      = GPT12E_T2IC^8;
sbit GPT12E_T2IC_IE                       = GPT12E_T2IC^6;
sbit GPT12E_T2IC_IR                       = GPT12E_T2IC^7;

// Timer 3
sfr  GPT12E_T3                        = 0xFE42;

// Timer 3 Control Register
sfr  GPT12E_T3CON                     = 0xFF42;
sbit GPT12E_T3CON_T3CHDIR                  = GPT12E_T3CON^14;
sbit GPT12E_T3CON_T3EDGE                   = GPT12E_T3CON^13;
sbit GPT12E_T3CON_T3OE                     = GPT12E_T3CON^9;
sbit GPT12E_T3CON_T3OTL                    = GPT12E_T3CON^10;
sbit GPT12E_T3CON_T3R                      = GPT12E_T3CON^6;
sbit GPT12E_T3CON_T3RDIR                   = GPT12E_T3CON^15;
sbit GPT12E_T3CON_T3UD                     = GPT12E_T3CON^7;
sbit GPT12E_T3CON_T3UDE                    = GPT12E_T3CON^8;

// GPT12 TIMER 3 IC
sfr  GPT12E_T3IC                      = 0xFF62;
sbit GPT12E_T3IC_GPX                      = GPT12E_T3IC^8;
sbit GPT12E_T3IC_IE                       = GPT12E_T3IC^6;
sbit GPT12E_T3IC_IR                       = GPT12E_T3IC^7;

// Timer 4
sfr  GPT12E_T4                        = 0xFE44;

// Timer 4 Control Register
sfr  GPT12E_T4CON                     = 0xFF44;
sbit GPT12E_T4CON_T4CHDIR                  = GPT12E_T4CON^14;
sbit GPT12E_T4CON_T4EDGE                   = GPT12E_T4CON^13;
sbit GPT12E_T4CON_T4IRDIS                  = GPT12E_T4CON^12;
sbit GPT12E_T4CON_T4R                      = GPT12E_T4CON^6;
sbit GPT12E_T4CON_T4RC                     = GPT12E_T4CON^9;
sbit GPT12E_T4CON_T4RDIR                   = GPT12E_T4CON^15;
sbit GPT12E_T4CON_T4UD                     = GPT12E_T4CON^7;
sbit GPT12E_T4CON_T4UDE                    = GPT12E_T4CON^8;

// GPT12 TIMER 4 IC
sfr  GPT12E_T4IC                      = 0xFF64;
sbit GPT12E_T4IC_GPX                      = GPT12E_T4IC^8;
sbit GPT12E_T4IC_IE                       = GPT12E_T4IC^6;
sbit GPT12E_T4IC_IR                       = GPT12E_T4IC^7;

// Timer 5
sfr  GPT12E_T5                        = 0xFE46;

// Timer 5 Control Register
sfr  GPT12E_T5CON                     = 0xFF46;
sbit GPT12E_T5CON_CT3                      = GPT12E_T5CON^10;
sbit GPT12E_T5CON_T5CC                     = GPT12E_T5CON^11;
sbit GPT12E_T5CON_T5CLR                    = GPT12E_T5CON^14;
sbit GPT12E_T5CON_T5R                      = GPT12E_T5CON^6;
sbit GPT12E_T5CON_T5RC                     = GPT12E_T5CON^9;
sbit GPT12E_T5CON_T5SC                     = GPT12E_T5CON^15;
sbit GPT12E_T5CON_T5UD                     = GPT12E_T5CON^7;
sbit GPT12E_T5CON_T5UDE                    = GPT12E_T5CON^8;

// GPT12 TIMER 5 IC
sfr  GPT12E_T5IC                      = 0xFF66;
sbit GPT12E_T5IC_GPX                      = GPT12E_T5IC^8;
sbit GPT12E_T5IC_IE                       = GPT12E_T5IC^6;
sbit GPT12E_T5IC_IR                       = GPT12E_T5IC^7;

// Timer 6
sfr  GPT12E_T6                        = 0xFE48;

// Timer 6 Control Register
sfr  GPT12E_T6CON                     = 0xFF48;
sbit GPT12E_T6CON_T6CLR                    = GPT12E_T6CON^14;
sbit GPT12E_T6CON_T6OE                     = GPT12E_T6CON^9;
sbit GPT12E_T6CON_T6OTL                    = GPT12E_T6CON^10;
sbit GPT12E_T6CON_T6R                      = GPT12E_T6CON^6;
sbit GPT12E_T6CON_T6SR                     = GPT12E_T6CON^15;
sbit GPT12E_T6CON_T6UD                     = GPT12E_T6CON^7;
sbit GPT12E_T6CON_T6UDE                    = GPT12E_T6CON^8;

// GPT12 TIMER 6 IC
sfr  GPT12E_T6IC                      = 0xFF68;
sbit GPT12E_T6IC_GPX                      = GPT12E_T6IC^8;
sbit GPT12E_T6IC_IE                       = GPT12E_T6IC^6;
sbit GPT12E_T6IC_IR                       = GPT12E_T6IC^7;

// Address Pointer
sfr  IDX0                             = 0xFF08;

// Address Pointer
sfr  IDX1                             = 0xFF0A;

// Flash State Busy
#define IMB_FSR_BUSY           (*((unsigned int volatile huge *) 0xFFFF06))

// Flash State Operations
#define IMB_FSR_OP             (*((unsigned int volatile huge *) 0xFFFF08))

// Flash State Protection
#define IMB_FSR_PROT           (*((unsigned int volatile huge *) 0xFFFF0A))

// IMB Control High
#define IMB_IMBCTRH            (*((unsigned int volatile huge *) 0xFFFF02))

// IMB Control Low
#define IMB_IMBCTRL            (*((unsigned int volatile huge *) 0xFFFF00))

// Interrupt Control
#define IMB_INTCTR             (*((unsigned int volatile huge *) 0xFFFF04))

// Margin Control
#define IMB_MAR                (*((unsigned int volatile huge *) 0xFFFF0C))

// Protection Configuration 0.
#define IMB_PROCON0            (*((unsigned int volatile huge *) 0xFFFF10))

// Protection Configuration 1.
#define IMB_PROCON1            (*((unsigned int volatile huge *) 0xFFFF12))

// Protection Configuration 2.
#define IMB_PROCON2            (*((unsigned int volatile huge *) 0xFFFF14))

// Status and Control Register
sfr  IOSR                             = 0xF06C;

// Accumulator High Word
sfr  MAH                              = 0xFE5E;

// Accumulator Low Word
sfr  MAL                              = 0xFE5C;

// MultiCAN Kernel State Con. Register
sfr  MCAN_KSCCFG                      = 0xFE1E;

// MAC Control Word
sfr  MCW                              = 0xFFDC;
sbit MCW_MP                       = MCW^10;
sbit MCW_MS                       = MCW^9;

// Multiply Divide Control
sfr  MDC                              = 0xFF0E;
sbit MDC_MDRIU                    = MDC^4;

// Multiply Divide High Word
sfr  MDH                              = 0xFE0C;

// Multiply Divide Low Word
sfr  MDL                              = 0xFE0E;

// London Subsystem Kernel State Control Register
sfr  MEM_KSCCFG                       = 0xF012;

// MAC Repeat Word
sfr  MRW                              = 0xFFDA;

// MAC Status Word
sfr  MSW                              = 0xFFDE;
sbit MSW_MC                       = MSW^10;
sbit MSW_ME                       = MSW^12;
sbit MSW_MN                       = MSW^8;
sbit MSW_MSL                      = MSW^13;
sbit MSW_MSV                      = MSW^11;
sbit MSW_MV                       = MSW^14;
sbit MSW_MZ                       = MSW^9;

// Constant Ones Register
sfr  ONES                             = 0xFF1E;

// Port 0 Input Register
sfr  P0_IN                            = 0xFF80;
sbit P0_IN_P0                       = P0_IN^0;
sbit P0_IN_P1                       = P0_IN^1;
sbit P0_IN_P10                      = P0_IN^10;
sbit P0_IN_P11                      = P0_IN^11;
sbit P0_IN_P12                      = P0_IN^12;
sbit P0_IN_P13                      = P0_IN^13;
sbit P0_IN_P14                      = P0_IN^14;
sbit P0_IN_P15                      = P0_IN^15;
sbit P0_IN_P2                       = P0_IN^2;
sbit P0_IN_P3                       = P0_IN^3;
sbit P0_IN_P4                       = P0_IN^4;
sbit P0_IN_P5                       = P0_IN^5;
sbit P0_IN_P6                       = P0_IN^6;
sbit P0_IN_P7                       = P0_IN^7;
sbit P0_IN_P8                       = P0_IN^8;
sbit P0_IN_P9                       = P0_IN^9;

// Port 0 Input/Output Control Register 00
#define P0_IOCR00              (*((unsigned int volatile sdata *) 0xE800))

// Port 0 Input/Output Control Register 01
#define P0_IOCR01              (*((unsigned int volatile sdata *) 0xE802))

// Port 0 Input/Output Control Register 02
#define P0_IOCR02              (*((unsigned int volatile sdata *) 0xE804))

// Port 0 Input/Output Control Register 03
#define P0_IOCR03              (*((unsigned int volatile sdata *) 0xE806))

// Port 0 Input/Output Control Register 04
#define P0_IOCR04              (*((unsigned int volatile sdata *) 0xE808))

// Port 0 Input/Output Control Register 05
#define P0_IOCR05              (*((unsigned int volatile sdata *) 0xE80A))

// Port 0 Input/Output Control Register 06
#define P0_IOCR06              (*((unsigned int volatile sdata *) 0xE80C))

// Port 0 Input/Output Control Register 07
#define P0_IOCR07              (*((unsigned int volatile sdata *) 0xE80E))

// Port 0 Output Modification Register Low
#define P0_OMRL                (*((unsigned int volatile sdata *) 0xE9C0))

// Port 0 Output Register
sfr  P0_OUT                           = 0xFFA2;
sbit P0_OUT_P0                       = P0_OUT^0;
sbit P0_OUT_P1                       = P0_OUT^1;
sbit P0_OUT_P10                      = P0_OUT^10;
sbit P0_OUT_P11                      = P0_OUT^11;
sbit P0_OUT_P12                      = P0_OUT^12;
sbit P0_OUT_P13                      = P0_OUT^13;
sbit P0_OUT_P14                      = P0_OUT^14;
sbit P0_OUT_P15                      = P0_OUT^15;
sbit P0_OUT_P2                       = P0_OUT^2;
sbit P0_OUT_P3                       = P0_OUT^3;
sbit P0_OUT_P4                       = P0_OUT^4;
sbit P0_OUT_P5                       = P0_OUT^5;
sbit P0_OUT_P6                       = P0_OUT^6;
sbit P0_OUT_P7                       = P0_OUT^7;
sbit P0_OUT_P8                       = P0_OUT^8;
sbit P0_OUT_P9                       = P0_OUT^9;

// Port 0 Output Control Register
#define P0_POCON               (*((unsigned int volatile sdata *) 0xE8A0))

// Port 10 Input Register
sfr  P10_IN                           = 0xFF94;
sbit P10_IN_P0                       = P10_IN^0;
sbit P10_IN_P1                       = P10_IN^1;
sbit P10_IN_P10                      = P10_IN^10;
sbit P10_IN_P11                      = P10_IN^11;
sbit P10_IN_P12                      = P10_IN^12;
sbit P10_IN_P13                      = P10_IN^13;
sbit P10_IN_P14                      = P10_IN^14;
sbit P10_IN_P15                      = P10_IN^15;
sbit P10_IN_P2                       = P10_IN^2;
sbit P10_IN_P3                       = P10_IN^3;
sbit P10_IN_P4                       = P10_IN^4;
sbit P10_IN_P5                       = P10_IN^5;
sbit P10_IN_P6                       = P10_IN^6;
sbit P10_IN_P7                       = P10_IN^7;
sbit P10_IN_P8                       = P10_IN^8;
sbit P10_IN_P9                       = P10_IN^9;

// Port 10 Input/Output Control Register 00
#define P10_IOCR00             (*((unsigned int volatile sdata *) 0xE940))

// Port 10 Input/Output Control Register 01
#define P10_IOCR01             (*((unsigned int volatile sdata *) 0xE942))

// Port 10 Input/Output Control Register 02
#define P10_IOCR02             (*((unsigned int volatile sdata *) 0xE944))

// Port 10 Input/Output Control Register 03
#define P10_IOCR03             (*((unsigned int volatile sdata *) 0xE946))

// Port 10 Input/Output Control Register 04
#define P10_IOCR04             (*((unsigned int volatile sdata *) 0xE948))

// Port 10 Input/Output Control Register 05
#define P10_IOCR05             (*((unsigned int volatile sdata *) 0xE94A))

// Port 10 Input/Output Control Register 06
#define P10_IOCR06             (*((unsigned int volatile sdata *) 0xE94C))

// Port 10 Input/Output Control Register 07
#define P10_IOCR07             (*((unsigned int volatile sdata *) 0xE94E))

// Port 10 Input/Output Control Register 08
#define P10_IOCR08             (*((unsigned int volatile sdata *) 0xE950))

// Port 10 Input/Output Control Register 09
#define P10_IOCR09             (*((unsigned int volatile sdata *) 0xE952))

// Port 10 Input/Output Control Register 10
#define P10_IOCR10             (*((unsigned int volatile sdata *) 0xE954))

// Port 10 Input/Output Control Register 11
#define P10_IOCR11             (*((unsigned int volatile sdata *) 0xE956))

// Port 10 Input/Output Control Register 12
#define P10_IOCR12             (*((unsigned int volatile sdata *) 0xE958))

// Port 10 Input/Output Control Register 13
#define P10_IOCR13             (*((unsigned int volatile sdata *) 0xE95A))

// Port 10 Input/Output Control Register 14
#define P10_IOCR14             (*((unsigned int volatile sdata *) 0xE95C))

// Port 10 Input/Output Control Register 15
#define P10_IOCR15             (*((unsigned int volatile sdata *) 0xE95E))

// Port 10 Output Modification Register High
#define P10_OMRH               (*((unsigned int volatile sdata *) 0xE9EA))

// Port 10 Output Modification Register Low
#define P10_OMRL               (*((unsigned int volatile sdata *) 0xE9E8))

// Port 10 Output Register
sfr  P10_OUT                          = 0xFFB6;
sbit P10_OUT_P0                       = P10_OUT^0;
sbit P10_OUT_P1                       = P10_OUT^1;
sbit P10_OUT_P10                      = P10_OUT^10;
sbit P10_OUT_P11                      = P10_OUT^11;
sbit P10_OUT_P12                      = P10_OUT^12;
sbit P10_OUT_P13                      = P10_OUT^13;
sbit P10_OUT_P14                      = P10_OUT^14;
sbit P10_OUT_P15                      = P10_OUT^15;
sbit P10_OUT_P2                       = P10_OUT^2;
sbit P10_OUT_P3                       = P10_OUT^3;
sbit P10_OUT_P4                       = P10_OUT^4;
sbit P10_OUT_P5                       = P10_OUT^5;
sbit P10_OUT_P6                       = P10_OUT^6;
sbit P10_OUT_P7                       = P10_OUT^7;
sbit P10_OUT_P8                       = P10_OUT^8;
sbit P10_OUT_P9                       = P10_OUT^9;

// Port 10 Output Control Register
#define P10_POCON              (*((unsigned int volatile sdata *) 0xE8B4))

// Port 11 Input Register
sfr  P11_IN                           = 0xFF96;
sbit P11_IN_P0                       = P11_IN^0;
sbit P11_IN_P1                       = P11_IN^1;
sbit P11_IN_P10                      = P11_IN^10;
sbit P11_IN_P11                      = P11_IN^11;
sbit P11_IN_P12                      = P11_IN^12;
sbit P11_IN_P13                      = P11_IN^13;
sbit P11_IN_P14                      = P11_IN^14;
sbit P11_IN_P15                      = P11_IN^15;
sbit P11_IN_P2                       = P11_IN^2;
sbit P11_IN_P3                       = P11_IN^3;
sbit P11_IN_P4                       = P11_IN^4;
sbit P11_IN_P5                       = P11_IN^5;
sbit P11_IN_P6                       = P11_IN^6;
sbit P11_IN_P7                       = P11_IN^7;
sbit P11_IN_P8                       = P11_IN^8;
sbit P11_IN_P9                       = P11_IN^9;

// Port 11 Input/Output Control Register 00
#define P11_IOCR00             (*((unsigned int volatile sdata *) 0xE960))

// Port 11 Input/Output Control Register 01
#define P11_IOCR01             (*((unsigned int volatile sdata *) 0xE962))

// Port 11 Input/Output Control Register 02
#define P11_IOCR02             (*((unsigned int volatile sdata *) 0xE964))

// Port 11 Input/Output Control Register 03
#define P11_IOCR03             (*((unsigned int volatile sdata *) 0xE966))

// Port 11 Input/Output Control Register 04
#define P11_IOCR04             (*((unsigned int volatile sdata *) 0xE968))

// Port 11 Input/Output Control Register 05
#define P11_IOCR05             (*((unsigned int volatile sdata *) 0xE96A))

// Port 11 Output Modification Register Low
#define P11_OMRL               (*((unsigned int volatile sdata *) 0xE9EC))

// Port 11 Output Register
sfr  P11_OUT                          = 0xFFB8;
sbit P11_OUT_P0                       = P11_OUT^0;
sbit P11_OUT_P1                       = P11_OUT^1;
sbit P11_OUT_P10                      = P11_OUT^10;
sbit P11_OUT_P11                      = P11_OUT^11;
sbit P11_OUT_P12                      = P11_OUT^12;
sbit P11_OUT_P13                      = P11_OUT^13;
sbit P11_OUT_P14                      = P11_OUT^14;
sbit P11_OUT_P15                      = P11_OUT^15;
sbit P11_OUT_P2                       = P11_OUT^2;
sbit P11_OUT_P3                       = P11_OUT^3;
sbit P11_OUT_P4                       = P11_OUT^4;
sbit P11_OUT_P5                       = P11_OUT^5;
sbit P11_OUT_P6                       = P11_OUT^6;
sbit P11_OUT_P7                       = P11_OUT^7;
sbit P11_OUT_P8                       = P11_OUT^8;
sbit P11_OUT_P9                       = P11_OUT^9;

// Port 11 Output Control Register
#define P11_POCON              (*((unsigned int volatile sdata *) 0xE8B6))

// Port 15 Digital Input Disable Register
sfr  P15_DIDIS                        = 0xFE9E;

// Port 15 Input Register
sfr  P15_IN                           = 0xFF9E;
sbit P15_IN_P0                       = P15_IN^0;
sbit P15_IN_P1                       = P15_IN^1;
sbit P15_IN_P10                      = P15_IN^10;
sbit P15_IN_P11                      = P15_IN^11;
sbit P15_IN_P12                      = P15_IN^12;
sbit P15_IN_P13                      = P15_IN^13;
sbit P15_IN_P14                      = P15_IN^14;
sbit P15_IN_P15                      = P15_IN^15;
sbit P15_IN_P2                       = P15_IN^2;
sbit P15_IN_P3                       = P15_IN^3;
sbit P15_IN_P4                       = P15_IN^4;
sbit P15_IN_P5                       = P15_IN^5;
sbit P15_IN_P6                       = P15_IN^6;
sbit P15_IN_P7                       = P15_IN^7;
sbit P15_IN_P8                       = P15_IN^8;
sbit P15_IN_P9                       = P15_IN^9;

// Port 1 Input Register
sfr  P1_IN                            = 0xFF82;
sbit P1_IN_P0                       = P1_IN^0;
sbit P1_IN_P1                       = P1_IN^1;
sbit P1_IN_P10                      = P1_IN^10;
sbit P1_IN_P11                      = P1_IN^11;
sbit P1_IN_P12                      = P1_IN^12;
sbit P1_IN_P13                      = P1_IN^13;
sbit P1_IN_P14                      = P1_IN^14;
sbit P1_IN_P15                      = P1_IN^15;
sbit P1_IN_P2                       = P1_IN^2;
sbit P1_IN_P3                       = P1_IN^3;
sbit P1_IN_P4                       = P1_IN^4;
sbit P1_IN_P5                       = P1_IN^5;
sbit P1_IN_P6                       = P1_IN^6;
sbit P1_IN_P7                       = P1_IN^7;
sbit P1_IN_P8                       = P1_IN^8;
sbit P1_IN_P9                       = P1_IN^9;

// Port 1 Input/Output Control Register 00
#define P1_IOCR00              (*((unsigned int volatile sdata *) 0xE820))

// Port 1 Input/Output Control Register 01
#define P1_IOCR01              (*((unsigned int volatile sdata *) 0xE822))

// Port 1 Input/Output Control Register 02
#define P1_IOCR02              (*((unsigned int volatile sdata *) 0xE824))

// Port 1 Input/Output Control Register 03
#define P1_IOCR03              (*((unsigned int volatile sdata *) 0xE826))

// Port 1 Input/Output Control Register 04
#define P1_IOCR04              (*((unsigned int volatile sdata *) 0xE828))

// Port 1 Input/Output Control Register 05
#define P1_IOCR05              (*((unsigned int volatile sdata *) 0xE82A))

// Port 1 Input/Output Control Register 06
#define P1_IOCR06              (*((unsigned int volatile sdata *) 0xE82C))

// Port 1 Input/Output Control Register 07
#define P1_IOCR07              (*((unsigned int volatile sdata *) 0xE82E))

// Port 1 Output Modification Register Low
#define P1_OMRL                (*((unsigned int volatile sdata *) 0xE9C4))

// Port 1 Output Register
sfr  P1_OUT                           = 0xFFA4;
sbit P1_OUT_P0                       = P1_OUT^0;
sbit P1_OUT_P1                       = P1_OUT^1;
sbit P1_OUT_P10                      = P1_OUT^10;
sbit P1_OUT_P11                      = P1_OUT^11;
sbit P1_OUT_P12                      = P1_OUT^12;
sbit P1_OUT_P13                      = P1_OUT^13;
sbit P1_OUT_P14                      = P1_OUT^14;
sbit P1_OUT_P15                      = P1_OUT^15;
sbit P1_OUT_P2                       = P1_OUT^2;
sbit P1_OUT_P3                       = P1_OUT^3;
sbit P1_OUT_P4                       = P1_OUT^4;
sbit P1_OUT_P5                       = P1_OUT^5;
sbit P1_OUT_P6                       = P1_OUT^6;
sbit P1_OUT_P7                       = P1_OUT^7;
sbit P1_OUT_P8                       = P1_OUT^8;
sbit P1_OUT_P9                       = P1_OUT^9;

// Port 1 Output Control Register
#define P1_POCON               (*((unsigned int volatile sdata *) 0xE8A2))

// Port 2 Input Register
sfr  P2_IN                            = 0xFF84;
sbit P2_IN_P0                       = P2_IN^0;
sbit P2_IN_P1                       = P2_IN^1;
sbit P2_IN_P10                      = P2_IN^10;
sbit P2_IN_P11                      = P2_IN^11;
sbit P2_IN_P12                      = P2_IN^12;
sbit P2_IN_P13                      = P2_IN^13;
sbit P2_IN_P14                      = P2_IN^14;
sbit P2_IN_P15                      = P2_IN^15;
sbit P2_IN_P2                       = P2_IN^2;
sbit P2_IN_P3                       = P2_IN^3;
sbit P2_IN_P4                       = P2_IN^4;
sbit P2_IN_P5                       = P2_IN^5;
sbit P2_IN_P6                       = P2_IN^6;
sbit P2_IN_P7                       = P2_IN^7;
sbit P2_IN_P8                       = P2_IN^8;
sbit P2_IN_P9                       = P2_IN^9;

// Port 2 Input/Output Control Register 00
#define P2_IOCR00              (*((unsigned int volatile sdata *) 0xE840))

// Port 2 Input/Output Control Register 01
#define P2_IOCR01              (*((unsigned int volatile sdata *) 0xE842))

// Port 2 Input/Output Control Register 02
#define P2_IOCR02              (*((unsigned int volatile sdata *) 0xE844))

// Port 2 Input/Output Control Register 03
#define P2_IOCR03              (*((unsigned int volatile sdata *) 0xE846))

// Port 2 Input/Output Control Register 04
#define P2_IOCR04              (*((unsigned int volatile sdata *) 0xE848))

// Port 2 Input/Output Control Register 05
#define P2_IOCR05              (*((unsigned int volatile sdata *) 0xE84A))

// Port 2 Input/Output Control Register 06
#define P2_IOCR06              (*((unsigned int volatile sdata *) 0xE84C))

// Port 2 Input/Output Control Register 07
#define P2_IOCR07              (*((unsigned int volatile sdata *) 0xE84E))

// Port 2 Input/Output Control Register 08
#define P2_IOCR08              (*((unsigned int volatile sdata *) 0xE850))

// Port 2 Input/Output Control Register 09
#define P2_IOCR09              (*((unsigned int volatile sdata *) 0xE852))

// Port 2 Input/Output Control Register 10
#define P2_IOCR10              (*((unsigned int volatile sdata *) 0xE854))

// Port 2 Input/Output Control Register 11
#define P2_IOCR11              (*((unsigned int volatile sdata *) 0xE856))

// Port 2 Input/Output Control Register 12
#define P2_IOCR12              (*((unsigned int volatile sdata *) 0xE858))

// Port 2 Output Modification Register High
#define P2_OMRH                (*((unsigned int volatile sdata *) 0xE9CA))

// Port 2 Output Modification Register Low
#define P2_OMRL                (*((unsigned int volatile sdata *) 0xE9C8))

// Port 2 Output Register
sfr  P2_OUT                           = 0xFFA6;
sbit P2_OUT_P0                       = P2_OUT^0;
sbit P2_OUT_P1                       = P2_OUT^1;
sbit P2_OUT_P10                      = P2_OUT^10;
sbit P2_OUT_P11                      = P2_OUT^11;
sbit P2_OUT_P12                      = P2_OUT^12;
sbit P2_OUT_P13                      = P2_OUT^13;
sbit P2_OUT_P14                      = P2_OUT^14;
sbit P2_OUT_P15                      = P2_OUT^15;
sbit P2_OUT_P2                       = P2_OUT^2;
sbit P2_OUT_P3                       = P2_OUT^3;
sbit P2_OUT_P4                       = P2_OUT^4;
sbit P2_OUT_P5                       = P2_OUT^5;
sbit P2_OUT_P6                       = P2_OUT^6;
sbit P2_OUT_P7                       = P2_OUT^7;
sbit P2_OUT_P8                       = P2_OUT^8;
sbit P2_OUT_P9                       = P2_OUT^9;

// Port 2 Output Control Register
#define P2_POCON               (*((unsigned int volatile sdata *) 0xE8A4))

// Port 3 Input Register
sfr  P3_IN                            = 0xFF86;
sbit P3_IN_P0                       = P3_IN^0;
sbit P3_IN_P1                       = P3_IN^1;
sbit P3_IN_P10                      = P3_IN^10;
sbit P3_IN_P11                      = P3_IN^11;
sbit P3_IN_P12                      = P3_IN^12;
sbit P3_IN_P13                      = P3_IN^13;
sbit P3_IN_P14                      = P3_IN^14;
sbit P3_IN_P15                      = P3_IN^15;
sbit P3_IN_P2                       = P3_IN^2;
sbit P3_IN_P3                       = P3_IN^3;
sbit P3_IN_P4                       = P3_IN^4;
sbit P3_IN_P5                       = P3_IN^5;
sbit P3_IN_P6                       = P3_IN^6;
sbit P3_IN_P7                       = P3_IN^7;
sbit P3_IN_P8                       = P3_IN^8;
sbit P3_IN_P9                       = P3_IN^9;

// Port 3 Input/Output Control Register 00
#define P3_IOCR00              (*((unsigned int volatile sdata *) 0xE860))

// Port 3 Input/Output Control Register 01
#define P3_IOCR01              (*((unsigned int volatile sdata *) 0xE862))

// Port 3 Input/Output Control Register 02
#define P3_IOCR02              (*((unsigned int volatile sdata *) 0xE864))

// Port 3 Input/Output Control Register 03
#define P3_IOCR03              (*((unsigned int volatile sdata *) 0xE866))

// Port 3 Input/Output Control Register 04
#define P3_IOCR04              (*((unsigned int volatile sdata *) 0xE868))

// Port 3 Input/Output Control Register 05
#define P3_IOCR05              (*((unsigned int volatile sdata *) 0xE86A))

// Port 3 Input/Output Control Register 06
#define P3_IOCR06              (*((unsigned int volatile sdata *) 0xE86C))

// Port 3 Input/Output Control Register 07
#define P3_IOCR07              (*((unsigned int volatile sdata *) 0xE86E))

// Port 3 Output Modification Register Low
#define P3_OMRL                (*((unsigned int volatile sdata *) 0xE9CC))

// Port 3 Output Register
sfr  P3_OUT                           = 0xFFA8;
sbit P3_OUT_P0                       = P3_OUT^0;
sbit P3_OUT_P1                       = P3_OUT^1;
sbit P3_OUT_P10                      = P3_OUT^10;
sbit P3_OUT_P11                      = P3_OUT^11;
sbit P3_OUT_P12                      = P3_OUT^12;
sbit P3_OUT_P13                      = P3_OUT^13;
sbit P3_OUT_P14                      = P3_OUT^14;
sbit P3_OUT_P15                      = P3_OUT^15;
sbit P3_OUT_P2                       = P3_OUT^2;
sbit P3_OUT_P3                       = P3_OUT^3;
sbit P3_OUT_P4                       = P3_OUT^4;
sbit P3_OUT_P5                       = P3_OUT^5;
sbit P3_OUT_P6                       = P3_OUT^6;
sbit P3_OUT_P7                       = P3_OUT^7;
sbit P3_OUT_P8                       = P3_OUT^8;
sbit P3_OUT_P9                       = P3_OUT^9;

// Port 3 Output Control Register
#define P3_POCON               (*((unsigned int volatile sdata *) 0xE8A6))

// Port 4 Input Register
sfr  P4_IN                            = 0xFF88;
sbit P4_IN_P0                       = P4_IN^0;
sbit P4_IN_P1                       = P4_IN^1;
sbit P4_IN_P10                      = P4_IN^10;
sbit P4_IN_P11                      = P4_IN^11;
sbit P4_IN_P12                      = P4_IN^12;
sbit P4_IN_P13                      = P4_IN^13;
sbit P4_IN_P14                      = P4_IN^14;
sbit P4_IN_P15                      = P4_IN^15;
sbit P4_IN_P2                       = P4_IN^2;
sbit P4_IN_P3                       = P4_IN^3;
sbit P4_IN_P4                       = P4_IN^4;
sbit P4_IN_P5                       = P4_IN^5;
sbit P4_IN_P6                       = P4_IN^6;
sbit P4_IN_P7                       = P4_IN^7;
sbit P4_IN_P8                       = P4_IN^8;
sbit P4_IN_P9                       = P4_IN^9;

// Port 4 Input/Output Control Register 00
#define P4_IOCR00              (*((unsigned int volatile sdata *) 0xE880))

// Port 4 Input/Output Control Register 01
#define P4_IOCR01              (*((unsigned int volatile sdata *) 0xE882))

// Port 4 Input/Output Control Register 02
#define P4_IOCR02              (*((unsigned int volatile sdata *) 0xE884))

// Port 4 Input/Output Control Register 03
#define P4_IOCR03              (*((unsigned int volatile sdata *) 0xE886))

// Port 4 Input/Output Control Register 04
#define P4_IOCR04              (*((unsigned int volatile sdata *) 0xE888))

// Port 4 Input/Output Control Register 05
#define P4_IOCR05              (*((unsigned int volatile sdata *) 0xE88A))

// Port 4 Input/Output Control Register 06
#define P4_IOCR06              (*((unsigned int volatile sdata *) 0xE88C))

// Port 4 Input/Output Control Register 07
#define P4_IOCR07              (*((unsigned int volatile sdata *) 0xE88E))

// Port 4 Output Modification Register Low
#define P4_OMRL                (*((unsigned int volatile sdata *) 0xE9D0))

// Port 4 Output Register
sfr  P4_OUT                           = 0xFFAA;
sbit P4_OUT_P0                       = P4_OUT^0;
sbit P4_OUT_P1                       = P4_OUT^1;
sbit P4_OUT_P10                      = P4_OUT^10;
sbit P4_OUT_P11                      = P4_OUT^11;
sbit P4_OUT_P12                      = P4_OUT^12;
sbit P4_OUT_P13                      = P4_OUT^13;
sbit P4_OUT_P14                      = P4_OUT^14;
sbit P4_OUT_P15                      = P4_OUT^15;
sbit P4_OUT_P2                       = P4_OUT^2;
sbit P4_OUT_P3                       = P4_OUT^3;
sbit P4_OUT_P4                       = P4_OUT^4;
sbit P4_OUT_P5                       = P4_OUT^5;
sbit P4_OUT_P6                       = P4_OUT^6;
sbit P4_OUT_P7                       = P4_OUT^7;
sbit P4_OUT_P8                       = P4_OUT^8;
sbit P4_OUT_P9                       = P4_OUT^9;

// Port 4 Output Control Register
#define P4_POCON               (*((unsigned int volatile sdata *) 0xE8A8))

// Port 5 Digital Input Disable Register
sfr  P5_DIDIS                         = 0xFE8A;

// Port 5 Input Register
sfr  P5_IN                            = 0xFF8A;
sbit P5_IN_P0                       = P5_IN^0;
sbit P5_IN_P1                       = P5_IN^1;
sbit P5_IN_P10                      = P5_IN^10;
sbit P5_IN_P11                      = P5_IN^11;
sbit P5_IN_P12                      = P5_IN^12;
sbit P5_IN_P13                      = P5_IN^13;
sbit P5_IN_P14                      = P5_IN^14;
sbit P5_IN_P15                      = P5_IN^15;
sbit P5_IN_P2                       = P5_IN^2;
sbit P5_IN_P3                       = P5_IN^3;
sbit P5_IN_P4                       = P5_IN^4;
sbit P5_IN_P5                       = P5_IN^5;
sbit P5_IN_P6                       = P5_IN^6;
sbit P5_IN_P7                       = P5_IN^7;
sbit P5_IN_P8                       = P5_IN^8;
sbit P5_IN_P9                       = P5_IN^9;

// Port 6 Input Register
sfr  P6_IN                            = 0xFF8C;
sbit P6_IN_P0                       = P6_IN^0;
sbit P6_IN_P1                       = P6_IN^1;
sbit P6_IN_P10                      = P6_IN^10;
sbit P6_IN_P11                      = P6_IN^11;
sbit P6_IN_P12                      = P6_IN^12;
sbit P6_IN_P13                      = P6_IN^13;
sbit P6_IN_P14                      = P6_IN^14;
sbit P6_IN_P15                      = P6_IN^15;
sbit P6_IN_P2                       = P6_IN^2;
sbit P6_IN_P3                       = P6_IN^3;
sbit P6_IN_P4                       = P6_IN^4;
sbit P6_IN_P5                       = P6_IN^5;
sbit P6_IN_P6                       = P6_IN^6;
sbit P6_IN_P7                       = P6_IN^7;
sbit P6_IN_P8                       = P6_IN^8;
sbit P6_IN_P9                       = P6_IN^9;

// Port 6 Input/Output Control Register 00
#define P6_IOCR00              (*((unsigned int volatile sdata *) 0xE8C0))

// Port 6 Input/Output Control Register 01
#define P6_IOCR01              (*((unsigned int volatile sdata *) 0xE8C2))

// Port 6 Input/Output Control Register 02
#define P6_IOCR02              (*((unsigned int volatile sdata *) 0xE8C4))

// Port 6 Input/Output Control Register 03
#define P6_IOCR03              (*((unsigned int volatile sdata *) 0xE8C6))

// Port 6 Output Modification Register Low
#define P6_OMRL                (*((unsigned int volatile sdata *) 0xE9D8))

// Port 6 Output Register
sfr  P6_OUT                           = 0xFFAE;
sbit P6_OUT_P0                       = P6_OUT^0;
sbit P6_OUT_P1                       = P6_OUT^1;
sbit P6_OUT_P10                      = P6_OUT^10;
sbit P6_OUT_P11                      = P6_OUT^11;
sbit P6_OUT_P12                      = P6_OUT^12;
sbit P6_OUT_P13                      = P6_OUT^13;
sbit P6_OUT_P14                      = P6_OUT^14;
sbit P6_OUT_P15                      = P6_OUT^15;
sbit P6_OUT_P2                       = P6_OUT^2;
sbit P6_OUT_P3                       = P6_OUT^3;
sbit P6_OUT_P4                       = P6_OUT^4;
sbit P6_OUT_P5                       = P6_OUT^5;
sbit P6_OUT_P6                       = P6_OUT^6;
sbit P6_OUT_P7                       = P6_OUT^7;
sbit P6_OUT_P8                       = P6_OUT^8;
sbit P6_OUT_P9                       = P6_OUT^9;

// Port 6 Output Control Register
#define P6_POCON               (*((unsigned int volatile sdata *) 0xE8AC))

// Port 7 Input Register
sfr  P7_IN                            = 0xFF8E;
sbit P7_IN_P0                       = P7_IN^0;
sbit P7_IN_P1                       = P7_IN^1;
sbit P7_IN_P10                      = P7_IN^10;
sbit P7_IN_P11                      = P7_IN^11;
sbit P7_IN_P12                      = P7_IN^12;
sbit P7_IN_P13                      = P7_IN^13;
sbit P7_IN_P14                      = P7_IN^14;
sbit P7_IN_P15                      = P7_IN^15;
sbit P7_IN_P2                       = P7_IN^2;
sbit P7_IN_P3                       = P7_IN^3;
sbit P7_IN_P4                       = P7_IN^4;
sbit P7_IN_P5                       = P7_IN^5;
sbit P7_IN_P6                       = P7_IN^6;
sbit P7_IN_P7                       = P7_IN^7;
sbit P7_IN_P8                       = P7_IN^8;
sbit P7_IN_P9                       = P7_IN^9;

// Port 7 Input/Output Control Register 00
#define P7_IOCR00              (*((unsigned int volatile sdata *) 0xE8E0))

// Port 7 Input/Output Control Register 01
#define P7_IOCR01              (*((unsigned int volatile sdata *) 0xE8E2))

// Port 7 Input/Output Control Register 02
#define P7_IOCR02              (*((unsigned int volatile sdata *) 0xE8E4))

// Port 7 Input/Output Control Register 03
#define P7_IOCR03              (*((unsigned int volatile sdata *) 0xE8E6))

// Port 7 Input/Output Control Register 04
#define P7_IOCR04              (*((unsigned int volatile sdata *) 0xE8E8))

// Port 7 Output Modification Register Low
#define P7_OMRL                (*((unsigned int volatile sdata *) 0xE9DC))

// Port 7 Output Register
sfr  P7_OUT                           = 0xFFB0;
sbit P7_OUT_P0                       = P7_OUT^0;
sbit P7_OUT_P1                       = P7_OUT^1;
sbit P7_OUT_P10                      = P7_OUT^10;
sbit P7_OUT_P11                      = P7_OUT^11;
sbit P7_OUT_P12                      = P7_OUT^12;
sbit P7_OUT_P13                      = P7_OUT^13;
sbit P7_OUT_P14                      = P7_OUT^14;
sbit P7_OUT_P15                      = P7_OUT^15;
sbit P7_OUT_P2                       = P7_OUT^2;
sbit P7_OUT_P3                       = P7_OUT^3;
sbit P7_OUT_P4                       = P7_OUT^4;
sbit P7_OUT_P5                       = P7_OUT^5;
sbit P7_OUT_P6                       = P7_OUT^6;
sbit P7_OUT_P7                       = P7_OUT^7;
sbit P7_OUT_P8                       = P7_OUT^8;
sbit P7_OUT_P9                       = P7_OUT^9;

// Port 7 Output Control Register
#define P7_POCON               (*((unsigned int volatile sdata *) 0xE8AE))

// Port 8 Input Register
sfr  P8_IN                            = 0xFF90;
sbit P8_IN_P0                       = P8_IN^0;
sbit P8_IN_P1                       = P8_IN^1;
sbit P8_IN_P10                      = P8_IN^10;
sbit P8_IN_P11                      = P8_IN^11;
sbit P8_IN_P12                      = P8_IN^12;
sbit P8_IN_P13                      = P8_IN^13;
sbit P8_IN_P14                      = P8_IN^14;
sbit P8_IN_P15                      = P8_IN^15;
sbit P8_IN_P2                       = P8_IN^2;
sbit P8_IN_P3                       = P8_IN^3;
sbit P8_IN_P4                       = P8_IN^4;
sbit P8_IN_P5                       = P8_IN^5;
sbit P8_IN_P6                       = P8_IN^6;
sbit P8_IN_P7                       = P8_IN^7;
sbit P8_IN_P8                       = P8_IN^8;
sbit P8_IN_P9                       = P8_IN^9;

// Port 8 Input/Output Control Register 00
#define P8_IOCR00              (*((unsigned int volatile sdata *) 0xE900))

// Port 8 Input/Output Control Register 01
#define P8_IOCR01              (*((unsigned int volatile sdata *) 0xE902))

// Port 8 Input/Output Control Register 02
#define P8_IOCR02              (*((unsigned int volatile sdata *) 0xE904))

// Port 8 Input/Output Control Register 03
#define P8_IOCR03              (*((unsigned int volatile sdata *) 0xE906))

// Port 8 Input/Output Control Register 04
#define P8_IOCR04              (*((unsigned int volatile sdata *) 0xE908))

// Port 8 Input/Output Control Register 05
#define P8_IOCR05              (*((unsigned int volatile sdata *) 0xE90A))

// Port 8 Input/Output Control Register 06
#define P8_IOCR06              (*((unsigned int volatile sdata *) 0xE90C))

// Port 8 Output Modification Register Low
#define P8_OMRL                (*((unsigned int volatile sdata *) 0xE9E0))

// Port 8 Output Register
sfr  P8_OUT                           = 0xFFB2;
sbit P8_OUT_P0                       = P8_OUT^0;
sbit P8_OUT_P1                       = P8_OUT^1;
sbit P8_OUT_P10                      = P8_OUT^10;
sbit P8_OUT_P11                      = P8_OUT^11;
sbit P8_OUT_P12                      = P8_OUT^12;
sbit P8_OUT_P13                      = P8_OUT^13;
sbit P8_OUT_P14                      = P8_OUT^14;
sbit P8_OUT_P15                      = P8_OUT^15;
sbit P8_OUT_P2                       = P8_OUT^2;
sbit P8_OUT_P3                       = P8_OUT^3;
sbit P8_OUT_P4                       = P8_OUT^4;
sbit P8_OUT_P5                       = P8_OUT^5;
sbit P8_OUT_P6                       = P8_OUT^6;
sbit P8_OUT_P7                       = P8_OUT^7;
sbit P8_OUT_P8                       = P8_OUT^8;
sbit P8_OUT_P9                       = P8_OUT^9;

// Port 8 Output Control Register
#define P8_POCON               (*((unsigned int volatile sdata *) 0xE8B0))

// Port 9 Input Register
sfr  P9_IN                            = 0xFF92;
sbit P9_IN_P0                       = P9_IN^0;
sbit P9_IN_P1                       = P9_IN^1;
sbit P9_IN_P10                      = P9_IN^10;
sbit P9_IN_P11                      = P9_IN^11;
sbit P9_IN_P12                      = P9_IN^12;
sbit P9_IN_P13                      = P9_IN^13;
sbit P9_IN_P14                      = P9_IN^14;
sbit P9_IN_P15                      = P9_IN^15;
sbit P9_IN_P2                       = P9_IN^2;
sbit P9_IN_P3                       = P9_IN^3;
sbit P9_IN_P4                       = P9_IN^4;
sbit P9_IN_P5                       = P9_IN^5;
sbit P9_IN_P6                       = P9_IN^6;
sbit P9_IN_P7                       = P9_IN^7;
sbit P9_IN_P8                       = P9_IN^8;
sbit P9_IN_P9                       = P9_IN^9;

// Port 9 Input/Output Control Register 00
#define P9_IOCR00              (*((unsigned int volatile sdata *) 0xE920))

// Port 9 Input/Output Control Register 01
#define P9_IOCR01              (*((unsigned int volatile sdata *) 0xE922))

// Port 9 Input/Output Control Register 02
#define P9_IOCR02              (*((unsigned int volatile sdata *) 0xE924))

// Port 9 Input/Output Control Register 03
#define P9_IOCR03              (*((unsigned int volatile sdata *) 0xE926))

// Port 9 Input/Output Control Register 04
#define P9_IOCR04              (*((unsigned int volatile sdata *) 0xE928))

// Port 9 Input/Output Control Register 05
#define P9_IOCR05              (*((unsigned int volatile sdata *) 0xE92A))

// Port 9 Input/Output Control Register 06
#define P9_IOCR06              (*((unsigned int volatile sdata *) 0xE92C))

// Port 9 Input/Output Control Register 07
#define P9_IOCR07              (*((unsigned int volatile sdata *) 0xE92E))

// Port 9 Output Modification Register Low
#define P9_OMRL                (*((unsigned int volatile sdata *) 0xE9E4))

// Port 9 Output Register
sfr  P9_OUT                           = 0xFFB4;
sbit P9_OUT_P0                       = P9_OUT^0;
sbit P9_OUT_P1                       = P9_OUT^1;
sbit P9_OUT_P10                      = P9_OUT^10;
sbit P9_OUT_P11                      = P9_OUT^11;
sbit P9_OUT_P12                      = P9_OUT^12;
sbit P9_OUT_P13                      = P9_OUT^13;
sbit P9_OUT_P14                      = P9_OUT^14;
sbit P9_OUT_P15                      = P9_OUT^15;
sbit P9_OUT_P2                       = P9_OUT^2;
sbit P9_OUT_P3                       = P9_OUT^3;
sbit P9_OUT_P4                       = P9_OUT^4;
sbit P9_OUT_P5                       = P9_OUT^5;
sbit P9_OUT_P6                       = P9_OUT^6;
sbit P9_OUT_P7                       = P9_OUT^7;
sbit P9_OUT_P8                       = P9_OUT^8;
sbit P9_OUT_P9                       = P9_OUT^9;

// Port 9 Output Control Register
#define P9_POCON               (*((unsigned int volatile sdata *) 0xE8B2))

// PEC Channel Control Reg. 0
sfr  PECC0                            = 0xFEC0;

// PEC Channel Control Reg. 1
sfr  PECC1                            = 0xFEC2;

// PEC Channel Control Reg. 2
sfr  PECC2                            = 0xFEC4;

// PEC Channel Control Reg. 3
sfr  PECC3                            = 0xFEC6;

// PEC Channel Control Reg. 4
sfr  PECC4                            = 0xFEC8;

// PEC Channel Control Reg. 5
sfr  PECC5                            = 0xFECA;

// PEC Channel Control Reg. 6
sfr  PECC6                            = 0xFECC;

// PEC Channel Control Reg. 7
sfr  PECC7                            = 0xFECE;

// PEC Intr. Sub Node Control
sfr  PECISNC                          = 0xFFD8;
sbit PECISNC_C0IE                     = PECISNC^0;
sbit PECISNC_C0IR                     = PECISNC^1;
sbit PECISNC_C1IE                     = PECISNC^2;
sbit PECISNC_C1IR                     = PECISNC^3;
sbit PECISNC_C2IE                     = PECISNC^4;
sbit PECISNC_C2IR                     = PECISNC^5;
sbit PECISNC_C3IE                     = PECISNC^6;
sbit PECISNC_C3IR                     = PECISNC^7;
sbit PECISNC_C4IE                     = PECISNC^8;
sbit PECISNC_C4IR                     = PECISNC^9;
sbit PECISNC_C5IE                     = PECISNC^10;
sbit PECISNC_C5IR                     = PECISNC^11;
sbit PECISNC_C6IE                     = PECISNC^12;
sbit PECISNC_C6IR                     = PECISNC^13;
sbit PECISNC_C7IE                     = PECISNC^14;
sbit PECISNC_C7IR                     = PECISNC^15;

// PEC Segment Pointer 0
#define PECSEG0                (*((unsigned int volatile sdata *) 0xEC80))

// PEC Segment Pointer 1
#define PECSEG1                (*((unsigned int volatile sdata *) 0xEC82))

// PEC Segment Pointer 2
#define PECSEG2                (*((unsigned int volatile sdata *) 0xEC84))

// PEC Segment Pointer 3
#define PECSEG3                (*((unsigned int volatile sdata *) 0xEC86))

// PEC Segment Pointer 4
#define PECSEG4                (*((unsigned int volatile sdata *) 0xEC88))

// PEC Segment Pointer 5
#define PECSEG5                (*((unsigned int volatile sdata *) 0xEC8A))

// PEC Segment Pointer 6
#define PECSEG6                (*((unsigned int volatile sdata *) 0xEC8C))

// PEC Segment Pointer 7
#define PECSEG7                (*((unsigned int volatile sdata *) 0xEC8E))

// Program Flash Interrupt
sfr  PFM_IC                           = 0xF19A;
sbit PFM_IC_GPX                      = PFM_IC^8;
sbit PFM_IC_IE                       = PFM_IC^6;
sbit PFM_IC_IR                       = PFM_IC^7;

// Processor Status Word
sfr  PSW                              = 0xFF10;
sbit PSW_C                        = PSW^1;
sbit PSW_E                        = PSW^4;
sbit PSW_HLDEN                    = PSW^10;
sbit PSW_IEN                      = PSW^11;
sbit PSW_MULIP                    = PSW^5;
sbit PSW_N                        = PSW^0;
sbit PSW_USR0                     = PSW^6;
sbit PSW_USR1                     = PSW^7;
sbit PSW_V                        = PSW^2;
sbit PSW_Z                        = PSW^3;

// Offset Register
sfr  QR0                              = 0xF004;

// Offset Register
sfr  QR1                              = 0xF006;

// Offset Register
sfr  QX0                              = 0xF000;

// Offset Register
sfr  QX1                              = 0xF002;

// Control Register
sfr  RTC_CON                          = 0xF110;
sbit RTC_CON_ACCPOS                   = RTC_CON^15;
sbit RTC_CON_PRE                      = RTC_CON^1;
sbit RTC_CON_REFCLK                   = RTC_CON^4;
sbit RTC_CON_RUN                      = RTC_CON^0;
sbit RTC_CON_T14DEC                   = RTC_CON^2;
sbit RTC_CON_T14INC                   = RTC_CON^3;

// Real Time Clock Interrupt
sfr  RTC_IC                           = 0xF19C;
sbit RTC_IC_GPX                      = RTC_IC^8;
sbit RTC_IC_IE                       = RTC_IC^6;
sbit RTC_IC_IR                       = RTC_IC^7;

// Interrupt Sub Node Control
sfr  RTC_ISNC                         = 0xF10C;
sbit RTC_ISNC_CNT0IE                   = RTC_ISNC^2;
sbit RTC_ISNC_CNT0IR                   = RTC_ISNC^3;
sbit RTC_ISNC_CNT1IE                   = RTC_ISNC^4;
sbit RTC_ISNC_CNT1IR                   = RTC_ISNC^5;
sbit RTC_ISNC_CNT2IE                   = RTC_ISNC^6;
sbit RTC_ISNC_CNT2IR                   = RTC_ISNC^7;
sbit RTC_ISNC_CNT3IE                   = RTC_ISNC^8;
sbit RTC_ISNC_CNT3IR                   = RTC_ISNC^9;
sbit RTC_ISNC_T14IE                    = RTC_ISNC^0;
sbit RTC_ISNC_T14IR                    = RTC_ISNC^1;

// RTC Kernel State Con. Register
sfr  RTC_KSCCFG                       = 0xF010;

// RTC Reload Register High
sfr  RTC_RELH                         = 0xF0CE;

// RTC Reload Register Low
sfr  RTC_RELL                         = 0xF0CC;

// RTC Count Register High
sfr  RTC_RTCH                         = 0xF0D6;

// RTC Count Register Low
sfr  RTC_RTCL                         = 0xF0D4;

// T14 Count Register
sfr  RTC_T14                          = 0xF0D2;

// T14 Reload Register
sfr  RTC_T14REL                       = 0xF0D0;

// RWDATA in Monitor Controlled Tracing Mode
sfr  RWDATA                           = 0xF06A;

// Data Register in RW Mode
sfr  RWDATA                           = 0xF06A;

// Data Register in RW Mode, Byte layout
sfr  RWDATA                           = 0xF06A;

// SBRAM Data Register 0
sfr  SBRAM_DATA0                      = 0xFEE0;

// SBRAM Data Register 1
sfr  SBRAM_DATA1                      = 0xFEE2;

// SBRAM Read Address Register
sfr  SBRAM_RADD                       = 0xFEDC;

// SBRAM Write Address Register
sfr  SBRAM_WADD                       = 0xFEDE;

// SCU 0
sfr  SCU_0IC                          = 0xF198;
sbit SCU_0IC_GPX                      = SCU_0IC^8;
sbit SCU_0IC_IE                       = SCU_0IC^6;
sbit SCU_0IC_IR                       = SCU_0IC^7;

// SCU 1
sfr  SCU_1IC                          = 0xF196;
sbit SCU_1IC_GPX                      = SCU_1IC^8;
sbit SCU_1IC_IE                       = SCU_1IC^6;
sbit SCU_1IC_IR                       = SCU_1IC^7;

// Debug Pin Routing Register
sfr  SCU_DBGPRR                       = 0xF06E;

// DMP_M Int. and Trap Trigger Register
sfr  SCU_DMPMIT                       = 0xFE96;

// DMP_M Int. and Trap Clear Register
sfr  SCU_DMPMITCLR                    = 0xFE98;

// ESR0 Configuration Register
sfr  SCU_ESRCFG0                      = 0xF100;
sbit SCU_ESRCFG0_DFEN                     = SCU_ESRCFG0^4;
sbit SCU_ESRCFG0_IN                       = SCU_ESRCFG0^6;
sbit SCU_ESRCFG0_OUT                      = SCU_ESRCFG0^5;

// ESR1 Configuration Register
sfr  SCU_ESRCFG1                      = 0xF102;
sbit SCU_ESRCFG1_DFEN                     = SCU_ESRCFG1^4;
sbit SCU_ESRCFG1_IN                       = SCU_ESRCFG1^6;
sbit SCU_ESRCFG1_OUT                      = SCU_ESRCFG1^5;

// ESR2 Configuration Register
sfr  SCU_ESRCFG2                      = 0xF104;
sbit SCU_ESRCFG2_DFEN                     = SCU_ESRCFG2^4;
sbit SCU_ESRCFG2_IN                       = SCU_ESRCFG2^6;
sbit SCU_ESRCFG2_OUT                      = SCU_ESRCFG2^5;

// ESR Data Register
sfr  SCU_ESRDAT                       = 0xF106;

// ESR1 External Control Register
sfr  SCU_ESREXCON1                    = 0xFF32;
sbit SCU_ESREXCON1_ESR1EN                   = SCU_ESREXCON1^0;
sbit SCU_ESREXCON1_P100EN                   = SCU_ESREXCON1^3;
sbit SCU_ESREXCON1_P10EN                    = SCU_ESREXCON1^4;
sbit SCU_ESREXCON1_P12EN                    = SCU_ESREXCON1^5;
sbit SCU_ESREXCON1_P21EN                    = SCU_ESREXCON1^6;
sbit SCU_ESREXCON1_P24EN                    = SCU_ESREXCON1^1;
sbit SCU_ESREXCON1_P30EN                    = SCU_ESREXCON1^2;

// ESR2 External Control Register
sfr  SCU_ESREXCON2                    = 0xFF34;
sbit SCU_ESREXCON2_ESR2EN                   = SCU_ESREXCON2^0;
sbit SCU_ESREXCON2_P1014EN                  = SCU_ESREXCON2^3;
sbit SCU_ESREXCON2_P11EN                    = SCU_ESREXCON2^4;
sbit SCU_ESREXCON2_P13EN                    = SCU_ESREXCON2^5;
sbit SCU_ESREXCON2_P22EN                    = SCU_ESREXCON2^6;
sbit SCU_ESREXCON2_P23EN                    = SCU_ESREXCON2^1;
sbit SCU_ESREXCON2_P70EN                    = SCU_ESREXCON2^2;

// EVR_1 Control 0 Register
sfr  SCU_EVR1CON0                     = 0xF088;

// EVR_1 Setting for 1.0 V Register
sfr  SCU_EVR1SET10V                   = 0xF098;

// EVR_1 Setting for 1.5 V HP Register
sfr  SCU_EVR1SET15VHP                 = 0xF09E;

// EVR_1 Setting for 1.5 V LP Register
sfr  SCU_EVR1SET15VLP                 = 0xF09C;

// EVR_1 Status Register
sfr  SCU_EVR1STAT                     = 0xF08E;

// EVR_M Control 0 Register
sfr  SCU_EVRMCON0                     = 0xF084;

// EVR_M Control 1 Register
sfr  SCU_EVRMCON1                     = 0xF086;

// EVR_M Setting for 1.0 V Register
sfr  SCU_EVRMSET10V                   = 0xF090;

// EVR_M Setting for 1.5 V HP Register
sfr  SCU_EVRMSET15VHP                 = 0xF096;

// EVR_M Setting for 1.5 V LP Register
sfr  SCU_EVRMSET15VLP                 = 0xF094;

// EVR_M Status Register
sfr  SCU_EVRMSTAT                     = 0xF08C;

// External Int. Trigger Control 0 Register
sfr  SCU_EXICON0                      = 0xF030;

// External Int. Trigger Control 1 Register
sfr  SCU_EXICON1                      = 0xF032;

// External Int. Trigger Control 2 Register
sfr  SCU_EXICON2                      = 0xF034;

// External Int. Trigger Control 3 Register
sfr  SCU_EXICON3                      = 0xF036;

// External Int. Input Select Register
sfr  SCU_EXISEL                       = 0xF1A0;

// External Output Trigger Control 0 Register
sfr  SCU_EXOCON0                      = 0xFE30;

// External Output Trigger Control 1 Register
sfr  SCU_EXOCON1                      = 0xFE32;

// External Output Trigger Control 2 Register
sfr  SCU_EXOCON2                      = 0xFE34;

// External Output Trigger Control 3 Register
sfr  SCU_EXOCON3                      = 0xFE36;

// External Clock Control Register
sfr  SCU_EXTCON                       = 0xFF5E;
sbit SCU_EXTCON_EN                       = SCU_EXTCON^0;
sbit SCU_EXTCON_FOEN                     = SCU_EXTCON^15;
sbit SCU_EXTCON_FOSS                     = SCU_EXTCON^14;
sbit SCU_EXTCON_FOTL                     = SCU_EXTCON^6;

// GSC Enable Register
sfr  SCU_GSCEN                        = 0xFF16;
sbit SCU_GSCEN_1                        = SCU_GSCEN^13;
sbit SCU_GSCEN_ESR0EN                   = SCU_GSCEN^5;
sbit SCU_GSCEN_ESR1EN                   = SCU_GSCEN^6;
sbit SCU_GSCEN_ESR2EN                   = SCU_GSCEN^7;
sbit SCU_GSCEN_GPTEN                    = SCU_GSCEN^10;
sbit SCU_GSCEN_ITCEN                    = SCU_GSCEN^9;
sbit SCU_GSCEN_OCDSENEN                 = SCU_GSCEN^14;
sbit SCU_GSCEN_OCDSEXEN                 = SCU_GSCEN^4;
sbit SCU_GSCEN_PSCAENEN                 = SCU_GSCEN^3;
sbit SCU_GSCEN_PSCAEXEN                 = SCU_GSCEN^2;
sbit SCU_GSCEN_PSCBENEN                 = SCU_GSCEN^1;
sbit SCU_GSCEN_PSCBEXEN                 = SCU_GSCEN^0;
sbit SCU_GSCEN_SW1EN                    = SCU_GSCEN^11;
sbit SCU_GSCEN_SW2EN                    = SCU_GSCEN^12;
sbit SCU_GSCEN_WUTEN                    = SCU_GSCEN^8;

// GSC Status Register
sfr  SCU_GSCSTAT                      = 0xFF18;
sbit SCU_GSCSTAT_ERR                      = SCU_GSCSTAT^8;
sbit SCU_GSCSTAT_PEN                      = SCU_GSCSTAT^9;

// GSC SW Request Register
sfr  SCU_GSCSWREQ                     = 0xFF14;
sbit SCU_GSCSWREQ_SWTRG1                   = SCU_GSCSWREQ^0;
sbit SCU_GSCSWREQ_SWTRG2                   = SCU_GSCSWREQ^1;

// High Precision OSC Control Register
sfr  SCU_HPOSCCON                     = 0xF1B4;
sbit SCU_HPOSCCON_EMCLKEN                  = SCU_HPOSCCON^9;
sbit SCU_HPOSCCON_EMFINDISEN               = SCU_HPOSCCON^10;
sbit SCU_HPOSCCON_OSC2L0                   = SCU_HPOSCCON^12;
sbit SCU_HPOSCCON_OSC2L1                   = SCU_HPOSCCON^11;
sbit SCU_HPOSCCON_OSCWDTRST                = SCU_HPOSCCON^1;
sbit SCU_HPOSCCON_PLLV                     = SCU_HPOSCCON^0;
sbit SCU_HPOSCCON_SHBY                     = SCU_HPOSCCON^8;
sbit SCU_HPOSCCON_X1D                      = SCU_HPOSCCON^6;
sbit SCU_HPOSCCON_X1DEN                    = SCU_HPOSCCON^7;

// Chip Identification Register
sfr  SCU_IDCHIP                       = 0xF07C;

// Manufacturer Identification Register
sfr  SCU_IDMANUF                      = 0xF07E;

// Program Memory Identification Register
sfr  SCU_IDMEM                        = 0xF07A;

// Programming Voltage Id. Register
sfr  SCU_IDPROG                       = 0xF078;

// Interrupt Clear Register
sfr  SCU_INTCLR                       = 0xFE82;

// Interrupt Disable Register
sfr  SCU_INTDIS                       = 0xFE84;

// Interrupt Node Pointer 0 Register
sfr  SCU_INTNP0                       = 0xFE86;

// Interrupt Node Pointer 1 Register
sfr  SCU_INTNP1                       = 0xFE88;

// Interrupt Set Register
sfr  SCU_INTSET                       = 0xFE80;

// Interrupt Status Register
sfr  SCU_INTSTAT                      = 0xFF00;
sbit SCU_INTSTAT_GSCI                     = SCU_INTSTAT^9;
sbit SCU_INTSTAT_PVC1I1                   = SCU_INTSTAT^4;
sbit SCU_INTSTAT_PVC1I2                   = SCU_INTSTAT^5;
sbit SCU_INTSTAT_PVCMI1                   = SCU_INTSTAT^2;
sbit SCU_INTSTAT_PVCMI2                   = SCU_INTSTAT^3;
sbit SCU_INTSTAT_SWDI1                    = SCU_INTSTAT^0;
sbit SCU_INTSTAT_SWDI2                    = SCU_INTSTAT^1;
sbit SCU_INTSTAT_WDTI                     = SCU_INTSTAT^8;
sbit SCU_INTSTAT_WUI                      = SCU_INTSTAT^7;
sbit SCU_INTSTAT_WUTI                     = SCU_INTSTAT^6;

// Interrupt Source Select Register
sfr  SCU_ISSR                         = 0xFF2E;
sbit SCU_ISSR_ISS0                     = SCU_ISSR^0;
sbit SCU_ISSR_ISS1                     = SCU_ISSR^1;
sbit SCU_ISSR_ISS10                    = SCU_ISSR^10;
sbit SCU_ISSR_ISS11                    = SCU_ISSR^11;
sbit SCU_ISSR_ISS12                    = SCU_ISSR^12;
sbit SCU_ISSR_ISS13                    = SCU_ISSR^13;
sbit SCU_ISSR_ISS14                    = SCU_ISSR^14;
sbit SCU_ISSR_ISS15                    = SCU_ISSR^15;
sbit SCU_ISSR_ISS2                     = SCU_ISSR^2;
sbit SCU_ISSR_ISS3                     = SCU_ISSR^3;
sbit SCU_ISSR_ISS4                     = SCU_ISSR^4;
sbit SCU_ISSR_ISS5                     = SCU_ISSR^5;
sbit SCU_ISSR_ISS6                     = SCU_ISSR^6;
sbit SCU_ISSR_ISS7                     = SCU_ISSR^7;
sbit SCU_ISSR_ISS8                     = SCU_ISSR^8;
sbit SCU_ISSR_ISS9                     = SCU_ISSR^9;

// Marker Memory 0 Register
sfr  SCU_MKMEM0                       = 0xFED0;

// Marker Memory 1 Register
sfr  SCU_MKMEM1                       = 0xFED2;

// Marker Memory 2 Register
sfr  SCU_MKMEM2                       = 0xFED4;

// Marker Memory 3 Register
sfr  SCU_MKMEM3                       = 0xFED6;

// PLL Configuration 0 Register
sfr  SCU_PLLCON0                      = 0xF1B8;
sbit SCU_PLLCON0_NACK                     = SCU_PLLCON0^15;
sbit SCU_PLLCON0_REGENCLR                 = SCU_PLLCON0^4;
sbit SCU_PLLCON0_REGENSET                 = SCU_PLLCON0^5;
sbit SCU_PLLCON0_VCOBY                    = SCU_PLLCON0^0;
sbit SCU_PLLCON0_VCOPWD                   = SCU_PLLCON0^1;

// PLL Configuration 1 Register
sfr  SCU_PLLCON1                      = 0xF1BA;
sbit SCU_PLLCON1_AOSCSEL                  = SCU_PLLCON1^3;
sbit SCU_PLLCON1_EMCLKEN                  = SCU_PLLCON1^5;
sbit SCU_PLLCON1_EMFINDISEN               = SCU_PLLCON1^6;
sbit SCU_PLLCON1_OSCSEL                   = SCU_PLLCON1^1;
sbit SCU_PLLCON1_PACK                     = SCU_PLLCON1^15;
sbit SCU_PLLCON1_PLLPWD                   = SCU_PLLCON1^0;
sbit SCU_PLLCON1_RESLD                    = SCU_PLLCON1^2;

// PLL Configuration 2 Register
sfr  SCU_PLLCON2                      = 0xF1BC;
sbit SCU_PLLCON2_K1ACK                    = SCU_PLLCON2^15;

// PLL Configuration 3 Register
sfr  SCU_PLLCON3                      = 0xF1BE;
sbit SCU_PLLCON3_K2ACK                    = SCU_PLLCON3^15;

// PLL OSC Configuration Register
sfr  SCU_PLLOSCCON                    = 0xF1B6;
sbit SCU_PLLOSCCON_OSCPD                    = SCU_PLLOSCCON^0;

// PLL Status Register
sfr  SCU_PLLSTAT                      = 0xF0BC;

// PSC Status Register
#define SCU_PSCSTAT            (*((unsigned int volatile sdata *) 0xFFE8))

// PVC_1 Control Step 0 Register
sfr  SCU_PVC1CON0                     = 0xF014;

// PVC_1 Control for Step 1Set A Register
sfr  SCU_PVC1CONA1                    = 0xF016;

// PVC_1 Control for Step 2 Set A Register
sfr  SCU_PVC1CONA2                    = 0xF018;

// PVC_1 Control for Step 3 Set A Register
sfr  SCU_PVC1CONA3                    = 0xF01A;

// PVC_1 Control for Step 4 Set A Register
sfr  SCU_PVC1CONA4                    = 0xF01C;

// PVC_1 Control for Step 5 Set A Register
sfr  SCU_PVC1CONA5                    = 0xF01E;

// PVC_1 Control for Step 6 Set A Register
sfr  SCU_PVC1CONA6                    = 0xF020;

// PVC_1 Control for Step 1 Set B Register
sfr  SCU_PVC1CONB1                    = 0xF024;

// PVC_1 Control for Step 2 Set B Register
sfr  SCU_PVC1CONB2                    = 0xF026;

// PVC_1 Control for Step 3 Set B Register
sfr  SCU_PVC1CONB3                    = 0xF028;

// PVC_1 Control for Step 4 Set B Register
sfr  SCU_PVC1CONB4                    = 0xF02A;

// PVC_1 Control for Step 5 Set B Register
sfr  SCU_PVC1CONB5                    = 0xF02C;

// PVC_1 Control for Step 6 Set B Register
sfr  SCU_PVC1CONB6                    = 0xF02E;

// PVC_M Control Step 0 Register
#define SCU_PVCMCON0           (*((unsigned int volatile sdata *) 0xF1E4))

// PVC_M Control for Step 1 Set A Register
#define SCU_PVCMCONA1          (*((unsigned int volatile sdata *) 0xF1E6))

// PVC_M Control for Step 2 Set A Register
#define SCU_PVCMCONA2          (*((unsigned int volatile sdata *) 0xF1E8))

// PVC_M Control for Step 3 Set A Register
#define SCU_PVCMCONA3          (*((unsigned int volatile sdata *) 0xF1EA))

// PVC_M Control for Step 4 Set A Register
#define SCU_PVCMCONA4          (*((unsigned int volatile sdata *) 0xF1EC))

// PVC_M Control for Step 5 Set A Register
#define SCU_PVCMCONA5          (*((unsigned int volatile sdata *) 0xF1EE))

// PVC_M Control for Step 6 Set A Register
#define SCU_PVCMCONA6          (*((unsigned int volatile sdata *) 0xF1F0))

// PVC_M Control for Step 1 Set B Register
#define SCU_PVCMCONB1          (*((unsigned int volatile sdata *) 0xF1F4))

// PVC_M Control for Step 2 Set B Register
#define SCU_PVCMCONB2          (*((unsigned int volatile sdata *) 0xF1F6))

// PVC_M Control for Step 3 Set B Register
#define SCU_PVCMCONB3          (*((unsigned int volatile sdata *) 0xF1F8))

// PVC_M Control for Step 4 Set B Register
#define SCU_PVCMCONB4          (*((unsigned int volatile sdata *) 0xF1FA))

// PVC_M Control for Step 5 Set B Register
#define SCU_PVCMCONB5          (*((unsigned int volatile sdata *) 0xF1FC))

// PVC_M Control for Step 6 Set B Register
#define SCU_PVCMCONB6          (*((unsigned int volatile sdata *) 0xF1FE))

// Reset Counter Control Register
sfr  SCU_RSTCNTCON                    = 0xF1B2;

// Reset Configuration 0 Register
sfr  SCU_RSTCON0                      = 0xF0B8;

// Reset Configuration 1 Register
sfr  SCU_RSTCON1                      = 0xF0BA;

// Reset Status 0 Register
sfr  SCU_RSTSTAT0                     = 0xF0B2;

// Reset Status 1 Register
sfr  SCU_RSTSTAT1                     = 0xF0B4;

// Reset Status 2 Register
sfr  SCU_RSTSTAT2                     = 0xF0B6;

// RTC Clock Control Register
sfr  SCU_RTCCLKCON                    = 0xFF4E;
sbit SCU_RTCCLKCON_RTCCM                    = SCU_RTCCLKCON^2;

// Sequence Step 1 for Set A Register
sfr  SCU_SEQASTEP1                    = 0xFEE6;

// Sequence Step 2 for Set A Register
sfr  SCU_SEQASTEP2                    = 0xFEE8;

// Sequence Step 3 for Set A Register
sfr  SCU_SEQASTEP3                    = 0xFEEA;

// Sequence Step 4 for Set A Register
sfr  SCU_SEQASTEP4                    = 0xFEEC;

// Sequence Step 5 for Set A Register
sfr  SCU_SEQASTEP5                    = 0xFEEE;

// Sequence Step 6 for Set A Register
sfr  SCU_SEQASTEP6                    = 0xFEF0;

// Sequence Step 1 for Set B Register
sfr  SCU_SEQBSTEP1                    = 0xFEF4;

// Sequence Step 2 for Set B Register
sfr  SCU_SEQBSTEP2                    = 0xFEF6;

// Sequence Step 3 for Set B Register
sfr  SCU_SEQBSTEP3                    = 0xFEF8;

// Sequence Step 4 for Set B Register
sfr  SCU_SEQBSTEP4                    = 0xFEFA;

// Sequence Step 5 for Set B Register
sfr  SCU_SEQBSTEP5                    = 0xFEFC;

// Sequence Step 6 for Set B Register
sfr  SCU_SEQBSTEP6                    = 0xFEFE;

// Sequence Control Register
sfr  SCU_SEQCON                       = 0xFEE4;

// Security Level Command Register
sfr  SCU_SLC                          = 0xF0C0;

// Security Level Status Register
sfr  SCU_SLS                          = 0xF0C2;

// Status Clear 0 Register
sfr  SCU_STATCLR0                     = 0xF0E0;

// Status Clear 1 Register
sfr  SCU_STATCLR1                     = 0xF0E2;

// Start-up Configuration Register
#define SCU_STCON              (*((unsigned int volatile sdata *) 0xF1E2))

// Step 0 Register
sfr  SCU_STEP0                        = 0xFEF2;

// Start-up Memory 0 Register
sfr  SCU_STMEM0                       = 0xF0A0;

// Start-up Status Register
#define SCU_STSTAT             (*((unsigned int volatile sdata *) 0xF1E0))

// SWD Control 0 Register
sfr  SCU_SWDCON0                      = 0xF080;

// SWD Control 1 Register
sfr  SCU_SWDCON1                      = 0xF082;

// SW Reset Control Register
sfr  SCU_SWRSTCON                     = 0xF0AE;

// System Control 0 Register
sfr  SCU_SYSCON0                      = 0xFF4A;
sbit SCU_SYSCON0_EMCLKSELEN               = SCU_SYSCON0^6;
sbit SCU_SYSCON0_EMSOSC                   = SCU_SYSCON0^12;
sbit SCU_SYSCON0_EMSPWR                   = SCU_SYSCON0^14;
sbit SCU_SYSCON0_EMSVCO                   = SCU_SYSCON0^13;
sbit SCU_SYSCON0_SELSTAT                  = SCU_SYSCON0^15;

// System Control 1 Register
sfr  SCU_SYSCON1                      = 0xFF4C;
sbit SCU_SYSCON1_GLCCST                   = SCU_SYSCON1^3;
sbit SCU_SYSCON1_OCDSEN                   = SCU_SYSCON1^2;
sbit SCU_SYSCON1_VRMDS                    = SCU_SYSCON1^1;
sbit SCU_SYSCON1_VRMPS                    = SCU_SYSCON1^0;

// Temperature Compensation Register
sfr  SCU_TCCR                         = 0xF1AC;
sbit SCU_TCCR_TCE                      = SCU_TCCR^7;

// Temperature Comp. Level Register
sfr  SCU_TCLR                         = 0xF0AC;

// Trap Clear Register
sfr  SCU_TRAPCLR                      = 0xFE8E;

// Trap Disable Register
sfr  SCU_TRAPDIS                      = 0xFE90;

// Trap Node Pointer Register
sfr  SCU_TRAPNP                       = 0xFE92;

// Trap Set Register
sfr  SCU_TRAPSET                      = 0xFE8C;

// Trap Status Register
sfr  SCU_TRAPSTAT                     = 0xFF02;
sbit SCU_TRAPSTAT_ESR0T                    = SCU_TRAPSTAT^1;
sbit SCU_TRAPSTAT_ESR1T                    = SCU_TRAPSTAT^2;
sbit SCU_TRAPSTAT_ESR2T                    = SCU_TRAPSTAT^3;
sbit SCU_TRAPSTAT_FAT                      = SCU_TRAPSTAT^0;
sbit SCU_TRAPSTAT_OSCWDTT                  = SCU_TRAPSTAT^4;
sbit SCU_TRAPSTAT_PET                      = SCU_TRAPSTAT^6;
sbit SCU_TRAPSTAT_RAT                      = SCU_TRAPSTAT^5;
sbit SCU_TRAPSTAT_VCOLCKT                  = SCU_TRAPSTAT^7;

// WDT Control and Status Register
sfr  SCU_WDTCS                        = 0xF0C6;

// WDT Reload Register
sfr  SCU_WDTREL                       = 0xF0C8;

// WDT Timer Register
sfr  SCU_WDTTIM                       = 0xF0CA;

// Wake-up Interval Count Register
sfr  SCU_WICR                         = 0xF0B0;

// Wake-up Control Register
sfr  SCU_WUCR                         = 0xF1B0;
sbit SCU_WUCR_AON                      = SCU_WUCR^9;
sbit SCU_WUCR_ASP                      = SCU_WUCR^10;
sbit SCU_WUCR_CLRTRG                   = SCU_WUCR^7;
sbit SCU_WUCR_RUN                      = SCU_WUCR^8;
sbit SCU_WUCR_TTSTAT                   = SCU_WUCR^14;
sbit SCU_WUCR_WUTRG                    = SCU_WUCR^15;

// Wake-up OSC Control Register
sfr  SCU_WUOSCCON                     = 0xF1AE;
sbit SCU_WUOSCCON_DIS                      = SCU_WUOSCCON^4;

// Stack Pointer
sfr  SP                               = 0xFE12;

// Stack Pointer Segment
sfr  SPSEG                            = 0xFF0C;

// PEC Source Pointer 0
#define SRCP0                  (*((unsigned int volatile sdata *) 0xEC40))

// PEC Source Pointer 1
#define SRCP1                  (*((unsigned int volatile sdata *) 0xEC44))

// PEC Source Pointer 2
#define SRCP2                  (*((unsigned int volatile sdata *) 0xEC48))

// PEC Source Pointer 3
#define SRCP3                  (*((unsigned int volatile sdata *) 0xEC4C))

// PEC Source Pointer 4
#define SRCP4                  (*((unsigned int volatile sdata *) 0xEC50))

// PEC Source Pointer 5
#define SRCP5                  (*((unsigned int volatile sdata *) 0xEC54))

// PEC Source Pointer 6
#define SRCP6                  (*((unsigned int volatile sdata *) 0xEC58))

// PEC Source Pointer 7
#define SRCP7                  (*((unsigned int volatile sdata *) 0xEC5C))

// Stack Overflow Pointer
sfr  STKOV                            = 0xFE14;

// Stack Underflow Pointer
sfr  STKUN                            = 0xFE16;

// Trap Flag Register
sfr  TFR                              = 0xFFAC;
sbit TFR_ACER                     = TFR^4;
sbit TFR_ILLOPA                   = TFR^2;
sbit TFR_PRTFLT                   = TFR^3;
sbit TFR_SOFTBRK                  = TFR^12;
sbit TFR_SR0                      = TFR^15;
sbit TFR_SR1                      = TFR^11;
sbit TFR_STKOF                    = TFR^14;
sbit TFR_STKUF                    = TFR^13;
sbit TFR_UNDOPC                   = TFR^7;

// USIC Interrupt Control Reg. 0
sfr  U0C0_0IC                         = 0xF120;
sbit U0C0_0IC_GPX                      = U0C0_0IC^8;
sbit U0C0_0IC_IE                       = U0C0_0IC^6;
sbit U0C0_0IC_IR                       = U0C0_0IC^7;

// USIC Interrupt Control Reg. 1
sfr  U0C0_1IC                         = 0xF122;
sbit U0C0_1IC_GPX                      = U0C0_1IC^8;
sbit U0C0_1IC_IE                       = U0C0_1IC^6;
sbit U0C0_1IC_IR                       = U0C0_1IC^7;

// USIC Interrupt Control Reg. 2
sfr  U0C0_2IC                         = 0xF124;
sbit U0C0_2IC_GPX                      = U0C0_2IC^8;
sbit U0C0_2IC_IE                       = U0C0_2IC^6;
sbit U0C0_2IC_IR                       = U0C0_2IC^7;

// Baud Rate Generator Register H
#define U0C0_BRGH              (*((unsigned int volatile huge *) 0x20401E))

// Baud Rate Generator Register L
#define U0C0_BRGL              (*((unsigned int volatile huge *) 0x20401C))

// Bypass Data Register
#define U0C0_BYP               (*((unsigned int volatile huge *) 0x204100))

// Bypass Control Register H
#define U0C0_BYPCRH            (*((unsigned int volatile huge *) 0x204106))

// Bypass Control Register L
#define U0C0_BYPCRL            (*((unsigned int volatile huge *) 0x204104))

// Channel Configuration Register
#define U0C0_CCFG              (*((unsigned int volatile huge *) 0x204018))

// Channel Control Register
#define U0C0_CCR               (*((unsigned int volatile huge *) 0x204010))

// I0put Control Register n
#define U0C0_DX0CR             (*((unsigned int volatile huge *) 0x204020))

// I1put Control Register n
#define U0C0_DX1CR             (*((unsigned int volatile huge *) 0x204024))

// I2put Control Register n
#define U0C0_DX2CR             (*((unsigned int volatile huge *) 0x204028))

// Error Detection and Correction Test Register H
#define U0C0_EDCRH             (*((unsigned int volatile huge *) 0x20406E))

// Error Detection and Correction Test Register L
#define U0C0_EDCRL             (*((unsigned int volatile huge *) 0x20406C))

// Fractional Divider Register H
#define U0C0_FDRH              (*((unsigned int volatile huge *) 0x204006))

// Fractional Divider Register L
#define U0C0_FDRL              (*((unsigned int volatile huge *) 0x204004))

// Flag Modification Register H
#define U0C0_FMRH              (*((unsigned int volatile huge *) 0x20403A))

// Flag Modification Register L
#define U0C0_FMRL              (*((unsigned int volatile huge *) 0x204038))

// Transmit FIFO Input Location 00
#define U0C0_IN00              (*((unsigned int volatile huge *) 0x204180))

// Transmit FIFO Input Location 01
#define U0C0_IN01              (*((unsigned int volatile huge *) 0x204184))

// Transmit FIFO Input Location 02
#define U0C0_IN02              (*((unsigned int volatile huge *) 0x204188))

// Transmit FIFO Input Location 03
#define U0C0_IN03              (*((unsigned int volatile huge *) 0x20418C))

// Transmit FIFO Input Location 04
#define U0C0_IN04              (*((unsigned int volatile huge *) 0x204190))

// Transmit FIFO Input Location 05
#define U0C0_IN05              (*((unsigned int volatile huge *) 0x204194))

// Transmit FIFO Input Location 06
#define U0C0_IN06              (*((unsigned int volatile huge *) 0x204198))

// Transmit FIFO Input Location 07
#define U0C0_IN07              (*((unsigned int volatile huge *) 0x20419C))

// Transmit FIFO Input Location 08
#define U0C0_IN08              (*((unsigned int volatile huge *) 0x2041A0))

// Transmit FIFO Input Location 09
#define U0C0_IN09              (*((unsigned int volatile huge *) 0x2041A4))

// Transmit FIFO Input Location 10
#define U0C0_IN10              (*((unsigned int volatile huge *) 0x2041A8))

// Transmit FIFO Input Location 11
#define U0C0_IN11              (*((unsigned int volatile huge *) 0x2041AC))

// Transmit FIFO Input Location 12
#define U0C0_IN12              (*((unsigned int volatile huge *) 0x2041B0))

// Transmit FIFO Input Location 13
#define U0C0_IN13              (*((unsigned int volatile huge *) 0x2041B4))

// Transmit FIFO Input Location 14
#define U0C0_IN14              (*((unsigned int volatile huge *) 0x2041B8))

// Transmit FIFO Input Location 15
#define U0C0_IN15              (*((unsigned int volatile huge *) 0x2041BC))

// Transmit FIFO Input Location 16
#define U0C0_IN16              (*((unsigned int volatile huge *) 0x2041C0))

// Transmit FIFO Input Location 17
#define U0C0_IN17              (*((unsigned int volatile huge *) 0x2041C4))

// Transmit FIFO Input Location 18
#define U0C0_IN18              (*((unsigned int volatile huge *) 0x2041C8))

// Transmit FIFO Input Location 19
#define U0C0_IN19              (*((unsigned int volatile huge *) 0x2041CC))

// Transmit FIFO Input Location 20
#define U0C0_IN20              (*((unsigned int volatile huge *) 0x2041D0))

// Transmit FIFO Input Location 21
#define U0C0_IN21              (*((unsigned int volatile huge *) 0x2041D4))

// Transmit FIFO Input Location 22
#define U0C0_IN22              (*((unsigned int volatile huge *) 0x2041D8))

// Transmit FIFO Input Location 23
#define U0C0_IN23              (*((unsigned int volatile huge *) 0x2041DC))

// Transmit FIFO Input Location 24
#define U0C0_IN24              (*((unsigned int volatile huge *) 0x2041E0))

// Transmit FIFO Input Location 25
#define U0C0_IN25              (*((unsigned int volatile huge *) 0x2041E4))

// Transmit FIFO Input Location 26
#define U0C0_IN26              (*((unsigned int volatile huge *) 0x2041E8))

// Transmit FIFO Input Location 27
#define U0C0_IN27              (*((unsigned int volatile huge *) 0x2041EC))

// Transmit FIFO Input Location 28
#define U0C0_IN28              (*((unsigned int volatile huge *) 0x2041F0))

// Transmit FIFO Input Location 29
#define U0C0_IN29              (*((unsigned int volatile huge *) 0x2041F4))

// Transmit FIFO Input Location 30
#define U0C0_IN30              (*((unsigned int volatile huge *) 0x2041F8))

// Transmit FIFO Input Location 31
#define U0C0_IN31              (*((unsigned int volatile huge *) 0x2041FC))

// Interrupt Node Pointer Register H
#define U0C0_INPRH             (*((unsigned int volatile huge *) 0x204016))

// Interrupt Node Pointer Register L
#define U0C0_INPRL             (*((unsigned int volatile huge *) 0x204014))

// Kernel State Configuration Register
#define U0C0_KSCFG             (*((unsigned int volatile huge *) 0x20400C))

// Receiver Buffer Output Register H for Debugger
#define U0C0_OUTDRH            (*((unsigned int volatile huge *) 0x204126))

// Receiver Buffer Output Register L for Debugger
#define U0C0_OUTDRL            (*((unsigned int volatile huge *) 0x204124))

// Receiver Buffer Output Register H
#define U0C0_OUTRH             (*((unsigned int volatile huge *) 0x204122))

// Receiver Buffer Output Register L
#define U0C0_OUTRL             (*((unsigned int volatile huge *) 0x204120))

// Protocol Control Register H
#define U0C0_PCRH              (*((unsigned int volatile huge *) 0x204042))

// Protocol Control Register L
#define U0C0_PCRL              (*((unsigned int volatile huge *) 0x204040))

// Protocol Status Clear Register
#define U0C0_PSCR              (*((unsigned int volatile huge *) 0x204048))

// Protocol Status Register
#define U0C0_PSR               (*((unsigned int volatile huge *) 0x204044))

// Receiver Buffer Control Register H
#define U0C0_RBCTRH            (*((unsigned int volatile huge *) 0x204116))

// Receiver Buffer Control Register L
#define U0C0_RBCTRL            (*((unsigned int volatile huge *) 0x204114))

// Receiver Buffer Register
#define U0C0_RBUF              (*((unsigned int volatile huge *) 0x20405C))

// Receiver Buffer Register 0
#define U0C0_RBUF0             (*((unsigned int volatile huge *) 0x204050))

// Receiver Buffer 01 Status Register H
#define U0C0_RBUF01SRH         (*((unsigned int volatile huge *) 0x204062))

// Receiver Buffer 01 Status Register L
#define U0C0_RBUF01SRL         (*((unsigned int volatile huge *) 0x204060))

// Receiver Buffer Register 1
#define U0C0_RBUF1             (*((unsigned int volatile huge *) 0x204054))

// Receiver Buffer Reg. for Debugger
#define U0C0_RBUFD             (*((unsigned int volatile huge *) 0x20404C))

// Receiver Buffer Status Register
#define U0C0_RBUFSR            (*((unsigned int volatile huge *) 0x204058))

// Shift Control Register H
#define U0C0_SCTRH             (*((unsigned int volatile huge *) 0x204032))

// Shift Control Register L
#define U0C0_SCTRL             (*((unsigned int volatile huge *) 0x204030))

// Transmitter Buffer Control Reg. H
#define U0C0_TBCTRH            (*((unsigned int volatile huge *) 0x204112))

// Transmitter Buffer Control Reg. L
#define U0C0_TBCTRL            (*((unsigned int volatile huge *) 0x204110))

// Transmit Buffer Location 00
#define U0C0_TBUF00            (*((unsigned int volatile huge *) 0x204080))

// Transmit Buffer Location 01
#define U0C0_TBUF01            (*((unsigned int volatile huge *) 0x204084))

// Transmit Buffer Location 02
#define U0C0_TBUF02            (*((unsigned int volatile huge *) 0x204088))

// Transmit Buffer Location 03
#define U0C0_TBUF03            (*((unsigned int volatile huge *) 0x20408C))

// Transmit Buffer Location 04
#define U0C0_TBUF04            (*((unsigned int volatile huge *) 0x204090))

// Transmit Buffer Location 05
#define U0C0_TBUF05            (*((unsigned int volatile huge *) 0x204094))

// Transmit Buffer Location 06
#define U0C0_TBUF06            (*((unsigned int volatile huge *) 0x204098))

// Transmit Buffer Location 07
#define U0C0_TBUF07            (*((unsigned int volatile huge *) 0x20409C))

// Transmit Buffer Location 08
#define U0C0_TBUF08            (*((unsigned int volatile huge *) 0x2040A0))

// Transmit Buffer Location 09
#define U0C0_TBUF09            (*((unsigned int volatile huge *) 0x2040A4))

// Transmit Buffer Location 10
#define U0C0_TBUF10            (*((unsigned int volatile huge *) 0x2040A8))

// Transmit Buffer Location 11
#define U0C0_TBUF11            (*((unsigned int volatile huge *) 0x2040AC))

// Transmit Buffer Location 12
#define U0C0_TBUF12            (*((unsigned int volatile huge *) 0x2040B0))

// Transmit Buffer Location 13
#define U0C0_TBUF13            (*((unsigned int volatile huge *) 0x2040B4))

// Transmit Buffer Location 14
#define U0C0_TBUF14            (*((unsigned int volatile huge *) 0x2040B8))

// Transmit Buffer Location 15
#define U0C0_TBUF15            (*((unsigned int volatile huge *) 0x2040BC))

// Transmit Buffer Location 16
#define U0C0_TBUF16            (*((unsigned int volatile huge *) 0x2040C0))

// Transmit Buffer Location 17
#define U0C0_TBUF17            (*((unsigned int volatile huge *) 0x2040C4))

// Transmit Buffer Location 18
#define U0C0_TBUF18            (*((unsigned int volatile huge *) 0x2040C8))

// Transmit Buffer Location 19
#define U0C0_TBUF19            (*((unsigned int volatile huge *) 0x2040CC))

// Transmit Buffer Location 20
#define U0C0_TBUF20            (*((unsigned int volatile huge *) 0x2040D0))

// Transmit Buffer Location 21
#define U0C0_TBUF21            (*((unsigned int volatile huge *) 0x2040D4))

// Transmit Buffer Location 22
#define U0C0_TBUF22            (*((unsigned int volatile huge *) 0x2040D8))

// Transmit Buffer Location 23
#define U0C0_TBUF23            (*((unsigned int volatile huge *) 0x2040DC))

// Transmit Buffer Location 24
#define U0C0_TBUF24            (*((unsigned int volatile huge *) 0x2040E0))

// Transmit Buffer Location 25
#define U0C0_TBUF25            (*((unsigned int volatile huge *) 0x2040E4))

// Transmit Buffer Location 26
#define U0C0_TBUF26            (*((unsigned int volatile huge *) 0x2040E8))

// Transmit Buffer Location 27
#define U0C0_TBUF27            (*((unsigned int volatile huge *) 0x2040EC))

// Transmit Buffer Location 28
#define U0C0_TBUF28            (*((unsigned int volatile huge *) 0x2040F0))

// Transmit Buffer Location 29
#define U0C0_TBUF29            (*((unsigned int volatile huge *) 0x2040F4))

// Transmit Buffer Location 30
#define U0C0_TBUF30            (*((unsigned int volatile huge *) 0x2040F8))

// Transmit Buffer Location 31
#define U0C0_TBUF31            (*((unsigned int volatile huge *) 0x2040FC))

// Transmit Control/Status Register H
#define U0C0_TCSRH             (*((unsigned int volatile huge *) 0x20403E))

// Transmit Control/Status Register L
#define U0C0_TCSRL             (*((unsigned int volatile huge *) 0x20403C))

// Transmit / Receive Buffer Pointer Reg H
#define U0C0_TRBPTRH           (*((unsigned int volatile huge *) 0x20410A))

// Transmit / Receive Buffer Pointer Reg L
#define U0C0_TRBPTRL           (*((unsigned int volatile huge *) 0x204108))

// Transmit / Receive Buffer Status Clear Reg
#define U0C0_TRBSCR            (*((unsigned int volatile huge *) 0x20411C))

// Transmit / Receive Buffer Status Reg H
#define U0C0_TRBSRH            (*((unsigned int volatile huge *) 0x20411A))

// Transmit / Receive Buffer Status Reg. L
#define U0C0_TRBSRL            (*((unsigned int volatile huge *) 0x204118))

// USIC Interrupt Control Reg. 0
sfr  U0C1_0IC                         = 0xF126;
sbit U0C1_0IC_GPX                      = U0C1_0IC^8;
sbit U0C1_0IC_IE                       = U0C1_0IC^6;
sbit U0C1_0IC_IR                       = U0C1_0IC^7;

// USIC Interrupt Control Reg. 1
sfr  U0C1_1IC                         = 0xF128;
sbit U0C1_1IC_GPX                      = U0C1_1IC^8;
sbit U0C1_1IC_IE                       = U0C1_1IC^6;
sbit U0C1_1IC_IR                       = U0C1_1IC^7;

// USIC Interrupt Control Reg. 2
sfr  U0C1_2IC                         = 0xF12A;
sbit U0C1_2IC_GPX                      = U0C1_2IC^8;
sbit U0C1_2IC_IE                       = U0C1_2IC^6;
sbit U0C1_2IC_IR                       = U0C1_2IC^7;

// Baud Rate Generator Register H
#define U0C1_BRGH              (*((unsigned int volatile huge *) 0x20421E))

// Baud Rate Generator Register L
#define U0C1_BRGL              (*((unsigned int volatile huge *) 0x20421C))

// Bypass Data Register
#define U0C1_BYP               (*((unsigned int volatile huge *) 0x204300))

// Bypass Control Register H
#define U0C1_BYPCRH            (*((unsigned int volatile huge *) 0x204306))

// Bypass Control Register L
#define U0C1_BYPCRL            (*((unsigned int volatile huge *) 0x204304))

// Channel Configuration Register
#define U0C1_CCFG              (*((unsigned int volatile huge *) 0x204218))

// Channel Control Register
#define U0C1_CCR               (*((unsigned int volatile huge *) 0x204210))

// I0put Control Register n
#define U0C1_DX0CR             (*((unsigned int volatile huge *) 0x204220))

// I1put Control Register n
#define U0C1_DX1CR             (*((unsigned int volatile huge *) 0x204224))

// I2put Control Register n
#define U0C1_DX2CR             (*((unsigned int volatile huge *) 0x204228))

// Error Detection and Correction Test Register H
#define U0C1_EDCRH             (*((unsigned int volatile huge *) 0x20426E))

// Error Detection and Correction Test Register L
#define U0C1_EDCRL             (*((unsigned int volatile huge *) 0x20426C))

// Fractional Divider Register H
#define U0C1_FDRH              (*((unsigned int volatile huge *) 0x204206))

// Fractional Divider Register L
#define U0C1_FDRL              (*((unsigned int volatile huge *) 0x204204))

// Flag Modification Register H
#define U0C1_FMRH              (*((unsigned int volatile huge *) 0x20423A))

// Flag Modification Register L
#define U0C1_FMRL              (*((unsigned int volatile huge *) 0x204238))

// Transmit FIFO Input Location 00
#define U0C1_IN00              (*((unsigned int volatile huge *) 0x204380))

// Transmit FIFO Input Location 01
#define U0C1_IN01              (*((unsigned int volatile huge *) 0x204384))

// Transmit FIFO Input Location 02
#define U0C1_IN02              (*((unsigned int volatile huge *) 0x204388))

// Transmit FIFO Input Location 03
#define U0C1_IN03              (*((unsigned int volatile huge *) 0x20438C))

// Transmit FIFO Input Location 04
#define U0C1_IN04              (*((unsigned int volatile huge *) 0x204390))

// Transmit FIFO Input Location 05
#define U0C1_IN05              (*((unsigned int volatile huge *) 0x204394))

// Transmit FIFO Input Location 06
#define U0C1_IN06              (*((unsigned int volatile huge *) 0x204398))

// Transmit FIFO Input Location 07
#define U0C1_IN07              (*((unsigned int volatile huge *) 0x20439C))

// Transmit FIFO Input Location 08
#define U0C1_IN08              (*((unsigned int volatile huge *) 0x2043A0))

// Transmit FIFO Input Location 09
#define U0C1_IN09              (*((unsigned int volatile huge *) 0x2043A4))

// Transmit FIFO Input Location 10
#define U0C1_IN10              (*((unsigned int volatile huge *) 0x2043A8))

// Transmit FIFO Input Location 11
#define U0C1_IN11              (*((unsigned int volatile huge *) 0x2043AC))

// Transmit FIFO Input Location 12
#define U0C1_IN12              (*((unsigned int volatile huge *) 0x2043B0))

// Transmit FIFO Input Location 13
#define U0C1_IN13              (*((unsigned int volatile huge *) 0x2043B4))

// Transmit FIFO Input Location 14
#define U0C1_IN14              (*((unsigned int volatile huge *) 0x2043B8))

// Transmit FIFO Input Location 15
#define U0C1_IN15              (*((unsigned int volatile huge *) 0x2043BC))

// Transmit FIFO Input Location 16
#define U0C1_IN16              (*((unsigned int volatile huge *) 0x2043C0))

// Transmit FIFO Input Location 17
#define U0C1_IN17              (*((unsigned int volatile huge *) 0x2043C4))

// Transmit FIFO Input Location 18
#define U0C1_IN18              (*((unsigned int volatile huge *) 0x2043C8))

// Transmit FIFO Input Location 19
#define U0C1_IN19              (*((unsigned int volatile huge *) 0x2043CC))

// Transmit FIFO Input Location 20
#define U0C1_IN20              (*((unsigned int volatile huge *) 0x2043D0))

// Transmit FIFO Input Location 21
#define U0C1_IN21              (*((unsigned int volatile huge *) 0x2043D4))

// Transmit FIFO Input Location 22
#define U0C1_IN22              (*((unsigned int volatile huge *) 0x2043D8))

// Transmit FIFO Input Location 23
#define U0C1_IN23              (*((unsigned int volatile huge *) 0x2043DC))

// Transmit FIFO Input Location 24
#define U0C1_IN24              (*((unsigned int volatile huge *) 0x2043E0))

// Transmit FIFO Input Location 25
#define U0C1_IN25              (*((unsigned int volatile huge *) 0x2043E4))

// Transmit FIFO Input Location 26
#define U0C1_IN26              (*((unsigned int volatile huge *) 0x2043E8))

// Transmit FIFO Input Location 27
#define U0C1_IN27              (*((unsigned int volatile huge *) 0x2043EC))

// Transmit FIFO Input Location 28
#define U0C1_IN28              (*((unsigned int volatile huge *) 0x2043F0))

// Transmit FIFO Input Location 29
#define U0C1_IN29              (*((unsigned int volatile huge *) 0x2043F4))

// Transmit FIFO Input Location 30
#define U0C1_IN30              (*((unsigned int volatile huge *) 0x2043F8))

// Transmit FIFO Input Location 31
#define U0C1_IN31              (*((unsigned int volatile huge *) 0x2043FC))

// Interrupt Node Pointer Register H
#define U0C1_INPRH             (*((unsigned int volatile huge *) 0x204216))

// Interrupt Node Pointer Register L
#define U0C1_INPRL             (*((unsigned int volatile huge *) 0x204214))

// Kernel State Configuration Register
#define U0C1_KSCFG             (*((unsigned int volatile huge *) 0x20420C))

// Receiver Buffer Output Register H for Debugger
#define U0C1_OUTDRH            (*((unsigned int volatile huge *) 0x204326))

// Receiver Buffer Output Register L for Debugger
#define U0C1_OUTDRL            (*((unsigned int volatile huge *) 0x204324))

// Receiver Buffer Output Register H
#define U0C1_OUTRH             (*((unsigned int volatile huge *) 0x204322))

// Receiver Buffer Output Register L
#define U0C1_OUTRL             (*((unsigned int volatile huge *) 0x204320))

// Protocol Control Register H
#define U0C1_PCRH              (*((unsigned int volatile huge *) 0x204242))

// Protocol Control Register L
#define U0C1_PCRL              (*((unsigned int volatile huge *) 0x204240))

// Protocol Status Clear Register
#define U0C1_PSCR              (*((unsigned int volatile huge *) 0x204248))

// Protocol Status Register
#define U0C1_PSR               (*((unsigned int volatile huge *) 0x204244))

// Receiver Buffer Control Register H
#define U0C1_RBCTRH            (*((unsigned int volatile huge *) 0x204316))

// Receiver Buffer Control Register L
#define U0C1_RBCTRL            (*((unsigned int volatile huge *) 0x204314))

// Receiver Buffer Register
#define U0C1_RBUF              (*((unsigned int volatile huge *) 0x20425C))

// Receiver Buffer Register 0
#define U0C1_RBUF0             (*((unsigned int volatile huge *) 0x204250))

// Receiver Buffer 01 Status Register H
#define U0C1_RBUF01SRH         (*((unsigned int volatile huge *) 0x204262))

// Receiver Buffer 01 Status Register L
#define U0C1_RBUF01SRL         (*((unsigned int volatile huge *) 0x204260))

// Receiver Buffer Register 1
#define U0C1_RBUF1             (*((unsigned int volatile huge *) 0x204254))

// Receiver Buffer Reg. for Debugger
#define U0C1_RBUFD             (*((unsigned int volatile huge *) 0x20424C))

// Receiver Buffer Status Register
#define U0C1_RBUFSR            (*((unsigned int volatile huge *) 0x204258))

// Shift Control Register H
#define U0C1_SCTRH             (*((unsigned int volatile huge *) 0x204232))

// Shift Control Register L
#define U0C1_SCTRL             (*((unsigned int volatile huge *) 0x204230))

// Transmitter Buffer Control Reg. H
#define U0C1_TBCTRH            (*((unsigned int volatile huge *) 0x204312))

// Transmitter Buffer Control Reg. L
#define U0C1_TBCTRL            (*((unsigned int volatile huge *) 0x204310))

// Transmit Buffer Location 00
#define U0C1_TBUF00            (*((unsigned int volatile huge *) 0x204280))

// Transmit Buffer Location 01
#define U0C1_TBUF01            (*((unsigned int volatile huge *) 0x204284))

// Transmit Buffer Location 02
#define U0C1_TBUF02            (*((unsigned int volatile huge *) 0x204288))

// Transmit Buffer Location 03
#define U0C1_TBUF03            (*((unsigned int volatile huge *) 0x20428C))

// Transmit Buffer Location 04
#define U0C1_TBUF04            (*((unsigned int volatile huge *) 0x204290))

// Transmit Buffer Location 05
#define U0C1_TBUF05            (*((unsigned int volatile huge *) 0x204294))

// Transmit Buffer Location 06
#define U0C1_TBUF06            (*((unsigned int volatile huge *) 0x204298))

// Transmit Buffer Location 07
#define U0C1_TBUF07            (*((unsigned int volatile huge *) 0x20429C))

// Transmit Buffer Location 08
#define U0C1_TBUF08            (*((unsigned int volatile huge *) 0x2042A0))

// Transmit Buffer Location 09
#define U0C1_TBUF09            (*((unsigned int volatile huge *) 0x2042A4))

// Transmit Buffer Location 10
#define U0C1_TBUF10            (*((unsigned int volatile huge *) 0x2042A8))

// Transmit Buffer Location 11
#define U0C1_TBUF11            (*((unsigned int volatile huge *) 0x2042AC))

// Transmit Buffer Location 12
#define U0C1_TBUF12            (*((unsigned int volatile huge *) 0x2042B0))

// Transmit Buffer Location 13
#define U0C1_TBUF13            (*((unsigned int volatile huge *) 0x2042B4))

// Transmit Buffer Location 14
#define U0C1_TBUF14            (*((unsigned int volatile huge *) 0x2042B8))

// Transmit Buffer Location 15
#define U0C1_TBUF15            (*((unsigned int volatile huge *) 0x2042BC))

// Transmit Buffer Location 16
#define U0C1_TBUF16            (*((unsigned int volatile huge *) 0x2042C0))

// Transmit Buffer Location 17
#define U0C1_TBUF17            (*((unsigned int volatile huge *) 0x2042C4))

// Transmit Buffer Location 18
#define U0C1_TBUF18            (*((unsigned int volatile huge *) 0x2042C8))

// Transmit Buffer Location 19
#define U0C1_TBUF19            (*((unsigned int volatile huge *) 0x2042CC))

// Transmit Buffer Location 20
#define U0C1_TBUF20            (*((unsigned int volatile huge *) 0x2042D0))

// Transmit Buffer Location 21
#define U0C1_TBUF21            (*((unsigned int volatile huge *) 0x2042D4))

// Transmit Buffer Location 22
#define U0C1_TBUF22            (*((unsigned int volatile huge *) 0x2042D8))

// Transmit Buffer Location 23
#define U0C1_TBUF23            (*((unsigned int volatile huge *) 0x2042DC))

// Transmit Buffer Location 24
#define U0C1_TBUF24            (*((unsigned int volatile huge *) 0x2042E0))

// Transmit Buffer Location 25
#define U0C1_TBUF25            (*((unsigned int volatile huge *) 0x2042E4))

// Transmit Buffer Location 26
#define U0C1_TBUF26            (*((unsigned int volatile huge *) 0x2042E8))

// Transmit Buffer Location 27
#define U0C1_TBUF27            (*((unsigned int volatile huge *) 0x2042EC))

// Transmit Buffer Location 28
#define U0C1_TBUF28            (*((unsigned int volatile huge *) 0x2042F0))

// Transmit Buffer Location 29
#define U0C1_TBUF29            (*((unsigned int volatile huge *) 0x2042F4))

// Transmit Buffer Location 30
#define U0C1_TBUF30            (*((unsigned int volatile huge *) 0x2042F8))

// Transmit Buffer Location 31
#define U0C1_TBUF31            (*((unsigned int volatile huge *) 0x2042FC))

// Transmit Control/Status Register H
#define U0C1_TCSRH             (*((unsigned int volatile huge *) 0x20423E))

// Transmit Control/Status Register L
#define U0C1_TCSRL             (*((unsigned int volatile huge *) 0x20423C))

// Transmit / Receive Buffer Pointer Reg H
#define U0C1_TRBPTRH           (*((unsigned int volatile huge *) 0x20430A))

// Transmit / Receive Buffer Pointer Reg L
#define U0C1_TRBPTRL           (*((unsigned int volatile huge *) 0x204308))

// Transmit / Receive Buffer Status Clear Reg
#define U0C1_TRBSCR            (*((unsigned int volatile huge *) 0x20431C))

// Transmit / Receive Buffer Status Reg H
#define U0C1_TRBSRH            (*((unsigned int volatile huge *) 0x20431A))

// Transmit / Receive Buffer Status Reg. L
#define U0C1_TRBSRL            (*((unsigned int volatile huge *) 0x204318))

// USIC Interrupt Control Reg. 0
sfr  U1C0_0IC                         = 0xF12C;
sbit U1C0_0IC_GPX                      = U1C0_0IC^8;
sbit U1C0_0IC_IE                       = U1C0_0IC^6;
sbit U1C0_0IC_IR                       = U1C0_0IC^7;

// USIC Interrupt Control Reg. 1
sfr  U1C0_1IC                         = 0xF12E;
sbit U1C0_1IC_GPX                      = U1C0_1IC^8;
sbit U1C0_1IC_IE                       = U1C0_1IC^6;
sbit U1C0_1IC_IR                       = U1C0_1IC^7;

// USIC Interrupt Control Reg. 2
sfr  U1C0_2IC                         = 0xF130;
sbit U1C0_2IC_GPX                      = U1C0_2IC^8;
sbit U1C0_2IC_IE                       = U1C0_2IC^6;
sbit U1C0_2IC_IR                       = U1C0_2IC^7;

// Baud Rate Generator Register H
#define U1C0_BRGH              (*((unsigned int volatile huge *) 0x20481E))

// Baud Rate Generator Register L
#define U1C0_BRGL              (*((unsigned int volatile huge *) 0x20481C))

// Bypass Data Register
#define U1C0_BYP               (*((unsigned int volatile huge *) 0x204900))

// Bypass Control Register H
#define U1C0_BYPCRH            (*((unsigned int volatile huge *) 0x204906))

// Bypass Control Register L
#define U1C0_BYPCRL            (*((unsigned int volatile huge *) 0x204904))

// Channel Configuration Register
#define U1C0_CCFG              (*((unsigned int volatile huge *) 0x204818))

// Channel Control Register
#define U1C0_CCR               (*((unsigned int volatile huge *) 0x204810))

// I0put Control Register n
#define U1C0_DX0CR             (*((unsigned int volatile huge *) 0x204820))

// I1put Control Register n
#define U1C0_DX1CR             (*((unsigned int volatile huge *) 0x204824))

// I2put Control Register n
#define U1C0_DX2CR             (*((unsigned int volatile huge *) 0x204828))

// Error Detection and Correction Test Register H
#define U1C0_EDCRH             (*((unsigned int volatile huge *) 0x20486E))

// Error Detection and Correction Test Register L
#define U1C0_EDCRL             (*((unsigned int volatile huge *) 0x20486C))

// Fractional Divider Register H
#define U1C0_FDRH              (*((unsigned int volatile huge *) 0x204806))

// Fractional Divider Register L
#define U1C0_FDRL              (*((unsigned int volatile huge *) 0x204804))

// Flag Modification Register H
#define U1C0_FMRH              (*((unsigned int volatile huge *) 0x20483A))

// Flag Modification Register L
#define U1C0_FMRL              (*((unsigned int volatile huge *) 0x204838))

// Transmit FIFO Input Location 00
#define U1C0_IN00              (*((unsigned int volatile huge *) 0x204980))

// Transmit FIFO Input Location 01
#define U1C0_IN01              (*((unsigned int volatile huge *) 0x204984))

// Transmit FIFO Input Location 02
#define U1C0_IN02              (*((unsigned int volatile huge *) 0x204988))

// Transmit FIFO Input Location 03
#define U1C0_IN03              (*((unsigned int volatile huge *) 0x20498C))

// Transmit FIFO Input Location 04
#define U1C0_IN04              (*((unsigned int volatile huge *) 0x204990))

// Transmit FIFO Input Location 05
#define U1C0_IN05              (*((unsigned int volatile huge *) 0x204994))

// Transmit FIFO Input Location 06
#define U1C0_IN06              (*((unsigned int volatile huge *) 0x204998))

// Transmit FIFO Input Location 07
#define U1C0_IN07              (*((unsigned int volatile huge *) 0x20499C))

// Transmit FIFO Input Location 08
#define U1C0_IN08              (*((unsigned int volatile huge *) 0x2049A0))

// Transmit FIFO Input Location 09
#define U1C0_IN09              (*((unsigned int volatile huge *) 0x2049A4))

// Transmit FIFO Input Location 10
#define U1C0_IN10              (*((unsigned int volatile huge *) 0x2049A8))

// Transmit FIFO Input Location 11
#define U1C0_IN11              (*((unsigned int volatile huge *) 0x2049AC))

// Transmit FIFO Input Location 12
#define U1C0_IN12              (*((unsigned int volatile huge *) 0x2049B0))

// Transmit FIFO Input Location 13
#define U1C0_IN13              (*((unsigned int volatile huge *) 0x2049B4))

// Transmit FIFO Input Location 14
#define U1C0_IN14              (*((unsigned int volatile huge *) 0x2049B8))

// Transmit FIFO Input Location 15
#define U1C0_IN15              (*((unsigned int volatile huge *) 0x2049BC))

// Transmit FIFO Input Location 16
#define U1C0_IN16              (*((unsigned int volatile huge *) 0x2049C0))

// Transmit FIFO Input Location 17
#define U1C0_IN17              (*((unsigned int volatile huge *) 0x2049C4))

// Transmit FIFO Input Location 18
#define U1C0_IN18              (*((unsigned int volatile huge *) 0x2049C8))

// Transmit FIFO Input Location 19
#define U1C0_IN19              (*((unsigned int volatile huge *) 0x2049CC))

// Transmit FIFO Input Location 20
#define U1C0_IN20              (*((unsigned int volatile huge *) 0x2049D0))

// Transmit FIFO Input Location 21
#define U1C0_IN21              (*((unsigned int volatile huge *) 0x2049D4))

// Transmit FIFO Input Location 22
#define U1C0_IN22              (*((unsigned int volatile huge *) 0x2049D8))

// Transmit FIFO Input Location 23
#define U1C0_IN23              (*((unsigned int volatile huge *) 0x2049DC))

// Transmit FIFO Input Location 24
#define U1C0_IN24              (*((unsigned int volatile huge *) 0x2049E0))

// Transmit FIFO Input Location 25
#define U1C0_IN25              (*((unsigned int volatile huge *) 0x2049E4))

// Transmit FIFO Input Location 26
#define U1C0_IN26              (*((unsigned int volatile huge *) 0x2049E8))

// Transmit FIFO Input Location 27
#define U1C0_IN27              (*((unsigned int volatile huge *) 0x2049EC))

// Transmit FIFO Input Location 28
#define U1C0_IN28              (*((unsigned int volatile huge *) 0x2049F0))

// Transmit FIFO Input Location 29
#define U1C0_IN29              (*((unsigned int volatile huge *) 0x2049F4))

// Transmit FIFO Input Location 30
#define U1C0_IN30              (*((unsigned int volatile huge *) 0x2049F8))

// Transmit FIFO Input Location 31
#define U1C0_IN31              (*((unsigned int volatile huge *) 0x2049FC))

// Interrupt Node Pointer Register H
#define U1C0_INPRH             (*((unsigned int volatile huge *) 0x204816))

// Interrupt Node Pointer Register L
#define U1C0_INPRL             (*((unsigned int volatile huge *) 0x204814))

// Kernel State Configuration Register
#define U1C0_KSCFG             (*((unsigned int volatile huge *) 0x20480C))

// Receiver Buffer Output Register H for Debugger
#define U1C0_OUTDRH            (*((unsigned int volatile huge *) 0x204926))

// Receiver Buffer Output Register L for Debugger
#define U1C0_OUTDRL            (*((unsigned int volatile huge *) 0x204924))

// Receiver Buffer Output Register H
#define U1C0_OUTRH             (*((unsigned int volatile huge *) 0x204922))

// Receiver Buffer Output Register L
#define U1C0_OUTRL             (*((unsigned int volatile huge *) 0x204920))

// Protocol Control Register H
#define U1C0_PCRH              (*((unsigned int volatile huge *) 0x204842))

// Protocol Control Register L
#define U1C0_PCRL              (*((unsigned int volatile huge *) 0x204840))

// Protocol Status Clear Register
#define U1C0_PSCR              (*((unsigned int volatile huge *) 0x204848))

// Protocol Status Register
#define U1C0_PSR               (*((unsigned int volatile huge *) 0x204844))

// Receiver Buffer Control Register H
#define U1C0_RBCTRH            (*((unsigned int volatile huge *) 0x204916))

// Receiver Buffer Control Register L
#define U1C0_RBCTRL            (*((unsigned int volatile huge *) 0x204914))

// Receiver Buffer Register
#define U1C0_RBUF              (*((unsigned int volatile huge *) 0x20485C))

// Receiver Buffer Register 0
#define U1C0_RBUF0             (*((unsigned int volatile huge *) 0x204850))

// Receiver Buffer 01 Status Register H
#define U1C0_RBUF01SRH         (*((unsigned int volatile huge *) 0x204862))

// Receiver Buffer 01 Status Register L
#define U1C0_RBUF01SRL         (*((unsigned int volatile huge *) 0x204860))

// Receiver Buffer Register 1
#define U1C0_RBUF1             (*((unsigned int volatile huge *) 0x204854))

// Receiver Buffer Reg. for Debugger
#define U1C0_RBUFD             (*((unsigned int volatile huge *) 0x20484C))

// Receiver Buffer Status Register
#define U1C0_RBUFSR            (*((unsigned int volatile huge *) 0x204858))

// Shift Control Register H
#define U1C0_SCTRH             (*((unsigned int volatile huge *) 0x204832))

// Shift Control Register L
#define U1C0_SCTRL             (*((unsigned int volatile huge *) 0x204830))

// Transmitter Buffer Control Reg. H
#define U1C0_TBCTRH            (*((unsigned int volatile huge *) 0x204912))

// Transmitter Buffer Control Reg. L
#define U1C0_TBCTRL            (*((unsigned int volatile huge *) 0x204910))

// Transmit Buffer Location 00
#define U1C0_TBUF00            (*((unsigned int volatile huge *) 0x204880))

// Transmit Buffer Location 01
#define U1C0_TBUF01            (*((unsigned int volatile huge *) 0x204884))

// Transmit Buffer Location 02
#define U1C0_TBUF02            (*((unsigned int volatile huge *) 0x204888))

// Transmit Buffer Location 03
#define U1C0_TBUF03            (*((unsigned int volatile huge *) 0x20488C))

// Transmit Buffer Location 04
#define U1C0_TBUF04            (*((unsigned int volatile huge *) 0x204890))

// Transmit Buffer Location 05
#define U1C0_TBUF05            (*((unsigned int volatile huge *) 0x204894))

// Transmit Buffer Location 06
#define U1C0_TBUF06            (*((unsigned int volatile huge *) 0x204898))

// Transmit Buffer Location 07
#define U1C0_TBUF07            (*((unsigned int volatile huge *) 0x20489C))

// Transmit Buffer Location 08
#define U1C0_TBUF08            (*((unsigned int volatile huge *) 0x2048A0))

// Transmit Buffer Location 09
#define U1C0_TBUF09            (*((unsigned int volatile huge *) 0x2048A4))

// Transmit Buffer Location 10
#define U1C0_TBUF10            (*((unsigned int volatile huge *) 0x2048A8))

// Transmit Buffer Location 11
#define U1C0_TBUF11            (*((unsigned int volatile huge *) 0x2048AC))

// Transmit Buffer Location 12
#define U1C0_TBUF12            (*((unsigned int volatile huge *) 0x2048B0))

// Transmit Buffer Location 13
#define U1C0_TBUF13            (*((unsigned int volatile huge *) 0x2048B4))

// Transmit Buffer Location 14
#define U1C0_TBUF14            (*((unsigned int volatile huge *) 0x2048B8))

// Transmit Buffer Location 15
#define U1C0_TBUF15            (*((unsigned int volatile huge *) 0x2048BC))

// Transmit Buffer Location 16
#define U1C0_TBUF16            (*((unsigned int volatile huge *) 0x2048C0))

// Transmit Buffer Location 17
#define U1C0_TBUF17            (*((unsigned int volatile huge *) 0x2048C4))

// Transmit Buffer Location 18
#define U1C0_TBUF18            (*((unsigned int volatile huge *) 0x2048C8))

// Transmit Buffer Location 19
#define U1C0_TBUF19            (*((unsigned int volatile huge *) 0x2048CC))

// Transmit Buffer Location 20
#define U1C0_TBUF20            (*((unsigned int volatile huge *) 0x2048D0))

// Transmit Buffer Location 21
#define U1C0_TBUF21            (*((unsigned int volatile huge *) 0x2048D4))

// Transmit Buffer Location 22
#define U1C0_TBUF22            (*((unsigned int volatile huge *) 0x2048D8))

// Transmit Buffer Location 23
#define U1C0_TBUF23            (*((unsigned int volatile huge *) 0x2048DC))

// Transmit Buffer Location 24
#define U1C0_TBUF24            (*((unsigned int volatile huge *) 0x2048E0))

// Transmit Buffer Location 25
#define U1C0_TBUF25            (*((unsigned int volatile huge *) 0x2048E4))

// Transmit Buffer Location 26
#define U1C0_TBUF26            (*((unsigned int volatile huge *) 0x2048E8))

// Transmit Buffer Location 27
#define U1C0_TBUF27            (*((unsigned int volatile huge *) 0x2048EC))

// Transmit Buffer Location 28
#define U1C0_TBUF28            (*((unsigned int volatile huge *) 0x2048F0))

// Transmit Buffer Location 29
#define U1C0_TBUF29            (*((unsigned int volatile huge *) 0x2048F4))

// Transmit Buffer Location 30
#define U1C0_TBUF30            (*((unsigned int volatile huge *) 0x2048F8))

// Transmit Buffer Location 31
#define U1C0_TBUF31            (*((unsigned int volatile huge *) 0x2048FC))

// Transmit Control/Status Register H
#define U1C0_TCSRH             (*((unsigned int volatile huge *) 0x20483E))

// Transmit Control/Status Register L
#define U1C0_TCSRL             (*((unsigned int volatile huge *) 0x20483C))

// Transmit / Receive Buffer Pointer Reg H
#define U1C0_TRBPTRH           (*((unsigned int volatile huge *) 0x20490A))

// Transmit / Receive Buffer Pointer Reg L
#define U1C0_TRBPTRL           (*((unsigned int volatile huge *) 0x204908))

// Transmit / Receive Buffer Status Clear Reg
#define U1C0_TRBSCR            (*((unsigned int volatile huge *) 0x20491C))

// Transmit / Receive Buffer Status Reg H
#define U1C0_TRBSRH            (*((unsigned int volatile huge *) 0x20491A))

// Transmit / Receive Buffer Status Reg. L
#define U1C0_TRBSRL            (*((unsigned int volatile huge *) 0x204918))

// USIC Interrupt Control Reg. 0
sfr  U1C1_0IC                         = 0xF132;
sbit U1C1_0IC_GPX                      = U1C1_0IC^8;
sbit U1C1_0IC_IE                       = U1C1_0IC^6;
sbit U1C1_0IC_IR                       = U1C1_0IC^7;

// USIC Interrupt Control Reg. 1
sfr  U1C1_1IC                         = 0xF134;
sbit U1C1_1IC_GPX                      = U1C1_1IC^8;
sbit U1C1_1IC_IE                       = U1C1_1IC^6;
sbit U1C1_1IC_IR                       = U1C1_1IC^7;

// USIC Interrupt Control Reg. 2
sfr  U1C1_2IC                         = 0xF136;
sbit U1C1_2IC_GPX                      = U1C1_2IC^8;
sbit U1C1_2IC_IE                       = U1C1_2IC^6;
sbit U1C1_2IC_IR                       = U1C1_2IC^7;

// Baud Rate Generator Register H
#define U1C1_BRGH              (*((unsigned int volatile huge *) 0x204A1E))

// Baud Rate Generator Register L
#define U1C1_BRGL              (*((unsigned int volatile huge *) 0x204A1C))

// Bypass Data Register
#define U1C1_BYP               (*((unsigned int volatile huge *) 0x204B00))

// Bypass Control Register H
#define U1C1_BYPCRH            (*((unsigned int volatile huge *) 0x204B06))

// Bypass Control Register L
#define U1C1_BYPCRL            (*((unsigned int volatile huge *) 0x204B04))

// Channel Configuration Register
#define U1C1_CCFG              (*((unsigned int volatile huge *) 0x204A18))

// Channel Control Register
#define U1C1_CCR               (*((unsigned int volatile huge *) 0x204A10))

// I0put Control Register n
#define U1C1_DX0CR             (*((unsigned int volatile huge *) 0x204A20))

// I1put Control Register n
#define U1C1_DX1CR             (*((unsigned int volatile huge *) 0x204A24))

// I2put Control Register n
#define U1C1_DX2CR             (*((unsigned int volatile huge *) 0x204A28))

// Error Detection and Correction Test Register H
#define U1C1_EDCRH             (*((unsigned int volatile huge *) 0x204A6E))

// Error Detection and Correction Test Register L
#define U1C1_EDCRL             (*((unsigned int volatile huge *) 0x204A6C))

// Fractional Divider Register H
#define U1C1_FDRH              (*((unsigned int volatile huge *) 0x204A06))

// Fractional Divider Register L
#define U1C1_FDRL              (*((unsigned int volatile huge *) 0x204A04))

// Flag Modification Register H
#define U1C1_FMRH              (*((unsigned int volatile huge *) 0x204A3A))

// Flag Modification Register L
#define U1C1_FMRL              (*((unsigned int volatile huge *) 0x204A38))

// Transmit FIFO Input Location 00
#define U1C1_IN00              (*((unsigned int volatile huge *) 0x204B80))

// Transmit FIFO Input Location 01
#define U1C1_IN01              (*((unsigned int volatile huge *) 0x204B84))

// Transmit FIFO Input Location 02
#define U1C1_IN02              (*((unsigned int volatile huge *) 0x204B88))

// Transmit FIFO Input Location 03
#define U1C1_IN03              (*((unsigned int volatile huge *) 0x204B8C))

// Transmit FIFO Input Location 04
#define U1C1_IN04              (*((unsigned int volatile huge *) 0x204B90))

// Transmit FIFO Input Location 05
#define U1C1_IN05              (*((unsigned int volatile huge *) 0x204B94))

// Transmit FIFO Input Location 06
#define U1C1_IN06              (*((unsigned int volatile huge *) 0x204B98))

// Transmit FIFO Input Location 07
#define U1C1_IN07              (*((unsigned int volatile huge *) 0x204B9C))

// Transmit FIFO Input Location 08
#define U1C1_IN08              (*((unsigned int volatile huge *) 0x204BA0))

// Transmit FIFO Input Location 09
#define U1C1_IN09              (*((unsigned int volatile huge *) 0x204BA4))

// Transmit FIFO Input Location 10
#define U1C1_IN10              (*((unsigned int volatile huge *) 0x204BA8))

// Transmit FIFO Input Location 11
#define U1C1_IN11              (*((unsigned int volatile huge *) 0x204BAC))

// Transmit FIFO Input Location 12
#define U1C1_IN12              (*((unsigned int volatile huge *) 0x204BB0))

// Transmit FIFO Input Location 13
#define U1C1_IN13              (*((unsigned int volatile huge *) 0x204BB4))

// Transmit FIFO Input Location 14
#define U1C1_IN14              (*((unsigned int volatile huge *) 0x204BB8))

// Transmit FIFO Input Location 15
#define U1C1_IN15              (*((unsigned int volatile huge *) 0x204BBC))

// Transmit FIFO Input Location 16
#define U1C1_IN16              (*((unsigned int volatile huge *) 0x204BC0))

// Transmit FIFO Input Location 17
#define U1C1_IN17              (*((unsigned int volatile huge *) 0x204BC4))

// Transmit FIFO Input Location 18
#define U1C1_IN18              (*((unsigned int volatile huge *) 0x204BC8))

// Transmit FIFO Input Location 19
#define U1C1_IN19              (*((unsigned int volatile huge *) 0x204BCC))

// Transmit FIFO Input Location 20
#define U1C1_IN20              (*((unsigned int volatile huge *) 0x204BD0))

// Transmit FIFO Input Location 21
#define U1C1_IN21              (*((unsigned int volatile huge *) 0x204BD4))

// Transmit FIFO Input Location 22
#define U1C1_IN22              (*((unsigned int volatile huge *) 0x204BD8))

// Transmit FIFO Input Location 23
#define U1C1_IN23              (*((unsigned int volatile huge *) 0x204BDC))

// Transmit FIFO Input Location 24
#define U1C1_IN24              (*((unsigned int volatile huge *) 0x204BE0))

// Transmit FIFO Input Location 25
#define U1C1_IN25              (*((unsigned int volatile huge *) 0x204BE4))

// Transmit FIFO Input Location 26
#define U1C1_IN26              (*((unsigned int volatile huge *) 0x204BE8))

// Transmit FIFO Input Location 27
#define U1C1_IN27              (*((unsigned int volatile huge *) 0x204BEC))

// Transmit FIFO Input Location 28
#define U1C1_IN28              (*((unsigned int volatile huge *) 0x204BF0))

// Transmit FIFO Input Location 29
#define U1C1_IN29              (*((unsigned int volatile huge *) 0x204BF4))

// Transmit FIFO Input Location 30
#define U1C1_IN30              (*((unsigned int volatile huge *) 0x204BF8))

// Transmit FIFO Input Location 31
#define U1C1_IN31              (*((unsigned int volatile huge *) 0x204BFC))

// Interrupt Node Pointer Register H
#define U1C1_INPRH             (*((unsigned int volatile huge *) 0x204A16))

// Interrupt Node Pointer Register L
#define U1C1_INPRL             (*((unsigned int volatile huge *) 0x204A14))

// Kernel State Configuration Register
#define U1C1_KSCFG             (*((unsigned int volatile huge *) 0x204A0C))

// Receiver Buffer Output Register H for Debugger
#define U1C1_OUTDRH            (*((unsigned int volatile huge *) 0x204B26))

// Receiver Buffer Output Register L for Debugger
#define U1C1_OUTDRL            (*((unsigned int volatile huge *) 0x204B24))

// Receiver Buffer Output Register H
#define U1C1_OUTRH             (*((unsigned int volatile huge *) 0x204B22))

// Receiver Buffer Output Register L
#define U1C1_OUTRL             (*((unsigned int volatile huge *) 0x204B20))

// Protocol Control Register H
#define U1C1_PCRH              (*((unsigned int volatile huge *) 0x204A42))

// Protocol Control Register L
#define U1C1_PCRL              (*((unsigned int volatile huge *) 0x204A40))

// Protocol Status Clear Register
#define U1C1_PSCR              (*((unsigned int volatile huge *) 0x204A48))

// Protocol Status Register
#define U1C1_PSR               (*((unsigned int volatile huge *) 0x204A44))

// Receiver Buffer Control Register H
#define U1C1_RBCTRH            (*((unsigned int volatile huge *) 0x204B16))

// Receiver Buffer Control Register L
#define U1C1_RBCTRL            (*((unsigned int volatile huge *) 0x204B14))

// Receiver Buffer Register
#define U1C1_RBUF              (*((unsigned int volatile huge *) 0x204A5C))

// Receiver Buffer Register 0
#define U1C1_RBUF0             (*((unsigned int volatile huge *) 0x204A50))

// Receiver Buffer 01 Status Register H
#define U1C1_RBUF01SRH         (*((unsigned int volatile huge *) 0x204A62))

// Receiver Buffer 01 Status Register L
#define U1C1_RBUF01SRL         (*((unsigned int volatile huge *) 0x204A60))

// Receiver Buffer Register 1
#define U1C1_RBUF1             (*((unsigned int volatile huge *) 0x204A54))

// Receiver Buffer Reg. for Debugger
#define U1C1_RBUFD             (*((unsigned int volatile huge *) 0x204A4C))

// Receiver Buffer Status Register
#define U1C1_RBUFSR            (*((unsigned int volatile huge *) 0x204A58))

// Shift Control Register H
#define U1C1_SCTRH             (*((unsigned int volatile huge *) 0x204A32))

// Shift Control Register L
#define U1C1_SCTRL             (*((unsigned int volatile huge *) 0x204A30))

// Transmitter Buffer Control Reg. H
#define U1C1_TBCTRH            (*((unsigned int volatile huge *) 0x204B12))

// Transmitter Buffer Control Reg. L
#define U1C1_TBCTRL            (*((unsigned int volatile huge *) 0x204B10))

// Transmit Buffer Location 00
#define U1C1_TBUF00            (*((unsigned int volatile huge *) 0x204A80))

// Transmit Buffer Location 01
#define U1C1_TBUF01            (*((unsigned int volatile huge *) 0x204A84))

// Transmit Buffer Location 02
#define U1C1_TBUF02            (*((unsigned int volatile huge *) 0x204A88))

// Transmit Buffer Location 03
#define U1C1_TBUF03            (*((unsigned int volatile huge *) 0x204A8C))

// Transmit Buffer Location 04
#define U1C1_TBUF04            (*((unsigned int volatile huge *) 0x204A90))

// Transmit Buffer Location 05
#define U1C1_TBUF05            (*((unsigned int volatile huge *) 0x204A94))

// Transmit Buffer Location 06
#define U1C1_TBUF06            (*((unsigned int volatile huge *) 0x204A98))

// Transmit Buffer Location 07
#define U1C1_TBUF07            (*((unsigned int volatile huge *) 0x204A9C))

// Transmit Buffer Location 08
#define U1C1_TBUF08            (*((unsigned int volatile huge *) 0x204AA0))

// Transmit Buffer Location 09
#define U1C1_TBUF09            (*((unsigned int volatile huge *) 0x204AA4))

// Transmit Buffer Location 10
#define U1C1_TBUF10            (*((unsigned int volatile huge *) 0x204AA8))

// Transmit Buffer Location 11
#define U1C1_TBUF11            (*((unsigned int volatile huge *) 0x204AAC))

// Transmit Buffer Location 12
#define U1C1_TBUF12            (*((unsigned int volatile huge *) 0x204AB0))

// Transmit Buffer Location 13
#define U1C1_TBUF13            (*((unsigned int volatile huge *) 0x204AB4))

// Transmit Buffer Location 14
#define U1C1_TBUF14            (*((unsigned int volatile huge *) 0x204AB8))

// Transmit Buffer Location 15
#define U1C1_TBUF15            (*((unsigned int volatile huge *) 0x204ABC))

// Transmit Buffer Location 16
#define U1C1_TBUF16            (*((unsigned int volatile huge *) 0x204AC0))

// Transmit Buffer Location 17
#define U1C1_TBUF17            (*((unsigned int volatile huge *) 0x204AC4))

// Transmit Buffer Location 18
#define U1C1_TBUF18            (*((unsigned int volatile huge *) 0x204AC8))

// Transmit Buffer Location 19
#define U1C1_TBUF19            (*((unsigned int volatile huge *) 0x204ACC))

// Transmit Buffer Location 20
#define U1C1_TBUF20            (*((unsigned int volatile huge *) 0x204AD0))

// Transmit Buffer Location 21
#define U1C1_TBUF21            (*((unsigned int volatile huge *) 0x204AD4))

// Transmit Buffer Location 22
#define U1C1_TBUF22            (*((unsigned int volatile huge *) 0x204AD8))

// Transmit Buffer Location 23
#define U1C1_TBUF23            (*((unsigned int volatile huge *) 0x204ADC))

// Transmit Buffer Location 24
#define U1C1_TBUF24            (*((unsigned int volatile huge *) 0x204AE0))

// Transmit Buffer Location 25
#define U1C1_TBUF25            (*((unsigned int volatile huge *) 0x204AE4))

// Transmit Buffer Location 26
#define U1C1_TBUF26            (*((unsigned int volatile huge *) 0x204AE8))

// Transmit Buffer Location 27
#define U1C1_TBUF27            (*((unsigned int volatile huge *) 0x204AEC))

// Transmit Buffer Location 28
#define U1C1_TBUF28            (*((unsigned int volatile huge *) 0x204AF0))

// Transmit Buffer Location 29
#define U1C1_TBUF29            (*((unsigned int volatile huge *) 0x204AF4))

// Transmit Buffer Location 30
#define U1C1_TBUF30            (*((unsigned int volatile huge *) 0x204AF8))

// Transmit Buffer Location 31
#define U1C1_TBUF31            (*((unsigned int volatile huge *) 0x204AFC))

// Transmit Control/Status Register H
#define U1C1_TCSRH             (*((unsigned int volatile huge *) 0x204A3E))

// Transmit Control/Status Register L
#define U1C1_TCSRL             (*((unsigned int volatile huge *) 0x204A3C))

// Transmit / Receive Buffer Pointer Reg H
#define U1C1_TRBPTRH           (*((unsigned int volatile huge *) 0x204B0A))

// Transmit / Receive Buffer Pointer Reg L
#define U1C1_TRBPTRL           (*((unsigned int volatile huge *) 0x204B08))

// Transmit / Receive Buffer Status Clear Reg
#define U1C1_TRBSCR            (*((unsigned int volatile huge *) 0x204B1C))

// Transmit / Receive Buffer Status Reg H
#define U1C1_TRBSRH            (*((unsigned int volatile huge *) 0x204B1A))

// Transmit / Receive Buffer Status Reg. L
#define U1C1_TRBSRL            (*((unsigned int volatile huge *) 0x204B18))

// USIC Interrupt Control Reg. 0
sfr  U2C0_0IC                         = 0xF138;
sbit U2C0_0IC_GPX                      = U2C0_0IC^8;
sbit U2C0_0IC_IE                       = U2C0_0IC^6;
sbit U2C0_0IC_IR                       = U2C0_0IC^7;

// USIC Interrupt Control Reg. 1
sfr  U2C0_1IC                         = 0xF13A;
sbit U2C0_1IC_GPX                      = U2C0_1IC^8;
sbit U2C0_1IC_IE                       = U2C0_1IC^6;
sbit U2C0_1IC_IR                       = U2C0_1IC^7;

// USIC Interrupt Control Reg. 2
sfr  U2C0_2IC                         = 0xF13C;
sbit U2C0_2IC_GPX                      = U2C0_2IC^8;
sbit U2C0_2IC_IE                       = U2C0_2IC^6;
sbit U2C0_2IC_IR                       = U2C0_2IC^7;

// Baud Rate Generator Register H
#define U2C0_BRGH              (*((unsigned int volatile huge *) 0x20501E))

// Baud Rate Generator Register L
#define U2C0_BRGL              (*((unsigned int volatile huge *) 0x20501C))

// Bypass Data Register
#define U2C0_BYP               (*((unsigned int volatile huge *) 0x205100))

// Bypass Control Register H
#define U2C0_BYPCRH            (*((unsigned int volatile huge *) 0x205106))

// Bypass Control Register L
#define U2C0_BYPCRL            (*((unsigned int volatile huge *) 0x205104))

// Channel Configuration Register
#define U2C0_CCFG              (*((unsigned int volatile huge *) 0x205018))

// Channel Control Register
#define U2C0_CCR               (*((unsigned int volatile huge *) 0x205010))

// I0put Control Register n
#define U2C0_DX0CR             (*((unsigned int volatile huge *) 0x205020))

// I1put Control Register n
#define U2C0_DX1CR             (*((unsigned int volatile huge *) 0x205024))

// I2put Control Register n
#define U2C0_DX2CR             (*((unsigned int volatile huge *) 0x205028))

// Error Detection and Correction Test Register H
#define U2C0_EDCRH             (*((unsigned int volatile huge *) 0x20506E))

// Error Detection and Correction Test Register L
#define U2C0_EDCRL             (*((unsigned int volatile huge *) 0x20506C))

// Fractional Divider Register H
#define U2C0_FDRH              (*((unsigned int volatile huge *) 0x205006))

// Fractional Divider Register L
#define U2C0_FDRL              (*((unsigned int volatile huge *) 0x205004))

// Flag Modification Register H
#define U2C0_FMRH              (*((unsigned int volatile huge *) 0x20503A))

// Flag Modification Register L
#define U2C0_FMRL              (*((unsigned int volatile huge *) 0x205038))

// Transmit FIFO Input Location 00
#define U2C0_IN00              (*((unsigned int volatile huge *) 0x205180))

// Transmit FIFO Input Location 01
#define U2C0_IN01              (*((unsigned int volatile huge *) 0x205184))

// Transmit FIFO Input Location 02
#define U2C0_IN02              (*((unsigned int volatile huge *) 0x205188))

// Transmit FIFO Input Location 03
#define U2C0_IN03              (*((unsigned int volatile huge *) 0x20518C))

// Transmit FIFO Input Location 04
#define U2C0_IN04              (*((unsigned int volatile huge *) 0x205190))

// Transmit FIFO Input Location 05
#define U2C0_IN05              (*((unsigned int volatile huge *) 0x205194))

// Transmit FIFO Input Location 06
#define U2C0_IN06              (*((unsigned int volatile huge *) 0x205198))

// Transmit FIFO Input Location 07
#define U2C0_IN07              (*((unsigned int volatile huge *) 0x20519C))

// Transmit FIFO Input Location 08
#define U2C0_IN08              (*((unsigned int volatile huge *) 0x2051A0))

// Transmit FIFO Input Location 09
#define U2C0_IN09              (*((unsigned int volatile huge *) 0x2051A4))

// Transmit FIFO Input Location 10
#define U2C0_IN10              (*((unsigned int volatile huge *) 0x2051A8))

// Transmit FIFO Input Location 11
#define U2C0_IN11              (*((unsigned int volatile huge *) 0x2051AC))

// Transmit FIFO Input Location 12
#define U2C0_IN12              (*((unsigned int volatile huge *) 0x2051B0))

// Transmit FIFO Input Location 13
#define U2C0_IN13              (*((unsigned int volatile huge *) 0x2051B4))

// Transmit FIFO Input Location 14
#define U2C0_IN14              (*((unsigned int volatile huge *) 0x2051B8))

// Transmit FIFO Input Location 15
#define U2C0_IN15              (*((unsigned int volatile huge *) 0x2051BC))

// Transmit FIFO Input Location 16
#define U2C0_IN16              (*((unsigned int volatile huge *) 0x2051C0))

// Transmit FIFO Input Location 17
#define U2C0_IN17              (*((unsigned int volatile huge *) 0x2051C4))

// Transmit FIFO Input Location 18
#define U2C0_IN18              (*((unsigned int volatile huge *) 0x2051C8))

// Transmit FIFO Input Location 19
#define U2C0_IN19              (*((unsigned int volatile huge *) 0x2051CC))

// Transmit FIFO Input Location 20
#define U2C0_IN20              (*((unsigned int volatile huge *) 0x2051D0))

// Transmit FIFO Input Location 21
#define U2C0_IN21              (*((unsigned int volatile huge *) 0x2051D4))

// Transmit FIFO Input Location 22
#define U2C0_IN22              (*((unsigned int volatile huge *) 0x2051D8))

// Transmit FIFO Input Location 23
#define U2C0_IN23              (*((unsigned int volatile huge *) 0x2051DC))

// Transmit FIFO Input Location 24
#define U2C0_IN24              (*((unsigned int volatile huge *) 0x2051E0))

// Transmit FIFO Input Location 25
#define U2C0_IN25              (*((unsigned int volatile huge *) 0x2051E4))

// Transmit FIFO Input Location 26
#define U2C0_IN26              (*((unsigned int volatile huge *) 0x2051E8))

// Transmit FIFO Input Location 27
#define U2C0_IN27              (*((unsigned int volatile huge *) 0x2051EC))

// Transmit FIFO Input Location 28
#define U2C0_IN28              (*((unsigned int volatile huge *) 0x2051F0))

// Transmit FIFO Input Location 29
#define U2C0_IN29              (*((unsigned int volatile huge *) 0x2051F4))

// Transmit FIFO Input Location 30
#define U2C0_IN30              (*((unsigned int volatile huge *) 0x2051F8))

// Transmit FIFO Input Location 31
#define U2C0_IN31              (*((unsigned int volatile huge *) 0x2051FC))

// Interrupt Node Pointer Register H
#define U2C0_INPRH             (*((unsigned int volatile huge *) 0x205016))

// Interrupt Node Pointer Register L
#define U2C0_INPRL             (*((unsigned int volatile huge *) 0x205014))

// Kernel State Configuration Register
#define U2C0_KSCFG             (*((unsigned int volatile huge *) 0x20500C))

// Receiver Buffer Output Register H for Debugger
#define U2C0_OUTDRH            (*((unsigned int volatile huge *) 0x205126))

// Receiver Buffer Output Register L for Debugger
#define U2C0_OUTDRL            (*((unsigned int volatile huge *) 0x205124))

// Receiver Buffer Output Register H
#define U2C0_OUTRH             (*((unsigned int volatile huge *) 0x205122))

// Receiver Buffer Output Register L
#define U2C0_OUTRL             (*((unsigned int volatile huge *) 0x205120))

// Protocol Control Register H
#define U2C0_PCRH              (*((unsigned int volatile huge *) 0x205042))

// Protocol Control Register L
#define U2C0_PCRL              (*((unsigned int volatile huge *) 0x205040))

// Protocol Status Clear Register
#define U2C0_PSCR              (*((unsigned int volatile huge *) 0x205048))

// Protocol Status Register
#define U2C0_PSR               (*((unsigned int volatile huge *) 0x205044))

// Receiver Buffer Control Register H
#define U2C0_RBCTRH            (*((unsigned int volatile huge *) 0x205116))

// Receiver Buffer Control Register L
#define U2C0_RBCTRL            (*((unsigned int volatile huge *) 0x205114))

// Receiver Buffer Register
#define U2C0_RBUF              (*((unsigned int volatile huge *) 0x20505C))

// Receiver Buffer Register 0
#define U2C0_RBUF0             (*((unsigned int volatile huge *) 0x205050))

// Receiver Buffer 01 Status Register H
#define U2C0_RBUF01SRH         (*((unsigned int volatile huge *) 0x205062))

// Receiver Buffer 01 Status Register L
#define U2C0_RBUF01SRL         (*((unsigned int volatile huge *) 0x205060))

// Receiver Buffer Register 1
#define U2C0_RBUF1             (*((unsigned int volatile huge *) 0x205054))

// Receiver Buffer Reg. for Debugger
#define U2C0_RBUFD             (*((unsigned int volatile huge *) 0x20504C))

// Receiver Buffer Status Register
#define U2C0_RBUFSR            (*((unsigned int volatile huge *) 0x205058))

// Shift Control Register H
#define U2C0_SCTRH             (*((unsigned int volatile huge *) 0x205032))

// Shift Control Register L
#define U2C0_SCTRL             (*((unsigned int volatile huge *) 0x205030))

// Transmitter Buffer Control Reg. H
#define U2C0_TBCTRH            (*((unsigned int volatile huge *) 0x205112))

// Transmitter Buffer Control Reg. L
#define U2C0_TBCTRL            (*((unsigned int volatile huge *) 0x205110))

// Transmit Buffer Location 00
#define U2C0_TBUF00            (*((unsigned int volatile huge *) 0x205080))

// Transmit Buffer Location 01
#define U2C0_TBUF01            (*((unsigned int volatile huge *) 0x205084))

// Transmit Buffer Location 02
#define U2C0_TBUF02            (*((unsigned int volatile huge *) 0x205088))

// Transmit Buffer Location 03
#define U2C0_TBUF03            (*((unsigned int volatile huge *) 0x20508C))

// Transmit Buffer Location 04
#define U2C0_TBUF04            (*((unsigned int volatile huge *) 0x205090))

// Transmit Buffer Location 05
#define U2C0_TBUF05            (*((unsigned int volatile huge *) 0x205094))

// Transmit Buffer Location 06
#define U2C0_TBUF06            (*((unsigned int volatile huge *) 0x205098))

// Transmit Buffer Location 07
#define U2C0_TBUF07            (*((unsigned int volatile huge *) 0x20509C))

// Transmit Buffer Location 08
#define U2C0_TBUF08            (*((unsigned int volatile huge *) 0x2050A0))

// Transmit Buffer Location 09
#define U2C0_TBUF09            (*((unsigned int volatile huge *) 0x2050A4))

// Transmit Buffer Location 10
#define U2C0_TBUF10            (*((unsigned int volatile huge *) 0x2050A8))

// Transmit Buffer Location 11
#define U2C0_TBUF11            (*((unsigned int volatile huge *) 0x2050AC))

// Transmit Buffer Location 12
#define U2C0_TBUF12            (*((unsigned int volatile huge *) 0x2050B0))

// Transmit Buffer Location 13
#define U2C0_TBUF13            (*((unsigned int volatile huge *) 0x2050B4))

// Transmit Buffer Location 14
#define U2C0_TBUF14            (*((unsigned int volatile huge *) 0x2050B8))

// Transmit Buffer Location 15
#define U2C0_TBUF15            (*((unsigned int volatile huge *) 0x2050BC))

// Transmit Buffer Location 16
#define U2C0_TBUF16            (*((unsigned int volatile huge *) 0x2050C0))

// Transmit Buffer Location 17
#define U2C0_TBUF17            (*((unsigned int volatile huge *) 0x2050C4))

// Transmit Buffer Location 18
#define U2C0_TBUF18            (*((unsigned int volatile huge *) 0x2050C8))

// Transmit Buffer Location 19
#define U2C0_TBUF19            (*((unsigned int volatile huge *) 0x2050CC))

// Transmit Buffer Location 20
#define U2C0_TBUF20            (*((unsigned int volatile huge *) 0x2050D0))

// Transmit Buffer Location 21
#define U2C0_TBUF21            (*((unsigned int volatile huge *) 0x2050D4))

// Transmit Buffer Location 22
#define U2C0_TBUF22            (*((unsigned int volatile huge *) 0x2050D8))

// Transmit Buffer Location 23
#define U2C0_TBUF23            (*((unsigned int volatile huge *) 0x2050DC))

// Transmit Buffer Location 24
#define U2C0_TBUF24            (*((unsigned int volatile huge *) 0x2050E0))

// Transmit Buffer Location 25
#define U2C0_TBUF25            (*((unsigned int volatile huge *) 0x2050E4))

// Transmit Buffer Location 26
#define U2C0_TBUF26            (*((unsigned int volatile huge *) 0x2050E8))

// Transmit Buffer Location 27
#define U2C0_TBUF27            (*((unsigned int volatile huge *) 0x2050EC))

// Transmit Buffer Location 28
#define U2C0_TBUF28            (*((unsigned int volatile huge *) 0x2050F0))

// Transmit Buffer Location 29
#define U2C0_TBUF29            (*((unsigned int volatile huge *) 0x2050F4))

// Transmit Buffer Location 30
#define U2C0_TBUF30            (*((unsigned int volatile huge *) 0x2050F8))

// Transmit Buffer Location 31
#define U2C0_TBUF31            (*((unsigned int volatile huge *) 0x2050FC))

// Transmit Control/Status Register H
#define U2C0_TCSRH             (*((unsigned int volatile huge *) 0x20503E))

// Transmit Control/Status Register L
#define U2C0_TCSRL             (*((unsigned int volatile huge *) 0x20503C))

// Transmit / Receive Buffer Pointer Reg H
#define U2C0_TRBPTRH           (*((unsigned int volatile huge *) 0x20510A))

// Transmit / Receive Buffer Pointer Reg L
#define U2C0_TRBPTRL           (*((unsigned int volatile huge *) 0x205108))

// Transmit / Receive Buffer Status Clear Reg
#define U2C0_TRBSCR            (*((unsigned int volatile huge *) 0x20511C))

// Transmit / Receive Buffer Status Reg H
#define U2C0_TRBSRH            (*((unsigned int volatile huge *) 0x20511A))

// Transmit / Receive Buffer Status Reg. L
#define U2C0_TRBSRL            (*((unsigned int volatile huge *) 0x205118))

// USIC Interrupt Control Reg. x
sfr  U2C1_0IC                         = 0xF13E;
sbit U2C1_0IC_GPX                      = U2C1_0IC^8;
sbit U2C1_0IC_IE                       = U2C1_0IC^6;
sbit U2C1_0IC_IR                       = U2C1_0IC^7;

// USIC Interrupt Control Reg.
sfr  U2C1_1IC                         = 0xF180;
sbit U2C1_1IC_GPX                      = U2C1_1IC^8;
sbit U2C1_1IC_IE                       = U2C1_1IC^6;
sbit U2C1_1IC_IR                       = U2C1_1IC^7;

// USIC Interrupt Control Reg.
sfr  U2C1_2IC                         = 0xF182;
sbit U2C1_2IC_GPX                      = U2C1_2IC^8;
sbit U2C1_2IC_IE                       = U2C1_2IC^6;
sbit U2C1_2IC_IR                       = U2C1_2IC^7;

// Baud Rate Generator Register H
#define U2C1_BRGH              (*((unsigned int volatile huge *) 0x20521E))

// Baud Rate Generator Register L
#define U2C1_BRGL              (*((unsigned int volatile huge *) 0x20521C))

// Bypass Data Register
#define U2C1_BYP               (*((unsigned int volatile huge *) 0x205300))

// Bypass Control Register H
#define U2C1_BYPCRH            (*((unsigned int volatile huge *) 0x205306))

// Bypass Control Register L
#define U2C1_BYPCRL            (*((unsigned int volatile huge *) 0x205304))

// Channel Configuration Register
#define U2C1_CCFG              (*((unsigned int volatile huge *) 0x205218))

// Channel Control Register
#define U2C1_CCR               (*((unsigned int volatile huge *) 0x205210))

// I0put Control Register n
#define U2C1_DX0CR             (*((unsigned int volatile huge *) 0x205220))

// I1put Control Register n
#define U2C1_DX1CR             (*((unsigned int volatile huge *) 0x205224))

// I2put Control Register n
#define U2C1_DX2CR             (*((unsigned int volatile huge *) 0x205228))

// Error Detection and Correction Test Register H
#define U2C1_EDCRH             (*((unsigned int volatile huge *) 0x20526E))

// Error Detection and Correction Test Register L
#define U2C1_EDCRL             (*((unsigned int volatile huge *) 0x20526C))

// Fractional Divider Register H
#define U2C1_FDRH              (*((unsigned int volatile huge *) 0x205206))

// Fractional Divider Register L
#define U2C1_FDRL              (*((unsigned int volatile huge *) 0x205204))

// Flag Modification Register H
#define U2C1_FMRH              (*((unsigned int volatile huge *) 0x20523A))

// Flag Modification Register L
#define U2C1_FMRL              (*((unsigned int volatile huge *) 0x205238))

// Transmit FIFO Input Location 00
#define U2C1_IN00              (*((unsigned int volatile huge *) 0x205380))

// Transmit FIFO Input Location 01
#define U2C1_IN01              (*((unsigned int volatile huge *) 0x205384))

// Transmit FIFO Input Location 02
#define U2C1_IN02              (*((unsigned int volatile huge *) 0x205388))

// Transmit FIFO Input Location 03
#define U2C1_IN03              (*((unsigned int volatile huge *) 0x20538C))

// Transmit FIFO Input Location 04
#define U2C1_IN04              (*((unsigned int volatile huge *) 0x205390))

// Transmit FIFO Input Location 05
#define U2C1_IN05              (*((unsigned int volatile huge *) 0x205394))

// Transmit FIFO Input Location 06
#define U2C1_IN06              (*((unsigned int volatile huge *) 0x205398))

// Transmit FIFO Input Location 07
#define U2C1_IN07              (*((unsigned int volatile huge *) 0x20539C))

// Transmit FIFO Input Location 08
#define U2C1_IN08              (*((unsigned int volatile huge *) 0x2053A0))

// Transmit FIFO Input Location 09
#define U2C1_IN09              (*((unsigned int volatile huge *) 0x2053A4))

// Transmit FIFO Input Location 10
#define U2C1_IN10              (*((unsigned int volatile huge *) 0x2053A8))

// Transmit FIFO Input Location 11
#define U2C1_IN11              (*((unsigned int volatile huge *) 0x2053AC))

// Transmit FIFO Input Location 12
#define U2C1_IN12              (*((unsigned int volatile huge *) 0x2053B0))

// Transmit FIFO Input Location 13
#define U2C1_IN13              (*((unsigned int volatile huge *) 0x2053B4))

// Transmit FIFO Input Location 14
#define U2C1_IN14              (*((unsigned int volatile huge *) 0x2053B8))

// Transmit FIFO Input Location 15
#define U2C1_IN15              (*((unsigned int volatile huge *) 0x2053BC))

// Transmit FIFO Input Location 16
#define U2C1_IN16              (*((unsigned int volatile huge *) 0x2053C0))

// Transmit FIFO Input Location 17
#define U2C1_IN17              (*((unsigned int volatile huge *) 0x2053C4))

// Transmit FIFO Input Location 18
#define U2C1_IN18              (*((unsigned int volatile huge *) 0x2053C8))

// Transmit FIFO Input Location 19
#define U2C1_IN19              (*((unsigned int volatile huge *) 0x2053CC))

// Transmit FIFO Input Location 20
#define U2C1_IN20              (*((unsigned int volatile huge *) 0x2053D0))

// Transmit FIFO Input Location 21
#define U2C1_IN21              (*((unsigned int volatile huge *) 0x2053D4))

// Transmit FIFO Input Location 22
#define U2C1_IN22              (*((unsigned int volatile huge *) 0x2053D8))

// Transmit FIFO Input Location 23
#define U2C1_IN23              (*((unsigned int volatile huge *) 0x2053DC))

// Transmit FIFO Input Location 24
#define U2C1_IN24              (*((unsigned int volatile huge *) 0x2053E0))

// Transmit FIFO Input Location 25
#define U2C1_IN25              (*((unsigned int volatile huge *) 0x2053E4))

// Transmit FIFO Input Location 26
#define U2C1_IN26              (*((unsigned int volatile huge *) 0x2053E8))

// Transmit FIFO Input Location 27
#define U2C1_IN27              (*((unsigned int volatile huge *) 0x2053EC))

// Transmit FIFO Input Location 28
#define U2C1_IN28              (*((unsigned int volatile huge *) 0x2053F0))

// Transmit FIFO Input Location 29
#define U2C1_IN29              (*((unsigned int volatile huge *) 0x2053F4))

// Transmit FIFO Input Location 30
#define U2C1_IN30              (*((unsigned int volatile huge *) 0x2053F8))

// Transmit FIFO Input Location 31
#define U2C1_IN31              (*((unsigned int volatile huge *) 0x2053FC))

// Interrupt Node Pointer Register H
#define U2C1_INPRH             (*((unsigned int volatile huge *) 0x205216))

// Interrupt Node Pointer Register L
#define U2C1_INPRL             (*((unsigned int volatile huge *) 0x205214))

// Kernel State Configuration Register
#define U2C1_KSCFG             (*((unsigned int volatile huge *) 0x20520C))

// Receiver Buffer Output Register H for Debugger
#define U2C1_OUTDRH            (*((unsigned int volatile huge *) 0x205326))

// Receiver Buffer Output Register L for Debugger
#define U2C1_OUTDRL            (*((unsigned int volatile huge *) 0x205324))

// Receiver Buffer Output Register H
#define U2C1_OUTRH             (*((unsigned int volatile huge *) 0x205322))

// Receiver Buffer Output Register L
#define U2C1_OUTRL             (*((unsigned int volatile huge *) 0x205320))

// Protocol Control Register H
#define U2C1_PCRH              (*((unsigned int volatile huge *) 0x205242))

// Protocol Control Register L
#define U2C1_PCRL              (*((unsigned int volatile huge *) 0x205240))

// Protocol Status Clear Register
#define U2C1_PSCR              (*((unsigned int volatile huge *) 0x205248))

// Protocol Status Register
#define U2C1_PSR               (*((unsigned int volatile huge *) 0x205244))

// Receiver Buffer Control Register H
#define U2C1_RBCTRH            (*((unsigned int volatile huge *) 0x205316))

// Receiver Buffer Control Register L
#define U2C1_RBCTRL            (*((unsigned int volatile huge *) 0x205314))

// Receiver Buffer Register
#define U2C1_RBUF              (*((unsigned int volatile huge *) 0x20525C))

// Receiver Buffer Register 0
#define U2C1_RBUF0             (*((unsigned int volatile huge *) 0x205250))

// Receiver Buffer 01 Status Register H
#define U2C1_RBUF01SRH         (*((unsigned int volatile huge *) 0x205262))

// Receiver Buffer 01 Status Register L
#define U2C1_RBUF01SRL         (*((unsigned int volatile huge *) 0x205260))

// Receiver Buffer Register 1
#define U2C1_RBUF1             (*((unsigned int volatile huge *) 0x205254))

// Receiver Buffer Reg. for Debugger
#define U2C1_RBUFD             (*((unsigned int volatile huge *) 0x20524C))

// Receiver Buffer Status Register
#define U2C1_RBUFSR            (*((unsigned int volatile huge *) 0x205258))

// Shift Control Register H
#define U2C1_SCTRH             (*((unsigned int volatile huge *) 0x205232))

// Shift Control Register L
#define U2C1_SCTRL             (*((unsigned int volatile huge *) 0x205230))

// Transmitter Buffer Control Reg. H
#define U2C1_TBCTRH            (*((unsigned int volatile huge *) 0x205312))

// Transmitter Buffer Control Reg. L
#define U2C1_TBCTRL            (*((unsigned int volatile huge *) 0x205310))

// Transmit Buffer Location 00
#define U2C1_TBUF00            (*((unsigned int volatile huge *) 0x205280))

// Transmit Buffer Location 01
#define U2C1_TBUF01            (*((unsigned int volatile huge *) 0x205284))

// Transmit Buffer Location 02
#define U2C1_TBUF02            (*((unsigned int volatile huge *) 0x205288))

// Transmit Buffer Location 03
#define U2C1_TBUF03            (*((unsigned int volatile huge *) 0x20528C))

// Transmit Buffer Location 04
#define U2C1_TBUF04            (*((unsigned int volatile huge *) 0x205290))

// Transmit Buffer Location 05
#define U2C1_TBUF05            (*((unsigned int volatile huge *) 0x205294))

// Transmit Buffer Location 06
#define U2C1_TBUF06            (*((unsigned int volatile huge *) 0x205298))

// Transmit Buffer Location 07
#define U2C1_TBUF07            (*((unsigned int volatile huge *) 0x20529C))

// Transmit Buffer Location 08
#define U2C1_TBUF08            (*((unsigned int volatile huge *) 0x2052A0))

// Transmit Buffer Location 09
#define U2C1_TBUF09            (*((unsigned int volatile huge *) 0x2052A4))

// Transmit Buffer Location 10
#define U2C1_TBUF10            (*((unsigned int volatile huge *) 0x2052A8))

// Transmit Buffer Location 11
#define U2C1_TBUF11            (*((unsigned int volatile huge *) 0x2052AC))

// Transmit Buffer Location 12
#define U2C1_TBUF12            (*((unsigned int volatile huge *) 0x2052B0))

// Transmit Buffer Location 13
#define U2C1_TBUF13            (*((unsigned int volatile huge *) 0x2052B4))

// Transmit Buffer Location 14
#define U2C1_TBUF14            (*((unsigned int volatile huge *) 0x2052B8))

// Transmit Buffer Location 15
#define U2C1_TBUF15            (*((unsigned int volatile huge *) 0x2052BC))

// Transmit Buffer Location 16
#define U2C1_TBUF16            (*((unsigned int volatile huge *) 0x2052C0))

// Transmit Buffer Location 17
#define U2C1_TBUF17            (*((unsigned int volatile huge *) 0x2052C4))

// Transmit Buffer Location 18
#define U2C1_TBUF18            (*((unsigned int volatile huge *) 0x2052C8))

// Transmit Buffer Location 19
#define U2C1_TBUF19            (*((unsigned int volatile huge *) 0x2052CC))

// Transmit Buffer Location 20
#define U2C1_TBUF20            (*((unsigned int volatile huge *) 0x2052D0))

// Transmit Buffer Location 21
#define U2C1_TBUF21            (*((unsigned int volatile huge *) 0x2052D4))

// Transmit Buffer Location 22
#define U2C1_TBUF22            (*((unsigned int volatile huge *) 0x2052D8))

// Transmit Buffer Location 23
#define U2C1_TBUF23            (*((unsigned int volatile huge *) 0x2052DC))

// Transmit Buffer Location 24
#define U2C1_TBUF24            (*((unsigned int volatile huge *) 0x2052E0))

// Transmit Buffer Location 25
#define U2C1_TBUF25            (*((unsigned int volatile huge *) 0x2052E4))

// Transmit Buffer Location 26
#define U2C1_TBUF26            (*((unsigned int volatile huge *) 0x2052E8))

// Transmit Buffer Location 27
#define U2C1_TBUF27            (*((unsigned int volatile huge *) 0x2052EC))

// Transmit Buffer Location 28
#define U2C1_TBUF28            (*((unsigned int volatile huge *) 0x2052F0))

// Transmit Buffer Location 29
#define U2C1_TBUF29            (*((unsigned int volatile huge *) 0x2052F4))

// Transmit Buffer Location 30
#define U2C1_TBUF30            (*((unsigned int volatile huge *) 0x2052F8))

// Transmit Buffer Location 31
#define U2C1_TBUF31            (*((unsigned int volatile huge *) 0x2052FC))

// Transmit Control/Status Register H
#define U2C1_TCSRH             (*((unsigned int volatile huge *) 0x20523E))

// Transmit Control/Status Register L
#define U2C1_TCSRL             (*((unsigned int volatile huge *) 0x20523C))

// Transmit / Receive Buffer Pointer Reg H
#define U2C1_TRBPTRH           (*((unsigned int volatile huge *) 0x20530A))

// Transmit / Receive Buffer Pointer Reg L
#define U2C1_TRBPTRL           (*((unsigned int volatile huge *) 0x205308))

// Transmit / Receive Buffer Status Clear Reg
#define U2C1_TRBSCR            (*((unsigned int volatile huge *) 0x20531C))

// Transmit / Receive Buffer Status Reg H
#define U2C1_TRBSRH            (*((unsigned int volatile huge *) 0x20531A))

// Transmit / Receive Buffer Status Reg. L
#define U2C1_TRBSRL            (*((unsigned int volatile huge *) 0x205318))

// Vector Segment Pointer
sfr  VECSEG                           = 0xFF12;

// Constant Zeros Register
sfr  ZEROS                            = 0xFF1C;


#endif  // ifndef _XC2XXXREGS_H_

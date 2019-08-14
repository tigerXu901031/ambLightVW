/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2010)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Lin_SFR16.h                                                   **
**                                                                            **
**  VERSION   : 1.0.2                                                         **
**                                                                            **
**  DATE      : 2011.11.01                                                    **
**                                                                            **
**  PLATFORM  : Infineon XC2000                                               **
**                                                                            **
**  COMPILER  : Tasking - Viper v2.4 r2                                       **
**                                                                            **
**  PROJECT   :  XC2000 LIN                                                   **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains functionality of Lin Hardware dependent **
**  layer. In abstracts SFR Layer                                             **
*******************************************************************************/
/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PM         Puneetha Mukherjee                                             **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.2: 2011.11.01, PM  : UTP ID AI00058130 is fixed.
 * V1.0.1: 2010.12.03, PM  : Code Clean up done. 
 * V1.0.0: 2010.05.19, PM  : Final Released Version
 * V0.1.0: 2010.04.16, PM  : Fixed MISRA checking. . 
 * V0.0.0: 2010.03.12, PM  : Initial version of IDL for LIN
 */

#ifndef _LIN_SFR16_
#define _LIN_SFR16_

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "COMPILER.h"
/* Global Suppression of Rule 18.4 in order to access SFR's through Unions*/
/*lint -esym(960,18.4) */
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
#if _IFC_SCND_TMR_NUM == GPT_T2
  #define _GPT12E_T2CON            (*( __GPT12E_T2CON_type *)0xFF40)
  #define _GPT12E_T3CON            (*( __GPT12E_T3CON_type *)0xFF42)
  #define _GPT12E_T2               (*( __SFR_type *)0xFE40)
  #define _GPT12E_T3               (*( __SFR_type *)0xFE42)
  #define _GPT12E_IC               (*( __IC_type *)0xFF62)
#else /* GPT T6 is configured */
  #define _GPT12E_T6CON            (*( __GPT12E_T6CON_type *)0xFF48)
  #define _GPT12E_CAPREL           (*( __SFR_type *)0xFE4A)
  #define _GPT12E_T6               (*( __SFR_type *)0xFE48)
  #define _GPT12E_IC               (*( __IC_type *)0xFF68)  
#endif /* _IFC_SCND_TMR_NUM */

/* GPT12E Kernel State Con. Register */
#define _GPT12E_KSCCFG           (*( __IC_type *)0xFE1C) 
#define _PSW                     (*( __PSW_type *)0xFF10)

#define USIC_BASE_ADDRESS        (0x204000U)


#define SCU_SLC          (*((uint16 volatile *) 0xF0C0))
#define SCU_SLS          (*((uint16 volatile *) 0xF0C2))

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
typedef volatile union __IC_union
{
    struct __IC_struct
    {
        unsigned int GLVL        :2;
        unsigned int ILVL        :4;
        unsigned int IE          :1;
        unsigned int IR          :1;
        unsigned int GPX         :1;
        unsigned int             :7;
    } B;
    uint16 U;
} __IC_type;

/* Define general type for SFRs without bitfields */
typedef volatile union __SFR_union
{
    uint16 U;
} __SFR_type;

typedef volatile union __UC_CCR_union
{
    struct __UC_CCR_struct
    {
        unsigned int MODE        :4;
        unsigned int             :4;
        unsigned int PM          :2;
        unsigned int RSIEN       :1;
        unsigned int DLIEN       :1;
        unsigned int TSIEN       :1;
        unsigned int TBIEN       :1;
        unsigned int RIEN        :1;
        unsigned int AIEN        :1;
    } B;
    uint16 U;
} __UC_CCR_type;

typedef volatile union __UC_CCFG_union
{
    struct __UC_CCFG_struct
    {
        unsigned int SSC         :1;
        unsigned int ASC         :1;
        unsigned int IIC         :1;
        unsigned int IIS         :1;
        unsigned int             :2;
        unsigned int RB          :1;
        unsigned int TB          :1;
        unsigned int             :8;
    } B;
    uint16 U;
} __UC_CCFG_type;

typedef volatile union __UC_KSCFG_union
{
    struct __UC_KSCFG_struct
    {
        unsigned int MODEN       :1;
        unsigned int BPMODEN     :1;
        unsigned int             :2;
        unsigned int NOMCFG      :2;
        unsigned int             :1;
        unsigned int BPNOM       :1;
        unsigned int SUMCFG      :2;
        unsigned int             :1;
        unsigned int BPSUM       :1;
        unsigned int COMCFG      :2;
        unsigned int             :1;
        unsigned int BPCOM       :1;
    } B;
    uint16 U;
} __UC_KSCFG_type;

typedef volatile union __UC_INPRL_union
{
    struct __UC_INPRL_struct
    {
        unsigned int TSINP       :2;
        unsigned int             :2;
        unsigned int TBINP       :2;
        unsigned int             :2;
        unsigned int RINP        :2;
        unsigned int             :2;
        unsigned int AINP        :2;
        unsigned int             :2;
    } B;
    uint16 U;
} __UC_INPRL_type;

typedef volatile union __UC_INPRH_union
{
    struct __UC_INPRH_struct
    {
        unsigned int PINP        :2;
        unsigned int             :14;
    } B;
    uint16 U;
} __UC_INPRH_type;

typedef volatile union __UC_PCRL_union
{
    struct __UC_PCRL_1_struct
    {
        unsigned int CTR0        :1;
        unsigned int CTR1        :1;
        unsigned int CTR2        :1;
        unsigned int CTR3        :1;
        unsigned int CTR4        :1;
        unsigned int CTR5        :1;
        unsigned int CTR6        :1;
        unsigned int CTR7        :1;
        unsigned int CTR8        :1;
        unsigned int CTR9        :1;
        unsigned int CTR10       :1;
        unsigned int CTR11       :1;
        unsigned int CTR12       :1;
        unsigned int CTR13       :1;
        unsigned int CTR14       :1;
        unsigned int CTR15       :1;
    } B1;
    struct __UC_PCRL_2_struct
    {
        unsigned int SMD         :1;
        unsigned int STPB        :1;
        unsigned int IDM         :1;
        unsigned int SBIEN       :1;
        unsigned int CDEN        :1;
        unsigned int RNIEN       :1;
        unsigned int FEIEN       :1;
        unsigned int FFIEN       :1;
        unsigned int SP1          :5;
        unsigned int PL          :3;
    } B2;
    struct __UC_PCRL_3_struct
    {
        unsigned int MSLSEN      :1;
        unsigned int SELCTR      :1;
        unsigned int SELINV      :1;
        unsigned int FEM         :1;
        unsigned int CTQSEL1     :2;
        unsigned int PCTQ1       :2;
        unsigned int DCTQ1       :5;
        unsigned int             :1;
        unsigned int MSLSIEN     :1;
        unsigned int DX2TIEN     :1;
    } B3;
    struct __UC_PCRL_4_struct
    {
        unsigned int SLAD        :16;
    } B4;
    struct __UC_PCRL_5_struct
    {
        unsigned int WAGEN       :1;
        unsigned int DTEN        :1;
        unsigned int SELINV      :1;
        unsigned int             :1;
        unsigned int WAFEIEN     :1;
        unsigned int WAREIEN     :1;
        unsigned int ENDIEN      :1;
        unsigned int             :8;
        unsigned int DX2TIEN     :1;
    } B5;
    uint16 U;
} __UC_PCRL_type;

typedef volatile union __UC_PCRH_union
{
    struct __UC_PCRH_1_struct
    {
        unsigned int CTR16       :1;
        unsigned int CTR17       :1;
        unsigned int CTR18       :1;
        unsigned int CTR19       :1;
        unsigned int CTR20       :1;
        unsigned int CTR21       :1;
        unsigned int CTR22       :1;
        unsigned int CTR23       :1;
        unsigned int CTR24       :1;
        unsigned int CTR25       :1;
        unsigned int CTR26       :1;
        unsigned int CTR27       :1;
        unsigned int CTR28       :1;
        unsigned int CTR29       :1;
        unsigned int CTR30       :1;
        unsigned int CTR31       :1;
    } B1;
    struct __UC_PCRH_2_struct
    {
        unsigned int RSTEN       :1;
        unsigned int TSTEN       :1;
        unsigned int             :13;
        unsigned int MCLK        :1;
    } B2;
    struct __UC_PCRH_3_struct
    {
        unsigned int SELO        :8;
        unsigned int TIWEN       :1;
        unsigned int             :6;
        unsigned int MCLK        :1;
    } B3;
    struct __UC_PCRH_4_struct
    {
        unsigned int ACK00       :1;
        unsigned int STIM        :1;
        unsigned int SCRIEN      :1;
        unsigned int RSCRIEN     :1;
        unsigned int PCRIEN      :1;
        unsigned int NACKIEN     :1;
        unsigned int ARLIEN      :1;
        unsigned int SRRIEN      :1;
        unsigned int ERRIEN      :1;
        unsigned int SACKDIS     :1;
        unsigned int HDEL        :4;
        unsigned int             :1;
        unsigned int MCLK        :1;
    } B4;
    struct __UC_PCRH_5_struct
    {
        unsigned int TDEL        :6;
        unsigned int             :9;
        unsigned int MCLK        :1;
    } B5;
    uint16 U;
} __UC_PCRH_type;

typedef volatile union __UC_PSR_union
{
    struct __UC_PSR_1_struct
    {
        unsigned int ST0         :1;
        unsigned int ST1         :1;
        unsigned int ST2         :1;
        unsigned int ST3         :1;
        unsigned int ST4         :1;
        unsigned int ST5         :1;
        unsigned int ST6         :1;
        unsigned int ST7         :1;
        unsigned int ST8         :1;
        unsigned int ST9         :1;
        unsigned int RSIF        :1;
        unsigned int DLIF        :1;
        unsigned int TSIF        :1;
        unsigned int TBIF        :1;
        unsigned int RIF         :1;
        unsigned int AIF         :1;
    } B1;
    struct __UC_PSR_2_struct
    {
        unsigned int TXIDLE      :1;
        unsigned int RXIDLE      :1;
        unsigned int SBD         :1;
        unsigned int COL         :1;
        unsigned int RNS         :1;
        unsigned int FER0        :1;
        unsigned int FER1        :1;
        unsigned int RFF         :1;
        unsigned int TFF         :1;
        unsigned int BUSY        :1;
        unsigned int RSIF        :1;
        unsigned int DLIF        :1;
        unsigned int TSIF        :1;
        unsigned int TBIF        :1;
        unsigned int RIF         :1;
        unsigned int AIF         :1;
    } B2;
    struct __UC_PSR_3_struct
    {
        unsigned int MSLS        :1;
        unsigned int DX2S        :1;
        unsigned int MSLSEV      :1;
        unsigned int DX2TEV      :1;
        unsigned int             :6;
        unsigned int RSIF        :1;
        unsigned int DLIF        :1;
        unsigned int TSIF        :1;
        unsigned int TBIF        :1;
        unsigned int RIF         :1;
        unsigned int AIF         :1;
    } B3;
    struct __UC_PSR_4_struct
    {
        unsigned int SLSEL       :1;
        unsigned int WTDF        :1;
        unsigned int SCR         :1;
        unsigned int RSCR        :1;
        unsigned int PCR         :1;
        unsigned int NACK        :1;
        unsigned int ARL         :1;
        unsigned int SRR         :1;
        unsigned int ERR         :1;
        unsigned int             :1;
        unsigned int RSIF        :1;
        unsigned int DLIF        :1;
        unsigned int TSIF        :1;
        unsigned int TBIF        :1;
        unsigned int RIF         :1;
        unsigned int AIF         :1;
    } B4;
    struct __UC_PSR_5_struct
    {
        unsigned int WA          :1;
        unsigned int DX2S        :1;
        unsigned int             :1;
        unsigned int DX2TEV      :1;
        unsigned int WAFE        :1;
        unsigned int WARE        :1;
        unsigned int END         :1;
        unsigned int             :3;
        unsigned int RSIF        :1;
        unsigned int DLIF        :1;
        unsigned int TSIF        :1;
        unsigned int TBIF        :1;
        unsigned int RIF         :1;
        unsigned int AIF         :1;
    } B5;
    uint16 U;
} __UC_PSR_type;

typedef volatile union __UC_PSCR_union
{
    struct __UC_PSCR_struct
    {
        unsigned int CST0        :1;
        unsigned int CST1        :1;
        unsigned int CST2        :1;
        unsigned int CST3        :1;
        unsigned int CST4        :1;
        unsigned int CST5        :1;
        unsigned int CST6        :1;
        unsigned int CST7        :1;
        unsigned int CST8        :1;
        unsigned int CST9        :1;
        unsigned int CRSIF       :1;
        unsigned int CDLIF       :1;
        unsigned int CTSIF       :1;
        unsigned int CTBIF       :1;
        unsigned int CRIF        :1;
        unsigned int CAIF        :1;
    } B;
    uint16 U;
} __UC_PSCR_type;

typedef volatile union __UC_DXCR_union
{
    struct __UC_DXCR_struct
    {
        unsigned int DSEL        :3;
        unsigned int             :1;
        unsigned int INSW        :1;
        unsigned int DFEN        :1;
        unsigned int DSEN        :1;
        unsigned int             :1;
        unsigned int DPOL        :1;
        unsigned int SFSEL       :1;
        unsigned int CM          :2;
        unsigned int             :3;
        unsigned int DXS         :1;
    } B;
    uint16 U;
} __UC_DXCR_type;

typedef volatile union __UC_FDRL_union
{
    struct __UC_FDRL_struct
    {
        unsigned int STEP        :10;
        unsigned int             :4;
        unsigned int DM          :2;
    } B;
    uint16 U;
} __UC_FDRL_type;

typedef volatile union __UC_FDRH_union
{
    struct __UC_FDRH_struct
    {
        unsigned int RESULT      :10;
        unsigned int             :6;
    } B;
    uint16 U;
} __UC_FDRH_type;

typedef volatile union __UC_BRGL_union
{
    struct __UC_BRGL_struct
    {
        unsigned int CLKSEL       :2;
        unsigned int              :1;
        unsigned int TMEN         :1;
        unsigned int PPPEN        :1;
        unsigned int              :1;
        unsigned int CTQSEL       :2;
        unsigned int PCTQ         :2;
        unsigned int DCTQ         :5;
        unsigned int              :1;
    } B;
    uint16 U;
} __UC_BRGL_type;

typedef volatile union __UC_BRGH_union
{
    struct __UC_BRGH_struct
    {
        unsigned int PDIV        :10;
        unsigned int             :3;
        unsigned int MCLKCFG     :1;
        unsigned int SCLKCFG     :2;
    } B;
    uint16 U;
} __UC_BRGH_type;

typedef volatile union __UC_SCTRL_union
{
    struct __UC_SCTRL_struct
    {
        unsigned int SDIR        :1;
        unsigned int PDL         :1;
        unsigned int             :4;
        unsigned int DOCFG       :2;
        unsigned int TRM         :2;
        unsigned int             :6;
    } B;
    uint16 U;
} __UC_SCTRL_type;

typedef volatile union __UC_SCTRH_union
{
    struct __UC_SCTRH_struct
    {
        unsigned int FLE         :6;
        unsigned int             :2;
        unsigned int WLE         :4;
        unsigned int             :4;
    } B;
    uint16 U;
} __UC_SCTRH_type;

typedef volatile union __UC_TCSRL_union
{
    struct __UC_TCSRL_struct
    {
        unsigned int WLEMD       :1;
        unsigned int SELMD       :1;
        unsigned int FLEMD       :1;
        unsigned int WAMD        :1;
        unsigned int             :1;
        unsigned int SOF         :1;
        unsigned int EO          :1;
        unsigned int TDV         :1;
        unsigned int TDSSM       :1;
        unsigned int             :1;
        unsigned int TDEN        :2;
        unsigned int TDVTR       :1;
        unsigned int WA          :1;
        unsigned int             :2;
    } B;
    uint16 U;
} __UC_TCSRL_type;

typedef volatile union __UC_TCSRH_union
{
    struct __UC_TCSRH_struct
    {
        unsigned int             :8;
        unsigned int TSOF        :1;
        unsigned int             :1;
        unsigned int TV          :1;
        unsigned int TVC         :1;
        unsigned int TE          :1;
        unsigned int             :3;
    } B;
    uint16 U;
} __UC_TCSRH_type;

typedef volatile union __UC_FMRL_union
{
    struct __UC_FMRL_struct
    {
        unsigned int MTDV        :2;
        unsigned int             :2;
        unsigned int ATVC        :1;
        unsigned int             :9;
        unsigned int CRDV0       :1;
        unsigned int CRDV1       :1;
    } B;
    uint16 U;
} __UC_FMRL_type;

typedef volatile union __UC_FMRH_union
{
    struct __UC_FMRH_struct
    {
        unsigned int SIO0        :1;
        unsigned int SIO1        :1;
        unsigned int SIO2        :1;
        unsigned int SIO3        :1;
        unsigned int             :12;
    } B;
    uint16 U;
} __UC_FMRH_type;

typedef volatile union __UC_RBUFSRL_union
{
    struct __UC_RBUFSRL_struct
    {
        unsigned int WLEN0       :4;
        unsigned int             :2;
        unsigned int SOF0        :1;
        unsigned int             :1;
        unsigned int PAR0        :1;
        unsigned int PERR0       :1;
        unsigned int             :3;
        unsigned int RDV00       :1;
        unsigned int RDV01       :1;
        unsigned int DS0         :1;
    } B;
    uint16 U;
} __UC_RBUFSRL_type;

typedef volatile union __UC_RBUFSRH_union
{
    struct __UC_RBUFSRH_struct
    {
        unsigned int WLEN1       :4;
        unsigned int             :2;
        unsigned int SOF1        :1;
        unsigned int             :1;
        unsigned int PAR1        :1;
        unsigned int PERR1       :1;
        unsigned int             :3;
        unsigned int RDV10       :1;
        unsigned int RDV11       :1;
        unsigned int DS1         :1;
    } B;
    uint16 U;
} __UC_RBUFSRH_type;

typedef volatile union __UC_RBUFSR_union
{
    struct __UC_RBUFSR_struct
    {
        unsigned int WLEN        :4;
        unsigned int             :2;
        unsigned int SOF         :1;
        unsigned int             :1;
        unsigned int PAR         :1;
        unsigned int PERR        :1;
        unsigned int             :3;
        unsigned int RDV0        :1;
        unsigned int RDV1        :1;
        unsigned int DS          :1;
    } B;
    uint16 U;
} __UC_RBUFSR_type;

typedef volatile union __UC_BYPCRL_union
{
    struct __UC_BYPCRL_struct
    {
        unsigned int BWLE        :4;
        unsigned int             :4;
        unsigned int BDSSM       :1;
        unsigned int             :1;
        unsigned int BDEN        :2;
        unsigned int BDVTR       :1;
        unsigned int BPRIO       :1;
        unsigned int             :1;
        unsigned int BDV         :1;
    } B;
    uint16 U;
} __UC_BYPCRL_type;

typedef volatile union __UC_BYPCRH_union
{
    struct __UC_BYPCRH_struct
    {
        unsigned int BSELO       :5;
        unsigned int             :11;
    } B;
    uint16 U;
} __UC_BYPCRH_type;

typedef volatile union __UC_TRBSRL_union
{
    struct __UC_TRBSRL_struct
    {
        unsigned int SRBI        :1;
        unsigned int RBERI       :1;
        unsigned int ARBI        :1;
        unsigned int REMPTY      :1;
        unsigned int RFULL       :1;
        unsigned int RBUS        :1;
        unsigned int             :2;
        unsigned int STBI        :1;
        unsigned int TBERI       :1;
        unsigned int             :1;
        unsigned int TEMPTY      :1;
        unsigned int TFULL       :1;
        unsigned int TBUS        :1;
        unsigned int             :2;
    } B;
    uint16 U;
} __UC_TRBSRL_type;

typedef volatile union __UC_TRBSRH_union
{
    struct __UC_TRBSRH_struct
    {
        unsigned int RBFLVL      :7;
        unsigned int             :1;
        unsigned int TBFLVL      :7;
        unsigned int             :1;
    } B;
    uint16 U;
} __UC_TRBSRH_type;

typedef volatile union __UC_TRBSCR_union
{
    struct __UC_TRBSCR_struct
    {
        unsigned int CSRBI       :1;
        unsigned int CRBERI      :1;
        unsigned int CARBI       :1;
        unsigned int             :5;
        unsigned int CSTBI       :1;
        unsigned int CTBERI      :1;
        unsigned int CBDV        :1;
        unsigned int             :3;
        unsigned int FLUSHRB     :1;
        unsigned int FLUSHTB     :1;
    } B;
    uint16 U;
} __UC_TRBSCR_type;

typedef volatile union __UC_TBCTRL_union
{
    struct __UC_TBCTRL_struct
    {
        unsigned int DPTR        :6;
        unsigned int             :2;
        unsigned int LIMIT       :6;
        unsigned int             :2;
    } B;
    uint16 U;
} __UC_TBCTRL_type;

typedef volatile union __UC_TBCTRH_union
{
    struct __UC_TBCTRH_struct
    {
        unsigned int STBINP      :2;
        unsigned int             :1;
        unsigned int ATBINP      :2;
        unsigned int             :3;
        unsigned int SIZE        :3;
        unsigned int             :1;
        unsigned int LOF         :1;
        unsigned int             :1;
        unsigned int STBIEN      :1;
        unsigned int TBERIEN     :1;
    } B;
    uint16 U;
} __UC_TBCTRH_type;

typedef volatile union __UC_RBCTRL_union
{
    struct __UC_RBCTRL_struct
    {
        unsigned int DPTR        :6;
        unsigned int             :2;
        unsigned int LIMIT       :6;
        unsigned int             :2;
    } B;
    uint16 U;
} __UC_RBCTRL_type;

typedef volatile union __UC_RBCTRH_union
{
    struct __UC_RBCTRH_struct
    {
        unsigned int SRBINP      :2;
        unsigned int             :1;
        unsigned int ARBINP      :2;
        unsigned int             :1;
        unsigned int RCIM        :2;
        unsigned int SIZE        :3;
        unsigned int RNM         :1;
        unsigned int LOF         :1;
        unsigned int ARBIEN      :1;
        unsigned int SRBIEN      :1;
        unsigned int RBERIEN     :1;
    } B;
    uint16 U;
} __UC_RBCTRH_type;

typedef volatile union __UC_OUTRH_union
{
    struct __UC_OUTRH_struct
    {
        unsigned int RCI         :5;
        unsigned int             :11;
    } B;
    uint16 U;
} __UC_OUTRH_type;

typedef volatile union __UC_OUTDRH_union
{
    struct __UC_OUTDRH_struct
    {
        unsigned int RCI         :5;
        unsigned int             :11;
    } B;
    uint16 U;
} __UC_OUTDRH_type;

typedef volatile union __UC_TRBPTRL_union
{
    struct __UC_TRBPTRL_struct
    {
        unsigned int TDIPTR      :6;
        unsigned int             :2;
        unsigned int TDOPTR      :6;
        unsigned int             :2;
    } B;
    uint16 U;
} __UC_TRBPTRL_type;

typedef volatile union __UC_TRBPTRH_union
{
    struct __UC_TRBPTRH_struct
    {
        unsigned int RDIPTR      :6;
        unsigned int             :2;
        unsigned int RDOPTR      :6;
        unsigned int             :2;
    } B;
    uint16 U;
} __UC_TRBPTRH_type;

typedef volatile union __USIC_IDL_union
{
    struct __USIC_IDL_struct
    {
        unsigned int MOD_REV     :8;
        unsigned int MOD_TYPE    :8;
    } B;
    uint16 U;
} __USIC_IDL_type;



typedef volatile struct USIC_RegMap
{
  uint16       Reserved0[2];     /* Offset 0x00 */
  __UC_FDRL_type       FDRL;     /* Offset 0x04 */
  __UC_FDRH_type       FDRH;     /* Offset 0x06 */
  __USIC_IDL_type      IDL;      /* Offset 0x08 */
  __SFR_type           IDH;      /* Offset 0x0A */
  __UC_KSCFG_type      KSCFG;    /* Offset 0x0C */
  uint16       Reserved1;        /* Offset 0x0E */
  __UC_CCR_type        CCR;      /* Offset 0x10 */
  uint16       Reserved2;        /* Offset 0x12 */
  __UC_INPRL_type      INPRL;    /* Offset 0x14 */
  __UC_INPRH_type      INPRH;    /* Offset 0x16 */
  __UC_CCFG_type       CCFG;     /* Offset 0x18 */
  uint16       Reserved3;        /* Offset 0x1A */
  __UC_BRGL_type       BRGL;     /* Offset 0x1C */
  __UC_BRGH_type       BRGH;     /* Offset 0x1E */
  __UC_DXCR_type       DX0CR;    /* Offset 0x20 */
  uint16       Reserved4;        /* Offset 0x22 */
  __UC_DXCR_type       DX1CR;    /* Offset 0x24 */
  uint16       Reserved5;        /* Offset 0x26 */
  __UC_DXCR_type       DX2CR;    /* Offset 0x28 */
  uint16       Reserved6[3];     /* Offset 0x2A */
  __UC_SCTRL_type      SCTRL;    /* Offset 0x30 */
  __UC_SCTRH_type      SCTRH;    /* Offset 0x32 */
  uint16       Reserved7[2];     /* Offset 0x34 */
  __UC_FMRL_type       FMRL;     /* Offset 0x38 */
  __UC_FMRH_type       FMRH;     /* Offset 0x3A */
  __UC_TCSRL_type      TCSRL;    /* Offset 0x3C */
  __UC_TCSRH_type      TCSRH;    /* Offset 0x3E */
  __UC_PCRL_type       PCRL;     /* Offset 0x40 */
  __UC_PCRH_type       PCRH;     /* Offset 0x42 */
  __UC_PSR_type        PSR;      /* Offset 0x44 */
  uint16       Reserved8;        /* Offset 0x46 */
  __UC_PSCR_type       PSCR;     /* Offset 0x48 */
  uint16       Reserved9;        /* Offset 0x4A */
  __SFR_type           RBUFD;    /* Offset 0x4C */
  uint16       Reserved10;       /* Offset 0x4E */
  __SFR_type           RBUF0;    /* Offset 0x50 */
  uint16       Reserved11;       /* Offset 0x52 */
  __SFR_type           RBUF1;    /* Offset 0x54 */
  uint16       Reserved12;       /* Offset 0x56 */
  __UC_RBUFSR_type     RBUFSR;   /* Offset 0x58 */
  uint16       Reserved13;       /* Offset 0x5A */
  __SFR_type           RBUF;     /* Offset 0x5C */
  uint16       Reserved14;       /* Offset 0x5E */
  __UC_RBUFSRL_type    RBUF01SRL;/* Offset 0x60 */
  __UC_RBUFSRH_type    RBUF01SRH;/* Offset 0x62 */
  uint16       Reserved15[4];    /* Offset 0x64 */
  __SFR_type           EDCRL;    /* Offset 0x6C */
  __SFR_type           EDCRH;    /* Offset 0x6E */
  uint16       Reserved16[8];    /* Offset 0x70 */
  uint32        TBUF00[32];      /* Offset 0x80 TO 0xFF - 4bytes
                                                each TBUF*/
  __SFR_type           BYP;      /* Offset 0x100 */
  uint16       Reserved17;       /* Offset 0x102 */
  __UC_BYPCRL_type     BYPCRL;   /* Offset 0x104 */
  __UC_BYPCRH_type     BYPCRH;   /* Offset 0x106 */
  __UC_TRBPTRL_type    TRBPTRL;  /* Offset 0x108 */
  __UC_TRBPTRH_type    TRBPTRH;  /* Offset 0x10A */
  uint16       Reserved18[2];    /* Offset 0x10C */
  __UC_TBCTRL_type     TBCTRL;   /* Offset 0x110 */
  __UC_TBCTRH_type     TBCTRH;   /* Offset 0x112 */
  __UC_RBCTRL_type     RBCTRL;   /* Offset 0x114 */
  __UC_RBCTRH_type     RBCTRH;   /* Offset 0x116 */
  __UC_TRBSRL_type     TRBSRL;   /* Offset 0x118 */
  __UC_TRBSRH_type     TRBSRH;   /* Offset 0x11A */
  __UC_TRBSCR_type     TRBSCR;   /* Offset 0x11C */
  uint16       Reserved19;       /* Offset 0x11E */
  __SFR_type           OUTRL;    /* Offset 0x120 */
  __UC_OUTRH_type      OUTRH;    /* Offset 0x122 */
  __SFR_type           OUTDRL;   /* Offset 0x124 */
  __UC_OUTDRH_type     OUTDRH;   /* Offset 0x126 */
  uint16       Reserved20[44];   /* Offset 0x128 */
  uint32        IN00[32];         /* Offset 0x180 to 0x1FF-4 bytes
                                                              each IN00*/
}USIC_RegMapType;

typedef volatile union __GPT12E_T2CON_union
{
    struct __GPT12E_T2CON_struct
    {
        unsigned int T2I         :3;
        unsigned int T2M         :3;
        unsigned int T2R         :1;
        unsigned int T2UD        :1;
        unsigned int T2UDE       :1;
        unsigned int T2RC        :1;
        unsigned int             :2;
        unsigned int T2IRDIS     :1;
        unsigned int T2EDGE      :1;
        unsigned int T2CHDIR     :1;
        unsigned int T2RDIR      :1;
    } B;
    uint16 U;
} __GPT12E_T2CON_type;

typedef volatile union __GPT12E_T3CON_union
{
    struct __GPT12E_T3CON_struct
    {
        unsigned int T3I         :3;
        unsigned int T3M         :3;
        unsigned int T3R         :1;
        unsigned int T3UD        :1;
        unsigned int T3UDE       :1;
        unsigned int T3OE        :1;
        unsigned int T3OTL       :1;
        unsigned int BPS1        :2;
        unsigned int T3EDGE      :1;
        unsigned int T3CHDIR     :1;
        unsigned int T3RDIR      :1;
    } B;
    uint16 U;
} __GPT12E_T3CON_type;


typedef volatile union __GPT12E_T6CON_union
{
    struct __GPT12E_T6CON_struct
    {
        unsigned int T6I        :3;
        unsigned int T6M        :3;
        unsigned int T6R        :1;
        unsigned int T6UD       :1;
        unsigned int T6UDE      :1;
        unsigned int T6OE       :1;
        unsigned int T6OTl      :1;
        unsigned int BPS2       :2;
        unsigned int            :1;
        unsigned int T6CLR      :1;
        unsigned int T6SR       :1;
    } B;
    uint16 U;
} __GPT12E_T6CON_type;

typedef volatile union __IOCR_union
{
    struct __IOCR_struct
    {
        unsigned int             :4;
        unsigned int PC          :4;
        unsigned int             :8;
    } B;
    uint16 U;
} __IOCR_type;

typedef volatile union __SCU_ESRCFG_union
{
    struct __SCU_ESRCFG_struct
    {
        unsigned int PC          :4;
        unsigned int DFEN        :1;
        unsigned int OUT         :1;
        unsigned int IN          :1;
        unsigned int SEDCON      :2;
        unsigned int AEDCON      :2;
        unsigned int             :5;
    } B;
    uint16 U;
} __SCU_ESRCFG_type;

typedef volatile union __POCON_union
{
    struct __POCON_struct
    {
        unsigned int PDM0        :3;
        unsigned int PPS0        :1;
        unsigned int PDM1        :3;
        unsigned int PPS1        :1;
        unsigned int PDM2        :3;
        unsigned int PPS2        :1;
        unsigned int PDM3        :3;
        unsigned int PPS3        :1;
    } B;
    uint16 U;
} __POCON_type;

typedef volatile union __OMRL_union
{
    struct __OMRL_struct
    {
        unsigned int PS0         :1;
        unsigned int PS1         :1;
        unsigned int PS2         :1;
        unsigned int PS3         :1;
        unsigned int PS4         :1;
        unsigned int PS5         :1;
        unsigned int PS6         :1;
        unsigned int PS7         :1;
        unsigned int PC0         :1;
        unsigned int PC1         :1;
        unsigned int PC2         :1;
        unsigned int PC3         :1;
        unsigned int PC4         :1;
        unsigned int PC5         :1;
        unsigned int PC6         :1;
        unsigned int PC7         :1;
    } B;
    uint16 U;
} __OMRL_type;

typedef volatile union __OMRH_union
{
    struct __OMRH_struct
    {
        unsigned int PS8         :1;
        unsigned int PS9         :1;
        unsigned int PS10        :1;
        unsigned int PS11        :1;
        unsigned int PS12        :1;
        unsigned int PS13        :1;
        unsigned int PS14        :1;
        unsigned int PS15        :1;
        unsigned int PC8         :1;
        unsigned int PC9         :1;
        unsigned int PC10        :1;
        unsigned int PC11        :1;
        unsigned int PC12        :1;
        unsigned int PC13        :1;
        unsigned int PC14        :1;
        unsigned int PC15        :1;
    } B;
    uint16 U;
} __OMRH_type;

typedef volatile union __OUT_union
{
    struct __OUT_struct
    {
        unsigned int p0        :1;
        unsigned int p1        :1;
        unsigned int p2        :1;
        unsigned int p3        :1;
        unsigned int p4        :1;
        unsigned int p5        :1;
        unsigned int p6        :1;
        unsigned int p7        :1;
        unsigned int p8        :1;
        unsigned int p9        :1;
        unsigned int p10        :1;
        unsigned int p11        :1;
        unsigned int p12        :1;
        unsigned int p13        :1;
        unsigned int p14        :1;
        unsigned int p15        :1;
    } B;
    uint16 U;
} __OUT_type;


typedef volatile union __PSW_union
{
    struct __PSW_struct
    {
        unsigned int N          :1;
        unsigned int C          :1;
        unsigned int V          :1;
        unsigned int Z          :1;
        unsigned int E          :1;
        unsigned int PL0        :1;
        unsigned int USR0       :1;
        unsigned int USR1       :1;
        unsigned int BANK       :2;
        unsigned int HLDEN_PL1  :1;
        unsigned int IEN        :1;
        unsigned int ILVL       :4;
    } B;
    uint16 U;
} __PSW_type;

/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
/*lint +esym(960,18.4) */
#endif /* _LIN_SFR16_ */

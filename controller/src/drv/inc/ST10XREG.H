/*--------------------------------------------------------------------------
ST10XREG.H

X Register for ST10F280 including CAN Registers
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __ST10XREG_h__
#define __ST10XREG_h__

//---------------------------
//CAN Registers
//---------------------------


/* Control/Status Register */
#define CAN1CSR     (*((unsigned int volatile sdata *) 0xEF00))
/* Interrupt Register */
#define CAN1IR      (*((unsigned int volatile sdata *) 0xEF02))
/* Bit Timing Register */ 
#define CAN1BTR     (*((unsigned int volatile sdata *) 0xEF04))
/* Global Mask Short */
#define CAN1GMS     (*((unsigned int volatile sdata *) 0xEF06))
/* Upper Global Mask Long */
#define CAN1UGML    (*((unsigned int volatile sdata *) 0xEF08))
/* Lower Global Mask Long */
#define CAN1LGML    (*((unsigned int volatile sdata *) 0xEF0A))
/* Upper Mask of Last Message */
#define CAN1UMLM    (*((unsigned int volatile sdata *) 0xEF0C))
/* Lower Mask of Last Message */
#define CAN1LMLM    (*((unsigned int volatile sdata *) 0xEF0E))

#define BIT_TIMING              0x2440

/* Masks for testing field 'msg_ctl' of the 15 CAN objects */
/* These are used by reading the message control register of a CAN object,
   then bitwise-ANDing the value read with the appropriate mask.
   Example:
   if (CAN_MSGOBJ[can_object_number].msg_ctl & NEWDAT_) {
      Actions to take when NEWDAT flag is true go here.
   }
*/
#define INTPND_                 0x0002u
#define RXIE_                   0x0008u
#define TXIE_                   0x0020u
#define MSGVAL_                 0x0080u
#define NEWDAT_                 0x0200u
#define MSGLST_                 0x0800u
#define CPUUPD_                 0x0800u
#define TXRQ_                   0x2000u
#define RMTPND_                 0x8000u

/* Masks for clearing (resetting) flags in field 'msg_ctl' of the 15 CAN objects */
/* To compute the value to write to the message control register of a CAN
   object to change some of its flags, bitwise-and together the appropriate
   macros (Chosen from the various *_CLR and *_SET macros).
   For example, this statement clears (resets) the CPUUPD flag and sets the
   NEWDAT and TXRQ flags, while leaving all the other flags unchanged:
   CAN_MSGOBJ[can_object_number].msg_ctl = CPUUPD_CLR & NEWDAT_SET & TXRQ_SET;
*/
#define INTPND_CLR              (~INTPND_)
#define RXIE_CLR                (~RXIE_)
#define TXIE_CLR                (~TXIE_)
#define MSGVAL_CLR              (~MSGVAL_)
#define NEWDAT_CLR              (~NEWDAT_)
#define MSGLST_CLR              (~MSGLST_)
#define CPUUPD_CLR              (~CPUUPD_)
#define TXRQ_CLR                (~TXRQ_)
#define RMTPND_CLR              (~RMTPND_)

/* Masks for setting flags in field 'msg_ctl' of the 15 CAN objects */
/* See the comments for the preceding set of macros (INTPND_CLR, etc.)
   for explanation.
*/
#define INTPND_SET              (~(INTPND_ >> 1))
#define RXIE_SET                (~(RXIE_ >> 1))
#define TXIE_SET                (~(TXIE_ >> 1))
#define MSGVAL_SET              (~(MSGVAL_ >> 1))
#define NEWDAT_SET              (~(NEWDAT_ >> 1))
#define MSGLST_SET              (~(MSGLST_ >> 1))
#define CPUUPD_SET              (~(CPUUPD_ >> 1))
#define TXRQ_SET                (~(TXRQ_ >> 1))
#define RMTPND_SET              (~(RMTPND_ >> 1))

/* Old Masks for field 'msg_ctl' of the 15 CAN objects */
/* These were defined in previous versions of the C166 tools, but they
   are awkward to use.  They are included for backward compatibility.
   For new programs, we recommend ignoring these and using the preceding
   three sets of macros instead.
*/
#define INTPND_MASK             0x0001
#define RXIE_MASK               0x0004
#define TXIE_MASK               0x0010
#define MSGVAL_MASK             0x0040
#define NEWDAT_MASK             0x0100
#define MSGLST_MASK             0x0400
#define CPUUPD_MASK             0x0400
#define TXRQ_MASK               0x1000
#define RMTPND_MASK             0x4000

/* Masks for field 'msg_cfg' of the 15 CAN objects */
#define XTD_MASK                0x0004
#define DIR_MASK                0x0008

/* Structure for a single CAN object */
/* A total of 15 such object structures exists (starting at EF10H) */
struct can_obj {
  unsigned int  msg_ctl;   /* Message Control       */
  unsigned long arbitr;    /* Arbitration           */
  unsigned char msg_cfg;   /* Message Configuration */
  unsigned char msg[8];    /* Message Data 0 .. 7   */ 
  unsigned char dummy;     /* Reserved Byte         */
};

#define CAN1OBJ ((struct can_obj volatile sdata *)  0xEF10)
#define CAN1MOBJ ((struct can_obj volatile sdata *) 0xEF00)

/* Control/Status Register */
#define CAN2CSR     (*((unsigned int volatile sdata *) 0xEE00))
/* Interrupt Register */
#define CAN2IR      (*((unsigned int volatile sdata *) 0xEE02))
/* Bit Timing Register */ 
#define CAN2BTR     (*((unsigned int volatile sdata *) 0xEE04))
/* Global Mask Short */
#define CAN2GMS     (*((unsigned int volatile sdata *) 0xEE06))
/* Upper Global Mask Long */
#define CAN2UGML    (*((unsigned int volatile sdata *) 0xEE08))
/* Lower Global Mask Long */
#define CAN2LGML    (*((unsigned int volatile sdata *) 0xEE0A))
/* Upper Mask of Last Message */
#define CAN2UMLM    (*((unsigned int volatile sdata *) 0xEE0C))
/* Lower Mask of Last Message */
#define CAN2LMLM    (*((unsigned int volatile sdata *) 0xEE0E))
/* Can Objects */
#define CAN2OBJ     ((struct can_obj volatile sdata *) 0xEE10)
#define CAN2MOBJ    ((struct can_obj volatile sdata *) 0xEE00)

/* Bits in the control portion (low byte) of the CAN control/status register */
#define CAN_INIT_  1
#define CAN_IE_    2
#define CAN_SIE_   4
#define CAN_EIE_   8
#define CAN_CCE_  64
/* Bits in the status portion (high byte) of the CAN control/status register
   These values are for accessing the status byte alone (CxSR).  When
   accessing the full 16-bit control/status register (CxCSR), these
   values should be shifted left 8 bit positions. 
*/
#define CAN_LEC_    7
#define CAN_TXOK_   8
#define CAN_RXOK_  16
#define CAN_EWRN_  64
#define CAN_BOFF_ 128

//---------------------------
// X Registers
//---------------------------

#define XADCMUX     ((struct can_obj volatile sdata *) 0xC384)
#define XDP9        ((struct can_obj volatile sdata *) 0xC200)
#define XDP9CLR     ((struct can_obj volatile sdata *) 0xC204)
#define XDP9SET     ((struct can_obj volatile sdata *) 0xC202)
#define XODP9       ((struct can_obj volatile sdata *) 0xC300)
#define XODP9CLR    ((struct can_obj volatile sdata *) 0xC304)
#define XODP9SET    ((struct can_obj volatile sdata *) 0xC302)
#define XP10        ((struct can_obj volatile sdata *) 0xC380)
#define XP10DIDIS   ((struct can_obj volatile sdata *) 0xC382)
#define XP9         ((struct can_obj volatile sdata *) 0xC100)
#define XP9CLR      ((struct can_obj volatile sdata *) 0xC104)
#define XP9SET      ((struct can_obj volatile sdata *) 0xC102)
#define XPOLAR      ((struct can_obj volatile sdata *) 0xEC04)
#define XPP0        ((struct can_obj volatile sdata *) 0xEC20)
#define XPP1        ((struct can_obj volatile sdata *) 0xEC22)
#define XPP2        ((struct can_obj volatile sdata *) 0xEC24)
#define XPP3        ((struct can_obj volatile sdata *) 0xEC26)
#define XPT0        ((struct can_obj volatile sdata *) 0xEC10)
#define XPT1        ((struct can_obj volatile sdata *) 0xEC22)
#define XPT2        ((struct can_obj volatile sdata *) 0xEC14)
#define XPT3        ((struct can_obj volatile sdata *) 0xEC16)
#define XPW0        ((struct can_obj volatile sdata *) 0xEC30)
#define XPW1        ((struct can_obj volatile sdata *) 0xEC32) 
#define XPW2        ((struct can_obj volatile sdata *) 0xEC34)
#define XPW3        ((struct can_obj volatile sdata *) 0xEC36)
#define XPWMCON0    ((struct can_obj volatile sdata *) 0xEC00)
#define XPWMCON1    ((struct can_obj volatile sdata *) 0xEC02)
#define XTCR        ((struct can_obj volatile sdata *) 0xC000)
#define XTCVR       ((struct can_obj volatile sdata *) 0xC006)
#define XTEVR       ((struct can_obj volatile sdata *) 0xC004)
#define XTSVR       ((struct can_obj volatile sdata *) 0xC002)


#endif

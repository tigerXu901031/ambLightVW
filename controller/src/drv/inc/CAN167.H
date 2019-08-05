/*--------------------------------------------------------------------------
Register Declarations for C167CR CAN Registers
C166/EC++ Version 5.
Copyright (c) 1995-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __CAN167_H__
#define __CAN167_H__

/* Control/Status Register */
#define CAN_CTL_STAT   (*((unsigned int volatile sdata *) 0xEF00))
/* Interrupt Register */
#define CAN_INTID      (*((unsigned int volatile sdata *) 0xEF02))
/* Bit Timing Register */ 
#define CAN_BIT_TIMING (*((unsigned int volatile sdata *) 0xEF04))
/* Global Mask Short */
#define CAN_MASK_SHORT (*((unsigned int volatile sdata *) 0xEF06))
/* Upper Global Mask Long */
#define CAN_UMASK_LONG (*((unsigned int volatile sdata *) 0xEF08))
/* Lower Global Mask Long */
#define CAN_LMASK_LONG (*((unsigned int volatile sdata *) 0xEF0A))
/* Upper Mask of Last Message */
#define CAN_UMASK_LAST (*((unsigned int volatile sdata *) 0xEF0C))
/* Lower Mask of Last Message */
#define CAN_LMASK_LAST (*((unsigned int volatile sdata *) 0xEF0E))

/* Initial values */
/* 1 MBit/s, valid for SILICONIX Si9200DY driver and a short bus 2..3 m */
#define BIT_TIMING              0x2440

/* Masks for field 'msg_ctl' of the 15 CAN objects */
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

#define CAN_OBJ ((struct can_obj volatile sdata *) 0xEF10)

#endif

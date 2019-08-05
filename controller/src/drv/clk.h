#ifndef __CLK_H__
#define __CLK_H__

#include "XC22xxLREGS.H"
#include "scs.h"
#include "inc/INTRINS.H"
#include "../srv/type.h"

#define TIME_NS_PER_INSTRUCTION_CYCLE 50

extern void MAIN_vChangeFreq(void);
extern void MAIN_vUnlockProtecReg(void);
extern void MAIN_vLockProtecReg(void);
extern void delay(uint16 cycle);
extern void longDelay(uint16 cycle);
extern void delay300ns();

#endif
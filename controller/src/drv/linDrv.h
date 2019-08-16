#ifndef __LINDRV_H__
#define __LINDRV_H__

#include "XC22xxLREGS.H"
#include "../srv/type.h"
#include "../srv/linSrv.h"

#define U0C0_SRN0 0x50
#define U0C0_SRN1 0x51
#define U0C0_SRN2 0x52

extern void U2C0_LIN_Master_vInit(void);

#endif
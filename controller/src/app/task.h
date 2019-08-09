#ifndef __TASK_H__
#define __TASK_H__

#define LED_PROJECT     1

#include "../drv/XC22xxLREGS.H"
#include "../drv/clk.h"
#include "../drv/linDrv.h"
#include "../drv/io.h"
#include "../srv/led.h"
#include "ledCtrl.h"

extern void taskSlow();
extern void taskFast();
extern void taskInit();

#endif
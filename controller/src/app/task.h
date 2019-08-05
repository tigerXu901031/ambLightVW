#ifndef __TASK_H__
#define __TASK_H__

#define LED_PROJECT     1

#include "../drv/XC22xxLREGS.H"
#include "../drv/clk.h"
#include "../drv/io.h"
#include "../srv/led.h"
#include "ledCtrl.h"

// #if LED_PROJECT == 1
// inline void testFun1()
// {
//     uint8 i = 0;
//     while(1)
//     {
//         for(i = 0; i <LED_NUM; i ++)
//         {
//             i ++;
//             i --;
//         }
//     }
// }
// #elif LED_PROJECT == 2
// #endif

extern void taskSlow();
extern void taskFast();
extern void taskInit();

#endif
#ifndef __LEDCTRL_H__
#define __LEDCTRL_H__

#include "../srv/led.h"
#include "../srv/linSrv.h"

typedef enum{
   color_green,
   color_blue,
   color_red,
   color_orange,
   color_yellow,
   color_purple,
   color_off,
   color_max,
}color_enum;

/* 
 **************************************************************
   mode 1:  根据外部亮度调节全局亮度，无特殊说明均使用全局亮度值将亮
            度分为三档，高(100%功率)，中（75%功率），低(50%功率)
   mode 2:  T-zone全部灯常绿
   mode 3:  T-zone全部灯闪烁绿光，0.5s灭，0.5s亮
   mode 4:  从6，7两灯开始常亮，其余灯保持状态3中的闪烁频率，每次亮
            向外的两颗灯进入常亮状态，直至恢复至状态2
   mode 5:  三区构成一个大流水灯，四灯一组，红橙黄绿蓝紫六色，0.5s移
            动一灯
   mode 6:  T-zone闪烁的黄色灯0.3s灭，0.3s亮(表示低紧急度)
   mode 7:  三区黄红交替闪烁0.3s黄0.3s红，并且将亮度调至最高(表示
            高紧急度)(车内其余内饰也应有配合提醒)
   mode 8:  T-zone 全部灯蓝绿闪烁0.5s蓝0.5s绿，3s后切换为低亮度蓝色
   mode 9:  T-zone 全部灯为低亮度蓝色
   mode 10: 从T-zone 1 和L-zone的11、12开始，闪烁黄色0.3s亮0.3s灭,
            每次闪烁多亮三颗灯（T-zone+1，L-zone+2）直至T-zone左侧
            (1-6)和L-zone全部进入闪烁状态
   mode 11: 从T-zone 12 和R-zone的1、2开始，闪烁黄色0.3s亮0.3s灭，每
            次闪烁多亮三颗灯(T-zone+1，L-zone+2)直至T-zone右侧(7-12)
            和R-zone全部进入闪烁状态
   mode 12: 三区全部灯闪烁红色，0.3s亮，0.3s灭
   mode 13: 三区黄红交替闪烁0.3s黄0.3s红
   mode 14: 从T-zone的1-4开始四灯绿色，0.5s向左运动一灯即L-zone，运动
            L-zone 1灯开始重复返回T-zone 4灯
   mode 15: 从T-zone的1-4开始四灯绿色，0.5s向左运动一灯即L-zone，运动
            L-zone 1灯开始重复返回T-zone 4灯 
   mode 16: 从T-zone的8-12开始四灯绿色，0.5s向右运动一灯即R-zone，运动
            至R-zone12灯开始重复返回T-zone 8灯
   mode 17: 从L-zone 1开始，闪烁黄色0.3s亮0.3s灭；每次闪烁一个灯；逐步
            过渡到2,3,4,5,6,7,8,9,10,11,12; 然后循环开始，重新从1，
            逐步再次过度到12
   mode 18: 从L-zone 12开始，闪烁黄色0.3s亮0.3s灭；每次闪烁一个灯；逐
            步过渡到11,10,9,8,7,6,5,4,3,2,1; 然后循环开始，重新从11，
            逐步再次过度到1
 **************************************************************
 */
typedef enum{
    ledMode_1 = 1,
    ledMode_2,
    ledMode_3,
    ledMode_4,
    ledMode_5,
    ledMode_6,
    ledMode_7,
    ledMode_8,
    ledMode_9,
    ledMode_10,
    ledMode_11,
    ledMode_12,
    ledMode_13,
    ledMode_14,
    ledMode_15,
    ledMode_16,
    ledMode_17,
    ledMode_18,
    ledMode_max,
    ledMode_FF = 0xff,
}ledMode_enum;

typedef enum{
    lightLevel_default  = 0,
    lightLevel_low      = 1,
    lightLevel_medium   = 2,
    lightLevel_high     = 3,
}lightLevel_enum;

/* temporary use */
typedef struct
{
    struct
    {
        uint8 ledCtrlMode;
    }input;
    struct
    {
        uint8 dummySig;
    }output;
}canSignalsType;

extern void ledModeUpdate();

#endif
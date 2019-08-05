#ifndef __LED_H__
#define __LED_H__

#include "type.h"
#include "../drv/clk.h"
#include "../drv/io.h"

#define LED_NUM                 12
#define BITS_FOR_EACH_LED       24

#define LED_BIT_HIGH_DUTY       80
#define LED_BIT_LOW_DUTY        20

#define PWN_CTRL                1
#define GPIO_CTRL               2

#define LED_OUTPUT_TYPE         GPIO_CTRL

#define setGpio(ioPort, value)  IO_##ioPort = ##value

typedef enum{
    ledStripIdx_left    = 0,
    ledStripIdx_center  = 1,
    ledStripIdx_right   = 2,
    ledStripIdx_max     = 3,
}ledStripIdx_type;

typedef struct{
    uint8 red;
    uint8 green;
    uint8 blue;
}rgb_type;

typedef struct{
    rgb_type    led[LED_NUM];
    uint8       curLedIdx;
    uint8       curBitIdx;
    uint8       isFinished;
}ledStrip_type;

extern uint8 ledDutyCycleArrary[ledStripIdx_max][LED_NUM * BITS_FOR_EACH_LED];

extern void ledInit();
extern void setSingleLed(ledStripIdx_type ledStripIdx, uint8 ledIdx, rgb_type rgbVal);
extern void ledRgbEncodeUpdate(ledStripIdx_type ledStripIdx);

#endif
#include "task.h"
#include "../srv/led.h"

void main()
{
    uint16 i = 0;
    uint8 ledZoneSwitch = 0xff;
    taskInit();



    while(1)
    {
        switch(ledZoneSwitch)
        {
            case 0xff:
                taskSlow();
                ledZoneSwitch = ledStripIdx_left;
                longDelay(20);
                break;
            case ledStripIdx_left:
                if(ledDutyCycleArrary[ledStripIdx_left][i])
                {
                    setGpio(P10_4, 1);
                    delay300ns();
                    delay300ns();
                    delay300ns();
                    setGpio(P10_4, 0);
                }
                else
                {
                    setGpio(P10_4, 1);
                    delay300ns();
                    setGpio(P10_4, 0);
                    delay300ns();
                    delay300ns();
                }
                i ++;
                if(i == LED_NUM * BITS_FOR_EACH_LED)
                {
                    delay(10000);
                    i = 0;
                    ledZoneSwitch = ledStripIdx_center;
                }
                break;
            case ledStripIdx_center:
                if(ledDutyCycleArrary[ledStripIdx_center][i])
                {
                    setGpio(P10_5, 1);
                    delay300ns();
                    delay300ns();
                    delay300ns();
                    setGpio(P10_5, 0);
                }
                else
                {
                    setGpio(P10_5, 1);
                    delay300ns();
                    setGpio(P10_5, 0);
                    delay300ns();
                    delay300ns();
                }
                i ++;
                if(i == LED_NUM * BITS_FOR_EACH_LED)
                {
                    delay(10000);
                    i = 0;
                    ledZoneSwitch = ledStripIdx_right;
                }
                break;
            case ledStripIdx_right:
                if(ledDutyCycleArrary[ledStripIdx_center][i])
                {
                    setGpio(P10_7, 1);
                    delay300ns();
                    delay300ns();
                    delay300ns();
                    setGpio(P10_7, 0);
                }
                else
                {
                    setGpio(P10_7, 1);
                    delay300ns();
                    setGpio(P10_7, 0);
                    delay300ns();
                    delay300ns();
                }
                i ++;
                if(i == LED_NUM * BITS_FOR_EACH_LED)
                {
                    delay(10000);
                    i = 0;
                    ledZoneSwitch = 0xff;
                }
                break;
        }
        

        
    }
}
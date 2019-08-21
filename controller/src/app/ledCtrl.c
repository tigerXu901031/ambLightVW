#include "ledCtrl.h"

const rgb_type colorArrOrign[color_max] = {
    /* color_green */
    {0, 255, 0},
    /* color_blue */
    {0, 0, 255},
    /* color_red */
    {255, 0, 0},
    /* color_orange */
    {200, 100, 0},
    /* color_yellow */
    {255, 255, 0},
    /* color_purple */
    {204, 0, 255},
    /* color_off */
    {0, 0, 0}};

rgb_type colorArr[color_max] = {
    /* color_green */
    {0, 255, 0},
    /* color_blue */
    {0, 0, 255},
    /* color_red */
    {255, 0, 0},
    /* color_orange */
    {200, 100, 0},
    /* color_yellow */
    {255, 255, 0},
    /* color_purple */
    {204, 0, 255},
    /* color_off */
    {0, 0, 0}};

// static void ledMode1Ctrl(ledMode_enum oldInpMode)
// {
//     static uint8 darknessLevel = 0;
//     uint8 j = 0;
//     if (oldInpMode != ledMode_1)
//     {
//         darknessLevel++;
//         if (darknessLevel == 3)
//         {
//             darknessLevel = 0;
//         }
//         else
//         {
//         }
//         for (j = 0; j < color_max; j++)
//         {
//             colorArr[j].blue    = colorArrOrign[j].blue * (1 - (0.25 * darknessLevel));
//             colorArr[j].green   = colorArrOrign[j].green * (1 - (0.25 * darknessLevel));
//             colorArr[j].red     = colorArrOrign[j].red * (1 - (0.25 * darknessLevel));
//         }
//     }
// }

static void ledMode2Ctrl()
{
    uint8 i = 0;
    for (i = 0; i < LED_NUM; i++)
    {
        setSingleLed(ledStripIdx_center, i, colorArr[color_green]);
        setSingleLed(ledStripIdx_left, i, colorArr[color_off]);
        setSingleLed(ledStripIdx_right, i, colorArr[color_off]);
    }
}

static void ledMode3Ctrl()
{
    static uint8 i = 0;
    uint8 j = 0;

    switch (i)
    {
    /* all green ON first 500ms */
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        for (j = 0; j < LED_NUM; j++)
        {
            setSingleLed(ledStripIdx_center, j, colorArr[color_green]);
            setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
        }
        i++;
        break;
    /* all OFF next 500ms */
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        for (j = 0; j < LED_NUM; j++)
        {
            setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
        }
        i++;
        if (i == 15)
            i = 0;
        break;
    default:
        break;
    }
}

static void ledMode4Ctrl(ledMode_enum oldInpMode)
{
    static uint8 i = 0, k = 0;
    uint8 j = 0;

    if (oldInpMode != ledMode_4)
    {
        i = 0;
        k = 0;
    }
    else
    {
    }

    i++;
    if (i == 10)
    {
        i = 0;
        if (k <= 5)
        {
            k++;
        }
    }
    else
    {
    }
    switch(i)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            for(j = 0; j < LED_NUM; j ++)
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
                setSingleLed(ledStripIdx_center, j, colorArr[color_green]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_green]);
            }
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            for(j = 0; j < LED_NUM; j ++)
            {
                if((j >= (5 - k)) && (j <= (6 + k)))
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
                    setSingleLed(ledStripIdx_center, j, colorArr[color_green]);
                    setSingleLed(ledStripIdx_right, j, colorArr[color_green]);
                }
                else
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                    setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                    setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
                }
            }
            break;
        default:
            break;
    }

}

static void ledMode5Ctrl(ledMode_enum oldInpMode)
{
    static uint8 cycCnt = 0;
    static rgb_type streamColorArr[24];
    rgb_type colorTemp;
    uint8 i = 0, j = 0, k = 0;
    
    if(oldInpMode != ledMode_5)
    {
        cycCnt = 0;
        streamColorArr[0] = colorArr[color_red];
        streamColorArr[1] = colorArr[color_red];
        streamColorArr[2] = colorArr[color_red];
        streamColorArr[3] = colorArr[color_red];

        streamColorArr[4] = colorArr[color_orange];
        streamColorArr[5] = colorArr[color_orange];
        streamColorArr[6] = colorArr[color_orange];
        streamColorArr[7] = colorArr[color_orange];

        streamColorArr[8] = colorArr[color_yellow];
        streamColorArr[9] = colorArr[color_yellow];
        streamColorArr[10] = colorArr[color_yellow];
        streamColorArr[11] = colorArr[color_yellow];

        streamColorArr[12] = colorArr[color_green];
        streamColorArr[13] = colorArr[color_green];
        streamColorArr[14] = colorArr[color_green];
        streamColorArr[15] = colorArr[color_green];

        streamColorArr[16] = colorArr[color_blue];
        streamColorArr[17] = colorArr[color_blue];
        streamColorArr[18] = colorArr[color_blue];
        streamColorArr[19] = colorArr[color_blue];

        streamColorArr[20] = colorArr[color_purple];
        streamColorArr[21] = colorArr[color_purple];
        streamColorArr[22] = colorArr[color_purple];
        streamColorArr[23] = colorArr[color_purple];
    }
    cycCnt ++;
    /* each 0.5s update the stream arrary */
    if(cycCnt == 5)
    {
        cycCnt = 0;
        
        colorTemp = streamColorArr[23];
        for(i = 0; i < 23; i ++)
        {
            streamColorArr[23 - i] = streamColorArr[22 - i];
        }
        streamColorArr[0] = colorTemp;
    }
    
    /* light the led according to the stream array */
    for(j = 0; j < LED_NUM; j ++)
    {
        setSingleLed(ledStripIdx_left, j, streamColorArr[j]);
        setSingleLed(ledStripIdx_right, j, streamColorArr[j]);
        setSingleLed(ledStripIdx_center, j, streamColorArr[j + 12]);
    }
}

static void ledMode6Ctrl()
{
    static uint8 i = 0;
    uint8 j = 0;

    switch (i)
    {
    /* all green ON first 500ms */
    case 0:
    case 1:
    case 2:
        for (j = 0; j < LED_NUM; j++)
        {
            setSingleLed(ledStripIdx_center, j, colorArr[color_yellow]);
            setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
        }
        i++;
        break;
    /* all OFF next 500ms */
    case 3:
    case 4:
    case 5:
        for (j = 0; j < LED_NUM; j++)
        {
            setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
        }
        i++;
        if (i == 6)
            i = 0;
        break;
    default:
        break;
    }
}

static void ledMode7Ctrl()
{
    static uint8 i = 0;
    uint8 j = 0;

    switch (i)
    {
        /* all lights yellow first 300ms */
        case 0:
        case 1:
        case 2:
            for (j = 0; j < LED_NUM; j++)
            {
                /* in this mode locally use the highest brightness level */
                setSingleLed(ledStripIdx_left, j, colorArrOrign[color_yellow]);
                setSingleLed(ledStripIdx_center, j, colorArrOrign[color_yellow]);
                setSingleLed(ledStripIdx_right, j, colorArrOrign[color_yellow]);
            }
            i++;
            break;
        /* all lights red first 300ms */
        case 3:
        case 4:
        case 5:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_left, j, colorArrOrign[color_red]);
                setSingleLed(ledStripIdx_center, j, colorArrOrign[color_red]);
                setSingleLed(ledStripIdx_right, j, colorArrOrign[color_red]);
            }
            i++;
            if (i == 6)
            {
                i = 0;
            }
            else
            {
            }
            break;
        default:
            break;
    }
}

static void ledMode8Ctrl(ledMode_enum oldInpMode)
{
    static uint8 i = 0, k = 0;
    uint8 j = 0;
    rgb_type brightnessColor;

    /* recover to the begining in case of stucked in the last cycle of
       of this mode */
    if (oldInpMode != ledMode_8)
    {
        i = 0;
        k = 0;
    }
    else
    {
    }
    if (k == 6)
    {
        /* 3s passed ... */
        i = 0xff;
    }
    else
    {
    }

    switch (i)
    {

        /* all green first 500ms */
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_center, j, colorArr[color_green]);
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
            }
            i++;
            break;
        /* all blue next 500ms */
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_center, j, colorArr[color_blue]);
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
            }
            i++;
            if (i == 10)
            {
                i = 0;
                k++;
            }
            break;
        case 0xff:
            brightnessColor.blue = colorArrOrign[color_blue].blue / 2;
            brightnessColor.green = colorArrOrign[color_blue].green / 2;
            brightnessColor.red = colorArrOrign[color_blue].red / 2;
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_center, j, brightnessColor);
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
            }
        default:
            break;
    }
}

static void ledMode9Ctrl()
{
    uint8 i = 0;
    rgb_type brightnessColor;
    brightnessColor.blue = colorArrOrign[color_blue].blue / 2;
    brightnessColor.green = colorArrOrign[color_blue].green / 2;
    brightnessColor.red = colorArrOrign[color_blue].red / 2;
    for (i = 0; i < LED_NUM; i++)
    {
        setSingleLed(ledStripIdx_center, i, brightnessColor);
    }
}

static void ledMode10Ctrl(ledMode_enum oldInpMode)
{
    static uint8 i = 0, k = 0;
    uint8 j = 0;

    /* recover to the begining in case of stucked in the last cycle of
       of this mode */
    if (oldInpMode != ledMode_10)
    {
        i = 0;
        k = 0;
    }
    else
    {
    }
    switch(i)
    {
        /* some of the led yellow first 300ms */
        case 0:
        case 1:
        case 2:
            for (j = 0; j < LED_NUM; j++)
            {
                if(k < 6)
                {
                    if(j >= (LED_NUM - 2 * (k + 1)))
                    {
                        setSingleLed(ledStripIdx_left, j, colorArr[color_yellow]);
                    }
                    else
                    {
                        setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                    }
                    if(j < (k + 1))
                    {
                        setSingleLed(ledStripIdx_center, j, colorArr[color_yellow]);
                    }
                    else
                    {
                        setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                    }
                    setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
                }
                else
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_yellow]);
                    if(j < 6)
                    {
                        setSingleLed(ledStripIdx_center, j, colorArr[color_yellow]);
                    }
                    else
                    {
                        setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                    }
                    setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
                }
            }
            i++;
            break;
        /* all off next 300ms */
        case 3:
        case 4:
        case 5:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
            }
            i++;
            if (i == 6)
            {
                i = 0;
                if(k < 5)
                {
                    k++;
                }
            }
            break;
        default:
        break;
    }
}

static void ledMode11Ctrl(ledMode_enum oldInpMode)
{
    static uint8 i = 0, k = 0;
    uint8 j = 0;

    /* recover to the begining in case of stucked in the last cycle of
       of this mode */
    if (oldInpMode != ledMode_11)
    {
        i = 0;
        k = 0;
    }
    else
    {
    }
    switch(i)
    {
        /* some of the led yellow first 300ms */
        case 0:
        case 1:
        case 2:
            for (j = 0; j < LED_NUM; j++)
            {
                if(k < 6)
                {
                    if(j  < 2 * (k + 1))
                    {
                        setSingleLed(ledStripIdx_right, j, colorArr[color_yellow]);
                    }
                    else
                    {
                        setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
                    }
                    if(j >= (LED_NUM - (k + 1)))
                    {
                        setSingleLed(ledStripIdx_center, j, colorArr[color_yellow]);
                    }
                    else
                    {
                        setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                    }
                    setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                }
                else
                {
                    setSingleLed(ledStripIdx_right, j, colorArr[color_yellow]);
                    if(j > 5)
                    {
                        setSingleLed(ledStripIdx_center, j, colorArr[color_yellow]);
                    }
                    else
                    {
                        setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                    }
                    setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                }
            }
            i++;
            break;
        /* all off next 300ms */
        case 3:
        case 4:
        case 5:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
            }
            i++;
            if (i == 6)
            {
                i = 0;
                if(k < 5)
                {
                    k++;
                }
            }
            break;
        default:
        break;
    }
}

static void ledMode12Ctrl()
{
    static uint8 i = 0;
    uint8 j = 0;

    switch (i)
    {
        /* all green ON first 300ms */
        case 0:
        case 1:
        case 2:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_red]);
                setSingleLed(ledStripIdx_center, j, colorArr[color_red]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_red]);
            }
            i++;
            break;
        /* all OFF next 300ms */
        case 3:
        case 4:
        case 5:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
            }
            i++;
            if (i == 6)
                i = 0;
            break;
        default:
            break;
    }
}

static void ledMode13Ctrl()
{
    static uint8 i = 0;
    uint8 j = 0;

    switch (i)
    {
        /* all green ON first 300ms */
        case 0:
        case 1:
        case 2:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_yellow]);
                setSingleLed(ledStripIdx_center, j, colorArr[color_yellow]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_yellow]);
            }
            i++;
            break;
        /* all OFF next 300ms */
        case 3:
        case 4:
        case 5:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_red]);
                setSingleLed(ledStripIdx_center, j, colorArr[color_red]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_red]);
            }
            i++;
            if (i == 6)
                i = 0;
            break;
        default:
            break;
    }
}

static void ledMode14Ctrl(ledMode_enum oldInpMode)
{
    static uint8 cycCnt = 0;
    static rgb_type streamColorArr[16];
    rgb_type colorTemp;
    uint8 i = 0, j = 0;
    if((oldInpMode != ledMode_14) || (cycCnt == (12 * 5)))
    {
        cycCnt = 0;

        streamColorArr[0] = colorArr[color_green];
        streamColorArr[1] = colorArr[color_green];
        streamColorArr[2] = colorArr[color_green];
        streamColorArr[3] = colorArr[color_green];

        streamColorArr[4] = colorArr[color_off];
        streamColorArr[5] = colorArr[color_off];
        streamColorArr[6] = colorArr[color_off];
        streamColorArr[7] = colorArr[color_off];

        streamColorArr[8] = colorArr[color_off];
        streamColorArr[9] = colorArr[color_off];
        streamColorArr[10] = colorArr[color_off];
        streamColorArr[11] = colorArr[color_off];

        streamColorArr[12] = colorArr[color_off];
        streamColorArr[13] = colorArr[color_off];
        streamColorArr[14] = colorArr[color_off];
        streamColorArr[15] = colorArr[color_off];
    }
    cycCnt ++;
    /* each 0.5s update the stream arrary */
    if(((cycCnt + 1) % 5) == 0)
    {        
        colorTemp = streamColorArr[15];
        for(i = 0; i < 15; i ++)
        {
            streamColorArr[15 - i] = streamColorArr[14 - i];
        }
        streamColorArr[0] = colorTemp;
    }
    for(j = 0; j < LED_NUM; j ++)
    {
        if(j < 4)
        {
            setSingleLed(ledStripIdx_center, j, streamColorArr[4 - j]);
        }
        else
        {
            setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
        }
        setSingleLed(ledStripIdx_left, j, streamColorArr[LED_NUM - j + 3]);
        setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
    }
}

static void ledMode15Ctrl(ledMode_enum oldInpMode)
{
    /* same mode as mode 14 */
    if(oldInpMode == ledMode_15)
    {
        ledMode14Ctrl(ledMode_14);
    }
    else
    {
        ledMode14Ctrl(oldInpMode);
    }
}

static void ledMode16Ctrl(ledMode_enum oldInpMode)
{
    static uint8 cycCnt = 0;
    static rgb_type streamColorArr[16];
    rgb_type colorTemp;
    uint8 i = 0, j = 0;
    if((oldInpMode != ledMode_16) || (cycCnt == (12 * 5)))
    {
        cycCnt = 0;

        streamColorArr[0] = colorArr[color_green];
        streamColorArr[1] = colorArr[color_green];
        streamColorArr[2] = colorArr[color_green];
        streamColorArr[3] = colorArr[color_green];

        streamColorArr[4] = colorArr[color_off];
        streamColorArr[5] = colorArr[color_off];
        streamColorArr[6] = colorArr[color_off];
        streamColorArr[7] = colorArr[color_off];

        streamColorArr[8] = colorArr[color_off];
        streamColorArr[9] = colorArr[color_off];
        streamColorArr[10] = colorArr[color_off];
        streamColorArr[11] = colorArr[color_off];

        streamColorArr[12] = colorArr[color_off];
        streamColorArr[13] = colorArr[color_off];
        streamColorArr[14] = colorArr[color_off];
        streamColorArr[15] = colorArr[color_off];
    }
    cycCnt ++;
    /* each 0.5s update the stream arrary */
    if(((cycCnt + 1) % 5) == 0)
    {        
        colorTemp = streamColorArr[15];
        for(i = 0; i < 15; i ++)
        {
            streamColorArr[15 - i] = streamColorArr[14 - i];
        }
        streamColorArr[0] = colorTemp;
    }
    for(j = 0; j < LED_NUM; j ++)
    {
        if(j >= (LED_NUM - 4))
        {
            setSingleLed(ledStripIdx_center, j, streamColorArr[j - 8]);
        }
        else
        {
            setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
        }
        setSingleLed(ledStripIdx_right, j, streamColorArr[j + 4]);
        setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
    }
}

static void ledMode17Ctrl(ledMode_enum oldInpMode)
{
    static uint8 i = 0;
    uint8 j = 0;
    static uint8 ledIdxOn = 0;

    if (oldInpMode != ledMode_17)
    {
        ledIdxOn = 0;
        i = 0;
    }
    else
    {
    }

    switch (i)
    {
        /* one of the 12 led light in yellow */
        case 0:
        case 1:
        case 2:
            for (j = 0; j < LED_NUM; j++)
            {
                if (j == ledIdxOn)
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_yellow]);
                }
                else
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                }
                setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
            }
            i++;
            break;

        /* all OFF next 300ms */
        case 3:
        case 4:
        case 5:
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
            }
            i++;
            if (i == 6)
            {
                ledIdxOn++;
                if (ledIdxOn == 12)
                {
                    ledIdxOn = 0;
                }
                else
                {
                }
                i = 0;
            }
            else
            {
            }
            break;

        default:
            break;
    }
}

static void ledMode18Ctrl(ledMode_enum oldInpMode)
{
    static uint8 i = 0;
    uint8 j = 0;
    static uint8 ledIdxOn = 0;

    if (oldInpMode != ledMode_18)
    {
        ledIdxOn = 0;
        i = 0;
    }
    else
    {
    }

    switch (i)
    {
    /* one of the 12 led light in yellow */
    case 0:
    case 1:
    case 2:
        for (j = 0; j < LED_NUM; j++)
        {
            if (j == (12 - ledIdxOn))
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_yellow]);
            }
            else
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            }
            setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
        }
        i++;
        break;

    /* all OFF next 300ms */
    case 3:
    case 4:
    case 5:
        for (j = 0; j < LED_NUM; j++)
        {
            setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
        }
        i++;
        if (i == 6)
        {
            ledIdxOn++;
            if (ledIdxOn == 12)
            {
                ledIdxOn = 0;
            }
            else
            {
            }
            i = 0;
        }
        else
        {
        }
        break;

    default:
        break;
    }
}

static color_enum freeModeColor2InternalColor(uint8 freeModeColor)
{
    color_enum retColor = color_off;
    switch (freeModeColor)
    {
        case 1:
            retColor = color_red;
            break;
        case 2:
            retColor = color_yellow;
            break;
        case 3:
            retColor = color_green;
            break;
        case 4:
            retColor = color_blue;
            break;
        default:
            retColor = color_off;
            break;
    }
    return retColor;
}

static void ledModeFreeCtrl()
{
    uint8 j = 0;
    color_enum selColor = color_off;
    uint8 freeModeColor = 0;
    /* left zone */
    freeModeColor = getLeftZoneFreeMode();
    selColor = freeModeColor2InternalColor(freeModeColor);
    for(j = 0; j < LED_NUM; j ++)
    {
        setSingleLed(ledStripIdx_left, j, colorArr[selColor]);
    }

    /* right zone */
    freeModeColor = getRightZoneFreeMode();
    selColor = freeModeColor2InternalColor(freeModeColor);
    for(j = 0; j < LED_NUM; j ++)
    {
        setSingleLed(ledStripIdx_right, j, colorArr[selColor]);
    }

    /* center zone */
    freeModeColor = getCenterZoneFreeMode();
    selColor = freeModeColor2InternalColor(freeModeColor);
    for(j = 0; j < LED_NUM; j ++)
    {
        setSingleLed(ledStripIdx_center, j, colorArr[selColor]);
    }
}

static void LedlightLevelCtrl(lightLevel_enum lightLevel)
{
    uint8 i = 0;
    static lightLevel_enum oldLightLevel = lightLevel_high;

    if(lightLevel != oldLightLevel)
    {
        switch (lightLevel)
        {
        case lightLevel_default:
        case lightLevel_high:
            for (i = 0; i < color_max; i++)
            {
                colorArr[i].blue    = colorArrOrign[i].blue;
                colorArr[i].green   = colorArrOrign[i].green;
                colorArr[i].red     = colorArrOrign[i].red;
            }
            break;
        case lightLevel_medium:
            for (i = 0; i < color_max; i++)
            {
                colorArr[i].blue    = colorArrOrign[i].blue * 0.75;
                colorArr[i].green   = colorArrOrign[i].green * 0.75;
                colorArr[i].red     = colorArrOrign[i].red * 0.75;
            }
            break;
        case lightLevel_low:
            for (i = 0; i < color_max; i++)
            {
                colorArr[i].blue    = colorArrOrign[i].blue * 0.5;
                colorArr[i].green   = colorArrOrign[i].green * 0.5;
                colorArr[i].red     = colorArrOrign[i].red * 0.5;
            }
            break;
        default:
            break;
        }
    }
    else
    {
        
    }
    oldLightLevel = lightLevel;
}

void ledModeUpdate()
{
    static ledMode_enum oldUserInpMode = 0;
    ledMode_enum ledMode = 0;
    uint8 ledSwth = 0;
    lightLevel_enum brightnessLevel = 0;
    uint8 j = 0;

    /* signal update from lin communication */
    ledMode = (ledMode_enum)getLedMode();
    ledSwth = getLedSwitch();
    brightnessLevel = (lightLevel_enum)getLedBrightnessLevel();

    LedlightLevelCtrl(brightnessLevel);

    if(ledSwth)
    {
        switch (ledMode)
        {
            case ledMode_1:
                // ledMode1Ctrl(oldUserInpMode);
                break;
            case ledMode_2:
                ledMode2Ctrl();
                break;
            case ledMode_3:
                ledMode3Ctrl();
                break;
            case ledMode_4:
                ledMode4Ctrl(oldUserInpMode);
                break;
            case ledMode_5:
                ledMode5Ctrl(oldUserInpMode);
                break;
            case ledMode_6:
                ledMode6Ctrl();
                break;
            case ledMode_7:
                ledMode7Ctrl();
                break;
            case ledMode_8:
                ledMode8Ctrl(oldUserInpMode);
                break;
            case ledMode_9:
                ledMode9Ctrl();
                break;
            case ledMode_10:
                ledMode10Ctrl(oldUserInpMode);
                break;
            case ledMode_11:
                ledMode11Ctrl(oldUserInpMode);
                break;
            case ledMode_12:
                ledMode12Ctrl();
                break;
            case ledMode_13:
                ledMode13Ctrl();
                break;
            case ledMode_14:
                ledMode14Ctrl(oldUserInpMode);
                break;
            case ledMode_15:
                ledMode15Ctrl(oldUserInpMode);
                break;
            case ledMode_16:
                ledMode16Ctrl(oldUserInpMode);
                break;
            case ledMode_17:
                ledMode17Ctrl(oldUserInpMode);
                break;
            case ledMode_18:
                ledMode18Ctrl(oldUserInpMode);
                break;
            case ledMode_FF:
                ledModeFreeCtrl();
                break;
            default:
                /* all leds off */
                for (j = 0; j < LED_NUM; j++)
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
                    setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
                    setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
                }
                break;
        }
    }
    else
    {
        /* all leds off */
        for (j = 0; j < LED_NUM; j++)
        {
            setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_center, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, j, colorArr[color_off]);
        }
    }

    oldUserInpMode = ledMode;

    /* signal update to lin communication */
    setLedBrightnessLevelFbk((uint8)brightnessLevel);
    setLedModeFbk((uint8)ledMode);
    setLedSwitchFbk(ledSwth);
}


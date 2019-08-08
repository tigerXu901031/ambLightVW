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

// static void blinkCtrl()
// {
// }

// static void streamCtrl()
// {
// }

static void ledMode1Ctrl(ledMode_enum oldInpMode)
{
    static uint8 darknessLevel = 0;
    uint8 j = 0;
    if (oldInpMode != ledMode_1)
    {
        darknessLevel++;
        if (darknessLevel == 3)
        {
            darknessLevel = 0;
        }
        else
        {
        }
        for (j = 0; j < color_max; j++)
        {
            colorArr[j].blue    = colorArrOrign[j].blue * (1 - (0.25 * darknessLevel));
            colorArr[j].green   = colorArrOrign[j].green * (1 - (0.25 * darknessLevel));
            colorArr[j].red     = colorArrOrign[j].red * (1 - (0.25 * darknessLevel));
        }

    }
}

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
        for (j = 0; j < LED_NUM; j++)
        {
            setSingleLed(ledStripIdx_center, j, colorArr[color_green]);
            setSingleLed(ledStripIdx_left, i, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, i, colorArr[color_off]);
        }
        i++;
        break;
    /* all OFF next 500ms */
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        for (j = 0; j < LED_NUM; j++)
        {
            setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            setSingleLed(ledStripIdx_left, i, colorArr[color_off]);
            setSingleLed(ledStripIdx_right, i, colorArr[color_off]);
        }
        i++;
        if (i == 10)
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

static void ledMode10Ctrl()
{
}

static void ledMode11Ctrl()
{
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
            }
            i++;
            if (i == 6)
                i = 0;
            break;
        default:
            break;
    }
}

static void ledMode14Ctrl()
{

}

static void ledMode15Ctrl()
{
}

static void ledMode16Ctrl()
{
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
            if (j == (12 - ledIdxOn))
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_yellow]);
            }
            else
            {
                setSingleLed(ledStripIdx_left, j, colorArr[color_off]);
            }
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

void ledModeTransitionUpdate(canSignalsType *canSigObj)
{
    static ledMode_enum oldUserInpMode = 0xff;
    switch (canSigObj->input.ledCtrlMode)
    {
    case ledMode_1:
        ledMode1Ctrl(oldUserInpMode);
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
        ledMode5Ctrl();
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
        ledMode10Ctrl();
        break;
    case ledMode_11:
        ledMode11Ctrl();
        break;
    case ledMode_12:
        ledMode12Ctrl();
        break;
    case ledMode_13:
        ledMode13Ctrl();
        break;
    case ledMode_14:
        ledMode14Ctrl();
        break;
    case ledMode_15:
        ledMode15Ctrl();
        break;
    case ledMode_16:
        ledMode16Ctrl();
        break;
    case ledMode_17:
        ledMode17Ctrl(oldUserInpMode);
        break;
    case ledMode_18:
        ledMode18Ctrl(oldUserInpMode);
        break;
    default:
        /* when system onStart without any mode transition command */
        break;
    }
    oldUserInpMode = canSigObj->input.ledCtrlMode;
}
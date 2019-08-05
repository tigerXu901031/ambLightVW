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
            colorArr[j].blue = colorArrOrign[j].blue * (1 - (0.25 * darknessLevel));
            colorArr[j].green = colorArrOrign[j].green * (1 - (0.25 * darknessLevel));
            colorArr[j].red = colorArrOrign[j].red * (1 - (0.25 * darknessLevel));
        }

    }
}

static void ledMode2Ctrl()
{
    uint8 i = 0;
    for (i = 0; i < LED_NUM; i++)
    {
        setSingleLed(ledStripIdx_left, i, colorArr[color_green]);
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
            setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
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
                setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
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
                if ((j == 5) || (j == 6))
                    setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
                else
                {
                }
                if (((j == 4) || (j == 7)) && (k >= 1))
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
                }
                else
                {
                }
                if (((j == 3) || (j == 8)) && (k >= 2))
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
                }
                else
                {
                }
                if (((j == 2) || (j == 9)) && (k >= 3))
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
                }
                else
                {
                }
                if (((j == 1) || (j == 10)) && (k >= 4))
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
                }
                else
                {
                }
                if (((j == 0) || (j == 11)) && (k >= 5))
                {
                    setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
                }
                else
                {
                }
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
            break;
        default:
            break;
    }
}

static void ledMode5Ctrl()
{

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
            setSingleLed(ledStripIdx_left, j, colorArr[color_yellow]);
        }
        i++;
        break;
    /* all OFF next 500ms */
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

static void ledMode7Ctrl()
{
    rgb_type brightnessColor;
    static uint8 brightnessLevel = 0;
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
                brightnessColor.blue = colorArr[color_yellow].blue / (10 - brightnessLevel);
                brightnessColor.green = colorArr[color_yellow].green / (10 - brightnessLevel);
                brightnessColor.red = colorArr[color_yellow].red / (10 - brightnessLevel);
                setSingleLed(ledStripIdx_left, j, brightnessColor);
            }
            i++;
            break;
        /* all OFF next 500ms */
        case 3:
        case 4:
        case 5:
            for (j = 0; j < LED_NUM; j++)
            {
                brightnessColor.blue = colorArr[color_red].blue / (10 - brightnessLevel);
                brightnessColor.green = colorArr[color_red].green / (10 - brightnessLevel);
                brightnessColor.red = colorArr[color_red].red / (10 - brightnessLevel);
                setSingleLed(ledStripIdx_left, j, brightnessColor);
            }
            i++;
            if (i == 6)
            {
                i = 0;
                if (brightnessLevel < 9)
                {
                    brightnessLevel++;
                }
                else
                {
                }
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
                setSingleLed(ledStripIdx_left, j, colorArr[color_green]);
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
                setSingleLed(ledStripIdx_left, j, colorArr[color_blue]);
            }
            i++;
            if (i == 10)
            {
                i = 0;
                k++;
            }
            break;
        case 0xff:
            brightnessColor.blue = colorArr[color_blue].blue / 3;
            brightnessColor.green = colorArr[color_blue].green / 3;
            brightnessColor.red = colorArr[color_blue].red / 3;
            for (j = 0; j < LED_NUM; j++)
            {
                setSingleLed(ledStripIdx_left, j, brightnessColor);
            }
        default:
            break;
    }
}

static void ledMode9Ctrl()
{
    uint8 i = 0;
    rgb_type brightnessColor;
    brightnessColor.blue = colorArr[color_blue].blue / 3;
    brightnessColor.green = colorArr[color_blue].green / 3;
    brightnessColor.red = colorArr[color_blue].red / 3;
    for (i = 0; i < LED_NUM; i++)
    {
        setSingleLed(ledStripIdx_left, i, brightnessColor);
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
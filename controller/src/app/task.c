#include "task.h"

static void testFun()
{
    rgb_type rgbVal;
    rgbVal.blue = 0x00, rgbVal.red = 0xff, rgbVal.green = 0x00;
    setSingleLed(ledStripIdx_left, 0, rgbVal);
    rgbVal.blue = 0x00, rgbVal.red = 0x00, rgbVal.green = 0xff;
    setSingleLed(ledStripIdx_left, 1, rgbVal);
    rgbVal.blue = 0xff, rgbVal.red = 0x00, rgbVal.green = 0x00;
    setSingleLed(ledStripIdx_left, 2, rgbVal);
    rgbVal.blue = 0, rgbVal.red = 200, rgbVal.green = 100;
    setSingleLed(ledStripIdx_left, 3, rgbVal);
    rgbVal.blue = 0, rgbVal.red = 255, rgbVal.green = 255;
    setSingleLed(ledStripIdx_left, 4, rgbVal);
    rgbVal.blue = 255, rgbVal.red = 255, rgbVal.green = 0;
    setSingleLed(ledStripIdx_left, 5, rgbVal);
    rgbVal.blue = 0x20, rgbVal.red = 0x20, rgbVal.green = 0x20;
    setSingleLed(ledStripIdx_left, 6, rgbVal);
    rgbVal.blue = 0xaa, rgbVal.red = 0xaa, rgbVal.green = 0xaa;
    setSingleLed(ledStripIdx_left, 7, rgbVal);
    rgbVal.blue = 0xaa, rgbVal.red = 0xaa, rgbVal.green = 0xaa;
    setSingleLed(ledStripIdx_left, 8, rgbVal);
    rgbVal.blue = 0xaa, rgbVal.red = 0xaa, rgbVal.green = 0xaa;
    setSingleLed(ledStripIdx_left, 9, rgbVal);
    rgbVal.blue = 0xaa, rgbVal.red = 0xaa, rgbVal.green = 0xaa;
    setSingleLed(ledStripIdx_left, 10, rgbVal);
    rgbVal.blue = 0xaa, rgbVal.red = 0xaa, rgbVal.green = 0xaa;
    setSingleLed(ledStripIdx_left, 11, rgbVal);
}

void taskInit()
{

    /* globally disable interrupts */
    PSW_IEN = 0;

/*  -----------------------------------------------------------------------
     Configuration of the System Clock:
    -----------------------------------------------------------------------
 */

    /* 
    - VCO clock used, input clock is connected
    - input frequency is 8.00 MHz
    - system clock is 80.00 MHz
    */

    /* unlock write security */
    MAIN_vUnlockProtecReg();
    /* load PLL control register */
    MAIN_vChangeFreq();

/*  -----------------------------------------------------------------------
     SCU Interrupt Disable configuration:
    -----------------------------------------------------------------------
 */
  SCU_INTDIS     =  0xFFFF;      // SCU Interrupt Disable Register

/*  -----------------------------------------------------------------------
     Initialization of the Peripherals:
    -----------------------------------------------------------------------
 */

/* initializes the Capture / Compare Unit 60 (CCU60) */
#if LED_OUTPUT_TYPE == PWN_CTRL
    CCU60_vInit();
#elif LED_OUTPUT_TYPE == GPIO_CTRL
    IO_vInit();
#endif

/*  -----------------------------------------------------------------------
    SCU Interrupt Source Selection configuration:
    -----------------------------------------------------------------------
 */
    SCU_ISSR       =  0x0000;      // SCU Interrupt Source Select Register
/*  -----------------------------------------------------------------------
    Initialization of the Bank Select registers:
    -----------------------------------------------------------------------
 */

    /* lock write security */
    MAIN_vLockProtecReg();

/*  -----------------------------------------------------------------------
    Initialization of app module:
    -----------------------------------------------------------------------
 */

    /* globally enable interrupts */
    PSW_IEN = 1;
}

/* task will be running in this 100ms task cycle
   so far using while loop to manually realize the
   scheduler 
   So first do an very rough estimation of 100ms cycle.
   Later add an time stamp at the entry of this function
   and wait for some while to 
    1. change led strip mode
    2. CAN message Rx / Tx 
 */
uint8 manualMode = 0xff;

canSignalsType testCanSigObj;
void taskSlow()
{
    /* TODO: add entry time stamp record and some delay logic
       to ensure the time interval between two taskSlow is 100ms */
    /* test purpose only */
    // testFun();

    /* get the user input from can */
    // canUpdate(&canSigObj);

    /* according to the user input then do the led mode transition */
    ledModeTransitionUpdate(&testCanSigObj);

    /* encode all the led strip */
    ledRgbEncodeUpdate(ledStripIdx_left);
    // ledRgbEncodeUpdate(ledStripIdx_center);
    // ledRgbEncodeUpdate(ledStripIdx_right);
}

/* task will be running in this 1.25us task cycle
    1. encode the 24-bit NZR communication protocol
       to the single led
 */
void taskFast()
{
    // ledUpdate(ledStripIdx_left);
    // ledUpdate(ledStripIdx_right);
    // ledUpdate(ledStripIdx_center);
}
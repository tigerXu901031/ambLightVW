//**************************************************************************** 
// @Function void U0C0_LIN_Master_vInit(void)
// @Date 15.11.2007 
//**************************************************************************** 

#include "linDrv.h"

void linDrvInit(void)
{ 
    // Sys_Protection(0); 
    U0C0_KSCFG = 3; 
    // Sys_Protection(1);
    U0C0_CCR = 0x0000; // recommanded

/// ----------------------------------------------------------------------- 
/// 1. baud rate generation and the PPP configuration
/// baud rate = 19200,
/// fasc=80000 x 1000 /(1024-STEP) / (PDIV+1) / (PCTQ+1) / (DCTQ+1) = 19231
/// ----------------------------------------------------------------------- 
    U0C0_FDRL = (((uword)1<<14)|(764<<0));                              //DM=1(normal divider), STEP=764 
    U0C0_BRGL = ((15<<10)|(0<<8)|(0<<4)|(0<<0));                        //DCTQ=15,PCTQ=0,PPPEN=0,CLKSEL=0 
    U0C0_BRGH = ((0<<14)|(0<<13)|(0<<0));                               //SCLKCFG=0,MCLKCFG=0,PDIV=0

/// ----------------------------------------------------------------------- 
/// 2. Configuration of the U0C0 Input Control Register and port pins
/// -----------------------------------------------------------------------
// CM SFSEL DPOL DSEN DFEN INSW DESL 
    U0C0_DX0CR = ((0<<10)|(0<<9)|(0<<8)|(0<<6)|(0<<5)|(0<<4)|(5<<0));   //RX - P2.4(DX0F)
    // U0C0_DX1CR = ((0<<10)|(0<<9)|(0<<8)|(0<<6)|(0<<5)|(0<<4)|(4<<0));   //Tx - P2.3 colliion (optional in half-duplex)

/// ----------------------------------------------------------------------- 
/// 3. Data format: shift control signal, word/frame length control
/// -----------------------------------------------------------------------
    //           TRM=01b(ASC) DOCFG     PDL       SDIR=0(LSB first) 
    U0C0_SCTRL = (1 << 8) | (0 << 6) | (1 << 1) | (0 << 0); 
    U0C0_SCTRH = (7 << 8) | (7 << 0);                                 //WLE=7 , FLE=7

/// ----------------------------------------------------------------------- 
/// 4. data transmission control (TBUF single shot mode)        
/// -----------------------------------------------------------------------
//               TDEN=1      TDSSM=1    FLEMD=0    WLEMD=0 
    U0C0_TCSRL = (1 << 10) | (1 << 8) | (0 << 2) | (0 << 0); 
    U0C0_TCSRH = 0x0000;

/// ----------------------------------------------------------------------- 
// 5. protocol-related information
// CTR[0]       SMD     sample mode
// CTR[1]       STPB    stop bit
// CTR[2]       IDM     idle detection mode
// CTR[3]       SBIEN   Sync.-Break Interrupt Enable
// CTR[4]       CDEN    Collision Detection Enable (for half-duplex mode)
// CTR[5]       RNIEN   Receiver Noise Detection Interrupt Enable
// CTR[6]       FEIEN   Format Error Interrupt Enable
// CTR[7]       FFIEN   Frame Finished Interrupt Enable
// CTR[8-12]    SP      Sample Position
// CTR[13-15]   PL      Pulse Length
// CTR[31]      MCLK    master clock enable
/// -----------------------------------------------------------------------
    //          PL     SP     FFIEN  FEIEN  RNIEN  CDEN   SBIEN  IDM    STPB   SMD 
    U0C0_PCRL=(0<<13)|(7<<8)|(1<<7)|(0<<6)|(0<<5)|(0<<4)|(1<<3)|(0<<2)|(0<<1)|(0<<0);
    U0C0_PCRH=(0<<15);                                                  // MCLK not used
    /* TBD: 
        1. do FFIEN(Frame Finished Interrupt Enable) need to be set ?
        2. do MCLK(Master Clock Enable) need to be set ? */

/// ----------------------------------------------------------------------- 
/// 6. Configuration of the interrupts point and interrupt control registers 
/// -----------------------------------------------------------------------
    //            AINP=SR0,  RINP=SR0, TBINP=SR0,  TSINP=SR0
    U0C0_INPRL = (0 << 12) | (0 << 8) | (0 << 4) | (0 << 0);
    U0C0_INPRH = (1 << 0);                                              //PINP=SR1 for collision detection and SBIR

    U0C0_0IC = (0x80 * 0 + 0x40 * 1 + ((10 << 2)|0));                   //IR=0, IE=1, ILVL=10, GPX=0 
    U0C0_1IC = (0x80 * 0 + 0x40 * 1 + ((10 << 2)|1));                   //IR=0, IE=1, ILVL=10, GPX=1 
    U0C0_2IC = (0x80 * 0 + 0x40 * 0 + ((10 << 2)|2));                   //IR=0, IE=0, ILVL=10, GPX=2

/// -----------------------------------------------------------------------
/// 7. Configuration of the U0C0 Channel Control Register
// enable/disable general interrupt
// enable/disable the parity mode
// select the protocol mode
/// -----------------------------------------------------------------------
    // AIEN=0, RIEN=0, TBIEN=0, TSIEN=0, DLIEN=0, RSIEN=0  
    U0C0_CCR = (0 << 15)|(0 << 14)|(0 << 13)|(0 << 12)|(0 << 11)|(0 << 10);
    U0C0_CCR |= (0 << 8);                                               // PM=0(no parity generation)
    U0C0_CCR |= 0x0002;                                                 // active ASC mode


/// -----------------------------------------------------------------------
/// 8. input/output pins configuration
/// ----------------------------------------------------------------------- 
    P2_IOCR04 = 0x0020;                                                 // P2.4=input(pull_up)
    P2_IOCR03 = 0x0090;                                                 // P2.3=output(ALT1 open-drain)
}

void linDisable()
{
    /* globally disable interrupts */
    PSW_IEN = 0;

    rxDataBytePtr = 0;
}

void linEnable()
{
    linDrvInit();
    //rxDataBytePtr = 0;
    /* globally enable interrupts */
    PSW_IEN = 1;
}

uint16 psrReg = 0;
void U0C0_ASC_Protocol1(void) interrupt U0C0_SRN0
{
    static uword uwTSIRCount = 0;
    static uword uwPDIV[5];
    uword uwTmp = 0;

    /* lin slave sync field, baudrate measuring mode active */
    if((U0C0_BRGL & 0x0008) && (U0C0_PSR & 0x1000))
    {
        if(uwTSIRCount == 0)
        {
            uwTSIRCount +=1;
        }
        else if(uwTSIRCount < 4)
        {
            /* save PDIV */
            uwPDIV[uwTSIRCount] = U0C0_BRGH & 0x3ff;
            uwTSIRCount += 1;
        }
        else
        {
            /* save PDIV */
            uwPDIV[uwTSIRCount] = U0C0_BRGH & 0x3ff;

            uwTmp = (uwPDIV[uwTSIRCount] / 2);

            uwTmp = uwTmp / ((U0C0_BRGL & 0xFC00) >> 10);

            U0C0_BRGH = U0C0_BRGH & (~(uword)0x003f);
            
            /* PFDIV */
            U0C0_BRGH |= (uwTmp - 1);

            /* deactivate the baudrate measuring mode(reset TMEN) */
            U0C0_BRGL &= ~((uword)0x0008);
        
            /* disable the transmit shift interrupt (reset TSIEN) */
            U0C0_CCR &= ~((uword) 1 << 12);

            /* clear the synchronize bit counter */
            uwTSIRCount = 0;
            
            /* once detect the baud rate then switch the state to recieve
               the lin message id */
            Lin_StateMachine.Lin_CommState = LIN_PID;
        }
    }

    /* clear all flags */
    U0C0_PSCR = 0xFFFF;
}
//**************************************************************************** 
// @Function void U0C0_ASC_Protocoll(void)
// @Date 15.11.2007 
//****************************************************************************
uint16 rxDataGlobal[20];
uint8 dataByteCnt = 0;
void U0C0_ASC_Protocol(void) interrupt U0C0_SRN1
{
    static uword uwTSIRCount = 0;
    static uword uwPDIV[5];
    uint8 rxData = 0;
    uword uwTmp = 0;

    psrReg = U0C0_PSR;

    /* collesion interrupt */
    if(U0C0_PSR & 0x0008)
    {
        U0C0_PSCR |= 0x0008;        
    }

    /* lin slave state machine actions upon sync break detection */
    else if(U0C0_PSR & 0x0004)
    {
        /* set bit timing measuring mode bit-3 TMEN = 1*/
        U0C0_BRGL |= 0x0008;

        /* CM = 2(combination mode) falling edge activates DXnt */
        U0C0_DX0CR = (2 << 10) | (0 << 9) | (0 << 8) | (0 << 6) | (0 << 5) | (0 << 4) | (5 << 0);

        /* TSIEN = 1(transmit shift interrupt enable) */
        U0C0_CCR |= (1 << 12);
    }
    /* recieve or transmit interrupt */
    else if((U0C0_PSR & 0x0080) || (U0C0_PSR & 0x1000))
    {
        if(U0C0_PSR & 0x0080)
        {
            rxDataGlobal[dataByteCnt] = U0C0_RBUF;
            dataByteCnt ++;
            rxData = (uint8)U0C0_RBUF;
            if(dataByteCnt == 11)
            {
                dataByteCnt = 0;
            }
        }
        else
        {
            
        }
        /* handle the service such as message id 
           matching, tx, rx, checksum */
        linProtocolHandler(rxData);
    }
    else
    {

    }
    /* clear all interrupt flags */
    U0C0_PSCR = 0xFFFF;
}
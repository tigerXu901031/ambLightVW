//****************************************************************************
// @Module        Universal Serial Interface Channel (USIC) U0C0
// @Filename      u0c0.c
// @Project       ioPlusLIN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2234L-20F66L
//
// @Compiler      TASKING VX-toolset
//
// @Codegenerator 1.2
//
// @Description   This file contains functions that use the U0C0 module.
//
//----------------------------------------------------------------------------
// @Date          2019/8/4 11:50:49
//
//****************************************************************************

// USER CODE BEGIN (U0C0_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "u0c0.h"

// USER CODE BEGIN (U0C0_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (U0C0_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (U0C0_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (U0C0_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (U0C0_General,6)

// USER CODE END

uword uwU0C0TBIENflag;          // Flag for Transmit Buffer Interrupt

//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (U0C0_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (U0C0_General,8)

// USER CODE END




//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (U0C0_General,9)

// USER CODE END


//****************************************************************************
// @Function      void U0C0_ASC_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the U0C0 function
//                library. It is assumed that the SFRs used by this library
//                are in reset state.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/4
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void U0C0_ASC_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Channel Control Register (Mode & Interrupts):
  ///  -----------------------------------------------------------------------
  /// - The USIC channel is disabled
  /// - The parity generation is disabled

  U0C0_CCR       =  0x0000;      // load U0C0 channel control register

  ///  -----------------------------------------------------------------------
  ///  U0C0 ASC is configured for Full-Duplex Operation Mode:
  ///  -----------------------------------------------------------------------

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Fractional Divider:
  ///  -----------------------------------------------------------------------
  ///  - The Fractional divider is selected
  ///  - The step value STEP = 953

  U0C0_FDRL      =  0x83B9;      // load U0C0 fractional divider register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Baudrate Generator:
  ///  -----------------------------------------------------------------------
  ///  - The selected BaudRate is 19.200 kbaud
  ///  - The PreDivider for CTQ, PCTQ = 1
  ///  - The Denominator for CTQ, DCTQ = 15
  ///  - The Divider factor PDIV = 99

  U0C0_BRGL      =  0x3D00;      // load U0C0 load baud rate generator 
                                 // register L

  U0C0_BRGH      =  0x0063;      // load U0C0 load baud rate generator 
                                 // register H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Input Control Register 0:
  ///  -----------------------------------------------------------------------
  ///  - The data input DX0F is selected for pin - P2.4

  U0C0_DX0CR     =  0x0005;      // load U0C0 input control register(Data)

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Interrupt Node Pointer Register:
  ///  -----------------------------------------------------------------------
  ///  - AINP pointer points to Interrupt node U0C0_0IC
  ///  - RINP pointer points to Interrupt node U0C0_1IC
  ///  - TBINP pointer points to Interrupt node U0C0_0IC
  ///  - TSINP pointer points to Interrupt node U0C0_2IC
  ///  - PINP pointer points to Interrupt node U0C0_1IC

  U0C0_INPRL     =  0x0102;      // load U0C0 Interrupt Node Pointer register 
                                 // L
  U0C0_INPRH     =  0x0001;      // load U0C0 Interrupt Node Pointer register 
                                 // H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Shift Control:
  ///  -----------------------------------------------------------------------
  ///  - Transmit/Receive LSB first is selected
  ///  - Transmission Mode (TRM) = 1
  ///  - Passive Data Level (PDL) = 1

  U0C0_SCTRL     =  0x0102;      // load U0C0 shift control register L

  ///  - Word Length (WLE) = 7
  ///  - Frame Length (FLE) = 7

  U0C0_SCTRH     =  0x0707;      // load U0C0 shift control register H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Transmit Control/Status Register:
  ///  -----------------------------------------------------------------------
  ///  - TBUF Data Enable (TDEN) = 1
  ///  - TBUF Data Single Shot Mode (TDSSM) = 1

  U0C0_TCSRL     =  0x0500;      // load U0C0 transmit control/status 
                                 // register L
  U0C0_TCSRH     =  0x0000;      // load U0C0 transmit control/status 
                                 // register H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Protocol Control Register:
  ///  -----------------------------------------------------------------------
  ///  - Sample Mode (SMD) = 1
  ///  - 1 Stop bit is selected
  ///  - Receiver noise detection interrupt is enabled
  ///  - Format error interrupt is enabled
  ///  - Frame finished interrupt is enabled
  ///  - Sample Point (SP) = 7
  ///  - Pulse Length (PL) = 0

  U0C0_PCRL      =  0x07E1;      // load U0C0 protocol control register L
  U0C0_PCRH      =  0x0000;      // load U0C0 protocol control register H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Protocol Status Register:
  ///  -----------------------------------------------------------------------
  ///  - TBIF is set to simplify polling

  U0C0_PSR      |=  0x2000;      // load U0C0 protocol status register


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used U0C0 Interrupts:
  ///  -----------------------------------------------------------------------
  ///  U0C00IC service request node configuration:
  ///  - U0C00IC interrupt priority level (ILVL) = 15
  ///  - U0C00IC interrupt group level (GLVL) = 0
  ///  - U0C00IC group priority extension (GPX) = 0

  U0C0_0IC       =  0x007C;     

  ///  Use PEC channel 4 for U0C0_0IC INT:
  ///  - normal interrupt
  ///  - pointers are not modified
  ///  - transfer a word
  ///  - service End of PEC interrrupt by a EOP interrupt node is disabled
  ///  - channel link mode is disabled

  PECC4          =  0x0000;      // load PECC4 control register


  ///  U0C01IC service request node configuration:
  ///  - U0C01IC interrupt priority level (ILVL) = 14
  ///  - U0C01IC interrupt group level (GLVL) = 1
  ///  - U0C01IC group priority extension (GPX) = 0

  U0C0_1IC       =  0x0079;     

  ///  Use PEC channel 1 for U0C0_1IC INT:
  ///  - normal interrupt
  ///  - pointers are not modified
  ///  - transfer a word
  ///  - service End of PEC interrrupt by a EOP interrupt node is disabled
  ///  - channel link mode is disabled

  PECC1          =  0x0000;      // load PECC1 control register


  ///  U0C02IC service request node configuration:
  ///  - U0C02IC interrupt priority level (ILVL) = 13
  ///  - U0C02IC interrupt group level (GLVL) = 2
  ///  - U0C02IC group priority extension (GPX) = 0

  U0C0_2IC       =  0x0076;     

  ///  -----------------------------------------------------------------------
  ///  Configuration of U0C0 FIFO:
  ///  -----------------------------------------------------------------------
  ///  -----------------------------------------------------------------------
  ///  Configuration of U0C0 Transmitter Buffer Conrol Register:
  ///  -----------------------------------------------------------------------
  ///  - Transmit FIFO buffer is disabled
  ///  -----------------------------------------------------------------------
  ///  Configuration of U0C0 Receiver Buffer Conrol Register:
  ///  -----------------------------------------------------------------------
  ///  - Receive FIFO buffer is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Channel Control Register (Mode & Interrupts):
  ///  -----------------------------------------------------------------------
  ///  - ASC (SCI, UART) Protocol is selected 
  ///  - The parity generation is disabled
  ///  - Receiver start interrupt is enabled
  ///  - Transmit shift interrupt is enabled
  ///  - Transmit buffer interrupt is enabled
  ///  - Receive interrupt is enabled
  ///  - Alternate receive interrupt is enabled

  U0C0_CCR       =  0xF402;      // load U0C0 channel control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used U0C0 Port Pins:
  ///  -----------------------------------------------------------------------
  P2_IOCR04      =  0x0020;      // load port register for data input

  ///  - P2.3 is used for USIC0 Channel0 Shift Data Output(DOUT)

  P2_IOCR03 = 0x0090;    //set direction register



  // USER CODE BEGIN (U0C0_Function,3)

  // USER CODE END



} //  End of function U0C0_ASC_vInit


//****************************************************************************
// @Function      void U0C0_ASC_vSendData(uword uwData) 
//
//----------------------------------------------------------------------------
// @Description   This function clears the transmit buffer Indication flag 
//                first  & then writes the send data initialization word into 
//                the transmit buffer register.
//                
//                Note: 
//                In a multiprocessor system the master with this function 
//                has the possibility to send data to the selected slave.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    uwData: 
//                Data to be send
//
//----------------------------------------------------------------------------
// @Date          2019/8/4
//
//****************************************************************************

// USER CODE BEGIN (ASCSendData,1)

// USER CODE END

void U0C0_ASC_vSendData(uword uwData)
{

  U0C0_TBUF00    = uwData;   //  load transmit buffer register

  while(uwU0C0TBIENflag != 1);
  uwU0C0TBIENflag = 0;
} //  End of function U0C0_ASC_vSendData


//****************************************************************************
// @Function      uword U0C0_ASC_uwGetData(void) 
//
//----------------------------------------------------------------------------
// @Description   This function reads out the content of the receive buffer 
//                register which contains the received data.
//
//----------------------------------------------------------------------------
// @Returnvalue   Data that has been received
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/4
//
//****************************************************************************

// USER CODE BEGIN (ASCGetData,1)

// USER CODE END

uword U0C0_ASC_uwGetData(void)
{

  return(U0C0_RBUF);         // return receive buffer register


} //  End of function U0C0_ASC_uwGetData


//****************************************************************************
// @Function      ubyte U0C0_ASC_ubTxDataReady(void) 
//
//----------------------------------------------------------------------------
// @Description   This function can be used for checking up the status of the 
//                transmit shift indication flag U0C0_PSR_TSIF. This function 
//                shows when the sending of data has terminated. By 
//                continuously polling this flag after the function 
//                U0C0_ASC_vSendData has been called, it is possible to 
//                establish when U0C0 has terminated its task.
//
//----------------------------------------------------------------------------
// @Returnvalue   0 if transmitter is busy, else 1
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/4
//
//****************************************************************************

// USER CODE BEGIN (ASCTxDataReady,1)

// USER CODE END

ubyte U0C0_ASC_ubTxDataReady(void)
{
  ubyte ubReturnValue;

  ubReturnValue = 0;

  if(U0C0_PSR & 0x1000)               // if sending of data is terminated
  {
    ubReturnValue = 1;
    U0C0_PSCR |= 0x1000;
  }
  return(ubReturnValue);

} //  End of function U0C0_ASC_ubTxDataReady


//****************************************************************************
// @Function      void U0C0_ASC_vi0IC(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the Service 
//                Request Node U0C0_0IC.
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/4
//
//****************************************************************************

// USER CODE BEGIN (ASC0IC,1)

// USER CODE END

void U0C0_ASC_vi0IC(void) interrupt U0C0_0INT
{

  // USER CODE BEGIN (ASC0IC,2)

  // USER CODE END

  if (U0C0_PSR & 0x8000)         // Alternate receive interrupt flag
  {

  // USER CODE BEGIN (ASC0IC,3)

  // USER CODE END

  U0C0_PSCR   |= 0x8000;         // clear PSR_AIF
  }

  if (U0C0_PSR & 0x2000)         // Transmit buffer interrupt flag
  {

  // USER CODE BEGIN (ASC0IC,5)

  // USER CODE END

  uwU0C0TBIENflag = 1;
  U0C0_PSCR   |= 0x2000;         // clear PSR_TBIF
  }

  if (U0C0_PSR & 0x0400)         // Receiver start interrupt flag
  {

  // USER CODE BEGIN (ASC0IC,8)

  // USER CODE END

  U0C0_PSCR   |= 0x0400;         // clear PSR_RSIF
  }

  // USER CODE BEGIN (ASC0IC,15)

  // USER CODE END

} //  End of function U0C0_ASC_vi0IC


//****************************************************************************
// @Function      void U0C0_ASC_vi1IC(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the Service 
//                Request Node U0C0_1IC.
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/4
//
//****************************************************************************

// USER CODE BEGIN (ASC1IC,1)

// USER CODE END

void U0C0_ASC_vi1IC(void) interrupt U0C0_1INT
{

  // USER CODE BEGIN (ASC1IC,2)

  // USER CODE END

  if (U0C0_PSR & 0x4000)         // Receive interrupt flag
  {

  // USER CODE BEGIN (ASC1IC,4)

  // USER CODE END

  U0C0_PSCR   |= 0x4000;         // clear PSR_RIF
  }

  if (U0C0_PSR & 0x0010)         // Receiver noise detection interrupt flag
  {

  // USER CODE BEGIN (ASC1IC,10)

  // USER CODE END

  U0C0_PSCR   |= 0x0010;         // clear PSR_ST4/RNS
  }

  if (U0C0_PSR & 0x0020)         // Format error interrupt flag in stop bit 0
  {

  // USER CODE BEGIN (ASC1IC,11)

  // USER CODE END

  U0C0_PSCR   |= 0x0020;         // clear PSR_ST5/FER0
  }

  if (U0C0_PSR & 0x0040)         // Format error interrupt flag in stop bit 1
  {

  // USER CODE BEGIN (ASC1IC,12)

  // USER CODE END

  U0C0_PSCR   |= 0x0040;         // clear PSR_ST6/FER1
  }

  if (U0C0_PSR & 0x0080)         // Rx frame finished interrupt flag
  {

  // USER CODE BEGIN (ASC1IC,13)

  // USER CODE END

  U0C0_PSCR   |= 0x0080;         // clear PSR_ST7/RFF
  }

  if (U0C0_PSR & 0x0100)         // Tx frame finished interrupt flag
  {

  // USER CODE BEGIN (ASC1IC,14)

  // USER CODE END

  U0C0_PSCR   |= 0x0100;         // clear PSR_ST8/TFF
  }

  // USER CODE BEGIN (ASC1IC,15)

  // USER CODE END

} //  End of function U0C0_ASC_vi1IC


//****************************************************************************
// @Function      void U0C0_ASC_vi2IC(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the Service 
//                Request Node U0C0_2IC.
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/4
//
//****************************************************************************

// USER CODE BEGIN (ASC2IC,1)

// USER CODE END

void U0C0_ASC_vi2IC(void) interrupt U0C0_2INT
{

  // USER CODE BEGIN (ASC2IC,2)

  // USER CODE END

  if (U0C0_PSR & 0x1000)         // Transmit shift interrupt flag
  {

  // USER CODE BEGIN (ASC2IC,6)

  // USER CODE END

  U0C0_PSCR   |= 0x1000;         // clear PSR_TSIF
  }

  // USER CODE BEGIN (ASC2IC,15)

  // USER CODE END

} //  End of function U0C0_ASC_vi2IC




// USER CODE BEGIN (U0C0_General,10)

// USER CODE END


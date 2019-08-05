//****************************************************************************
// @Module        Universal Serial Interface Channel (USIC) U0C0
// @Filename      u0c0.h
// @Project       ioPlusLIN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2234L-20F66L
//
// @Compiler      TASKING VX-toolset
//
// @Codegenerator 1.2
//
// @Description   This file contains all function prototypes and macros for 
//                the U0C0 module.
//
//----------------------------------------------------------------------------
// @Date          2019/8/4 11:50:49
//
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,1)

// USER CODE END



#ifndef _u0c0_H_
#define _u0c0_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,2)
#include "XC22xxLREGS.H"
// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void U0C0_ASC_vInit(void);
void U0C0_ASC_vSendData(uword uwData);
uword U0C0_ASC_uwGetData(void);
ubyte U0C0_ASC_ubTxDataReady(void);


// USER CODE BEGIN (U0C0_Header,8)

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define U0C0_0INT    0x50         // SR0 of U0C0
#define U0C0_1INT    0x51         // SR1 of U0C0
#define U0C0_2INT    0x52         // SR2 of U0C0


// USER CODE BEGIN (U0C0_Header,9)

// USER CODE END


#endif  // ifndef _u0c0_H_

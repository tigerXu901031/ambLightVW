/***************************************************************************
**   File       :  linLdf.c
**   Controller :  Infineon XC2234L
**   LIN Version:  2.1
**   Description:  Source file for the defined LIN cluster(LIN_LDF_CFILE)
****************************************************************************/



#include "linLdf.h"


/*   This file contains the Modules for LIN cluster.It provides the details about
**   Schedules,Signals,Frames and its Types.
**   This file information provided by DAvE tool, User may not change the values.*/




/*   The Lin_FrmInfo represents frame properties.*/

     uint8 Lin_FrmInfo[LIN_SYS_TOTAl_NUM_FRAMES] = {
          0xC3,0x81,0x87,0xC7
         };

/*   The Lin_FrmOffset represents frame data offset.*/

     uint8 Lin_FrmOffset[LIN_SYS_TOTAl_NUM_FRAMES] = {
          0,4,6,14
         };

/*   The Lin_FrmTbl represents frame IDs.*/

     uint8 Lin_FrmTbl[LIN_SYS_TOTAl_NUM_FRAMES]  = {
          0x00,0x01,0x3C,0x3D
         };

     uint8 Lin_FrmData[LIN_SYS_TOTAl_FRM_BUFF_SZ + 8] = {
     0xCE,0x00,0x00,0xF0,0xF0,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x00,0x00
     };
     uint8 Lin_FrmDataUpdtFlag[(LIN_SYS_NUM_FRMS >> 3) + 1] = {
     0x00
     };
     uint8 Lin_FrmDataInitFlag[(LIN_SYS_NUM_FRMS >> 3) + 1] = {
     0x03
     };



#ifndef __LINSRV_H__
#define __LINSRV_H__

#include "type.h"
#include "../drv/linDrv.h"

#define LIN_MSG_LENGTH  8
#define LIN_MSG_TX_LENGTH   9

typedef enum{
    linRxReq,
    linTxReq,
}linReq_enum;

typedef struct{
    linReq_enum     reqType;
    uint8           reqMsgIdx;
}lineReq_type;

/*                                                                                       
   @enum:(DESIGN) LIN_IFC_CURR_STATE |                                                   
   Specify the current state of interface in specific frame transaction period.          
 */                                                                                      
typedef enum                                                                             
{                       
  /* 
  IDLE state, interface enter into this state whenever it expec
  after current frame transaction or sleep state. 
  */
  LIN_IDLE      = 0U,
  /* Interface waiting for receiving a break signal. */     
  LIN_BREAK     = 1U,   
   /* Waiting for sync signal */                
  LIN_SYNC      = 2U,  
  /* Waiting for frame ID */                                      
  LIN_PID       = 3U,         
  /* Interface is subscriber and receiving data */                            
  LIN_RX_DATA   = 4U,  
  /* Interface is publisher and transmits data */                 
  LIN_TX_DATA   = 5U,  
  /* Waiting for receiving checksum byte */                        
  LIN_RX_CHKSUM = 6U,        
   /* Sending checksum byte */                   
  LIN_TX_CHKSUM = 7U  
} LIN_COMM_STATE;   

typedef enum
{  
    /* Break / Sync default state , waiting for a new break */
    LIN_BRK_SYNC_IDLE = 0U,
    /* Break / Sync state is waiting for SYNC Byte */
    LIN_DETECT_SYNC   = 1U 
} LIN_BRK_SYNC_STATE;

typedef struct
{
    /* Break / SYNC State Machine */
    LIN_BRK_SYNC_STATE  Lin_BrkSyncState; 

    /* Frame Processing State Machine */	
    LIN_COMM_STATE      Lin_CommState;
}LIN_SLAVE_STATE_INFO;

typedef enum{
    LIN_RX_MSG_HMI_status_light_control,
    LIN_RX_MSG_MAX,
}LIN_RX_MSG_IDX;

typedef enum{
    LIN_TX_MSG_HMI_status_light_report,
    LIN_TX_MSG_MAX,
}LIN_TX_MSG_IDX;

/* message 0x017 layout */
typedef struct{
    uint8 HMI_status_light_switch       : 1;        /* byte 0, bit 0 */
    uint8                               : 3;        /* byte 0, bit 1 - 3 */
    uint8 HMI_status_lightness          : 2;        /* byte 0, bit 4 - 5 */
    uint8                               : 2;        /* byte 0, bit 6 - 7 */
    uint8 HMI_status_light_mode         : 8;        /* byte 1, bit 0 - 7 */
    uint8 FreeMode_LightMatrix_L        : 4;        /* byte 2, bit 0 - 3 */
    uint8 FreeMode_LightMatrix_T        : 4;        /* byte 2, bit 4 - 7 */
    uint8 FreeMode_LightMatrix_R        : 4;        /* byte 3, bit 0 - 4 */
}msg_HMI_status_light_control_type;

/* message 0x018 layout */
typedef struct{
    uint8 HMI_status_light_status       : 2;        /* byte 0, bit 0 - 1 */
    uint8                               : 2;        /* byte 0, bit 2 - 3 */
    uint8 HMI_status_lightness_report   : 2;        /* byte 0, bit 4 - 5 */
    uint8                               : 2;        /* byte 0, bit 6 - 7 */
    uint8 HMI_status_light_mode_report  : 8;        /* byte 1, bit 0 - 7 */
}msg_HMI_status_light_report_type;

typedef union{
    msg_HMI_status_light_control_type   msg_HMI_status_light_control;
    msg_HMI_status_light_report_type    msg_HMI_status_light_report;
    uint8                               dataBuf[9];
}LinMsgData_type;

typedef struct{
    uint8           msgId;
    LinMsgData_type msgData;
    uint8           chkSumResult;
}LinMsg_type;

typedef struct{
    LinMsg_type     rxMsg[LIN_RX_MSG_MAX];
    LinMsg_type     txMsg[LIN_TX_MSG_MAX];
}LinBus_type;

extern void linProtocolHandler(uint8 rxData);
extern void linComInit();

/* get and set interface function */
extern uint8 getLedMode();
extern uint8 getLedSwitch();
extern uint8 getLedBrightnessLevel();
extern uint8 getLeftZoneFreeMode();
extern uint8 getCenterZoneFreeMode();
extern uint8 getRightZoneFreeMode();
extern void setLedSwitchFbk(uint8 ledSwth);
extern void setLedModeFbk(uint8 ledMode);
extern void setLedBrightnessLevelFbk(uint8 brightnessLevel);

extern LIN_SLAVE_STATE_INFO     Lin_StateMachine;
extern LinBus_type              LinBus_Obj;
extern uint8 rxDataBytePtr;

#endif
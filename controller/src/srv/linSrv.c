#include "linSrv.h"

LIN_SLAVE_STATE_INFO    Lin_StateMachine;
LinBus_type             LinBus_Obj;

lineReq_type curLinReq;

uint8 rxDataBytePtr = 0;

/*  */
const uint8 linRxMsgIdArr[LIN_RX_MSG_MAX] = {0x17};
const uint8 linTxMsgIdArr[LIN_TX_MSG_MAX] = {0x18};

static void linUpdateChecksum(LIN_TX_MSG_IDX msgObjId)
{
    uint8 chkSumVal = 0;
    uint8 i = 0;
    chkSumVal = 0xD8;
    for(i = 0; i < LIN_MSG_LENGTH ; i++)
    {
        chkSumVal = chkSumVal + LinBus_Obj.txMsg[msgObjId].msgData.dataBuf[i];
    }
    chkSumVal = 255 - chkSumVal;
    LinBus_Obj.txMsg[msgObjId].msgData.dataBuf[8] = chkSumVal;

}

static void linChecksumVerify(LIN_TX_MSG_IDX msgObjId)
{
    uint8 checksumResult = 0;
    uint8 checksumVal = 0;
    uint8 i = 0;

    checksumVal = 0x97;
    for(i = 0; i < LIN_MSG_LENGTH; i++)
    {
        checksumVal = checksumVal + LinBus_Obj.rxMsg[msgObjId].msgData.dataBuf[i];
    }
    checksumVal = 255 - checksumVal;

    if(checksumVal == LinBus_Obj.rxMsg[msgObjId].msgData.dataBuf[8] || (checksumVal == LinBus_Obj.rxMsg[msgObjId].msgData.dataBuf[8] + 1))
    {
        LinBus_Obj.rxMsg[msgObjId].chkSumResult = 1;
    }
    else
    {
        LinBus_Obj.rxMsg[msgObjId].chkSumResult = 0;
    }
    
}

static void linRxDataHandler(uint8 rxData)
{

    if(rxDataBytePtr < LIN_MSG_LENGTH)
    {
        LinBus_Obj.rxMsg[curLinReq.reqMsgIdx].chkSumResult = 0;
        LinBus_Obj.rxMsg[curLinReq.reqMsgIdx].msgData.dataBuf[rxDataBytePtr] = rxData;
        rxDataBytePtr ++;
        if(rxDataBytePtr == LIN_MSG_LENGTH)
        {
            Lin_StateMachine.Lin_CommState = LIN_RX_CHKSUM;
            rxDataBytePtr = 0;
        }
    }
    else
    {

    }
}

uint16 testTBUFdata[10];
uint16 testPSRdata[10];
static void linTxDataHandler()
{
    ;
    #if 0
    static uint8 txDataBytePtr = 0;

    /* TSIEN = 1(transmit shift interrupt enable) */
    // U0C0_CCR |= (1 << 12);

    if(txDataBytePtr < LIN_MSG_TX_LENGTH)
    {
        setTxBuf(LinBus_Obj.txMsg[curLinReq.reqMsgIdx].msgData.dataBuf[txDataBytePtr]);
        testTBUFdata[txDataBytePtr] = U0C0_TBUF07;
        testPSRdata[txDataBytePtr] = U0C0_PSR;
        txDataBytePtr ++;
        if(txDataBytePtr == LIN_MSG_TX_LENGTH)
        {
            Lin_StateMachine.Lin_CommState = LIN_TX_CHKSUM;
            txDataBytePtr = 0;
        }
    }
    else
    {

    }
    #endif
}

static void setMsgIDState(uint8 msgId)
{
    uint8 i = 0;
    /* check if the message id is the rx message */
    for(i = 0; i < LIN_RX_MSG_MAX; i ++)
    {
        if(msgId == LinBus_Obj.rxMsg[i].msgId)
        {
            curLinReq.reqType = linRxReq;
            curLinReq.reqMsgIdx = i;
            Lin_StateMachine.Lin_CommState = LIN_RX_DATA;
            //rxDataBytePtr = 0;
            break;
        }
        else
        {
            /* do nothing */
        }
    }

    /* check if the message id is the tx message */
    for(i = 0; i < LIN_TX_MSG_MAX; i ++)
    {
        if(msgId == LinBus_Obj.txMsg[i].msgId)
        {
            curLinReq.reqType = linTxReq;
            curLinReq.reqMsgIdx = i;
            Lin_StateMachine.Lin_CommState = LIN_TX_DATA;
            /* trigger the first data byte send here
               then it will be triggered by the transmit
               finish interrupt one by one */
            //linTxDataHandler();
            break;
        }
        else
        {
            /* do nothing */
        }
    }
}

static void PIDHandler(uint8 rxData)
{
    uint8 curMsgId = 0;
    /* TODO: do prarity check if needed */

    /* fetch the lowest 6 bits */
    curMsgId = rxData & 0x3F;

    /* check its a Rx message or Tx message and set the
       communication status */
    setMsgIDState(curMsgId);
}

void linComInit()
{
    uint8 i = 0;
    /* message ID assignment */
    for(i = 0; i < LIN_RX_MSG_MAX; i ++)
    {
        LinBus_Obj.rxMsg[i].msgId = linRxMsgIdArr[i];
    }
    for(i = 0; i < LIN_TX_MSG_MAX; i ++)
    {
        LinBus_Obj.txMsg[i].msgId = linTxMsgIdArr[i];
    }
}

void linProtocolHandler(uint8 rxData)
{
    switch (Lin_StateMachine.Lin_CommState)
    {
        case LIN_IDLE:
        {
            /* first byte was 0x00 and next byte should be the message ID */
            // Lin_StateMachine.Lin_CommState = LIN_PID;
        }
            break;

        case LIN_PID:
        {
            PIDHandler(rxData);
        }
            break;

        case LIN_RX_DATA:
        {
            linRxDataHandler(rxData);
        }
            break;

        case LIN_TX_DATA:
        {
            //linTxDataHandler();
        }
            break;

        case LIN_RX_CHKSUM:
        {
            /* get the checksum byte */
            LinBus_Obj.rxMsg[curLinReq.reqMsgIdx].msgData.dataBuf[8] = rxData;

            /* verify the checksum result */
            linChecksumVerify(curLinReq.reqMsgIdx);

            /* set the lin state to idle */
            Lin_StateMachine.Lin_CommState = LIN_IDLE;
        }
            break;

        case LIN_TX_CHKSUM:
        {
            //Lin_StateMachine.Lin_CommState = LIN_IDLE;
        }
            break;   
        default:
            break;
    }
}

uint8 getLedMode()
{
    uint8 newSig = 0;
    static uint8 oldSig = 0;
    static uint8 formalSignal = 0;
    static uint8 cnt = 0;

    /* signal debounce */
    newSig = (uint8)LinBus_Obj.rxMsg[LIN_RX_MSG_HMI_status_light_control].msgData.msg_HMI_status_light_control.HMI_status_light_mode;
    if(newSig == oldSig)
    {
        if(cnt >= 5)
        {
            formalSignal = newSig;
            //oldSig = newSig;
            cnt = 0;
        }
        else
        {
            cnt ++;
        }
    }
    else
    {
        cnt = 0;
    }
    
    oldSig = newSig;

    return formalSignal;
}

uint8 getLedSwitch()
{
    uint8 newSig = 0;
    static uint8 oldSig = 0;
    static uint8 formalSignal = 0;
    static uint8 cnt = 0;

    /* signal debounce */
    newSig = (uint8)LinBus_Obj.rxMsg[LIN_RX_MSG_HMI_status_light_control].msgData.msg_HMI_status_light_control.HMI_status_light_switch;
    if(newSig == oldSig)
    {
        if(cnt >= 5)
        {
            formalSignal = newSig;
            cnt = 0;
        }
        else
        {
            cnt ++;
        }
    }
    else
    {
        cnt = 0;
    }
    
    oldSig = newSig;

    return formalSignal;
}

uint8 getLedBrightnessLevel()
{
    return (uint8)LinBus_Obj.rxMsg[LIN_RX_MSG_HMI_status_light_control].msgData.msg_HMI_status_light_control.HMI_status_lightness;
}

uint8 getLeftZoneFreeMode()
{
    return (uint8)LinBus_Obj.rxMsg[LIN_RX_MSG_HMI_status_light_control].msgData.msg_HMI_status_light_control.FreeMode_LightMatrix_L;
}

uint8 getCenterZoneFreeMode()
{
    return (uint8)LinBus_Obj.rxMsg[LIN_RX_MSG_HMI_status_light_control].msgData.msg_HMI_status_light_control.FreeMode_LightMatrix_T;
}

uint8 getRightZoneFreeMode()
{
    return (uint8)LinBus_Obj.rxMsg[LIN_RX_MSG_HMI_status_light_control].msgData.msg_HMI_status_light_control.FreeMode_LightMatrix_R;
}

void setLedSwitchFbk(uint8 ledSwth)
{
    LinBus_Obj.txMsg[LIN_TX_MSG_HMI_status_light_report].msgData.msg_HMI_status_light_report.HMI_status_light_status = ledSwth;
    linUpdateChecksum(LIN_TX_MSG_HMI_status_light_report);
}

void setLedModeFbk(uint8 ledMode)
{
    LinBus_Obj.txMsg[LIN_TX_MSG_HMI_status_light_report].msgData.msg_HMI_status_light_report.HMI_status_light_mode_report = ledMode;
}

void setLedBrightnessLevelFbk(uint8 brightnessLevel)
{
    LinBus_Obj.txMsg[LIN_TX_MSG_HMI_status_light_report].msgData.msg_HMI_status_light_report.HMI_status_lightness_report = brightnessLevel;
}
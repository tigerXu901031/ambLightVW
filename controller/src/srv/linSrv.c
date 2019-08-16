#include "linSrv.h"

LIN_SLAVE_STATE_INFO    Lin_StateMachine;
LinBus_type             LinBus_Obj;

lineReq_type curLinReq;

/*  */
const uint8 linRxMsgIdArr[LIN_RX_MSG_MAX] = {0x17};
const uint8 linTxMsgIdArr[LIN_TX_MSG_MAX] = {0x18};

static setMsgIDState(uint8 msgId)
{
    uint8 i = 0;
    /* check if the message id is the rx message */
    for(i = 0; i < LIN_RX_MSG_MAX; i ++)
    {
        if(msgId == LinBus_Obj.rxMsg[i].msgId)
        {
            curLinReq.reqType = linRxReq;
            curLinReq.reqMsgIdx = i;
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
            break;
        }
        else
        {
            /* do nothing */
        }
    }
}

static PIDHandler(uint8 rxData)
{
    uint8 curMsgId = 0;
    /* 6bit id, 2bit parity */
    /* do prarity check if needed */

    /* fetch id fomr higher 6 bit */
    curMsgId = rxData >> 2;

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

void linComIsrHandler(uint8 rxData)
{
    switch (Lin_StateMachine.Lin_CommState)
    {
    case LIN_IDLE:
    {
        /* do nothing */
    }
        break;
        
    case LIN_PID:
    {
        PIDHandler(rxData);
    }
        break;

    case LIN_RX_DATA:
    {

    }
        break;

    case LIN_TX_DATA:
    {

    }
        break;

    case LIN_RX_CHKSUM:
    {

    }
        break;
    
    case LIN_TX_CHKSUM:
    {

    }
        break;   
    default:
        break;
    }
}
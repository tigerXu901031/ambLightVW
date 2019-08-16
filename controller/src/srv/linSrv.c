#include "linSrv.h"

LIN_SLAVE_STATE_INFO    Lin_StateMachine;

uint8 curMsgId;

static setMsgIDState(uint8 msgId)
{

}

static PIDHandler(uint8 rxData)
{
    /* 6bit id, 2bit parity */
    /* do prarity check if needed */

    /* fetch id fomr higher 6 bit */
    curMsgId = rxData >> 2;

    /* check its a Rx message or Tx message and set the
       communication status */
    setMsgIDState(curMsgId);

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
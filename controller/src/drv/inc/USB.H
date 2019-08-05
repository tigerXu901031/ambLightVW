// Base Addresses

#define USB_BASE_ADDR	0x00EE00
#define EPEC_BASE_ADDR	0x00ED00

// Local Control Structures

typedef struct {
  unsigned int	CLC;		// 00/01 Clock Control Register
  unsigned int	bpi_1;		// 02/03
  unsigned int	bpi_2;		// 04/05
  unsigned int	bpi_3;		// 06/07
  unsigned int	bpi_4;		// 08/09
  unsigned int	bpi_5;		// 0a/0b
  unsigned int	bpi_6;		// 0c/0d
  unsigned int	bpi_7;		// 0e/0f
  unsigned int	CMD;		// 10/11 Command Register
  unsigned int	STATUS0; 	// 12/13 RX_EMPTY / TX_FULL
  unsigned int	STATUS1;	// 14/15 RX_XFER_ACK / TX_XFER_ACK
  unsigned int	STATUS2;	// 16/17 Remote Wakeup
  unsigned int	reserved[0x06];
  unsigned int	TIME;		// 24/25 11-Bit timestamp of packet
  unsigned int	SETUP01;	// 26/27 Bytes 0+1 of Setup Command
  unsigned int	SETUP23;	// 28/29 Bytes 2+3 of Setup Command
  unsigned int	SETUP45;	// 2a/2b Bytes 4+5 of Setup Command
  unsigned int	SETUP67;  	// 2c/2d Bytes 6+7 of Setup Command
  unsigned int	TX_WR0;		// 2e/2f Transmit FIFO endpoint #0
  unsigned int	TX_EOD0;	// 30/31 Transmit endpoint #0 out of data
  unsigned int	RX_RR0;		// 32/33 Receive FIFO endpoint #0
  unsigned int	RX_BYTECNT0;// 34/35 10 Bit read byte counter endpoint #0
  unsigned int	TX_WR1;		// 36/37 Transmit FIFO endpoint #1
  unsigned int	TX_EOD1;	// 38/39 Transmit endpoint #1 out of data
  unsigned int	RX_RR1;		// 3a/3b Receive FIFO endpoint #1
  unsigned int	RX_BYTECNT1;// 3c/3d 10 Bit read byte counter endpoint #1
  unsigned int	TX_WR2;		// 3e/3f Transmit FIFO endpoint #2
  unsigned int	TX_EOD2;	// 40/41 Transmit endpoint #2 out of data
  unsigned int	RX_RR2;		// 42/43 Receive FIFO endpoint #2
  unsigned int	RX_BYTECNT2;// 44/45 10 Bit read byte counter endpoint #2
  unsigned int	TX_WR3;		// 46/47 Transmit FIFO endpoint #3
  unsigned int	TX_EOD3;	// 48/49 Transmit endpoint #3 out of data
  unsigned int	RX_RR3;		// 4a/4b Receive FIFO endpoint #3
  unsigned int	RX_BYTECNT3;// 4c/4d 10 Bit read byte counter endpoint #3
  unsigned int	TX_WR4;		// 4e/4f Transmit FIFO endpoint #4
  unsigned int	TX_EOD4;	// 50/51 Transmit endpoint #4 out of data
  unsigned int	RX_RR4;		// 52/53 Receive FIFO endpoint #4
  unsigned int	RX_BYTECNT4;// 54/55 10 Bit read byte counter endpoint #4
  unsigned int	TX_WR5;		// 56/57 Transmit FIFO endpoint #5
  unsigned int	TX_EOD5;	// 58/59 Transmit endpoint #5 out of data
  unsigned int	RX_RR5;		// 5a/5b Receive FIFO endpoint #5
  unsigned int	RX_BYTECNT5;// 5c/5d 10 Bit read byte counter endpoint #5
  unsigned int	TX_WR6;		// 5e/5f Transmit FIFO endpoint #6
  unsigned int	TX_EOD6;	// 60/61 Transmit endpoint #6 out of data
  unsigned int	RX_RR6;		// 62/63 Receive FIFO endpoint #6
  unsigned int	RX_BYTECNT6;// 64/65 10 Bit read byte counter endpoint #6
  unsigned int	TX_WR7;		// 66/67 Transmit FIFO endpoint #7
  unsigned int	TX_EOD7;	// 68/69 Transmit endpoint #7 out of data
  unsigned int	RX_RR7;		// 6a/6b Receive FIFO endpoint #7
  unsigned int	RX_BYTECNT7;// 6c/6d 10 Bit read byte counter endpoint #7
  unsigned int	CFGVAL;		// 6e/6f Current Configuration and Alternate Setting selected by host
  unsigned int	CMD_RESET;	// 70/71 Block Reset
} USB_REG_MAP;

typedef struct {
    unsigned int	CLC;		// 00/01 Clock Control Register
    unsigned int	PCC;		// 02/03 Peripheral Clock Control Register
    unsigned int	PPIS;		// 04/05 Peripheral Port Input Select Register
    unsigned int	reserved[0x5];
    unsigned long	SPTR0IN;	// 10/13 endpoint#0 source pointer in
    unsigned long	SPTR0OUT;	// 14/17 endpoint#0 source pointer out
    unsigned long	SPTR1;		// 18/1B endpoint#1 source pointer
    unsigned long	SPTR2;		// 1C/1F endpoint#2 source pointer
    unsigned long	SPTR3;		// 20/23 endpoint#3 source pointer
    unsigned long	SPTR4;		// 24/27 endpoint#4 source pointer
    unsigned long	SPTR5;		// 28/2B endpoint#5 source pointer
    unsigned long	SPTR6;		// 2C/2F endpoint#6 source pointer
    unsigned long	SPTR7;		// 30/33 endpoint#7 source pointer
    unsigned long	DPTR0IN;	// 34/37 endpoint#0 destination pointer in
    unsigned long	DPTR0OUT;	// 38/3B endpoint#0 destination pointer out
    unsigned long	DPTR1;		// 3C/3F endpoint#1 destination pointer
    unsigned long	DPTR2;		// 40/43 endpoint#2 destination pointer
    unsigned long	DPTR3;		// 44/47 endpoint#3 destination pointer
    unsigned long	DPTR4;		// 48/4B endpoint#4 destination pointer
    unsigned long	DPTR5;		// 4C/4F endpoint#5 destination pointer
    unsigned long	DPTR6;		// 50/53 endpoint#6 destination pointer
    unsigned long	DPTR7;		// 54/57 endpoint#7 destination pointer
    unsigned int	CTRL0IN;	// 58/59 Control Register		
    unsigned int	CTRL0OUT;	// 5A/5B Control Register		
    unsigned int	CTRL1;		// 5C/5D Control Register		
    unsigned int	CTRL2;		// 5E/5F Control Register		
    unsigned int	CTRL3;		// 60/61 Control Register		
    unsigned int	CTRL4;		// 62/63 Control Register		
    unsigned int	CTRL5; 		// 64/65 Control Register		
    unsigned int	CTRL6; 		// 66/67 Control Register		
    unsigned int	CTRL7; 		// 68/69 Control Register
    unsigned int	INT;		// 6A/6B Interrupt Register
    unsigned int	INTMSK;		// 6C/6D Interrupt Mask Register		
} EPEC_REG_MAP;


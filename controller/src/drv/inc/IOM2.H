///////////////////////////////////////////////////////////////////////////////
//
//	Basic module configuration
//
///////////////////////////////////////////////////////////////////////////////

#define IOM2_BASE_ADDR		0x00EF00
#define MONITOR_BASE_ADDR	0x00EF50
#define HDLC_BASE_ADDR      0x00EF80

///////////////////////////////////////////////////////////////////////////////
//
//	Local control structures
//
///////////////////////////////////////////////////////////////////////////////

typedef struct {
	unsigned int	IOMCLC;			// IOM-2 Clock Control Register
	unsigned int	reserved1[3];	// Reserved Bits
	unsigned int	IOMID;			// IOM-2 Identification Register
	unsigned int	reserved2[3];	// Reserved Bits
	unsigned int	CDA_10;			// Controller Data Access Register
	unsigned int	CDA_11;			// Controller Data Access Register
	unsigned int	CDA_20;			// Controller Data Access Register
	unsigned int	CDA_21;			// Controller Dara Access Register
	unsigned int	CDA_TSDP10;		// Time Slot and Data Port Selection
	unsigned int	CDA_TSDP11;		// Time Slot and Data Port Selection
	unsigned int	CDA_TSDP20;		// Time Slot and Data Port Selection
	unsigned int	CDA_TSDP21;		// Time Slot and Data Port Selection
	unsigned int	B1_TSDP;		// Time Slot and Data Port Selection for B1
	unsigned int	B2_TSDP;		// Time Slot and Data Port Selection for B2
	unsigned int	D1_TSDP;		// Time Slot and Data Port Selection for D1
	unsigned int	D2_TSDP;		// Time SLot and Data Port Selection for D2
	unsigned int	reserved3[4];	// Reserved Bits
	unsigned int	ISTA;			// Interrupt Status Register
	unsigned int	MASK;			// Interrupt Mask Register
	unsigned int	CDA1_CR;		// Control Register for Controller Data Access
	unsigned int	CDA2_CR;		// Control Register for Controller Data Access
	unsigned int	CIC_CR;			// Control Register for Command/Indication Channel
	unsigned int	MON_CR;			// Control Register for Monitor Channel
	unsigned int	IOM_CR;			// Control Register for IOM Interface
	unsigned int	reserved4;		// Reserved Bits
	unsigned int	STI;			// Synchronous Transfer Interrupt
	unsigned int	MSTI;			// Mask Synchronous Transfer Interrupt
	unsigned int	ASTI;			// Acknowledge Synchronous Transfer Interrupt
	unsigned int	reserved5[5];	// Reserved Bits
	unsigned int	MOR;			// Monitor Recieve Channel
	unsigned int	MOX;			// Monitor Transmit Channel
	unsigned int	MOCR;			// Monitor Control Register
	unsigned int	MSTA;			// Monitor Status Register
	unsigned int	MOSR;			// Monitor Interrupt Status Register
	unsigned int	MCDA;			// Monitoring CDA Bits
	unsigned int	reserved6[2];	// Reserved Bits
	unsigned int	CIC0_D;			// Command/Indication Channel 0 Data
	unsigned int	CIC1_D;			// Command/Indication Channel 1 Data
	unsigned int	CIC_CMD;		// Command/Indication Channel Command Register
	unsigned int	CIC_ST;			// Command/Indication Channel Status Register
	unsigned int	DCSI;			// DCL Clock Supervision Interval
	unsigned int	reserved7[11];	// Reserved Bits
	unsigned int	RFIFO_0;		// Receive FIFO 
	unsigned int	TFIFO_0;		// Transmit FIFO
	unsigned int	ISTAH_0;		// Interrupt Status Register
	unsigned int	MASKH_0;		// Interrupt Mask Registet´r
	unsigned int	STAR_0;			// Status Register
	unsigned int	CMDR_0;			// Command Register
	unsigned int	IOMSEL_CR_0;	// Control Register for IOM-2 Channel Selection
	unsigned int	MODEH_0;		// Mode Register
	unsigned int	SAP1_0;			// SAPI1 Register
	unsigned int	SAP2_0;			// SAPI2 Register
	unsigned int	RBC_0;			// Receive Frame Byte Count
	unsigned int	TEI1_0;			// TEI1 Register
	unsigned int	TEI2_0;			// TEI2 Register
	unsigned int	LOOPH_0;		// Looping Register
	unsigned int	reserved8[2];	// Reserved Bits
	unsigned int	RFIFO_1;		// Receive FIFO 
	unsigned int	TFIFO_1;		// Transmit FIFO
	unsigned int	ISTAH_1;		// Interrupt Status Register
	unsigned int	MASKH_1;		// Interrupt Mask Registet´r
	unsigned int	STAR_1;			// Status Register
	unsigned int	CMDR_1;			// Command Register
	unsigned int	IOMSEL_CR_1;	// Control Register for IOM-2 Channel Selection
	unsigned int	MODEH_1;		// Mode Register
	unsigned int	SAP1_1;			// SAPI1 Register
	unsigned int	SAP2_1;			// SAPI2 Register
	unsigned int	RBC_1;			// Receive Frame Byte Count
	unsigned int	TEI1_1;			// TEI1 Register
	unsigned int	TEI2_1;			// TEI2 Register
	unsigned int	LOOPH_1;		// Looping Register
	unsigned int	reserved9[2];	// Reserved Bits
	unsigned int	RFIFO_2;		// Receive FIFO 
	unsigned int	TFIFO_2;		// Transmit FIFO
	unsigned int	ISTAH_2;		// Interrupt Status Register
	unsigned int	MASKH_2;		// Interrupt Mask Registet´r
	unsigned int	STAR_2;			// Status Register
	unsigned int	CMDR_2;			// Command Register
	unsigned int	IOMSEL_CR_2;	// Control Register for IOM-2 Channel Selection
	unsigned int	MODEH_2;		// Mode Register
	unsigned int	SAP1_2;			// SAPI1 Register
	unsigned int	SAP2_2;			// SAPI2 Register
	unsigned int	RBC_2;			// Receive Frame Byte Count
	unsigned int	TEI1_2;			// TEI1 Register
	unsigned int	TEI2_2;			// TEI2 Register
	unsigned int	LOOPH_2;		// Looping Register
	unsigned int	reserved10[2];	// Reserved Bits
	unsigned int	RFIFO_3;		// Receive FIFO 
	unsigned int	TFIFO_3;		// Transmit FIFO
	unsigned int	ISTAH_3;		// Interrupt Status Register
	unsigned int	MASKH_3;		// Interrupt Mask Registet´r
	unsigned int	STAR_3;			// Status Register
	unsigned int	CMDR_3;			// Command Register
	unsigned int	IOMSEL_CR_3;	// Control Register for IOM-2 Channel Selection
	unsigned int	MODEH_3;		// Mode Register
	unsigned int	SAP1_3;			// SAPI1 Register
	unsigned int	SAP2_3;			// SAPI2 Register
	unsigned int	RBC_3;			// Receive Frame Byte Count
	unsigned int	TEI1_3;			// TEI1 Register
	unsigned int	TEI2_3;			// TEI2 Register
	unsigned int	LOOPH_3;		// Looping Register
} IOM2_REG_MAP;

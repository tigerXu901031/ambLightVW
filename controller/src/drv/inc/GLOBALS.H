// Configurations
//---------------------------------------------------------
#define XBUSADRS1			0x0EF0
#define XBUSCON1			0x04AF
#define XBUSADRS2			0x0EE0            
#define XBUSCON2	     	0x04AF
#define XBUSADRS3			0x0ED0            
#define XBUSCON3	     	0x04AF
#define XXBUSADRS2 			0x00E0
#define XXBUSCON2			0x04BE

// Base Addresses
//---------------------------------------------------------
#define C161PEC_POINTER_BASE_ADR	0x00FCE0
#define SFR_BASE_ADDR				0x00FE00
#define ESFR_BASE_ADDR				0x00F000

// Register-Mapping
//---------------------------------------------------------

typedef struct {
    unsigned int	DPP0;			// 00/01
    unsigned int	DPP1;			// 02/03
    unsigned int	DPP2;			// 04/05
    unsigned int	DPP3;			// 06/07
    unsigned int	CSP;			// 08/09
    unsigned int	EMUCON;			// 0A/0B
    unsigned int	MDH;			// 0C/0D
    unsigned int	MDL;			// 0E/0F
    unsigned int	CP;				// 10/11
    unsigned int	SP;				// 12/13
    unsigned int	STKOV;			// 14/15
    unsigned int	STKUN;			// 16/17
    unsigned int	ADDRSEL1;		// 18/19
    unsigned int 	ADDRSEL2;		// 1A/1B
    unsigned int	ADDRSEL3;		// 1C/1D
    unsigned int	ADDRSEL4;		// 1E/1F
    unsigned int	reserved1;
    unsigned int	ODP0H;			// 22/23
    unsigned int	ODP1L;			// 24/25
    unsigned int	ODP1H;			// 26/27
    unsigned int	reserved2[0xC];
    unsigned int	T2;             // 40/41
    unsigned int	T3;             // 42/43
    unsigned int	T4;             // 44/45
    unsigned int	T5;             // 46/47
    unsigned int	T6;             // 48/49
    unsigned int	CAPREL;		    // 4A/4B
    unsigned int	GPTCLC;			// 4C/4D
    unsigned int	reserved3[0x9];
    unsigned int	P0LPUDSEL;   	// 60/61
    unsigned int	P0HPUDSEL;   	// 62/63
    unsigned int	P0LPUDEN;   	// 64/65
    unsigned int	P0HPUDEN;   	// 66/67
    unsigned int	P0LPHEN;   		// 68/69
    unsigned int	P0HPHEN;   		// 6A/6B
    unsigned int	P1LPUDSEL;   	// 6C/6D
    unsigned int	P1HPUDSEL;   	// 6E/6F
    unsigned int	P1LPUDEN;   	// 70/71
    unsigned int	P1HPUDEN;   	// 71/73
    unsigned int	P1LPHEN;   		// 74/75
    unsigned int	P1HPHEN;   		// 76/77
    unsigned int	P2PUDSEL;   	// 78/79
    unsigned int	P2PUDEN;   		// 7A/7B
    unsigned int	P2PHEN;   		// 7C/7D
    unsigned int	P3PUDSEL;   	// 7E/7F
    unsigned int	P3PUDEN;   		// 80/81
    unsigned int	P3PHEN;   		// 82/83
    unsigned int	P4PUDSEL;   	// 84/85
    unsigned int	P4PUDEN;   		// 86/87
    unsigned int	P4PHEN;   		// 88/89
    unsigned int	reserved4[0x3];
    unsigned int	P6PUDSEL;   	// 90/91
    unsigned int	P6PUDEN;   		// 92/93
    unsigned int	P6PHEN;   		// 94/95
    unsigned int	P7PUDSEL;   	// 96/97
    unsigned int	P7PUDEN;   		// 98/99
    unsigned int	P7PHEN;   		// 9A/9B
    unsigned int	reserved5[0x7];
    unsigned int	S0PMW;   		// AA/AB
    unsigned int	reserved6;
    unsigned int	WDT;	   		// AE/AF
    unsigned int	S0TBUF;			// B0/B1	
    unsigned int	S0RBUF;			// B2/B3	
    unsigned int	S0BG;			// B4/B5	
    unsigned int	S0FDV;			// B6/B7	
    unsigned int	reserved7[0x4];
    unsigned int	PECC0;			// C0/C1
    unsigned int	PECC1;			// C2/C3
    unsigned int	PECC2;			// C4/C5
    unsigned int	PECC3;			// C6/C7
    unsigned int	PECC4;			// C8/C9
    unsigned int	PECC5;			// CA/CB
    unsigned int	PECC6;			// CC/CD
    unsigned int	PECC7;			// CE/CF
    unsigned int	PECSN0;			// D0/D1	
    unsigned int	PECSN1;			// D2/D3	
    unsigned int	PECSN2;			// D4/D5	
    unsigned int	PECSN3;			// D6/D7	
    unsigned int	PECSN4;			// D8/D9	
    unsigned int	PECSN5;			// DA/DB	
    unsigned int	PECSN6;			// DC/DD	
    unsigned int	PECSN7;			// DE/DF
    unsigned int	reserved8[0x8];	
    unsigned int	PECXC0;			// F0/F1	
    unsigned int	PECXC1;			// F2/F3
    unsigned int	reserved9[0x2];	
    unsigned int	ABS0CON;		// F8/F9	
    unsigned int	reserved10[0x2];
    unsigned int	ABSTATUS;		// FE/FF
    unsigned int	P0L;			// 100/101	
    unsigned int	P0H;			// 102/103	
    unsigned int	P1L;			// 104/105	
    unsigned int	P1H;			// 106/107
    unsigned int	reserved11[0x2];
    unsigned int	BUSCON0;		// 10C/10D
    unsigned int	MDC;			// 10E/10F
    unsigned int	PSW;			// 110/111	
    unsigned int 	SYSCON;			// 112/113
    unsigned int	BUSCON1;		// 114/115
    unsigned int	BUSCON2;		// 116/117
    unsigned int	BUSCON3;		// 118/119
    unsigned int	BUSCON4;		// 11A/11B
    unsigned int	ZEROS;			// 11C/11D	
    unsigned int	ONES;			// 11E/11F	
    unsigned int	reserved12[0x10];
    unsigned int	T2CON;			// 140/141
    unsigned int	T3CON;			// 142/143
    unsigned int	T4CON;			// 144/145
    unsigned int	T5CON;			// 146/147
    unsigned int	T6CON;			// 148/149
    unsigned int	reserved13[0x0B];
    unsigned int	T2IC;			// 160/161
    unsigned int	T3IC;			// 162/163
    unsigned int	T4IC;			// 164/165
    unsigned int	T5IC;			// 166/167
    unsigned int	T6IC;			// 168/169
    unsigned int	CRIC;			// 16A/16B
    unsigned int	S0TIC;			// 16C/16D
    unsigned int	S0RIC;			// 16E/16F
    unsigned int	S0EIC;			// 170/171
    unsigned int	SSCTIC;			// 172/173	
    unsigned int	SSCRIC;			// 174/175	
    unsigned int	SSCEIC;			// 176/177
    unsigned int	URD3IC;			// 178/179	
    unsigned int	URD4IC;			// 17A/17B	
    unsigned int	URD5IC;			// 17C/17D	
    unsigned int	URD6IC;			// 17E/17F	
    unsigned int	URD7IC;			// 180/181	
    unsigned int	UTD0IC;			// 182/183	
    unsigned int	UTD1IC;			// 184/185	
    unsigned int	UTD2IC;			// 186/187	
    unsigned int	FEI0IC;			// 188/189
    unsigned int	FEI1IC;			// 18A/18B
    unsigned int	FEI2IC;			// 18C/18D
    unsigned int	FEI3IC;			// 18E/18F
    unsigned int	FEI4IC;			// 190/191
    unsigned int	FEI5IC;			// 192/193
    unsigned int	FEI6IC;			// 194/195
    unsigned int	FEI7IC;			// 196/197
    unsigned int	RES4IC;			// 198/199
    unsigned int	IOMIOIC;		// 19A/19B
    unsigned int	URD2IC;			// 19C/19D
    unsigned int	URD1IC;			// 19E/19F
    unsigned int	reserved14[0x04];
    unsigned int	CLISNC;			// 1A8/1A9
    unsigned int	FOCON;			// 1AA/1AB
    unsigned int	TFR;			// 1AC/1AD
    unsigned int	WDTCON;			// 1AE/1AF
    unsigned int	S0CON;			// 1B0/1B1
    unsigned int	SSCCON;			// 1B2/1B3
    unsigned int	reserved15[0x3];
    unsigned int	S0CLC;			// 1BA/1BB
    unsigned int	reserved16[0x2];
    unsigned int	P2;				// 1C0/1C1
    unsigned int	DP2;			// 1C2/1C3
    unsigned int	P3;				// 1C4/1C5
    unsigned int	DP3;			// 1C6/1C7
    unsigned int	P4;				// 1C8/1C9
    unsigned int	DP4;			// 1CA/1CB
    unsigned int	P6;				// 1CC/1CD
    unsigned int	DP6;			// 1CE/1CF
    unsigned int	P7;				// 1D0/1D1
    unsigned int	DP7;			// 1D2/1D3
} SFR_REG_MAP;

typedef struct {
    unsigned int 	reserved1[0x06];
    unsigned int	CPUID;			// 0C/0D
    unsigned int	reserved2[0x3];
    unsigned int	XADRS1;			// 14/15
    unsigned int	XADRS2;			// 16/17
    unsigned int	XADRS3;			// 18/19
    unsigned int	XADRS4;			// 1A/1B
    unsigned int	XADRS5;			// 1C/1D
    unsigned int	XADRS6;			// 1E/1F
    unsigned int	reserved3[0x7A];// !!!!!!!
    unsigned int	XBCON1;			// 114/115
    unsigned int	XBCON2;			// 116/117
    unsigned int	XBCON3;			// 118/119
    unsigned int	XBCON4;			// 11A/11B
    unsigned int	XBCON5;			// 11C/11D
    unsigned int	XBCON6;			// 11E/11F
    unsigned int	reserved4[0x20];
    unsigned int	UTD3IC;			// 160/161
    unsigned int	UTD4IC;			// 162/163
    unsigned int	UTD5IC;			// 164/165
    unsigned int	UTD6IC;			// 166/167
    unsigned int	UTD7IC;			// 168/169
    unsigned int	URXRIC;			// 16A/16B
    unsigned int	UTXRIC;			// 16C/16D
    unsigned int	UCFGVIC;		// 16E/16F
    unsigned int	USOFIC;			// 170/171
    unsigned int	USSOIC;			// 172/173
    unsigned int	USSIC;			// 174/175
    unsigned int	ULCDIC;			// 176/177
    unsigned int	USETIC;			// 178/179
    unsigned int	URD0IC;			// 17A/17B
    unsigned int	EPECIC;			// 17C/17D
    unsigned int	IOMC0TIC;		// 17E/17F
    unsigned int	PECCLIC;		// 180/181
    unsigned int	IOMC0RIC;		// 182/183
    unsigned int	reserved5;
    unsigned int	XP0IC;			// 186/187
    unsigned int 	reserved6;
    unsigned int	IOMC1TIC;		// 18A/18B	
    unsigned int	ABENDIC;		// 18C/18D
    unsigned int	XP1IC;			// 18E/18F
    unsigned int	reserved7;
    unsigned int	IOMC1RIC;		// 192/193
    unsigned int	ABSTIC;			// 194/195
    unsigned int	XP2IC;			// 196/197			
    unsigned int	reserved8[0x02];
    unsigned int	S0TBIC;			// 19C/19D
    unsigned int	XP3IC;			// 19E/19F
    unsigned int	reserved9[0x11];
    unsigned int	EXICON;			// 1C0/1C1 !!!!!!
} ESFR_REG_MAP;

#ifndef SRCP0
typedef struct {
    unsigned int      SRCP0;     // C161 PEC 0 Source Pointer
    unsigned int      DSTP0;     // C161 PEC 0 Destination Pointer
    unsigned int      SRCP1;     // C161 PEC 1 Source Pointer
    unsigned int      DSTP1;     // C161 PEC 1 Destination Pointer
    unsigned int      SRCP2;     // C161 PEC 2 Source Pointer
    unsigned int      DSTP2;     // C161 PEC 2 Destination Pointer
    unsigned int      SRCP3;     // C161 PEC 3 Source Pointer
    unsigned int      DSTP3;     // C161 PEC 3 Destination Pointer
    unsigned int      SRCP4;     // C161 PEC 4 Source Pointer
    unsigned int      DSTP4;     // C161 PEC 4 Destination Pointer
    unsigned int      SRCP5;     // C161 PEC 5 Source Pointer
    unsigned int      DSTP5;     // C161 PEC 5 Destination Pointer
    unsigned int      SRCP6;     // C161 PEC 6 Source Pointer
    unsigned int      DSTP6;     // C161 PEC 6 Destination Pointer
    unsigned int      SRCP7;     // C161 PEC 7 Source Pointer
    unsigned int      DSTP7;     // C161 PEC 7 Destination Pointer
} C161_PEC_POINTER;
#endif

/****************************************************************************
**        File        :  LIN_CFG.h
**        Controller  :  Infineon XC2224L
**        LIN Version :  2.1
**        Description :  LIN Configuration File for the defined LIN cluster
*****************************************************************************/

#ifndef LIN_CFG_H
#define LIN_CFG_H

/*@doc API*/

/* @Topic LIN driver configuration parameters */

/*
*     @def LIN_V_2_1/0 |
*     This defines LIN specification version
*/
#define LIN_V_2_1

/*
*     @def USIC_UxCy_CHANNEL |
*     The following defines are used to select the USIC channel
*     required to be used as LIN channel.
*     'x': Range < 0 to 3 > - USIC module
*     'y': Range < 0 to 1 > - Channel of the USIC module
*/
#define USIC_U0C0_CHANNEL    (0U)   /* USIC 0 Channel 0 */
#define USIC_U0C1_CHANNEL    (1U)   /* USIC 0 Channel 1 */
#define USIC_U1C0_CHANNEL    (2U)   /* USIC 1 Channel 0 */
#define USIC_U1C1_CHANNEL    (3U)   /* USIC 1 Channel 1 */

/*
*     @def LIN_CFG_CHANNEL_ID |
*     This define can be configured to select the USIC channel
*     required to be used as LIN channel.
*     Range - USIC_UxCy_CHANNEL (defined above)
*/
#define LIN_CFG_CHANNEL_ID       (USIC_U1C0_CHANNEL)

/*
*     @def PORT_x, PIN_y |
*     These defines must be used to configure LIN_PORT_IN, LIN_PORT_OUT,
*     LIN_PIN_IN, LIN_PIN_OUT for selection of appropriate port pins for
*     input as well as outputs.
*/
#define PORT_0           0
#define PORT_1           1
#define PORT_2           2
#define PORT_3           3
#define PORT_4           4
#define PORT_5           5
#define PORT_6           6
#define PORT_7           7
#define PORT_8           8
#define PORT_9           9
#define PORT_10          10
#define PORT_11          11

#define PIN_0            0
#define PIN_1            1
#define PIN_2            2
#define PIN_3            3
#define PIN_4            4
#define PIN_5            5
#define PIN_6            6
#define PIN_7            7
#define PIN_8            8
#define PIN_9            9
#define PIN_10           10
#define PIN_11           11
#define PIN_12           12
#define PIN_13           13
#define PIN_14           14
#define PIN_15           15

/*
*     @def LIN_PORT_IN, LIN_PIN_IN, LIN_PORT_OUT, LIN_PIN_OUT |
*     These defines can be configured to select the Port and pin
*     required to be used for input and output respectively for
*     the LIN channel.
*     Range - Above USIC - Port pin matrix can be used to select 
*     the appropriate port pin. The defines PORT_x, PIN_y must
*     be used which are defined above.
*/
#define LIN_PORT_IN                           PORT_2
#define LIN_PORT_OUT                          PORT_10
#define LIN_PIN_IN                            PIN_7
#define LIN_PIN_OUT                           PIN_10

#define GPT_T2                                (0U)
#define GPT_T6                                (1U)

/*
*     @def _IFC_SCND_TMR_NUM |
*     Master/Slave may use any of the available timer T2/T6
*     to schedule the frame IDs as defined in scheduler table.
*     GPT_T2 --> Timer T2;  GPT_T6 --> Timer T6
*     
*/
#define _IFC_SCND_TMR_NUM                     GPT_T2

/*
*     @def USIC_REQ0_ILVL_PRIO |
*     USIC Transmit shift INT interrupt priority level ranges from 0 to 15.
*     Priority increases with the numerical value of ILVL.
*/
#define USIC_REQ0_ILVL_PRIO                   12

/*
*     @def USIC_REQ1_ILVL_PRIO |
*     USIC Protocol INT interrupt priority level ranges from 0 to 15.
*     Priority increases with the numerical value of ILVL.
*/
#define USIC_REQ1_ILVL_PRIO                   11

/*
*     @def GPT_REQ_ILVL_PRIO |
*     Timer INT interrupt priority level ranges from 0 to 15.
*     Priority increases with the numerical value of ILVL.
*/
#define GPT_REQ_ILVL_PRIO                     13

/*
*     @def _IFC_MASTER/SLAVE |
*     The following defines are used to select the mode of interface.
*     [Master/Slave] Only one definition shall be selected.
*     Use the following defines to select the interface mode
*     #define _IFC_MASTER --> Interface is master
*     #define _IFC_SLAVE  --> Interface is slave
*     Note:
*     Interface can either be master or slave but not both.
*/
#define _IFC_SLAVE /* Interface is Slave*/

/*
*     @def _EVNT_SPRDC_FRM_SPRT |
*     This define enables the support for event triggered and sporadic frames. Basic
*     slave would not provide this functionality. If this feature is disabled
*     supporting APIs may not be available in LLD header and c source files.
*/
#define _EVNT_SPRDC_FRM_SPRT                  1

/*
*     @def _WKUP_SLP_SPRT |
*     This define enables the support for sleep, wakeup signals and requests.
*     Basic slave would not provide this functionality. If this feature is disabled,
*     supporting APIs may not be available in LLD header and c source files and
*     corresponding optional timer will not be used by LLD in slave.
*/
#define _WKUP_SLP_SPRT                        1

/*
*     @def _SIG_RDWR_FUNC_SPRT |
*     This definition enables the functionality of reading and writing of signal
*     information from/to the frame data buffer (e.g. l_bool_rd, l_bool_wr,
*     uint8_rd and uint8_wr etc ..). This functionality automatically gets enabled
*     incase _FEATURES functionality is enabled.
*/
#define _SIG_RDWR_FUNC_SPRT                   1

/*
*     @def _DGNSTC_FRM_SPRT |
*     This definition enables the functionality of publishing and subscription to
*     master request and slave response frames. If this feature is disabled
*     supporting APIs may not be available in LLD header and c source files.
*/
#define _DGNSTC_FRM_SPRT                      1

/*
*     @def _DGNSTC_ASGN_FRM_SPRT |
*     This definition enables the functionality of changing the current frame id to
*     the requested frame ID based on message ID. The request is made by application.
*     This feature increases data size, changing the constant definitions to normal data.
*     Note:
*     This is effective only when _DGNSTC_FRM_SPRT or _FEATURES.
*/
#define _DGNSTC_ASGN_FRM_SPRT                 1

/*
*     @def _FEATURES |
*     This enables the slave/master with full functionality supporting all features
*     of LIN v2.1/v2.0 protocol specification. The individual feature disabling wouldn't
*     effect the specific functional support by the LLD, means this option have higher
*     priority than individual configuration option.
*/
#define _FEATURES                             1

/*
*      @def PRPL_FREQ |
*      This defines the peripheral frequency, this value is used to derive
*      the baud rate values for USIC and input frequency for timers.
*/
#define PRPL_FREQ                           32000000//40000000//  

/*
*     @def _TMR_BASE |
*     This is used as a base to reduce the number of timer overflow per time base value
*     _SCHD_TIME_BASE defined in LDF file. It is closely dependent on timer module
*     frequency. It is divisible multiple integral of this value equal to time base
*     defined in LDF file. e.g. _SCHD_TIME_BASE = 1 *  _TMR_BASE
*     Range: 0.075us to 4.9ms (system freq --> 80MHz)
*     Note: Configure this value to the integral value without decimal points
*     then  LIN_frm_base[x].frm_data API shall not used by LLD.
*/
#define _TMR_BASE                             1


/*
*     @def _PDIV_VAL |
*     PDIV is the P divider value for deriving the system frequency.
*/
#define _PDIV_VAL                             207

/*
*     @def _DGNSTC_TBUFF_SZ |
*     This is an array of diagnostic transmit buffers. Each buffer occupies 8 bytes
*     of data. The application writes the desired diagnostic transmit data to
*     these buffers and the LLD transmits the data.
*     
*     Note: This configuration is effective only when the diagnostic/full driver
*           support is enabled.
*/
#define _DGNSTC_TBUFF_SZ                      1

/*
*     @def _DGNSTC_RBUFF_SZ |
*     This is an array of diagnostic receive buffers. Each buffer occupies 8 bytes
*     of data. The application reads the diagnostic received data from these
*     buffers and the LLD stores the received diagnostic data in these buffers.
*     
*     Note: This configuration is effective only when the diagnostic/full driver
*           support is enabled.
*/
#define _DGNSTC_RBUFF_SZ                      1

/*
*      @def _DUMMY_DATA_VAL |
*      This value will be used by publisher to respond to master header incase
*      for the particular frame no updated data available in frame data buffer.
*      Range 0x00 to 0xFF.
*/
#define _DUMMY_DATA_VAL                       0

/*
*     @def     _IFC_NAD |
*     Interface Node Diagnostic Address value ranges from 1 to 126.
*/
#define _IFC_NAD                              1  /*Value in one byte*/

/*
*     @def _IFCx[0-1]_RESP_ERR_FRM_NUM |
*     This is used to set a response error bit in the corresponding frame.
*     LLD will set the response error bit in case of an unsuccessful
*     transmit/receive of frame data, and accordingly the information
*     update flag also will be set.
*     
*     Note: Macro value of -1 indicates that the corresponding interface
*           has not set the response frame error bit.
*/
#define _IFC_RESP_ERR_FRM_NUM                 13

/*
*     @def _IFC0_RESP_ERR_FRM_BIT_LOC |
*     This represents the bit location in the response error frame.
*     LLD will set this bit on an unsuccessful transmittal or
*     receival of frame data. This information is used by the master
*     interface for diagnostic purposes.
*/
#define _IFC_RESP_ERR_FRM_BIT_LOC             63

/*
*     @def     _SUPPLIER_ID |
*     This is the controller supplier ID and is used in diagnostic information.
*/
#define _SUPPLIER_ID                          0x0042

/*
*     @def     _FUNCTION_ID |
*     This is the controller function ID and is used in diagnostic information.
*/
#define _FUNCTION_ID                          0x000C

/*
*     @def     _VARIANT_ID |
*     This is the controller variant ID and is used in diagnostic information.
*/
#define _VARIANT_ID                           0x01

/*
*     @def     _SIGNAL_PROTOTYPE |
*     This defines the signal prototype. Signal prototype can be either Static or Dynamic.
*     0 --> Static; 1 --> Dynamic
*/
#define _SIGNAL_PROTOTYPE                     0

/*
*     @def     _TP_BUFF_MGMT |
*     This defines the Transport Protocol Management feature.
*     0 - Application provides the buffer and its  responsibility of application to
*     maintain  the buffer.
*     1 - Driver defines the buffer and the buffer size is configured by macro
*     _TP_BUFF_SIZE.
*/
#define _TP_BUFF_MGMT                         1
#define _TP_BUFF_SIZE                         4096


#endif  /* #ifndef LIN_CFG_H */

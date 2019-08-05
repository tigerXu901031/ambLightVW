/*--------------------------------------------------------------------------
RTX166T.H

Prototypes for RTX166 Tiny Real-Time Operating System
for C166/EC++ Version 5.
Copyright (c) 1992-2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __RTX166T_H__
#define __RTX166T_H__

/* constants for os_wait function */
#define K_SIG      1                 /* Wait for Signal   */
#define K_TMO      2                 /* Wait for Timeout  */
#define K_IVL      128               /* Wait for Interval */

/* function return values */
#define NOT_OK     255               /* Parameter Error */
#define TMO_EVENT  8                 /* Timeout Event */
#define SIG_EVENT  4                 /* Signal  Event */

// define EC++ compatible keywords
#ifndef __cplusplus             // C166
  #define __task      _task_
  #define __priority  _priority_
  #define __using     _using_
#endif

#ifdef __cplusplus               // EC++
extern "C"  {
#endif

extern int   os_create_task  (int tasd_id);
extern int   os_delete_task  (int tasd_id);
extern int   os_delay_task   (unsigned int timeout);
extern int   os_wait         (int typ, unsigned int timeout, int dummy);
extern int   os_clear_signal (int task_id);

extern int   os_send_signal  (int task_id);
extern int   isr_send_signal (int task_id);
extern int   os_wait_signal  (void);
extern int   os_running_task_id (void);
extern void  os_reset_interval  (unsigned int ticks);
extern void  os_start        (void);

#ifdef __cplusplus               // EC++
}
#endif

#endif

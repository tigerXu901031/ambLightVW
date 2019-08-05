/*--------------------------------------------------------------------------
MEMBOX.H

Fixed Memory Pool Management functions
for C166/EC++ Version 5.01
Copyright (c) 1992 - 2004 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __MEMBOX_H__
#define __MEMBOX_H__

#ifndef NULL
 #ifdef __cplusplus              // EC++
   #define NULL   0
 #else
   #define NULL ((void *) 0)
 #endif
#endif

#ifdef __cplusplus               // EC++
extern "C"  {
#endif

#ifndef _SIZE_T
 #define _SIZE_T
 typedef unsigned int size_t;
#endif

/* Parameters: 
 *   box_mem  := start address of memory that should be split into blocks. 
 *   box_size := size of the memory that should be maintained.
 *   box_size := size of a single memory block that should be maintained.
 */

/*------- near memory box management functions --------*/

extern int        _init_boxn   (void near *box_mem, 
                                unsigned int box_mem_size,
                                unsigned int box_size);

extern void near *_alloc_boxn  (void near *box_mem);

extern void near *_calloc_boxn (void near *box_mem);

extern int        _free_boxn   (void near *box_mem, 
                                void near *box);


#if (__MODEL__ != 0)          /* if not tiny model */

/*-------- far memory box management functions --------*/

extern int        _init_boxf   (void far *box_mem, 
                                unsigned int box_mem_size,
                                unsigned int box_size);

extern void far  *_alloc_boxf  (void far *box_mem);

extern void far  *_calloc_boxf (void far *box_mem);

extern int        _free_boxf   (void far *box_mem, 
                                void far *box);


/*------- huge memory box management functions --------*/

extern int        _init_boxh   (void huge *box_mem, 
                                unsigned int box_mem_size,
                                unsigned int box_size);

extern void huge *_alloc_boxh  (void huge *box_mem);

extern void huge *_calloc_boxh (void huge *box_mem);

extern int        _free_boxh   (void huge *box_mem, 
                                void huge *box);


#endif                           // not TINY model

/*---- generic memory model independant prototypes ----*/
 
// for: TINY, SMALL, MEDIUM
#if (__MODEL__ == 0 || __MODEL__ == 1 || __MODEL__ == 3)
  #define _init_box    _init_boxn
  #define _alloc_box   _alloc_boxn
  #define _free_box    _free_boxn
  #define _calloc_box  _calloc_boxn
#endif
 
// for: COMPACT, LARGE
#if (__MODEL__ == 2 || __MODEL__ == 4)
  #define _init_box    _init_boxf
  #define _alloc_box   _alloc_boxf
  #define _free_box    _free_boxf
  #define _calloc_box  _calloc_boxf
#endif
 
// for: HCOMPACT, HLARGE, XLARGE
#if (__MODEL__ == 5 || __MODEL__ == 6 || __MODEL__ == 7)
  #define _init_box    _init_boxh
  #define _alloc_box   _alloc_boxh
  #define _free_box    _free_boxh
  #define _calloc_box  _calloc_boxh
#endif
 

#ifdef __cplusplus               // EC++
}
#endif

#endif

/***********************************************************************/
/*  calloc_b.c                                                         */
/*  Special Version of 'calloc' for block based xhuge buffers          */
/*  Copyright KEIL ELEKTRONIK GmbH 1995 - 2004                         */
/***********************************************************************/

#include <string.h>
#include <stdlib.h>

#if (__MODEL__ == 5 || __MODEL__ == 6 || __MODEL__ == 7)
  #define MTYP_B  huge   // for HCOMPACT and HLARGE
#else
  #define MTYP_B  far    // for other models
#endif

void MTYP_B *calloc_b (unsigned int size, unsigned int len)  {
  void MTYP_B *p;

  size *= len;
  p = malloc_b (size);
  if (p) memset (p, 0, size);
  return (p);
}


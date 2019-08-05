/***********************************************************************/
/*  realloc_b.c                                                        */
/*  Special Version of 'realloc' for block based xhuge buffers         */
/*  Copyright KEIL ELEKTRONIK GmbH 1995 - 2004                         */
/***********************************************************************/

#include <string.h>
#include <stdlib.h>

#if (__MODEL__ == 5 || __MODEL__ == 6 || __MODEL__ == 7)
  #define MTYP_B  huge   // for HCOMPACT and HLARGE
#else
  #define MTYP_B  far    // for other models
#endif

struct __mp_b__  {                      /* memory pool */
  struct __mp_b__ MTYP_B  *next;        /* single-linked list */
  unsigned int              len;        /* length of following block */
};

extern void MTYP_B * MTYP_B __mp_b__;   /* Memory Pool Header */
#define	HLEN	(sizeof(struct __mp_b__))

/*  Memory pool header:  __mp__ points to the first available.
 *
 *  Note that the list is maintained in address order.  __mp__ points to the
 *  block with the lowest address.  That block points to the block with the
 *  next higher address and so on.                                          */

#define MIN_BLOCK	(HLEN * 4)

void MTYP_B *realloc_b (void MTYP_B *oldp, unsigned int size)  {
#define p   ((struct __mp_b__ MTYP_B *) oldp)   
#define p0  ((struct __mp_b__ MTYP_B *)&p[-1]) /* block to realloc */
  void MTYP_B *newp;

/*  Make sure that block is word aligned                                    */
  size = (size + 1) & ~1L;
  newp = malloc_b (size);
  if (!newp) return (NULL);
  if (oldp)  {
    if (size > p0->len)  size = p0->len;
#if (__MODEL__ == 1 || __MODEL__ == 3)   // SMALL and MEDIUM
    fmemcpy (newp, oldp, size);
#else
    memcpy (newp, oldp, size);
#endif
    free_b (oldp);
  }
  return (newp);
}


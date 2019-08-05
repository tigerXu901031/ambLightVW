/***********************************************************************/
/*  malloc_b.c                                                         */
/*  Special Version of 'malloc', 'init_mempool', and 'free'            */
/*  for block based xhuge buffers                                      */
/*  Copyright KEIL ELEKTRONIK GmbH 1995 - 2004                         */
/***********************************************************************/

#include <stdlib.h>

#if (__MODEL__ == 5 || __MODEL__ == 6 || __MODEL__ == 7)
  #define MTYP_B  huge   // for HCOMPACT, HLARGE, and XLARGE
#else
  #define MTYP_B  far    // for other models
#endif

#define SEG(p)  (((unsigned int *) &(p))[1])
#define SOF(p)  (((unsigned int *) &(p))[0])

struct __mp_b__  {                      /* memory pool */
  struct __mp_b__ MTYP_B  *next;        /* single-linked list */
  unsigned int              len;        /* length of following block */
};

struct __mp_b__ MTYP_B * MTYP_B __mp_b__;      /* Memory Pool Header */
#define	HLEN	(sizeof(struct __mp_b__))

/*  Memory pool header:  __mp_b__ points to the first available.
 *
 *  Note that the list is maintained in address order.  __mp_b__ points to the
 *  block with the lowest address.  That block points to the block with the
 *  next higher address and so on.
 *
 *  Memory is laid out as follows:
 *
 *  {[NEXT | LEN] [BLOCK (LEN bytes)]} {[NEXT | LEN][BLOCK] } ...
 *
 *  Note that the size of a node is:
 *          mp.len + sizeof (struct mp_b)
 */


#define MIN_BLOCK	(HLEN * 4)

void MTYP_B *malloc_b (size_t size)   {
  struct __mp_b__ MTYP_B *q;  /* ptr to free block */
  struct __mp_b__ MTYP_B *p;  /* q->next */
  unsigned int k;             /* space remaining in the allocated block */
 
/*  Make sure that block is word aligned                                    */
  size = (size + 1) & ~1L;

/*  Initialization:  Q is the pointer to the next available block.          */
  q = (struct __mp_b__ MTYP_B *) &__mp_b__;

/*  End-Of-List:  P points to the next block.  If that block DNE (P==NULL),
 *  we are at the end of the list.                                          */

  while (1)  {
    p = q->next;
    if (!p)  return (NULL); /* FAILURE */

/*  Found Space:  If block is large enough, reserve if.  Otherwise, copy P
 *  to Q and try the next free block.                                       */
    if (p->len >= size) break;
    q = p;
  }

/*  Reserve P:  Use at least part of the P block to satisfy the allocation
 *  request.  At this time, the following pointers are setup:
 *  P points to the block from which we allocate Q->next points to P        */

  k = p->len - size;		/* calc. remaining bytes in block */

  if (k < MIN_BLOCK)  {		/* rem. bytes too small for new block */
    q->next = p->next;
    return (&p[1]);		    /* SUCCESS */
  }

/*  Split P Block:  If P is larger than we need, we split P into two blocks:
 *  the leftover space and the allocated space.  That means, we need to 
 *  create a header in the allocated space.                                 */

  k -= HLEN;
  p->len = k;

  q = (struct __mp_b__ MTYP_B *) (((char MTYP_B *) (&p[1])) + k);
  q->len = size;
  return (&q[1]);           /* SUCCESS */
}


/* Initialize Block oriented memory pool */
void init_mempool_b (
  void xhuge *pool,                     /* address of the memory pool  */
  unsigned long size)  {                /* size of the pool in bytes   */

  unsigned long  len;                   /* actual block length         */
  struct __mp_b__ MTYP_B *q;            /* ptr to free block list      */

/*  Set the __mp_b__ to point to the beginning of the pool and set
 *  the pool size.                                                     */

  __mp_b__ = (void MTYP_B *) pool;

  q = __mp_b__;

/*  Generate a linked list that does not cross segment bondaries       */

  while (q)  {
    size -= HLEN;
#if (__MODEL__ == 5 || __MODEL__ == 6 || __MODEL__ == 7)
    len = 0x10000 - SOF (q);             /* maximum block size  */
#else                                           /* far memory type     */
    len = 0x4000 - (SOF (q) & 0x3FFF);   /* maximum block size  */
#endif
    if (len > size)  len = size;                /* actual len          */
    q->len = (unsigned int) (len - HLEN);       /* free block size     */
    size  -= len;                               /* remaining pool size */
    if (size)  {                                /* still blocks?       */
      pool = (void xhuge *) (((char xhuge *) pool) + len);
      q->next = (void MTYP_B *) pool;           /* next block          */
    }
    else {                                      /* no remaining blocks */
      q->next = NULL;                           /* last block          */
    }
    q = q->next;                                /* linked list pointer */
  }
}



void free_b (void MTYP_B *memp)  {
/*  FREE attempts to organize Q, P0, and P so that Q < P0 < P.  Then, P0 is
 *  inserted into the free list so that the list is maintained in address
 *  order.
 *
 *  FREE also attempts to consolidate small blocks into the largest block
 *  possible.  So, after allocating all memory and freeing all memory,
 *  you will have a single block that is the size of the memory pool.  The
 *  overhead for the merge is very minimal.                                */

  struct __mp_b__ MTYP_B *q;                  /* ptr to free block */
  struct __mp_b__ MTYP_B *p;                  /* q->next           */
  char xhuge *n;                              /* next block        */ 
#define p0 ((struct __mp_b__ MTYP_B *) memp)    /* block to free */

/*  If the user tried to free NULL, get out now.  Otherwise, get the address
 *  of the header of the memp block (P0).  Then, try to locate Q and P such
 *  that Q < P0 < P.                                                       */

  if (!memp)  return;

  memp = &p0 [-1];              /* get address of header */

/*  Initialize.  Q = Location of first available block.                    */
  q = __mp_b__;
  if (!q)  {
    __mp_b__ = p0;
    p0->next = NULL;
    return;
  }

  if (q > memp)  {
    p = q;
    q = NULL;
    __mp_b__ = memp;
  }

/*  B2. Advance P. Hop through the list until we find a free block that is
 *  located in memory AFTER the block we're trying to free.                */
  if (q) while (1)  {
    p = q->next;
    if (!p || (p > memp)) break;
    q = p;
  }

/*  B3. Check upper bound. If P0 and P are contiguous, merge block P into
 *  block P0.                                                              */

  if (p)  {
    n = ((char xhuge *) memp) + p0->len + HLEN;
    if ((SEG (n) == SEG (memp)) && (n == (char xhuge *) p))  {
      p0->len += p->len + HLEN;
      p0->next = p->next;
    }
    else  {
      p0->next = p;
    }
  }
  else  {
    p0->next = NULL;
  }


/*  B4. Check lower bound. If Q and P0 are contiguous, merge P0 into Q.  */
  if (!q)  return;

  n = ((char xhuge *) q) + q->len + HLEN;
  if ((SEG (n) == SEG (q)) && (n == (char xhuge *) p0))  {
    q->len += p0->len + HLEN;
    q->next = p0->next;
  }
  else  {
    q->next  = p0;
  }
}


#ifndef INC_MEMLAYOUT_H
#define INC_MEMLAYOUT_H

// Memory layout

#define EXTMEM  0x100000            // Start of extended memory
#define PHYSTOP 0xE000000           // Top physical memory
#define DEVSPACE 0xFE000000         // Other devices are at high addresses

#define KSTKSIZE (8*PGSIZE)			// Size of a kernel stack

// Key addresses for address space layout (see kmap in vm.c for layout)
#define KERNBASE 0xF0000000         // First kernel virtual address
#define KERNLINK (KERNBASE+EXTMEM)  // Address where kernel is linked

#ifndef __ASSEMBLER__

#include <inc/types.h>

typedef uint32_t pde_t;

#define V2P(a) (((uint32_t) (a)) - KERNBASE)
#define P2V(a) ((void *)(((char *) (a)) + KERNBASE))

#define V2P_WO(x) ((x) - KERNBASE)    // same as V2P, but without casts
#define P2V_WO(x) ((x) + KERNBASE)    // same as P2V, but without casts

#endif /* !__ASSEMBLER__ */

#endif /* !INC_MEMLAYOUT_H */
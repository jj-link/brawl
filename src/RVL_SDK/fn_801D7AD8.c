#include <types.h>

#pragma force_active on

asm u32 fn_801D7AD8(void) {
    nofralloc
    mfspr r4, 920
    rlwinm r3, r4, 8, 28, 31
    blr
}

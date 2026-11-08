#include <types.h>

#pragma force_active on

asm u32 fn_801D5144(void) {
    nofralloc
    sync
    mfspr r3, 921
    blr
}

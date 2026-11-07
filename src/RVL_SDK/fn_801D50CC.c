#include <types.h>

#pragma force_active on

asm u32 fn_801D50CC(u32 val) {
    nofralloc
    mtspr PMC1, r3
    blr
}
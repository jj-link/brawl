#include <types.h>

#pragma force_active on

asm void fn_801D50BC(u32 val) {
    nofralloc
    mtspr MMCR0, r3
    blr
}

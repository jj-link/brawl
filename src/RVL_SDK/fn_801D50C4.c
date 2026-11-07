#include <types.h>

#pragma force_active on

asm void fn_801D50C4(register u32 value) {
    nofralloc
    mtspr 0x3BC, value
    blr
}

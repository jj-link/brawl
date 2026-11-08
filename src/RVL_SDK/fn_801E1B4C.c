#include <revolution/OS/OSTime.h>

#pragma force_active on

asm u32 OSGetTick(void) {
    nofralloc
    mftb r3, 268
    blr
}

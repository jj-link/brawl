#include <types.h>
#include <revolution/OS/OSCache.h>

#pragma force_active on

asm void DCFlushRange(register const void* buf, register u32 len) {
    // clang-format off
    nofralloc
    cmplwi r4, 0
    blelr
    clrlwi r5, r3, 27
    add r4, r4, r5
    addi r4, r4, 31
    srwi r4, r4, 5
    mtctr r4
loop:
    dcbf r0, r3
    addi r3, r3, 32
    bdnz loop
    sc
    blr
    // clang-format on
}

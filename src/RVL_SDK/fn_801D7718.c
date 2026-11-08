#include <types.h>

#pragma force_active on

asm void fn_801D7718(register const void* buf, register u32 len) {
    nofralloc

    cmplwi len, 0
    blelr

    clrlwi r5, buf, 27
    add len, len, r5
    addi len, len, 31
    srwi len, len, 5
    mtctr len

do_store:
    dcbst 0, buf
    addi buf, buf, 32
    bdnz do_store
    sc

    blr
}

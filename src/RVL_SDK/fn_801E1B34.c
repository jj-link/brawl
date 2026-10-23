#include <types.h>
#pragma force_active on

#define CWASM as##m

CWASM s64 OSGetTime(void) {
    nofralloc

    mftbu r3
    mftb r4

    mftbu r5
    cmpw r3, r5
    bne OSGetTime

    blr
}

#include <revolution/BASE.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)

BLOCK void fn_801D63E8(void) {
    nofralloc
    li r5, 0x40
    mflr r3
    stw r3, 0xc(r5)
    lwz r3, 0x8(r5)
    oris r3, r3, 0x8000
    mtlr r3
    li r3, 0x30
    mtmsr r3
    blr
}

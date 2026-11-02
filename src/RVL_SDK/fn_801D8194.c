#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

BLOCK void fn_801D8194(RG void* func, RG void* stack) {
    // clang-format off
    nofralloc

    mflr r0
    mr r5, r1
    stwu r5, -8(stack)
    mr r1, stack
    stw r0, 4(r5)
    mtlr func
    blrl
    lwz r5, 0(r1)
    lwz r0, 4(r5)
    mtlr r0
    mr r1, r5
    blr
    // clang-format on
}
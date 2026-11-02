#include <types.h>

#pragma force_active on
#pragma schedule off

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)

void fn_801D7928(void) {
    BLOCK {
        lis r3, 0xE000
        li r4, 0x200
        mtctr r4
    do_invalidate:
        dcbi r0, r3
        addi r3, r3, 0x20
        bdnz do_invalidate
        mfspr r4, 0x398
        rlwinm r4, r4, 0, 4, 2
        mtspr 0x398, r4
    }
}

#pragma schedule on

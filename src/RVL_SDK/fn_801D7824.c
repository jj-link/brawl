#include <types.h>

#pragma force_active on
#pragma schedule off

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)

void fn_801D7824(void) {
    BLOCK {
        mfmsr r5
        ori r5, r5, 0x1000
        mtmsr r5

        lis r3, 0x8000
        li r4, 0x400
        mtctr r4
    do_store:
        dcbt 0, r3
        dcbst 0, r3
        addi r3, r3, 0x20
        bdnz do_store

        mfspr r4, 0x398
        oris r4, r4, 0x100F
        mtspr 0x398, r4

        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop

        lis r3, 0xE000
        ori r3, r3, 0x2
        mtdbatl 3, r3
        ori r3, r3, 0x1FE
        mtdbatu 3, r3
        isync

        lis r3, 0xE000
        li r6, 0x200
        mtctr r6
        li r6, 0
    do_load:
        dcbz_l r6, r3
        addi r3, r3, 0x20
        bdnz do_load

        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    }
}

#pragma schedule on

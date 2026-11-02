#include <revolution/BASE/PPCArch.h>
#include <revolution/OS/OSCache.h>

#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)

void __OSPSInit(void) {
    PPCMthid2(PPCMfhid2() | (1 << 31) | HID2_PSE);
    ICFlashInvalidate();

    BLOCK {
        sync
        li r3, 0
        mtgqr0 r3
        mtgqr1 r3
        mtgqr2 r3
        mtgqr3 r3
        mtgqr4 r3
        mtgqr5 r3
        mtgqr6 r3
        mtgqr7 r3
    }
}
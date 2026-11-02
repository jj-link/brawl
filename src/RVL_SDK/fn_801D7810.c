#include <revolution/BASE/PPCArch.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)

void ICEnable(void) {
    BLOCK {
        isync
        mfhid0 r3
        ori r3, r3, 0x8000
        mthid0 r3
    }
}

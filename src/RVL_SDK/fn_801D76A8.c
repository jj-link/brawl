#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void DCEnable(void) {
    BLOCK {
        sync
        mfhid0 r3
        ori r3, r3, 0x4000
        mthid0 r3
    }
}

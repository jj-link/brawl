#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

u32 fn_801D50EC(void) {
    RG u64 fpscr;
    BLOCK {
        mffs f31
        stfd f31, fpscr
    }
    return fpscr;
}

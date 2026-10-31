#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void fn_801D5080(RG u32 val) {
    BLOCK { mtspr 0x3F0, val }
}

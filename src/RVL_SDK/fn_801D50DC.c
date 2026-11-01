#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void fn_801D50DC(RG u32 val) {
    BLOCK { mtspr PMC3, val }
}

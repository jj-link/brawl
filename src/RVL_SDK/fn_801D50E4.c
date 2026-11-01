#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void fn_801D50E4(RG u32 val) {
    BLOCK { mtpmc4 val }
}

#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void fn_801D5180(void) {
    BLOCK { mtfsb1 29 }
}

#include <types.h>
#pragma force_active on

extern "C" {
void fn_8017604C(void);
void fn_8017607C(void);

void (*fn_80176004(s32 unused, s32 arg))() {
    switch (arg) {
    case 0:
        return fn_8017607C;
    default:
        return fn_8017604C;
    }
}
}

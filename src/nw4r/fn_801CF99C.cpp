#include <types.h>
#pragma force_active on
extern "C" {
void fn_801CF99C(u32 *arg0) {
    u32 ptr = *arg0;
    if (ptr != 0 && *(u32 *)(ptr + 0x920) == (u32)arg0) {
        *(u32 *)(ptr + 0x920) = 0;
    }
    if (*arg0 != 0) {
        *arg0 = 0;
    }
}
}

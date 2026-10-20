#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_C6F44(const void *p) {
    const s32 *field = (const s32 *)((const char *)p + 8);
    return *field >> 27;
}
}

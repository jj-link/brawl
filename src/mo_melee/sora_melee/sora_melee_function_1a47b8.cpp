#include <types.h>
#pragma force_active on

extern "C" int fn_27_1A47B8(void *a) {
    s32 val = *(s32 *)((u8 *)a + 8);
    return val >> 28;
}

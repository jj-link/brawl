#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_19F878(u32 *p) {
    return (s32)((p[2] << 4) & 0xF8000000) >> 28;
}
}

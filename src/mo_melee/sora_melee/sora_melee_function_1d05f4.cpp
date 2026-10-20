#include <types.h>
#pragma force_active on

struct fn_27_1D05F4_obj {
    u32 pad[2];
    u32 field;
};

extern "C" {
s32 fn_27_1D05F4(fn_27_1D05F4_obj* p) {
    s32 v = (s32)((p->field << 2) & 0xE0000000);
    return v >> 30;
}
}

#include <types.h>
#pragma force_active on

struct fn_27_19E8AC_obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
s32 fn_27_19E8AC(fn_27_19E8AC_obj* p) {
    u32 v = p->flags;
    u32 field = (v >> 21) & 0x3F;
    return (s32)(field << 26) >> 27;
}
}

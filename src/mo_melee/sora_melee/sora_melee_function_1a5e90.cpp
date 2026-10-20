#include <types.h>
#pragma force_active on

struct fn_27_Obj {
    char pad[8];
    u32 flags;
};

extern "C" {
s32 fn_27_1A5E90(fn_27_Obj* p) {
    u32 x = p->flags;
    u32 y = ((x << 20) | (x >> 12)) & 0xFFE00000;
    return ((s32)y) >> 22;
}
}

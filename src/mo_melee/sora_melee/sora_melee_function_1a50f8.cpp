#include <types.h>
#pragma force_active on

struct fn27Bits {
    u8 pad[8];
    u32 a : 5;
    s32 b : 5;
    u32 c : 22;
};

extern "C" s32 fn_27_1A50F8(fn27Bits* p) {
    return p->b;
}

#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 6;
    s32 b : 6;
    u32 c : 20;
};

extern "C" s32 fn_27_CEB64(void* p) {
    Bits* bits = (Bits*)((u8*)p + 8);
    return bits->b;
}

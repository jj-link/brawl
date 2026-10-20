#include <types.h>
#pragma force_active on

struct fn_27_Bits {
    u32 a : 8;
    u32 b : 4;
    u32 c : 12;
    u32 d : 8;
};

extern "C" void fn_27_1A4C58(void* p, u32 v) {
    fn_27_Bits* s = (fn_27_Bits*)((char*)p + 8);
    s->b = v;
}

#include <types.h>
#pragma force_active on

struct fn_27_1A6968_bits {
    u32 a : 10;
    u32 b : 10;
    u32 c : 12;
};

extern "C" void fn_27_1A6968(void* p, u32 v) {
    fn_27_1A6968_bits* w = (fn_27_1A6968_bits*)((char*)p + 8);
    w->b = v;
}

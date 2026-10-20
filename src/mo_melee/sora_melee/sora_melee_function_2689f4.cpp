#include <types.h>
#pragma force_active on

struct Fn27Bits {
    u32 a : 5;
    u32 b : 27;
};

extern "C" void fn_27_2689F4(void* p, u32 v) {
    Fn27Bits* s = (Fn27Bits*)((char*)p + 8);
    s->a = v;
}

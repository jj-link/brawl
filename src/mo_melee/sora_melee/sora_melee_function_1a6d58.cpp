#include <types.h>
#pragma force_active on

struct Fn27Bits {
    u32 hi : 10;
    u32 lo : 22;
};

extern "C" void fn_27_1A6D58(void* p, u32 v) {
    Fn27Bits* w = (Fn27Bits*)((char*)p + 8);
    w->hi = v;
}

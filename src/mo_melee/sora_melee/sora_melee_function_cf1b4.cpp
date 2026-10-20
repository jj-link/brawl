#include <types.h>
#pragma force_active on

struct Bits {
    u32 hi : 6;
    u32 lo : 26;
};

extern "C" void fn_27_CF1B4(u8* p, u32 v) {
    Bits* b = (Bits*)(p + 8);
    b->hi = v;
}

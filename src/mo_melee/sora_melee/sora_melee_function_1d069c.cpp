#include <types.h>
#pragma force_active on

struct UnkBits {
    u32 hi : 4;
    u32 lo : 28;
};

struct UnkStruct {
    u32 pad0;
    u32 pad4;
    UnkBits bits;
};

extern "C" void fn_27_1D069C(UnkStruct* p, u32 val) {
    p->bits.hi = val;
}

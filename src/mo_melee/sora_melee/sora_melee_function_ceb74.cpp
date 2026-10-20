#include <types.h>
#pragma force_active on

struct BitsCEB74 {
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_CEB74(u8* self, u32 value) {
    BitsCEB74* w = (BitsCEB74*)(self + 0x8);
    w->b = value;
}

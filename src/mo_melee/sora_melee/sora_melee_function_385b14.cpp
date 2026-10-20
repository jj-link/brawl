#include <types.h>
#pragma force_active on

struct Bits8 {
    u32 hi : 10;
    u32 mid : 10;
    u32 lo : 12;
};

extern "C" void fn_27_385B14(void* p, u32 v) {
    Bits8* w = (Bits8*)((char*)p + 8);
    w->mid = v;
}

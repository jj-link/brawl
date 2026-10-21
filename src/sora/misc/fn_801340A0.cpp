#include <types.h>
#pragma force_active on

struct Fn1340Word {
    u32 hi : 8;
    u32 lo : 24;
};

extern "C" void fn_801340A0(void* self) {
    u8* p = static_cast<u8*>(self);
    Fn1340Word* w = reinterpret_cast<Fn1340Word*>(p + 8);
    w->hi = 1;
    *reinterpret_cast<u8*>(p + 0x75) = *reinterpret_cast<u8*>(p + 0x75) | 0x80;
}

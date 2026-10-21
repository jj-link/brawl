#include <types.h>
#pragma force_active on

extern "C" u64 fn_801C8010();
extern "C" int fn_801D3698(u8 a, u32 b, u32 c);

struct FnObj {
    u8 pad[0x28];
    u32 unk28;
};

extern "C" int fn_801C7654(FnObj* self) {
    struct { u32 hi; u32 lo; } s;
    u64 v = fn_801C8010();
    s.hi = (u32)(v >> 32);
    s.lo = (u32)v;
    u8 b = *(u8*)&s.hi;
    return fn_801D3698(b, s.lo, self->unk28) != 0;
}

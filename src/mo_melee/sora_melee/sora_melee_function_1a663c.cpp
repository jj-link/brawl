#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A663C(void* r3, u32 src) {
    union { u32 raw; struct { u32 lo : 22; u32 top : 10; }; } s;
    union { u32 raw; struct { u32 field : 10; u32 rest : 22; }; } d;
    s.raw = src;
    d.raw = *(u32*)((u8*)r3 + 8);
    d.field = s.top;
    *(u32*)((u8*)r3 + 8) = d.raw;
}

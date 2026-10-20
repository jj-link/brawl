#include <types.h>
#pragma force_active on

struct FooField {
    u8 pad[8];
    u32 hi : 12;
    u32 f : 6;
    u32 lo : 14;
};

extern "C" void fn_27_19E6D8(FooField* p, u32 v)
{
    p->f = v;
}

#include <types.h>
#pragma force_active on

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 f0 : 4;
    u32 f : 2;
    u32 f2 : 26;
};

extern "C" void fn_27_1A00E4(Obj *p, u32 v)
{
    p->f = v;
}

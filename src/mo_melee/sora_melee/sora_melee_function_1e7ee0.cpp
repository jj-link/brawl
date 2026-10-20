#include <types.h>
#pragma force_active on

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 4;
    u32 lo : 28;
};

extern "C" void fn_27_1E7EE0(fn27Obj* p, u32 v)
{
    p->hi = v;
}

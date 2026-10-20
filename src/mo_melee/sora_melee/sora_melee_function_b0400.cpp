#include <types.h>
#pragma force_active on

struct fn_27_B0400_obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 18;
    u32 field : 9;
    u32 lo : 5;
};

extern "C" void fn_27_B0400(fn_27_B0400_obj* p, u32 v)
{
    p->field = v;
}
